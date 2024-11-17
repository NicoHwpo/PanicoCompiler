#include <iostream>
#include <fstream>
#include <stack>
#include "antlr4-runtime.h"
#include "generated/PanicoLexer.h"
#include "generated/PanicoParser.h"
#include "generated/PanicoBaseVisitor.h"
#include "include/FunctionDirectory.h"
#include "include/SemanticCube.h"
#include "include/VariableTable.h"

struct Quadruple {
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string result;
};

// Custom visitor to process parse tree nodes (override methods as needed)
class CustomVisitor : public PanicoBaseVisitor {
public:
    SemanticCube semanticCube;
    FunctionDirectory functionDirectory;

    std::stack<std::string> operandStack;
    std::stack<Type> typeStack;
    std::stack<std::string> operatorStack;
    std::stack<int> jumpStack;
    std::vector<Quadruple> quadruples;
    int tempCounter = 0;
    int paramCounter = 0;

    std::string createTempVar() {
        return "t" + std::to_string(tempCounter++);
    }

    std::string createParamVar() {
        return "param" + std::to_string(paramCounter++);
    }

    void generateQuadruple(const std::string &op, const std::string &arg1, const std::string &arg2, const std::string &result) {
        quadruples.push_back({op, arg1, arg2, result});
    }

    antlrcpp::Any visitPrograma(PanicoParser::ProgramaContext *ctx) override {
        std::string programName = ctx->ID()->getText();
        // std::cout << "Program name: " << programName << std::endl;
        functionDirectory.addFunction(programName, VOID);
        functionDirectory.setMainFunction(functionDirectory.getCurrentFunction());
        // generate GOTO quadruple to jump to the main function
        generateQuadruple("GOTO", "nil", "nil", "nil");
        // visit the vars and funcs
        if (ctx->vars() != nullptr) {
            visit(ctx->vars());
        }
        for (size_t i = 0; i < ctx->funcs().size(); i++) {
            visit(ctx->funcs(i));
        }
        // update the GOTO quadruple to jump to the start of the main function
        quadruples[0].result = std::to_string(quadruples.size());
        // visit the main function
        visit(ctx->cuerpo());
        // generate HALT quadruple to end the program
        generateQuadruple("HALT", "nil", "nil", "nil");
        return nullptr;
    }

    antlrcpp::Any visitFuncs(PanicoParser::FuncsContext *ctx) override {
        std::string functionName = ctx->ID()->getText();
        Type returnType = semanticCube.getTypeFromString(ctx->VOID()->getText());
        if (!functionDirectory.addFunction(functionName, returnType)) {
            std::cerr << "Function " << functionName << " already declared." << std::endl;
            return nullptr;
        }
        // process the function parameters and variables
        if (ctx->params() != nullptr) {
            visit(ctx->params());
        }
        if (ctx->vars() != nullptr) {
            visit(ctx->vars());
        }
        // set the start of the function
        functionDirectory.setStartAddressToCurFunc(quadruples.size());
        // process the function body
        visit(ctx->cuerpo());
        // generate ENDFUNC quadruple
        generateQuadruple("ENDFUNC", "nil", "nil", "nil");
        return nullptr;
    }

    antlrcpp::Any visitLlamada(PanicoParser::LlamadaContext *ctx) override {
        // get func name
        std::string funcName = ctx->ID()->getText();
        // get func info
        FunctionInfo *funcInfo = functionDirectory.getFunctionInfo(funcName);
        if (funcInfo == nullptr) {
            antlr4::Token *startToken = ctx->getStart();
            int line = startToken->getLine();
            int column = startToken->getCharPositionInLine();
            std::cerr << "Function " << funcName << " not found. Line: " << line << ", Column: " << column << std::endl;
            return nullptr;
        }
        // generate ERA quadruple to prepare for activation record for the func
        generateQuadruple("ERA", funcName, "nil", "nil");
        // check if the number of arguments matches the number of parameters
        if (ctx->expresion().size() != funcInfo->numParams) {
            antlr4::Token *startToken = ctx->getStart();
            int line = startToken->getLine();
            int column = startToken->getCharPositionInLine();
            std::cerr << "Function " << funcName << " expects " << funcInfo->numParams << " arguments, but " << ctx->expresion().size() << " were provided. Line: " << line << ", Column: " << column << std::endl;
            return nullptr;
        }
        // process the function arguments and generate PARAM quadruples
        for (size_t i = 0; i < ctx->expresion().size(); i++) {
            // visit the expression
            visit(ctx->expresion(i));
            // pop the result of the expression
            std::string param = operandStack.top(); operandStack.pop();
            // generate PARAM quadruple
            generateQuadruple("PARAM", param, "nil", createParamVar());
        }
        paramCounter = 0;
        // generate GOSUB quadruple to call the function
        int startAddress = funcInfo->startAddress;
        generateQuadruple("GOSUB", funcName, "nil", std::to_string(startAddress));
        return nullptr;
    }

    antlrcpp::Any visitParams(PanicoParser::ParamsContext *ctx) override {
        size_t numParams = ctx->ID().size();
        for (size_t i = 0; i < numParams; i++) {
            std::string paramName = ctx->ID(i)->getText();
            Type paramType = semanticCube.getTypeFromString(ctx->tipo(i)->getText());
            functionDirectory.addParameterToCurFunc(paramName, paramType);
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDecl_var(PanicoParser::Decl_varContext *ctx) override {
        Type varsType = semanticCube.getTypeFromString(ctx->tipo()->getText());
        size_t numVars = ctx->ID().size();
        for (size_t i = 0; i < numVars; i++) {
            std::string varName = ctx->ID(i)->getText();
            functionDirectory.addVariableToCurFunc(varName, varsType);
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAsigna(PanicoParser::AsignaContext *ctx) override {
        std::string varName = ctx->ID()->getText();
        VariableInfo *varInfo = functionDirectory.getVarInFuncOrGlobalScope(varName);
        if (varInfo == nullptr) {
            antlr4::Token *startToken = ctx->getStart();
            int line = startToken->getLine();
            int column = startToken->getCharPositionInLine();
            std::cerr << "Variable " << varName << " not found. Line: " << line << ", Column: " << column << std::endl;
            return nullptr;
        }
        visit(ctx->expresion());
        // pop the result of the expression
        std::string result = operandStack.top(); operandStack.pop();
        // type checking
        Type resultType = typeStack.top(); typeStack.pop();
        
        generateQuadruple("=", result, "nil", varName);
        return nullptr;
    }

    antlrcpp::Any visitExpresion(PanicoParser::ExpresionContext *ctx) override {
        // visit the left operand
        visit(ctx->exp(0));
        if (ctx->exp().size() > 1) {
            // if there is a relational operator, push it into the operator stack
            operatorStack.push(ctx->children[1]->getText());
            // visit the right operand
            visit(ctx->exp(1));
            // pop the relational operator from the operator stack
            std::string relationalOp = operatorStack.top(); operatorStack.pop();
            std::string rightOperand = operandStack.top(); operandStack.pop();
            std::string leftOperand = operandStack.top(); operandStack.pop();

            // type checking
            Type rightType = typeStack.top(); typeStack.pop();
            Type leftType = typeStack.top(); typeStack.pop();
            Type resultType = semanticCube.getResultType(leftType, rightType, relationalOp);
            if (resultType == ERROR) {
                std::cerr << "Type mismatch in relational operation." << std::endl;
            }

            // generate result & quadruple and push on stack
            std::string tempResult = createTempVar();
            generateQuadruple(relationalOp, leftOperand, rightOperand, tempResult);
            operandStack.push(tempResult);
            typeStack.push(resultType);
            return tempResult;
        }
        return nullptr;
    }

    antlrcpp::Any visitExp(PanicoParser::ExpContext *ctx) override {
        // visit the left operand
        // std::string leftOperand = std::any_cast<std::string>(visit(ctx->termino(0)));
        // operandStack.push(leftOperand);
        visit(ctx->termino(0));
        for (size_t i = 1; i < ctx->termino().size(); i++) {
            std::string arithmeticOp = ctx->children[i * 2 - 1]->getText();
            operatorStack.push(arithmeticOp);
            // std::string rightOperand = std::any_cast<std::string>(visit(ctx->termino(i)));
            // operandStack.push(rightOperand);
            visit(ctx->termino(i));
            if (operatorStack.top() == "+" || operatorStack.top() == "-") {
                // pop the operator and operands and types
                std::string rightOperand = operandStack.top(); operandStack.pop();
                Type rightType = typeStack.top(); typeStack.pop();
                std::string leftOperand = operandStack.top(); operandStack.pop();
                Type leftType = typeStack.top(); typeStack.pop();
                std::string op = operatorStack.top(); operatorStack.pop();
                // type checking
                Type resultType = semanticCube.getResultType(leftType, rightType, op);
                if (resultType == ERROR) {
                    std::cerr << "Type mismatch in arithmetic operation." << std::endl;
                    return nullptr;
                }
                // generate result & quadruple and push on stack
                std::string tempResult = createTempVar();
                generateQuadruple(op, leftOperand, rightOperand, tempResult);
                operandStack.push(tempResult);
                typeStack.push(resultType);
            }
        }
        return nullptr;
    }

    antlrcpp::Any visitTermino(PanicoParser::TerminoContext *ctx) override {
        // std::string leftOperand = std::any_cast<std::string>(visit(ctx->factor(0)));
        // operandStack.push(leftOperand);
        visit(ctx->factor(0));
        for (size_t i = 1; i < ctx->factor().size(); i++) {
            std::string arithmeticOp = ctx->children[i * 2 - 1]->getText();
            operatorStack.push(arithmeticOp);
            // std::string rightOperand = std::any_cast<std::string>(visit(ctx->factor(i)));
            // operandStack.push(rightOperand);
            visit(ctx->factor(i));
            if (operatorStack.top() == "*" || operatorStack.top() == "/") {
                // pop the operator and operands and types
                std::string rightOperand = operandStack.top(); operandStack.pop();
                Type rightType = typeStack.top(); typeStack.pop();
                std::string leftOperand = operandStack.top(); operandStack.pop();
                Type leftType = typeStack.top(); typeStack.pop();
                std::string op = operatorStack.top(); operatorStack.pop();
                // type checking
                Type resultType = semanticCube.getResultType(leftType, rightType, op);
                if (resultType == ERROR) {
                    std::cerr << "Type mismatch in arithmetic operation." << std::endl;
                    return nullptr;
                }
                // generate result & quadruple and push on stack
                std::string tempResult = createTempVar();
                generateQuadruple(op, leftOperand, rightOperand, tempResult);
                operandStack.push(tempResult);
                typeStack.push(resultType);
            }
        }
        return nullptr;
    }

    antlrcpp::Any visitFactor(PanicoParser::FactorContext *ctx) override {
        std::string operandName;
        if (ctx->PARENIZQ() != nullptr) {
            // if the factor is an expression, visit the expression
            // operandName = std::any_cast<std::string>(visit(ctx->expresion()));
            visit(ctx->expresion());
        } else if (ctx->ID() != nullptr) {
            // if the factor is an ID, get the variable info
            operandName = ctx->ID()->getText();
            operandStack.push(operandName);
            VariableInfo *varInfo = functionDirectory.getVarInFuncOrGlobalScope(operandName);
            if (varInfo == nullptr) {
                antlr4::Token *startToken = ctx->getStart();
                int line = startToken->getLine();
                int column = startToken->getCharPositionInLine();
                std::cerr << "Variable " << operandName << " not found. Line: " << line << ", Column: " << column << std::endl;
                return nullptr;
            }
            typeStack.push(varInfo->type);
        } else if (ctx->cte() != nullptr) {
            // if the factor is a constant, get the constant value
            operandName = ctx->cte()->getText();
            operandStack.push(operandName);
            if (ctx->cte()->CTE_ENT() != nullptr) {
                typeStack.push(INT);
            } else if (ctx->cte()->CTE_FLOT() != nullptr) {
                typeStack.push(FLOAT);
            }
        }
        // check for unary minus
        if (ctx->MENOS() != nullptr) {
            std::string tempResult = createTempVar();
            // pop the operand and type
            operandStack.pop();
            generateQuadruple("MINUS", operandName, "nil", tempResult);
            operandStack.push(tempResult);
            operandName = tempResult;
        }
        return nullptr;
    }

    antlrcpp::Any visitImprime(PanicoParser::ImprimeContext *ctx) override {
        // iterate over all the expressions to print
        for (size_t i = 0; i < ctx->impr().size(); i++) {
            std::string printOperand;

            if (ctx->impr(i)->expresion() != nullptr) {
                // if the expression is a variable or constant, visit it
                visit(ctx->impr(i)->expresion());
                printOperand = operandStack.top(); operandStack.pop();
            } else if (ctx->impr(i)->LETRERO_VALOR() != nullptr) {
                // if the expression is a string, get the string value
                printOperand = ctx->impr(i)->LETRERO_VALOR()->getText();
            }
            // generate quadruple to print the operand
            generateQuadruple("PRINT", printOperand, "nil", "nil");
        }
        return nullptr;
    }

    antlrcpp::Any visitCondicion(PanicoParser::CondicionContext *ctx) override {
        // visit the expression
        visit(ctx->expresion());
        std::string result = operandStack.top(); operandStack.pop();
        // check type of the expression
        Type resultType = typeStack.top(); typeStack.pop();
        if (resultType != BOOL) {
            std::cerr << "Condition must be of type bool." << std::endl;
            return nullptr;
        }

        // generate quadruple to jump if false and push the jump label
        int gotofQuadIndex = quadruples.size();
        generateQuadruple("GOTOF", result, "nil", "pending");
        jumpStack.push(gotofQuadIndex);
        // visit the body of the if statement
        visit(ctx->cuerpo(0));
        // if there is an else statement, generate quadruple to jump to end of else and push the jump label
        if (ctx->ELSE() != nullptr) {
            // handle else part
            int gotoQuadIndex = quadruples.size();
            generateQuadruple("GOTO", "nil", "nil", "pending");
            
            // update the GOTOF target to jump to the else statement
            int gotofAddress = jumpStack.top(); jumpStack.pop();
            quadruples[gotofAddress].result = std::to_string(quadruples.size());
            // push the new GOTO location and visit the else statement
            jumpStack.push(gotoQuadIndex);
            visit(ctx->cuerpo(1));
        }
        // fill the final jump target
        int exitAddress = jumpStack.top(); jumpStack.pop();
        quadruples[exitAddress].result = std::to_string(quadruples.size());
        return nullptr;
    }

    antlrcpp::Any visitCiclo(PanicoParser::CicloContext *ctx) override {
        // save the current quadruple index
        int startAddress = quadruples.size();
        // evaluate the loop condition
        visit(ctx->expresion());
        std::string result = operandStack.top(); operandStack.pop();
        // check type of the expression
        Type resultType = typeStack.top(); typeStack.pop();
        if (resultType != BOOL) {
            std::cerr << "Condition must be of type bool." << std::endl;
            return nullptr;
        }
        // gen the GOTOF quad
        int gotofQuadIndex = quadruples.size();
        generateQuadruple("GOTOF", result, "nil", "pending");
        // push the jump target to the jump stack
        jumpStack.push(gotofQuadIndex);
        // visit the loop body
        visit(ctx->cuerpo());
        // generate the GOTO quad to return to the loop condition
        generateQuadruple("GOTO", "nil", "nil", std::to_string(startAddress));
        // update the GOTOF result with the current quadruple index
        int exitAddress = jumpStack.top(); jumpStack.pop();
        quadruples[exitAddress].result = std::to_string(quadruples.size());
        return nullptr;
    }
};

// function to print quadruples
void printQuadruples(const std::vector<Quadruple> &quadruples) {
    for (size_t i = 0; i < quadruples.size(); i++) {
        const Quadruple &quad = quadruples[i];
        std::cout << i << ": " << quad.op << " " << quad.arg1 << " " << quad.arg2 << " " << quad.result << std::endl;
    }
}

// Function to print all variables in each function within the Function Directory
void printFunctionDirectory(FunctionDirectory &functionDirectory) {
    const auto &functions = functionDirectory.getFunctionDirectory();
    for (auto &function : *functions) {
        std::cout << "Function: " << function.first << std::endl;
        std::cout << "Return type: " << function.second.returnType << std::endl;
        std::cout << "Parameters:\n";
        const auto &parameters = function.second.parametersTable.getVariables();
        for (const auto &param : *parameters) {
            std::cout << param.first << " " << param.second.type << std::endl;
        }
        std::cout << "Variables:\n";
        const auto &variables = function.second.variableTable.getVariables();
        for (const auto &var : *variables) {
            std::cout << var.first << " " << var.second.type << std::endl;
        }
    }
}


int main(int argc, const char* argv[]) {
    // Check for input file argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        return 1;
    }

    // Open the input file
    std::ifstream stream;
    stream.open(argv[1]);
    if (!stream.is_open()) {
        std::cerr << "Could not open file: " << argv[1] << std::endl;
        return 1;
    }

    // Set up ANTLR input and lexer
    antlr4::ANTLRInputStream input(stream);
    PanicoLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    // Create the parser and parse the input starting from the 'programa' rule
    PanicoParser parser(&tokens);
    antlr4::tree::ParseTree *tree = parser.programa();

    // Print the parse tree (for debugging)
    // std::cout << tree->toStringTree(&parser) << std::endl;

    // Visit the parse tree with our custom visitor
    CustomVisitor visitor;
    visitor.visit(tree);

    // Print all variables in each function
    // printFunctionDirectory(visitor.functionDirectory);

    // print quadruples
    printQuadruples(visitor.quadruples);

    
    return 0;
}


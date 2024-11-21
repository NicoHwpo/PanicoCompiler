// CustomVisitor.cpp
#include "CustomVisitor.h"

int CustomVisitor::allocateMemory(Type type, bool isGlobal) {
    int address = -1;
    if (isGlobal) {
        if (type == INT) address = memoryManager.allocateGlobalInt();
        else if (type == FLOAT) address = memoryManager.allocateGlobalFloat();
    } else {
        if (type == INT) address = memoryManager.allocateLocalInt();
        else if (type == FLOAT) address = memoryManager.allocateLocalFloat();
    }
    return address;
}

void CustomVisitor::handleMemoryAllocationError(int address, antlr4::Token *startToken) {
    int line = startToken->getLine();
    int column = startToken->getCharPositionInLine();
    switch (address) {
        case -1:
            std::cerr << "Out of memory for global variables. Line: " << line << ", Column: " << column << std::endl;
            return;
        case -2:
            std::cerr << "Out of memory for local variables. Line: " << line << ", Column: " << column << std::endl;
            return;
        case -3:
            std::cerr << "Out of memory for integer constants. Line: " << line << ", Column: " << column << std::endl;
            return;
        case -4:
            std::cerr << "Out of memory for float constants. Line: " << line << ", Column: " << column << std::endl;
            return;
        case -5:
            std::cerr << "Out of memory for string constants. Line: " << line << ", Column: " << column << std::endl;
            return;
        default:
            return;
    }
    throw std::runtime_error("Memory allocation error.");
}

void CustomVisitor::handleVarInfoError(std::string var, antlr4::Token *startToken) {
    int line = startToken->getLine();
    int column = startToken->getCharPositionInLine();
    std::cerr << "Variable " << var << " not found. Line: " << line << ", Column: " << column << std::endl;
    throw std::runtime_error("Variable info error.");
}

std::string CustomVisitor::createTempVar() {
    return "t" + std::to_string(tempCounter++);
}

void CustomVisitor::generateQuadruple(const std::string &op, const std::string &arg1, const std::string &arg2, const std::string &result) {
    // generate quadruple with names and addresses
    Quadruple quad = {{op, -1}, {arg1, getAddress(arg1)}, {arg2, getAddress(arg2)}, {result, getAddress(result)}};
    quadruples.push_back(quad);
    // quadruplesWithAddresses.push_back({op, std::to_string(getAddress(arg1)), std::to_string(getAddress(arg2)), std::to_string(getAddress(result))});
}

int CustomVisitor::getAddress(const std::string &var) {
    if (functionDirectory.getVarInFuncOrGlobalScope(var) != nullptr) {
        return functionDirectory.getVarInFuncOrGlobalScope(var)->memoryAddress;
    }
    return -1;
}

// programa: PROGRAM ID PUNTOYCOMA vars? funcs* START LLAVEIZQ cuerpo LLAVEDER END; 
antlrcpp::Any CustomVisitor::visitPrograma(PanicoParser::ProgramaContext *ctx) {
    // get the program name
    std::string programName = ctx->ID()->getText();
    // add the program as a function to the function directory
    functionDirectory.addFunction(programName, VOID);
    // set the main function to the current function
    functionDirectory.setMainFunction(functionDirectory.getCurrentFunction());
    // generate GOTO quadruple to jump to the main function
    jumpStack.push(quadruples.size());
    generateQuadruple("GOTO", "nil", "nil", "pending");
    // visit the vars
    if (ctx->vars() != nullptr) {
        visit(ctx->vars());
    }
    // visit the functions
    for (size_t i = 0; i < ctx->funcs().size(); i++) {
        // visit the function
        visit(ctx->funcs(i));
        // after visiting the function, reset the local memory
        memoryManager.resetLocals();
    }
    // update the GOTO quadruple to jump to the start of the main function
    int startAddress = jumpStack.top(); jumpStack.pop();
    quadruples[startAddress].result.name = std::to_string(quadruples.size());
    // visit the main function
    visit(ctx->cuerpo());
    // generate HALT quadruple to end the program
    generateQuadruple("HALT", "nil", "nil", "nil");
    return nullptr;
}

// vars: VARS LLAVEIZQ decl_var+ LLAVEDER;
antlrcpp::Any CustomVisitor::visitVars(PanicoParser::VarsContext *ctx) {
    // iterate over all the variable declarations
    for (size_t i = 0; i < ctx->decl_var().size(); i++) {
        visit(ctx->decl_var(i));
    }
    return nullptr;
}

// decl_var: ID (COMA ID)* DOSPUNTOS tipo PUNTOYCOMA;
antlrcpp::Any CustomVisitor::visitDecl_var(PanicoParser::Decl_varContext *ctx) {
    // get the variable type as a Type enum from the string
    Type varsType = semanticCube.getTypeFromString(ctx->tipo()->getText());
    // check if the variables declared are in the global or local scope
    bool isGlobal = functionDirectory.isGlobalScope();
    // iterate over all the variables declared
    for (size_t i = 0; i < ctx->ID().size(); i++) {
        // get the variable name
        std::string varName = ctx->ID(i)->getText();
        // allocate memory for the variable
        int address = allocateMemory(varsType, isGlobal);
        // handle memory allocation error
        handleMemoryAllocationError(address, ctx->getStart());
        // add the variable to the current function's variable table
        functionDirectory.addVariableToCurFunc(varName, varsType, address);
    }
    return nullptr;
}

// funcs: VOID ID PARENIZQ params? PARENDER LLAVEIZQ vars? cuerpo LLAVEDER PUNTOYCOMA;
antlrcpp::Any CustomVisitor::visitFuncs(PanicoParser::FuncsContext *ctx) {
    // get the function name and return type
    std::string functionName = ctx->ID()->getText();
    Type returnType = semanticCube.getTypeFromString(ctx->VOID()->getText());
    // add the function to the function directory
    if (!functionDirectory.addFunction(functionName, returnType)) {
        int line = ctx->getStart()->getLine();
        int column = ctx->getStart()->getCharPositionInLine();
        std::cerr << "Function " << functionName << " already declared. Line: " << line << ", Column: " << column << std::endl;
        return nullptr;
    }
    // set the start of the function
    functionDirectory.setStartAddressToCurFunc(quadruples.size());
    // process the function parameters
    if (ctx->params() != nullptr) {
        visit(ctx->params());
    }
    // process the function variables
    if (ctx->vars() != nullptr) {
        visit(ctx->vars());
    }
    // process the function body
    visit(ctx->cuerpo());
    // generate ENDFUNC quadruple
    generateQuadruple("ENDFUNC", "nil", "nil", "nil");
    functionDirectory.setCurrentFunction(functionDirectory.getMainFunction());
    return nullptr;
}

// params: ID DOSPUNTOS tipo (COMA ID DOSPUNTOS tipo)*;
antlrcpp::Any CustomVisitor::visitParams(PanicoParser::ParamsContext *ctx) {
    // iterate over all the parameters
    for (size_t i = 0; i < ctx->ID().size(); i++) {
        // get the parameter name and type
        std::string paramName = ctx->ID(i)->getText();
        Type paramType = semanticCube.getTypeFromString(ctx->tipo(i)->getText());
        // allocate memory for the parameter
        int address = allocateMemory(paramType, false);
        // handle memory allocation error
        handleMemoryAllocationError(address, ctx->getStart());
        // add the parameter to the function's parameter table
        functionDirectory.addParameterToCurFunc(paramName, paramType, address);
    }
    return nullptr;
}

// cuerpo: estatuto*;
antlrcpp::Any CustomVisitor::visitCuerpo(PanicoParser::CuerpoContext *ctx) {
    // iterate over all the statements in the function body
    for (size_t i = 0; i < ctx->estatuto().size(); i++) {
        visit(ctx->estatuto(i));
    }
    return nullptr;
}

// estatuto: asigna | condicion | ciclo | llamada | imprime;
antlrcpp::Any CustomVisitor::visitEstatuto(PanicoParser::EstatutoContext *ctx) {
    visitChildren(ctx);
    return nullptr;
}

// asigna: ID IGUAL expresion PUNTOYCOMA;
antlrcpp::Any CustomVisitor::visitAsigna(PanicoParser::AsignaContext *ctx) {
    // get the variable name
    std::string varName = ctx->ID()->getText();
    // get the variable info from the function directory
    VariableInfo *varInfo = functionDirectory.getVarInFuncOrGlobalScope(varName);
    // handle variable info error
    if (varInfo == nullptr) handleVarInfoError(varName, ctx->getStart());
    // visit the expression to assign
    visit(ctx->expresion());
    // pop the result of the expression
    std::string result = operandStack.top(); operandStack.pop();
    // pop the type of the result of the expression
    Type rightOpType = typeStack.top(); typeStack.pop();
    Type varType = varInfo->type;
    // type checking
    Type resultType = semanticCube.getResultType(varType, rightOpType, "=");
    if (resultType == ERROR) {
        std::cerr << "Type mismatch in assignment." << std::endl;
        return nullptr;
    }
    // generate assignment quadruple
    generateQuadruple("=", result, "nil", varName);
    return nullptr;
}

// expresion: exp ((MAYORQUE | MENORQUE | DIFERENTE | IGUALIGUAL) exp)?;
antlrcpp::Any CustomVisitor::visitExpresion(PanicoParser::ExpresionContext *ctx) {
    // visit the left exp
    visit(ctx->exp(0));
    // if there is a relational operator, visit the right exp
    if (ctx->exp().size() > 1) {
        // if there is a relational operator, push it into the operator stack
        operatorStack.push(ctx->children[1]->getText());
        // visit the right operand
        visit(ctx->exp(1));
        // pop the operands
        std::string rightOperand = operandStack.top(); operandStack.pop();
        std::string leftOperand = operandStack.top(); operandStack.pop();
        // pop the types
        Type rightType = typeStack.top(); typeStack.pop();
        Type leftType = typeStack.top(); typeStack.pop();
        // pop the operator
        std::string relationalOp = operatorStack.top(); operatorStack.pop();
        // type checking
        Type resultType = semanticCube.getResultType(leftType, rightType, relationalOp);
        if (resultType == ERROR) {
            std::cerr << "Type mismatch in relational operation." << std::endl;
            return nullptr;
        }
        // generate temporary variable for the result
        std::string tempResult = createTempVar();
        // allocate memory for the temporary variable
        int address = allocateMemory(resultType, functionDirectory.isGlobalScope());
        // handle memory allocation error
        handleMemoryAllocationError(address, ctx->getStart());
        // add the temporary variable to the function's variable table
        functionDirectory.addVariableToCurFunc(tempResult, resultType, address);
        // generate quadruple for the relational operation
        generateQuadruple(relationalOp, leftOperand, rightOperand, tempResult);
        // push the temporary variable operand and type to the stacks
        operandStack.push(tempResult);
        typeStack.push(resultType);
    }
    return nullptr;
}

// exp: termino ((MAS | MENOS) termino)*;
antlrcpp::Any CustomVisitor::visitExp(PanicoParser::ExpContext *ctx) {
    // visit the left termino
    visit(ctx->termino(0));
    // visit the rest of the terminos; meaning that there is a + or - operator
    for (size_t i = 1; i < ctx->termino().size(); i++) {
        // get the operator (either + or -)
        std::string arithmeticOp = ctx->children[i * 2 - 1]->getText();
        // push the operator into the operator stack
        operatorStack.push(arithmeticOp);
        // visit the right termino
        visit(ctx->termino(i));
        // generate quadruple for the arithmetic operation
        if (operatorStack.top() == "+" || operatorStack.top() == "-") { // CHECK_LUEGO: para que preguntar si es obvio que si hay mas de 1 termino, significa que hay una operacion de + o -
            // pop the operands
            std::string rightOperand = operandStack.top(); operandStack.pop();
            std::string leftOperand = operandStack.top(); operandStack.pop();
            // pop the types
            Type rightType = typeStack.top(); typeStack.pop();
            Type leftType = typeStack.top(); typeStack.pop();
            // pop the operator
            std::string op = operatorStack.top(); operatorStack.pop();
            // type checking
            Type resultType = semanticCube.getResultType(leftType, rightType, op);
            if (resultType == ERROR) {
                std::cerr << "Type mismatch in arithmetic operation." << std::endl;
                return nullptr;
            }
            // generate temporary variable for the result
            std::string tempResult = createTempVar();
            // allocate memory for the temporary variable
            int address = allocateMemory(resultType, functionDirectory.isGlobalScope());
            // handle memory allocation error
            handleMemoryAllocationError(address, ctx->getStart());
            // add the temporary variable to the function's variable table
            functionDirectory.addVariableToCurFunc(tempResult, resultType, address);
            // generate quadruple for the arithmetic operation
            generateQuadruple(op, leftOperand, rightOperand, tempResult);
            // push the temporary variable operand and type to the stacks
            operandStack.push(tempResult);
            typeStack.push(resultType);
        }
    }
    return nullptr;
}

// termino: factor ((MULT | DIV) factor)*;
antlrcpp::Any CustomVisitor::visitTermino(PanicoParser::TerminoContext *ctx) {
    // visit the left factor
    visit(ctx->factor(0));
    // visit the rest of the factors; meaning that there is a * or / operator
    for (size_t i = 1; i < ctx->factor().size(); i++) {
        // get the operator (either * or /)
        std::string arithmeticOp = ctx->children[i * 2 - 1]->getText();
        // push the operator into the operator stack
        operatorStack.push(arithmeticOp);
        // visit the right factor
        visit(ctx->factor(i));
        // generate quadruple for the arithmetic operation
        if (operatorStack.top() == "*" || operatorStack.top() == "/") { // CHECK_LUEGO: para que preguntar si es obvio que si hay mas de 1 factor, significa que hay una operacion de * o /
            // pop the operands
            std::string rightOperand = operandStack.top(); operandStack.pop();
            std::string leftOperand = operandStack.top(); operandStack.pop();
            // pop the types
            Type rightType = typeStack.top(); typeStack.pop();
            Type leftType = typeStack.top(); typeStack.pop();
            // pop the operator
            std::string op = operatorStack.top(); operatorStack.pop();
            // type checking
            Type resultType = semanticCube.getResultType(leftType, rightType, op);
            if (resultType == ERROR) {
                std::cerr << "Type mismatch in arithmetic operation." << std::endl;
                return nullptr;
            }
            // generate temporary variable for the result
            std::string tempResult = createTempVar();
            // allocate memory for the temporary variable
            int address = allocateMemory(resultType, functionDirectory.isGlobalScope());
            // handle memory allocation error
            handleMemoryAllocationError(address, ctx->getStart());
            // add the temporary variable to the function's variable table
            functionDirectory.addVariableToCurFunc(tempResult, resultType, address);
            // generate quadruple for the arithmetic operation
            generateQuadruple(op, leftOperand, rightOperand, tempResult);
            // push the temporary variable operand and type to the stacks
            operandStack.push(tempResult);
            typeStack.push(resultType);
        }
    }
    return nullptr;
}

// factor: PARENIZQ expresion PARENDER | MENOS? (ID | cte);
antlrcpp::Any CustomVisitor::visitFactor(PanicoParser::FactorContext *ctx) {
    std::string operandName;
    if (ctx->PARENIZQ() != nullptr) {
        // if the factor is an expression, visit the expression
        visit(ctx->expresion());
    } else if (ctx->ID() != nullptr) {
        // if the factor is an ID, get the variable info
        operandName = ctx->ID()->getText();
        // get the variable info from the function directory
        VariableInfo *varInfo = functionDirectory.getVarInFuncOrGlobalScope(operandName);
        // handle variable info error
        if (varInfo == nullptr) handleVarInfoError(operandName, ctx->getStart());
        // push the operand and type to the stacks
        operandStack.push(operandName);
        typeStack.push(varInfo->type);
    } else if (ctx->cte() != nullptr) {
        // if the factor is a constant, get the constant value
        operandName = ctx->cte()->getText();
        // get the type of the constant (INT or FLOAT)
        Type cteType = semanticCube.getTypeFromConstant(operandName);
        // allocate memory for the constant
        int address = memoryManager.getOrCreateConstant(cteType, operandName);
        // handle memory allocation error
        handleMemoryAllocationError(address, ctx->getStart());
        // push the operand and type to the stacks
        operandStack.push(operandName);
        typeStack.push(cteType);
    }
    // check for unary minus
    if (ctx->MENOS() != nullptr) {
        // generate temporary variable for the unary minus
        std::string tempResult = createTempVar();
        // pop the operand and type
        operandName = operandStack.top(); operandStack.pop();
        Type operandType = typeStack.top(); typeStack.pop();
        // allocate memory for the temporary variable
        int address = allocateMemory(operandType, functionDirectory.isGlobalScope());
        // handle memory allocation error
        handleMemoryAllocationError(address, ctx->getStart());
        // add the temporary variable to the function's variable table
        functionDirectory.addVariableToCurFunc(tempResult, operandType, address);
        // generate quadruple for the unary minus
        generateQuadruple("MINUS", operandName, "nil", tempResult);
        // push the temporary variable operand and type to the stacks
        operandStack.push(tempResult);
        typeStack.push(operandType);
    }
    return nullptr;
}

// imprime: PRINT PARENIZQ impr (COMA impr)* PARENDER PUNTOYCOMA;
antlrcpp::Any CustomVisitor::visitImprime(PanicoParser::ImprimeContext *ctx) {
    // iterate over all the expressions to print
    for (size_t i = 0; i < ctx->impr().size(); i++) {
        visit(ctx->impr(i));
    }
    return nullptr;
}

// impr: expresion | LETRERO_VALOR;
antlrcpp::Any CustomVisitor::visitImpr(PanicoParser::ImprContext *ctx) {
    std::string printOperand;
    if (ctx->expresion() != nullptr) {
        // if the expression is a variable or constant, visit it
        visit(ctx->expresion());
    } else if (ctx->LETRERO_VALOR() != nullptr) {
        // if the expression is a string, get the string value
        printOperand = ctx->LETRERO_VALOR()->getText();
        // allocate memory for the string
        int address = memoryManager.getOrCreateConstant(STRING, printOperand);
        // handle memory allocation error
        handleMemoryAllocationError(address, ctx->getStart());
        // push the operand to the operand stack
        operandStack.push(printOperand);
    }
    // pop the operand
    printOperand = operandStack.top(); operandStack.pop();
    // pop the type
    Type printType = typeStack.top(); typeStack.pop();
    // generate quadruple to print the operand
    generateQuadruple("PRINT", printOperand, "nil", "nil");
    return nullptr;
}

// ciclo: WHILE PARENIZQ expresion PARENDER LLAVEIZQ cuerpo LLAVEDER PUNTOYCOMA;
antlrcpp::Any CustomVisitor::visitCiclo(PanicoParser::CicloContext *ctx) {
    // save the current quadruple index
    int startAddress = quadruples.size();
    // evaluate the loop condition
    visit(ctx->expresion());
    // pop the result of the expression
    std::string result = operandStack.top(); operandStack.pop();
    // pop the type of the result of the expression
    Type resultType = typeStack.top(); typeStack.pop();
    // type checking
    if (resultType != INT) {
        std::cerr << "Condition must be of type bool." << std::endl;
        return nullptr;
    }
    // generate the GOTO false quadruple
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
    quadruples[exitAddress].result.name = std::to_string(quadruples.size());
    return nullptr;
}

// condicion: IF PARENIZQ expresion PARENDER LLAVEIZQ cuerpo LLAVEDER (ELSE LLAVEIZQ cuerpo LLAVEDER)? PUNTOYCOMA;
antlrcpp::Any CustomVisitor::visitCondicion(PanicoParser::CondicionContext *ctx) {
    // visit the expression
    visit(ctx->expresion());
    // pop the result of the expression
    std::string result = operandStack.top(); operandStack.pop();
    // pop the type of the result of the expression
    Type resultType = typeStack.top(); typeStack.pop();
    // type checking
    if (resultType != INT) {
        std::cerr << "Condition must be of type INT." << std::endl;
        return nullptr;
    }
    // generate quadruple to jump if false and push the jump label
    int gotofQuadIndex = quadruples.size();
    generateQuadruple("GOTOF", result, "nil", "pending");
    // push the jump target to the jump stack
    jumpStack.push(gotofQuadIndex);
    // visit the body of the if statement
    visit(ctx->cuerpo(0));
    // if there is an else statement, generate quadruple to jump to end of else and push the jump label
    if (ctx->ELSE() != nullptr) {
        // handle else part
        int gotoQuadIndex = quadruples.size();
        // generate GOTO quadruple to jump to the end of the else statement
        generateQuadruple("GOTO", "nil", "nil", "pending");
        // update the GOTOF target to jump to the else statement
        int gotofAddress = jumpStack.top(); jumpStack.pop();
        // fill the GOTOF target
        quadruples[gotofAddress].result.name = std::to_string(quadruples.size());
        // push the new GOTO location and visit the else statement
        jumpStack.push(gotoQuadIndex);
        visit(ctx->cuerpo(1));
    }
    // fill the final jump target
    int exitAddress = jumpStack.top(); jumpStack.pop();
    quadruples[exitAddress].result.name = std::to_string(quadruples.size());
    return nullptr;
}

// llamada: ID PARENIZQ (expresion (COMA expresion)*)? PARENDER PUNTOYCOMA;
antlrcpp::Any CustomVisitor::visitLlamada(PanicoParser::LlamadaContext *ctx) {
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
        std::string argument = operandStack.top(); operandStack.pop();
        // pop the type of the result of the expression
        Type argumentType = typeStack.top(); typeStack.pop();
        // get the expected parameter type
        Type expectedType = funcInfo->parametersTable[i].type;
        // param address
        int address = funcInfo->parametersTable[i].memoryAddress;
        // type checking
        if (argumentType != expectedType) {
            antlr4::Token *startToken = ctx->expresion(i)->getStart();
            int line = startToken->getLine();
            int column = startToken->getCharPositionInLine();
            std::cerr << "Argument " << i + 1 << " for function " << funcName << " must be of type " << semanticCube.getStringFromType(expectedType) << ". Line: " << line << ", Column: " << column << std::endl;
            return nullptr;
        }
        // generate PARAM quadruple
        generateQuadruple("PARAM", argument, "nil", std::to_string(address));
    }
    // generate GOSUB quadruple to call the function
    int startAddress = funcInfo->startAddress;
    generateQuadruple("GOSUB", funcName, "nil", std::to_string(startAddress));
    return nullptr;
}



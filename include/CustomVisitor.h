// CustomVisitor.h
#ifndef CUSTOM_VISITOR_H
#define CUSTOM_VISITOR_H

#include <iostream>
#include <fstream>
#include <stack>
#include "antlr4-runtime.h"
#include "../generated/PanicoLexer.h"
#include "../generated/PanicoParser.h"
#include "../generated/PanicoBaseVisitor.h"
#include "FunctionDirectory.h"
#include "SemanticCube.h"
#include "VariableTable.h"
#include "MemoryManager.h"

struct QuadrupleValue {
    std::string name;
    int address;
};


struct Quadruple {
    QuadrupleValue op;
    QuadrupleValue arg1;
    QuadrupleValue arg2;
    QuadrupleValue result;
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
    
    MemoryManager memoryManager;

    std::string createTempVar();

    std::string createParamVar();
    void generateQuadruple(const std::string &op, const std::string &arg1, const std::string &arg2, const std::string &result);
    int getAddress(const std::string &var);
    int allocateMemory(Type type, bool isGlobal);
    void handleMemoryAllocationError(int address, antlr4::Token *startToken);
    void handleVarInfoError(std::string var, antlr4::Token *startToken);

    antlrcpp::Any visitPrograma(PanicoParser::ProgramaContext *ctx) override;
    antlrcpp::Any visitFuncs(PanicoParser::FuncsContext *ctx) override;
    antlrcpp::Any visitLlamada(PanicoParser::LlamadaContext *ctx) override;
    antlrcpp::Any visitParams(PanicoParser::ParamsContext *ctx) override;
    antlrcpp::Any visitVars(PanicoParser::VarsContext *ctx) override;
    antlrcpp::Any visitDecl_var(PanicoParser::Decl_varContext *ctx) override;
    antlrcpp::Any visitCuerpo(PanicoParser::CuerpoContext *ctx) override;
    antlrcpp::Any visitEstatuto(PanicoParser::EstatutoContext *ctx) override;
    antlrcpp::Any visitAsigna(PanicoParser::AsignaContext *ctx) override;
    antlrcpp::Any visitExpresion(PanicoParser::ExpresionContext *ctx) override;
    antlrcpp::Any visitExp(PanicoParser::ExpContext *ctx) override;
    antlrcpp::Any visitTermino(PanicoParser::TerminoContext *ctx) override;
    antlrcpp::Any visitFactor(PanicoParser::FactorContext *ctx) override;
    antlrcpp::Any visitImprime(PanicoParser::ImprimeContext *ctx) override;
    antlrcpp::Any visitCondicion(PanicoParser::CondicionContext *ctx) override;
    antlrcpp::Any visitCiclo(PanicoParser::CicloContext *ctx) override;
    antlrcpp::Any visitImpr(PanicoParser::ImprContext *ctx) override;
};

#endif // CUSTOM_VISITOR_H
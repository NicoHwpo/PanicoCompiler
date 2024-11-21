
// Generated from Panico.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PanicoParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PanicoParser.
 */
class  PanicoVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PanicoParser.
   */
    virtual std::any visitPrograma(PanicoParser::ProgramaContext *context) = 0;

    virtual std::any visitVars(PanicoParser::VarsContext *context) = 0;

    virtual std::any visitDecl_var(PanicoParser::Decl_varContext *context) = 0;

    virtual std::any visitTipo(PanicoParser::TipoContext *context) = 0;

    virtual std::any visitFuncs(PanicoParser::FuncsContext *context) = 0;

    virtual std::any visitParams(PanicoParser::ParamsContext *context) = 0;

    virtual std::any visitCuerpo(PanicoParser::CuerpoContext *context) = 0;

    virtual std::any visitEstatuto(PanicoParser::EstatutoContext *context) = 0;

    virtual std::any visitAsigna(PanicoParser::AsignaContext *context) = 0;

    virtual std::any visitExpresion(PanicoParser::ExpresionContext *context) = 0;

    virtual std::any visitExp(PanicoParser::ExpContext *context) = 0;

    virtual std::any visitTermino(PanicoParser::TerminoContext *context) = 0;

    virtual std::any visitFactor(PanicoParser::FactorContext *context) = 0;

    virtual std::any visitCte(PanicoParser::CteContext *context) = 0;

    virtual std::any visitCondicion(PanicoParser::CondicionContext *context) = 0;

    virtual std::any visitCiclo(PanicoParser::CicloContext *context) = 0;

    virtual std::any visitLlamada(PanicoParser::LlamadaContext *context) = 0;

    virtual std::any visitImprime(PanicoParser::ImprimeContext *context) = 0;

    virtual std::any visitImpr(PanicoParser::ImprContext *context) = 0;


};


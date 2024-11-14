
// Generated from Panico.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PanicoVisitor.h"


/**
 * This class provides an empty implementation of PanicoVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PanicoBaseVisitor : public PanicoVisitor {
public:

  virtual std::any visitPrograma(PanicoParser::ProgramaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVars(PanicoParser::VarsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_var(PanicoParser::Decl_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTipo(PanicoParser::TipoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncs(PanicoParser::FuncsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(PanicoParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCuerpo(PanicoParser::CuerpoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEstatuto(PanicoParser::EstatutoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsigna(PanicoParser::AsignaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpresion(PanicoParser::ExpresionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp(PanicoParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermino(PanicoParser::TerminoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(PanicoParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCte(PanicoParser::CteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondicion(PanicoParser::CondicionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCiclo(PanicoParser::CicloContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLlamada(PanicoParser::LlamadaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImprime(PanicoParser::ImprimeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImpr(PanicoParser::ImprContext *ctx) override {
    return visitChildren(ctx);
  }


};


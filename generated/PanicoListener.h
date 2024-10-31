
// Generated from Panico.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PanicoParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PanicoParser.
 */
class  PanicoListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPrograma(PanicoParser::ProgramaContext *ctx) = 0;
  virtual void exitPrograma(PanicoParser::ProgramaContext *ctx) = 0;

  virtual void enterVars(PanicoParser::VarsContext *ctx) = 0;
  virtual void exitVars(PanicoParser::VarsContext *ctx) = 0;

  virtual void enterDecl_var(PanicoParser::Decl_varContext *ctx) = 0;
  virtual void exitDecl_var(PanicoParser::Decl_varContext *ctx) = 0;

  virtual void enterTipo(PanicoParser::TipoContext *ctx) = 0;
  virtual void exitTipo(PanicoParser::TipoContext *ctx) = 0;

  virtual void enterFuncs(PanicoParser::FuncsContext *ctx) = 0;
  virtual void exitFuncs(PanicoParser::FuncsContext *ctx) = 0;

  virtual void enterParams(PanicoParser::ParamsContext *ctx) = 0;
  virtual void exitParams(PanicoParser::ParamsContext *ctx) = 0;

  virtual void enterCuerpo(PanicoParser::CuerpoContext *ctx) = 0;
  virtual void exitCuerpo(PanicoParser::CuerpoContext *ctx) = 0;

  virtual void enterEstatuto(PanicoParser::EstatutoContext *ctx) = 0;
  virtual void exitEstatuto(PanicoParser::EstatutoContext *ctx) = 0;

  virtual void enterAsigna(PanicoParser::AsignaContext *ctx) = 0;
  virtual void exitAsigna(PanicoParser::AsignaContext *ctx) = 0;

  virtual void enterExpresion(PanicoParser::ExpresionContext *ctx) = 0;
  virtual void exitExpresion(PanicoParser::ExpresionContext *ctx) = 0;

  virtual void enterExp(PanicoParser::ExpContext *ctx) = 0;
  virtual void exitExp(PanicoParser::ExpContext *ctx) = 0;

  virtual void enterTermino(PanicoParser::TerminoContext *ctx) = 0;
  virtual void exitTermino(PanicoParser::TerminoContext *ctx) = 0;

  virtual void enterFactor(PanicoParser::FactorContext *ctx) = 0;
  virtual void exitFactor(PanicoParser::FactorContext *ctx) = 0;

  virtual void enterCte(PanicoParser::CteContext *ctx) = 0;
  virtual void exitCte(PanicoParser::CteContext *ctx) = 0;

  virtual void enterCondicion(PanicoParser::CondicionContext *ctx) = 0;
  virtual void exitCondicion(PanicoParser::CondicionContext *ctx) = 0;

  virtual void enterCiclo(PanicoParser::CicloContext *ctx) = 0;
  virtual void exitCiclo(PanicoParser::CicloContext *ctx) = 0;

  virtual void enterLlamada(PanicoParser::LlamadaContext *ctx) = 0;
  virtual void exitLlamada(PanicoParser::LlamadaContext *ctx) = 0;

  virtual void enterImprime(PanicoParser::ImprimeContext *ctx) = 0;
  virtual void exitImprime(PanicoParser::ImprimeContext *ctx) = 0;

  virtual void enterImpr(PanicoParser::ImprContext *ctx) = 0;
  virtual void exitImpr(PanicoParser::ImprContext *ctx) = 0;


};


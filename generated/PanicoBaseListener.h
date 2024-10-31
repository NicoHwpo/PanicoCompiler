
// Generated from Panico.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PanicoListener.h"


/**
 * This class provides an empty implementation of PanicoListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PanicoBaseListener : public PanicoListener {
public:

  virtual void enterPrograma(PanicoParser::ProgramaContext * /*ctx*/) override { }
  virtual void exitPrograma(PanicoParser::ProgramaContext * /*ctx*/) override { }

  virtual void enterVars(PanicoParser::VarsContext * /*ctx*/) override { }
  virtual void exitVars(PanicoParser::VarsContext * /*ctx*/) override { }

  virtual void enterDecl_var(PanicoParser::Decl_varContext * /*ctx*/) override { }
  virtual void exitDecl_var(PanicoParser::Decl_varContext * /*ctx*/) override { }

  virtual void enterTipo(PanicoParser::TipoContext * /*ctx*/) override { }
  virtual void exitTipo(PanicoParser::TipoContext * /*ctx*/) override { }

  virtual void enterFuncs(PanicoParser::FuncsContext * /*ctx*/) override { }
  virtual void exitFuncs(PanicoParser::FuncsContext * /*ctx*/) override { }

  virtual void enterParams(PanicoParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(PanicoParser::ParamsContext * /*ctx*/) override { }

  virtual void enterCuerpo(PanicoParser::CuerpoContext * /*ctx*/) override { }
  virtual void exitCuerpo(PanicoParser::CuerpoContext * /*ctx*/) override { }

  virtual void enterEstatuto(PanicoParser::EstatutoContext * /*ctx*/) override { }
  virtual void exitEstatuto(PanicoParser::EstatutoContext * /*ctx*/) override { }

  virtual void enterAsigna(PanicoParser::AsignaContext * /*ctx*/) override { }
  virtual void exitAsigna(PanicoParser::AsignaContext * /*ctx*/) override { }

  virtual void enterExpresion(PanicoParser::ExpresionContext * /*ctx*/) override { }
  virtual void exitExpresion(PanicoParser::ExpresionContext * /*ctx*/) override { }

  virtual void enterExp(PanicoParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(PanicoParser::ExpContext * /*ctx*/) override { }

  virtual void enterTermino(PanicoParser::TerminoContext * /*ctx*/) override { }
  virtual void exitTermino(PanicoParser::TerminoContext * /*ctx*/) override { }

  virtual void enterFactor(PanicoParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(PanicoParser::FactorContext * /*ctx*/) override { }

  virtual void enterCte(PanicoParser::CteContext * /*ctx*/) override { }
  virtual void exitCte(PanicoParser::CteContext * /*ctx*/) override { }

  virtual void enterCondicion(PanicoParser::CondicionContext * /*ctx*/) override { }
  virtual void exitCondicion(PanicoParser::CondicionContext * /*ctx*/) override { }

  virtual void enterCiclo(PanicoParser::CicloContext * /*ctx*/) override { }
  virtual void exitCiclo(PanicoParser::CicloContext * /*ctx*/) override { }

  virtual void enterLlamada(PanicoParser::LlamadaContext * /*ctx*/) override { }
  virtual void exitLlamada(PanicoParser::LlamadaContext * /*ctx*/) override { }

  virtual void enterImprime(PanicoParser::ImprimeContext * /*ctx*/) override { }
  virtual void exitImprime(PanicoParser::ImprimeContext * /*ctx*/) override { }

  virtual void enterImpr(PanicoParser::ImprContext * /*ctx*/) override { }
  virtual void exitImpr(PanicoParser::ImprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


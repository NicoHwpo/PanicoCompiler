
// Generated from Panico.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PanicoParser : public antlr4::Parser {
public:
  enum {
    PROGRAMA = 1, INICIO = 2, FIN = 3, VARS = 4, INT = 5, FLOAT = 6, PRINT = 7, 
    WHILE = 8, VOID = 9, IF = 10, ELSE = 11, PUNTOYCOMA = 12, COMA = 13, 
    DOSPUNTOS = 14, LLAVEIZQ = 15, LLAVEDER = 16, PARENIZQ = 17, PARENDER = 18, 
    IGUAL = 19, MAYORQUE = 20, MENORQUE = 21, DIFERENTE = 22, IGUALIGUAL = 23, 
    MAS = 24, MENOS = 25, MULT = 26, DIV = 27, ID = 28, CTE_ENT = 29, CTE_FLOT = 30, 
    LETRERO_VALOR = 31, WS = 32
  };

  enum {
    RulePrograma = 0, RuleVars = 1, RuleDecl_var = 2, RuleTipo = 3, RuleFuncs = 4, 
    RuleParams = 5, RuleCuerpo = 6, RuleEstatuto = 7, RuleAsigna = 8, RuleExpresion = 9, 
    RuleExp = 10, RuleTermino = 11, RuleFactor = 12, RuleCte = 13, RuleCondicion = 14, 
    RuleCiclo = 15, RuleLlamada = 16, RuleImprime = 17, RuleImpr = 18
  };

  explicit PanicoParser(antlr4::TokenStream *input);

  PanicoParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~PanicoParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramaContext;
  class VarsContext;
  class Decl_varContext;
  class TipoContext;
  class FuncsContext;
  class ParamsContext;
  class CuerpoContext;
  class EstatutoContext;
  class AsignaContext;
  class ExpresionContext;
  class ExpContext;
  class TerminoContext;
  class FactorContext;
  class CteContext;
  class CondicionContext;
  class CicloContext;
  class LlamadaContext;
  class ImprimeContext;
  class ImprContext; 

  class  ProgramaContext : public antlr4::ParserRuleContext {
  public:
    ProgramaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGRAMA();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *PUNTOYCOMA();
    antlr4::tree::TerminalNode *INICIO();
    antlr4::tree::TerminalNode *LLAVEIZQ();
    CuerpoContext *cuerpo();
    antlr4::tree::TerminalNode *LLAVEDER();
    antlr4::tree::TerminalNode *FIN();
    VarsContext *vars();
    std::vector<FuncsContext *> funcs();
    FuncsContext* funcs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramaContext* programa();

  class  VarsContext : public antlr4::ParserRuleContext {
  public:
    VarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARS();
    antlr4::tree::TerminalNode *LLAVEIZQ();
    antlr4::tree::TerminalNode *LLAVEDER();
    std::vector<Decl_varContext *> decl_var();
    Decl_varContext* decl_var(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarsContext* vars();

  class  Decl_varContext : public antlr4::ParserRuleContext {
  public:
    Decl_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *DOSPUNTOS();
    TipoContext *tipo();
    antlr4::tree::TerminalNode *PUNTOYCOMA();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_varContext* decl_var();

  class  TipoContext : public antlr4::ParserRuleContext {
  public:
    TipoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TipoContext* tipo();

  class  FuncsContext : public antlr4::ParserRuleContext {
  public:
    FuncsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VOID();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *PARENIZQ();
    antlr4::tree::TerminalNode *PARENDER();
    antlr4::tree::TerminalNode *LLAVEIZQ();
    CuerpoContext *cuerpo();
    antlr4::tree::TerminalNode *LLAVEDER();
    antlr4::tree::TerminalNode *PUNTOYCOMA();
    ParamsContext *params();
    VarsContext *vars();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncsContext* funcs();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOSPUNTOS();
    antlr4::tree::TerminalNode* DOSPUNTOS(size_t i);
    std::vector<TipoContext *> tipo();
    TipoContext* tipo(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  CuerpoContext : public antlr4::ParserRuleContext {
  public:
    CuerpoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EstatutoContext *> estatuto();
    EstatutoContext* estatuto(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CuerpoContext* cuerpo();

  class  EstatutoContext : public antlr4::ParserRuleContext {
  public:
    EstatutoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AsignaContext *asigna();
    CondicionContext *condicion();
    CicloContext *ciclo();
    LlamadaContext *llamada();
    ImprimeContext *imprime();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EstatutoContext* estatuto();

  class  AsignaContext : public antlr4::ParserRuleContext {
  public:
    AsignaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *IGUAL();
    ExpresionContext *expresion();
    antlr4::tree::TerminalNode *PUNTOYCOMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AsignaContext* asigna();

  class  ExpresionContext : public antlr4::ParserRuleContext {
  public:
    ExpresionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    antlr4::tree::TerminalNode *MAYORQUE();
    antlr4::tree::TerminalNode *MENORQUE();
    antlr4::tree::TerminalNode *DIFERENTE();
    antlr4::tree::TerminalNode *IGUALIGUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpresionContext* expresion();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TerminoContext *> termino();
    TerminoContext* termino(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MAS();
    antlr4::tree::TerminalNode* MAS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MENOS();
    antlr4::tree::TerminalNode* MENOS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpContext* exp();

  class  TerminoContext : public antlr4::ParserRuleContext {
  public:
    TerminoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MULT();
    antlr4::tree::TerminalNode* MULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TerminoContext* termino();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARENIZQ();
    ExpresionContext *expresion();
    antlr4::tree::TerminalNode *PARENDER();
    antlr4::tree::TerminalNode *ID();
    CteContext *cte();
    antlr4::tree::TerminalNode *MENOS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  CteContext : public antlr4::ParserRuleContext {
  public:
    CteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CTE_ENT();
    antlr4::tree::TerminalNode *CTE_FLOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CteContext* cte();

  class  CondicionContext : public antlr4::ParserRuleContext {
  public:
    CondicionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *PARENIZQ();
    ExpresionContext *expresion();
    antlr4::tree::TerminalNode *PARENDER();
    std::vector<antlr4::tree::TerminalNode *> LLAVEIZQ();
    antlr4::tree::TerminalNode* LLAVEIZQ(size_t i);
    std::vector<CuerpoContext *> cuerpo();
    CuerpoContext* cuerpo(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LLAVEDER();
    antlr4::tree::TerminalNode* LLAVEDER(size_t i);
    antlr4::tree::TerminalNode *PUNTOYCOMA();
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondicionContext* condicion();

  class  CicloContext : public antlr4::ParserRuleContext {
  public:
    CicloContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PARENIZQ();
    ExpresionContext *expresion();
    antlr4::tree::TerminalNode *PARENDER();
    antlr4::tree::TerminalNode *LLAVEIZQ();
    CuerpoContext *cuerpo();
    antlr4::tree::TerminalNode *LLAVEDER();
    antlr4::tree::TerminalNode *PUNTOYCOMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CicloContext* ciclo();

  class  LlamadaContext : public antlr4::ParserRuleContext {
  public:
    LlamadaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *PARENIZQ();
    antlr4::tree::TerminalNode *PARENDER();
    antlr4::tree::TerminalNode *PUNTOYCOMA();
    std::vector<ExpresionContext *> expresion();
    ExpresionContext* expresion(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LlamadaContext* llamada();

  class  ImprimeContext : public antlr4::ParserRuleContext {
  public:
    ImprimeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    antlr4::tree::TerminalNode *PARENIZQ();
    std::vector<ImprContext *> impr();
    ImprContext* impr(size_t i);
    antlr4::tree::TerminalNode *PARENDER();
    antlr4::tree::TerminalNode *PUNTOYCOMA();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImprimeContext* imprime();

  class  ImprContext : public antlr4::ParserRuleContext {
  public:
    ImprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpresionContext *expresion();
    antlr4::tree::TerminalNode *LETRERO_VALOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImprContext* impr();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};


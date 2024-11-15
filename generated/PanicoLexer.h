
// Generated from Panico.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PanicoLexer : public antlr4::Lexer {
public:
  enum {
    PROGRAM = 1, START = 2, END = 3, VARS = 4, INT = 5, FLOAT = 6, PRINT = 7, 
    WHILE = 8, VOID = 9, IF = 10, ELSE = 11, PUNTOYCOMA = 12, COMA = 13, 
    DOSPUNTOS = 14, LLAVEIZQ = 15, LLAVEDER = 16, PARENIZQ = 17, PARENDER = 18, 
    IGUAL = 19, MAYORQUE = 20, MENORQUE = 21, DIFERENTE = 22, IGUALIGUAL = 23, 
    MAS = 24, MENOS = 25, MULT = 26, DIV = 27, ID = 28, CTE_ENT = 29, CTE_FLOT = 30, 
    LETRERO_VALOR = 31, WS = 32
  };

  explicit PanicoLexer(antlr4::CharStream *input);

  ~PanicoLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};


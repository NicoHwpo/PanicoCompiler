
// Generated from Panico.g4 by ANTLR 4.13.2


#include "PanicoListener.h"
#include "PanicoVisitor.h"

#include "PanicoParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PanicoParserStaticData final {
  PanicoParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PanicoParserStaticData(const PanicoParserStaticData&) = delete;
  PanicoParserStaticData(PanicoParserStaticData&&) = delete;
  PanicoParserStaticData& operator=(const PanicoParserStaticData&) = delete;
  PanicoParserStaticData& operator=(PanicoParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag panicoParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PanicoParserStaticData> panicoParserStaticData = nullptr;

void panicoParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (panicoParserStaticData != nullptr) {
    return;
  }
#else
  assert(panicoParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PanicoParserStaticData>(
    std::vector<std::string>{
      "programa", "vars", "decl_var", "tipo", "funcs", "params", "cuerpo", 
      "estatuto", "asigna", "expresion", "exp", "termino", "factor", "cte", 
      "condicion", "ciclo", "llamada", "imprime", "impr"
    },
    std::vector<std::string>{
      "", "'program'", "'start'", "'end'", "'vars'", "'int'", "'float'", 
      "'print'", "'while'", "'void'", "'if'", "'else'", "';'", "','", "':'", 
      "'{'", "'}'", "'('", "')'", "'='", "'>'", "'<'", "'!='", "'=='", "'+'", 
      "'-'", "'*'", "'/'"
    },
    std::vector<std::string>{
      "", "PROGRAM", "START", "END", "VARS", "INT", "FLOAT", "PRINT", "WHILE", 
      "VOID", "IF", "ELSE", "PUNTOYCOMA", "COMA", "DOSPUNTOS", "LLAVEIZQ", 
      "LLAVEDER", "PARENIZQ", "PARENDER", "IGUAL", "MAYORQUE", "MENORQUE", 
      "DIFERENTE", "IGUALIGUAL", "MAS", "MENOS", "MULT", "DIV", "ID", "CTE_ENT", 
      "CTE_FLOT", "LETRERO_VALOR", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,32,218,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,0,1,0,3,0,43,8,0,
  	1,0,5,0,46,8,0,10,0,12,0,49,9,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,4,
  	1,60,8,1,11,1,12,1,61,1,1,1,1,1,2,1,2,1,2,5,2,69,8,2,10,2,12,2,72,9,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,3,4,84,8,4,1,4,1,4,1,4,3,4,89,
  	8,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,102,8,5,10,5,12,5,
  	105,9,5,1,6,5,6,108,8,6,10,6,12,6,111,9,6,1,7,1,7,1,7,1,7,1,7,3,7,118,
  	8,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,3,9,128,8,9,1,10,1,10,1,10,5,10,133,
  	8,10,10,10,12,10,136,9,10,1,11,1,11,1,11,5,11,141,8,11,10,11,12,11,144,
  	9,11,1,12,1,12,1,12,1,12,1,12,3,12,151,8,12,1,12,1,12,3,12,155,8,12,3,
  	12,157,8,12,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,3,14,173,8,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,5,16,191,8,16,10,16,12,16,194,9,
  	16,3,16,196,8,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,5,17,206,8,17,
  	10,17,12,17,209,9,17,1,17,1,17,1,17,1,18,1,18,3,18,216,8,18,1,18,0,0,
  	19,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,0,5,1,0,5,6,1,
  	0,20,23,1,0,24,25,1,0,26,27,1,0,29,30,221,0,38,1,0,0,0,2,56,1,0,0,0,4,
  	65,1,0,0,0,6,77,1,0,0,0,8,79,1,0,0,0,10,94,1,0,0,0,12,109,1,0,0,0,14,
  	117,1,0,0,0,16,119,1,0,0,0,18,124,1,0,0,0,20,129,1,0,0,0,22,137,1,0,0,
  	0,24,156,1,0,0,0,26,158,1,0,0,0,28,160,1,0,0,0,30,176,1,0,0,0,32,185,
  	1,0,0,0,34,200,1,0,0,0,36,215,1,0,0,0,38,39,5,1,0,0,39,40,5,28,0,0,40,
  	42,5,12,0,0,41,43,3,2,1,0,42,41,1,0,0,0,42,43,1,0,0,0,43,47,1,0,0,0,44,
  	46,3,8,4,0,45,44,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,0,48,
  	50,1,0,0,0,49,47,1,0,0,0,50,51,5,2,0,0,51,52,5,15,0,0,52,53,3,12,6,0,
  	53,54,5,16,0,0,54,55,5,3,0,0,55,1,1,0,0,0,56,57,5,4,0,0,57,59,5,15,0,
  	0,58,60,3,4,2,0,59,58,1,0,0,0,60,61,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,
  	0,62,63,1,0,0,0,63,64,5,16,0,0,64,3,1,0,0,0,65,70,5,28,0,0,66,67,5,13,
  	0,0,67,69,5,28,0,0,68,66,1,0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,1,
  	0,0,0,71,73,1,0,0,0,72,70,1,0,0,0,73,74,5,14,0,0,74,75,3,6,3,0,75,76,
  	5,12,0,0,76,5,1,0,0,0,77,78,7,0,0,0,78,7,1,0,0,0,79,80,5,9,0,0,80,81,
  	5,28,0,0,81,83,5,17,0,0,82,84,3,10,5,0,83,82,1,0,0,0,83,84,1,0,0,0,84,
  	85,1,0,0,0,85,86,5,18,0,0,86,88,5,15,0,0,87,89,3,2,1,0,88,87,1,0,0,0,
  	88,89,1,0,0,0,89,90,1,0,0,0,90,91,3,12,6,0,91,92,5,16,0,0,92,93,5,12,
  	0,0,93,9,1,0,0,0,94,95,5,28,0,0,95,96,5,14,0,0,96,103,3,6,3,0,97,98,5,
  	13,0,0,98,99,5,28,0,0,99,100,5,14,0,0,100,102,3,6,3,0,101,97,1,0,0,0,
  	102,105,1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,11,1,0,0,0,105,103,
  	1,0,0,0,106,108,3,14,7,0,107,106,1,0,0,0,108,111,1,0,0,0,109,107,1,0,
  	0,0,109,110,1,0,0,0,110,13,1,0,0,0,111,109,1,0,0,0,112,118,3,16,8,0,113,
  	118,3,28,14,0,114,118,3,30,15,0,115,118,3,32,16,0,116,118,3,34,17,0,117,
  	112,1,0,0,0,117,113,1,0,0,0,117,114,1,0,0,0,117,115,1,0,0,0,117,116,1,
  	0,0,0,118,15,1,0,0,0,119,120,5,28,0,0,120,121,5,19,0,0,121,122,3,18,9,
  	0,122,123,5,12,0,0,123,17,1,0,0,0,124,127,3,20,10,0,125,126,7,1,0,0,126,
  	128,3,20,10,0,127,125,1,0,0,0,127,128,1,0,0,0,128,19,1,0,0,0,129,134,
  	3,22,11,0,130,131,7,2,0,0,131,133,3,22,11,0,132,130,1,0,0,0,133,136,1,
  	0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,21,1,0,0,0,136,134,1,0,0,0,
  	137,142,3,24,12,0,138,139,7,3,0,0,139,141,3,24,12,0,140,138,1,0,0,0,141,
  	144,1,0,0,0,142,140,1,0,0,0,142,143,1,0,0,0,143,23,1,0,0,0,144,142,1,
  	0,0,0,145,146,5,17,0,0,146,147,3,18,9,0,147,148,5,18,0,0,148,157,1,0,
  	0,0,149,151,5,25,0,0,150,149,1,0,0,0,150,151,1,0,0,0,151,154,1,0,0,0,
  	152,155,5,28,0,0,153,155,3,26,13,0,154,152,1,0,0,0,154,153,1,0,0,0,155,
  	157,1,0,0,0,156,145,1,0,0,0,156,150,1,0,0,0,157,25,1,0,0,0,158,159,7,
  	4,0,0,159,27,1,0,0,0,160,161,5,10,0,0,161,162,5,17,0,0,162,163,3,18,9,
  	0,163,164,5,18,0,0,164,165,5,15,0,0,165,166,3,12,6,0,166,172,5,16,0,0,
  	167,168,5,11,0,0,168,169,5,15,0,0,169,170,3,12,6,0,170,171,5,16,0,0,171,
  	173,1,0,0,0,172,167,1,0,0,0,172,173,1,0,0,0,173,174,1,0,0,0,174,175,5,
  	12,0,0,175,29,1,0,0,0,176,177,5,8,0,0,177,178,5,17,0,0,178,179,3,18,9,
  	0,179,180,5,18,0,0,180,181,5,15,0,0,181,182,3,12,6,0,182,183,5,16,0,0,
  	183,184,5,12,0,0,184,31,1,0,0,0,185,186,5,28,0,0,186,195,5,17,0,0,187,
  	192,3,18,9,0,188,189,5,13,0,0,189,191,3,18,9,0,190,188,1,0,0,0,191,194,
  	1,0,0,0,192,190,1,0,0,0,192,193,1,0,0,0,193,196,1,0,0,0,194,192,1,0,0,
  	0,195,187,1,0,0,0,195,196,1,0,0,0,196,197,1,0,0,0,197,198,5,18,0,0,198,
  	199,5,12,0,0,199,33,1,0,0,0,200,201,5,7,0,0,201,202,5,17,0,0,202,207,
  	3,36,18,0,203,204,5,13,0,0,204,206,3,36,18,0,205,203,1,0,0,0,206,209,
  	1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,210,1,0,0,0,209,207,1,0,0,
  	0,210,211,5,18,0,0,211,212,5,12,0,0,212,35,1,0,0,0,213,216,3,18,9,0,214,
  	216,5,31,0,0,215,213,1,0,0,0,215,214,1,0,0,0,216,37,1,0,0,0,20,42,47,
  	61,70,83,88,103,109,117,127,134,142,150,154,156,172,192,195,207,215
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  panicoParserStaticData = std::move(staticData);
}

}

PanicoParser::PanicoParser(TokenStream *input) : PanicoParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PanicoParser::PanicoParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PanicoParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *panicoParserStaticData->atn, panicoParserStaticData->decisionToDFA, panicoParserStaticData->sharedContextCache, options);
}

PanicoParser::~PanicoParser() {
  delete _interpreter;
}

const atn::ATN& PanicoParser::getATN() const {
  return *panicoParserStaticData->atn;
}

std::string PanicoParser::getGrammarFileName() const {
  return "Panico.g4";
}

const std::vector<std::string>& PanicoParser::getRuleNames() const {
  return panicoParserStaticData->ruleNames;
}

const dfa::Vocabulary& PanicoParser::getVocabulary() const {
  return panicoParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PanicoParser::getSerializedATN() const {
  return panicoParserStaticData->serializedATN;
}


//----------------- ProgramaContext ------------------------------------------------------------------

PanicoParser::ProgramaContext::ProgramaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::ProgramaContext::PROGRAM() {
  return getToken(PanicoParser::PROGRAM, 0);
}

tree::TerminalNode* PanicoParser::ProgramaContext::ID() {
  return getToken(PanicoParser::ID, 0);
}

tree::TerminalNode* PanicoParser::ProgramaContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}

tree::TerminalNode* PanicoParser::ProgramaContext::START() {
  return getToken(PanicoParser::START, 0);
}

tree::TerminalNode* PanicoParser::ProgramaContext::LLAVEIZQ() {
  return getToken(PanicoParser::LLAVEIZQ, 0);
}

PanicoParser::CuerpoContext* PanicoParser::ProgramaContext::cuerpo() {
  return getRuleContext<PanicoParser::CuerpoContext>(0);
}

tree::TerminalNode* PanicoParser::ProgramaContext::LLAVEDER() {
  return getToken(PanicoParser::LLAVEDER, 0);
}

tree::TerminalNode* PanicoParser::ProgramaContext::END() {
  return getToken(PanicoParser::END, 0);
}

PanicoParser::VarsContext* PanicoParser::ProgramaContext::vars() {
  return getRuleContext<PanicoParser::VarsContext>(0);
}

std::vector<PanicoParser::FuncsContext *> PanicoParser::ProgramaContext::funcs() {
  return getRuleContexts<PanicoParser::FuncsContext>();
}

PanicoParser::FuncsContext* PanicoParser::ProgramaContext::funcs(size_t i) {
  return getRuleContext<PanicoParser::FuncsContext>(i);
}


size_t PanicoParser::ProgramaContext::getRuleIndex() const {
  return PanicoParser::RulePrograma;
}

void PanicoParser::ProgramaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrograma(this);
}

void PanicoParser::ProgramaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrograma(this);
}


std::any PanicoParser::ProgramaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitPrograma(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::ProgramaContext* PanicoParser::programa() {
  ProgramaContext *_localctx = _tracker.createInstance<ProgramaContext>(_ctx, getState());
  enterRule(_localctx, 0, PanicoParser::RulePrograma);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(PanicoParser::PROGRAM);
    setState(39);
    match(PanicoParser::ID);
    setState(40);
    match(PanicoParser::PUNTOYCOMA);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PanicoParser::VARS) {
      setState(41);
      vars();
    }
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PanicoParser::VOID) {
      setState(44);
      funcs();
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(50);
    match(PanicoParser::START);
    setState(51);
    match(PanicoParser::LLAVEIZQ);
    setState(52);
    cuerpo();
    setState(53);
    match(PanicoParser::LLAVEDER);
    setState(54);
    match(PanicoParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarsContext ------------------------------------------------------------------

PanicoParser::VarsContext::VarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::VarsContext::VARS() {
  return getToken(PanicoParser::VARS, 0);
}

tree::TerminalNode* PanicoParser::VarsContext::LLAVEIZQ() {
  return getToken(PanicoParser::LLAVEIZQ, 0);
}

tree::TerminalNode* PanicoParser::VarsContext::LLAVEDER() {
  return getToken(PanicoParser::LLAVEDER, 0);
}

std::vector<PanicoParser::Decl_varContext *> PanicoParser::VarsContext::decl_var() {
  return getRuleContexts<PanicoParser::Decl_varContext>();
}

PanicoParser::Decl_varContext* PanicoParser::VarsContext::decl_var(size_t i) {
  return getRuleContext<PanicoParser::Decl_varContext>(i);
}


size_t PanicoParser::VarsContext::getRuleIndex() const {
  return PanicoParser::RuleVars;
}

void PanicoParser::VarsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVars(this);
}

void PanicoParser::VarsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVars(this);
}


std::any PanicoParser::VarsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitVars(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::VarsContext* PanicoParser::vars() {
  VarsContext *_localctx = _tracker.createInstance<VarsContext>(_ctx, getState());
  enterRule(_localctx, 2, PanicoParser::RuleVars);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(PanicoParser::VARS);
    setState(57);
    match(PanicoParser::LLAVEIZQ);
    setState(59); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(58);
      decl_var();
      setState(61); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PanicoParser::ID);
    setState(63);
    match(PanicoParser::LLAVEDER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_varContext ------------------------------------------------------------------

PanicoParser::Decl_varContext::Decl_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PanicoParser::Decl_varContext::ID() {
  return getTokens(PanicoParser::ID);
}

tree::TerminalNode* PanicoParser::Decl_varContext::ID(size_t i) {
  return getToken(PanicoParser::ID, i);
}

tree::TerminalNode* PanicoParser::Decl_varContext::DOSPUNTOS() {
  return getToken(PanicoParser::DOSPUNTOS, 0);
}

PanicoParser::TipoContext* PanicoParser::Decl_varContext::tipo() {
  return getRuleContext<PanicoParser::TipoContext>(0);
}

tree::TerminalNode* PanicoParser::Decl_varContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}

std::vector<tree::TerminalNode *> PanicoParser::Decl_varContext::COMA() {
  return getTokens(PanicoParser::COMA);
}

tree::TerminalNode* PanicoParser::Decl_varContext::COMA(size_t i) {
  return getToken(PanicoParser::COMA, i);
}


size_t PanicoParser::Decl_varContext::getRuleIndex() const {
  return PanicoParser::RuleDecl_var;
}

void PanicoParser::Decl_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl_var(this);
}

void PanicoParser::Decl_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl_var(this);
}


std::any PanicoParser::Decl_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitDecl_var(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::Decl_varContext* PanicoParser::decl_var() {
  Decl_varContext *_localctx = _tracker.createInstance<Decl_varContext>(_ctx, getState());
  enterRule(_localctx, 4, PanicoParser::RuleDecl_var);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(PanicoParser::ID);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PanicoParser::COMA) {
      setState(66);
      match(PanicoParser::COMA);
      setState(67);
      match(PanicoParser::ID);
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
    match(PanicoParser::DOSPUNTOS);
    setState(74);
    tipo();
    setState(75);
    match(PanicoParser::PUNTOYCOMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TipoContext ------------------------------------------------------------------

PanicoParser::TipoContext::TipoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::TipoContext::INT() {
  return getToken(PanicoParser::INT, 0);
}

tree::TerminalNode* PanicoParser::TipoContext::FLOAT() {
  return getToken(PanicoParser::FLOAT, 0);
}


size_t PanicoParser::TipoContext::getRuleIndex() const {
  return PanicoParser::RuleTipo;
}

void PanicoParser::TipoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTipo(this);
}

void PanicoParser::TipoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTipo(this);
}


std::any PanicoParser::TipoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitTipo(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::TipoContext* PanicoParser::tipo() {
  TipoContext *_localctx = _tracker.createInstance<TipoContext>(_ctx, getState());
  enterRule(_localctx, 6, PanicoParser::RuleTipo);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    _la = _input->LA(1);
    if (!(_la == PanicoParser::INT

    || _la == PanicoParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncsContext ------------------------------------------------------------------

PanicoParser::FuncsContext::FuncsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::FuncsContext::VOID() {
  return getToken(PanicoParser::VOID, 0);
}

tree::TerminalNode* PanicoParser::FuncsContext::ID() {
  return getToken(PanicoParser::ID, 0);
}

tree::TerminalNode* PanicoParser::FuncsContext::PARENIZQ() {
  return getToken(PanicoParser::PARENIZQ, 0);
}

tree::TerminalNode* PanicoParser::FuncsContext::PARENDER() {
  return getToken(PanicoParser::PARENDER, 0);
}

tree::TerminalNode* PanicoParser::FuncsContext::LLAVEIZQ() {
  return getToken(PanicoParser::LLAVEIZQ, 0);
}

PanicoParser::CuerpoContext* PanicoParser::FuncsContext::cuerpo() {
  return getRuleContext<PanicoParser::CuerpoContext>(0);
}

tree::TerminalNode* PanicoParser::FuncsContext::LLAVEDER() {
  return getToken(PanicoParser::LLAVEDER, 0);
}

tree::TerminalNode* PanicoParser::FuncsContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}

PanicoParser::ParamsContext* PanicoParser::FuncsContext::params() {
  return getRuleContext<PanicoParser::ParamsContext>(0);
}

PanicoParser::VarsContext* PanicoParser::FuncsContext::vars() {
  return getRuleContext<PanicoParser::VarsContext>(0);
}


size_t PanicoParser::FuncsContext::getRuleIndex() const {
  return PanicoParser::RuleFuncs;
}

void PanicoParser::FuncsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncs(this);
}

void PanicoParser::FuncsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncs(this);
}


std::any PanicoParser::FuncsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitFuncs(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::FuncsContext* PanicoParser::funcs() {
  FuncsContext *_localctx = _tracker.createInstance<FuncsContext>(_ctx, getState());
  enterRule(_localctx, 8, PanicoParser::RuleFuncs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(PanicoParser::VOID);
    setState(80);
    match(PanicoParser::ID);
    setState(81);
    match(PanicoParser::PARENIZQ);
    setState(83);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PanicoParser::ID) {
      setState(82);
      params();
    }
    setState(85);
    match(PanicoParser::PARENDER);
    setState(86);
    match(PanicoParser::LLAVEIZQ);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PanicoParser::VARS) {
      setState(87);
      vars();
    }
    setState(90);
    cuerpo();
    setState(91);
    match(PanicoParser::LLAVEDER);
    setState(92);
    match(PanicoParser::PUNTOYCOMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

PanicoParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PanicoParser::ParamsContext::ID() {
  return getTokens(PanicoParser::ID);
}

tree::TerminalNode* PanicoParser::ParamsContext::ID(size_t i) {
  return getToken(PanicoParser::ID, i);
}

std::vector<tree::TerminalNode *> PanicoParser::ParamsContext::DOSPUNTOS() {
  return getTokens(PanicoParser::DOSPUNTOS);
}

tree::TerminalNode* PanicoParser::ParamsContext::DOSPUNTOS(size_t i) {
  return getToken(PanicoParser::DOSPUNTOS, i);
}

std::vector<PanicoParser::TipoContext *> PanicoParser::ParamsContext::tipo() {
  return getRuleContexts<PanicoParser::TipoContext>();
}

PanicoParser::TipoContext* PanicoParser::ParamsContext::tipo(size_t i) {
  return getRuleContext<PanicoParser::TipoContext>(i);
}

std::vector<tree::TerminalNode *> PanicoParser::ParamsContext::COMA() {
  return getTokens(PanicoParser::COMA);
}

tree::TerminalNode* PanicoParser::ParamsContext::COMA(size_t i) {
  return getToken(PanicoParser::COMA, i);
}


size_t PanicoParser::ParamsContext::getRuleIndex() const {
  return PanicoParser::RuleParams;
}

void PanicoParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void PanicoParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


std::any PanicoParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::ParamsContext* PanicoParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 10, PanicoParser::RuleParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(PanicoParser::ID);
    setState(95);
    match(PanicoParser::DOSPUNTOS);
    setState(96);
    tipo();
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PanicoParser::COMA) {
      setState(97);
      match(PanicoParser::COMA);
      setState(98);
      match(PanicoParser::ID);
      setState(99);
      match(PanicoParser::DOSPUNTOS);
      setState(100);
      tipo();
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CuerpoContext ------------------------------------------------------------------

PanicoParser::CuerpoContext::CuerpoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PanicoParser::EstatutoContext *> PanicoParser::CuerpoContext::estatuto() {
  return getRuleContexts<PanicoParser::EstatutoContext>();
}

PanicoParser::EstatutoContext* PanicoParser::CuerpoContext::estatuto(size_t i) {
  return getRuleContext<PanicoParser::EstatutoContext>(i);
}


size_t PanicoParser::CuerpoContext::getRuleIndex() const {
  return PanicoParser::RuleCuerpo;
}

void PanicoParser::CuerpoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCuerpo(this);
}

void PanicoParser::CuerpoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCuerpo(this);
}


std::any PanicoParser::CuerpoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitCuerpo(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::CuerpoContext* PanicoParser::cuerpo() {
  CuerpoContext *_localctx = _tracker.createInstance<CuerpoContext>(_ctx, getState());
  enterRule(_localctx, 12, PanicoParser::RuleCuerpo);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 268436864) != 0)) {
      setState(106);
      estatuto();
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EstatutoContext ------------------------------------------------------------------

PanicoParser::EstatutoContext::EstatutoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PanicoParser::AsignaContext* PanicoParser::EstatutoContext::asigna() {
  return getRuleContext<PanicoParser::AsignaContext>(0);
}

PanicoParser::CondicionContext* PanicoParser::EstatutoContext::condicion() {
  return getRuleContext<PanicoParser::CondicionContext>(0);
}

PanicoParser::CicloContext* PanicoParser::EstatutoContext::ciclo() {
  return getRuleContext<PanicoParser::CicloContext>(0);
}

PanicoParser::LlamadaContext* PanicoParser::EstatutoContext::llamada() {
  return getRuleContext<PanicoParser::LlamadaContext>(0);
}

PanicoParser::ImprimeContext* PanicoParser::EstatutoContext::imprime() {
  return getRuleContext<PanicoParser::ImprimeContext>(0);
}


size_t PanicoParser::EstatutoContext::getRuleIndex() const {
  return PanicoParser::RuleEstatuto;
}

void PanicoParser::EstatutoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEstatuto(this);
}

void PanicoParser::EstatutoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEstatuto(this);
}


std::any PanicoParser::EstatutoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitEstatuto(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::EstatutoContext* PanicoParser::estatuto() {
  EstatutoContext *_localctx = _tracker.createInstance<EstatutoContext>(_ctx, getState());
  enterRule(_localctx, 14, PanicoParser::RuleEstatuto);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(112);
      asigna();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(113);
      condicion();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(114);
      ciclo();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(115);
      llamada();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(116);
      imprime();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsignaContext ------------------------------------------------------------------

PanicoParser::AsignaContext::AsignaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::AsignaContext::ID() {
  return getToken(PanicoParser::ID, 0);
}

tree::TerminalNode* PanicoParser::AsignaContext::IGUAL() {
  return getToken(PanicoParser::IGUAL, 0);
}

PanicoParser::ExpresionContext* PanicoParser::AsignaContext::expresion() {
  return getRuleContext<PanicoParser::ExpresionContext>(0);
}

tree::TerminalNode* PanicoParser::AsignaContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}


size_t PanicoParser::AsignaContext::getRuleIndex() const {
  return PanicoParser::RuleAsigna;
}

void PanicoParser::AsignaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsigna(this);
}

void PanicoParser::AsignaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsigna(this);
}


std::any PanicoParser::AsignaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitAsigna(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::AsignaContext* PanicoParser::asigna() {
  AsignaContext *_localctx = _tracker.createInstance<AsignaContext>(_ctx, getState());
  enterRule(_localctx, 16, PanicoParser::RuleAsigna);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(PanicoParser::ID);
    setState(120);
    match(PanicoParser::IGUAL);
    setState(121);
    expresion();
    setState(122);
    match(PanicoParser::PUNTOYCOMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpresionContext ------------------------------------------------------------------

PanicoParser::ExpresionContext::ExpresionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PanicoParser::ExpContext *> PanicoParser::ExpresionContext::exp() {
  return getRuleContexts<PanicoParser::ExpContext>();
}

PanicoParser::ExpContext* PanicoParser::ExpresionContext::exp(size_t i) {
  return getRuleContext<PanicoParser::ExpContext>(i);
}

tree::TerminalNode* PanicoParser::ExpresionContext::MAYORQUE() {
  return getToken(PanicoParser::MAYORQUE, 0);
}

tree::TerminalNode* PanicoParser::ExpresionContext::MENORQUE() {
  return getToken(PanicoParser::MENORQUE, 0);
}

tree::TerminalNode* PanicoParser::ExpresionContext::DIFERENTE() {
  return getToken(PanicoParser::DIFERENTE, 0);
}

tree::TerminalNode* PanicoParser::ExpresionContext::IGUALIGUAL() {
  return getToken(PanicoParser::IGUALIGUAL, 0);
}


size_t PanicoParser::ExpresionContext::getRuleIndex() const {
  return PanicoParser::RuleExpresion;
}

void PanicoParser::ExpresionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpresion(this);
}

void PanicoParser::ExpresionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpresion(this);
}


std::any PanicoParser::ExpresionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitExpresion(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::ExpresionContext* PanicoParser::expresion() {
  ExpresionContext *_localctx = _tracker.createInstance<ExpresionContext>(_ctx, getState());
  enterRule(_localctx, 18, PanicoParser::RuleExpresion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    exp();
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15728640) != 0)) {
      setState(125);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 15728640) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(126);
      exp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

PanicoParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PanicoParser::TerminoContext *> PanicoParser::ExpContext::termino() {
  return getRuleContexts<PanicoParser::TerminoContext>();
}

PanicoParser::TerminoContext* PanicoParser::ExpContext::termino(size_t i) {
  return getRuleContext<PanicoParser::TerminoContext>(i);
}

std::vector<tree::TerminalNode *> PanicoParser::ExpContext::MAS() {
  return getTokens(PanicoParser::MAS);
}

tree::TerminalNode* PanicoParser::ExpContext::MAS(size_t i) {
  return getToken(PanicoParser::MAS, i);
}

std::vector<tree::TerminalNode *> PanicoParser::ExpContext::MENOS() {
  return getTokens(PanicoParser::MENOS);
}

tree::TerminalNode* PanicoParser::ExpContext::MENOS(size_t i) {
  return getToken(PanicoParser::MENOS, i);
}


size_t PanicoParser::ExpContext::getRuleIndex() const {
  return PanicoParser::RuleExp;
}

void PanicoParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void PanicoParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


std::any PanicoParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::ExpContext* PanicoParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 20, PanicoParser::RuleExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    termino();
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PanicoParser::MAS

    || _la == PanicoParser::MENOS) {
      setState(130);
      _la = _input->LA(1);
      if (!(_la == PanicoParser::MAS

      || _la == PanicoParser::MENOS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(131);
      termino();
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TerminoContext ------------------------------------------------------------------

PanicoParser::TerminoContext::TerminoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PanicoParser::FactorContext *> PanicoParser::TerminoContext::factor() {
  return getRuleContexts<PanicoParser::FactorContext>();
}

PanicoParser::FactorContext* PanicoParser::TerminoContext::factor(size_t i) {
  return getRuleContext<PanicoParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> PanicoParser::TerminoContext::MULT() {
  return getTokens(PanicoParser::MULT);
}

tree::TerminalNode* PanicoParser::TerminoContext::MULT(size_t i) {
  return getToken(PanicoParser::MULT, i);
}

std::vector<tree::TerminalNode *> PanicoParser::TerminoContext::DIV() {
  return getTokens(PanicoParser::DIV);
}

tree::TerminalNode* PanicoParser::TerminoContext::DIV(size_t i) {
  return getToken(PanicoParser::DIV, i);
}


size_t PanicoParser::TerminoContext::getRuleIndex() const {
  return PanicoParser::RuleTermino;
}

void PanicoParser::TerminoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermino(this);
}

void PanicoParser::TerminoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermino(this);
}


std::any PanicoParser::TerminoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitTermino(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::TerminoContext* PanicoParser::termino() {
  TerminoContext *_localctx = _tracker.createInstance<TerminoContext>(_ctx, getState());
  enterRule(_localctx, 22, PanicoParser::RuleTermino);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    factor();
    setState(142);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PanicoParser::MULT

    || _la == PanicoParser::DIV) {
      setState(138);
      _la = _input->LA(1);
      if (!(_la == PanicoParser::MULT

      || _la == PanicoParser::DIV)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(139);
      factor();
      setState(144);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

PanicoParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::FactorContext::PARENIZQ() {
  return getToken(PanicoParser::PARENIZQ, 0);
}

PanicoParser::ExpresionContext* PanicoParser::FactorContext::expresion() {
  return getRuleContext<PanicoParser::ExpresionContext>(0);
}

tree::TerminalNode* PanicoParser::FactorContext::PARENDER() {
  return getToken(PanicoParser::PARENDER, 0);
}

tree::TerminalNode* PanicoParser::FactorContext::ID() {
  return getToken(PanicoParser::ID, 0);
}

PanicoParser::CteContext* PanicoParser::FactorContext::cte() {
  return getRuleContext<PanicoParser::CteContext>(0);
}

tree::TerminalNode* PanicoParser::FactorContext::MENOS() {
  return getToken(PanicoParser::MENOS, 0);
}


size_t PanicoParser::FactorContext::getRuleIndex() const {
  return PanicoParser::RuleFactor;
}

void PanicoParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void PanicoParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


std::any PanicoParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::FactorContext* PanicoParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 24, PanicoParser::RuleFactor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PanicoParser::PARENIZQ: {
        enterOuterAlt(_localctx, 1);
        setState(145);
        match(PanicoParser::PARENIZQ);
        setState(146);
        expresion();
        setState(147);
        match(PanicoParser::PARENDER);
        break;
      }

      case PanicoParser::MENOS:
      case PanicoParser::ID:
      case PanicoParser::CTE_ENT:
      case PanicoParser::CTE_FLOT: {
        enterOuterAlt(_localctx, 2);
        setState(150);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PanicoParser::MENOS) {
          setState(149);
          match(PanicoParser::MENOS);
        }
        setState(154);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PanicoParser::ID: {
            setState(152);
            match(PanicoParser::ID);
            break;
          }

          case PanicoParser::CTE_ENT:
          case PanicoParser::CTE_FLOT: {
            setState(153);
            cte();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CteContext ------------------------------------------------------------------

PanicoParser::CteContext::CteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::CteContext::CTE_ENT() {
  return getToken(PanicoParser::CTE_ENT, 0);
}

tree::TerminalNode* PanicoParser::CteContext::CTE_FLOT() {
  return getToken(PanicoParser::CTE_FLOT, 0);
}


size_t PanicoParser::CteContext::getRuleIndex() const {
  return PanicoParser::RuleCte;
}

void PanicoParser::CteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCte(this);
}

void PanicoParser::CteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCte(this);
}


std::any PanicoParser::CteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitCte(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::CteContext* PanicoParser::cte() {
  CteContext *_localctx = _tracker.createInstance<CteContext>(_ctx, getState());
  enterRule(_localctx, 26, PanicoParser::RuleCte);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    _la = _input->LA(1);
    if (!(_la == PanicoParser::CTE_ENT

    || _la == PanicoParser::CTE_FLOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondicionContext ------------------------------------------------------------------

PanicoParser::CondicionContext::CondicionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::CondicionContext::IF() {
  return getToken(PanicoParser::IF, 0);
}

tree::TerminalNode* PanicoParser::CondicionContext::PARENIZQ() {
  return getToken(PanicoParser::PARENIZQ, 0);
}

PanicoParser::ExpresionContext* PanicoParser::CondicionContext::expresion() {
  return getRuleContext<PanicoParser::ExpresionContext>(0);
}

tree::TerminalNode* PanicoParser::CondicionContext::PARENDER() {
  return getToken(PanicoParser::PARENDER, 0);
}

std::vector<tree::TerminalNode *> PanicoParser::CondicionContext::LLAVEIZQ() {
  return getTokens(PanicoParser::LLAVEIZQ);
}

tree::TerminalNode* PanicoParser::CondicionContext::LLAVEIZQ(size_t i) {
  return getToken(PanicoParser::LLAVEIZQ, i);
}

std::vector<PanicoParser::CuerpoContext *> PanicoParser::CondicionContext::cuerpo() {
  return getRuleContexts<PanicoParser::CuerpoContext>();
}

PanicoParser::CuerpoContext* PanicoParser::CondicionContext::cuerpo(size_t i) {
  return getRuleContext<PanicoParser::CuerpoContext>(i);
}

std::vector<tree::TerminalNode *> PanicoParser::CondicionContext::LLAVEDER() {
  return getTokens(PanicoParser::LLAVEDER);
}

tree::TerminalNode* PanicoParser::CondicionContext::LLAVEDER(size_t i) {
  return getToken(PanicoParser::LLAVEDER, i);
}

tree::TerminalNode* PanicoParser::CondicionContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}

tree::TerminalNode* PanicoParser::CondicionContext::ELSE() {
  return getToken(PanicoParser::ELSE, 0);
}


size_t PanicoParser::CondicionContext::getRuleIndex() const {
  return PanicoParser::RuleCondicion;
}

void PanicoParser::CondicionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondicion(this);
}

void PanicoParser::CondicionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondicion(this);
}


std::any PanicoParser::CondicionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitCondicion(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::CondicionContext* PanicoParser::condicion() {
  CondicionContext *_localctx = _tracker.createInstance<CondicionContext>(_ctx, getState());
  enterRule(_localctx, 28, PanicoParser::RuleCondicion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(PanicoParser::IF);
    setState(161);
    match(PanicoParser::PARENIZQ);
    setState(162);
    expresion();
    setState(163);
    match(PanicoParser::PARENDER);
    setState(164);
    match(PanicoParser::LLAVEIZQ);
    setState(165);
    cuerpo();
    setState(166);
    match(PanicoParser::LLAVEDER);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PanicoParser::ELSE) {
      setState(167);
      match(PanicoParser::ELSE);
      setState(168);
      match(PanicoParser::LLAVEIZQ);
      setState(169);
      cuerpo();
      setState(170);
      match(PanicoParser::LLAVEDER);
    }
    setState(174);
    match(PanicoParser::PUNTOYCOMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CicloContext ------------------------------------------------------------------

PanicoParser::CicloContext::CicloContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::CicloContext::WHILE() {
  return getToken(PanicoParser::WHILE, 0);
}

tree::TerminalNode* PanicoParser::CicloContext::PARENIZQ() {
  return getToken(PanicoParser::PARENIZQ, 0);
}

PanicoParser::ExpresionContext* PanicoParser::CicloContext::expresion() {
  return getRuleContext<PanicoParser::ExpresionContext>(0);
}

tree::TerminalNode* PanicoParser::CicloContext::PARENDER() {
  return getToken(PanicoParser::PARENDER, 0);
}

tree::TerminalNode* PanicoParser::CicloContext::LLAVEIZQ() {
  return getToken(PanicoParser::LLAVEIZQ, 0);
}

PanicoParser::CuerpoContext* PanicoParser::CicloContext::cuerpo() {
  return getRuleContext<PanicoParser::CuerpoContext>(0);
}

tree::TerminalNode* PanicoParser::CicloContext::LLAVEDER() {
  return getToken(PanicoParser::LLAVEDER, 0);
}

tree::TerminalNode* PanicoParser::CicloContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}


size_t PanicoParser::CicloContext::getRuleIndex() const {
  return PanicoParser::RuleCiclo;
}

void PanicoParser::CicloContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCiclo(this);
}

void PanicoParser::CicloContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCiclo(this);
}


std::any PanicoParser::CicloContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitCiclo(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::CicloContext* PanicoParser::ciclo() {
  CicloContext *_localctx = _tracker.createInstance<CicloContext>(_ctx, getState());
  enterRule(_localctx, 30, PanicoParser::RuleCiclo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(PanicoParser::WHILE);
    setState(177);
    match(PanicoParser::PARENIZQ);
    setState(178);
    expresion();
    setState(179);
    match(PanicoParser::PARENDER);
    setState(180);
    match(PanicoParser::LLAVEIZQ);
    setState(181);
    cuerpo();
    setState(182);
    match(PanicoParser::LLAVEDER);
    setState(183);
    match(PanicoParser::PUNTOYCOMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LlamadaContext ------------------------------------------------------------------

PanicoParser::LlamadaContext::LlamadaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::LlamadaContext::ID() {
  return getToken(PanicoParser::ID, 0);
}

tree::TerminalNode* PanicoParser::LlamadaContext::PARENIZQ() {
  return getToken(PanicoParser::PARENIZQ, 0);
}

tree::TerminalNode* PanicoParser::LlamadaContext::PARENDER() {
  return getToken(PanicoParser::PARENDER, 0);
}

tree::TerminalNode* PanicoParser::LlamadaContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}

std::vector<PanicoParser::ExpresionContext *> PanicoParser::LlamadaContext::expresion() {
  return getRuleContexts<PanicoParser::ExpresionContext>();
}

PanicoParser::ExpresionContext* PanicoParser::LlamadaContext::expresion(size_t i) {
  return getRuleContext<PanicoParser::ExpresionContext>(i);
}

std::vector<tree::TerminalNode *> PanicoParser::LlamadaContext::COMA() {
  return getTokens(PanicoParser::COMA);
}

tree::TerminalNode* PanicoParser::LlamadaContext::COMA(size_t i) {
  return getToken(PanicoParser::COMA, i);
}


size_t PanicoParser::LlamadaContext::getRuleIndex() const {
  return PanicoParser::RuleLlamada;
}

void PanicoParser::LlamadaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLlamada(this);
}

void PanicoParser::LlamadaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLlamada(this);
}


std::any PanicoParser::LlamadaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitLlamada(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::LlamadaContext* PanicoParser::llamada() {
  LlamadaContext *_localctx = _tracker.createInstance<LlamadaContext>(_ctx, getState());
  enterRule(_localctx, 32, PanicoParser::RuleLlamada);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(PanicoParser::ID);
    setState(186);
    match(PanicoParser::PARENIZQ);
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1912733696) != 0)) {
      setState(187);
      expresion();
      setState(192);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PanicoParser::COMA) {
        setState(188);
        match(PanicoParser::COMA);
        setState(189);
        expresion();
        setState(194);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(197);
    match(PanicoParser::PARENDER);
    setState(198);
    match(PanicoParser::PUNTOYCOMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImprimeContext ------------------------------------------------------------------

PanicoParser::ImprimeContext::ImprimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PanicoParser::ImprimeContext::PRINT() {
  return getToken(PanicoParser::PRINT, 0);
}

tree::TerminalNode* PanicoParser::ImprimeContext::PARENIZQ() {
  return getToken(PanicoParser::PARENIZQ, 0);
}

std::vector<PanicoParser::ImprContext *> PanicoParser::ImprimeContext::impr() {
  return getRuleContexts<PanicoParser::ImprContext>();
}

PanicoParser::ImprContext* PanicoParser::ImprimeContext::impr(size_t i) {
  return getRuleContext<PanicoParser::ImprContext>(i);
}

tree::TerminalNode* PanicoParser::ImprimeContext::PARENDER() {
  return getToken(PanicoParser::PARENDER, 0);
}

tree::TerminalNode* PanicoParser::ImprimeContext::PUNTOYCOMA() {
  return getToken(PanicoParser::PUNTOYCOMA, 0);
}

std::vector<tree::TerminalNode *> PanicoParser::ImprimeContext::COMA() {
  return getTokens(PanicoParser::COMA);
}

tree::TerminalNode* PanicoParser::ImprimeContext::COMA(size_t i) {
  return getToken(PanicoParser::COMA, i);
}


size_t PanicoParser::ImprimeContext::getRuleIndex() const {
  return PanicoParser::RuleImprime;
}

void PanicoParser::ImprimeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImprime(this);
}

void PanicoParser::ImprimeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImprime(this);
}


std::any PanicoParser::ImprimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitImprime(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::ImprimeContext* PanicoParser::imprime() {
  ImprimeContext *_localctx = _tracker.createInstance<ImprimeContext>(_ctx, getState());
  enterRule(_localctx, 34, PanicoParser::RuleImprime);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(PanicoParser::PRINT);
    setState(201);
    match(PanicoParser::PARENIZQ);
    setState(202);
    impr();
    setState(207);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PanicoParser::COMA) {
      setState(203);
      match(PanicoParser::COMA);
      setState(204);
      impr();
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(210);
    match(PanicoParser::PARENDER);
    setState(211);
    match(PanicoParser::PUNTOYCOMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImprContext ------------------------------------------------------------------

PanicoParser::ImprContext::ImprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PanicoParser::ExpresionContext* PanicoParser::ImprContext::expresion() {
  return getRuleContext<PanicoParser::ExpresionContext>(0);
}

tree::TerminalNode* PanicoParser::ImprContext::LETRERO_VALOR() {
  return getToken(PanicoParser::LETRERO_VALOR, 0);
}


size_t PanicoParser::ImprContext::getRuleIndex() const {
  return PanicoParser::RuleImpr;
}

void PanicoParser::ImprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImpr(this);
}

void PanicoParser::ImprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PanicoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImpr(this);
}


std::any PanicoParser::ImprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PanicoVisitor*>(visitor))
    return parserVisitor->visitImpr(this);
  else
    return visitor->visitChildren(this);
}

PanicoParser::ImprContext* PanicoParser::impr() {
  ImprContext *_localctx = _tracker.createInstance<ImprContext>(_ctx, getState());
  enterRule(_localctx, 36, PanicoParser::RuleImpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(215);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PanicoParser::PARENIZQ:
      case PanicoParser::MENOS:
      case PanicoParser::ID:
      case PanicoParser::CTE_ENT:
      case PanicoParser::CTE_FLOT: {
        enterOuterAlt(_localctx, 1);
        setState(213);
        expresion();
        break;
      }

      case PanicoParser::LETRERO_VALOR: {
        enterOuterAlt(_localctx, 2);
        setState(214);
        match(PanicoParser::LETRERO_VALOR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void PanicoParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  panicoParserInitialize();
#else
  ::antlr4::internal::call_once(panicoParserOnceFlag, panicoParserInitialize);
#endif
}

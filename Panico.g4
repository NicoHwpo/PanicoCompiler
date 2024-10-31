grammar Panico;

// LEXER
// Palabras clave
PROGRAMA: 'programa';
INICIO: 'inicio';
FIN: 'fin';
VARS: 'vars';
INT: 'int';
FLOAT: 'float';
PRINT: 'print';
WHILE: 'while';
VOID: 'void';
IF: 'if';
ELSE: 'else';

// Operadores y símbolos
PUNTOYCOMA: ';';
COMA: ',';
DOSPUNTOS: ':';
LLAVEIZQ: '{';
LLAVEDER: '}';
PARENIZQ: '(';
PARENDER: ')';
IGUAL: '=';
MAYORQUE: '>';
MENORQUE: '<';
DIFERENTE: '!=';
IGUALIGUAL: '==';
MAS: '+';
MENOS: '-';
MULT: '*';
DIV: '/';

// Identificadores y constantes
ID: [a-zA-Z_][a-zA-Z0-9_]*;
CTE_ENT: [0-9]+;
CTE_FLOT: [0-9]+'.'[0-9]+;
LETRERO_VALOR: '"' .*? '"'; // Para cadenas de texto (letrero)

// Ignorar espacios en blanco
WS: [ \t\r\n]+ -> skip;


// PARSER
programa: PROGRAMA ID PUNTOYCOMA vars? funcs* INICIO LLAVEIZQ cuerpo LLAVEDER FIN; 

vars: VARS LLAVEIZQ decl_var+ LLAVEDER;
decl_var: ID (COMA ID)* DOSPUNTOS tipo PUNTOYCOMA;
tipo: INT | FLOAT;

funcs: VOID ID PARENIZQ params? PARENDER LLAVEIZQ vars? cuerpo LLAVEDER PUNTOYCOMA;
params: ID DOSPUNTOS tipo (COMA ID DOSPUNTOS tipo)*;

cuerpo: estatuto*;
estatuto: asigna | condicion | ciclo | llamada | imprime;
asigna: ID IGUAL expresion PUNTOYCOMA;
expresion: exp ((MAYORQUE | MENORQUE | DIFERENTE | IGUALIGUAL) exp)?;
exp: termino ((MAS | MENOS) termino)*;
termino: factor ((MULT | DIV) factor)*;
factor: PARENIZQ expresion PARENDER | (MAS | MENOS)? (ID | cte);
cte: CTE_ENT | CTE_FLOT;

condicion: IF PARENIZQ expresion PARENDER LLAVEIZQ cuerpo LLAVEDER (ELSE LLAVEIZQ cuerpo LLAVEDER)? PUNTOYCOMA;

ciclo: WHILE PARENIZQ expresion PARENDER LLAVEIZQ cuerpo LLAVEDER PUNTOYCOMA;

llamada: ID PARENIZQ (expresion (COMA expresion)*)? PARENDER PUNTOYCOMA;

imprime: PRINT PARENIZQ impr (COMA impr)* PARENDER PUNTOYCOMA;
impr: expresion | LETRERO_VALOR;


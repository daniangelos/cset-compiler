%{
#include <stdio.h>
#include <string.h>

/* constantes para identificar os tipos de tokens */
#define INT				1 // inteiro com ou sem sinal
#define STRING			2 // string entre aspas
#define BEGIN_TAG		3 // abre tag '<'
#define BEGIN_CL_TAG	4 // abre tag de fechamento '</'
#define END_TAG			5 // fecha tag '>'
#define END_SINGLE_TAG	6 // fecha tag simples '/>'
#define ID				7 // identificador
#define EQUALS			8 // sinal '='
#define ESC_SEQ			9 // sequência de escape '&id;'

int line = 1; // contador de linhas
char idvalue[100]; // valor dos identificadores
%}

/* Na seção de declarações, é possível criar expressões auxiliares, que depois são referenciadas entre chaves {} */

/* dígitos */
D   [0-9]
/* letras */
L   [a-zA-Z]
/* fim de linha */
EOL  "\n"|"\r"|"\r\n"
/* espaço em branco */
WS  [ \t\v\f]

%%

-?{D}+		{ return INT; } // um ou mais dígitos, com ou sem sinal?
\"[^"]*\"	{ return STRING; } // aspas duplas, seguidas de zero ou mais chars que não são aspas, seguido de aspas duplas?
"<"			{ return BEGIN_TAG; }
"</"		{ return BEGIN_CL_TAG; }
">"			{ return END_TAG; }
"/>"		{ return END_SINGLE_TAG; }
{L}+		{ strcpy(idvalue, yytext); return ID; }
"="			{ return EQUALS; }
&{L}+;		{ return ESC_SEQ; } // '&', seguido de uma ou mais letras, seguido ';'?
{WS}+		{ BEGIN(INITIAL); } // volta o autômato para o estado inicial, i.e., ignora este token
{EOL}		{ ++line; BEGIN(INITIAL); }
.			{ return *yytext; } // se achar um caractere inesperado, simplesmente retorna-o

%%

int yywrap() { return 1; }

int main(int argc, char *argv[]) {
	static char const* tokens[] = {0, "int", "string", "begin tag", "begin cl tag", "end tag", "end single tag", "id", "equals", "esc seq"};
	int token;
	
	// assume que o usuário informou corretamente um arquivo de entrada no primeiro parâmetro
	yyin = fopen(argv[1], "r");
	
	while ((token = yylex())) {
		if ((token < 1) || (token > 9))
			printf("line %d, unknown char: '%c'\n", line, (char) token);
		else {
			if (token == ID) {
				printf("line %d, token: %s '%s'\n", line, tokens[token], idvalue);
			}
			else
				printf("line %d, token: %s\n", line, tokens[token]);
		}
	}
	return 0;
}

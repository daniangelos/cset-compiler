%{

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cset.tab.h"

#define MAX_TOKENS 2048

int lines = 1, columns = 1;
int lexerrors = 0;

%}

%x BL_COMMENT
%x LN_COMMENT

/* dígitos */
D   [0-9]
/* letras */
L   [a-zA-Z]
/* fim de linha */
EOL  "\n"|"\r"|"\r\n"
/* espaço em branco */
WS  [ \t\v\f]

INT_V		-?{D}+
FLOAT_V		(-?{D})+(".")({D})+
CHAR_V 		\'[^'\n\\]\'
STRING_V	\"([^"\\])*\"
BOOL_V		"true"|"false"
INT 		"int"
FLOAT 		"float"
CHAR 		"char"
BOOL 		"bool"
SET 		"set"
PAIR 		"pair"
WHILE 		"while"
IF 			"if"
ELSE 		"else"
RETURN 		"return"
PRINT		"print"
READ		"read"

%%

"/*"				{BEGIN(BL_COMMENT);}
<BL_COMMENT>"*/"	{BEGIN(INITIAL);}
<BL_COMMENT>{EOL}	{lines++; columns = 1;}
<BL_COMMENT>.		{columns+=yyleng;}

"//"				{BEGIN(LN_COMMENT);}
<LN_COMMENT>.		{columns+=yyleng;}
<LN_COMMENT>{EOL}	{lines++; columns = 1; BEGIN(INITIAL);}


{INT_V}			{columns += yyleng; yylval.intv = atoi(yytext); return INT_VALUE;}
{FLOAT_V}		{columns += yyleng; yylval.floatv = atof(yytext); return FLOAT_VALUE;}
{CHAR_V}	  	{columns += yyleng; yylval.charv = yytext[1]; return CHAR_VALUE;}
{BOOL_V} 		{columns += yyleng; yylval.boolv = strdup(yytext); return BOOL_VALUE;}
{STRING_V}		{columns += yyleng; return STR;}

{INT}			{columns += yyleng; return K_INT;}
{FLOAT}			{columns += yyleng; return K_FLOAT;}
{CHAR}			{columns += yyleng; return K_CHAR;}
{BOOL}			{columns += yyleng; return K_BOOL;}
{PAIR}			{columns += yyleng; return K_PAIR;}
{SET}			{columns += yyleng; return K_SET;}
{WHILE}			{columns += yyleng; return K_WHILE;}
{IF}			{columns += yyleng; return K_IF;}
{ELSE}			{columns += yyleng; return K_ELSE;}
{RETURN}		{columns += yyleng; return K_RETURN;}
{PRINT}			{columns += yyleng; return K_PRINT;}
{READ}			{columns += yyleng; return K_READ;}


(_|{L})(_|{D}|{L})*	{yylval.str = strdup(yytext); return ID;}
{D}+(_|{L}|{D})*	{lexerrors++; printf("Lexical error at line %d. Incorrect ID formation.\n", lines) ; BEGIN(INITIAL);}

"<<"			{return DOUBLE_BR_OP;}
">>"			{return DOUBLE_BR_CL;}

"="				{return '=';}
"=="			{return COMPARE;}
"!="			{return DIFFERENCE;}
"<"				{return '<';}
"<="			{return LE;}
">"				{return '>';}
">="			{return GE;}
"||"			{return LOGICAL_OR;}
"&&"			{return LOGICAL_AND;}
"<?>"			{return PERTINENCE;}
"<*>"			{return CARTESIAN;}
"+"				{return '+';}
"-"				{return '-';}
"*"				{return '*';}
"/"				{return '/';}
"$"				{return '$';}
"!"				{return '!';}
"("				{return '(';}
")"				{return ')';}
"["				{return '[';}
"]"				{return ']';}
"{"				{return '{';}
"}"				{return '}';}
","				{return ',';}
";"				{return ';';}

{WS}+			{columns+=yyleng; BEGIN(INITIAL);} 
{EOL}			{columns = 1; lines++; BEGIN(INITIAL);}

.				{lexerrors++; printf("Lexical error at line %d. Unrecognized token.\n", lines) ; BEGIN(INITIAL);}

%%

typedef struct tokens_t
{
	int line;
	int token_id;
	char* token_name;
}tokens_t;

void print_tokens(int total_t, tokens_t *alltokens);
int yywrap() { return 1; }


%{

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cset.tab.h"

#define MAX_TOKENS 2048

int lines = 1, columns = 1;
int errors = 0;

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
{D}+(_|{L}|{D})*	{return -1;}

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

.				{return -1;}

%%

typedef struct tokens_t
{
	int line;
	int token_id;
	char* token_name;
}tokens_t;

void print_tokens(int total_t, tokens_t *alltokens);
int yywrap() { return 1; }

/*int main(int argc, char* argv[])*/
/*{*/
	/*int token;*/
	/*int tot_erros = 0;*/
	/*int total_t = 0;*/
	/*tokens_t *alltokens;*/
	/*int file_mode = 0;*/
	/*FILE *log;*/
	
	/*int i;*/

	/*if(argc < 2) { printf("Arquivo de entrada nao informado.\n"); return -1;}*/
	/*else if(argc > 2)*/
	/*{*/
		/*if(strcmp(argv[2], "-f")) { printf("Argumento invalido!\n"); return -1;}*/
		/*file_mode = 1;*/
	/*}*/

	/*yyin = fopen(argv[1], "r");*/
	/*if(file_mode) log = fopen(strcat(argv[1],".log"), "w");*/

	/*alltokens = malloc(sizeof(tokens_t)*MAX_TOKENS);*/

	/*while(token = yylex())*/
	/*{*/
		/*if(token > 0)*/
		/*{*/
			/*alltokens[total_t].line = lines;*/
			/*alltokens[total_t].token_id = token;*/
			/*alltokens[total_t].token_name = malloc(yyleng + 1);*/
			/*strcpy(alltokens[total_t].token_name, yytext);*/
			/*total_t++;*/
		/*}*/
		/*else */
		/*{*/
		/*if (tot_erros == 0) */
			/*if(file_mode) fprintf(log,"\n* -------- Erro(s) encontrado(s) --------- *\n\n");*/
			/*else printf("\n* -------- Erro(s) encontrado(s) --------- *\n\n");*/
		/*if(file_mode) */
			/*fprintf(log, "Erro linha:coluna %d:%d. Sequencia (%s) nao reconhecida\n", lines, columns, yytext);*/
		/*else */
			/*printf("Erro linha:coluna %d:%d. Sequencia (%s) nao reconhecida\n", lines, columns, yytext);*/
		/*tot_erros++;*/
		/*}*/
		/*columns += yyleng;*/
	/*}*/

	/*print_tokens(total_t, alltokens);*/

	/*free(alltokens);*/

	/*return 0;*/
/*}*/

/*void print_tokens(int total_t, tokens_t *alltokens)*/
/*{*/
	/*static char const* tokens[] =*/
		/*{ 0, "INT_C", "FLOAT_C", "CHAR_C", "BOOL_C", "KEYWORD_INT", "KEYWORD_FLOAT",*/
		/*"KEYWORD_CHAR", "KEYWORD_BOOL", "KEYWORD_SET", "KEYWORD_PAIR", "KEYWORD_WHILE",*/
		/*"KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_RETURN", "EQUAL", "COMPARE",*/
		/*"DIFFERENCE", "LT", "LE", "GT", "GE", "LOGICAL_OR", "LOGICAL_AND", "PERTINENCE",*/
		/*"CARTESIAN", "ADD", "SUB", "MULT", "DIV", "CARD", "NOT", "COMMA", "DOUBLE_BR_OP",*/
		/*"DOUBLE_BR_CL", "OPEN_P", "CLOSE_P", "OPEN_SQR_BRACKET", "CLOSE_SQR_BRACKET",*/
		/*"OPEN_BRACKET", "CLOSE_BRACKET", "SEMI_COLON", "ID", "KEYWORD_PRINT",*/
		/*"KEYWORD_READ", "STRING_C"};*/

	/*int i;*/

	/*printf("\n");*/
	/*printf("* ----------- Token(s) lido(s) ----------- *\n\n");*/

	/*for(i = 0; i<total_t; i++)*/
	/*{*/
		/*printf("Linha: %d \tToken: %-15.15s \t\tConteudo: ", alltokens[i].line, tokens[alltokens[i].token_id]);*/
		/*printf("%s", alltokens[i].token_name);*/
		/*printf("\n");*/
		/*free(alltokens[i].token_name);*/
	/*}*/

	/*printf("\n");*/

/*}*/






%{

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_TOKENS 2048

/* constantes para identificar tokens */
#define INT_C				1  // representacao de constante inteira 
#define FLOAT_C				2  // representacao de constante float 
#define CHAR_C				3  // representacao de constante char 
#define BOOL_C				4  // representacao de constante bool
#define KEYWORD_INT			5
#define KEYWORD_FLOAT		6
#define KEYWORD_CHAR		7
#define KEYWORD_BOOL		8
#define KEYWORD_SET			9
#define KEYWORD_PAIR		10
#define KEYWORD_WHILE 		11 
#define KEYWORD_IF 			12
#define KEYWORD_ELSE 		13
#define KEYWORD_RETURN 		14
#define EQUAL 				15  // =
#define COMPARE 			16  // ==
#define DIFFERENCE 			17  // !=
#define LT 					18  // <
#define LE 					19  // <= 
#define GT 					20  // >
#define GE 					21  // >=
#define LOGICAL_OR 			22  // ||
#define LOGICAL_AND 		23  // &&
#define PERTINENCE 			24  // <?>
#define CARTESIAN 			25  // <*>
#define ADD 				26  // +
#define SUB					27  // -
#define MULT 				28  // *
#define DIV 				29  // /
#define CARD 				30  // $
#define NOT 				31  // !
#define COMMA				32  // ,
#define DOUBLE_BR_OP		33 	// <<
#define DOUBLE_BR_CL		34 	// >>
#define OPEN_P				35  // (
#define CLOSE_P				36  // )
#define OPEN_SQR_BRACKET	37  // [
#define CLOSE_SQR_BRACKET 	38  // ]
#define OPEN_BRACKET		39
#define CLOSE_BRACKET		40
#define SEMI_COLON			41  // ;
#define ID					42 
#define KEYWORD_PRINT		43
#define KEYWORD_READ		44
#define STRING_C			45

int lines = 1, columns = 1;

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


{INT_V}			{return INT_C;}
{FLOAT_V}		{return FLOAT_C;}
{CHAR_V}	  	{return CHAR_C;}
{BOOL_V} 		{return BOOL_C;}
{STRING_V}		{return STRING_C;}

{INT}			{return KEYWORD_INT;}
{FLOAT}			{return KEYWORD_FLOAT;}
{CHAR}			{return KEYWORD_CHAR;}
{BOOL}			{return KEYWORD_BOOL;}
{PAIR}			{return KEYWORD_PAIR;}
{SET}			{return KEYWORD_SET;}
{WHILE}			{return KEYWORD_WHILE;}
{IF}			{return KEYWORD_IF;}
{ELSE}			{return KEYWORD_ELSE;}
{RETURN}		{return KEYWORD_RETURN;}
{PRINT}			{return KEYWORD_PRINT;}
{READ}			{return KEYWORD_READ;}


(_|{L})(_|{D}|{L})*	{return ID;}
{D}+(_|{L}|{D})*	{return -1;}

"<<"			{return DOUBLE_BR_OP;}
">>"			{return DOUBLE_BR_CL;}

"="				{return EQUAL;}
"=="			{return COMPARE;}
"!="			{return DIFFERENCE;}
"<"				{return LT;}
"<="			{return LE;}
">"				{return GT;}
">="			{return GE;}
"||"			{return LOGICAL_OR;}
"&&"			{return LOGICAL_AND;}
"<?>"			{return PERTINENCE;}
"<*>"			{return CARTESIAN;}
"+"				{return ADD;}
"-"				{return SUB;}
"*"				{return MULT;}
"/"				{return DIV;}
"$"				{return CARD;}
"!"				{return NOT;}
"("				{return OPEN_P;}
")"				{return CLOSE_P;}
"["				{return OPEN_SQR_BRACKET;}
"]"				{return CLOSE_SQR_BRACKET;}
"{"				{return OPEN_BRACKET;}
"}"				{return CLOSE_BRACKET;}
","				{return COMMA;}
";"				{return SEMI_COLON;}

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

int main(int argc, char* argv[])
{
	int token;
	int tot_erros = 0;
	int total_t = 0;
	tokens_t *alltokens;
	int file_mode = 0;
	FILE *log;
	
	int i;

	if(argc < 2) { printf("Arquivo de entrada nao informado.\n"); return -1;}
	else if(argc > 2)
	{
		if(strcmp(argv[2], "-f")) { printf("Argumento invalido!\n"); return -1;}
		file_mode = 1;
	}

	yyin = fopen(argv[1], "r");
	if(file_mode) log = fopen(strcat(argv[1],".log"), "w");

	alltokens = malloc(sizeof(tokens_t)*MAX_TOKENS);

	while(token = yylex())
	{
		if(token > 0)
		{
			alltokens[total_t].line = lines;
			alltokens[total_t].token_id = token;
			alltokens[total_t].token_name = malloc(yyleng + 1);
			strcpy(alltokens[total_t].token_name, yytext);
			total_t++;
		}
		else 
		{
		if (tot_erros == 0) 
			if(file_mode) fprintf(log,"\n* -------- Erro(s) encontrado(s) --------- *\n\n");
			else printf("\n* -------- Erro(s) encontrado(s) --------- *\n\n");
		if(file_mode) 
			fprintf(log, "Erro linha:coluna %d:%d. Sequencia (%s) nao reconhecida\n", lines, columns, yytext);
		else 
			printf("Erro linha:coluna %d:%d. Sequencia (%s) nao reconhecida\n", lines, columns, yytext);
		tot_erros++;
		}
		columns += yyleng;
	}

	print_tokens(total_t, alltokens);

	free(alltokens);

	return 0;
}

void print_tokens(int total_t, tokens_t *alltokens)
{
	static char const* tokens[] =
		{ 0, "INT_C", "FLOAT_C", "CHAR_C", "BOOL_C", "KEYWORD_INT", "KEYWORD_FLOAT",
		"KEYWORD_CHAR", "KEYWORD_BOOL", "KEYWORD_SET", "KEYWORD_PAIR", "KEYWORD_WHILE",
		"KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_RETURN", "EQUAL", "COMPARE",
		"DIFFERENCE", "LT", "LE", "GT", "GE", "LOGICAL_OR", "LOGICAL_AND", "PERTINENCE",
		"CARTESIAN", "ADD", "SUB", "MULT", "DIV", "CARD", "NOT", "COMMA", "DOUBLE_BR_OP",
		"DOUBLE_BR_CL", "OPEN_P", "CLOSE_P", "OPEN_SQR_BRACKET", "CLOSE_SQR_BRACKET",
		"OPEN_BRACKET", "CLOSE_BRACKET", "SEMI_COLON", "ID", "KEYWORD_PRINT",
		"KEYWORD_READ", "STRING_C"};

	int i;

	printf("\n");
	printf("* ----------- Token(s) lido(s) ----------- *\n\n");

	for(i = 0; i<total_t; i++)
	{
		printf("Linha: %d \tToken: %-15.15s \t\tConteudo: ", alltokens[i].line, tokens[alltokens[i].token_id]);
		printf("%s", alltokens[i].token_name);
		printf("\n");
		free(alltokens[i].token_name);
	}

	printf("\n");

}






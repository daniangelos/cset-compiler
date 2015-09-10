%{

#include<stdio.h>
#include<string.h>

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
#define PAIR_BR_OPEN		33 	// <<
#define PAIR_BR_CLOSE		34 	// >>
#define OPEN_P				35  // (
#define CLOSE_P				36  // )
#define OPEN_SQR_BRACKET	37  // [
#define CLOSE_SQR_BRACKET 	38  // ]
#define OPEN_BRACKET		39
#define CLOSE_BRACKET		40
#define SEMI_COLON			41  // ;
#define ID					42 

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


(_|{L})(_|{D}|{L})*	{return ID;}

"<<"			{return PAIR_BR_OPEN;}
">>"			{return PAIR_BR_CLOSE;}

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

{WS}+			{columns+=yyleng; BEGIN(INITIAL);} 
{EOL}			{lines++; BEGIN(INITIAL);}

.				{return -1;}

%%

int yywrap() { return 1; }

int main(int argc, char* argv[])
{
	int token;
	int total_t = 0;
	int *token_id;
	int *line;
	char** data;
	int i;

	static char const* tokens[] =
		{ 0, "INT_C", "FLOAT_C", "CHAR_C", "BOOL_C", "KEYWORD_INT", "KEYWORD_FLOAT",
		"KEYWORD_CHAR", "KEYWORD_BOOL", "KEYWORD_SET", "KEYWORD_PAIR", "KEYWORD_WHILE",
		"KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_RETURN", "EQUAL", "COMPARE",
		"DIFFERENCE", "LT", "LE", "GT", "GE", "LOGICAL_OR", "LOGICAL_AND", "PERTINENCE",
		"CARTESIAN", "ADD", "SUB", "MULT", "DIV", "CARD", "NOT", "COMMA", "PAIR_BR_OPEN",
		"PAIR_BR_CLOSE", "OPEN_P", "CLOSE_P", "OPEN_SQR_BRACKET", "CLOSE_SQR_BRACKET",
		"OPEN_BRACKET", "CLOSE_BRACKET", "SEMI_COLON", "ID"};

	if(argc < 2) { printf("Arquivo de entrada nao informado.\n"); return -1;}

	yyin = fopen(argv[1], "r");

	token_id = malloc(sizeof(int));
	line = malloc(sizeof(int));
	data = malloc(sizeof(char*));

	while(token = yylex())
	{
		if(token > 0)
		{
			line[total_t] = lines;
			token_id[total_t] = token;
			data[total_t] = malloc(yyleng);
			strcpy(data[total_t], yytext);
			total_t++;
			printf("\n");
		}
		else printf("Erro linha:coluna %d:%d. Sequencia (%s) nao reconhecida\n", lines, columns, yytext);
		columns += yyleng;
	}

	for(i = 0; i<total_t; i++)
	{
		printf("Linha: %d \tToken: %s \tConteudo: ", line[i], tokens[token_id[i]]);
		if(token == 1) printf("%d", atoi(data[i]));
		else if(token == 2) printf("%.4f", atof(data[i]));
		else printf("%s", data[i]);
		printf("\n");
	}

	return 0;
}






%{

#include<stdio.h>
#include<string.h>

/* constantes para identificar tokens */
#define INT_T			1  // representacao de constante inteira 
#define FLOAT_T			2  // representacao de constante float 
#define CHAR_T			3  // representacao de constante char 
#define BOOL_T			4  // representacao de constante bool
#define SET_T			5  // representacao de constante set 
#define PAIR_T			6  // representacao de constante pair 	
#define KEYWORD_INT		5
#define KEYWORD_FLOAT	6
#define KEYWORD_CHAR	7
#define KEYWORD_BOOL	8
#define KEYWORD_SET		9
#define KEYWORD_PAIR	10
#define PAIR_BR_OPEN	11 // <<
#define PAIR_BR_CLOSE	12 // >>
#define KEYWORD_WHILE 	15 
#define KEYWORD_IF 		16
#define KEYWORD_ELSE 	17
#define KEYWORD_RETURN 	18
#define EQUAL 			19  // =
#define COMPARE 		20  // ==
#define DIFFERENCE 		21  // !=
#define LT 				22  // <
#define LE 				23  // <= 
#define GT 				24  // >
#define GE 				25  // >=
#define LOGICAL_OR 		26  // ||
#define LOGICAL_AND 	27  // &&
#define PERTINENCE 		28  // <?>
#define CARTESIAN 		29  // <*>
#define ADD 			30  // +
#define SUB				31  // -
#define MULT 			32  // *
#define DIV 			33  // /
#define CARD 			34  // $
#define NOT 			35  // !
#define COMMA			36  // ,
#define OPEN_P			37  // (
#define CLOSE_P			38  // )
#define OPEN_SQR_BRACKET		39  // [
#define CLOSE_SQR_BRACKET 	40  // ]
#define OPEN_BRACKET
#define CLOSE_BRACKET
#define SEMI_COLON		41  // ;

%}

/* ** EXPRESSOES AUXILIARES ** */
/* dígitos */
D   [0-9]
/* letras */
L   [a-zA-Z]
/* fim de linha */
EOL  "\n"|"\r"|"\r\n"
/* espaço em branco */
WS  [ \t\v\f]

INT_V		-?{D}+
FLOAT_V		-?{D}+"."{D}+
CHAR_V 		\'[^'\n\\]\'
BOOL_V		"true"|"false"
PAIR_V		"<<"{VALUE}","{VALUE}">>"
SET_V		"{}"|"{"[{VALUE},]*{VALUE}"}"
VALUE 		{INT_V}|{FLOAT_V}|{CHAR_V}|{BOOL_V}|{SET_V}|{PAIR_V}
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
/*TYPE		{INT}|{FLOAT}|{CHAR}|{SET}|{PAIR}*/


%%
{INT_V}			{return INT_T;}
{FLOAT_V}		{return FLOAT_T;}
{CHAR_V}	  	{return CHAR_T;}
{BOOL_V} 		{return BOOL_T;}
{PAIR_V}		{return PAIR_T;}
{SET_V}			{return SET_T;}

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

[_{L}][_{D}{L}]*	{return ID;}

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








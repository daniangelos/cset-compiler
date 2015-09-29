/* Syntax analyser */
%{
#include <stdio.h>
#include "lex.yy.c" /*É necessário adicionar o arquivo do analisador lexico gerado */

void yyerror(const char *str)
{    fprintf(stderr,"error: %s\n",str);}
%}

%token DIGIT
%token STR
%token ID
%token INT
%token FLOAT
%token CHAR
%token BOOL
%token SET
%token PAIR
%token WHILE
%token IF
%token ELSE
%token PRINT
%token READ
%token RETURN
%token BOOL_VALUE
%token NUM_VALUE
%token CHAR_VALUE

%%

outset		  	: function
			  	| outset function
			  	;

function	  	: type ID '(' arglist ')' compoundstmt
			   	;

arglist		  	: arg
			   	| arglist ',' arg
			  	;

arg			  	: type ID
	  			;

compoundstmt 	: '{' stmtlist '}'
			  	;

type			: INT
	   			| FLOAT
				| CHAR
				| BOOL
				| SET "<<" type ">>"
				| PAIR "<<" type ',' type ">>"
				;

stmtlist 		: stmtlist stmt
		   		| stmt 
				;

stmt			: whilestmt
	   			| expr ';'
				| ifstmt
				| compoundstmt
				| declaration ';'
				| io ';'
				| returnstmt ';'
				;

whilestmt		: WHILE '(' expr ')' stmt
		   		;

ifstmt 			: IF '(' expr ')' stmt elsepart
		  		;

elsepart		: ELSE stmt
		  		| 
				;

declaration		: type identlist
			 	| type attr

io				: PRINT '(' STR ')'
	  			| PRINT '(' ID ')'
				| READ '(' ID ')'
				;

returnstmt		: RETURN expr
				| RETURN
				;

expr 			: attr
				| rvalue
				| funccall
				;

attr 			: ID '=' expr
				;

identlist 		: ID ',' identlist
				| ID
				;

rvalue			: rvalue compare logicalor
		 		| logicalor
				;

compare			: "=="
		  		| "<"
				| ">"
				| "<="
				| ">="
				| "!="
				;

logicalor		: logicaland "||" logicalor
		   		| logicaland
				;

logicaland		: pertinence "&&" logicaland
				| pertinence
				;

pertinence		: pertinence "<?>" cartesian
				| cartesian
				;

cartesian		: cartesian "<*>" addition
				| addition
				;

addition		: addition "+" multiplication
		  		| addition "-" multiplication
		  		| multiplication
				;

multiplication	: multiplication "*" term
			   	| multiplication "/" term
			   	| term
				;

term			: '(' expr ')'
	   			| '-' term
				| '+' term
				| '$' term
				| '!' term
				| '{' factorlist '}'
				| '(' pair ')'
				| factor
				;

factor 			: ID
		  		| BOOL_VALUE
				| NUM_VALUE
				| CHAR_VALUE
				;

factorlist		: factorlist ',' factor
				| factor
				| 
				;

pair			: factor ',' factor 
	   			;

funccall 		: ID '(' identlist ')'
		   		;

/*expr : expr expr '+'    {$$ = $1 + $3;}*/
	/*| expr expr '*' 	{$$ = $1 * $3;}*/
	/*| DIGIT */
    /*;*/

%%

int main(int argc, char** argv)
{
	yyparse();
	return 0;
}

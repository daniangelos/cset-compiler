/* Syntax analyser */
%{
#include <stdio.h>
#include "lex.yy.c" /*É necessário adicionar o arquivo do analisador lexico gerado */
#include "src/tree.h"
#include "src/table.h"

#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

void yyerror(const char *str)
{    fprintf(stderr,"error: %s\n",str);}
int boolean_to_int(char* boolv);

int synerrors = 0;

%}


%error-verbose

%token <str>STR
%token <str>ID
%token K_INT
%token K_FLOAT
%token K_CHAR
%token K_BOOL
%token K_SET
%token K_PAIR
%token K_WHILE
%token K_IF
%token K_ELSE
%token K_PRINT
%token K_READ
%token K_RETURN
%token <boolv> BOOL_VALUE
%token <intv> INT_VALUE
%token <floatv> FLOAT_VALUE
%token <charv> CHAR_VALUE
%token DOUBLE_BR_OP
%token DOUBLE_BR_CL
%token COMPARE 			
%token DIFFERENCE 		
%token LE 				
%token GE 				
%token LOGICAL_OR 		
%token LOGICAL_AND 		
%token PERTINENCE 		
%token CARTESIAN 		

%union {
	char* boolv;
	int intv;
	float floatv;
	char charv;
	char* str;

	struct outset_t* outset_n;
	struct function_t* function_n;
	struct type_t* type_n;
	struct arglist_t* arglist_n;
	struct compoundstmt_t* compoundstmt_n;
	struct arg_t* arg_n;
	struct stmtlist_t* stmtlist_n;
	struct stmt_t* stmt_n;
	struct if_t* if_n;
	struct else_t* else_n;
	struct while_t* while_n;
	struct io_t* io_n;
	struct return_t* return_n;
	struct declaration_t* declaration_n;
	struct factor_t* factor_n;
	struct expr_t* expr_n;
	struct opun_t* opun_n;
	struct identlist_t* identlist_n;
	struct factorlist_t* factorlist_n;
	/*struct set_t* set_n;*/
	struct pair_t* pair_n;
	struct attr_t* attr_n;
	struct operation_t* operation_n;
	struct funccall_t* funccall_n;
	struct term_t* term_n;
	int op_n;

}

%type <outset_n> outset
%type <function_n> function
%type <arglist_n> arglist
%type <compoundstmt_n> compoundstmt
%type <type_n> type
%type <arg_n> arg
%type <stmtlist_n> stmtlist
%type <stmt_n> stmt
%type <while_n> whilestmt
%type <if_n> ifstmt
%type <else_n> elsepart
%type <declaration_n> declaration
%type <io_n> io
%type <return_n> returnstmt
%type <expr_n> expr
%type <attr_n> attr
%type <identlist_n> identlist
%type <operation_n> rvalue
%type <operation_n> logicalor
%type <operation_n> logicaland
%type <operation_n> pertinence
%type <operation_n> cartesian
%type <operation_n> addition
%type <operation_n> multiplication
%type <term_n> term
%type <factor_n> factor
%type <factorlist_n> factorlist
%type <pair_n> pair
%type <funccall_n> funccall
%type <op_n> compare

%%

program			: outset
		  		{
					outset_t* node = NEW(outset_t);
					node = $1;
					if(!synerrors) {
						printf("\n ***** Syntax Tree ****** \n\n");
						printSyntaxTree(node, 0);
					}
				}
					

outset		  	: outset function
				{
					outset_t* node = NEW(outset_t);
					node->outset = $1;
					node->function = $2;
					$$ = node;
				}
				| function
		   		{ 	outset_t* node = NEW(outset_t);
					node->function = $1;
					node->outset = NULL;
					$$ = node;
				}
			  	;

function	  	: type ID '(' arglist ')' compoundstmt
				{
					function_t* node = NEW(function_t);
					node->type = $1;
					node->id = malloc(strlen($2) + 1);
					strcpy(node->id, $2);
					node->arglist = $4;
					node->compoundstmt = $6;
					$$ = node;
				}
				| error '}' { printf("Line: %d\t", lines); synerrors++; yyerrok; }
			   	;

arglist		  	: arg
				{
					arglist_t* node = NEW(arglist_t);
					node->arglist = NULL;
					node->arg = $1;
					$$ = node;
				}
			   	| arglist ',' arg
				{
					arglist_t* node = NEW(arglist_t);
					node->arglist = $1;
					node->arg = $3;
					$$ = node;
				}
				|
				{
					arglist_t* node = NEW(arglist_t);
					node->arglist = NULL;
					node->arg = NULL;
					$$ = node;
				}
	
			  	;

arg			  	: type ID
		 		{
					arg_t* node = NEW(arg_t);
					node->type = $1;
					node->id = $2;
					$$ = node;
				}
				| error ' ' { printf("Line: %d\t", lines);  synerrors++; yyerrok; }
	  			;

compoundstmt 	: '{' stmtlist '}'
			  	{
					compoundstmt_t* node = NEW(compoundstmt_t);
					node->stmt_list = $2;
					$$ = node;
				}
			  	;

type			: K_INT 
	   			{
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(4);
					strcpy(tp->type.b_type, "int");
					$$ = tp;
				}
	   			| K_FLOAT
	   			{
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(6);
					strcpy(tp->type.b_type, "float");
					$$ = tp;
				}
				| K_CHAR
	   			{
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(5);
					strcpy(tp->type.b_type, "char");
					$$ = tp;
				}
				| K_BOOL
	   			{
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(5);
					strcpy(tp->type.b_type, "bool");
					$$ = tp;
				}
				| K_SET DOUBLE_BR_OP type DOUBLE_BR_CL
	   			{
					type_t* tp = NEW(type_t);
					tp->activated = 1;
					tp->type.s_type = malloc(sizeof(settype_t));
					tp->type.s_type->t = $3;
					$$ = tp;
				}
				| K_PAIR DOUBLE_BR_OP type ',' type DOUBLE_BR_CL
	   			{
					type_t* tp = malloc(sizeof(type_t));
					tp->activated = 2;
					tp->type.p_type = malloc(sizeof(pairtype_t));
					tp->type.p_type->t1 = $3;
					tp->type.p_type->t2 = $5;
					$$ = tp;
				}
				;

stmtlist 		: stmtlist stmt
		   		{
					stmtlist_t* node = NEW(stmtlist_t);
					node->stmtlist = $1;
					node->stmt = $2;
					$$ = node;
				}
		   		| stmt 
				{
					stmtlist_t* node = NEW(stmtlist_t);
					node->stmtlist = NULL;
					node->stmt = $1;
					$$ = node;
				}	
				;

stmt			: whilestmt
	   			{
					stmt_t* node = NEW(stmt_t);
					node->activated = 0;
					node->stmt.while_node = $1;
					$$ = node;
				}
	   			| expr ';'
	   			{
					stmt_t* node = NEW(stmt_t);
					node->activated = 1;
					node->stmt.expr_node = $1;
					$$ = node;
				}
				| ifstmt
	   			{
					stmt_t* node = NEW(stmt_t);
					node->activated = 2;
					node->stmt.if_node = $1;
					$$ = node;
				}
				| compoundstmt
	   			{
					stmt_t* node = NEW(stmt_t);
					node->activated = 3;
					node->stmt.cmp_node = $1;
					$$ = node;
				}
				| declaration ';'
	   			{
					stmt_t* node = NEW(stmt_t);
					node->activated = 4;
					node->stmt.declaration_node = $1;
					$$ = node;
				}
				| io ';'
	   			{
					stmt_t* node = NEW(stmt_t);
					node->activated = 5;
					node->stmt.io_node = $1;
					$$ = node;
				}
				| returnstmt ';'
	   			{
					stmt_t* node = NEW(stmt_t);
					node->activated = 6;
					node->stmt.return_node = $1;
					$$ = node;
				}
				;

whilestmt		: K_WHILE '(' expr ')' stmt
		   		{
					while_t* node = NEW(while_t);
					node->expr = $3;
					node->stmt = $5;
					$$ = node;
				}
				| error '}' {  printf("Line: %d\t", lines); synerrors++; yyerrok; }
		   		;

ifstmt 			: K_IF '(' expr ')' compoundstmt
				{
					if_t* node = NEW(if_t);
					node->expr = $3;
					node->cstmt = $5;
					node->else_node = NULL;
					$$ = node;
				}
		  		| K_IF '(' expr ')' compoundstmt elsepart
				{
					if_t* node = NEW(if_t);
					node->expr = $3;
					node->cstmt = $5;
					node->else_node = $6;
					$$ = node;
				}
		  		;

elsepart		: K_ELSE stmt
		  		{
					else_t* node = NEW(else_t);
					node->stmt = $2;
					$$ = node;
				}
				;

declaration		: type identlist
			 	{
					declaration_t* node = NEW(declaration_t);
					int activated = 0;
					node->type = $1;
					node->decl.identlist = $2;
					$$ = node;
				}	
			 	| type attr
			 	{
					declaration_t* node = NEW(declaration_t);
					int activated = 1;
					node->type = $1;
					node->decl.attr = $2;
					$$ = node;
				}	
				| error ';' { printf("Line: %d\t", lines);  synerrors++; yyerrok; }
				;

io				: K_PRINT '(' STR ')'
	  			{
					io_t* node = NEW(io_t);
					node->kind = malloc(6);
					strcpy(node->kind, "print");
					node->content = malloc(strlen($3)+1);
					strcpy(node->content, $3);
					$$ = node;
				}
	  			| K_PRINT '(' ID ')'
	  			{
					io_t* node = NEW(io_t);
					node->kind = malloc(6);
					strcpy(node->kind, "print");
					node->content = malloc(strlen($3)+1);
					strcpy(node->content, $3);
					$$ = node;
				}
				| K_READ '(' ID ')'
	  			{
					io_t* node = NEW(io_t);
					node->kind = malloc(5);
					strcpy(node->kind, "read");
					node->content = malloc(strlen($3)+1);
					strcpy(node->content, $3);
					$$ = node;
				}
				;

returnstmt		: K_RETURN expr
				{
					return_t* node = NEW(return_t);
					node->expr = $2;
					$$ = node;
				}
				| K_RETURN
				{
					return_t* node = NEW(return_t);
					node->expr = NULL;
					$$ = node;
				}
				;

expr 			: attr
				{
					expr_t* node = NEW(expr_t);
					node->activated = 0;
					node->expr.attr = $1;
					$$ = node;
				}
				| rvalue
				{
					expr_t* node = NEW(expr_t);
					node->activated = 1;
					node->expr.operation = $1;
					$$ = node;
				}
				| funccall
				{
					expr_t* node = NEW(expr_t);
					node->activated = 2;
					node->expr.funccall = $1;
					$$ = node;
				}
				;

attr 			: ID '=' expr
				{
					attr_t* node = NEW(attr_t);
					node->id = malloc(strlen($1));
					strcpy(node->id, $1);
					node->expr = $3;
					$$ = node;
				}
				;

identlist 		: ID ',' identlist
				{
					identlist_t* node = NEW(identlist_t);
					node->id = malloc(strlen($1));
					strcpy(node->id, $1);
					node->identlist = $3;
					$$ = node;
				}
				| ID
				{
					identlist_t* node = NEW(identlist_t);
					node->id = malloc(strlen($1));
					strcpy(node->id, $1);
					node->identlist = NULL;
					$$ = node;
				}
				;

rvalue			: rvalue compare logicalor
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = malloc(sizeof(opbin_t));
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = $3;
					node->kind.opbin->op = $2;
					$$ = node;
				}
		 		| logicalor
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = $1;
					$$ = node;
				}
				;

compare			: COMPARE { $$ = COMPARE_bin; }
		  		| '<' { $$ = LT_bin;}
				| '>' { $$ = GT_bin;}
				| LE { $$ = LE_bin;}
				| GE { $$ = GE_bin;}
				| DIFFERENCE { $$ = DIFFERENCE_bin;}
				;

logicalor		: logicaland LOGICAL_OR logicalor
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = $3;
					node->kind.opbin->op = LOGICALOR_bin;
					$$ = node;
				}
		   		| logicaland
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = $1;
					$$ = node;
				}
				;

logicaland		: pertinence LOGICAL_AND logicaland
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = $3;
					node->kind.opbin->op = LOGICALAND_bin;
					$$ = node;
				}
				| pertinence
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = $1;
					$$ = node;
				}
				;

pertinence		: pertinence PERTINENCE cartesian
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = $3;
					node->kind.opbin->op = PERT_bin;
					$$ = node;
				}
				| cartesian
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = $1;
					$$ = node;
				}
				;

cartesian		: cartesian CARTESIAN addition
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = $3;
					node->kind.opbin->op = CART_bin;
					$$ = node;
				}
				| addition
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = $1;
					$$ = node;
				}
				;

addition		: addition '+' multiplication
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = $3;
					node->kind.opbin->op = ADD_bin;
					$$ = node;
				}
		  		| addition '-' multiplication
		 		{ operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = $3;
					node->kind.opbin->op = MINUS_bin;
					$$ = node;
				}
		  		| multiplication
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = $1;
					$$ = node;
				}
				;

multiplication	: multiplication '*' term
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 1;
					node->kind.opbin->rhs.term = $3;
					node->kind.opbin->op = MULT_bin;
					$$ = node;
				}
			   	| multiplication '/' term
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = $1;
					node->kind.opbin->activated = 1;
					node->kind.opbin->rhs.term = $3;
					node->kind.opbin->op = DIV_bin;
					$$ = node;
				}
			   	| term
		 		{
					operation_t* node = NEW(operation_t);
					node->activated = 2;
					node->kind.term = $1;
					$$ = node;
				}
				;

term			: '(' expr ')'
	   			{
					term_t* node = NEW(term_t);
					node->activated = 0;
					node->typeofterm.expr = $2;
					$$ = node;
				}
	   			| '-' term
	   			{
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = MINUS_un;
					node->typeofterm.opun->term = $2;
					$$ = node;
				}
				| '+' term
	   			{
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = ADD_un;
					node->typeofterm.opun->term = $2;
					$$ = node;
				}
				| '$' term
	   			{
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = CARD_un;
					node->typeofterm.opun->term = $2;
					$$ = node;
				}
				| '!' term
	   			{
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = NOT_un;
					node->typeofterm.opun->term = $2;
					$$ = node;
				}
				| '{' factorlist '}'
	   			{
					term_t* node = NEW(term_t);
					node->activated = 2;
					node->typeofterm.factorlist = $2;
					$$ = node;
				}
				| '(' pair ')'
	   			{
					term_t* node = NEW(term_t);
					node->activated = 3;
					node->typeofterm.pair = $2;
					$$ = node;
				}
				| factor
	   			{
					term_t* node = NEW(term_t);
					node->activated = 4;
					node->typeofterm.factor = $1;
					$$ = node;
				}
				;

factor 			: ID
		  		{
					factor_t* node = NEW(factor_t);
					node->activated = 0;
					node->fac.id = malloc(strlen($1) + 1);
					strcpy(node->fac.id, $1);
					$$ = node;
				}
		  		| BOOL_VALUE
		  		{
					factor_t* node = NEW(factor_t);
					node->activated = 1;
					node->fac.b_value = boolean_to_int($1);
					$$ = node;
				}
				| INT_VALUE
		  		{
					factor_t* node = NEW(factor_t);
					node->activated = 2;
					node->fac.i_value = $1;
					$$ = node;
				}
				| FLOAT_VALUE
		  		{
					factor_t* node = NEW(factor_t);
					node->activated = 3;
					node->fac.f_value = $1;
					$$ = node;
				}
				| CHAR_VALUE
		  		{
					factor_t* node = NEW(factor_t);
					node->activated = 4;
					node->fac.c_value = $1;
					$$ = node;
				}
				;

factorlist		: factorlist ',' factor
				{
					factorlist_t* node = NEW(factorlist_t);
					node->factorlist = $1;	
					node->factor = $3;
					$$ = node;
				}
				| factor
				{
					factorlist_t* node = NEW(factorlist_t);
					node->factorlist = NULL;
					node->factor = $1;
					$$ = node;
				}
				| 
				{
					factorlist_t* node = NEW(factorlist_t);
					node->factorlist = NULL;
					node->factor = NULL;
					$$ = node;
				}
				;

pair			: factor ',' factor 
	   			{
					pair_t* node = NEW(pair_t);
					node->f1 = $1;
					node->f2 = $3;
					$$ = node;
				}
	   			;

funccall 		: ID '(' identlist ')'
		   		{
					funccall_t* node = NEW(funccall_t);
					node->id = malloc(strlen($1) + 1);
					strcpy(node->id, $1);
					node->identlist = $3;
					$$ = node;
				}
		   		;


%%

int main(int argc, char** argv)
{
	yyparse();

	return 0;
}

int boolean_to_int(char* boolv) {
	if(strcmp(boolv, "false")) return 1;
	return 0;
}

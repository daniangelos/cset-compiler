/* Syntax analyser */
%{
#include <stdio.h>
#include "lex.yy.c" /*É necessário adicionar o arquivo do analisador lexico gerado */
#include "src/tree.h"
#include "src/table.h"
#include "src/semantic.h"
#include "src/tac.h"

#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

extern lines;
void yyerror(const char *str)
{    fprintf(stderr,"error: %s line: %d\n",str, lines);}
int boolean_to_int(char* boolv);

int synerrors = 0;
int semerrors = 0;
int label = 0;

symb** table;
int scope = 0;
char c;
functionsymb_t* f_temp;


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
%type <arglist_n> arglistlist
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
%type <identlist_n> identlistlist
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
					outset_t* root = NEW(outset_t);
					root = $1;
					checkForUndefinedSymbols(table);
					if(!synerrors && !lexerrors && !semerrors) {
						/*printf("\n ****** Syntax Tree ****** \n\n");*/
						/*printSyntaxTree(root, 0);*/
						/*typeCheck(root);*/
						/*printf("\n\n ****** Symbol Table ****** \n\n");*/
						/*printTable(table);*/
						generateCode(table, root);
						/*destructTree(root);*/
						/*destructTable(table);*/
					}
				}
					

outset		  	: outset function
				{
					outset_t* node = NEW(outset_t);
					node->outset = $1;
					node->function = $2;
					$$ = node;
				}
				| declaration ';'
				{
					scope++;
					outset_t* node = NEW(outset_t);
					node->declaration = $1;
					node->outset = NULL;
					node->function = NULL;
					$$ = node;
					
				}
				| function
		   		{ 	
					outset_t* node = NEW(outset_t);
					node->function = $1;
					node->outset = NULL;
					node->declaration = NULL;
					$$ = node;
				}
			  	;

function	  	: type ID '(' arglist ')' compoundstmt
				{
					scope++;
					function_t* node = NEW(function_t);
					node->type = $1;
					node->id = malloc(strlen($2) + 1);
					strcpy(node->id, $2);
					node->arglist = $4;
					node->compoundstmt = $6;
					node->code = malloc(strlen($2) + 3);
					strcpy(node->code, "\n");
					strcat(node->code, $2);
					strcat(node->code, ": ");	
					/*printf("%s\n",node->code);*/
					$$ = node;

					f_temp = NEW(functionsymb_t);
					f_temp->type_return = $1;
					f_temp->args = $4;
					if(addSymbol(table, $2, $1, scope, f_temp)) {
						semerrors++;
						printf("Erro semantico. Redeclaracao da funcao '%s'. Linha: %d\n", $2, lines);	
					}
				}
				| error '}' { synerrors++; yyerrok; }
			   	;

arglist		  	: arglistlist
				{
					$$ = $1;
				}
				| 
				{
					$$ = NULL;
				}
				;

arglistlist	   	: arglist ',' arg
				{
					arglist_t* node = NEW(arglist_t);
					node->arglist = $1;
					node->arg = $3;
					$$ = node;
				}
				| arg
				{
					arglist_t* node = NEW(arglist_t);
					node->arglist = NULL;
					node->arg = $1;
					$$ = node;
				}
			  	;

arg			  	: type ID
		 		{
					arg_t* node = NEW(arg_t);
					node->type = $1;
					node->id = $2;
					$$ =  node;
					if(addSymbol(table, $2, $1, scope + 1, NULL)) {
						semerrors++;
						printf("Erro semantico. Redeclaracao do identificador '%s'. Linha: %d\n", $2, lines);	
					}
				}
				| error ' ' { synerrors++; yyerrok; }
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
					node->code = malloc(50);
					label++;
					char* str1 = malloc(strlen("label: if !expr goto whilenext\n") + 5);
					sprintf(str1, "label%d: if !expr goto whilenext%d\n", label, label);
					strcpy(node->code, str1);
					strcat(node->code, "stmt code\n");
					char* str2 = malloc(strlen("goto labelx"));
					sprintf(str2,"goto label%d\n", label);
					strcat(node->code, str2);
					sprintf(str2, "whilenext%d:",label);
					strcat(node->code, str2);
					/*free(str1);*/
					/*free(str2);*/
					/*printf("%s\n", node->code);*/
					$$ = node;
					if(typeCheckCond(table, $3, scope)){
						semerrors++;
						printf("Erro semantivo linha %d. Condicao em while deve ter tipo bool.\n", lines);
					}
				}
				| error '}' { synerrors++; yyerrok; }
		   		;

ifstmt 			: K_IF '(' expr ')' compoundstmt
				{
					if_t* node = NEW(if_t);
					node->expr = $3;
					node->cstmt = $5;
					node->else_node = NULL;
					label++;
					node->code = malloc(50);
					char* str1 = malloc(strlen("if !expr goto ifnext\n") + 10);
					sprintf(str1, "if !expr goto ifnext%d\n", label);
					strcpy(node->code, str1);
					strcat(node->code, "cmpstmt code\n");
					char* str2 = malloc(strlen("goto labelx"));
					sprintf(str2, "ifnext%d:",label);
					strcat(node->code, str2);
					/*free(str1);*/
					/*free(str2);*/
					/*printf("%s\n", node->code);*/
					$$ = node;
					if(typeCheckCond(table, $3, scope)){
						semerrors++;
						printf("Erro semantivo linha %d. Condicao em if deve ter tipo bool.\n", lines);
					}
				}
		  		| K_IF '(' expr ')' compoundstmt elsepart
				{
					if_t* node = NEW(if_t);
					node->expr = $3;
					node->cstmt = $5;
					node->else_node = $6;
					$$ = node;
					if(typeCheckCond(table, $3, scope)){
						semerrors++;
						printf("Erro semantivo linha %d. Condicao em if deve ter tipo bool.\n", lines);
					}
				}
		  		;

elsepart		: K_ELSE stmt
		  		{
					else_t* node = NEW(else_t);
					node->stmt = $2;
					$$ = node;
				}
				;

declaration		: type attr
			 	{
					declaration_t* node = NEW(declaration_t);
					int activated = 1;
					node->type = $1;
					node->decl.attr = $2;
					$$ = node;
					if(addSymbol(table, node->decl.attr->id, $1, scope + 1, NULL)){
						semerrors++;
						printf("Erro semantico. Redeclaracao do identificador '%s'. Linha: %d\n", node->decl.attr->id, lines);	
					}
				}
			 	| type identlist
			 	{
					declaration_t* node = NEW(declaration_t);
					int activated = 0;
					node->type = $1;
					node->decl.identlist = $2;
					if(addSymbol(table, node->decl.identlist->id, $1, scope + 1, NULL)){
						semerrors++;
						printf("Erro semantico. Redeclaracao do identificador '%s'. Linha: %d\n", node->decl.identlist->id, lines);	
					}
					$$ = node;
				}	
				| error ';' { synerrors++; yyerrok; }
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
					addSymbol(table, $3, NULL, scope + 1, NULL);	
				}
				| K_READ '(' ID ')'
	  			{
					io_t* node = NEW(io_t);
					node->kind = malloc(5);
					strcpy(node->kind, "read");
					node->content = malloc(strlen($3)+1);
					strcpy(node->content, $3);
					$$ = node;
					addSymbol(table, $3, NULL, scope + 1, NULL);	
				}
				;

returnstmt		: K_RETURN expr
				{
					return_t* node = NEW(return_t);
					node->expr = $2;
					$$ = node;
				}
				/*| K_RETURN*/
				/*{*/
					/*return_t* node = NEW(return_t);*/
					/*node->expr = NULL;*/
					/*$$ = node;*/
				/*}*/
				;

expr 			: attr
				{
					expr_t* node = NEW(expr_t);
					node->activated = 0;
					node->expr.attr = $1;
					node->type = NULL;
					/*node->code = $1->code;*/
					$$ = node;
				}
				| rvalue
				{
					expr_t* node = NEW(expr_t);
					node->activated = 1;
					node->expr.operation = $1;
					node->type = NULL;
					/*node->code = malloc(strlen($1->code)+1);*/
					$$ = node;
				}
				| funccall
				{
					expr_t* node = NEW(expr_t);
					node->activated = 2;
					node->expr.funccall = $1;
					node->type = NULL;
					node->code = $1->code;
					$$ = node;
				}
				;

attr 			: ID '=' expr
				{
					attr_t* node = NEW(attr_t);
					node->id = malloc(strlen($1));
					strcpy(node->id, $1);
					node->expr = $3;
					/*node->code = malloc(strlen($3->code)+strlen($1)+6);*/
					$$ = node;
					addSymbol(table, $1, NULL, scope + 1, NULL);	
					switch(typeCheckAttr(table, $1, $3, scope + 1)){
					case 1:
						semerrors++;
						printf("Erro semantico linha %d. Tipos incompativeis na atribuicao.\n",lines);
						break;
					case 2:
						semerrors++;
						printf("Erro semantico linha %d. O tipo do lado esquerdo da atribuicao nao pode ser avaliado.\n",lines);
						break;
					case 3:
						semerrors++;
						printf("Erro semantico linha %d. O tipo do lado direito da atribuicao nao pode ser avaliado.\n",lines);
						break;
					}
	
				}
				;

identlist 		: identlistlist
				|
				{
					$$ = NULL;
				}
				;

identlistlist:	identlist ',' ID
				{
					identlist_t* node = NEW(identlist_t);
					node->id = malloc(strlen($3));
					strcpy(node->id, $3);
					node->identlist = $1;
					$$ = node;
					addSymbol(table, $3, NULL, scope + 1, NULL);	
				}
				| ID
				{
					identlist_t* node = NEW(identlist_t);
					node->id = malloc(strlen($1));
					strcpy(node->id, $1);
					node->identlist = NULL;
					$$ = node;
					addSymbol(table, $1, NULL, scope + 1, NULL);	
				}

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
					addSymbol(table, $1, NULL, scope + 1, NULL);	
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
					int numparam;
					if($3 == NULL) {
						node->code = malloc(strlen($1) + 10);
						numparam = 0;
					}
					else {
						char* aux = stackId($3, &numparam);
						node->code = malloc(strlen(aux) + strlen($1) + 10);
						strcpy(node->code, aux);
						/*free(aux);*/
					}
					strcat(node->code, "call ");
					strcat(node->code, $1);
					strcat(node->code, ", ");
					char str[3];
					sprintf(str, "%d", numparam);
					strcat(node->code, str);
					/*printf("%s\n", node->code);*/
					$$ = node;
					switch(findFuncDecl(table, $1, $3, scope+1)) {
					case 1:
						printf("Erro semantico, linha %d. Chamada a funcao nao definida!\n", lines);							
						semerrors++;
						break;
					case 2:
						printf("Erro semantico, linha %d. Numero de argumentos invalido!\n", lines);							
						semerrors++;
						break;
					case 3:
						printf("Erro semantico, linha %d. Tipo de argumento nao esperado.\n", lines);
						semerrors++;
						break;
					}
						

				}
		   		;


%%

int main(int argc, char** argv)
{
	if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }
	table = malloc(sizeof(symb));
	yyparse();

	return 0;
}

int boolean_to_int(char* boolv) {
	if(strcmp(boolv, "false")) return 1;
	return 0;
}

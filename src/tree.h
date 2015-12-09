#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum{COMPARE_bin, LT_bin, GT_bin, LE_bin, GE_bin, DIFFERENCE_bin, LOGICALOR_bin, LOGICALAND_bin, ADD_bin, MINUS_bin, MULT_bin, DIV_bin, PERT_bin, CART_bin};
enum{MINUS_un, ADD_un, CARD_un, NOT_un};

typedef struct outset_t outset_t;
typedef struct function_t function_t;
typedef struct type_t type_t;
typedef struct arglist_t arglist_t;
typedef struct compoundstmt_t compoundstmt_t;
typedef struct arg_t arg_t;
typedef struct stmtlist_t stmtlist_t;
typedef struct stmt_t stmt_t;
typedef struct if_t if_t;
typedef struct else_t else_t;
typedef struct while_t while_t;
typedef struct io_t io_t;
typedef struct return_t return_t;
typedef struct declaration_t declaration_t;
typedef struct factor_t factor_t;
typedef struct expr_t expr_t;
typedef struct opun_t opun_t;
typedef struct identlist_t identlist_t;
typedef struct factorlist_t factorlist_t;
typedef struct settype_t settype_t;
typedef struct pairtype_t pairtype_t;
typedef struct pair_t pair_t;
typedef struct attr_t attr_t;
typedef struct operation_t operation_t;
typedef struct funccall_t funccall_t;
typedef struct term_t term_t;
typedef struct opbin_t opbin_t; 

struct outset_t {
	outset_t* outset;
	int activated;
	union{
		declaration_t* declaration;
		function_t* function;
	}kind;
};

struct function_t {
	type_t* type;
	char* id;
	arglist_t* arglist;
	compoundstmt_t* compoundstmt;
	char* code;
};

struct arglist_t {
	arglist_t* arglist;
	//,
	arg_t* arg;
};

struct arg_t {
	type_t* type;
	char* id;
};

struct compoundstmt_t {
	stmtlist_t* stmt_list; /*** NAO ESQUECE AS CHAVES ***/
};

struct type_t {
	int activated;
	union {
		char* b_type;
		settype_t* s_type;
		pairtype_t* p_type;
	}type;
};

struct stmtlist_t {
	stmtlist_t* stmtlist;
	stmt_t* stmt;
};

struct stmt_t {
	int activated;
	union {
		while_t* while_node;
		expr_t* expr_node; /*** NAO ESQUECE O PONTO E VIRGULA ***/
		if_t* if_node;
		compoundstmt_t* cmp_node;
		declaration_t* declaration_node; /*** AQ TBM ***/
		io_t* io_node; /***AQ TBM***/
		return_t* return_node; /*** AQ TBM ***/
	} stmt;
};

struct while_t {
	//char* while_k = "while";
	//(
	expr_t* expr;
	//)
	stmt_t* stmt;
	char* code;
};

struct if_t {  
	//char* if_k = "if";
	//(
	expr_t* expr;
	//)
	compoundstmt_t* cstmt;
	else_t* else_node;
	char* code;
};

struct else_t {
	//char* else_k = "else";
	stmt_t* stmt;
};

struct declaration_t {
	type_t* type;
	int activated;
	union {
		identlist_t* identlist;
		attr_t* attr;
	}decl;
};

struct io_t {
	char* kind;
	// (
	char* content;
	//)
};

struct return_t {
	//char* return_k = "return";
	expr_t* expr; /*** PODE SER VAZIO ***/
};

struct expr_t {
	int activated;
	union {
		attr_t* attr;
		operation_t* operation;
		funccall_t* funccall;
	}expr;
	type_t* type;
	char* code;
};

struct attr_t {
	char* id;
	// =
	expr_t* expr;
	char* code;
};

struct identlist_t {
	char* id;
	identlist_t* identlist; // PODE SER VAZIO
};

struct operation_t {
	int activated;
	union {
		opbin_t* opbin;
		operation_t* operation;
		term_t* term;
	}kind;
	char* code;
};

struct opbin_t {
	int op;
	operation_t* lhs;
	int activated;
	union {
		operation_t* rop;
		term_t* term;
	}rhs;
};

struct term_t {
	int activated;
	union {
		/*(*/ expr_t* expr; /*)*/
		opun_t* opun;
		/*{*/ factorlist_t* factorlist; /*}*/
		/*(*/ pair_t* pair; /*)*/
		factor_t* factor;
	}typeofterm;
};

struct opun_t {
	int opt;
	term_t* term;
};

struct factor_t {
	int activated;
	union {
		char* id;
		int b_value; //0 false 1 true
		int i_value;
		float f_value;
		char c_value;
	}fac;
};

struct factorlist_t {
	factorlist_t* factorlist; //PODE SER NULL
	// ,
	factor_t* factor;
};

struct pair_t {
	factor_t* f1;
	//,
	factor_t* f2;
};

struct settype_t {
	type_t* t;
};

struct pairtype_t {
	// (
	type_t* t1;
	type_t* t2;
	// )
};

struct funccall_t {
	char* id;
	//(
	identlist_t* identlist;
	//)
	char* code;
};

void printSyntaxTree ( outset_t* node , int i );
void printFunctionTree ( function_t* function , int i );
void printType ( type_t* type , int i );
void printSetType( settype_t* settype , int i );
void printPairType ( pairtype_t* pairtype, int i );
void printArglist (arglist_t* arglist, int i);
void printArg ( arg_t* arg, int i);
void printCompoundstmt(compoundstmt_t* cstmt, int i );
void printStmtlist ( stmtlist_t* stmtlist , int i ) ;
void printStmt ( stmt_t* stmt, int i) ;
void printWhile(while_t* while_node, int i) ;
void printExpr ( expr_t* expr, int i) ;
void printIf (if_t* if_node, int i) ;
void printElse(else_t* else_node, int i) ;
void printDecl (declaration_t* decl, int i );
void printIO (io_t* io_node, int i ) ;
void printReturn (return_t* ret, int i) ;
void printAttr ( attr_t* attr, int i) ;
void printFunccall (funccall_t* funcc, int i) ;
void printIdentlist (identlist_t* ident, int i) ;
void printOperation ( operation_t* op , int i ) ;
void printOpbin (opbin_t* opbin, int i) ;
void printTerm ( term_t* term, int i) ;
void printOpun ( opun_t* opun , int i) ;
void printFactorlist ( factorlist_t* flist , int i ) ;
void printFactor (factor_t* factor, int i ) ;
void printPair(pair_t* pair, int i) ;
void destructTree(outset_t* node);

void destructFunction(function_t* node) ;
void destructArglist(arglist_t* node) ;
void destructCompound(compoundstmt_t* node) ;
void destructArg(arg_t* node) ;
void destructStmtlist(stmtlist_t* node) ;
void destructType(type_t* node) ;
void destructStmt(stmt_t* node) ;
void destructSetType(settype_t* node) ;
void destructPairType(pairtype_t* node);
void destructWhile(while_t* node) ;
void destructIf(if_t* node);
void destructDeclaration(declaration_t* node) ;
void destructIO (io_t* node) ;
void destructReturn(return_t* node) ;
void destructExpr(expr_t* node) ;
void destructAttr(attr_t* node) ;
void destructIdentlist(identlist_t* node);
void destructOperation(operation_t* node) ;
void destructOpbin(opbin_t* node) ;
void destructTerm(term_t* node);
void destructOpun(opun_t* node);
void destructFactor(factor_t* node) ;
void destructFactorlist(factorlist_t* node) ;
void destructPair(pair_t* node) ;
void destructFunccall (funccall_t* node) ;

#endif //TREE_H

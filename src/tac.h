#ifndef TAC_H
#define TAC_H

#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
#include "table.h"

void gerenateCode(symb** first, outset_t* root);
char* stackId (identlist_t* list, int* n) ;
void printFunctionCode(function_t* node, FILE* fp) ;	
void printWhileCode(while_t* node, FILE* fp) ;
void printIfCode(if_t* node, FILE* fp) ;
void printExprCode(char* tmp, expr_t* node, FILE* fp) ;
void printStmtCode(stmt_t* node, FILE* fp) ;
void printCmpCode(compoundstmt_t* node, FILE* fp) ;
void printDeclCode(declaration_t* node, FILE* fp) ;
void printIOCode (io_t* node, FILE* fp) ;
void printReturnCode (return_t* node, FILE* fp) ;
void printAttrCode(attr_t* node, FILE* fp) ;
void printIdentlistCode(identlist_t* node, FILE* fp) ;
void printOpCode (char* tmp, operation_t* node, FILE* fp) ;
void printTermCode(char* tmp, term_t* node, FILE* fp) ;
void printFactorCode(char* tmp, factor_t* node, FILE *fp) ;
void printOpUnCode(opun_t* node, FILE* fp) ;
void printOpbinCode(char* tmp, opbin_t* node, FILE* fp) ;
char* opuntostr (int op) ;
char* opbintostr(int op) ;
char* chooseTemporary() ;

int i;
int label;
#endif // TAC_H

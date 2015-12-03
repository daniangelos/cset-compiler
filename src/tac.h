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
void printExprCode(expr_t* node, FILE* fp) ;

#endif // TAC_H

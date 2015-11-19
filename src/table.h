#ifndef TABLE_H
#define TABLE_H

#include<stdio.h>
#include<string.h>
#include "tree.h"

typedef struct functionsymb_t {
	type_t* type_return;
	arglist_t* args;
}functionsymb_t;

typedef struct symb {
	char * id;
	struct symb* next;
	type_t* type;
	int scope;
	functionsymb_t* function;
	//function_t* function;
}symb;

void createTable(symb** first) ;
int addSymbol (symb** first, char* content, type_t* type, int scope, functionsymb_t* function) ;
void printTable(symb** first);

#endif //TABLE_H


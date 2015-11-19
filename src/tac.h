#ifndef TAC_H
#define TAC_H

#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
#include "table.h"

void gerenateCode(symb** first, outset_t* root);
char* stackId (identlist_t* list, int* n) ;

#endif // TAC_H

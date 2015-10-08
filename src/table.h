#ifndef TABLE_H
#define TABLE_H

#include<stdio.h>
#include "tree.h"

typedef struct symb {
	char * id;
	struct symb* next;
	type_t* type;
}symb;

#endif //TABLE_H


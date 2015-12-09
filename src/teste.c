#include "tree.h"
#include "semantic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	type_t* tint = malloc(sizeof(type_t));
	tint->activated = 0;
	tint->type.b_type = malloc(4);
	strcpy(tint->type.b_type, "int");
	type_t* tp = malloc(sizeof(type_t*));
	tp->activated = 2;
	tp->type.p_type = malloc(sizeof(pairtype_t*));
	tp->type.p_type->t1 = tint;
	tp->type.p_type->t2 = tint;
	factorlist_t* fl = malloc(sizeof(factorlist_t));
	fl->factorlist = malloc(sizeof(factorlist_t));
	fl->factorlist->factor = malloc(sizeof(factor_t));
	fl->factor = malloc(sizeof(factor_t));
	fl->factorlist->factorlist = NULL;
	fl->factorlist->factor->activated = 2;
	fl->factorlist->factor->fac.i_value = 10;
	fl->factor->activated = 2;
	fl->factor->fac.i_value = 42;

	

	printf("type is: %s\n", type_tostring(factorlistHasType(NULL, fl, 0)));

	free(tint->type.b_type);
	free(tint);
	free(tp->type.p_type);
	free(tp);

	return 0;
}


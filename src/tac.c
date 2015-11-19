#include "tac.h"

void generateCode(symb** first, outset_t* root){
	FILE *fout;
	fout = fopen("cset.tac","w");

			


}

char* stackId (identlist_t* list, int* n) {
	identlist_t* aux = list;
	char* code = malloc(1);
	*n = 1;

	while(aux->identlist != NULL) {
		code = realloc(code, strlen(aux->id) + 8);
		strcat(code, "param ");
		strcat(code, aux->id);
		strcat(code, "\n");
		aux = aux->identlist;
		*n = *n + 1;
	}
	code = realloc(code, strlen(aux->id) + 8);
	strcat(code, "param ");
	strcat(code, aux->id);
	strcat(code, "\n");
	return code;
}
		

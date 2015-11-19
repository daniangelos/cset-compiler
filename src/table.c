#include "table.h"

extern int checkTable(symb** first, char* content, int scope, int function);

int addSymbol (symb** first, char* content, type_t* type, int scope, functionsymb_t* function) {
	int fun = 1; 
	if(function == NULL) fun = 0;

	if(type != NULL && *first != NULL) { 
		int err = checkTable(first, content, scope, fun);
		if (err) { return err; }
	}
		
	symb* temp = malloc(sizeof(symb));

	temp->id = content;
	temp->type = type;
	temp->scope = scope;
	temp->function = function;
	temp->next = NULL;

	if(*first == NULL) *first = temp;
	else {
		symb* aux;
		aux = *first;
		while(aux->next != NULL) {
			if(aux->scope != scope) aux = aux->next;
			else {
				if(strcmp(aux->id, content) == 0) 
				{
					if (aux->type == NULL && type != NULL)
						aux->type = type;
					return 0;
				}
				aux = aux->next;
			}

		}

		if(aux->scope == scope) {
			if(strcmp(aux->id, content) == 0)
			{
				if (aux->type == NULL) aux->type = type;
				return 0;
			}
		}
		aux->next = temp;

	}



	return 0;
}


void printTable (symb** first) {
	symb* aux;
	aux = *first;

	printf("[ \t ID \t | \tTYPE \t |\tSCOPE \t] \n");

	while(aux!=NULL) {
		printf("|\t");
		printf ("%s", aux->id);
		printf("\t | \t");
		if(aux->type != NULL) {
			switch(aux->type->activated) {
				case 0:
					printf(" %s", aux->type->type.b_type);
					break;
				case 1:
					printf(" set");
					break;
				case 2:
					printf(" pair");
					break;
			}
		}
		printf("\t | \t");
		printf(" %d ", aux->scope);
		aux = aux->next;
		printf(" \t|\n");
	}

	printf("\n");

	return;

}

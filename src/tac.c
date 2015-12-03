#include "tac.h"

void generateCode(symb** first, outset_t* root){
	FILE *fout;
	fout = fopen("cset.tac","w");
	outset_t* node = root;

	while(node->outset != NULL) {
		if(node->function != NULL) 
			printFunctionCode(node->function, fout);
		node = node->outset;
	}

	printFunctionCode(node->function, fout);
			

	fprintf(fout, "\n");
	fclose(fout);

}

void printFunctionCode(function_t* node, FILE* fp) {
	if( node != NULL) {
		stmtlist_t* aux = node->compoundstmt->stmt_list;
		fprintf(fp, "%s", node->code);
			
		if(aux != NULL) {
			while(aux->stmtlist != NULL) {
				if(aux->stmt->activated == 0)
					printWhileCode(aux->stmt->stmt.while_node, fp);
				else if(aux->stmt->activated == 1)
					printExprCode(aux->stmt->stmt.expr_node, fp);
				else if(aux->stmt->activated == 2)
					printIfCode(aux->stmt->stmt.if_node, fp);
				aux = aux->stmtlist;
			}
		}


	}
}

void printWhileCode(while_t* node, FILE* fp) {
	if(node != NULL) {
		fprintf(fp, "%s", node->code);
	}
}

void printIfCode(if_t* node, FILE* fp) {
	if(node != NULL) {
		fprintf(fp, "%s", node->code);
	}
}

void printExprCode(expr_t* node, FILE* fp) {
	if(node->activated == 2){
		fprintf(fp, "%s", node->expr.funccall->code);
	}

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
		

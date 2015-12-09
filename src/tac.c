#include "tac.h"

int i = 0;
int label = 0;

void generateCode(symb** first, outset_t* root){
	FILE *fout;
	fout = fopen("cset.tac","w");
	outset_t* node = root;

	while(node->outset != NULL) {
		if(node->activated == 1)
			printFunctionCode(node->kind.function, fout);
		node = node->outset;
	}

	if(node->activated == 1)
		printFunctionCode(node->kind.function, fout);
				

	fprintf(fout, "\n");
	fclose(fout);

}

void printFunctionCode(function_t* node, FILE* fp) {
	if( node != NULL) {
		fprintf(fp, "%s", node->code);
		printCmpCode(node->compoundstmt, fp);
	}
}

void printStmtlistCode(stmtlist_t* node, FILE* fp) {
	if(node != NULL) {
		stmtlist_t* aux = node->stmtlist;
		if(aux != NULL) {
			while(aux->stmtlist != NULL) {
				printStmtCode(aux->stmt, fp);
				aux = aux->stmtlist;
			}
			printStmtCode(aux->stmt, fp);
		}
	}
}

void printStmtCode(stmt_t* node, FILE* fp) {
	if(node != NULL) { 
		char* tmp = chooseTemporary();
		switch (node->activated ) {
			case 0:
				printWhileCode(node->stmt.while_node, fp);
				break;
			case 1:
				printExprCode(tmp, node->stmt.expr_node, fp);
				break;
			case 2:
				printIfCode(node->stmt.if_node, fp);
				break;
			case 3:
				printCmpCode(node->stmt.cmp_node, fp);
				break;
			case 4:
				printDeclCode(node->stmt.declaration_node, fp);
				break;
			case 5:
				printIOCode(node->stmt.io_node, fp);
				break;
			case 6:
				printReturnCode(node->stmt.return_node, fp);
				break;
		}
	}
}

void printWhileCode(while_t* node, FILE* fp) {
	if(node != NULL) {
		size_t sz;
		char* tmp = chooseTemporary();
		sz = 50;
		node->code = malloc(sz);
		printExprCode(tmp, node->expr, fp);
		char* str1 = malloc(strlen("label: if !expr goto whilenext\n") + 5);
		sprintf(str1, "label%d: if !expr goto whilenext%d\n", label, label);
		strcpy(node->code, str1);
		strcat(node->code, "stmt code\n");
		char* str2 = malloc(strlen("goto labelx"));
		sprintf(str2,"goto label%d\n", label);
		strcat(node->code, str2);
		sprintf(str2, "whilenext%d:",label);
		strcat(node->code, str2);
		fprintf(fp, "%s", node->code);
		label++;
	}
}

void printIfCode(if_t* node, FILE* fp) {
	if(node != NULL) {
		size_t sz;
		label++;
		sz = 50;
		node->code = malloc(sz);
		char* str1 = malloc(strlen("if !expr goto ifnext\n") + 10);
		sprintf(str1, "if !expr goto ifnext%d\n", label);
		strcpy(node->code, str1);
		strcat(node->code, "cmpstmt code\n");
		char* str2 = malloc(strlen("goto labelx"));
		sprintf(str2, "ifnext%d:",label);
		strcat(node->code, str2);
		fprintf(fp, "%s", node->code);
	}
}

void printExprCode(char* tmp, expr_t* node, FILE* fp) {
	if(node != NULL) {
		switch(node->activated) {
			case 0:
				printAttrCode(node->expr.attr, fp);
				break;
			case 1:
				printOpCode(tmp, node->expr.operation, fp);
				break;
			case 2:
				fprintf(fp, "%s", node->expr.funccall->code);
				break;
		}
	}
}

void printCmpCode(compoundstmt_t* node, FILE* fp) {
	if(node != NULL) {
		printStmtlistCode(node->stmt_list, fp);
	}
}

void printDeclCode(declaration_t* node, FILE* fp) {
	if(node != NULL) {
		if(node->activated == 0) {
			printIdentlistCode(node->decl.identlist, fp);
		}
		else{
			printAttrCode(node->decl.attr, fp);
		}
	}
}

void printIOCode (io_t* node, FILE* fp) {
	/*printf("oi");*/
}

void printReturnCode (return_t* node, FILE* fp) {
	/*printf("return");*/
	char* tmp = chooseTemporary();
	printExprCode(tmp, node->expr, fp);
}

void printIdentlistCode(identlist_t* node, FILE* fp) {
	if(node!= NULL) {
		identlist_t* aux = node->identlist;
		while(aux != NULL) {
			aux = node->identlist;
		}
	}
}

void printAttrCode(attr_t* node, FILE* fp) {
	char* tmp;
	tmp = chooseTemporary();

	printExprCode(tmp, node->expr, fp);
	fprintf(fp, "%s = %s\n", node->id, tmp);
	free(tmp);
}

void printOpCode (char* tmp, operation_t* node, FILE* fp) {
	while(node->activated == 1) {
		node = node->kind.operation;
	}

	switch(node->activated) {
		case 0:
			printOpbinCode(tmp, node->kind.opbin, fp);
			break;
		case 2:
			printTermCode(tmp, node->kind.term, fp);
			break;
	}

}

void printOpbinCode(char* tmp, opbin_t* node, FILE* fp) {
	if(node != NULL) {
		char* lhs = chooseTemporary();
		char* rhs = chooseTemporary();
		char* op = opbintostr(node->op);
		/*fprintf(fp, "%s = ", str);*/
		printOpCode(lhs, node->lhs, fp);

		if(node->activated == 0) 
			printOpCode(rhs, node->rhs.rop, fp);
		else
			printTermCode(rhs, node->rhs.term, fp);

		fprintf(fp, "%s = %s %s %s\n", tmp, lhs, op, rhs);

	}
}

void printTermCode(char* tmp, term_t* node, FILE* fp) {
	if(node != NULL) {
		/*char* tmp = chooseTemporary();*/
		switch(node->activated) {
			case 0:
				printExprCode(tmp, node->typeofterm.expr, fp);
				break;
			case 1:
				printOpUnCode(node->typeofterm.opun, fp);
				break;
			case 2:
				/*printFactorlistCode(node->typeofterm.factorlist, fp);*/
				break;
			case 3:
				/*printPairCode(node->typeofterm.pair, fp);*/
				break;
			case 4:
				printFactorCode(tmp, node->typeofterm.factor, fp);
				break;
		}
	}
}

void printOpUnCode(opun_t* node, FILE* fp) {
	if (node != NULL ){
		char* tmp = chooseTemporary();
		fprintf(fp, "%s", opuntostr(node->opt));
		printTermCode(tmp, node->term, fp);
	}
}

void printFactorCode(char* tmp, factor_t* node, FILE *fp) {
	if(node != NULL) {
		fprintf(fp, "%s = ", tmp);
		switch(node->activated) {
			case 0:
				fprintf(fp, "%s\n", node->fac.id);
				break;
			case 1:
				if(node->fac.b_value == 0)
					fprintf(fp, "false\n");
				else
					fprintf(fp, "true\n");
				break;
			case 2:
				fprintf(fp, "%d\n", node->fac.i_value);
				break;
			case 3:
				fprintf(fp, "%f\n", node->fac.f_value);
				break;
			case 4:
				fprintf(fp, "%c\n", node->fac.c_value);
				break;
		}
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


char* chooseTemporary() {
	char* str;
	size_t sz;
	sz = 5;
	str = malloc(sz);

	sprintf(str, "t%d", i);
	i++;
	if(i > 999) i = 0;
	return str;
}
		
char* opuntostr (int op) {
	char* str;
	size_t sz = 1;

	switch(op){
		case 0:
			sz += strlen("minus");
			str = malloc(sz);
			strcpy(str, "minus ");
			break;
		case 3:
			sz += strlen("not");
			str = malloc(sz);
			strcpy(str, "not ");
			break;
	}


	return str;
}

char* opbintostr(int op) {
	char* str;
	size_t sz = 1;

	switch(op){
		case 0:
			sz+=2;
			str = malloc(sz);
			strcpy(str, "==");
			break;
		case 1:
			sz++;
			str = malloc(sz);
			strcpy(str, "<");
			break;
		case 2:
			sz++;
			str = malloc(sz);
			strcpy(str, ">");
			break;
		case 3:
			sz += 2;
			str = malloc(sz);
			strcpy(str, "<=");
			break;
		case 4:
			sz += 2;
			str = malloc(sz);
			strcpy(str, ">=");
			break;
		case 5:
			sz += 2;
			str = malloc(sz);
			strcpy(str, "!=");
			break;
		case 6:
			sz += 2;
			str = malloc(sz);
			strcpy(str, "!!");
			break;
		case 7:
			sz += 2;
			str = malloc(sz);
			strcpy(str, "&&");
			break;
		case 8:
			sz++;
			str = malloc(sz);
			strcpy(str, "+");
			break;
		case 9:
			sz++;
			str = malloc(sz);
			strcpy(str, "-");
			break;
		case 10:
			sz++;
			str = malloc(sz);
			strcpy(str, "*");
			break;
		case 11:
			sz++;
			str = malloc(sz);
			strcpy(str, "/");
			break;
		case 12:
			sz += 3;
			str = malloc(sz);
			strcpy(str, "<?>");
			break;
		case 13:
			sz += 3;
			str = malloc(sz);
			strcpy(str, "<*>");
			break;
	}

	return str;
}

			









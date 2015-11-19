#include "semantic.h"

int checkTable(symb** first, char* content, int scope, int function) {
	symb* aux;
	aux = *first;
	
	while(aux->next != NULL) {
		if(strcmp(aux->id, content) == 0){
			if(aux->scope == scope)
				return 1;
			if(aux->function != NULL && function == 1)
				return 1;
		}
		aux = aux->next;

	}


	return 0;
}

void checkForUndefinedSymbols(symb** first) {
	symb* aux = *first;

	while(aux->next != NULL) {
		if(aux->type == NULL) printf("Erro semantico. Identificador '%s' nao declarado.\n", aux->id);
		aux = aux->next;
	}

	if(aux->type == NULL) printf("Erro semantico. Identificador '%s' nao declarado.\n", aux->id);

}


type_t* findType(symb** first, char* id, int scope) {
	symb* aux;
	aux = *first;

	while(aux->next != NULL) {
		if(strcmp(aux->id, id) == 0 && aux->scope == scope){
			return aux->type;
		}
		aux = aux->next;
	}

	if(strcmp(aux->id, id) == 0){
		return aux->type;
	}

	return NULL;
}
	


char* type_tostring(type_t* tp_aux) {
	char* tp;
	if(tp_aux == NULL) {return "null";}
	switch(tp_aux->activated){
		case 0:
			tp = malloc(sizeof(strlen(tp_aux->type.b_type)));
			strcpy(tp, tp_aux->type.b_type);
			return tp;
		case 1:
			tp = malloc(sizeof(4));
			strcpy(tp, "set");
			return tp;
		case 2:
			tp = malloc(sizeof(5));
			strcpy(tp, "pair");
			return tp;
		default:
			return NULL;
	}
}

int findFuncDecl (symb** first, char* id, identlist_t* identlist, int scope) {
	symb* aux;
	aux = *first;
	identlist_t* list;
	list = identlist;
	int found = 1;
	type_t* tp_aux;
	char* tp1;
	char* tp2;
	int i = 1;

	while(aux->next != NULL) {
		if(strcmp(aux->id, id) == 0){
			found = 0;
			arglist_t* args = aux->function->args; 
			/*printf("Funcao encontrada: %s\n", aux->id);*/
			if(identlist == NULL && args == NULL) return found;
			else if(identlist == NULL) return 2; // numero de argumentos difere do 
			else if(args == NULL) return 2; // numero de parametros
			while(args->arglist != NULL && list->identlist != NULL) {
				tp_aux = findType(&aux, list->id, scope);
				if(tp_aux != NULL) {
					tp1 = type_tostring(tp_aux);
					tp2 = type_tostring(args->arg->type);
					/*printf("primeiro tipo: %s segundo tipo: %s\n", tp1, tp2);*/
					if(strcmp(tp1, tp2) != 0) return 3; // argumento i tipo inconsistente
				}
				

				args = args->arglist;
				list = list->identlist;
				i++;
			}

			if(args->arglist != NULL || list->identlist != NULL) {
				return 2; // numero difere
			}
			tp_aux = findType(&aux, list->id, scope);
			if(tp_aux != NULL) {
				tp1 = type_tostring(tp_aux);
				tp2 = type_tostring(args->arg->type);
				if(strcmp(tp1, tp2) != 0) return 3; // argumento i tipo inconsistente
			}

			/*printf("tudo certo com a chamada desta funcao!\n");*/
			return found;
		}
		aux = aux->next;
	}


	return found;
}

type_t* findFunctionScope (symb** first, int scope) {
	symb* aux = *first;

	while(aux->next != NULL) {
		if(aux->scope == scope && aux->function != NULL) {
			return aux->type;
		}

		aux = aux->next;
	}


	return NULL;
}

void checkReturnType(symb** first, expr_t* expr, int scope){
	/*expr_t* aux = expr;*/
	type_t* tp;

	tp = findFunctionScope(first, scope);
	if(tp != NULL)
	printType(tp, 0);



}

void checkReturn (stmtlist_t* node, type_t* type) {

}


int typeCheckAttr(symb** first, char* id, expr_t* expr, int scope){
	type_t* tp1;
	tp1 = findType(first, id, scope);
	type_t* tp2 = NULL;
	tp2 = exprHasType(first, expr, scope);
	
	if(tp1!=NULL){
		if(tp2!=NULL){
			if(strcmp(type_tostring(tp1), 
						type_tostring(tp2)) != 0)
				return 1; // tipos incompativeis
		}
		else return 2;
	}
	else return 2;



	return 0;

}

int typeCheckCond(symb** first, expr_t* expr, int scope) {
	type_t* tp;

	tp = exprHasType(first, expr, scope);
	if(isBool(tp)) return 0;

	return 1;
}

type_t* exprHasType(symb** first, expr_t* node, int scope) {
	type_t* tp;

	switch(node->activated) {
		case 0:
			tp = exprHasType(first, node->expr.attr->expr, scope);
			break;
		case 1:
			tp = opHasType(first, node->expr.operation, scope);
			break;
		case 2:
			tp = funccallHasType(first, node->expr.funccall, scope);
			break;
	}

	return tp;
}

type_t* opHasType(symb** first, operation_t* node, int scope) {
	type_t* tp;
	int i = 0;
	while(node->activated == 1) {
		i++;
		node = node->kind.operation;
	}
	switch(node->activated) {
		case 0:
			tp = opbinHasType(first, node->kind.opbin, scope);
			break;
		case 2:
			tp = termHasType(first, node->kind.term, scope);
			break;
	}

	return tp;
}

type_t* funccallHasType(symb** first, funccall_t* node, int scope) {
	type_t* tp;
	tp = findType(first, node->id, scope);

	return tp;
}

int isBool(type_t* tp) {
	char* b = malloc(5);
	strcpy(b, "bool");
	if(strcmp(b,type_tostring(tp)) != 0) return 0;
	return 1;
}

int isInt (type_t* tp) {
	char* i = malloc(4);
	strcpy(i, "int");
	/*printf("%s\n", type_tostring(tp));*/
	if(strcmp(i,type_tostring(tp)) == 0){ return 1;}
	return 0;
}

int isFloat (type_t* tp) {
	char* f = malloc(6);
	strcpy(f, "float");
	if(strcmp(f,type_tostring(tp)) != 0) return 0;
	return 1;
}

int isSet (type_t* tp) {
	char* s = malloc(4);
	strcpy(s, "set");
	if(strcmp(s,type_tostring(tp)) != 0) return 0;
	return 1;
}

int isPair (type_t* tp) {
	char* p = malloc(5);
	strcpy(p, "pair");
	if(strcmp(p,type_tostring(tp)) != 0) return 0;
	return 1;
}

type_t* opbinHasType (symb** first, opbin_t* node, int scope) {
	type_t* tp1;
	type_t* tp2;
	type_t* tbool = malloc(sizeof(type_t));
	tbool->activated = 0;
	tbool->type.b_type = malloc(5);
	strcpy(tbool->type.b_type, "bool");

	tp1 = opHasType(first, node->lhs, scope);
	switch(node->activated) {
		case 0:
			tp2 = opHasType(first, node->rhs.rop, scope);
			break;
		case 1:
			tp2 = termHasType(first, node->rhs.term, scope);
			break;
		default:
			tp2 = NULL;
	}


	if(node->op >= 0 && node->op <= 7){
		if(strcmp(type_tostring(tp1), type_tostring(tp2)) != 0) return NULL;
		return pType("bool");
	}
	else if(node->op > 7 && node->op <= 11) {
		if(isInt(tp1)) {
			if(strcmp(type_tostring(tp1), type_tostring(tp2)) != 0) return NULL;
			return tp1;
		}
		else if(isFloat(tp1)) {
			if(strcmp(type_tostring(tp1), type_tostring(tp2)) != 0) return NULL;
			return tp1;
		}
	}
	else if(node->op == 12){
		if(isSet(tp2)) {
			return tbool;
		}

	}
	else { 
		if(isSet(tp1)) {
			if(strcmp(type_tostring(tp1), type_tostring(tp2)) != 0) return NULL;
			return tp1;
		}
	}

	return tp1;
}

type_t* termHasType(symb** first, term_t* node, int scope) {
	type_t* tp;

	switch(node->activated) {
		case 0:
			tp = exprHasType(first, node->typeofterm.expr, scope);
			break;
		case 1:
			tp = opunHasType(first, node->typeofterm.opun, scope);
			break;
		case 2:
			tp = factorlistHasType(first, node->typeofterm.factorlist, scope);
			break;
		case 3:
			tp = pairHasType(first, node->typeofterm.pair, scope);
			break;
		case 4:
			tp = factorHasType(first, node->typeofterm.factor, scope);
			break;
	}

	return tp;
}

type_t* opunHasType(symb** first, opun_t* node, int scope) {
	type_t* tp;
	tp = termHasType(first, node->term, scope);
	if(node->opt < 2) {
		if(isInt(tp) || isFloat(tp)) return tp;
	}
	else if (node->opt == 2) {
		if(isSet(tp)) return tp;
	}
	else{
		if(isBool(tp)) return tp;
	}
	
	return NULL;
}

type_t* factorlistHasType(symb** first, factorlist_t* node, int scope) {
	type_t* tp;
	type_t* tp2;

	if(node->factorlist == NULL) {
		tp = factorHasType(first, node->factor, scope);
		return tp;
	}
	else {
		tp2 = factorlistHasType(first, node->factorlist, scope);
		tp = factorHasType(first, node->factor, scope);
		if(strcmp(type_tostring(tp), type_tostring(tp2)) == 0) return tp;
	}


	return NULL;
}

type_t* pairHasType(symb** first, pair_t* node, int scope) {
	type_t* tp1;
	type_t* tp2;

	tp1 = factorHasType(first, node->f1, scope);
	tp2 = factorHasType(first, node->f2, scope);

	if(strcmp(type_tostring(tp1), type_tostring(tp2)) == 0) return tp1;


	return NULL;
}

type_t* pType(char* tpc) {
	type_t* tp = malloc(sizeof(type_t));
	tp->activated = 0;
	tp->type.b_type = malloc(strlen(tpc)+1);
	strcpy(tp->type.b_type, tpc);
	return tp;
}

type_t* factorHasType(symb** first, factor_t* node, int scope) {
	type_t* tp;

	switch(node->activated) {
		case 0:
			tp = findType(first, node->fac.id, scope);
			break;
		case 1:
			tp = pType("bool");
			break;
		case 2:
			tp = pType("int");
			break;
		case 3:
			tp = pType("float");
			break;
		case 4:
			tp = pType("char");
			break;
	}

	return tp;
}


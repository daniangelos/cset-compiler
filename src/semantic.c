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

type_t* findTypeFunc(symb** first, char* id) {
	symb* aux;
	aux = *first;

	while(aux->next != NULL) {
		if(strcmp(aux->id, id) == 0){
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
	char* aux;
	char* aux2;
	size_t sz;
	if(tp_aux == NULL) {return NULL;}
	switch(tp_aux->activated){
		case 0:
			tp = malloc(sizeof(strlen(tp_aux->type.b_type)));
			strcpy(tp, tp_aux->type.b_type);
			return tp;
		case 1:
			aux = type_tostring((tp_aux->type.s_type->t));
			if(aux != NULL) {
				sz = strlen(aux) + 11;
				tp = malloc(sz);
				strcpy(tp, "set << ");
				strcat(tp, aux);
				strcat(tp, " >>");
				return tp;
			}
			return NULL;
		case 2:
			aux = type_tostring((tp_aux->type.p_type->t1));
			aux2 = type_tostring(tp_aux->type.p_type->t2);
			if(aux != NULL) {
				if(aux2 != NULL) {
					sz = strlen(aux) + strlen(aux2) + 15;
					tp = malloc(sz);
					strcpy(tp, "pair << ");
					strcat(tp, aux);
					strcat(tp, " , ");
					strcat(tp, aux2);
					strcat(tp, " >>");
					return tp;
				}
			}
			return NULL;
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
					if(tp1 != NULL && tp2 != NULL)
						if(strcmp(tp1, tp2) != 0){
							free(tp1);
							free(tp2);
						   	return 3; // argumento i tipo inconsistente
						}
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
				if(tp1 != NULL && tp2 != NULL)
					if(strcmp(tp1, tp2) != 0){
						free(tp1);
						free(tp2);
						return 3; // argumento i tipo inconsistente
					}
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
						type_tostring(tp2)) != 0){
				free(tp1);
				free(tp2);
				return 1; // tipos incompativeis
			}
		}
		else {
			free(tp1);
			return 2;
		}
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
	type_t* tp = NULL;

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
	type_t* tp = NULL;
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
	tp = findTypeFunc(first, node->id);

	return tp;
}

int isBool(type_t* tp) {
	char* b;
   	size_t sz = strlen("bool") + 1;	
	b = malloc(sz);
	strcpy(b, "bool");
	char* ts = type_tostring(tp);
	if(ts != NULL)
		if(strcmp(b,ts) != 0) {
			free(b);
			free(ts);
			return 0;
		}
	free(b);
	return 1;
}

int isInt (type_t* tp) {
	char* b;
   	size_t sz = strlen("int") + 1;	
	b = malloc(sz);
	strcpy(b, "int");
	/*printf("%s\n", type_tostring(tp));*/
	char* ts = type_tostring(tp);
	if(ts!=NULL)
		if(strcmp(b,ts) == 0){ 
			free(b);
			free(ts);
			return 1;
		}
	free(b);
	return 0;
}

int isFloat (type_t* tp) {
	char* f;
   	size_t sz = strlen("float") + 1;	
	f = malloc(sz);
	strcpy(f, "float");
	char* ts = type_tostring(tp);
	if(ts!=NULL)
		if(strcmp(f,ts) != 0) 
		{
			free(f);
			free(ts);
			return 0;
		}
	free(f);
	return 1;
}

int isSet (type_t* tp) {
	char* ts = type_tostring(tp);
	if(ts!=NULL)
		if(ts[0] == 's'){
			free(ts);
			return 1;
		}
	return 0;
}

int isPair (type_t* tp) {
	char* p;
	size_t sz = strlen("pair") + 1;
	p = malloc(sz);
	strcpy(p, "pair");
	char* ts = type_tostring(tp);
	if(ts!=NULL)
		if(strcmp(p,ts) != 0) {
			free(ts);
			free(p);
			return 0;
		}
	free(p);
	return 1;
}

type_t* opbinHasType (symb** first, opbin_t* node, int scope) {
	type_t* tp1 = NULL;
	type_t* tp2 = NULL;
	type_t* tbool = malloc(sizeof(type_t));
	tbool->activated = 0;
	size_t sz = strlen("bool") + 1;
	tbool->type.b_type = malloc(sz);
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

	/*printf("%s %s\n",type_tostring(tp1), type_tostring(tp2));*/

	if(node->op >= 0 && node->op <= 7){
		char* aux1 = type_tostring(tp1);
		char* aux2 = type_tostring(tp2);
		if(aux1 == NULL || aux2 == NULL) {return NULL;}
		else {
			if (strcmp(aux1, aux2) == 0) { 
				if(aux1!= NULL) free(aux1);
				if(aux2 != NULL) free(aux2);
				return tbool;
			}
		}
	}
	else if(node->op > 7 && node->op <= 11) {
		free(tbool->type.b_type);
		free(tbool);
		if(isInt(tp1)) {
			char* aux1 = type_tostring(tp1);
			char* aux2 = type_tostring(tp2);
			if(aux1 == NULL || aux2 == NULL) {if (strcmp(aux1, aux2) != 0) return NULL;}
			else {
				if(aux1!= NULL) free(aux1);
				if(aux2 != NULL) free(aux2);
				return tp1;
			}
		}
		else if(isFloat(tp1)) {
			char* aux1 = type_tostring(tp1);
			char* aux2 = type_tostring(tp2);
			if(aux1 == NULL || aux2 == NULL) {if (strcmp(aux1, aux2) != 0) return NULL;}
			else {
				if(aux1!= NULL) free(aux1);
				if(aux2 != NULL) free(aux2);
				return tp1;
			}
		}
		else if(node->op != 10 && isSet(tp1)){
			char* aux1 = type_tostring(tp1);
			char* aux2 = type_tostring(tp2);
			if(aux1 == NULL || aux2 == NULL) {if (strcmp(aux1, aux2) != 0) return NULL;}
			else {
				if(aux1!= NULL) free(aux1);
				if(aux2 != NULL) free(aux2);
				return tp1;
			}
		}
	}
	else if(node->op == 12){
		if(isSet(tp2)) {
			char* aux1 = type_tostring(tp1);
			char* aux2 = type_tostring(tp2->type.s_type->t);
			if(aux1 == NULL || aux2 == NULL) {if (strcmp(aux1, aux2) != 0) return NULL;}
			else{
				if(aux1!= NULL) free(aux1);
				if(aux2 != NULL) free(aux2);
				return tbool;
			}
			return NULL;
		}

	}
	else { // PRODUTO CARTESIANO 
		free(tbool->type.b_type);
		free(tbool);
		if(isSet(tp1)) {
			if(isSet(tp2)) {
				type_t* cart = malloc(sizeof(type_t));
				type_t* pair = malloc(sizeof(type_t));
				pair->activated = 2;
				pair->type.p_type = malloc(sizeof(pairtype_t));
				pair->type.p_type->t1 = tp1->type.s_type->t;
				pair->type.p_type->t2 = tp2->type.s_type->t;
				cart->activated = 1;
				cart->type.s_type = malloc(sizeof(settype_t));
				cart->type.s_type->t = pair;
				return cart;
			}
		}
	}

	return NULL;
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
	type_t* tp1;
	type_t* tp2;
	type_t* tset;
	tset = malloc(sizeof(type_t));
	tset->activated = 1;
	tset->type.s_type = malloc(sizeof(settype_t));

	if(node->factorlist == NULL) {
		tp = factorHasType(first, node->factor, scope);
		tset->type.s_type->t = tp;
		return tset;
	}
	else {
		tp2 = factorlistHasType(first, node->factorlist, scope);
		if(tp2 != NULL) {
			tp1 = tp2->type.s_type->t;
		}
		else tp1 = NULL;
		tp = factorHasType(first, node->factor, scope);
		char* aux1 = type_tostring(tp);
		char* aux2 = type_tostring(tp1);
		if(aux1 != NULL) {
			if(aux2 != NULL) {
				if(strcmp(aux1, aux2) == 0) {
					tset->type.s_type->t = tp;
					free(aux2);
					return tset;
				}
			}
			free(aux1);
		}
	}
	free(tset);


	return NULL;
}

type_t* pairHasType(symb** first, pair_t* node, int scope) {
	type_t* tp1;
	type_t* tp2;
	type_t* tp3 = malloc(sizeof(type_t));

	tp1 = factorHasType(first, node->f1, scope);
	tp2 = factorHasType(first, node->f2, scope);

	tp3->activated = 2;
	tp3->type.p_type = malloc(sizeof(pairtype_t*));
	tp3->type.p_type->t1 = tp1;
	tp3->type.p_type->t2 = tp2;

		

	return tp3;
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


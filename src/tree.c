#include "tree.h"

void printNode(char* str, int i){
	int j;
	for(j = 0; j<i; j++) printf("|\t");
	printf("%s\n", str);
}

void printSyntaxTree ( outset_t * node, int i ){


	printNode("outset", i);
	if(node->outset != NULL) {
		printSyntaxTree(node->outset, i+1);	
	}

	if(node->activated == 1)
		printFunctionTree(node->kind.function, i+1);
	else
		printDecl(node->kind.declaration, i+1);

	free(node);


	return;
}

void printFunctionTree(function_t* function, int i ) {

	printNode("function", i);
	printType(function->type, i+1);
	printNode("id", i+1);
	printNode(function->id, i+2);
	printNode("(", i+1);
	printArglist(function->arglist, i+1);
	printNode(")", i+1);
	printCompoundstmt(function->compoundstmt, i+1);

	free(function);


	return;
}

void printType ( type_t* type, int i ) {

	printNode("type", i);
	switch(type->activated) {
		case 0:
			printNode(type->type.b_type, i+1);
			break;
		case 1:
			printSetType(type->type.s_type, i+1);
			break;
		case 2:
			printPairType(type->type.p_type, i+1);
			break; 
		default:
			printNode("Type not recognized", i+1);
	}

	/*free(type);*/


	return;
}

void printSetType( settype_t* settype , int i ){
	printNode("set", i);
	printNode("<<", i);
	printType(settype->t, i);
	printNode(">>", i);

	free(settype);

	return ;
}

void printPairType ( pairtype_t* pairtype, int i ){
	printNode("pair", i);
	printNode("<<", i);
	printType(pairtype->t1, i);
	printNode(",",i);
	printType(pairtype->t2, i);
	printNode(">>",i);

	free(pairtype);

	return;
}

void printArglist (arglist_t* arglist, int i) {
	printNode("arglist", i);
	if(arglist!=NULL) {
		if ( arglist->arglist != NULL ) {
			printArglist ( arglist->arglist , i+1);
			printNode(",", i+1);
		}
		printArg(arglist->arg, i+1);
	}

	free(arglist);

	return;
}

void printArg ( arg_t* arg, int i) {
	if(arg!=NULL) {
		printNode("arg", i);
		printType(arg->type, i+1);
		printNode("id", i+1);
		printNode(arg->id, i+2);
	}
	else printf("nao\n");

	free(arg);

	return;
}

void printCompoundstmt (compoundstmt_t* cstmt, int i ) {
	printNode("compoundstmt", i);
	printNode("{", i+1);
	printStmtlist(cstmt->stmt_list, i+1);
	printNode("}", i+1);

	free(cstmt);

	return;
}

void printStmtlist ( stmtlist_t* stmtlist , int i ) {
	printNode("stmtlist", i);
	if ( stmtlist->stmtlist != NULL ) {
		printStmtlist ( stmtlist->stmtlist , i+1);
	}

	printStmt ( stmtlist->stmt, i+1 );

	free(stmtlist);

	return;
}

void printStmt ( stmt_t* stmt, int i) {
	printNode("stmt", i);

	switch(stmt->activated) {
		case 0: 
			printWhile(stmt->stmt.while_node, i+1);
			break;
		case 1:
			printExpr(stmt->stmt.expr_node, i+1);
			break;
		case 2:
			printIf(stmt->stmt.if_node, i+1);
			break;
		case 3:
			printCompoundstmt(stmt->stmt.cmp_node, i+1);
			break;
		case 4:
			printDecl(stmt->stmt.declaration_node, i+1);
			break;
		case 5:
			printIO(stmt->stmt.io_node, i+1);
			break;
		case 6:
			printReturn(stmt->stmt.return_node, i+1);
			break;
	}

	free(stmt);

	return;
}

void printWhile(while_t* while_node, int i) {
	printNode("while", i);
	printNode("(", i+1);
	printExpr(while_node->expr, i+1);
	printNode(")", i+1);

	printStmt(while_node->stmt, i+1);
	
	free(while_node);

	return ;
}

void printExpr ( expr_t* expr, int i) {
	printNode("expr", i);
	switch(expr->activated) {
		case 0:
			printAttr(expr->expr.attr, i+1);
			break;
		case 1:
			printOperation(expr->expr.operation, i+1);
			break;
		case 2:
			printFunccall(expr->expr.funccall, i+1);
			break;
	}

	free(expr);


	return;
}

void printIf (if_t* if_node, int i) {
	printNode("if", i);
	printExpr(if_node->expr, i+1);
	printCompoundstmt(if_node->cstmt, i+1);
	printElse(if_node->else_node, i+1);

	free(if_node);

	return ;

}

void printElse(else_t* else_node, int i) {
	if(else_node != NULL) {
		printNode("else", i);
		printStmt(else_node->stmt, i+1);
	}

	free(else_node);

	return;
}

void printDecl (declaration_t* decl, int i ){
	printNode("Declaration", i);
	printType(decl->type, i+1);
	switch(decl->activated) {
		case 0:
			printIdentlist(decl->decl.identlist, i+1);
			break;
		case 1:
			printAttr(decl->decl.attr, i+1);
			break;
	}

	free(decl);

	return;
}

void printIO (io_t* io_node, int i ) {
	printNode("io", i);
	printNode(io_node->kind, i+1);
	printNode("(", i+1);
	printNode(io_node->content, i+1);
	printNode(")", i+1);

	free(io_node);

	return;
}

void printReturn (return_t* ret, int i) {
	printNode("return", i);
	if(ret->expr != NULL) printExpr(ret->expr, i+1);

	free(ret);

	return;

}

void printAttr ( attr_t* attr, int i) {
	printNode("attr", i);
	printNode("id", i+1);
	printNode(attr->id, i+2);
	printNode("=", i+1);
	printExpr(attr->expr, i+1);


	free(attr);

	return;
}

void printFunccall (funccall_t* funcc, int i) {
	printNode("funccall", i);
	printNode("id", i+1);
	printNode(funcc->id, i+2);
	printIdentlist(funcc->identlist, i+1);

	free(funcc);

	return;
}

void printIdentlist (identlist_t* ident, int i) {
		printNode("identlist", i);
		printNode("id", i+1);
		printNode(ident->id, i+1);
		if(ident->identlist != NULL) {
			printNode(",", i+1);
			printIdentlist(ident->identlist, i+1);
		}
		free(ident);


	return;
}

void printOperation ( operation_t* op , int i ) {

	printNode("operation", i);
	switch(op->activated) {
		case 0:
			printOpbin(op->kind.opbin, i);
			break;
		case 1:
			printOperation (op->kind.operation, i+1);
			break;
		case 2:
			printTerm (op->kind.term, i+1);
			break;
	}

	free(op);

	return;
}

void printOpbin (opbin_t* opbin, int i) {
	static char* op[] = 
		{"COMPARE", "LT", "GT", "LE", "GE", "DIFFERENCE", "LOGICAL_OR", 
			"LOGICAL_AND", "ADD", "MINUS", "MULT", "MULT", "DIV",
			"PERT", "CART"};
		
	printNode("rvalue", i);
	printOperation(opbin->lhs, i+1);
	printNode(op[opbin->op], i+1);

	switch(opbin->activated) {
		case 0: 
			printOperation(opbin->rhs.rop, i+1);
			break;
		case 1:
			printTerm(opbin->rhs.term, i+1);
			break;
	}
	
	free(opbin);

	return;
}

void printTerm ( term_t* term, int i) {
	printNode ("term" , i);

	switch(term->activated) {
		case 0:
			printExpr(term->typeofterm.expr, i+1);
			break;
		case 1:
			printOpun(term->typeofterm.opun, i+1);
			break;
		case 2:
			printFactorlist(term->typeofterm.factorlist, i+1);
			break;
		case 3:
			printPair (term->typeofterm.pair, i+1);
			break;
		case 4:
			printFactor(term->typeofterm.factor, i+1);
			break;
	}

	free(term);

	return;
}

void printOpun ( opun_t* opun , int i) {
	static char* op[] =
	{"NEGATIVE", "POSITIVE", "CARD", "NOT"};

	printNode(op[opun->opt], i);
	printTerm(opun->term, i);

	free(opun);

	return;
}

void printFactorlist ( factorlist_t* flist , int i ) {
	if(flist != NULL) {
		printNode ("factorlist", i);
		if(flist->factorlist != NULL) {
			printNode(",", i+1);
			printFactorlist(flist->factorlist, i+1);
		}
	}

	free(flist);

	return;
}

void printFactor (factor_t* factor, int i ) {
	char * tmp;
	printNode("factor", i);

	tmp = malloc(1000);

	switch(factor->activated) {
		case 0:
			printNode("id", i+1);
			printNode(factor->fac.id, i+2);
			break;
		case 1:
			printNode("boolvalue", i+1);
			sprintf(tmp, "%d", factor->fac.b_value);
			printNode(tmp, i+2);
			break;
		case 2:
			printNode("intvalue", i+1);
			sprintf(tmp, "%d", factor->fac.i_value);
			printNode(tmp, i+2);
			break;
		case 3:
			printNode("floatvalue", i+1);
			sprintf(tmp, "%f", factor->fac.f_value);
			printNode(tmp, i+2);
			break;
		case 4:
			printNode("charvalue", i+1);
			sprintf(tmp, "%c", factor->fac.c_value);
			printNode(tmp, i+2);
			break;
	}
	free(tmp);

	free(factor);

	return;
}

void printPair(pair_t* pair, int i) {
	printNode("pair", i);

	printFactor(pair->f1, i+1);
	printNode(",", i+1);
	printFactor(pair->f2, i+1);

	free(pair);

	return ;
}

void destructTree(outset_t* node) {
	if(node->outset != NULL) {
		destructTree(node->outset);
	}

	if(node->activated == 1)
		destructFunction(node->kind.function);
	else
		destructDeclaration(node->kind.declaration);
	free(node);
	return;
}

void destructFunction(function_t* node) {
	destructType(node->type);
	free(node->id);
	destructArglist(node->arglist);
	destructCompound(node->compoundstmt);
	if(node->code != NULL) free(node->code);
	free(node);
	return;
}

void destructArglist(arglist_t* node) {
	if(node!=NULL) {
		if(node->arglist != NULL) {
			destructArglist(node->arglist);
		}
		if(node->arg != NULL){ 
			destructArg(node->arg);
		}
	}
	free(node);
	return;
}

void destructCompound(compoundstmt_t* node) {
	destructStmtlist(node->stmt_list);
	free(node);
}

void destructArg(arg_t* node) {
	if(node!= NULL) {
		destructType(node->type);
		free(node->id);
	}
	free(node);
}

void destructStmtlist(stmtlist_t* node) {
	if(node!= NULL) {
		if(node->stmtlist != NULL) {
			destructStmtlist(node->stmtlist);
		}
		destructStmt(node->stmt);
	}
	free(node);

}

void destructType(type_t* node) {
	if(node!=NULL) {
		switch(node->activated) {
			case 0:
				free(node->type.b_type);
				break;
			case 1:
				destructSetType(node->type.s_type);
				break;
			case 2:
				destructPairType(node->type.p_type);
				break;
		}
	}
	free(node);
	return;
}

void destructStmt(stmt_t* node) {
	switch(node->activated) {
		case 0:
			destructWhile(node->stmt.while_node);
			break;
		case 1:
			destructExpr(node->stmt.expr_node);
			break;
		case 2:
			destructIf(node->stmt.if_node);
			break;
		case 3:
			destructCompound(node->stmt.cmp_node);
			break;
		case 4:
			destructDeclaration(node->stmt.declaration_node);
			break;
		case 5:
			destructIO(node->stmt.io_node);
			break;
		case 6:
			destructReturn(node->stmt.return_node);
			break;
	}

	free(node);
	return;
}

void destructSetType(settype_t* node) {
	destructType(node->t);
	free(node);
	return;
}

void destructPairType(pairtype_t* node){
	destructType(node->t1);
	destructType(node->t2);
	free(node);
	return;
}

void destructWhile(while_t* node) {
	destructExpr(node->expr);
	destructStmt(node->stmt);
	/*if(node->code != NULL) free(node->code);*/
	free(node);
	return;
}

void destructIf(if_t* node){
	destructExpr(node->expr);
	destructCompound(node->cstmt);
	if(node->else_node != NULL) {
		destructStmt(node->else_node->stmt);
		free(node->else_node);
	}
	/*if(node->code != NULL) free(node->code);*/
	free(node);
	return;
}

void destructDeclaration(declaration_t* node) {
	destructType(node->type);
	if(node->activated == 0) destructIdentlist(node->decl.identlist);
	else destructAttr(node->decl.attr);
	free(node);
	return;
}

void destructIO (io_t* node) {
	free(node->kind);
	free(node->content);
	free(node);
}

void destructReturn(return_t* node) {
	destructExpr(node->expr);
	free(node);
	return;
}

void destructExpr(expr_t* node) {
	switch(node->activated){
		case 0:
			destructAttr(node->expr.attr);
			break;
		case 1:
			destructOperation(node->expr.operation);
			break;
		case 2:
			destructFunccall(node->expr.funccall);
			break;
	}
	destructType(node->type);
	/*if(node->code != NULL) free(node->code);*/
	free(node->code);
	return;
}

void destructAttr(attr_t* node) {
	free(node->id);
	destructExpr(node->expr);
	/*if(node->code != NULL) free(node->code);*/
	free(node);
	return;
}

void destructIdentlist(identlist_t* node){
	if(node!=NULL){
		free(node->id);
		if(node->identlist != NULL) destructIdentlist(node->identlist);
	}
	free(node);
	return;
}

void destructOperation(operation_t* node) {
	switch(node->activated) {
		case 0:
			destructOpbin(node->kind.opbin);
			break;
		case 1:
			destructOperation(node->kind.operation);
			break;
		case 2:
			destructTerm(node->kind.term);
			break;
	}
	/*if(node->code != NULL) free(node->code);*/
	free(node);
	return;
}

void destructOpbin(opbin_t* node) {
	destructOperation(node->lhs);
	if(node->activated == 0) destructOperation(node->rhs.rop);
	else destructTerm(node->rhs.term);
	free(node);
	return;
}

void destructTerm(term_t* node){
	switch(node->activated) {
		case 0:
			destructExpr(node->typeofterm.expr);
			break;
		case 1:
			destructOpun(node->typeofterm.opun);
			break;
		case 2:
			destructFactorlist(node->typeofterm.factorlist);
			break;
		case 3:
			destructPair(node->typeofterm.pair);
			break;
		case 4:
			destructFactor(node->typeofterm.factor);
			break;
	}
	free(node);
	return;
}

void destructOpun(opun_t* node){
	destructTerm(node->term);
	free(node);
	return;
}

void destructFactor(factor_t* node) {
	if(node->activated == 0) {
		free(node->fac.id);
	}
	free(node);
	return;
}

void destructFactorlist(factorlist_t* node) {
	if(node->factorlist != NULL) destructFactorlist(node->factorlist);
	destructFactor(node->factor);
	free(node);
}

void destructPair(pair_t* node) {
	destructFactor(node->f1);
	destructFactor(node->f2);
	free(node);
	return;
}

void destructFunccall (funccall_t* node) {
	free(node->id);
	destructIdentlist(node->identlist);
	/*if(node->code != NULL) free(node->code);*/
	free(node);
	return;
}
















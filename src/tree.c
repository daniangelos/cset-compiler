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

	printFunctionTree(node->function, i+1);

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

	free(type);


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

	switch(op->activated) {
		case 0:
			printOpbin(op->kind.opbin, i);
			break;
		case 1:
			printOperation (op->kind.operation, i);
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


















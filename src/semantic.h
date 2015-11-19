#ifndef SEMANTIC_H
#define SEMANTIC_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "table.h"
#include "tree.h"


int checkTable(symb** first, char* content, int scope, int function);
void checkForUndefinedSymbols(symb** first) ;
int findFuncDecl (symb** first, char* id, identlist_t* identlist, int scope) ;
type_t* findType(symb** first, char* id, int scope) ;
char* type_tostring(type_t* tp_aux) ;
void checkReturnType(symb** first, expr_t* expr, int scope); 
void typeCheck(outset_t* node);
void typeCheckFunction(function_t* node) ;
void typeCheckStmt(stmt_t* node) ;
int typeCheckCond(symb** first, expr_t* expr, int scope) ;
void typeCheckExpr(expr_t* node) ;
void typeCheckIf(if_t* node) ;
void typeCheckCompound(compoundstmt_t* node) ;
void typeCheckDeclaration(declaration_t* node) ;
int typeCheckAttr(symb** first, char* id, expr_t* expr, int scope);
void typeCheckOperation(operation_t* node) ;
type_t* exprHasType(symb** first, expr_t* expr, int scope) ;
type_t* opHasType(symb** first, operation_t* node, int scope) ;
type_t* funccallHasType(symb** first, funccall_t* node, int scope) ;
type_t* opbinHasType (symb** first, opbin_t* node, int scope) ;
type_t* termHasType(symb** first, term_t* node, int scope) ;
type_t* factorlistHasType(symb** first, factorlist_t* node, int scope) ;
type_t* pairHasType(symb** first, pair_t* node, int scope) ;
type_t* factorHasType(symb** first, factor_t* node, int scope) ;
type_t* opunHasType(symb** first, opun_t* node, int scope) ;
int isBool(type_t* tp) ;
type_t* pType(char* tpc) ;

#endif //SEMANTIC_H

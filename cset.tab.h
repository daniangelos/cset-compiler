/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_CSET_TAB_H_INCLUDED
# define YY_YY_CSET_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STR = 258,
    ID = 259,
    K_INT = 260,
    K_FLOAT = 261,
    K_CHAR = 262,
    K_BOOL = 263,
    K_SET = 264,
    K_PAIR = 265,
    K_WHILE = 266,
    K_IF = 267,
    K_ELSE = 268,
    K_PRINT = 269,
    K_READ = 270,
    K_RETURN = 271,
    BOOL_VALUE = 272,
    INT_VALUE = 273,
    FLOAT_VALUE = 274,
    CHAR_VALUE = 275,
    DOUBLE_BR_OP = 276,
    DOUBLE_BR_CL = 277,
    COMPARE = 278,
    DIFFERENCE = 279,
    LE = 280,
    GE = 281,
    LOGICAL_OR = 282,
    LOGICAL_AND = 283,
    PERTINENCE = 284,
    CARTESIAN = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 61 "src/cset.y" /* yacc.c:1909  */

	char* boolv;
	int intv;
	float floatv;
	char charv;
	char* str;

	struct outset_t* outset_n;
	struct function_t* function_n;
	struct type_t* type_n;
	struct arglist_t* arglist_n;
	struct compoundstmt_t* compoundstmt_n;
	struct arg_t* arg_n;
	struct stmtlist_t* stmtlist_n;
	struct stmt_t* stmt_n;
	struct if_t* if_n;
	struct else_t* else_n;
	struct while_t* while_n;
	struct io_t* io_n;
	struct return_t* return_n;
	struct declaration_t* declaration_n;
	struct factor_t* factor_n;
	struct expr_t* expr_n;
	struct opun_t* opun_n;
	struct identlist_t* identlist_n;
	struct factorlist_t* factorlist_n;
	/*struct set_t* set_n;*/
	struct pair_t* pair_n;
	struct attr_t* attr_n;
	struct operation_t* operation_n;
	struct funccall_t* funccall_n;
	struct term_t* term_n;
	int op_n;


#line 121 "cset.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CSET_TAB_H_INCLUDED  */

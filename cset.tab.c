/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "src/cset.y" /* yacc.c:339  */

#include <stdio.h>
#include "lex.yy.c" /*É necessário adicionar o arquivo do analisador lexico gerado */
#include "src/tree.h"
#include "src/table.h"
#include "src/semantic.h"
#include "src/tac.h"

#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

extern lines;
void yyerror(const char *str)
{    fprintf(stderr,"error: %s line: %d\n",str, lines);}
int boolean_to_int(char* boolv);

int synerrors = 0;
int semerrors = 0;
int label = 0;

symb** table;
int scope = 0;
char c;
functionsymb_t* f_temp;



#line 93 "cset.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cset.tab.h".  */
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
#line 61 "src/cset.y" /* yacc.c:355  */

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


#line 200 "cset.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CSET_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "cset.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    36,    46,     2,     2,    45,     2,     2,     2,
      32,    33,    43,    41,    35,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      39,    38,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   149,   156,   166,   176,   199,   202,   207,
     212,   219,   228,   239,   242,   250,   258,   266,   274,   282,
     290,   301,   308,   317,   324,   331,   338,   345,   352,   359,
     368,   393,   396,   420,   434,   442,   454,   466,   469,   478,
     488,   500,   514,   523,   532,   543,   570,   579,   589,   594,
     605,   614,   615,   616,   617,   618,   619,   622,   633,   642,
     653,   662,   673,   682,   693,   702,   713,   723,   732,   743,
     754,   763,   770,   779,   788,   797,   806,   813,   820,   829,
     838,   845,   852,   859,   868,   875,   883,   891,   900
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STR", "ID", "K_INT", "K_FLOAT",
  "K_CHAR", "K_BOOL", "K_SET", "K_PAIR", "K_WHILE", "K_IF", "K_ELSE",
  "K_PRINT", "K_READ", "K_RETURN", "BOOL_VALUE", "INT_VALUE",
  "FLOAT_VALUE", "CHAR_VALUE", "DOUBLE_BR_OP", "DOUBLE_BR_CL", "COMPARE",
  "DIFFERENCE", "LE", "GE", "LOGICAL_OR", "LOGICAL_AND", "PERTINENCE",
  "CARTESIAN", "';'", "'('", "')'", "'}'", "','", "' '", "'{'", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'$'", "'!'", "$accept",
  "program", "outset", "function", "arglist", "arglistlist", "arg",
  "compoundstmt", "type", "stmtlist", "stmt", "whilestmt", "ifstmt",
  "elsepart", "declaration", "io", "returnstmt", "expr", "attr",
  "identlist", "rvalue", "compare", "logicalor", "logicaland",
  "pertinence", "cartesian", "addition", "multiplication", "term",
  "factor", "factorlist", "pair", "funccall", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    59,    40,    41,   125,    44,    32,   123,    61,    60,
      62,    43,    45,    42,    47,    36,    33
};
# endif

#define YYPACT_NINF -113

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     128,   -15,  -113,  -113,  -113,  -113,    21,    51,    74,   171,
    -113,   105,    47,  -113,  -113,    59,    59,  -113,    65,  -113,
     116,   -21,  -113,    96,  -113,   110,   108,   113,    95,     9,
     136,  -113,    59,   111,    -3,  -113,  -113,   142,   -20,  -113,
    -113,  -113,  -113,     9,    69,    39,    39,    39,    39,  -113,
    -113,    -1,  -113,   123,     7,   133,     3,    18,  -113,  -113,
    -113,  -113,   151,  -113,   137,   213,  -113,   179,   152,   140,
     153,  -113,  -113,    14,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,    39,    39,    39,    39,    39,    39,
      39,    39,    39,  -113,   193,  -113,  -113,  -113,    42,  -113,
      69,  -113,  -113,    69,  -113,  -113,  -113,   133,     3,    18,
      18,  -113,  -113,     0,   156,   157,   158,   161,     9,   107,
    -113,   202,   150,  -113,  -113,  -113,   184,   185,   186,   195,
    -113,  -113,  -113,  -113,     9,     9,    79,   220,  -113,    58,
     189,  -113,  -113,  -113,  -113,  -113,  -113,   196,   198,   199,
     200,   203,   193,   137,  -113,  -113,  -113,  -113,   215,   193,
    -113,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,    16,    17,    18,     0,     0,     0,     0,
       5,    48,     0,    37,     7,     0,     0,     1,     0,     3,
       0,    47,    35,    36,     4,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     8,    11,     0,    79,    80,
      81,    82,    83,     0,    86,     0,     0,     0,     0,    45,
      42,    43,    50,    58,    60,    62,    64,    67,    70,    78,
      44,    46,     0,    13,     0,     0,    12,    48,     0,    78,
       0,    79,    85,     0,    73,    72,    74,    75,    51,    56,
      54,    55,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     6,    10,    47,     0,    71,
       0,    77,    76,     0,    49,    57,    59,    61,    63,    65,
      66,    68,    69,     0,     0,     0,     0,     0,     0,     0,
      26,    48,     0,    22,    23,    25,     0,     0,     0,     0,
      88,    87,    84,    31,     0,     0,     0,     0,    41,    78,
      47,    14,    21,    27,    28,    29,    24,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    30,    32,     0,
      33,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,   228,  -113,  -113,   175,   -62,     5,  -113,
    -112,  -113,  -113,  -113,   241,  -113,  -113,   -28,   -11,   176,
    -113,  -113,    10,   159,  -113,   155,   160,     8,   -39,   -40,
    -113,  -113,  -113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    34,    35,    36,   120,   121,   122,
     123,   124,   125,   160,   126,   127,   128,   129,    50,    23,
      51,    84,    52,    53,    54,    55,    56,    57,    58,    59,
      73,    70,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    49,    95,    69,    72,    11,    74,    75,    76,    77,
     142,    28,    67,    38,    20,    68,    13,    29,    29,    14,
      25,    26,    78,    79,    80,    81,    39,    40,    41,    42,
      64,    13,    65,    37,   133,    86,    87,    62,    82,    83,
     157,    43,    15,    71,    89,    90,    44,   161,   102,   103,
      45,    46,   111,   112,    47,    48,    39,    40,    41,    42,
     131,    91,    92,   132,     2,     3,     4,     5,     6,     7,
      37,    43,    16,    71,    17,   130,    44,    30,    24,   139,
      45,    46,   149,   150,    47,    48,    39,    40,    41,    42,
     138,   158,   -85,   -85,   104,   105,    33,   109,   110,    14,
       2,     3,     4,     5,     6,     7,   147,   148,   113,    21,
      22,    38,     2,     3,     4,     5,     6,     7,   114,   115,
      27,   116,   117,   118,    39,    40,    41,    42,    -9,     1,
      -9,    30,    31,     2,     3,     4,     5,     6,     7,    43,
      61,   -86,   -86,    32,   119,    28,    66,    63,    45,    46,
      85,   113,    47,    48,    38,     2,     3,     4,     5,     6,
       7,   114,   115,    88,   116,   117,   118,    39,    40,    41,
      42,    -2,    18,    93,    94,   100,     2,     3,     4,     5,
       6,     7,    43,    97,   141,    99,   101,   119,   134,   135,
     136,    45,    46,   137,   113,    47,    48,    38,     2,     3,
       4,     5,     6,     7,   114,   115,   140,   116,   117,   118,
      39,    40,    41,    42,    33,   143,   144,   145,     2,     3,
       4,     5,     6,     7,   151,    43,   146,    29,   159,   152,
     119,   153,   154,   155,    45,    46,   156,    19,    47,    48,
      96,    12,   107,    98,     0,   106,     0,     0,   108
};

static const yytype_int16 yycheck[] =
{
      11,    29,    64,    43,    44,     0,    45,    46,    47,    48,
     122,    32,    32,     4,     9,    43,    31,    38,    38,    34,
      15,    16,    23,    24,    25,    26,    17,    18,    19,    20,
      33,    31,    35,    28,    34,    28,    29,    32,    39,    40,
     152,    32,    21,     4,    41,    42,    37,   159,    34,    35,
      41,    42,    91,    92,    45,    46,    17,    18,    19,    20,
     100,    43,    44,   103,     5,     6,     7,     8,     9,    10,
      65,    32,    21,     4,     0,    33,    37,    35,    31,   119,
      41,    42,     3,     4,    45,    46,    17,    18,    19,    20,
     118,   153,    34,    35,    84,    85,     1,    89,    90,    34,
       5,     6,     7,     8,     9,    10,   134,   135,     1,     4,
     121,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       4,    14,    15,    16,    17,    18,    19,    20,    33,     1,
      35,    35,    22,     5,     6,     7,     8,     9,    10,    32,
       4,    34,    35,    35,    37,    32,     4,    36,    41,    42,
      27,     1,    45,    46,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    30,    14,    15,    16,    17,    18,    19,
      20,     0,     1,    22,    37,    35,     5,     6,     7,     8,
       9,    10,    32,     4,    34,    33,    33,    37,    32,    32,
      32,    41,    42,    32,     1,    45,    46,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     4,    14,    15,    16,
      17,    18,    19,    20,     1,    31,    31,    31,     5,     6,
       7,     8,     9,    10,     4,    32,    31,    38,    13,    33,
      37,    33,    33,    33,    41,    42,    33,     9,    45,    46,
      65,     0,    87,    67,    -1,    86,    -1,    -1,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,     6,     7,     8,     9,    10,    48,    49,
      50,    55,    61,    31,    34,    21,    21,     0,     1,    50,
      55,     4,    65,    66,    31,    55,    55,     4,    32,    38,
      35,    22,    35,     1,    51,    52,    53,    55,     4,    17,
      18,    19,    20,    32,    37,    41,    42,    45,    46,    64,
      65,    67,    69,    70,    71,    72,    73,    74,    75,    76,
      79,     4,    55,    36,    33,    35,     4,    32,    64,    76,
      78,     4,    76,    77,    75,    75,    75,    75,    23,    24,
      25,    26,    39,    40,    68,    27,    28,    29,    30,    41,
      42,    43,    44,    22,    37,    54,    53,     4,    66,    33,
      35,    33,    34,    35,    69,    69,    70,    72,    73,    74,
      74,    75,    75,     1,    11,    12,    14,    15,    16,    37,
      54,    55,    56,    57,    58,    59,    61,    62,    63,    64,
      33,    76,    76,    34,    32,    32,    32,    32,    64,    76,
       4,    34,    57,    31,    31,    31,    31,    64,    64,     3,
       4,     4,    33,    33,    33,    33,    33,    57,    54,    13,
      60,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    61,    61,    61,    62,    62,
      62,    63,    64,    64,    64,    65,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    77,    77,    77,    78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     6,     2,     1,     0,
       3,     1,     2,     2,     3,     1,     1,     1,     1,     4,
       6,     2,     1,     1,     2,     1,     1,     2,     2,     2,
       5,     2,     5,     6,     2,     2,     2,     2,     4,     4,
       4,     2,     1,     1,     1,     3,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     2,     2,     2,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 132 "src/cset.y" /* yacc.c:1646  */
    {
					outset_t* root = NEW(outset_t);
					root = (yyvsp[0].outset_n);
					checkForUndefinedSymbols(table);
					if(!synerrors && !lexerrors && !semerrors) {
						/*printf("\n ****** Syntax Tree ****** \n\n");*/
						/*printSyntaxTree(root, 0);*/
						/*typeCheck(root);*/
						printf("\n\n ****** Symbol Table ****** \n\n");
						printTable(table);
						generateCode(table, root);
						/*destructTree(root);*/
						/*destructTable(table);*/
					}
				}
#line 1438 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "src/cset.y" /* yacc.c:1646  */
    {
					outset_t* node = NEW(outset_t);
					node->outset = (yyvsp[-1].outset_n);
					node->function = (yyvsp[0].function_n);
					(yyval.outset_n) = node;
				}
#line 1449 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 157 "src/cset.y" /* yacc.c:1646  */
    {
					scope++;
					outset_t* node = NEW(outset_t);
					node->declaration = (yyvsp[-1].declaration_n);
					node->outset = NULL;
					node->function = NULL;
					(yyval.outset_n) = node;
					
				}
#line 1463 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 167 "src/cset.y" /* yacc.c:1646  */
    { 	
					outset_t* node = NEW(outset_t);
					node->function = (yyvsp[0].function_n);
					node->outset = NULL;
					node->declaration = NULL;
					(yyval.outset_n) = node;
				}
#line 1475 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 177 "src/cset.y" /* yacc.c:1646  */
    {
					scope++;
					function_t* node = NEW(function_t);
					node->type = (yyvsp[-5].type_n);
					node->id = malloc(strlen((yyvsp[-4].str)) + 1);
					strcpy(node->id, (yyvsp[-4].str));
					node->arglist = (yyvsp[-2].arglist_n);
					node->compoundstmt = (yyvsp[0].compoundstmt_n);
					node->code = malloc(strlen((yyvsp[-4].str)) + 3);
					strcpy(node->code, (yyvsp[-4].str));
					strcat(node->code, ": ");	
					printf("%s\n",node->code);
					(yyval.function_n) = node;

					f_temp = NEW(functionsymb_t);
					f_temp->type_return = (yyvsp[-5].type_n);
					f_temp->args = (yyvsp[-2].arglist_n);
					if(addSymbol(table, (yyvsp[-4].str), (yyvsp[-5].type_n), scope, f_temp)) {
						semerrors++;
						printf("Erro semantico. Redeclaracao da funcao '%s'. Linha: %d\n", (yyvsp[-4].str), lines);	
					}
				}
#line 1502 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 199 "src/cset.y" /* yacc.c:1646  */
    { synerrors++; yyerrok; }
#line 1508 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 203 "src/cset.y" /* yacc.c:1646  */
    {
					(yyval.arglist_n) = (yyvsp[0].arglist_n);
				}
#line 1516 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "src/cset.y" /* yacc.c:1646  */
    {
					(yyval.arglist_n) = NULL;
				}
#line 1524 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 213 "src/cset.y" /* yacc.c:1646  */
    {
					arglist_t* node = NEW(arglist_t);
					node->arglist = (yyvsp[-2].arglist_n);
					node->arg = (yyvsp[0].arg_n);
					(yyval.arglist_n) = node;
				}
#line 1535 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 220 "src/cset.y" /* yacc.c:1646  */
    {
					arglist_t* node = NEW(arglist_t);
					node->arglist = NULL;
					node->arg = (yyvsp[0].arg_n);
					(yyval.arglist_n) = node;
				}
#line 1546 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 229 "src/cset.y" /* yacc.c:1646  */
    {
					arg_t* node = NEW(arg_t);
					node->type = (yyvsp[-1].type_n);
					node->id = (yyvsp[0].str);
					(yyval.arg_n) =  node;
					if(addSymbol(table, (yyvsp[0].str), (yyvsp[-1].type_n), scope + 1, NULL)) {
						semerrors++;
						printf("Erro semantico. Redeclaracao do identificador '%s'. Linha: %d\n", (yyvsp[0].str), lines);	
					}
				}
#line 1561 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 239 "src/cset.y" /* yacc.c:1646  */
    { synerrors++; yyerrok; }
#line 1567 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 243 "src/cset.y" /* yacc.c:1646  */
    {
					compoundstmt_t* node = NEW(compoundstmt_t);
					node->stmt_list = (yyvsp[-1].stmtlist_n);
					(yyval.compoundstmt_n) = node;
				}
#line 1577 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 251 "src/cset.y" /* yacc.c:1646  */
    {
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(4);
					strcpy(tp->type.b_type, "int");
					(yyval.type_n) = tp;
				}
#line 1589 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 259 "src/cset.y" /* yacc.c:1646  */
    {
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(6);
					strcpy(tp->type.b_type, "float");
					(yyval.type_n) = tp;
				}
#line 1601 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 267 "src/cset.y" /* yacc.c:1646  */
    {
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(5);
					strcpy(tp->type.b_type, "char");
					(yyval.type_n) = tp;
				}
#line 1613 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 275 "src/cset.y" /* yacc.c:1646  */
    {
					type_t* tp = NEW(type_t);
					tp->activated = 0;
					tp->type.b_type = malloc(5);
					strcpy(tp->type.b_type, "bool");
					(yyval.type_n) = tp;
				}
#line 1625 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 283 "src/cset.y" /* yacc.c:1646  */
    {
					type_t* tp = NEW(type_t);
					tp->activated = 1;
					tp->type.s_type = malloc(sizeof(settype_t));
					tp->type.s_type->t = (yyvsp[-1].type_n);
					(yyval.type_n) = tp;
				}
#line 1637 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 291 "src/cset.y" /* yacc.c:1646  */
    {
					type_t* tp = malloc(sizeof(type_t));
					tp->activated = 2;
					tp->type.p_type = malloc(sizeof(pairtype_t));
					tp->type.p_type->t1 = (yyvsp[-3].type_n);
					tp->type.p_type->t2 = (yyvsp[-1].type_n);
					(yyval.type_n) = tp;
				}
#line 1650 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 302 "src/cset.y" /* yacc.c:1646  */
    {
					stmtlist_t* node = NEW(stmtlist_t);
					node->stmtlist = (yyvsp[-1].stmtlist_n);
					node->stmt = (yyvsp[0].stmt_n);
					(yyval.stmtlist_n) = node;
				}
#line 1661 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 309 "src/cset.y" /* yacc.c:1646  */
    {
					stmtlist_t* node = NEW(stmtlist_t);
					node->stmtlist = NULL;
					node->stmt = (yyvsp[0].stmt_n);
					(yyval.stmtlist_n) = node;
				}
#line 1672 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 318 "src/cset.y" /* yacc.c:1646  */
    {
					stmt_t* node = NEW(stmt_t);
					node->activated = 0;
					node->stmt.while_node = (yyvsp[0].while_n);
					(yyval.stmt_n) = node;
				}
#line 1683 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 325 "src/cset.y" /* yacc.c:1646  */
    {
					stmt_t* node = NEW(stmt_t);
					node->activated = 1;
					node->stmt.expr_node = (yyvsp[-1].expr_n);
					(yyval.stmt_n) = node;
				}
#line 1694 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 332 "src/cset.y" /* yacc.c:1646  */
    {
					stmt_t* node = NEW(stmt_t);
					node->activated = 2;
					node->stmt.if_node = (yyvsp[0].if_n);
					(yyval.stmt_n) = node;
				}
#line 1705 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 339 "src/cset.y" /* yacc.c:1646  */
    {
					stmt_t* node = NEW(stmt_t);
					node->activated = 3;
					node->stmt.cmp_node = (yyvsp[0].compoundstmt_n);
					(yyval.stmt_n) = node;
				}
#line 1716 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 346 "src/cset.y" /* yacc.c:1646  */
    {
					stmt_t* node = NEW(stmt_t);
					node->activated = 4;
					node->stmt.declaration_node = (yyvsp[-1].declaration_n);
					(yyval.stmt_n) = node;
				}
#line 1727 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 353 "src/cset.y" /* yacc.c:1646  */
    {
					stmt_t* node = NEW(stmt_t);
					node->activated = 5;
					node->stmt.io_node = (yyvsp[-1].io_n);
					(yyval.stmt_n) = node;
				}
#line 1738 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 360 "src/cset.y" /* yacc.c:1646  */
    {
					stmt_t* node = NEW(stmt_t);
					node->activated = 6;
					node->stmt.return_node = (yyvsp[-1].return_n);
					(yyval.stmt_n) = node;
				}
#line 1749 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 369 "src/cset.y" /* yacc.c:1646  */
    {
					while_t* node = NEW(while_t);
					node->expr = (yyvsp[-2].expr_n);
					node->stmt = (yyvsp[0].stmt_n);
					node->code = malloc(50);
					label++;
					char* str1 = malloc(strlen("label: if !expr goto whilenext\n") + 5);
					sprintf(str1, "label%d: if !expr goto whilenext%d\n", label, label);
					strcpy(node->code, str1);
					strcat(node->code, "stmt code\n");
					char* str2 = malloc(strlen("goto labelx"));
					sprintf(str2,"goto label%d\n", label);
					strcat(node->code, str2);
					sprintf(str2, "whilenext%d:",label);
					strcat(node->code, str2);
					free(str1);
					free(str2);
					printf("%s\n", node->code);
					(yyval.while_n) = node;
					if(typeCheckCond(table, (yyvsp[-2].expr_n), scope)){
						semerrors++;
						printf("Erro semantivo linha %d. Condicao em while deve ter tipo bool.\n", lines);
					}
				}
#line 1778 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 393 "src/cset.y" /* yacc.c:1646  */
    { synerrors++; yyerrok; }
#line 1784 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 397 "src/cset.y" /* yacc.c:1646  */
    {
					if_t* node = NEW(if_t);
					node->expr = (yyvsp[-2].expr_n);
					node->cstmt = (yyvsp[0].compoundstmt_n);
					node->else_node = NULL;
					label++;
					node->code = malloc(50);
					char* str1 = malloc(strlen("if !expr goto ifnext\n") + 10);
					sprintf(str1, "if !expr goto ifnext%d\n", label);
					strcpy(node->code, str1);
					strcat(node->code, "cmpstmt code\n");
					char* str2 = malloc(strlen("goto labelx"));
					sprintf(str2, "ifnext%d:",label);
					strcat(node->code, str2);
					free(str1);
					free(str2);
					printf("%s\n", node->code);
					(yyval.if_n) = node;
					if(typeCheckCond(table, (yyvsp[-2].expr_n), scope)){
						semerrors++;
						printf("Erro semantivo linha %d. Condicao em if deve ter tipo bool.\n", lines);
					}
				}
#line 1812 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 421 "src/cset.y" /* yacc.c:1646  */
    {
					if_t* node = NEW(if_t);
					node->expr = (yyvsp[-3].expr_n);
					node->cstmt = (yyvsp[-1].compoundstmt_n);
					node->else_node = (yyvsp[0].else_n);
					(yyval.if_n) = node;
					if(typeCheckCond(table, (yyvsp[-3].expr_n), scope)){
						semerrors++;
						printf("Erro semantivo linha %d. Condicao em if deve ter tipo bool.\n", lines);
					}
				}
#line 1828 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 435 "src/cset.y" /* yacc.c:1646  */
    {
					else_t* node = NEW(else_t);
					node->stmt = (yyvsp[0].stmt_n);
					(yyval.else_n) = node;
				}
#line 1838 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 443 "src/cset.y" /* yacc.c:1646  */
    {
					declaration_t* node = NEW(declaration_t);
					int activated = 1;
					node->type = (yyvsp[-1].type_n);
					node->decl.attr = (yyvsp[0].attr_n);
					(yyval.declaration_n) = node;
					if(addSymbol(table, node->decl.attr->id, (yyvsp[-1].type_n), scope + 1, NULL)){
						semerrors++;
						printf("Erro semantico. Redeclaracao do identificador '%s'. Linha: %d\n", node->decl.attr->id, lines);	
					}
				}
#line 1854 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 455 "src/cset.y" /* yacc.c:1646  */
    {
					declaration_t* node = NEW(declaration_t);
					int activated = 0;
					node->type = (yyvsp[-1].type_n);
					node->decl.identlist = (yyvsp[0].identlist_n);
					if(addSymbol(table, node->decl.identlist->id, (yyvsp[-1].type_n), scope + 1, NULL)){
						semerrors++;
						printf("Erro semantico. Redeclaracao do identificador '%s'. Linha: %d\n", node->decl.identlist->id, lines);	
					}
					(yyval.declaration_n) = node;
				}
#line 1870 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 466 "src/cset.y" /* yacc.c:1646  */
    { synerrors++; yyerrok; }
#line 1876 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 470 "src/cset.y" /* yacc.c:1646  */
    {
					io_t* node = NEW(io_t);
					node->kind = malloc(6);
					strcpy(node->kind, "print");
					node->content = malloc(strlen((yyvsp[-1].str))+1);
					strcpy(node->content, (yyvsp[-1].str));
					(yyval.io_n) = node;
				}
#line 1889 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 479 "src/cset.y" /* yacc.c:1646  */
    {
					io_t* node = NEW(io_t);
					node->kind = malloc(6);
					strcpy(node->kind, "print");
					node->content = malloc(strlen((yyvsp[-1].str))+1);
					strcpy(node->content, (yyvsp[-1].str));
					(yyval.io_n) = node;
					addSymbol(table, (yyvsp[-1].str), NULL, scope + 1, NULL);	
				}
#line 1903 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 489 "src/cset.y" /* yacc.c:1646  */
    {
					io_t* node = NEW(io_t);
					node->kind = malloc(5);
					strcpy(node->kind, "read");
					node->content = malloc(strlen((yyvsp[-1].str))+1);
					strcpy(node->content, (yyvsp[-1].str));
					(yyval.io_n) = node;
					addSymbol(table, (yyvsp[-1].str), NULL, scope + 1, NULL);	
				}
#line 1917 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 501 "src/cset.y" /* yacc.c:1646  */
    {
					return_t* node = NEW(return_t);
					node->expr = (yyvsp[0].expr_n);
					(yyval.return_n) = node;
				}
#line 1927 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 515 "src/cset.y" /* yacc.c:1646  */
    {
					expr_t* node = NEW(expr_t);
					node->activated = 0;
					node->expr.attr = (yyvsp[0].attr_n);
					node->type = NULL;
					/*node->code = $1->code;*/
					(yyval.expr_n) = node;
				}
#line 1940 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 524 "src/cset.y" /* yacc.c:1646  */
    {
					expr_t* node = NEW(expr_t);
					node->activated = 1;
					node->expr.operation = (yyvsp[0].operation_n);
					node->type = NULL;
					/*node->code = malloc(strlen($1->code)+1);*/
					(yyval.expr_n) = node;
				}
#line 1953 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 533 "src/cset.y" /* yacc.c:1646  */
    {
					expr_t* node = NEW(expr_t);
					node->activated = 2;
					node->expr.funccall = (yyvsp[0].funccall_n);
					node->type = NULL;
					node->code = (yyvsp[0].funccall_n)->code;
					(yyval.expr_n) = node;
				}
#line 1966 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 544 "src/cset.y" /* yacc.c:1646  */
    {
					attr_t* node = NEW(attr_t);
					node->id = malloc(strlen((yyvsp[-2].str)));
					strcpy(node->id, (yyvsp[-2].str));
					node->expr = (yyvsp[0].expr_n);
					/*node->code = malloc(strlen($3->code)+strlen($1)+6);*/
					(yyval.attr_n) = node;
					addSymbol(table, (yyvsp[-2].str), NULL, scope + 1, NULL);	
					switch(typeCheckAttr(table, (yyvsp[-2].str), (yyvsp[0].expr_n), scope + 1)){
					case 1:
						semerrors++;
						printf("Erro semantico linha %d. Tipos incompativeis na atribuicao.\n",lines);
						break;
					case 2:
						semerrors++;
						printf("Erro semantico linha %d. O tipo do lado esquerdo da atribuicao nao pode ser avaliado.\n",lines);
						break;
					case 3:
						semerrors++;
						printf("Erro semantico linha %d. O tipo do lado direito da atribuicao nao pode ser avaliado.\n",lines);
						break;
					}
	
				}
#line 1995 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 571 "src/cset.y" /* yacc.c:1646  */
    {
					identlist_t* node = NEW(identlist_t);
					node->id = malloc(strlen((yyvsp[0].str)));
					strcpy(node->id, (yyvsp[0].str));
					node->identlist = (yyvsp[-2].identlist_n);
					(yyval.identlist_n) = node;
					addSymbol(table, (yyvsp[0].str), NULL, scope + 1, NULL);	
				}
#line 2008 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 580 "src/cset.y" /* yacc.c:1646  */
    {
					identlist_t* node = NEW(identlist_t);
					node->id = malloc(strlen((yyvsp[0].str)));
					strcpy(node->id, (yyvsp[0].str));
					node->identlist = NULL;
					(yyval.identlist_n) = node;
					addSymbol(table, (yyvsp[0].str), NULL, scope + 1, NULL);	
				}
#line 2021 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 589 "src/cset.y" /* yacc.c:1646  */
    {
					(yyval.identlist_n) = NULL;
				}
#line 2029 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 595 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = malloc(sizeof(opbin_t));
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = (yyvsp[0].operation_n);
					node->kind.opbin->op = (yyvsp[-1].op_n);
					(yyval.operation_n) = node;
				}
#line 2044 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 606 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = (yyvsp[0].operation_n);
					(yyval.operation_n) = node;
				}
#line 2055 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 614 "src/cset.y" /* yacc.c:1646  */
    { (yyval.op_n) = COMPARE_bin; }
#line 2061 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 615 "src/cset.y" /* yacc.c:1646  */
    { (yyval.op_n) = LT_bin;}
#line 2067 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 616 "src/cset.y" /* yacc.c:1646  */
    { (yyval.op_n) = GT_bin;}
#line 2073 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 617 "src/cset.y" /* yacc.c:1646  */
    { (yyval.op_n) = LE_bin;}
#line 2079 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 618 "src/cset.y" /* yacc.c:1646  */
    { (yyval.op_n) = GE_bin;}
#line 2085 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 619 "src/cset.y" /* yacc.c:1646  */
    { (yyval.op_n) = DIFFERENCE_bin;}
#line 2091 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 623 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = (yyvsp[0].operation_n);
					node->kind.opbin->op = LOGICALOR_bin;
					(yyval.operation_n) = node;
				}
#line 2106 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 634 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = (yyvsp[0].operation_n);
					(yyval.operation_n) = node;
				}
#line 2117 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 643 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = (yyvsp[0].operation_n);
					node->kind.opbin->op = LOGICALAND_bin;
					(yyval.operation_n) = node;
				}
#line 2132 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 654 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = (yyvsp[0].operation_n);
					(yyval.operation_n) = node;
				}
#line 2143 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 663 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = (yyvsp[0].operation_n);
					node->kind.opbin->op = PERT_bin;
					(yyval.operation_n) = node;
				}
#line 2158 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 674 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = (yyvsp[0].operation_n);
					(yyval.operation_n) = node;
				}
#line 2169 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 683 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = (yyvsp[0].operation_n);
					node->kind.opbin->op = CART_bin;
					(yyval.operation_n) = node;
				}
#line 2184 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 694 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = (yyvsp[0].operation_n);
					(yyval.operation_n) = node;
				}
#line 2195 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 703 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = (yyvsp[0].operation_n);
					node->kind.opbin->op = ADD_bin;
					(yyval.operation_n) = node;
				}
#line 2210 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 714 "src/cset.y" /* yacc.c:1646  */
    { operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 0;
					node->kind.opbin->rhs.rop = (yyvsp[0].operation_n);
					node->kind.opbin->op = MINUS_bin;
					(yyval.operation_n) = node;
				}
#line 2224 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 724 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 1;
					node->kind.operation = (yyvsp[0].operation_n);
					(yyval.operation_n) = node;
				}
#line 2235 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 733 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 1;
					node->kind.opbin->rhs.term = (yyvsp[0].term_n);
					node->kind.opbin->op = MULT_bin;
					(yyval.operation_n) = node;
				}
#line 2250 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 744 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 0;
					node->kind.opbin = NEW(opbin_t);
					node->kind.opbin->lhs = (yyvsp[-2].operation_n);
					node->kind.opbin->activated = 1;
					node->kind.opbin->rhs.term = (yyvsp[0].term_n);
					node->kind.opbin->op = DIV_bin;
					(yyval.operation_n) = node;
				}
#line 2265 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 755 "src/cset.y" /* yacc.c:1646  */
    {
					operation_t* node = NEW(operation_t);
					node->activated = 2;
					node->kind.term = (yyvsp[0].term_n);
					(yyval.operation_n) = node;
				}
#line 2276 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 764 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 0;
					node->typeofterm.expr = (yyvsp[-1].expr_n);
					(yyval.term_n) = node;
				}
#line 2287 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 771 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = MINUS_un;
					node->typeofterm.opun->term = (yyvsp[0].term_n);
					(yyval.term_n) = node;
				}
#line 2300 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 780 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = ADD_un;
					node->typeofterm.opun->term = (yyvsp[0].term_n);
					(yyval.term_n) = node;
				}
#line 2313 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 789 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = CARD_un;
					node->typeofterm.opun->term = (yyvsp[0].term_n);
					(yyval.term_n) = node;
				}
#line 2326 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 798 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 1;
					node->typeofterm.opun = NEW(opun_t);
					node->typeofterm.opun->opt = NOT_un;
					node->typeofterm.opun->term = (yyvsp[0].term_n);
					(yyval.term_n) = node;
				}
#line 2339 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 807 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 2;
					node->typeofterm.factorlist = (yyvsp[-1].factorlist_n);
					(yyval.term_n) = node;
				}
#line 2350 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 814 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 3;
					node->typeofterm.pair = (yyvsp[-1].pair_n);
					(yyval.term_n) = node;
				}
#line 2361 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 821 "src/cset.y" /* yacc.c:1646  */
    {
					term_t* node = NEW(term_t);
					node->activated = 4;
					node->typeofterm.factor = (yyvsp[0].factor_n);
					(yyval.term_n) = node;
				}
#line 2372 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 830 "src/cset.y" /* yacc.c:1646  */
    {
					factor_t* node = NEW(factor_t);
					node->activated = 0;
					node->fac.id = malloc(strlen((yyvsp[0].str)) + 1);
					strcpy(node->fac.id, (yyvsp[0].str));
					(yyval.factor_n) = node;
					addSymbol(table, (yyvsp[0].str), NULL, scope + 1, NULL);	
				}
#line 2385 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 839 "src/cset.y" /* yacc.c:1646  */
    {
					factor_t* node = NEW(factor_t);
					node->activated = 1;
					node->fac.b_value = boolean_to_int((yyvsp[0].boolv));
					(yyval.factor_n) = node;
				}
#line 2396 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 846 "src/cset.y" /* yacc.c:1646  */
    {
					factor_t* node = NEW(factor_t);
					node->activated = 2;
					node->fac.i_value = (yyvsp[0].intv);
					(yyval.factor_n) = node;
				}
#line 2407 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 853 "src/cset.y" /* yacc.c:1646  */
    {
					factor_t* node = NEW(factor_t);
					node->activated = 3;
					node->fac.f_value = (yyvsp[0].floatv);
					(yyval.factor_n) = node;
				}
#line 2418 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 860 "src/cset.y" /* yacc.c:1646  */
    {
					factor_t* node = NEW(factor_t);
					node->activated = 4;
					node->fac.c_value = (yyvsp[0].charv);
					(yyval.factor_n) = node;
				}
#line 2429 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 869 "src/cset.y" /* yacc.c:1646  */
    {
					factorlist_t* node = NEW(factorlist_t);
					node->factorlist = (yyvsp[-2].factorlist_n);	
					node->factor = (yyvsp[0].factor_n);
					(yyval.factorlist_n) = node;
				}
#line 2440 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 876 "src/cset.y" /* yacc.c:1646  */
    {
					factorlist_t* node = NEW(factorlist_t);
					node->factorlist = NULL;
					node->factor = (yyvsp[0].factor_n);
					(yyval.factorlist_n) = node;
				}
#line 2451 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 883 "src/cset.y" /* yacc.c:1646  */
    {
					factorlist_t* node = NEW(factorlist_t);
					node->factorlist = NULL;
					node->factor = NULL;
					(yyval.factorlist_n) = node;
				}
#line 2462 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 892 "src/cset.y" /* yacc.c:1646  */
    {
					pair_t* node = NEW(pair_t);
					node->f1 = (yyvsp[-2].factor_n);
					node->f2 = (yyvsp[0].factor_n);
					(yyval.pair_n) = node;
				}
#line 2473 "cset.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 901 "src/cset.y" /* yacc.c:1646  */
    {
					funccall_t* node = NEW(funccall_t);
					node->id = malloc(strlen((yyvsp[-3].str)) + 1);
					strcpy(node->id, (yyvsp[-3].str));
					node->identlist = (yyvsp[-1].identlist_n);
					int numparam;
					if((yyvsp[-1].identlist_n) == NULL) {
						node->code = malloc(strlen((yyvsp[-3].str)) + 10);
						numparam = 0;
					}
					else {
						char* aux = stackId((yyvsp[-1].identlist_n), &numparam);
						node->code = malloc(strlen(aux) + strlen((yyvsp[-3].str)) + 10);
						strcpy(node->code, aux);
						free(aux);
					}
					strcat(node->code, "call ");
					strcat(node->code, (yyvsp[-3].str));
					strcat(node->code, ", ");
					char str[3];
					sprintf(str, "%d", numparam);
					strcat(node->code, str);
					/*printf("%s\n", node->code);*/
					(yyval.funccall_n) = node;
					switch(findFuncDecl(table, (yyvsp[-3].str), (yyvsp[-1].identlist_n), scope+1)) {
					case 1:
						printf("Erro semantico, linha %d. Chamada a funcao nao definida!\n", lines);							
						semerrors++;
						break;
					case 2:
						printf("Erro semantico, linha %d. Numero de argumentos invalido!\n", lines);							
						semerrors++;
						break;
					case 3:
						printf("Erro semantico, linha %d. Tipo de argumento nao esperado.\n", lines);
						semerrors++;
						break;
					}
						

				}
#line 2519 "cset.tab.c" /* yacc.c:1646  */
    break;


#line 2523 "cset.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 945 "src/cset.y" /* yacc.c:1906  */


int main(int argc, char** argv)
{
	if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }
	table = malloc(sizeof(symb));
	yyparse();

	return 0;
}

int boolean_to_int(char* boolv) {
	if(strcmp(boolv, "false")) return 1;
	return 0;
}

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
#line 1 "TESTsymbol.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "symb.h"
#define YYDEBUG 1
#define YYPRINT(file, type, value) yyprint (file, type, value)
#define MAX_STRING 1028 //the max length of a string
#define YY_BUF_SIZE 32768 //Buffer size for yy buffers 

/*Variable declarations******************************/
extern char *yytext;
extern FILE *yyin;
symrec *sym_table; //The symbol table is stored in symb.h
symrec *param_sym_table; //Second symbol table for function parameters only
typedef struct yy_buffer_state * YY_BUFFER_STATE; //input buffers
char *buff; //A buffer for string addition and mallocs
static int sym_scope[128]; //This keeps tracks of the # of symbols within each scope
static int scope_lvl = 0; //The current scope level, 0 is base
static int no_exec_flag = 0; //0 means execute normally, 1 means skip within ifstatement
static char TMP_BUFF[MAX_STRING];
static int f_flag = 0; //A flag telling the program to look for function symbols first
static char *f_name; //The global name of the current function

/*Function prototypes********************************/
void yyerror(const char *);
static void init_table();
static void yyprint(FILE *file, int type, struct symrec value);
static int free_sym_table(int scope);
static int free_sym_table_param();
static char *make_sym_name(char *func, char *param);

#line 100 "TESTsymbol.tab.c" /* yacc.c:339  */

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
   by #include "TESTsymbol.tab.h".  */
#ifndef YY_YY_TESTSYMBOL_TAB_H_INCLUDED
# define YY_YY_TESTSYMBOL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SCRIBE = 258,
    EXIT_COMMAND = 259,
    CAST = 260,
    SMITE = 261,
    EQ_OP = 262,
    NE_OP = 263,
    LE_OP = 264,
    GE_OP = 265,
    INTEGER = 266,
    REAL = 267,
    STRING = 268,
    ERA = 269,
    IDENTIFIER = 270,
    INQUIRE = 271,
    ALTERNATE = 272,
    RESEARCH = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef struct symrec YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TESTSYMBOL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "TESTsymbol.tab.c" /* yacc.c:358  */

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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    25,     2,     2,
      29,    30,    21,    19,    31,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    24,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    23,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    53,    54,    55,    56,    63,    78,
      97,   119,   131,   132,   136,   137,   163,   190,   220,   221,
     277,   307,   308,   337,   366,   395,   431,   432,   461,   496,
     497,   520,   521,   530,   533,   534,   538,   542,   548,   551,
     556,   619,   693,   754,   776,   802,   803,   807,   808,   811,
     812,   813,   814,   818,   874,   888,   922,   964,   984,   985
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCRIBE", "EXIT_COMMAND", "CAST",
  "SMITE", "EQ_OP", "NE_OP", "LE_OP", "GE_OP", "INTEGER", "REAL", "STRING",
  "ERA", "IDENTIFIER", "INQUIRE", "ALTERNATE", "RESEARCH", "'+'", "'-'",
  "'*'", "'/'", "'^'", "'='", "'%'", "'>'", "'<'", "'\\n'", "'('", "')'",
  "','", "$accept", "line", "constant", "string", "primary_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "assignment_expression",
  "expression", "expression_statement", "selection_statement", "ifs",
  "true", "false", "loop_statement", "loop_block", "compound_statement",
  "block_item_list", "statement", "function_call", "function_declaration",
  "func_head", "func_body", "parameter", "param_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    43,
      45,    42,    47,    94,    61,    37,    62,    60,    10,    40,
      41,    44
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      38,    80,   -48,    56,   -48,   -48,   -48,   -17,    16,   -13,
      14,   -48,    10,   -48,   -48,   -48,    82,    11,     8,    12,
     -48,    37,   -48,   -48,    22,   -48,   -48,   -48,   -48,   -48,
      39,    31,   -48,   -48,    74,   -48,    80,    80,    85,    80,
      46,   -48,   -48,   -48,   -48,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,   -48,   -48,    59,   -48,
     -48,   -48,   -48,    51,   -48,   -48,   -48,   -48,    27,    52,
      85,   -48,   -48,   -48,    82,    82,    11,    11,    11,    11,
       8,     8,    78,   -48,    89,   -48,    85,    71,    33,   -48,
     -48,   -48,   -48,   -48,    73,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    33,     0,     8,     9,    10,     0,    11,     0,
       0,    34,     0,    12,    13,    14,    18,    21,    26,    29,
      31,     0,    49,    50,    41,    51,    52,     2,     6,     4,
       0,    11,    32,    45,     0,    47,     0,     0,     0,     0,
       0,     1,     3,     7,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    40,    37,    56,
      54,    46,    48,     0,    30,    11,    57,    58,     0,     0,
       0,    15,    16,    17,    19,    20,    24,    25,    22,    23,
      27,    28,     0,    36,     0,    53,     0,    39,     0,    42,
      44,    43,    59,    38,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -38,    -2,   -47,    19,   -48,     0,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
      -1,    93,    94,   -48,   -48,    23,    40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    58,    83,    25,    91,    26,    34,
      27,    28,    29,    30,    60,    67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    32,    35,    76,    77,    78,    79,    71,    72,    73,
      41,    42,    36,     1,     2,     3,    39,    50,    51,    54,
      55,     4,     5,     6,     7,     8,     9,    57,    10,    40,
      48,    49,    66,    62,    52,    53,    63,    64,    11,    69,
      37,     1,     2,     3,    59,    38,    74,    75,    66,     4,
       5,     6,     7,     8,     9,    37,    10,    85,    86,     1,
       2,     3,    33,    94,    86,    56,    11,     4,     5,     6,
       7,    31,     9,    80,    81,    70,    82,     1,     2,     3,
      61,    84,    87,    89,    11,     4,     5,     6,     7,    31,
       9,     4,     5,     6,    90,    31,     4,     5,     6,    93,
      65,    95,    11,    45,    46,    43,    44,    47,     0,    92,
      88
};

static const yytype_int8 yycheck[] =
{
      38,     1,     3,    50,    51,    52,    53,    45,    46,    47,
       0,    12,    29,     3,     4,     5,    29,     9,    10,     7,
       8,    11,    12,    13,    14,    15,    16,     5,    18,    15,
      19,    20,    70,    34,    26,    27,    36,    37,    28,    39,
      24,     3,     4,     5,     5,    29,    48,    49,    86,    11,
      12,    13,    14,    15,    16,    24,    18,    30,    31,     3,
       4,     5,     6,    30,    31,    28,    28,    11,    12,    13,
      14,    15,    16,    54,    55,    29,    17,     3,     4,     5,
       6,    30,    30,     5,    28,    11,    12,    13,    14,    15,
      16,    11,    12,    13,     5,    15,    11,    12,    13,    28,
      15,    28,    28,    21,    22,    12,    12,    25,    -1,    86,
      70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    11,    12,    13,    14,    15,    16,
      18,    28,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    48,    50,    52,    53,    54,
      55,    15,    41,     6,    51,    52,    29,    24,    29,    29,
      15,     0,    52,    53,    54,    21,    22,    25,    19,    20,
       9,    10,    26,    27,     7,     8,    28,     5,    46,     5,
      56,     6,    52,    41,    41,    15,    36,    57,    58,    41,
      29,    36,    36,    36,    37,    37,    38,    38,    38,    38,
      39,    39,    17,    47,    30,    30,    31,    30,    58,     5,
       5,    49,    57,    28,    30,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    33,    33,    33,    33,    34,    34,
      35,    36,    36,    36,    37,    37,    37,    37,    38,    38,
      38,    39,    39,    39,    39,    39,    40,    40,    40,    41,
      41,    42,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    47,    48,    49,    50,    50,    51,    51,    52,
      52,    52,    52,    53,    54,    55,    56,    57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     2,     1,     1,     2,     3,     2,     5,     4,
       1,     0,     2,     5,     1,     2,     3,     1,     2,     1,
       1,     1,     1,     4,     2,     6,     1,     1,     1,     3
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
      YY_LAC_DISCARD ("YYBACKUP");                              \
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


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
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
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
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
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

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
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

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 51 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 1550 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 1556 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 1562 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 1568 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 55 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 1574 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 56 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 1580 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "TESTsymbol.y" /* yacc.c:1646  */
    {
             symrec* tmp;
             if ( (tmp = getsym((yyvsp[0]).name)) == 0){
               //Symbol does not exist in table yet
               putsym((yyvsp[0]).name, 0, 0);
               upsym((yyvsp[0]).name, (void *)&(yyvsp[0]).value.intval, NULL);
               tmp = getsym((yyvsp[0]).name);
               (yyval).name = tmp->name; (yyval).type = tmp->type;
               (yyval).qual = tmp->qual; (yyval).value = tmp->value;
               free((yyvsp[0]).name); //free alloc'd string
             }else{
               (yyval).name = tmp->name; (yyval).type = tmp->type;
               (yyval).qual = tmp->qual; (yyval).value = tmp->value;
               free((yyvsp[0]).name);
             } }
#line 1600 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "TESTsymbol.y" /* yacc.c:1646  */
    {
             symrec* tmp;
             if ( (tmp = getsym((yyvsp[0]).name)) == 0){
               //Symbol does not exist in table yet
               putsym((yyvsp[0]).name, 1, 0);
               upsym((yyvsp[0]).name, (void *)&(yyvsp[0]).value.doubleval, NULL);
               tmp = getsym((yyvsp[0]).name);
               (yyval).name = tmp->name; (yyval).type = tmp->type;
               (yyval).qual = tmp->qual; (yyval).value = tmp->value;
               free((yyvsp[0]).name); //free alloc'd string
             }else{
               (yyval).name = tmp->name; (yyval).type = tmp->type;
               (yyval).qual = tmp->qual; (yyval).value = tmp->value;
               free((yyvsp[0]).name); //yylval still has malloc
             } }
#line 1620 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 97 "TESTsymbol.y" /* yacc.c:1646  */
    {symrec* tmp;
             if ( (tmp = getsym((yyvsp[0]).name)) == 0){
               //Symbol does not exist in table yet
               putsym((yyvsp[0]).name, 2, 0);
               upsym((yyvsp[0]).name, (void *)(yyvsp[0]).value.strval, NULL);
               tmp = getsym((yyvsp[0]).name);
               (yyval).name = tmp->name; (yyval).type = tmp->type;
               (yyval).qual = tmp->qual; (yyval).value = tmp->value;
               free((yyvsp[0]).name); //free alloc'd string
             }else{
               //Symbol does, in fact, exist
               (yyval).name = tmp->name; (yyval).type = tmp->type;
               (yyval).qual = tmp->qual; (yyval).value = tmp->value;
               free((yyvsp[0]).name); //Still need to free yylval
             } }
#line 1640 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "TESTsymbol.y" /* yacc.c:1646  */
    {symrec* tmp;
            if( (tmp = getsym((yyvsp[0]).name)) == 0){
              //Symbol not yet in the table
              buff = malloc(strlen((yyvsp[0]).name) + 1);
              strcpy(buff, (yyvsp[0]).name);
              (yyval).name = buff; // Pass var name up
              free((yyvsp[0]).name); //Free yylval
            }else{
             (yyval).type = tmp->type; (yyval).qual = tmp->qual;
             (yyval).value = tmp->value;
             free((yyvsp[0]).name);
             } }
#line 1657 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 131 "TESTsymbol.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1663 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 132 "TESTsymbol.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1669 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval * (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 1; (yyval).value.doubleval = 
        (yyvsp[-2]).value.intval * (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval * (yyvsp[0]).value.intval;
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        (yyvsp[-2]).value.intval * (yyvsp[0]).value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot multiply using strings\n");
         YYERROR;
       }
      }
#line 1699 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 164 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval / (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 1; (yyval).value.doubleval = 
        (yyvsp[-2]).value.intval / (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval / (yyvsp[0]).value.intval;
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        (yyvsp[-2]).value.intval / (yyvsp[0]).value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot subract using strings\n");
         YYERROR;
       }
    
    }
#line 1730 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 191 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        	printf("Cannot modulus floats\n");
        	YYERROR;
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        	printf("Cannot modulus floats\n");
        	YYERROR;
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        	printf("Cannot modulus floats\n");
        	YYERROR;
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        (yyvsp[-2]).value.intval % (yyvsp[0]).value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot modulus using strings\n");
         YYERROR;
       }
    
    }
#line 1761 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval + (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 1; (yyval).value.doubleval = 
        (yyvsp[-2]).value.intval + (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval + (yyvsp[0]).value.intval;
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        (yyvsp[-2]).value.intval + (yyvsp[0]).value.intval;
        }
       //At least one arg is a string
       }else if((yyvsp[-2]).type == 2 && (yyvsp[0]).type == 2){
         //strings
         buff = malloc(strlen((yyvsp[-2]).value.strval) + strlen((yyvsp[0]).value.strval)+ 1);
         strcat(buff,(yyvsp[-2]).value.strval); strcat(buff,(yyvsp[0]).value.strval);
         (yyval).type = 2; (yyval).value.strval = buff;
       }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 2){
         //append an int to the beginning of a string
         buff = malloc(sizeof((yyvsp[-2]).value.intval) + strlen((yyvsp[0]).value.strval)+ 1);
         sprintf(buff+strlen(buff),"%d",(yyvsp[-2]).value.intval); 
         strcat(buff,(yyvsp[0]).value.strval); 
         (yyval).type = 2; (yyval).value.strval = buff;
       }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 2){
         //append a float to the beginning of a string
         buff = malloc(sizeof((yyvsp[-2]).value.doubleval) + strlen((yyvsp[0]).value.strval)+ 1);
         sprintf(buff+strlen(buff),"%g",(yyvsp[-2]).value.doubleval); 
         strcat(buff,(yyvsp[0]).value.strval); 
         (yyval).type = 2; (yyval).value.strval = buff;
       }else if((yyvsp[-2]).type == 2 && (yyvsp[0]).type == 0){
         //append int to end of string
         buff = malloc(strlen((yyvsp[-2]).value.strval) + sizeof((yyvsp[0]).value.intval)+ 1);
         strcat(buff,(yyvsp[-2]).value.strval); 
         sprintf(buff+strlen(buff),"%d",(yyvsp[0]).value.intval);  
         (yyval).type = 2; (yyval).value.strval = buff;
       }else if((yyvsp[-2]).type ==2 && (yyvsp[0]).type == 1){
         //append a float to end of string
         buff = malloc(strlen((yyvsp[-2]).value.strval) + sizeof((yyvsp[0]).value.doubleval)+ 1);
         strcat(buff,(yyvsp[-2]).value.strval); 
         sprintf(buff+strlen(buff),"%g",(yyvsp[0]).value.doubleval);  
         (yyval).type = 2; (yyval).value.strval = buff;
       }
       else{ 
         printf("Mismatched type; cannot add\n");
         YYERROR;
       }
      }
#line 1821 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 278 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval - (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 1; (yyval).value.doubleval = 
        (yyvsp[-2]).value.intval - (yyvsp[0]).value.doubleval;
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 1; (yyval).value.doubleval =
        (yyvsp[-2]).value.doubleval - (yyvsp[0]).value.intval;
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        (yyvsp[-2]).value.intval - (yyvsp[0]).value.intval;
        }
       //At least one arg is a string
       }else{ 
         printf("Cannot subract using strings\n");
         YYERROR;
       }
      }
#line 1851 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 309 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval > (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval > (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval > (yyvsp[0]).value.intval);
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval > (yyvsp[0]).value.intval);
        }
      }else if((yyvsp[-2]).type == (yyvsp[0]).type){//strcmp
         (yyval).type = 0; (yyval).value.intval = 
         (1 == strcmp((yyvsp[-2]).value.strval,(yyvsp[0]).value.strval));
         //1 means $1 > $3, true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
#line 1884 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 338 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval < (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval < (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval < (yyvsp[0]).value.intval);
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval < (yyvsp[0]).value.intval);
        }
      }else if((yyvsp[-2]).type == (yyvsp[0]).type){//strcmp
         (yyval).type = 0; (yyval).value.intval = 
         (-1 == strcmp((yyvsp[-2]).value.strval,(yyvsp[0]).value.strval));
         //-1 means $1 < $3, true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
#line 1917 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 367 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval <= (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval <= (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval <= (yyvsp[0]).value.intval);
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval <= (yyvsp[0]).value.intval);
        }
      }else if((yyvsp[-2]).type == (yyvsp[0]).type){//strcmp
         (yyval).type = 0; (yyval).value.intval = 
         (-1 != strcmp((yyvsp[-2]).value.strval,(yyvsp[0]).value.strval));
         //-1 means $3 < $1, not true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
#line 1950 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 396 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval >= (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval >= (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval >= (yyvsp[0]).value.intval);
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval >= (yyvsp[0]).value.intval);
        }
      }else if((yyvsp[-2]).type == (yyvsp[0]).type){//strcmp
         (yyval).type = 0; (yyval).value.intval = 
         (1 != strcmp((yyvsp[-2]).value.strval,(yyvsp[0]).value.strval));
         //1 means $3 > $1, not true here
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
#line 1983 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 433 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval == (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval == (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval == (yyvsp[0]).value.intval);
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval == (yyvsp[0]).value.intval);
        }
      }else if((yyvsp[-2]).type == (yyvsp[0]).type){//strcmp
         (yyval).type = 0; (yyval).value.intval = 
         (0 == strcmp((yyvsp[-2]).value.strval,(yyvsp[0]).value.strval));
         //Equal; strmp = 0 means they are equal
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
#line 2016 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 462 "TESTsymbol.y" /* yacc.c:1646  */
    {if( (yyvsp[-2]).type < 2 && (yyvsp[0]).type < 2 ){
      //Both are numbers
        if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 1){
        //floats
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval != (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 0 && (yyvsp[0]).type == 1){
        //one int one float
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval != (yyvsp[0]).value.doubleval);
        }else if((yyvsp[-2]).type == 1 && (yyvsp[0]).type == 0){
        //one float one int
        (yyval).type = 0; (yyval).value.intval =
        ((yyvsp[-2]).value.doubleval != (yyvsp[0]).value.intval);
        }else{
        //ints
        (yyval).type = 0; (yyval).value.intval = 
        ((yyvsp[-2]).value.intval != (yyvsp[0]).value.intval);
        }
      }else if((yyvsp[-2]).type == (yyvsp[0]).type){//strcmp
         (yyval).type = 0; (yyval).value.intval = 
         (0 != strcmp((yyvsp[-2]).value.strval,(yyvsp[0]).value.strval));
         //Not Equals; strmp = 0 means they are equal
       }else{ 
         printf("Mismatched type; cannot compare\n");
         YYERROR;
       }
      }
#line 2049 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 496 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 2055 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 498 "TESTsymbol.y" /* yacc.c:1646  */
    {symrec *tmp;
       if((yyvsp[0]).type == 0){//integer
         tmp = putsym((yyvsp[-2]).name, 0, 1); //add to sym_t
         upsym((yyvsp[-2]).name, (void *)&(yyvsp[0]).value.intval, NULL); //update val
         free((yyvsp[-2]).name); //yylval no longer needed, free 
         (yyval) = *tmp;
       }else if((yyvsp[0]).type == 1){//float
         tmp = putsym((yyvsp[-2]).name, 1, 1);
         upsym((yyvsp[-2]).name, (void *)&(yyvsp[0]).value.doubleval, NULL);
         free((yyvsp[-2]).name); 
         (yyval) = *tmp;
       }else{ //string
         tmp = putsym((yyvsp[-2]).name, 2, 1);
         upsym((yyvsp[-2]).name, (void *)(yyvsp[0]).value.strval, NULL);
         free((yyvsp[-2]).name);
         (yyval) = *tmp;
       }
      }
#line 2078 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 520 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 2084 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 522 "TESTsymbol.y" /* yacc.c:1646  */
    {if((yyvsp[0]).type == 0){//integer
        	   printf("%d\n",(yyvsp[0]).value.intval);
       		 }else if((yyvsp[0]).type == 1){//float
         	   printf("%g\n",(yyvsp[0]).value.doubleval);
       		 }else{ //string
         	   printf("%s\n",(yyvsp[0]).value.strval);
       		 }
	    	}
#line 2097 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 530 "TESTsymbol.y" /* yacc.c:1646  */
    {YYACCEPT;}
#line 2103 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 539 "TESTsymbol.y" /* yacc.c:1646  */
    {no_exec_flag = 0;
			free_sym_table(1);
			scope_lvl -= 1;}
#line 2111 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 543 "TESTsymbol.y" /* yacc.c:1646  */
    {no_exec_flag = 0;
			free_sym_table(1);
			scope_lvl -= 1;}
#line 2119 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 548 "TESTsymbol.y" /* yacc.c:1646  */
    {if(!(yyvsp[-2]).value.intval) no_exec_flag = 1;
              scope_lvl += 1;
              /*Set flag and inc scope*/}
#line 2127 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 551 "TESTsymbol.y" /* yacc.c:1646  */
    {if(!(yyvsp[-1]).value.intval) no_exec_flag = 1;
              scope_lvl += 1; }
#line 2134 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 557 "TESTsymbol.y" /* yacc.c:1646  */
    {
	      	char *ifName;
	        char *ifText;
	        int symReturn;
	        symrec *ifS;
	        //Create the symbol text
	        while( (symReturn = yylex() ) != SMITE){ //Consume SMITE token
	          //While reading the if block, copy into string
	          if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	            //STRINGs are stored in a separate buffer
	            if(symReturn == STRING){
	              strcat(TMP_BUFF, "\"");
	              strcat(TMP_BUFF,yylval.value.strval);
	              strcat(TMP_BUFF, "\" ");
	            }else{
	              strcat(TMP_BUFF, yytext);
	              strcat(TMP_BUFF, " ");
	            }
	            
	          }else{
	            //TMP_BUFF buffer overflow, error
	            printf("TMP BUFF overflowed\n");
	            YYERROR;
	          }
	        }
	        //Here, SMITE is in the yytext buffer
	        /*if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	          strcat(TMP_BUFF, yytext);
	          strcat(TMP_BUFF, " ");
	        }else{
	          //TMP_BUFF buffer overflow, error
	          printf("TMP BUFF overflowed\n");
	          YYERROR;
	        }*/
	        
	        ifText = malloc(strlen(TMP_BUFF) + 1);
	        strcpy(ifText, TMP_BUFF); //put text into new string
	        memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
	        ifName = make_sym_name("\0", "if");
	        
	        ifS = putsym(ifName, 2, 2);
	        upsym(ifName, (void *)ifText, NULL); //put and update symbol
	        
	        //Here, I would redirect the input of yyparse/flex to the string in if
	        //if the if statement is true
	        if(no_exec_flag){
	          no_exec_flag = 0;
	        }else{
	        //Switch input to string
	          YY_BUFFER_STATE ys = yy_scan_string(ifText);
	          yyparse();
	          yy_delete_buffer(ys);
	        
	        //Switch back to stdin
	          YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
	          yy_switch_to_buffer(ys2); 
	          
	          no_exec_flag = 1; //so alternate doesn't execute 
	        }
	        
	        }
#line 2200 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 619 "TESTsymbol.y" /* yacc.c:1646  */
    {
	      	char *ifName;
	        char *ifText;
	        int symReturn;
	        symrec *ifS;
	        //Create the symbol text
	        
	        //Here, get the lookahead token in yytext
	        if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	          strcat(TMP_BUFF, yytext);
	          strcat(TMP_BUFF, " ");
	        }else{
	          //TMP_BUFF buffer overflow, error
	          printf("TMP BUFF overflowed\n");
	          YYERROR;
	        }
	        
	        while( (symReturn = yylex() ) != '\n'){ //Consume \n token
	          //While reading the if block, copy into string
	          if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	            //STRINGs are stored in a separate buffer
	            if(symReturn == STRING){
	              strcat(TMP_BUFF, "\"");
	              strcat(TMP_BUFF,yylval.value.strval);
	              strcat(TMP_BUFF, "\" ");
	            }else{
	              strcat(TMP_BUFF, yytext);
	              strcat(TMP_BUFF, " ");
	            }
	            
	          }else{
	            //TMP_BUFF buffer overflow, error
	            printf("TMP BUFF overflowed\n");
	            YYERROR;
	          }
	        }
	        //Here, \n is in the yytext buffer
	        if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
	          strcat(TMP_BUFF, yytext);
	        }else{
	          //TMP_BUFF buffer overflow, error
	          printf("TMP BUFF overflowed\n");
	          YYERROR;
	        }
	        
	        ifText = malloc(strlen(TMP_BUFF) + 1);
	        strcpy(ifText, TMP_BUFF); //put text into new string
	        memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
	        ifName = make_sym_name("\0", "if");
	        
	        ifS = putsym(ifName, 2, 2);
	        upsym(ifName, (void *)ifText, NULL); //put and update symbol
	        
	        //Here, I would redirect the input of yyparse/flex to the string in if
	        //if the if statement is true
	        if(no_exec_flag){
	          no_exec_flag = 0;
	        }else{
	        //Switch input to string
	          YY_BUFFER_STATE ys = yy_scan_string(ifText);
	          yyparse();
	          yy_delete_buffer(ys);
	        
	        //Switch back to stdin
	          YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
	          yy_switch_to_buffer(ys2); 
	          
	          no_exec_flag = 1; //so alternate doesn't execute 
	        }
	        
	        }
#line 2276 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 694 "TESTsymbol.y" /* yacc.c:1646  */
    {
       char *ifName;
       char *ifText;
       int symReturn;
       symrec *ifS;
       //Create the symbol text
       while( (symReturn = yylex() ) != SMITE){
       //While reading the if block, copy into string
         if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
           if(symReturn == STRING){
	     strcat(TMP_BUFF, "\"");
	     strcat(TMP_BUFF,yylval.value.strval);
	     strcat(TMP_BUFF, "\" ");
	   }else{
	     strcat(TMP_BUFF, yytext);
	     strcat(TMP_BUFF, " ");
	   }
         }else{
           //TMP_BUFF buffer overflow, error
           printf("TMP BUFF overflowed\n");
           YYERROR;
         }
       }
       //Here, SMITE is in the yytext buffer
       /*if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
         strcat(TMP_BUFF, yytext);
         strcat(TMP_BUFF, " ");
       }else{
       //TMP_BUFF buffer overflow, error
         printf("TMP BUFF overflowed\n");
         YYERROR;
       }*/
       
       //Put the text within the if statement into a new symbol
       ifText = malloc(strlen(TMP_BUFF) + 1);
       strcpy(ifText, TMP_BUFF); //put text into new string
       memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
       ifName = make_sym_name("\0", "else");
       ifS = putsym(ifName, 2, 2);
       upsym(ifName, (void *)ifText, NULL); //put and update symbol
       
       //Here, I would redirect the input of yyparse/flex to the string in if
       //if the ELSE statement is true
       if(no_exec_flag){
         no_exec_flag = 0;
       }else{
         YY_BUFFER_STATE ys = yy_scan_string(ifText);
         yyparse();
         yy_delete_buffer(ys);
       
       //Switch back to stdin
         YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
         yy_switch_to_buffer(ys2); 
         
       }
       
       }
#line 2338 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 755 "TESTsymbol.y" /* yacc.c:1646  */
    {/*Increment scope
		  *While(loop_be.intval)
		  *While this is true, execute text stored in loop_block */
		  scope_lvl += 1; //Increment scope into loop
		  while((yyvsp[-2]).value.intval){
		  printf("$3 val: %d\n", (yyvsp[-2]).value.intval);
		     //Here, I would redirect the input of yyparse/flex to the string in if
      		 //if the ELSE statement is true
      		 
       	 	   YY_BUFFER_STATE ys = yy_scan_string((yyvsp[0]).value.strval);
      		   yyparse();
        	   yy_delete_buffer(ys);
       
      		 //Switch back to stdin
       		  YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
        	  yy_switch_to_buffer(ys2); 
		  }  
		}
#line 2361 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 777 "TESTsymbol.y" /* yacc.c:1646  */
    {/*Store block in $$*/
	char *ifText;
       symrec *ifS;
       //Create the loop text
       while(yylex() != SMITE){
       //While reading the if block, copy into string
         if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
           strcat(TMP_BUFF, yytext);
           strcat(TMP_BUFF, " ");
         }else{
           //TMP_BUFF buffer overflow, error
           printf("TMP BUFF overflowed\n");
           YYERROR;
         }
       }
      
       //Put the text within the if statement into $$
       ifText = malloc(strlen(TMP_BUFF) + 1);
       strcpy(ifText, TMP_BUFF); //put text into new string
       memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
       (yyval).value.strval = ifText; //Pass loop text up
       }
#line 2388 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 802 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 2394 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 803 "TESTsymbol.y" /* yacc.c:1646  */
    {;}
#line 2400 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 819 "TESTsymbol.y" /* yacc.c:1646  */
    {//param_list is in ptable
		 //Need to assign func.p symbols in normal table the values of
		 //the param_list symbols
		   //while param_sym_table != tail
		     //symrec *tmp = psymtable
		     //symrec *fSym = getsym($1.name)
		     //upsym(func.p1, tmp.value, tmp.params)
		     //get next, move pointers
		     //Check for errors
		 free((yyvsp[-1]).name); //Don't need the concat'd list of param names here    
		 symrec *ptr;
		 //printf("##fname in f_call: %s\n", $1.name);
		 symrec *fSymb = getsym((yyvsp[-3]).name); //Find the function symbol
		 free((yyvsp[-3]).name); //Use fSymb name now
		 int i = 0; //interate through function parameters
		 for(ptr = param_sym_table; strcmp(ptr->name,"tail") != 0; ptr = (symrec *)ptr->next){		 //Count # of parameters
		   i++;}
		 i--; //# of params will always be 1 more than actual
		 
		 for(ptr = param_sym_table; strcmp(ptr->name,"tail") != 0; ptr = (symrec *)ptr->next, i--){
		   if(ptr->type == 0){
		     putsym( *((*fSymb).params+i), 0, 1);
		     upsym( *((*fSymb).params+i), (void *)&(*ptr).value.intval, NULL);
		   }else if(ptr->type == 1){
		     putsym( *((*fSymb).params+i), 1, 1);
		     upsym( *((*fSymb).params+i), (void *)&(*ptr).value.doubleval, NULL);
		   }else{
		     putsym( *((*fSymb).params+i), 2, 1);
		     upsym( *((*fSymb).params+i), (void *)(*ptr).value.strval, NULL);
		   }
		 }
		 
		 //the func.p symbols will have values (free paramsymtable?)
		 free_sym_table_param();
		 //Global flag to look for function symbols first
		 f_flag = 1; 
		 f_name = fSymb->name;
		 //Read the function symbol's block, incr scope
		 scope_lvl += 1;
		 YY_BUFFER_STATE ys = yy_scan_string(fSymb->value.strval);
		 yyparse();
		 yy_delete_buffer(ys);
		 
		 //read back from stdin
		 free_sym_table(1); //delete function's stack frame
		 scope_lvl -= 1;
		 f_flag = 0;
		 f_name = NULL;
		 YY_BUFFER_STATE ys2 = yy_create_buffer(stdin, YY_BUF_SIZE);
		 yy_switch_to_buffer(ys2);
		
		}
#line 2457 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 875 "TESTsymbol.y" /* yacc.c:1646  */
    {symrec *tmp = getsym((yyvsp[-1]).name);
		 //Put function body and parameter names into function symbol
		 upsym((yyvsp[-1]).name, (yyvsp[0]).value.strval, tmp->params);
		 //printf("f_declar name: %s\n, text: %s\n, param1: %s\n",tmp->name,
		 //						tmp->value.strval,
		 //						*(*tmp).params);
		 free((yyvsp[-1]).name); //Free values no longer in use
		 free_sym_table_param(); //param_list adds to table, declaration
		 //DOESNOT USE THESE VALUES, so free
		}
#line 2472 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 889 "TESTsymbol.y" /* yacc.c:1646  */
    {char *token;
		 char *pName;
		 char **pNames = malloc(sizeof(char*) * 10);
		 int i = 0;
		 if( (token = strtok((yyvsp[-2]).name, ",")) != NULL){
		   //Create func.param symbol in table
		   pName = make_sym_name((yyvsp[-4]).name, token);
		   
		   //putsym(pName, 0, 1); //Name, Type(arbitrary), Qual(var)
		   *pNames = pName;
		 }else{
		   printf("func_head strtok returned as NULL first\n");
		   
		 }
		 while( (token = strtok(NULL, ",")) != NULL){
		   i++; 
		   
		   pName = make_sym_name((yyvsp[-4]).name, token);
		   //printf("%s\n",pName);
		   //putsym(pName, 0, 1);
		   *(pNames+i) = pName; //Add to list of params
		   
		 }
		 
		 putsym((yyvsp[-4]).name, 2, 2); //name, char*, function
		 upsym((yyvsp[-4]).name, NULL, pNames); //Put param list in function symbol
		 (yyval).name = (yyvsp[-4]).name; //Pass function name up
		  /*1. Create symbol w/ name IDENTIFIER and param_list
		    2. Create param symbols with func.param name scheme
		    3. $$ = function symbol*/}
#line 2507 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 923 "TESTsymbol.y" /* yacc.c:1646  */
    {char *funcText;
		int symReturn;
    	   	//Read the function text
       		while( (symReturn = yylex() ) != SMITE){
         	  //While reading the function block, copy into string
         	  if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
           	    if(symReturn == STRING){
	              strcat(TMP_BUFF, "\"");
	              strcat(TMP_BUFF,yylval.value.strval);
	              strcat(TMP_BUFF, "\" ");
	            }else{
	              strcat(TMP_BUFF, yytext);
	              strcat(TMP_BUFF, " ");
	            }
         	  }else{
           	    //TMP_BUFF buffer overflow, error
           	    printf("TMP BUFF overflowed in func_body\n");
           	    YYERROR;
         	  }
      		}
       		/*//Here, SMITE is in the yytext buffer
       		if(strlen(TMP_BUFF) < ( MAX_STRING + strlen(yytext) ) ){
         	  strcat(TMP_BUFF, yytext);
         	  strcat(TMP_BUFF, " ");
       		}else{
         	  //TMP_BUFF buffer overflow, error
         	  printf("TMP BUFF overflowed in func_body\n");
         	  YYERROR;
       		}*/
       
       		funcText = malloc(strlen(TMP_BUFF) + 1);
       		strcpy(funcText, TMP_BUFF); //put text into new string
       		memset(TMP_BUFF, '\0', strlen(TMP_BUFF) ); //zero out buffer
       		(yyval).value.strval = funcText; //Pass text up
       		}
#line 2547 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 965 "TESTsymbol.y" /* yacc.c:1646  */
    {symrec *tmp;
       		if((yyvsp[0]).type == 0){//integer
       		  tmp = putsym_param((yyvsp[0]).name, 0, 1); //add to sym_t
         	  upsym_param((yyvsp[0]).name, (void *)&(yyvsp[0]).value.intval, NULL); //update val
       		}else if((yyvsp[0]).type == 1){//float
        	  tmp = putsym_param((yyvsp[0]).name, 1, 1);
        	  upsym_param((yyvsp[0]).name, (void *)&(yyvsp[0]).value.doubleval, NULL);
       		}else{ //string
        	  tmp = putsym_param((yyvsp[0]).name, 2, 1);
       		  upsym_param((yyvsp[0]).name, (void *)(yyvsp[0]).value.strval, NULL);
      		}
      		
      		(yyval) = (yyvsp[0]); //Pass the symbol up after putting in symtablep
		}
#line 2566 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 986 "TESTsymbol.y" /* yacc.c:1646  */
    {//Concat the parameter names into one string to pass up
		 buff = malloc(strlen((yyvsp[-2]).name) + 1 + strlen((yyvsp[0]).name) + 1);
		 strcat(buff, (yyvsp[-2]).name);
		 strcat(buff,",");
		 strcat(buff, (yyvsp[0]).name);
		 (yyval).name = buff;
		 }
#line 2578 "TESTsymbol.tab.c" /* yacc.c:1646  */
    break;


#line 2582 "TESTsymbol.tab.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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

#if 1
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 996 "TESTsymbol.y" /* yacc.c:1906  */


int main(void)
{
  //yydebug = 1;
  int result;
  init_table();
  result = yyparse();
  free_sym_table(0); //free the symbol table!
  return result;
}

void init_table()
{
  putsym("tail", 0, 0); //Add first node to symbol table
  putsym_param("tail", 0, 0); //And to param symbol table
}

/*
*free_sym_table frees the symbols within the indicated scope
* A value of 0 means all scopes (called at end of program)
* Any other value means the current scope, the integer scope_lvl
*/
int free_sym_table(int scope)
{

  if(!scope){ //All scopes
    symrec *ptr = sym_table;
    symrec *next = (symrec *)sym_table->next;
    while( strcmp(ptr->name, "tail") != 0){ //while not tail
    
      //printf("##Freeing %s in symbol table\n",ptr->name);
      if(ptr->type == 2){free(ptr->value.strval);}
      if(ptr->qual == 2){free(ptr->params);} //free function parameters
      free(ptr->name);
      free(ptr);
      ptr = next;
      next = (symrec *)ptr->next;
      //printf("##Next symbol: %s\n",ptr->name);
      
    }
    //Free the tail
    free(ptr->name);
    free(ptr);

    return 0;
  }else{ //Free the variables for only THIS scope # = sym_scope[scope_lvl];
    symrec *ptr = sym_table;
    symrec *next = (symrec *)sym_table->next;
    //Loop once for each symbol in scope, decrementing # of symbols as it goes
    for(;sym_scope[scope_lvl] > 0; sym_scope[scope_lvl]--){
    
      //printf("##Freeing %s from scope %d\n",ptr->name,scope_lvl);
      if(ptr->type == 2){free(ptr->value.strval);}
      if(ptr->qual == 2){free(ptr->params);} //free function parameters
      free(ptr->name);
      free(ptr);
      ptr = next;
      next = (symrec *)ptr->next;

    }
    sym_table = ptr;
    return 0;
  }
}


int free_sym_table_param()
{
  
    symrec *ptr = param_sym_table;
    symrec *next = (symrec *)param_sym_table->next;
    while( strcmp(ptr->name, "tail") != 0){ //while not tail
      //printf("##freeing %s in p_sym_t\n",ptr->name);
      if(ptr->type == 2){free(ptr->value.strval);}
      free(ptr->name);
      free(ptr);
      ptr = next;
      next = (symrec *)ptr->next;
      //printf("##next symbol in p_sym_t: %s\n",ptr->name);
    }
    param_sym_table = ptr;
    //Don't free the tail
    return 0;
  
}

/*
*  symrec *putsym places a symbol at the front of the symbol chain and returns it
* type 0: integer, type 1: double, type 2: char*
* qual 0: constant, qual 1: var, qual 2: function/block
*/
symrec *putsym(char const *sym_name, int sym_type, int sym_qual)
{
  symrec *ptr = malloc(sizeof *ptr);
  ptr->name = malloc(strlen(sym_name) + 1);
  strcpy(ptr->name,sym_name);
  ptr->type = sym_type;
  ptr->qual = sym_qual;
  ptr->value.intval = 0;
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  sym_scope[scope_lvl] += 1;
  //printf("##Added %s to symbol table in scope %d\n",ptr->name, scope_lvl);
  return ptr;
}

/*putsym_param functions the same as putsym, except it only works
 with the parameter symbol table and it does not increment the symbol count */
symrec *putsym_param(char const *sym_name, int sym_type, int sym_qual)
{
  symrec *ptr = malloc(sizeof *ptr);
  ptr->name = malloc(strlen(sym_name) + 1);
  strcpy(ptr->name,sym_name);
  ptr->type = sym_type;
  ptr->qual = sym_qual;
  ptr->value.intval = 0;
  ptr->next = (struct symrec *)param_sym_table;
  param_sym_table = ptr;
  //printf("##Added %s to param symbol table\n",ptr->name);
  return ptr;
}

/*
*  Updates a symbol in the table to add its value
*  For functions/blocks, no malloc necessary as that block text has already been
* allocated
*/
symrec *upsym(char const *sym_name, void *value, char **parameters)
{
  symrec *ptr;
  for(ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
    if(strcmp(ptr->name, sym_name) == 0){ //symbol found
      if(ptr->qual == 0 || ptr->qual == 1){
        if(ptr->type == 0){ //integer
          ptr->value.intval = *(int *)value;
         // printf("##Added value %d to int %s in symbol table\n",ptr->value.intval,ptr->name);
        }else if(ptr->type == 1){ //float
          ptr->value.doubleval = *(double *)value;
          //printf("##Added value %g to double %s in symbol table\n",ptr->value.doubleval,ptr->name);
        }else if(ptr->type == 2){ //string
          ptr->value.strval = malloc(strlen( (char*)value )+1);
          strcpy(ptr->value.strval, (char*)value);
          //printf("##Added value \"%s\" to string %s in symbol table\n",ptr->value.strval,ptr->name);
        }
      }else{ //function or block
        ptr->value.strval = (char *)value;
        ptr->params = parameters; //List of function parameters, if there are any
        //printf("##Added value \"%s\" to block %s in symbol table\n",ptr->value.strval,ptr->name);
      }
      break;
    }
  }
  return ptr;
}

/*Updates a symbol within the parameter symbol table */
symrec *upsym_param(char const *sym_name, void *value, char **parameters)
{
  symrec *ptr;
  for(ptr = param_sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
    if(strcmp(ptr->name, sym_name) == 0){
      if(ptr->qual == 0 || ptr->qual == 1){
        if(ptr->type == 0){ //integer
          ptr->value.intval = *(int *)value;
          //printf("##Added value %d to int %s in param symbol table\n",ptr->value.intval,ptr->name);
        }else if(ptr->type == 1){ //float
          ptr->value.doubleval = *(double *)value;
          //printf("##Added value %g to double %s in param symbol table\n",ptr->value.doubleval,ptr->name);
        }else if(ptr->type == 2){ //string
          ptr->value.strval = malloc(strlen( (char*)value )+1);
          strcpy(ptr->value.strval, (char*)value);
          //printf("##Added value \"%s\" to string %s in param symbol table\n",ptr->value.strval,ptr->name);
        }
      }else{ //function or block
        ptr->value.strval = (char *)value;
        ptr->params = parameters; //List of function parameters, if there are any
        //printf("##Added value \"%s\" to block %s in symbol table\n",ptr->value.strval,ptr->name);
      }
      break;
    }
  }
  return ptr;
}

/*
*  symrec *getsym scans through the symbol chain to find the named symbol
*  if not found, return 0, or return a ptr to that symbol
*  If the f_flag is on, it searches for the function parameter with
*  that name first
*/
symrec *getsym(char const *sym_name)
{
  //If function flag is on, search for func parameter value first
  symrec *ptr;
  if(f_flag){
    //Make fname function
    strcat(TMP_BUFF, f_name); 
    strcat(TMP_BUFF, ".");
    strcat(TMP_BUFF, sym_name);
    //printf("file param name: %s\n",TMP_BUFF);
    char *sName = malloc(strlen(TMP_BUFF) + 1);
    //Copy into new string
    strcpy(sName, TMP_BUFF);
    //Clear buffer
    memset(TMP_BUFF, '\0', strlen(TMP_BUFF));
    for(ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
      if(strcmp(ptr->name, sName) == 0){
        free(sName); //free alloc'd string
        return ptr;
      }
    }
    free(sName); //Free if not returned
  }
  //If not found or if flag not on, search for normal
  
  for(ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next){
    if(strcmp(ptr->name, sym_name) == 0){
      return ptr;
    }
  }
  return 0;
  
}

/*
* make_sym_name makes a symbol name to put into table based on the two parameters
* char *func will tell whether this is a function parameter name or not
* char *param tells the name of said parameter, or if is the if OR else part of
* one of those statements
*/
static char *make_sym_name(char *func, char *param)
{
  char *ret;
  if(strlen(func) == 0){
    //if-else name
    sprintf(TMP_BUFF, "%d.%s",scope_lvl,param); //scope.if, scope.else
    ret = malloc(strlen(TMP_BUFF) + 1);
    strcpy(ret, TMP_BUFF);
    memset(TMP_BUFF, '\0', strlen(TMP_BUFF));
    return ret;
  }else{
    strcat(TMP_BUFF,func); strcat(TMP_BUFF,".");
    strcat(TMP_BUFF,param); //Make a function parameter name: func.p
    ret = malloc(strlen(TMP_BUFF) + 1);
    strcpy(ret, TMP_BUFF);
    memset(TMP_BUFF,'\0',strlen(TMP_BUFF));
    return ret;
  }
}

static void yyprint(FILE *file, int type, struct symrec value)
{
  fprintf(file, "yylval: name:%s, type:%d, qual:%d", value.name,value.type,value.qual);
}

void yyerror(const char *s) {fprintf(stderr,"%s\n",s);}

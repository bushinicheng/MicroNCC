/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntax.y" /* yacc.c:339  */

#include "common.h"
#include "debug.h"
#include "ast.h"

int yylex();
int yyerror(const char *str, ...);


#line 76 "syntax.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.h".  */
#ifndef YY_YY_SYNTAX_H_INCLUDED
# define YY_YY_SYNTAX_H_INCLUDED
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
    LOWWEST = 258,
    LOWWER_THAN_ELSE = 259,
    ELSE = 260,
    LT = 261,
    LE = 262,
    NE = 263,
    EQ = 264,
    GE = 265,
    GT = 266,
    BITAND = 267,
    BITOR = 268,
    BITNOR = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    ADD = 273,
    SUB = 274,
    MULT = 275,
    DIV = 276,
    RELOP = 277,
    ASSIGNOP = 278,
    LP = 279,
    RP = 280,
    LB = 281,
    RB = 282,
    LC = 283,
    RC = 284,
    DOT = 285,
    COMMA = 286,
    SEMI = 287,
    POINTER = 288,
    IF = 289,
    DO = 290,
    WHILE = 291,
    FOR = 292,
    RETURN = 293,
    TYPE = 294,
    INT = 295,
    CHAR = 296,
    FLOAT = 297,
    STRUCT = 298,
    NUM = 299,
    STRING = 300,
    ID = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "syntax.y" /* yacc.c:355  */

	Node *pnd;

#line 167 "syntax.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "syntax.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   618

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    72,    73,    76,    77,    81,    82,    85,
      86,    89,    92,    93,    98,   105,   106,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   124,   128,
     135,   136,   139,   140,   148,   152,   158,   159,   162,   163,
     166,   167,   168,   180,   181,   184,   185,   186,   190,   191,
     194,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOWWEST", "LOWWER_THAN_ELSE", "ELSE",
  "LT", "LE", "NE", "EQ", "GE", "GT", "BITAND", "BITOR", "BITNOR", "AND",
  "OR", "NOT", "ADD", "SUB", "MULT", "DIV", "RELOP", "ASSIGNOP", "LP",
  "RP", "LB", "RB", "LC", "RC", "DOT", "COMMA", "SEMI", "POINTER", "IF",
  "DO", "WHILE", "FOR", "RETURN", "TYPE", "INT", "CHAR", "FLOAT", "STRUCT",
  "NUM", "STRING", "ID", "$accept", "Program", "ExtDefList", "ExtDef",
  "FuncDec", "DefArgList", "DefArg", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "VarDec", "Specifier",
  "StructSpecifier", "ArgList", "Arg", "Exp", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -52,   -18,    18,   -52,    11,   -52,     1,   -52,    11,
     -22,   -52,   -52,   -52,   -21,   -52,     3,    16,     2,    10,
       9,    14,    11,     6,    11,   -52,    49,    98,   -52,   -52,
     -52,   -15,    61,    32,   -52,   -52,   -52,    24,   -52,    20,
      46,    40,   133,    61,    61,    61,    43,    51,    61,   133,
     -52,    31,   133,    69,    74,    61,   -52,   -52,    77,     7,
     133,   -52,   174,   -52,   426,    87,   -52,   -52,    11,   -52,
      75,   566,   566,    70,   -52,   -52,    70,    13,    61,    83,
      61,    61,   202,    61,   -52,   -52,   -52,    88,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    76,   -52,    78,   -52,   -52,   -52,
     -52,   -52,   258,    97,   286,   314,   -52,   -52,   100,    96,
     426,   -52,    64,    64,   583,   583,    64,    64,   566,   538,
     510,   482,   585,   585,    70,    70,   454,   230,   -52,   -52,
     133,    61,   133,    61,   -52,    61,   -52,   -52,   123,   342,
     -52,   370,   -52,   133,    99,    61,   -52,   -52,   398,   133,
     -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    43,     0,     0,     2,     3,     6,     0,    44,     0,
      45,     1,     4,    34,     0,    33,    40,     0,     0,    37,
      38,     0,    31,     0,     0,    41,     0,     0,     5,    35,
      32,     0,     0,     0,    46,    30,    40,     0,     7,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    53,    60,    51,     0,
      16,    18,     0,    36,    39,     0,    47,     8,     0,    11,
       0,    57,    58,    59,    54,    55,    56,     0,     0,     0,
       0,     0,     0,     0,    14,    12,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,    42,     9,    13,
      29,    21,     0,     0,     0,     0,    28,    20,     0,    49,
      50,    27,    69,    70,    71,    68,    73,    72,    76,    77,
      74,    75,    64,    65,    66,    67,    61,     0,    62,    63,
       0,     0,     0,     0,    52,     0,    79,    78,    22,     0,
      24,     0,    48,     0,     0,     0,    23,    25,     0,     0,
      26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   124,   -52,   -52,    71,   -52,   -52,   -20,   -51,
      -5,    15,   107,   -52,   -52,     4,   -52,    12,   -52,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    17,    39,    40,    28,    59,    60,
      21,    61,    18,    19,    20,    23,     8,   118,   119,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    79,    13,    29,     7,    14,    24,    13,    84,     7,
       9,    71,    72,    73,   110,     6,    76,    35,    11,    37,
       6,    14,    70,    82,    22,    25,    14,    26,    10,    77,
      41,    36,    32,    15,    30,    33,    85,    22,    15,    22,
      86,    31,   111,    34,    27,    67,   112,    16,   114,   115,
       1,   120,    36,    66,     2,    78,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    41,    43,    38,    44,    65,    68,    45,    46,
      47,    48,    98,    99,   100,   101,    69,    74,     1,   148,
     103,   150,     2,    80,   104,    75,   103,   106,    81,    42,
     104,    83,   156,   106,   109,    56,    57,    58,   160,   149,
      43,   151,    44,   120,   107,    45,    46,    47,    48,   113,
     121,   141,   138,   158,   139,   144,    49,   145,   153,    12,
      50,   157,    51,    52,    53,    54,    55,     1,    63,   108,
       0,     2,    56,    57,    58,    43,     0,    44,     0,     0,
      45,    46,    47,    48,     0,     0,     0,   152,     0,     0,
       0,    49,     0,     0,     0,    50,     0,    51,    52,    53,
      54,    55,     1,     0,     0,    87,     2,    56,    57,    58,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    96,
      97,     0,    98,    99,   100,   101,     0,   102,     0,     0,
     103,     0,     0,   116,   104,     0,   105,   106,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    96,    97,     0,
      98,    99,   100,   101,     0,   102,     0,     0,   103,     0,
       0,   146,   104,     0,   117,   106,    88,    89,    90,    91,
      92,    93,    94,    95,     0,    96,    97,     0,    98,    99,
     100,   101,     0,   102,     0,     0,   103,   147,     0,     0,
     104,     0,     0,   106,    88,    89,    90,    91,    92,    93,
      94,    95,     0,    96,    97,     0,    98,    99,   100,   101,
       0,   102,     0,   140,   103,     0,     0,     0,   104,     0,
       0,   106,    88,    89,    90,    91,    92,    93,    94,    95,
       0,    96,    97,     0,    98,    99,   100,   101,     0,   102,
       0,   142,   103,     0,     0,     0,   104,     0,     0,   106,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    96,
      97,     0,    98,    99,   100,   101,     0,   102,     0,     0,
     103,     0,     0,     0,   104,     0,   143,   106,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    96,    97,     0,
      98,    99,   100,   101,     0,   102,     0,   154,   103,     0,
       0,     0,   104,     0,     0,   106,    88,    89,    90,    91,
      92,    93,    94,    95,     0,    96,    97,     0,    98,    99,
     100,   101,     0,   102,     0,     0,   103,     0,     0,     0,
     104,     0,   155,   106,    88,    89,    90,    91,    92,    93,
      94,    95,     0,    96,    97,     0,    98,    99,   100,   101,
       0,   102,     0,   159,   103,     0,     0,     0,   104,     0,
       0,   106,    88,    89,    90,    91,    92,    93,    94,    95,
       0,    96,    97,     0,    98,    99,   100,   101,     0,   102,
       0,     0,   103,     0,     0,     0,   104,     0,     0,   106,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    96,
      97,     0,    98,    99,   100,   101,     0,     0,     0,     0,
     103,     0,     0,     0,   104,     0,     0,   106,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    96,     0,     0,
      98,    99,   100,   101,     0,     0,     0,     0,   103,     0,
       0,     0,   104,     0,     0,   106,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,    98,    99,
     100,   101,     0,     0,     0,     0,   103,     0,     0,     0,
     104,     0,     0,   106,    88,    89,    90,    91,    92,    93,
      94,     0,     0,     0,     0,     0,    98,    99,   100,   101,
       0,     0,     0,     0,   103,     0,     0,     0,   104,     0,
       0,   106,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,     0,    88,
      89,     0,   103,    92,    93,     0,   104,     0,     0,   106,
       0,    98,    99,   100,   101,   100,   101,     0,     0,   103,
       0,   103,     0,   104,     0,   104,   106,     0,   106
};

static const yytype_int16 yycheck[] =
{
      32,    52,     1,     1,     0,    20,    28,     1,     1,     5,
      28,    43,    44,    45,     1,     0,    48,    22,     0,    24,
       5,    20,    42,    55,     9,    46,    20,    24,    46,    49,
      26,    46,    23,    32,    32,    26,    29,    22,    32,    24,
      60,    31,    29,    29,    28,    25,    78,    46,    80,    81,
      39,    83,    46,    29,    43,    24,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    68,    12,    25,    14,    44,    31,    17,    18,
      19,    20,    18,    19,    20,    21,    46,    44,    39,   140,
      26,   142,    43,    24,    30,    44,    26,    33,    24,     1,
      30,    24,   153,    33,    29,    44,    45,    46,   159,   141,
      12,   143,    14,   145,    27,    17,    18,    19,    20,    36,
      32,    24,    46,   155,    46,    25,    28,    31,     5,     5,
      32,    32,    34,    35,    36,    37,    38,    39,    31,    68,
      -1,    43,    44,    45,    46,    12,    -1,    14,    -1,    -1,
      17,    18,    19,    20,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,     1,    43,    44,    45,    46,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    -1,    18,    19,    20,    21,    -1,    23,    -1,    -1,
      26,    -1,    -1,     1,    30,    -1,    32,    33,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    -1,
      18,    19,    20,    21,    -1,    23,    -1,    -1,    26,    -1,
      -1,     1,    30,    -1,    32,    33,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    15,    16,    -1,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    -1,    18,    19,    20,    21,
      -1,    23,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    -1,    18,    19,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    -1,    18,    19,    20,    21,    -1,    23,    -1,    -1,
      26,    -1,    -1,    -1,    30,    -1,    32,    33,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    -1,
      18,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    15,    16,    -1,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,
      30,    -1,    32,    33,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    -1,    18,    19,    20,    21,
      -1,    23,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    -1,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    -1,     6,
       7,    -1,    26,    10,    11,    -1,    30,    -1,    -1,    33,
      -1,    18,    19,    20,    21,    20,    21,    -1,    -1,    26,
      -1,    26,    -1,    30,    -1,    30,    33,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    43,    48,    49,    50,    58,    62,    63,    28,
      46,     0,    49,     1,    20,    32,    46,    51,    59,    60,
      61,    57,    58,    62,    28,    46,    24,    28,    54,     1,
      32,    31,    23,    26,    29,    57,    46,    57,    25,    52,
      53,    62,     1,    12,    14,    17,    18,    19,    20,    28,
      32,    34,    35,    36,    37,    38,    44,    45,    46,    55,
      56,    58,    66,    59,    66,    44,    29,    25,    31,    46,
      55,    66,    66,    66,    44,    44,    66,    55,    24,    56,
      24,    24,    66,    24,     1,    29,    55,     1,     6,     7,
       8,     9,    10,    11,    12,    13,    15,    16,    18,    19,
      20,    21,    23,    26,    30,    32,    33,    27,    52,    29,
       1,    29,    66,    36,    66,    66,     1,    32,    64,    65,
      66,    32,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    46,    46,
      25,    24,    25,    32,    25,    31,     1,    27,    56,    66,
      56,    66,    64,     5,    25,    32,    56,    32,    66,    25,
      56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     1,     3,     4,     3,
       1,     2,     3,     4,     3,     2,     1,     2,     1,     1,
       3,     3,     5,     7,     5,     7,     9,     3,     3,     3,
       2,     1,     3,     2,     2,     3,     3,     1,     1,     3,
       1,     2,     4,     1,     1,     2,     4,     5,     3,     1,
       1,     1,     4,     1,     2,     2,     2,     2,     2,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     4
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 69 "syntax.y" /* yacc.c:1646  */
    {astroot=build_subast(AST_Program_is_ExtDefList, &(yyloc), (yyvsp[0].pnd));}
#line 1567 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDefList_is_ExtDef, &(yyloc), (yyvsp[0].pnd));}
#line 1573 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDefList_is_ExtDef_ExtDefList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1579 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDef_is_Specifier_FuncDec_CompSt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1585 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDef_is_Def, &(yyloc), (yyvsp[0].pnd));}
#line 1591 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDec_is_ID_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1597 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDec_is_ID_LP_DefArgList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1603 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 85 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefArgList_is_DefArg_COMMA_DefArgList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1609 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefArgList_is_DefArg, &(yyloc), (yyvsp[0].pnd));}
#line 1615 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefArg_is_Specifier_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1621 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1627 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "syntax.y" /* yacc.c:1646  */
    {
		yyclearin;
		(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));
		yydebug((yylsp[-2]).first_line, (yylsp[-2]).last_column, 1, ERR_EXPECTED_STATEMENT);
		}
#line 1637 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(RC, &(yylsp[-1])));
		yyerr("%d:%d: error: missing '\x7d'\n", (yylsp[-1]).last_line, (yylsp[-1]).last_column);
		}
#line 1646 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt_StmtList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1652 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt, &(yyloc), (yyvsp[0].pnd));}
#line 1658 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Exp_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1664 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Def, &(yyloc), (yyvsp[0].pnd));}
#line 1670 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 111 "syntax.y" /* yacc.c:1646  */
    {}
#line 1676 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1682 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 113 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1688 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1694 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 115 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1700 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 116 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1706 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 117 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1712 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 118 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt, &(yyloc), (yyvsp[-8].pnd), (yyvsp[-7].pnd), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1718 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 119 "syntax.y" /* yacc.c:1646  */
    {
		yyclearin;
		(yyval.pnd)=build_subast(AST_Stmt_is_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), new_sym_node(SEMI, & (yylsp[-2])));
		yydebug((yylsp[-1]).first_line, (yylsp[-1]).first_column, 1, ERR_EXPECTED_SEMI);
	}
#line 1728 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 124 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(SEMI, & (yylsp[-1])));
		yydebug((yylsp[-1]).first_line, (yylsp[-1]).last_column, 1, ERR_MISSING_SEMI);
	}
#line 1737 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 128 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_Stmt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(RC, &(yylsp[-1])));
		yyerr("%d:%d: error: missing '\x7d'\n", (yyloc).first_line, (yylsp[-1]).last_column);
	}
#line 1746 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 135 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefList_is_Def_DefList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1752 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefList_is_Def, &(yyloc), (yyvsp[0].pnd));}
#line 1758 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 139 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Def_is_Specifier_DecList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1764 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 140 "syntax.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].pnd)->child->semanval != AST_StructSpecifier_is_STRUCT_LC_DefList_RC
		&& (yyvsp[-1].pnd)->child->semanval != AST_StructSpecifier_is_STRUCT_ID_LC_DefList_RC)
		{
			yydebug((yylsp[-1]).first_line, (yylsp[-1]).last_column, 1, ERR_NULL_DECLARATION);
		}
		(yyval.pnd)=build_subast(AST_Def_is_Specifier_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));
	}
#line 1777 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 148 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_Def_is_Specifier_SEMI, &(yyloc), (yyvsp[-1].pnd), new_sym_node(SEMI, & (yylsp[-1])));
		yydebug((yyloc).first_line, (yylsp[-1]).last_column, 1, ERR_MISSING_SEMI);
		}
#line 1786 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 152 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_Def_is_Specifier_DecList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(SEMI, & (yylsp[-1])));
		yydebug((yylsp[-1]).first_line, (yylsp[-1]).last_column, 1, ERR_MISSING_SEMI);
	}
#line 1795 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 158 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DecList_is_Dec_COMMA_DecList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1801 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DecList_is_Dec, &(yyloc), (yyvsp[0].pnd));}
#line 1807 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Dec_is_VarDec, &(yyloc), (yyvsp[0].pnd));}
#line 1813 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Dec_is_VarDec_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1819 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 166 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_VarDec_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 1825 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 167 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_VarDec_is_MULT_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1831 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 168 "syntax.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].pnd)->specval == 'f')
		{
			(yyvsp[-1].pnd)->specval = 'i';
			(yyvsp[-1].pnd)->exval.i = (yyvsp[-1].pnd)->exval.f;
			yyerr("%d: error type A: invalid dim\n", (yyloc).first_line);
		}
		(yyval.pnd)=build_subast(AST_VarDec_is_VarDec_LB_NUM_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));
	}
#line 1845 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_TYPE, &(yyloc), (yyvsp[0].pnd));}
#line 1851 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_StructSpecifier, &(yyloc), (yyvsp[0].pnd));}
#line 1857 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 184 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructSpecifier_is_STRUCT_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1863 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 185 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructSpecifier_is_STRUCT_LC_DefList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1869 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 186 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructSpecifier_is_STRUCT_ID_LC_DefList_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1875 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 190 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ArgList_is_Arg_COMMA_ArgList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1881 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 191 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ArgList_is_Arg, &(yyloc), (yyvsp[0].pnd));}
#line 1887 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 194 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Arg_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 1893 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 198 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 1899 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID_LP_ArgList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1905 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 200 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NUM, &(yyloc), (yyvsp[0].pnd));}
#line 1911 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 201 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ADD_NUM, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1917 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SUB_NUM, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1923 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 203 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_MULT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1929 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 204 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_BITAND_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1935 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 205 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_BITNOR_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1941 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 206 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1947 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 207 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_STRING, &(yyloc), (yyvsp[0].pnd));}
#line 1953 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 208 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1959 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 209 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DOT_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1965 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 210 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_POINTER_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1971 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 211 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ADD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1977 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 212 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_SUB_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1983 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 213 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MULT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1989 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 214 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DIV_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1995 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 215 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_EQ_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2001 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 216 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2007 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 217 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2013 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_NE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2019 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 219 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2025 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 220 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2031 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 221 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_AND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2037 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 222 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_OR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2043 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 223 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_BITAND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2049 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 224 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_BITOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2055 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 225 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2061 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 226 "syntax.y" /* yacc.c:1646  */
    {
		yyclearin;
		(yyval.pnd)=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(RB, &(yylsp[-1])));
		yydebug((yylsp[-1]).first_line, (yylsp[-1]).last_column, 1, ERR_MISSING_RB);
	}
#line 2071 "syntax.c" /* yacc.c:1646  */
    break;


#line 2075 "syntax.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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

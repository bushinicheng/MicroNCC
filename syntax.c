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
    AND = 269,
    OR = 270,
    NOT = 271,
    ADD = 272,
    SUB = 273,
    MULT = 274,
    DIV = 275,
    RELOP = 276,
    ASSIGNOP = 277,
    LP = 278,
    RP = 279,
    LB = 280,
    RB = 281,
    LC = 282,
    RC = 283,
    DOT = 284,
    COMMA = 285,
    SEMI = 286,
    POINTER = 287,
    IF = 288,
    DO = 289,
    WHILE = 290,
    FOR = 291,
    RETURN = 292,
    TYPE = 293,
    INT = 294,
    CHAR = 295,
    FLOAT = 296,
    STRUCT = 297,
    NUM = 298,
    STRING = 299,
    ID = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "syntax.y" /* yacc.c:355  */

	Node *pnd;

#line 166 "syntax.c" /* yacc.c:355  */
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

#line 197 "syntax.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    73,    74,    77,    78,    79,    80,    87,
      88,    91,    92,    95,    98,    99,   104,   111,   112,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     130,   134,   141,   142,   145,   146,   152,   153,   156,   157,
     160,   161,   173,   174,   175,   178,   179,   182,   185,   189,
     190,   193,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOWWEST", "LOWWER_THAN_ELSE", "ELSE",
  "LT", "LE", "NE", "EQ", "GE", "GT", "BITAND", "BITOR", "AND", "OR",
  "NOT", "ADD", "SUB", "MULT", "DIV", "RELOP", "ASSIGNOP", "LP", "RP",
  "LB", "RB", "LC", "RC", "DOT", "COMMA", "SEMI", "POINTER", "IF", "DO",
  "WHILE", "FOR", "RETURN", "TYPE", "INT", "CHAR", "FLOAT", "STRUCT",
  "NUM", "STRING", "ID", "$accept", "Program", "ExtDefList", "ExtDef",
  "FuncDec", "DefArgList", "DefArg", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "VarDec", "Specifier",
  "StructSpecifier", "Tag", "OptTag", "ArgList", "Arg", "Exp", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -49

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,    11,   -21,    16,   -45,    40,   -45,    -2,     5,   -45,
      19,   -45,    21,   -45,   -45,    15,    22,     0,    45,    -7,
     -45,   -45,    40,   -19,    79,   -45,   -45,   -45,    31,    -4,
       8,    57,    40,    31,   -45,   -45,    63,    58,    47,   190,
      -4,    50,    51,   190,   -45,    67,   190,    75,    76,    -4,
     -45,   -45,    77,     6,   190,   -45,   119,   -45,   -45,   392,
      78,   -45,   -45,   -45,    40,   -45,    73,    -3,   -45,   -45,
       9,    -4,    68,    -4,    -4,   146,    -4,   -45,   -45,   -45,
      80,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    90,   -45,    95,
     -45,   -45,   -45,   -45,   -45,   230,   120,   257,   284,   -45,
     -45,    94,   112,   392,   -45,    52,    52,   543,   543,    52,
      52,   527,   500,   473,   446,    54,    54,    -3,    -3,   419,
     173,   -45,   -45,   190,    -4,   190,    -4,   -45,    -4,   -45,
     -45,   140,   311,   -45,   338,   -45,   190,   115,    -4,   -45,
     -45,   365,   190,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    42,     0,     0,     2,     3,     6,     0,     0,    43,
      47,    45,     0,     1,     4,    40,     0,     0,    37,    38,
       8,     7,     0,     0,     0,     5,    35,    34,     0,     0,
       0,     0,    33,     0,    44,     9,     0,    12,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
      54,    58,    52,     0,    18,    20,     0,    40,    36,    39,
       0,    46,    32,    10,     0,    13,     0,    57,    55,    56,
       0,     0,     0,     0,     0,     0,     0,    16,    14,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      41,    11,    15,    31,    23,     0,     0,     0,     0,    30,
      22,     0,    50,    51,    29,    67,    68,    69,    66,    71,
      70,    74,    75,    72,    73,    62,    63,    64,    65,    59,
       0,    60,    61,     0,     0,     0,     0,    53,     0,    77,
      76,    24,     0,    26,     0,    49,     0,     0,     0,    25,
      27,     0,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   144,   -45,   -45,    98,   -45,   -45,   -22,   -44,
     135,     3,   141,   -45,   -45,     4,    28,   -45,   -45,    32,
     -45,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    36,    37,    25,    53,    54,
      31,    55,    17,    18,    19,    33,    34,    11,    12,   111,
     112,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    26,    72,     6,     7,    35,    20,    77,     6,     7,
     103,    67,    40,    41,    42,    29,    13,    66,    30,     1,
      75,    70,    96,     2,    10,    32,    97,    38,     8,    99,
       9,    27,    79,     8,    78,    32,    21,   104,    23,    50,
      51,    52,   105,    15,   107,   108,   -48,   113,    22,    24,
     -44,    60,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    38,    91,
      92,    93,    94,    93,    94,    28,    57,    96,     1,    96,
      39,    97,     2,    97,    99,    61,    99,    63,    64,   141,
      71,   143,    65,    68,    69,    40,    41,    42,    73,    74,
      76,   102,   149,   106,   100,   142,    43,   144,   153,   113,
      44,   114,    45,    46,    47,    48,    49,     1,   137,   151,
      80,     2,    50,    51,    52,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   131,    91,    92,    93,    94,
     132,    95,   138,   134,    96,   146,   150,   109,    97,    14,
      98,    99,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,   101,    91,    92,    93,    94,    62,    95,    58,
     145,    96,     0,     0,   139,    97,     0,   110,    99,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,    96,   140,
       0,     0,    97,     0,     0,    99,    40,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,    44,     0,    45,    46,    47,    48,    49,     1,     0,
       0,     0,     2,    50,    51,    52,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,    92,    93,
      94,     0,    95,     0,   133,    96,     0,     0,     0,    97,
       0,     0,    99,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,     0,    95,
       0,   135,    96,     0,     0,     0,    97,     0,     0,    99,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,    96,
       0,     0,     0,    97,     0,   136,    99,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,    92,
      93,    94,     0,    95,     0,   147,    96,     0,     0,     0,
      97,     0,     0,    99,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,    96,     0,     0,     0,    97,     0,   148,
      99,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,     0,    95,     0,   152,
      96,     0,     0,     0,    97,     0,     0,    99,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,    96,     0,     0,
       0,    97,     0,     0,    99,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
       0,     0,     0,     0,    96,     0,     0,     0,    97,     0,
       0,    99,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,    91,    92,    93,    94,     0,     0,     0,
       0,    96,     0,     0,     0,    97,     0,     0,    99,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      91,    92,    93,    94,     0,     0,     0,     0,    96,     0,
       0,     0,    97,     0,     0,    99,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,    91,    92,    93,
      94,     0,     0,     0,     0,    96,     0,     0,     0,    97,
       0,     0,    99,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    81,
      82,     0,    96,    85,    86,     0,    97,     0,     0,    99,
      91,    92,    93,    94,     0,     0,     0,     0,    96,     0,
       0,     0,    97,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      29,     1,    46,     0,     0,    24,     1,     1,     5,     5,
       1,    40,    16,    17,    18,    22,     0,    39,    25,    38,
      49,    43,    25,    42,    45,    22,    29,    23,     0,    32,
      19,    31,    54,     5,    28,    32,    31,    28,    23,    43,
      44,    45,    71,    45,    73,    74,    27,    76,    27,    27,
      45,    43,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    64,    17,
      18,    19,    20,    19,    20,    30,    45,    25,    38,    25,
       1,    29,    42,    29,    32,    28,    32,    24,    30,   133,
      23,   135,    45,    43,    43,    16,    17,    18,    23,    23,
      23,    28,   146,    35,    26,   134,    27,   136,   152,   138,
      31,    31,    33,    34,    35,    36,    37,    38,    24,   148,
       1,    42,    43,    44,    45,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    45,    17,    18,    19,    20,
      45,    22,    30,    23,    25,     5,    31,     1,    29,     5,
      31,    32,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    64,    17,    18,    19,    20,    32,    22,    28,
     138,    25,    -1,    -1,     1,    29,    -1,    31,    32,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    -1,    -1,    25,    26,
      -1,    -1,    29,    -1,    -1,    32,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    43,    44,    45,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    -1,    22,    -1,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    32,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    -1,    22,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,    31,    32,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    -1,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    32,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    31,
      32,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    -1,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    32,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    -1,    -1,    32,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,
      -1,    32,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    -1,    32,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,     6,
       7,    -1,    25,    10,    11,    -1,    29,    -1,    -1,    32,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    42,    47,    48,    49,    57,    61,    62,    19,
      45,    63,    64,     0,    48,    45,    50,    58,    59,    60,
       1,    31,    27,    23,    27,    53,     1,    31,    30,    22,
      25,    56,    57,    61,    62,    24,    51,    52,    61,     1,
      16,    17,    18,    27,    31,    33,    34,    35,    36,    37,
      43,    44,    45,    54,    55,    57,    67,    45,    58,    67,
      43,    28,    56,    24,    30,    45,    54,    67,    43,    43,
      54,    23,    55,    23,    23,    67,    23,     1,    28,    54,
       1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    17,    18,    19,    20,    22,    25,    29,    31,    32,
      26,    51,    28,     1,    28,    67,    35,    67,    67,     1,
      31,    65,    66,    67,    31,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    45,    45,    24,    23,    24,    31,    24,    30,     1,
      26,    55,    67,    55,    67,    65,     5,    24,    31,    55,
      31,    67,    24,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    51,    51,    52,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    62,    62,    63,    64,    65,
      65,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     1,     2,     2,     3,
       4,     3,     1,     2,     3,     4,     3,     2,     1,     2,
       1,     1,     3,     3,     5,     7,     5,     7,     9,     3,
       3,     3,     2,     1,     3,     3,     3,     1,     1,     3,
       1,     4,     1,     2,     1,     2,     5,     1,     1,     3,
       1,     1,     1,     4,     1,     2,     2,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4
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
#line 70 "syntax.y" /* yacc.c:1646  */
    {astroot=build_subast(AST_Program_is_ExtDefList, &(yyloc), (yyvsp[0].pnd));}
#line 1557 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDefList_is_ExtDef, &(yyloc), (yyvsp[0].pnd));}
#line 1563 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDefList_is_ExtDef_ExtDefList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1569 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 77 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDef_is_Specifier_FuncDec_CompSt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1575 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 78 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDef_is_Def, &(yyloc), (yyvsp[0].pnd));}
#line 1581 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDef_is_StructSpecifier_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1587 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 80 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_ExtDef_is_StructSpecifier_SEMI, &(yyloc), (yyvsp[-1].pnd), new_sym_node(SEMI, & (yylsp[-1])));
		logd("%d:%d: error: missing ';'\n", (yyloc).first_line, (yylsp[-1]).last_column);
		}
#line 1596 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 87 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDec_is_ID_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1602 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDec_is_ID_LP_DefArgList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1608 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 91 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefArgList_is_DefArg_COMMA_DefArgList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1614 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefArgList_is_DefArg, &(yyloc), (yyvsp[0].pnd));}
#line 1620 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 95 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefArg_is_Specifier_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1626 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1632 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "syntax.y" /* yacc.c:1646  */
    {
		yyclearin;
		(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));
		logd("%d:%d: error: expected definition or statement here.\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
		}
#line 1642 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(RC, &(yylsp[-1])));
		logd("%d:%d: error: missing '\x7d'\n", (yylsp[0]).last_line, (yylsp[0]).last_column);
		}
#line 1651 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 111 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt_StmtList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1657 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt, &(yyloc), (yyvsp[0].pnd));}
#line 1663 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Exp_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1669 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Def, &(yyloc), (yyvsp[0].pnd));}
#line 1675 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "syntax.y" /* yacc.c:1646  */
    {}
#line 1681 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1687 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1693 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1699 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1705 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1711 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1717 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 124 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt, &(yyloc), (yyvsp[-8].pnd), (yyvsp[-7].pnd), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1723 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 125 "syntax.y" /* yacc.c:1646  */
    {
		yyclearin;
		(yyval.pnd)=build_subast(AST_Stmt_is_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), new_sym_node(SEMI, & (yylsp[-2])));
		logd("%d:%d: error: expected ';' here.\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
	}
#line 1733 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 130 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(SEMI, & (yylsp[-1])));
		logd("%d:%d: error: missing ';'\n", (yyloc).first_line, (yylsp[-1]).last_column);
	}
#line 1742 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 134 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_Stmt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(RC, &(yylsp[-1])));
		logd("%d:%d: error: missing '\x7d'\n", (yyloc).first_line, (yylsp[-1]).last_column);
	}
#line 1751 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 141 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefList_is_Def_DefList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1757 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 142 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DefList_is_Def, &(yyloc), (yyvsp[0].pnd));}
#line 1763 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 145 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Def_is_Specifier_DecList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1769 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 146 "syntax.y" /* yacc.c:1646  */
    {
		(yyval.pnd)=build_subast(AST_Def_is_Specifier_DecList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(SEMI, & (yylsp[-1])));
		logd("%d:%d: error: missing ';'\n", (yyloc).first_line, (yyloc).last_column);
	}
#line 1778 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 152 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DecList_is_Dec_COMMA_DecList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1784 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DecList_is_Dec, &(yyloc), (yyvsp[0].pnd));}
#line 1790 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 156 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Dec_is_VarDec, &(yyloc), (yyvsp[0].pnd));}
#line 1796 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 157 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Dec_is_VarDec_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1802 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 160 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_VarDec_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 1808 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 161 "syntax.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].pnd)->specval == 'f')
		{
			(yyvsp[-1].pnd)->specval = 'i';
			(yyvsp[-1].pnd)->exval.i = (yyvsp[-1].pnd)->exval.f;
			logd("%d: error type A: invalid dim\n", (yyloc).first_line);
		}
		(yyval.pnd)=build_subast(AST_VarDec_is_VarDec_LB_NUM_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));
	}
#line 1822 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 173 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_TYPE, &(yyloc), (yyvsp[0].pnd));}
#line 1828 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 174 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_TYPE_MULT, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1834 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 175 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_StructSpecifier, &(yyloc), (yyvsp[0].pnd));}
#line 1840 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 178 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructSpecifier_is_STRUCT_Tag, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1846 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructSpecifier_is_STRUCT_OptTag_LC_DefList_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1852 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 182 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Tag_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 1858 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 185 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_OptTag_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 1864 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 189 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ArgList_is_Arg_COMMA_ArgList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1870 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 190 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ArgList_is_Arg, &(yyloc), (yyvsp[0].pnd));}
#line 1876 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 193 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Arg_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 1882 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 197 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 1888 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 198 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID_LP_ArgList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1894 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NUM, &(yyloc), (yyvsp[0].pnd));}
#line 1900 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 200 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ADD_NUM, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1906 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 201 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SUB_NUM, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1912 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1918 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 203 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_STRING, &(yyloc), (yyvsp[0].pnd));}
#line 1924 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 204 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1930 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 205 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DOT_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1936 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 206 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_POINTER_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1942 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 207 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ADD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1948 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 208 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_SUB_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1954 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 209 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MULT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1960 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 210 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DIV_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1966 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 211 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_EQ_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1972 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 212 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1978 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 213 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1984 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 214 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_NE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1990 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 215 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1996 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 216 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2002 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_AND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2008 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_OR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2014 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 219 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_BITAND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2020 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 220 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_BITOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2026 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 221 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2032 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 222 "syntax.y" /* yacc.c:1646  */
    {
		yyclearin;
		(yyval.pnd)=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), new_sym_node(RB, &(yylsp[-1])));
		logd("%d:%d: error: missing ']'\n", (yyloc).first_line, (yylsp[-1]).last_column);
	}
#line 2042 "syntax.c" /* yacc.c:1646  */
    break;


#line 2046 "syntax.c" /* yacc.c:1646  */
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

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

int yylex();
int yyerror(const char *str, ...);

extern Node *astroot;

#line 75 "syntax.c" /* yacc.c:339  */

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
    SIZEOF = 261,
    LSHIFT = 262,
    RSHIFT = 263,
    LSHIFTE = 264,
    RSHIFTE = 265,
    LT = 266,
    LE = 267,
    NE = 268,
    EQ = 269,
    GE = 270,
    GT = 271,
    AND = 272,
    OR = 273,
    XOR = 274,
    NOT = 275,
    ANDE = 276,
    ORE = 277,
    XORE = 278,
    LAND = 279,
    LOR = 280,
    LNOT = 281,
    ADD = 282,
    SUB = 283,
    MULT = 284,
    DIV = 285,
    MOD = 286,
    ADDE = 287,
    SUBE = 288,
    MULTE = 289,
    DIVE = 290,
    MODE = 291,
    INC = 292,
    DEC = 293,
    RELOP = 294,
    ASSIGNOP = 295,
    LP = 296,
    RP = 297,
    LB = 298,
    RB = 299,
    LC = 300,
    RC = 301,
    DOT = 302,
    COMMA = 303,
    SEMI = 304,
    POINTER = 305,
    COLON = 306,
    IF = 307,
    DO = 308,
    WHILE = 309,
    FOR = 310,
    RETURN = 311,
    SWITCH = 312,
    CASE = 313,
    BREAK = 314,
    DEFAULT = 315,
    GOTO = 316,
    TYPE = 317,
    VOID = 318,
    BOOL = 319,
    CHAR = 320,
    SHORT = 321,
    INT = 322,
    UNSIGNED = 323,
    FLOAT = 324,
    DOUBLE = 325,
    INT8T = 326,
    INT16T = 327,
    INT32T = 328,
    INT64T = 329,
    UINT8T = 330,
    UINT16T = 331,
    UINT32T = 332,
    UINT64T = 333,
    SIZET = 334,
    OFFT = 335,
    UINTPTRT = 336,
    ENUM = 337,
    UNION = 338,
    STRUCT = 339,
    NUM = 340,
    STRING = 341,
    NIL = 342,
    TRUE = 343,
    FALSE = 344,
    ID = 345
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "syntax.y" /* yacc.c:355  */

	Node *pnd;

#line 210 "syntax.c" /* yacc.c:355  */
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

#line 241 "syntax.c" /* yacc.c:358  */

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
#define YYLAST   1428

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    96,    97,   100,   101,   102,   105,   106,
     110,   113,   116,   117,   120,   121,   125,   126,   129,   130,
     133,   136,   140,   141,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     162,   163,   166,   167,   168,   172,   176,   177,   180,   181,
     184,   185,   188,   189,   190,   202,   203,   204,   207,   208,
     211,   212,   215,   216,   220,   221,   224,   227,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOWWEST", "LOWWER_THAN_ELSE", "ELSE",
  "SIZEOF", "LSHIFT", "RSHIFT", "LSHIFTE", "RSHIFTE", "LT", "LE", "NE",
  "EQ", "GE", "GT", "AND", "OR", "XOR", "NOT", "ANDE", "ORE", "XORE",
  "LAND", "LOR", "LNOT", "ADD", "SUB", "MULT", "DIV", "MOD", "ADDE",
  "SUBE", "MULTE", "DIVE", "MODE", "INC", "DEC", "RELOP", "ASSIGNOP", "LP",
  "RP", "LB", "RB", "LC", "RC", "DOT", "COMMA", "SEMI", "POINTER", "COLON",
  "IF", "DO", "WHILE", "FOR", "RETURN", "SWITCH", "CASE", "BREAK",
  "DEFAULT", "GOTO", "TYPE", "VOID", "BOOL", "CHAR", "SHORT", "INT",
  "UNSIGNED", "FLOAT", "DOUBLE", "INT8T", "INT16T", "INT32T", "INT64T",
  "UINT8T", "UINT16T", "UINT32T", "UINT64T", "SIZET", "OFFT", "UINTPTRT",
  "ENUM", "UNION", "STRUCT", "NUM", "STRING", "NIL", "TRUE", "FALSE", "ID",
  "$accept", "Program", "BlockList", "Block", "IdList", "StructDec",
  "AnonyStructDec", "StructDecVarList", "StructDecVar", "FuncDec",
  "FuncDefArgList", "FuncDefArg", "CompSt", "StmtList", "Stmt", "CaseList",
  "CaseOne", "VarDef", "DecList", "Dec", "Initializer", "VarDec",
  "Specifier", "TypeRef", "StarList", "CommonSpec", "FuncCallArgList",
  "FuncCallArg", "TypeConversion", "Exp", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -51,   -73,   -39,    18,   -73,   -51,   -23,   -73,   -73,   -26,
     -73,   -51,    -4,   -73,   -73,   -73,   -25,     3,     7,   -17,
       6,   -31,   -12,    10,   -51,   -25,   -51,   -73,    15,   -35,
     164,   -73,   -73,   -25,   292,   -24,   -73,   -73,   -73,    11,
      -9,    13,   -73,   -73,    20,    19,   -25,   420,   420,   420,
     420,   -22,   -19,   420,   420,   420,   218,   -73,    27,   164,
      28,    30,   346,    33,    26,   -10,   -73,   -73,   -73,   -73,
     -73,   -11,   -73,    35,   164,   -73,   -25,   420,   549,   -73,
     420,    36,   -73,  1165,    38,   -73,   -25,   -73,   -73,   -51,
      15,   110,  1329,   110,   110,   -73,   -73,   110,   110,   110,
      -7,    74,    89,   593,   420,    67,   420,   255,   -73,   637,
     420,   -73,    73,   379,   -73,   -73,   -73,   -73,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   -73,   -73,   420,   420,
      43,   420,   -73,    44,   681,   -73,   -73,   -73,   -73,   -73,
      89,   -73,   -73,   725,    94,   769,   420,   813,   -73,   857,
     -73,   -73,    95,    90,  1165,  1378,  1378,  1165,  1165,  1354,
    1354,   444,   444,  1354,  1354,  1329,  1247,  1288,  1165,  1165,
    1165,  1206,   112,   285,   285,   110,   110,   110,  1165,  1165,
    1165,  1165,  1165,  1165,   901,   -73,  1165,   -73,   -73,   -73,
     164,   420,   164,   945,   420,    99,   -73,   420,   -73,   140,
     989,   -73,   420,  1033,   -13,   -73,   164,    97,  1077,   420,
     420,   100,   115,   -13,   -73,   -73,   164,  1121,   504,   164,
     -73,   -73,   -73,   164,   164,   -73,   -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    62,     0,     0,     2,     3,    56,    57,     7,     0,
      55,     0,    63,     1,     4,     6,     0,    52,     0,     0,
      47,    48,    56,     0,    13,     0,     0,    52,    53,     0,
       0,     5,    45,     0,     0,     0,    15,    11,    12,     0,
       9,     0,    16,    56,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    82,    71,    72,
      73,    68,    26,     0,    23,    25,     0,     0,     0,    46,
       0,    68,    49,    50,     0,    14,     0,    10,    17,     0,
      20,    83,    79,    80,    81,    76,    77,    78,    86,    87,
       0,     0,    58,     0,     0,     0,     0,     0,    30,     0,
       0,    29,     0,     0,    28,    21,    22,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,    24,     0,     0,    54,     8,    18,    63,    67,
      60,    59,   120,     0,     0,     0,     0,     0,    31,     0,
      32,    69,     0,    65,    66,    88,    89,    94,    95,   110,
     111,   112,   109,   114,   113,   117,   118,   119,    91,    92,
      93,   115,   116,   104,   105,   106,   107,   108,    96,    97,
      98,    99,   100,    90,     0,   102,   101,   103,    51,    61,
       0,     0,     0,     0,     0,     0,    70,     0,   121,    33,
       0,    35,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,    41,    34,    36,     0,     0,     0,     0,
      39,    40,    38,     0,    42,    44,    37,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   151,   -73,    72,    31,   -73,    -1,   -73,   -73,
      75,   -73,   145,   -72,   -58,   -68,   -73,     5,   133,   -73,
     -73,    -8,    24,   -73,     9,   117,   -46,   -73,   -73,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    39,    43,     7,    23,    24,    18,
      44,    45,    72,    73,    74,   232,   233,    75,    19,    20,
      82,    21,    76,   101,   161,    10,   172,   173,    77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,   105,   116,    16,    16,     8,    11,    42,    28,    34,
       8,     1,    35,    91,    92,    93,    94,    40,    13,    97,
      98,    99,   103,    38,     9,    41,    15,     1,   109,     9,
     113,     6,    32,     2,    35,    25,     6,    36,    90,    86,
     114,    26,    22,   117,    29,   230,   154,   231,    25,     2,
      25,    12,    30,    46,    33,    22,    37,    22,    35,    87,
      85,    84,    88,    95,    17,    27,    96,    89,   104,   106,
     163,   107,   165,   167,   110,   111,   169,   113,    40,   174,
     112,   115,   155,   158,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   166,    46,   203,   204,   159,   206,   160,   118,
     119,   164,   170,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   213,   205,   207,   211,   134,   216,   217,   136,
     137,   138,   139,   140,   224,   226,   235,   146,   147,   146,
     147,   239,   219,   149,   221,   149,    14,   150,   156,   150,
     153,   240,   153,    31,   157,   241,    79,   245,   234,   209,
      47,   225,   247,   102,     0,     0,     0,   220,   242,     0,
     223,    48,     0,   174,    49,   246,     0,     0,   228,     0,
      50,    51,    52,    53,     0,   237,   238,     0,     0,     0,
       0,    54,    55,     0,     0,    56,     0,     0,     0,    30,
       0,     0,     0,    57,     0,     0,    58,    59,    60,    61,
      62,    63,     0,    64,    47,    65,     1,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    49,     0,
       0,     0,     0,     0,    50,    51,    52,    53,     2,    66,
      67,    68,    69,    70,    71,    54,    55,     0,     0,    56,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,    49,     0,     0,     0,     0,
       1,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,    54,    55,     0,     0,    56,     0,    47,     0,
       0,     0,   100,    66,    67,    68,    69,    70,    81,    48,
       0,     0,    49,     0,   138,   139,   140,     1,    50,    51,
      52,    53,   146,   147,     0,     0,     0,     0,   149,    54,
      55,     0,   150,    56,     0,   153,     0,    80,     0,     2,
      66,    67,    68,    69,    70,    81,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,     0,     0,     0,
       0,     0,    50,    51,    52,    53,     0,    66,    67,    68,
      69,    70,    81,    54,    55,    47,     0,    56,     0,     0,
       0,     0,     0,     0,     0,   108,    48,     0,     0,    49,
       0,     0,     0,     0,     0,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,    54,    55,     0,     0,
      56,   171,     0,     0,     0,     0,    47,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    81,    48,     0,     0,
      49,     0,     0,     0,     0,     0,    50,    51,    52,    53,
       0,   118,   119,     0,     0,   122,   123,    54,    55,   126,
     127,    56,     0,     0,    66,    67,    68,    69,    70,    81,
       0,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,   146,   147,     0,     0,     0,     0,   149,     0,     0,
       0,   150,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      81,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,   131,   132,   133,   134,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,   148,     0,     0,   149,     0,     0,
       0,   150,   151,     0,   153,   244,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     131,   132,   133,   134,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,   148,
       0,     0,   149,     0,     0,     0,   150,   151,   152,   153,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   131,   132,   133,   134,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,   148,     0,   162,   149,     0,     0,     0,
     150,   151,     0,   153,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   131,   132,
     133,   134,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,   148,     0,     0,
     149,     0,     0,     0,   150,   151,   168,   153,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   131,   132,   133,   134,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,   148,     0,     0,   149,     0,     0,   208,   150,   151,
       0,   153,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,   131,   132,   133,   134,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,   148,     0,   210,   149,     0,
       0,     0,   150,   151,     0,   153,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     131,   132,   133,   134,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,   148,
       0,   212,   149,     0,     0,     0,   150,   151,     0,   153,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   131,   132,   133,   134,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,   148,     0,     0,   149,     0,     0,     0,
     150,   151,   214,   153,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   131,   132,
     133,   134,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,   148,     0,   215,
     149,     0,     0,     0,   150,   151,     0,   153,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   131,   132,   133,   134,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,   148,     0,     0,   149,   218,     0,     0,   150,   151,
       0,   153,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,   131,   132,   133,   134,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,   148,     0,     0,   149,     0,
       0,     0,   150,   151,   222,   153,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     131,   132,   133,   134,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,     0,   148,
       0,   227,   149,     0,     0,     0,   150,   151,     0,   153,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   131,   132,   133,   134,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     0,   148,     0,     0,   149,     0,     0,     0,
     150,   151,   229,   153,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   131,   132,
     133,   134,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,   148,     0,   236,
     149,     0,     0,     0,   150,   151,     0,   153,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   131,   132,   133,   134,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,   148,     0,   243,   149,     0,     0,     0,   150,   151,
       0,   153,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,   131,   132,   133,   134,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,   148,     0,     0,   149,     0,
       0,     0,   150,   118,   119,   153,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,   146,   147,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   118,   119,   153,     0,   122,   123,
     124,   125,   126,   127,   128,     0,   130,     0,     0,     0,
       0,     0,     0,     0,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   118,   119,   153,     0,   122,
     123,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,   146,   147,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   118,   119,   153,     0,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   118,   119,     0,     0,     0,   146,   147,     0,     0,
       0,     0,   149,     0,     0,     0,   150,     0,     0,   153,
       0,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,   146,   147,     0,     0,     0,     0,   149,     0,     0,
       0,   150,     0,     0,   153,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,   146,   147,     0,     0,     0,
       0,   149,     0,     0,     0,   150,     0,     0,   153
};

static const yytype_int16 yycheck[] =
{
      34,    59,    74,    29,    29,     0,    45,    42,    16,    40,
       5,    62,    43,    47,    48,    49,    50,    25,     0,    53,
      54,    55,    56,    24,     0,    26,    49,    62,    62,     5,
      41,     0,    49,    84,    43,    11,     5,    49,    46,    48,
      51,    45,    11,    77,    41,    58,    80,    60,    24,    84,
      26,    90,    45,    29,    48,    24,    46,    26,    43,    46,
      49,    85,    42,    85,    90,    90,    85,    48,    41,    41,
     104,    41,   106,   107,    41,    49,   110,    41,    86,   113,
      90,    46,    44,    90,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   107,    89,   148,   149,    42,   151,    29,     7,
       8,    54,    49,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   166,    90,    90,    41,    24,    42,    48,    27,
      28,    29,    30,    31,    45,     5,    49,    37,    38,    37,
      38,    51,   210,    43,   212,    43,     5,    47,    86,    47,
      50,    46,    50,    18,    89,   233,    33,   239,   226,   160,
       6,   217,   244,    56,    -1,    -1,    -1,   211,   236,    -1,
     214,    17,    -1,   217,    20,   243,    -1,    -1,   222,    -1,
      26,    27,    28,    29,    -1,   229,   230,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    59,     6,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    84,    85,
      86,    87,    88,    89,    90,    37,    38,    -1,    -1,    41,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      62,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    41,    -1,     6,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    17,
      -1,    -1,    20,    -1,    29,    30,    31,    62,    26,    27,
      28,    29,    37,    38,    -1,    -1,    -1,    -1,    43,    37,
      38,    -1,    47,    41,    -1,    50,    -1,    45,    -1,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    85,    86,    87,
      88,    89,    90,    37,    38,     6,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    17,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,     7,     8,    -1,    -1,    11,    12,    37,    38,    15,
      16,    41,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    43,    -1,    -1,
      -1,    47,    48,    -1,    50,    51,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      47,    48,    -1,    50,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    47,    48,    49,    50,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    43,    -1,    -1,    46,    47,    48,
      -1,    50,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    47,    48,    -1,    50,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    47,    48,    -1,    50,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,
      47,    48,    49,    50,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    47,    48,    -1,    50,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    43,    44,    -1,    -1,    47,    48,
      -1,    50,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    43,    -1,
      -1,    -1,    47,    48,    49,    50,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    47,    48,    -1,    50,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,
      47,    48,    49,    50,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    47,    48,    -1,    50,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    47,    48,
      -1,    50,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    43,    -1,
      -1,    -1,    47,     7,     8,    50,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    47,     7,     8,    50,    -1,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,     7,     8,    50,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,     7,     8,    50,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,     7,     8,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,    84,    92,    93,    94,    96,    97,   108,   113,
     116,    45,    90,     0,    93,    49,    29,    90,   100,   109,
     110,   112,    96,    98,    99,   113,    45,    90,   112,    41,
      45,   103,    49,    48,    40,    43,    49,    46,    98,    95,
     112,    98,    42,    96,   101,   102,   113,     6,    17,    20,
      26,    27,    28,    29,    37,    38,    41,    49,    52,    53,
      54,    55,    56,    57,    59,    61,    85,    86,    87,    88,
      89,    90,   103,   104,   105,   108,   113,   119,   120,   109,
      45,    90,   111,   120,    85,    49,    48,    46,    42,    48,
     112,   120,   120,   120,   120,    85,    85,   120,   120,   120,
      84,   114,   116,   120,    41,   105,    41,    41,    49,   120,
      41,    49,    90,    41,    51,    46,   104,   120,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    21,    22,    23,    24,    25,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    40,    43,
      47,    48,    49,    50,   120,    44,    95,   101,    90,    42,
      29,   115,    42,   120,    54,   120,   108,   120,    49,   120,
      49,    42,   117,   118,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,    90,   120,    90,    46,   115,
      42,    41,    42,   120,    49,    42,    42,    48,    44,   105,
     120,   105,    49,   120,    45,   117,     5,    42,   120,    49,
      58,    60,   106,   107,   105,    49,    42,   120,   120,    51,
      46,   106,   105,    42,    51,   104,   105,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    93,    94,    94,    94,    95,    95,
      96,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   107,   107,   107,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     1,     3,     1,
       5,     4,     2,     1,     3,     2,     3,     4,     3,     1,
       2,     3,     2,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     3,     5,     7,     5,     7,     9,     8,     7,
       2,     1,     3,     4,     3,     3,     3,     1,     1,     3,
       1,     3,     1,     2,     4,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     3,     1,     1,     3,     1,     3,
       4,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4
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
#line 93 "syntax.y" /* yacc.c:1646  */
    {astroot=build_subast(AST_Program_is_BlockList, &(yyloc), (yyvsp[0].pnd));}
#line 1830 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_BlockList_is_Block, &(yyloc), (yyvsp[0].pnd));}
#line 1836 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 97 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_BlockList_is_Block_BlockList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1842 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Block_is_Specifier_FuncDec_CompSt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1848 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Block_is_StructDec_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1854 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Block_is_VarDef, &(yyloc), (yyvsp[0].pnd));}
#line 1860 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_IdList_is_VarDec_COMMA_IdList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1866 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_IdList_is_VarDec, &(yyloc), (yyvsp[0].pnd));}
#line 1872 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 110 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDec_is_STRUCT_ID_LC_StructDecVarList_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1878 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_AnonyStructDec_is_STRUCT_LC_StructDecVarList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1884 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 116 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDecVarList_is_StructDecVar_StructDecVarList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1890 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 117 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDecVarList_is_StructDecVar, &(yyloc), (yyvsp[0].pnd));}
#line 1896 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDecVar_is_Specifier_IdList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1902 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 121 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDecVar_is_StructDec_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1908 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 125 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDec_is_ID_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1914 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 126 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDec_is_ID_LP_FuncDefArgList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1920 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDefArgList_is_FuncDefArg_COMMA_FuncDefArgList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1926 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDefArgList_is_FuncDefArg, &(yyloc), (yyvsp[0].pnd));}
#line 1932 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 133 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDefArg_is_Specifier_VarDec, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1938 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1944 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt_StmtList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1950 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 141 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt, &(yyloc), (yyvsp[0].pnd));}
#line 1956 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Exp_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1962 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 145 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_VarDef, &(yyloc), (yyvsp[0].pnd));}
#line 1968 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 146 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_CompSt, &(yyloc), (yyvsp[0].pnd));}
#line 1974 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 147 "syntax.y" /* yacc.c:1646  */
    {}
#line 1980 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 148 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_ID_COLON, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1986 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 149 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_BREAK_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1992 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 150 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1998 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 151 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2004 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 152 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_GOTO_ID_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2010 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2016 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 154 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2022 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 155 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2028 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 156 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2034 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 157 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_Exp_SEMI_Exp_SEMI_Exp_RP_Stmt, &(yyloc), (yyvsp[-8].pnd), (yyvsp[-7].pnd), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2040 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 158 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_VarDef_Exp_SEMI_Exp_RP_Stmt, &(yyloc), (yyvsp[-7].pnd), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2046 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 159 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_SWITCH_LP_Exp_RP_LC_CaseList_RC, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2052 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CaseList_is_CaseOne_CaseList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2058 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CaseList_is_CaseOne, &(yyloc), (yyvsp[0].pnd));}
#line 2064 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 166 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CaseOne_is_CASE_Exp_COLON, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2070 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 167 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CaseOne_is_CASE_Exp_COLON_StmtList, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2076 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 168 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CaseOne_is_DEFAULT_COLON_StmtList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2082 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 172 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_VarDef_is_Specifier_DecList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2088 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 176 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DecList_is_Dec_COMMA_DecList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2094 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 177 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DecList_is_Dec, &(yyloc), (yyvsp[0].pnd));}
#line 2100 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Dec_is_VarDec, &(yyloc), (yyvsp[0].pnd));}
#line 2106 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 181 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Dec_is_VarDec_ASSIGNOP_Initializer, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2112 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 184 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initializer_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 2118 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 185 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initializer_is_LC_Exp_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2124 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 188 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_VarDec_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2130 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 189 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_VarDec_is_MULT_VarDec, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2136 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 190 "syntax.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].pnd)->idtype->cons.suptype == 'f')
		{
			(yyvsp[-1].pnd)->idtype->cons.suptype = 'i';
			(yyvsp[-1].pnd)->idtype->cons.supval.i = (yyvsp[-1].pnd)->idtype->cons.supval.f;
			yyerr("%d: error type A: invalid dim\n", (yyloc).first_line);
		}
		(yyval.pnd)=build_subast(AST_VarDec_is_VarDec_LB_NUM_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));
	}
#line 2150 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_CommonSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2156 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 203 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_StructDec, &(yyloc), (yyvsp[0].pnd));}
#line 2162 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 204 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Specifier_is_AnonyStructDec, &(yyloc), (yyvsp[0].pnd));}
#line 2168 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 207 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeRef_is_CommonSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2174 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 208 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeRef_is_CommonSpec_StarList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2180 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 211 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT, &(yyloc), (yyvsp[0].pnd));}
#line 2186 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 212 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT_StarList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2192 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 215 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CommonSpec_is_TYPE, &(yyloc), (yyvsp[0].pnd));}
#line 2198 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 216 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CommonSpec_is_STRUCT_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2204 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 220 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncCallArgList_is_FuncCallArg_COMMA_FuncCallArgList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2210 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 221 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncCallArgList_is_FuncCallArg, &(yyloc), (yyvsp[0].pnd));}
#line 2216 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 224 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncCallArg_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 2222 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 227 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeConversion_is_LP_TypeRef_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2228 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 231 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2234 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 232 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2240 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 233 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID_LP_FuncCallArgList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2246 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 234 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NIL, &(yyloc), (yyvsp[0].pnd));}
#line 2252 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 235 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_TRUE, &(yyloc), (yyvsp[0].pnd));}
#line 2258 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 236 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_FALSE, &(yyloc), (yyvsp[0].pnd));}
#line 2264 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 237 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NUM, &(yyloc), (yyvsp[0].pnd));}
#line 2270 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 238 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_TypeConversion_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2276 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 239 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ADD_NUM, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2282 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 240 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SUB_NUM, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2288 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 241 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_MULT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2294 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 242 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_AND_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2300 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 243 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2306 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 244 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LNOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2312 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 245 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_STRING, &(yyloc), (yyvsp[0].pnd));}
#line 2318 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 246 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SIZEOF_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2324 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 247 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_INC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2330 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 248 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DEC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2336 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 249 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_INC_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2342 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 250 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_DEC_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2348 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 251 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LSHIFTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2354 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 252 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_RSHIFTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2360 "syntax.c" /* yacc.c:1646  */
    break;

  case 90:
#line 253 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2366 "syntax.c" /* yacc.c:1646  */
    break;

  case 91:
#line 254 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ANDE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2372 "syntax.c" /* yacc.c:1646  */
    break;

  case 92:
#line 255 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ORE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2378 "syntax.c" /* yacc.c:1646  */
    break;

  case 93:
#line 256 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_XORE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2384 "syntax.c" /* yacc.c:1646  */
    break;

  case 94:
#line 257 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LSHIFTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2390 "syntax.c" /* yacc.c:1646  */
    break;

  case 95:
#line 258 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_RSHIFTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2396 "syntax.c" /* yacc.c:1646  */
    break;

  case 96:
#line 259 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ADDE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2402 "syntax.c" /* yacc.c:1646  */
    break;

  case 97:
#line 260 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_SUBE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2408 "syntax.c" /* yacc.c:1646  */
    break;

  case 98:
#line 261 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MULTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2414 "syntax.c" /* yacc.c:1646  */
    break;

  case 99:
#line 262 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DIVE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2420 "syntax.c" /* yacc.c:1646  */
    break;

  case 100:
#line 263 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MODE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2426 "syntax.c" /* yacc.c:1646  */
    break;

  case 101:
#line 264 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_COMMA_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2432 "syntax.c" /* yacc.c:1646  */
    break;

  case 102:
#line 265 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DOT_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2438 "syntax.c" /* yacc.c:1646  */
    break;

  case 103:
#line 266 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_POINTER_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2444 "syntax.c" /* yacc.c:1646  */
    break;

  case 104:
#line 267 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ADD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2450 "syntax.c" /* yacc.c:1646  */
    break;

  case 105:
#line 268 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_SUB_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2456 "syntax.c" /* yacc.c:1646  */
    break;

  case 106:
#line 269 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MULT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2462 "syntax.c" /* yacc.c:1646  */
    break;

  case 107:
#line 270 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DIV_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2468 "syntax.c" /* yacc.c:1646  */
    break;

  case 108:
#line 271 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MOD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2474 "syntax.c" /* yacc.c:1646  */
    break;

  case 109:
#line 272 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_EQ_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2480 "syntax.c" /* yacc.c:1646  */
    break;

  case 110:
#line 273 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2486 "syntax.c" /* yacc.c:1646  */
    break;

  case 111:
#line 274 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2492 "syntax.c" /* yacc.c:1646  */
    break;

  case 112:
#line 275 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_NE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2498 "syntax.c" /* yacc.c:1646  */
    break;

  case 113:
#line 276 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2504 "syntax.c" /* yacc.c:1646  */
    break;

  case 114:
#line 277 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2510 "syntax.c" /* yacc.c:1646  */
    break;

  case 115:
#line 278 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LAND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2516 "syntax.c" /* yacc.c:1646  */
    break;

  case 116:
#line 279 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2522 "syntax.c" /* yacc.c:1646  */
    break;

  case 117:
#line 280 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_AND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2528 "syntax.c" /* yacc.c:1646  */
    break;

  case 118:
#line 281 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_OR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2534 "syntax.c" /* yacc.c:1646  */
    break;

  case 119:
#line 282 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_XOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2540 "syntax.c" /* yacc.c:1646  */
    break;

  case 120:
#line 283 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LP_Exp_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2546 "syntax.c" /* yacc.c:1646  */
    break;

  case 121:
#line 284 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2552 "syntax.c" /* yacc.c:1646  */
    break;


#line 2556 "syntax.c" /* yacc.c:1646  */
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

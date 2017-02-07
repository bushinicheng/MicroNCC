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
    LOWWER_THAN_ELSE = 258,
    ELSE = 259,
    ID = 260,
    NUM = 261,
    STRING = 262,
    LITERAL = 263,
    SIZEOF = 264,
    TYPE_NAME = 265,
    COMMA = 266,
    DOT = 267,
    PTR = 268,
    QOP = 269,
    COLON = 270,
    ASSIGNOP = 271,
    DIVE = 272,
    MULTE = 273,
    MODE = 274,
    ADDE = 275,
    SUBE = 276,
    LSHIFTE = 277,
    RSHIFTE = 278,
    ANDE = 279,
    XORE = 280,
    ORE = 281,
    LAND = 282,
    LOR = 283,
    OR = 284,
    XOR = 285,
    AND = 286,
    EQ = 287,
    NE = 288,
    LT = 289,
    LE = 290,
    GE = 291,
    GT = 292,
    LSHIFT = 293,
    RSHIFT = 294,
    ADD = 295,
    SUB = 296,
    MULT = 297,
    DIV = 298,
    MOD = 299,
    INC = 300,
    DEC = 301,
    LNOT = 302,
    NOT = 303,
    TYPEDEF = 304,
    EXTERN = 305,
    STATIC = 306,
    AUTO = 307,
    REGISTER = 308,
    CONST = 309,
    VOLATILE = 310,
    STRUCT = 311,
    UNION = 312,
    ENUM = 313,
    ELLIPSIS = 314,
    CASE = 315,
    DEFAULT = 316,
    IF = 317,
    SWITCH = 318,
    WHILE = 319,
    DO = 320,
    FOR = 321,
    GOTO = 322,
    CONTINUE = 323,
    BREAK = 324,
    RETURN = 325,
    LC = 326,
    RC = 327,
    LB = 328,
    RB = 329,
    LP = 330,
    RP = 331,
    SEMI = 332,
    TYPE = 333,
    NIL = 334,
    TRUE = 335,
    FALSE = 336,
    CHAR = 337,
    SHORT = 338,
    INT = 339,
    LONG = 340,
    SIGNED = 341,
    UNSIGNED = 342,
    FLOAT = 343,
    DOUBLE = 344,
    VOID = 345,
    BOOL = 346,
    INT8T = 347,
    INT16T = 348,
    INT32T = 349,
    INT64T = 350,
    UINT8T = 351,
    UINT16T = 352,
    UINT32T = 353,
    UINT64T = 354,
    FLOAT32T = 355,
    FLOAT64T = 356,
    SIZET = 357,
    OFFT = 358,
    UINTPTRT = 359,
    TypeQulfr = 360,
    EQUOP = 361,
    RELOP = 362,
    UNARYOP = 363
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "syntax.y" /* yacc.c:355  */

	Node *pnd;

#line 228 "syntax.c" /* yacc.c:355  */
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

#line 259 "syntax.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1906

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  312

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   363

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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   102,   103,   107,   108,   112,   113,   114,
     115,   119,   120,   124,   125,   129,   130,   134,   135,   136,
     137,   141,   142,   146,   147,   151,   152,   153,   154,   158,
     159,   160,   164,   165,   169,   170,   174,   175,   179,   180,
     184,   185,   186,   190,   191,   192,   193,   194,   198,   199,
     203,   204,   208,   209,   213,   214,   215,   216,   217,   218,
     219,   223,   224,   225,   226,   230,   231,   235,   236,   240,
     241,   245,   246,   247,   251,   252,   256,   257,   261,   262,
     263,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     279,   280,   281,   282,   283,   287,   288,   292,   293,   297,
     298,   299,   303,   304,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOWWER_THAN_ELSE", "ELSE", "ID", "NUM",
  "STRING", "LITERAL", "SIZEOF", "TYPE_NAME", "COMMA", "DOT", "PTR", "QOP",
  "COLON", "ASSIGNOP", "DIVE", "MULTE", "MODE", "ADDE", "SUBE", "LSHIFTE",
  "RSHIFTE", "ANDE", "XORE", "ORE", "LAND", "LOR", "OR", "XOR", "AND",
  "EQ", "NE", "LT", "LE", "GE", "GT", "LSHIFT", "RSHIFT", "ADD", "SUB",
  "MULT", "DIV", "MOD", "INC", "DEC", "LNOT", "NOT", "TYPEDEF", "EXTERN",
  "STATIC", "AUTO", "REGISTER", "CONST", "VOLATILE", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "LC", "RC", "LB", "RB",
  "LP", "RP", "SEMI", "TYPE", "NIL", "TRUE", "FALSE", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID", "BOOL",
  "INT8T", "INT16T", "INT32T", "INT64T", "UINT8T", "UINT16T", "UINT32T",
  "UINT64T", "FLOAT32T", "FLOAT64T", "SIZET", "OFFT", "UINTPTRT",
  "TypeQulfr", "EQUOP", "RELOP", "UNARYOP", "$accept", "Program",
  "ExtDeclnList", "ExtDecln", "FuncDef", "ExpList", "DeclnList", "Decln",
  "DeclnSpec", "InitorDeclrList", "InitorDeclr", "TypeSpec", "CompSpec",
  "CompType", "CompDeclnList", "CompDecln", "CompDeclrList", "CompDeclr",
  "EnumSpec", "EnumorList", "Enumor", "Declr", "DirectDeclr", "StarList",
  "TypeQulfrList", "ParaTypeList", "ParaList", "ParaDecln", "IdList",
  "TypeName", "AbstDeclr", "DirectAbstDeclr", "Initor", "InitorList",
  "StmtList", "ExpStmt", "CompSt", "Stmt", "Exp", YY_NULLPTR
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     177,  -107,  -107,   -27,  -107,  -107,    69,    42,  -107,   978,
       6,   177,  -107,  -107,  -107,    39,   978,  -107,   100,  -107,
      29,   -42,     7,  -107,  -107,   -22,   -61,    16,   -54,  -107,
    -107,  -107,  -107,    95,  -107,   214,  -107,   -39,   978,   270,
      29,  -107,    39,  -107,  1626,    14,   -42,  -107,  -107,    16,
      13,    -6,  -107,  -107,    42,  -107,  1581,    29,  -107,   978,
      -2,   705,  -107,    27,  -107,  -107,  -107,  1806,  1825,  1825,
    1825,  1825,  1825,  1825,  1825,  1825,  1825,    31,   -47,   -15,
      34,   424,    35,    86,    43,    46,  1638,  -107,   514,  -107,
    -107,  -107,  -107,  -107,   347,  -107,  -107,   569,  -107,  -107,
     113,  -107,  -107,   620,  -107,  -107,    22,    59,   125,  -107,
      25,    66,  1825,    30,  -107,  -107,   136,  1581,  1825,  -107,
    1299,  -107,  1313,  1825,  -107,    98,   170,   175,  -107,  -107,
    -107,   514,   545,  1493,   947,   947,   545,   545,   545,   545,
     545,   658,   424,  1825,  1825,  1825,   137,   469,   131,  -107,
    -107,  -107,   707,   138,   128,   758,  -107,  -107,  1825,   211,
     212,  1825,  1825,  1825,  1825,  1825,  1825,  1825,  1825,  1825,
    1825,  1825,  1825,  1825,  1825,  1825,  1825,  -107,  -107,  1825,
    1683,  -107,  1825,  1825,  -107,  1703,   127,  -107,    21,  -107,
     134,  -107,   120,   215,  -107,    36,  -107,  1299,  -107,  -107,
     207,  -107,   102,   808,  -107,  1299,  -107,   221,  1825,   161,
     424,  -107,   846,   896,   935,   154,  -107,  -107,   469,   985,
    -107,  -107,   208,   139,  -107,  1825,  -107,  1299,  -107,  -107,
    1036,  1299,  1408,  1370,  1454,  1478,  1493,   668,   668,  1084,
    1084,   947,   947,   545,   545,   545,  1074,  -107,    51,  1299,
    1299,   857,  -107,  1123,  -107,   162,   164,   134,  1748,   750,
    -107,  -107,  -107,  -107,  1825,  1536,  -107,   226,  -107,  1299,
     558,  -107,   424,   424,   424,  1825,  1760,  -107,  -107,  1825,
    -107,  1825,  -107,  -107,  -107,  -107,  -107,  1161,  -107,   167,
    1299,  -107,  -107,  1825,   240,  -107,  -107,  1210,   424,  1249,
    1321,  1299,  -107,  -107,  1299,   424,   171,  -107,   424,  -107,
    -107,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    54,    28,    61,    32,    33,     0,     0,    25,    19,
       0,     2,     3,     5,     6,     0,    17,    26,     0,    27,
       0,    53,     0,    65,    63,    62,    47,     0,     0,    20,
       1,     4,    15,     0,    21,    23,    18,    31,     0,     0,
       0,    13,     0,    10,     0,     0,    52,    66,    64,     0,
      50,     0,    48,    55,     0,    16,     0,     0,     8,     0,
       0,     0,    34,   123,   124,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,     0,   104,
     125,   126,   127,   105,     0,   107,    97,     0,    14,     9,
      23,   123,    57,     0,    74,    60,    73,     0,    67,    69,
       0,     0,     0,     0,    43,    22,     0,     0,     0,    24,
      90,     7,     0,     0,    36,     0,    38,    40,    30,    35,
     109,     0,   146,   140,   142,   143,   141,   138,   139,   145,
     144,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,     0,    76,     0,     0,   103,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,     0,
       0,   106,     0,     0,    56,     0,     0,    71,    78,    72,
      79,    58,     0,     0,    59,     0,    45,    51,    44,    49,
       0,    95,     0,     0,    29,    41,    37,     0,     0,     0,
       0,   118,     0,     0,     0,     0,   101,    99,     0,     0,
     108,   113,     0,    78,    77,     0,   130,   167,   134,   135,
       0,   165,   162,   163,   161,   160,   159,   157,   158,   154,
     155,   152,   153,   149,   150,   151,     0,   132,     0,    11,
     166,   156,    82,     0,    86,     0,     0,    80,     0,     0,
      68,    70,    75,    46,     0,     0,    93,     0,    39,    42,
     147,   117,     0,     0,     0,     0,     0,   100,   148,     0,
     131,     0,   133,    83,    87,    81,    84,     0,    88,     0,
      91,    94,    96,     0,   114,   116,   119,     0,     0,     0,
     164,    12,    85,    89,    92,     0,     0,   121,     0,   115,
     120,   122
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,   238,  -107,  -107,   218,    23,     0,  -107,
     200,  -107,  -107,  -107,   199,   -43,    54,  -107,  -107,   220,
    -106,    61,   -20,     5,  -107,   -44,  -107,    75,  -107,   142,
      12,   -29,  -103,  -107,  -107,    70,   153,   -77,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,   248,    40,    93,    42,    33,
      34,    16,    17,    18,    61,    62,   125,   126,    19,    51,
      52,    20,    21,    22,    25,   255,   108,   109,   110,   154,
     256,   190,   119,   202,    94,   218,    95,    96,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      15,   107,    46,     1,   146,   113,    30,   199,    24,    29,
      49,    15,     1,   123,   201,     3,    36,   157,   129,   104,
       3,    50,    53,    14,     2,   103,     1,     1,   143,   112,
      48,    44,    59,    45,    14,    50,   193,   120,    60,     2,
       3,    50,   130,    41,     1,   106,   142,     1,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    41,    60,
     144,    60,   281,    98,     3,   211,   114,   152,    28,   155,
       4,     5,     6,     7,    26,   124,    35,   195,    23,   129,
      98,     3,     7,    47,     3,     4,     5,     6,   153,   199,
     105,   148,     8,   197,   185,   185,   186,   186,   120,   203,
      39,   194,   198,   100,   205,    37,    54,     8,   263,   145,
     147,   188,   155,   265,     7,   100,    32,     7,   189,     9,
     149,   127,    60,   150,   212,   213,   214,   282,   219,    56,
       2,   153,     1,   271,     9,   191,   192,     2,   196,   227,
      27,   200,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   223,   257,
     246,   249,   292,   250,   251,   224,   253,   187,    46,     3,
     217,    38,    55,    43,   266,   206,     4,     5,     6,   260,
       3,   207,     1,     4,     5,     6,   106,     2,    58,   269,
     208,   188,   106,    99,   257,   294,   295,   296,     8,   219,
     185,   215,   186,   254,   225,     8,   278,   258,   220,   259,
     121,   185,   185,   222,   222,   289,   228,   229,     2,     3,
     262,   307,   106,   264,     2,     9,     1,   223,   309,   275,
      56,   311,     9,     4,     5,     6,   123,   270,   284,   287,
     285,   217,   293,   303,   305,   290,   120,    28,   310,    31,
       3,   278,     7,    57,   115,     8,   297,   299,   122,   106,
     300,   268,   301,     3,     4,     5,     6,   261,   127,   111,
       4,     5,     6,   209,   304,    63,    64,    65,    66,    67,
       2,   185,     9,   222,   254,    39,     8,     0,   276,     0,
       0,     0,     8,     0,     0,     0,     7,     0,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,     9,     0,    72,    73,    74,    75,     9,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    39,    87,     0,     0,    88,     0,    89,     8,    90,
      91,    92,    63,    64,    65,    66,    67,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
       0,     0,    72,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    39,   156,
       0,     0,    88,     0,    89,     8,    90,    91,    92,    63,
      64,    65,    66,    67,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,     0,     0,    72,
      73,    74,    75,     0,   101,    64,    65,    66,    67,     2,
       4,     5,     6,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    39,     0,     0,     0,    88,
      68,    89,     8,    90,    91,    92,     0,     0,     0,    69,
      70,    71,     0,     0,    72,    73,    74,    75,     0,   101,
      64,    65,    66,    67,     2,     4,     5,     6,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    68,   216,     8,    90,    91,
      92,     0,     0,     0,    69,    70,    71,   159,   160,    72,
      73,    74,    75,   101,    64,    65,    66,    67,     0,     0,
       4,     5,     6,     0,     9,     0,     0,     0,     0,     0,
     158,   159,   160,   161,     0,   162,     0,     0,     0,    88,
     177,   178,     8,    90,    91,    92,   163,   164,   165,   166,
     167,   168,   169,     0,     0,    74,    75,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,     9,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,   160,   161,     0,   162,    90,    91,    92,
       0,     0,   179,     0,   180,     0,   181,   163,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,     0,   158,
     159,   160,   161,   210,   162,   182,   183,     0,     0,     0,
     159,   160,     0,     0,     0,   163,   164,   165,   166,   167,
     168,   169,     0,   179,   184,   180,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     2,     0,     0,   158,   159,
     160,   161,     0,   162,     0,     0,   182,   183,     0,     0,
       0,   179,     0,   180,   163,   164,   165,   166,   167,   168,
     169,   179,     0,   180,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,     0,     0,     0,     0,
       2,     4,     5,     6,   182,   183,     0,     0,     0,   158,
     159,   160,   161,     0,   162,   183,     0,   128,     0,     0,
     179,     0,   180,     8,   221,   163,   164,   165,   166,   167,
     168,   169,     0,     0,     0,     0,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     4,     5,     6,     0,
       9,     0,     0,   182,   183,     0,     0,     0,     0,   158,
     159,   160,   161,     0,   162,     0,   288,     0,     8,     0,
       0,   179,     0,   180,   226,   163,   164,   165,   166,   167,
     168,   169,     0,     0,     0,     0,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     9,     0,   158,   159,   160,
     161,     0,   162,     0,   182,   183,     0,     0,     0,   159,
     160,     0,     0,   163,   164,   165,   166,   167,   168,   169,
       0,   179,   267,   180,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,     0,   158,   159,   160,
     161,     0,   162,     0,   182,   183,     0,     0,     0,   179,
       0,   180,   272,   163,   164,   165,   166,   167,   168,   169,
     179,     0,   180,     0,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,     0,     0,   158,   159,   160,   161,
       0,   162,   182,   183,     0,     0,     0,     0,     0,   159,
     160,     0,   163,   164,   165,   166,   167,   168,   169,   179,
       0,   180,   273,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,     0,     0,     0,     0,     2,   174,
     175,   176,   177,   178,     0,     0,   158,   159,   160,   161,
       0,   162,   182,   183,     0,     0,     0,     0,   179,     0,
     180,   274,   163,   164,   165,   166,   167,   168,   169,     0,
     179,     0,   180,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,     4,     5,     6,     0,     0,     0,
       0,   182,   183,     0,     0,     0,     0,   158,   159,   160,
     161,   279,   162,     0,     0,     0,     8,     0,   179,     0,
     180,     0,   277,   163,   164,   165,   166,   167,   168,   169,
       0,     0,     0,     0,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     9,     0,   158,   159,   160,   161,     0,
     162,   182,   183,     0,     0,     0,   159,   160,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,     0,   179,
       0,   180,   170,   171,   172,   173,   174,   175,   176,   177,
     178,     0,     0,     0,   172,   173,   174,   175,   176,   177,
     178,     0,     0,     0,   158,   159,   160,   161,     0,   162,
       0,     0,   182,   183,     0,     0,     0,   179,   280,   180,
     163,   164,   165,   166,   167,   168,   169,   179,     0,   180,
       0,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   158,   159,   160,   161,     0,   162,     0,     0,
     182,   183,     0,     0,     0,     0,     0,     0,   163,   164,
     165,   166,   167,   168,   169,     0,   179,   283,   180,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,   160,   161,     0,   162,     0,     0,   182,
     183,     0,     0,     0,   179,   302,   180,   163,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,     0,     0,
     158,   159,   160,   161,     0,   162,     0,   182,   183,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   179,     0,   180,   306,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,     0,   162,   182,   183,     0,     0,
       0,     0,   179,     2,   180,   308,   163,   164,   165,   166,
     167,   168,   169,   159,   160,   161,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   182,   183,     0,     0,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     4,
       5,     6,   179,     0,   180,     0,     0,     0,     0,     0,
       0,     0,   159,   160,     0,   204,     0,     0,     0,     0,
       0,     8,     0,     0,   179,     0,   180,   163,     0,   165,
     166,   167,   168,   169,     0,   182,   183,     0,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,     9,     0,
     159,   160,     0,     0,     0,     0,     0,     0,   183,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,     0,   179,     0,   180,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,     0,     0,
       0,   179,     0,   180,   166,   167,   168,   169,     0,     0,
     159,   160,   170,   171,   172,   173,   174,   175,   176,   177,
     178,     0,     0,     0,     0,   159,   160,     0,     0,   167,
     168,   169,     0,     0,     0,   183,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   168,   169,   179,     0,   180,
       0,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,   101,    64,    65,    66,    67,     0,     0,   116,     0,
       0,   179,     0,   180,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,   179,    68,   180,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,     0,
       0,    72,    73,    74,    75,   183,   101,    64,    65,    66,
      67,     0,     0,   116,     0,     0,     0,     0,     0,     0,
     183,     0,     0,     0,     0,     0,     0,   117,   291,   118,
       0,    88,    68,     0,     0,    90,    91,    92,     0,     0,
       0,    69,    70,    71,     0,     0,    72,    73,    74,    75,
       0,   101,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,   101,    64,    65,    66,    67,     0,     0,
       0,     0,   117,     0,   118,     0,    88,    68,     0,     0,
      90,    91,    92,     0,     0,     0,    69,    70,    71,    68,
       0,    72,    73,    74,    75,     0,     0,     0,    69,    70,
      71,     0,     0,    72,    73,    74,    75,     0,   101,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
     102,    88,     0,     0,     0,    90,    91,    92,   101,    64,
      65,    66,    67,    88,    68,   151,     0,    90,    91,    92,
       0,     0,     0,    69,    70,    71,     0,     0,    72,    73,
      74,    75,     0,     0,    68,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,     0,     0,    72,    73,
      74,    75,     0,   101,    64,    65,    66,    67,    88,   247,
       0,     0,    90,    91,    92,   101,    64,    65,    66,    67,
       0,     0,     0,     0,     0,     0,     0,   252,    88,    68,
       0,     0,    90,    91,    92,     0,     0,     0,    69,    70,
      71,    68,     0,    72,    73,    74,    75,     0,     0,     0,
      69,    70,    71,     0,     0,    72,    73,    74,    75,     0,
       0,   101,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,   286,    88,     0,     0,     0,    90,    91,    92,
     101,    64,    65,    66,    67,    88,   298,    68,     0,    90,
      91,    92,     0,     0,     0,     0,    69,    70,    71,     0,
       0,    72,    73,    74,    75,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    71,     0,     0,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
       0,    45,    22,     5,    81,    11,     0,   113,     3,     9,
      71,    11,     5,    15,   117,    42,    16,    94,    61,     5,
      42,     5,    76,     0,    10,    44,     5,     5,    75,    16,
      25,    73,    71,    75,    11,     5,    11,    56,    38,    10,
      42,     5,    15,    20,     5,    45,    15,     5,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    35,    59,
      75,    61,    11,    40,    42,   142,    72,    86,     7,    88,
      56,    57,    58,    75,     5,    77,    15,    11,   105,   122,
      57,    42,    75,   105,    42,    56,    57,    58,    88,   195,
      76,     5,    78,   112,    73,    73,    75,    75,   117,   118,
      71,    76,    72,    42,   123,     5,    11,    78,    72,    75,
      75,   106,   131,    11,    75,    54,    77,    75,   106,   105,
      77,    60,   122,    77,   143,   144,   145,    76,   147,    16,
      10,   131,     5,   210,   105,    76,    11,    10,    72,   158,
      71,     5,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   153,   188,
     179,   180,   265,   182,   183,   153,   185,   106,   188,    42,
     147,    71,    77,    20,    72,    77,    56,    57,    58,    59,
      42,    11,     5,    56,    57,    58,   186,    10,    35,   208,
      15,   186,   192,    40,   223,   272,   273,   274,    78,   218,
      73,    64,    75,    76,    76,    78,   225,    73,    77,    75,
      57,    73,    73,    75,    75,   259,     5,     5,    10,    42,
       5,   298,   222,    16,    10,   105,     5,   222,   305,    75,
      16,   308,   105,    56,    57,    58,    15,    76,    76,   258,
      76,   218,    16,    76,     4,   264,   265,   186,    77,    11,
      42,   270,    75,    35,    54,    78,   275,   276,    59,   259,
     279,   207,   281,    42,    56,    57,    58,   192,   207,    49,
      56,    57,    58,   131,   293,     5,     6,     7,     8,     9,
      10,    73,   105,    75,    76,    71,    78,    -1,   218,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,   105,    -1,    45,    46,    47,    48,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    75,    -1,    77,    78,    79,
      80,    81,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    75,    -1,    77,    78,    79,    80,    81,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    45,
      46,    47,    48,    -1,     5,     6,     7,     8,     9,    10,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    75,
      31,    77,    78,    79,    80,    81,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    45,    46,    47,    48,    -1,     5,
       6,     7,     8,     9,    10,    56,    57,    58,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    31,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    40,    41,    42,    12,    13,    45,
      46,    47,    48,     5,     6,     7,     8,     9,    -1,    -1,
      56,    57,    58,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    75,
      45,    46,    78,    79,    80,    81,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    47,    48,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    73,   105,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    -1,    16,    79,    80,    81,
      -1,    -1,    73,    -1,    75,    -1,    77,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    11,
      12,    13,    14,    15,    16,   106,   107,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    73,    74,    75,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    10,    -1,    -1,    11,    12,
      13,    14,    -1,    16,    -1,    -1,   106,   107,    -1,    -1,
      -1,    73,    -1,    75,    27,    28,    29,    30,    31,    32,
      33,    73,    -1,    75,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    56,    57,    58,   106,   107,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    16,   107,    -1,    72,    -1,    -1,
      73,    -1,    75,    78,    77,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    56,    57,    58,    -1,
     105,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    16,    -1,    76,    -1,    78,    -1,
      -1,    73,    -1,    75,    76,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   105,    -1,    11,    12,    13,
      14,    -1,    16,    -1,   106,   107,    -1,    -1,    -1,    12,
      13,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      -1,    73,    74,    75,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    11,    12,    13,
      14,    -1,    16,    -1,   106,   107,    -1,    -1,    -1,    73,
      -1,    75,    76,    27,    28,    29,    30,    31,    32,    33,
      73,    -1,    75,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    11,    12,    13,    14,
      -1,    16,   106,   107,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    27,    28,    29,    30,    31,    32,    33,    73,
      -1,    75,    76,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    10,    42,
      43,    44,    45,    46,    -1,    -1,    11,    12,    13,    14,
      -1,    16,   106,   107,    -1,    -1,    -1,    -1,    73,    -1,
      75,    76,    27,    28,    29,    30,    31,    32,    33,    -1,
      73,    -1,    75,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    78,    -1,    73,    -1,
      75,    -1,    77,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   105,    -1,    11,    12,    13,    14,    -1,
      16,   106,   107,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    -1,    73,
      -1,    75,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,
      -1,    -1,   106,   107,    -1,    -1,    -1,    73,    74,    75,
      27,    28,    29,    30,    31,    32,    33,    73,    -1,    75,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    11,    12,    13,    14,    -1,    16,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    -1,    73,    74,    75,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    -1,    16,    -1,    -1,   106,
     107,    -1,    -1,    -1,    73,    74,    75,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    16,    -1,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    73,    -1,    75,    76,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,   106,   107,    -1,    -1,
      -1,    -1,    73,    10,    75,    76,    27,    28,    29,    30,
      31,    32,    33,    12,    13,    14,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,   106,   107,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    56,
      57,    58,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    73,    -1,    75,    27,    -1,    29,
      30,    31,    32,    33,    -1,   106,   107,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,   105,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    73,    -1,    75,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,
      -1,    73,    -1,    75,    30,    31,    32,    33,    -1,    -1,
      12,    13,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,   107,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    32,    33,    73,    -1,    75,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,     5,     6,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    73,    31,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    45,    46,    47,    48,   107,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    75,    31,    -1,    -1,    79,    80,    81,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    71,    -1,    73,    -1,    75,    31,    -1,    -1,
      79,    80,    81,    -1,    -1,    -1,    40,    41,    42,    31,
      -1,    45,    46,    47,    48,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    45,    46,    47,    48,    -1,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    -1,    79,    80,    81,     5,     6,
       7,     8,     9,    75,    31,    77,    -1,    79,    80,    81,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    45,    46,
      47,    48,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    45,    46,
      47,    48,    -1,     5,     6,     7,     8,     9,    75,    76,
      -1,    -1,    79,    80,    81,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    31,
      -1,    -1,    79,    80,    81,    -1,    -1,    -1,    40,    41,
      42,    31,    -1,    45,    46,    47,    48,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    -1,
      -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    79,    80,    81,
       5,     6,     7,     8,     9,    75,    76,    31,    -1,    79,
      80,    81,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    45,    46,    47,    48,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    79,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    10,    42,    56,    57,    58,    75,    78,   105,
     110,   111,   112,   113,   116,   117,   120,   121,   122,   127,
     130,   131,   132,   105,   132,   133,     5,    71,   130,   117,
       0,   112,    77,   118,   119,   130,   117,     5,    71,    71,
     115,   116,   117,   145,    73,    75,   131,   105,   132,    71,
       5,   128,   129,    76,    11,    77,    16,   115,   145,    71,
     117,   123,   124,     5,     6,     7,     8,     9,    31,    40,
      41,    42,    45,    46,    47,    48,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    72,    75,    77,
      79,    80,    81,   116,   143,   145,   146,   147,   116,   145,
     130,     5,    74,   147,     5,    76,   117,   134,   135,   136,
     137,   128,    16,    11,    72,   119,    12,    71,    73,   141,
     147,   145,   123,    15,    77,   125,   126,   130,    72,   124,
      15,    75,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,    15,    75,    75,    75,   146,    75,     5,    77,
      77,    77,   147,   117,   138,   147,    72,   146,    11,    12,
      13,    14,    16,    27,    28,    29,    30,    31,    32,    33,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    73,
      75,    77,   106,   107,    74,    73,    75,   130,   132,   139,
     140,    76,    11,    11,    76,    11,    72,   147,    72,   129,
       5,   141,   142,   147,    72,   147,    77,    11,    15,   138,
      15,   146,   147,   147,   147,    64,    77,   116,   144,   147,
      77,    77,    75,   132,   139,    76,    76,   147,     5,     5,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,    76,   114,   147,
     147,   147,    74,   147,    76,   134,   139,   140,    73,    75,
      59,   136,     5,    72,    16,    11,    72,    74,   125,   147,
      76,   146,    76,    76,    76,    75,   144,    77,   147,    15,
      74,    11,    76,    74,    76,    76,    74,   147,    76,   134,
     147,    72,   141,    16,   146,   146,   146,   147,    76,   147,
     147,   147,    74,    76,   147,     4,    76,   146,    76,   146,
      77,   146
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   111,   111,   112,   112,   113,   113,   113,
     113,   114,   114,   115,   115,   116,   116,   117,   117,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   121,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   127,   127,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   137,   137,   138,   138,   139,   139,
     139,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     141,   141,   141,   141,   141,   142,   142,   143,   143,   144,
     144,   144,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     4,     3,     3,
       2,     1,     3,     1,     2,     2,     3,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     2,     3,     1,     3,
       1,     2,     3,     4,     5,     5,     6,     2,     1,     3,
       1,     3,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     4,     5,     3,     4,     1,     3,     1,     2,     1,
       2,     1,     2,     3,     1,     1,     2,     1,     3,     2,
       2,     2,     2,     3,     5,     7,     5,     4,     3,     5,
       7,     6,     7,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     4,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     3,     3,     3
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
#line 98 "syntax.y" /* yacc.c:1646  */
    {astroot=build_subast(AST_Program_is_ExtDeclnList, &(yyloc), (yyvsp[0].pnd));}
#line 1986 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "syntax.y" /* yacc.c:1646  */
    {astroot=build_subast(AST_ExtDeclnList_is_ExtDecln, &(yyloc), (yyvsp[0].pnd));}
#line 1992 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDeclnList_is_ExtDeclnList_ExtDecln, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 1998 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDecln_is_FuncDef, &(yyloc), (yyvsp[0].pnd));}
#line 2004 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDecln_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 2010 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_DeclnSpec_Declr_DeclnList_CompSt, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2016 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_DeclnSpec_Declr_CompSt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2022 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_Declr_DeclnList_CompSt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2028 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_Declr_CompSt, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2034 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpList_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 2040 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpList_is_ExpList_COMMA_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2046 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnList_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 2052 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnList_is_DeclnList_Decln, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2058 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Decln_is_DeclnSpec_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2064 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Decln_is_DeclnSpec_InitorDeclrList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2070 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2076 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeSpec_DeclnSpec, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2082 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeQulfr, &(yyloc), (yyvsp[0].pnd));}
#line 2088 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 137 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeQulfr_DeclnSpec, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2094 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclrList_is_InitorDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2100 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclrList_is_InitorDeclrList_COMMA_InitorDeclr, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2106 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclr_is_Declr, &(yyloc), (yyvsp[0].pnd));}
#line 2112 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclr_is_Declr_ASSIGNOP_Initor, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2118 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_TYPE, &(yyloc), (yyvsp[0].pnd));}
#line 2124 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_CompSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2130 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_EnumSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2136 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 154 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_TYPE_NAME, &(yyloc), (yyvsp[0].pnd));}
#line 2142 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 158 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSpec_is_CompType_ID_LC_CompDeclnList_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2148 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 159 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSpec_is_CompType_LC_CompDeclnList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2154 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 160 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSpec_is_CompType_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2160 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompType_is_STRUCT, &(yyloc), (yyvsp[0].pnd));}
#line 2166 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 165 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompType_is_UNION, &(yyloc), (yyvsp[0].pnd));}
#line 2172 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 169 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDeclnList_is_CompDecln, &(yyloc), (yyvsp[0].pnd));}
#line 2178 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 170 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDeclnList_is_CompDeclnList_CompDecln, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2184 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 174 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDecln_is_DeclnSpec_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2190 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 175 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDecln_is_DeclnSpec_CompDeclrList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2196 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDeclrList_is_CompDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2202 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDeclrList_is_CompDeclr_COMMA_CompDeclrList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2208 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 184 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDeclr_is_Declr, &(yyloc), (yyvsp[0].pnd));}
#line 2214 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 185 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDeclr_is_COLON_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2220 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 186 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompDeclr_is_Declr_COLON_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2226 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 190 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_LC_EnumorList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2232 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 191 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_LC_EnumorList_COMMA_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2238 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 192 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2244 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 193 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_ID_LC_EnumorList_COMMA_RC, &(yyloc), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2250 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 194 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2256 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 198 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumorList_is_Enumor, &(yyloc), (yyvsp[0].pnd));}
#line 2262 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumorList_is_EnumorList_COMMA_Enumor, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2268 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 203 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Enumor_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2274 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 204 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Enumor_is_ID_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2280 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 208 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Declr_is_StarList_DirectDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2286 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 209 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Declr_is_DirectDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2292 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 213 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2298 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 214 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_LP_Declr_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2304 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 215 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2310 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 216 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LB_RB, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2316 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 217 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_ParaTypeList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2322 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_IdList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2328 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 219 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2334 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 223 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT, &(yyloc), (yyvsp[0].pnd));}
#line 2340 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 224 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT_TypeQulfrList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2346 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 225 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT_StarList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2352 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 226 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT_TypeQulfrList_StarList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2358 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 230 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfrList_is_TypeQulfr, &(yyloc), (yyvsp[0].pnd));}
#line 2364 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 231 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfrList_is_TypeQulfrList_TypeQulfr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2370 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 235 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaTypeList_is_ParaList, &(yyloc), (yyvsp[0].pnd));}
#line 2376 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 236 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaTypeList_is_ParaList_COMMA_ELLIPSIS, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2382 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 240 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaList_is_ParaDecln, &(yyloc), (yyvsp[0].pnd));}
#line 2388 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 241 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaList_is_ParaList_COMMA_ParaDecln, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2394 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 245 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaDecln_is_DeclnSpec_Declr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2400 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 246 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaDecln_is_DeclnSpec_AbstDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2406 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 247 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaDecln_is_DeclnSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2412 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 251 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_IdList_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2418 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 252 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_IdList_is_IdList_COMMA_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2424 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 256 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeName_is_DeclnSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2430 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 257 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeName_is_DeclnSpec_AbstDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2436 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 261 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_AbstDeclr_is_StarList, &(yyloc), (yyvsp[0].pnd));}
#line 2442 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 262 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_AbstDeclr_is_DirectAbstDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2448 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 263 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_AbstDeclr_is_StarList_DirectAbstDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2454 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 267 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LP_AbstDeclr_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2460 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 268 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LB_RB, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2466 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 269 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LB_Exp_RB, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2472 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 270 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_RB, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2478 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 271 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2484 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 272 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LP_RP, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2490 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 273 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LP_ParaTypeList_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2496 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 274 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2502 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 275 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_ParaTypeList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2508 "syntax.c" /* yacc.c:1646  */
    break;

  case 90:
#line 279 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 2514 "syntax.c" /* yacc.c:1646  */
    break;

  case 91:
#line 280 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_DOT_ID_ASSIGNOP_Exp, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2520 "syntax.c" /* yacc.c:1646  */
    break;

  case 92:
#line 281 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_LB_Exp_RB_ASSIGNOP_Exp, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2526 "syntax.c" /* yacc.c:1646  */
    break;

  case 93:
#line 282 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_LC_InitorList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2532 "syntax.c" /* yacc.c:1646  */
    break;

  case 94:
#line 283 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_LC_InitorList_COMMA_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2538 "syntax.c" /* yacc.c:1646  */
    break;

  case 95:
#line 287 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorList_is_Initor, &(yyloc), (yyvsp[0].pnd));}
#line 2544 "syntax.c" /* yacc.c:1646  */
    break;

  case 96:
#line 288 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorList_is_InitorList_COMMA_Initor, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2550 "syntax.c" /* yacc.c:1646  */
    break;

  case 97:
#line 292 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt, &(yyloc), (yyvsp[0].pnd));}
#line 2556 "syntax.c" /* yacc.c:1646  */
    break;

  case 98:
#line 293 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_StmtList_Stmt, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2562 "syntax.c" /* yacc.c:1646  */
    break;

  case 99:
#line 297 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpStmt_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 2568 "syntax.c" /* yacc.c:1646  */
    break;

  case 100:
#line 298 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpStmt_is_Exp_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2574 "syntax.c" /* yacc.c:1646  */
    break;

  case 101:
#line 299 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpStmt_is_SEMI, &(yyloc), (yyvsp[0].pnd));}
#line 2580 "syntax.c" /* yacc.c:1646  */
    break;

  case 102:
#line 303 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSt_is_LC_RC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2586 "syntax.c" /* yacc.c:1646  */
    break;

  case 103:
#line 304 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2592 "syntax.c" /* yacc.c:1646  */
    break;

  case 104:
#line 308 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_SEMI, &(yyloc), (yyvsp[0].pnd));}
#line 2598 "syntax.c" /* yacc.c:1646  */
    break;

  case 105:
#line 309 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 2604 "syntax.c" /* yacc.c:1646  */
    break;

  case 106:
#line 310 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Exp_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2610 "syntax.c" /* yacc.c:1646  */
    break;

  case 107:
#line 311 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_CompSt, &(yyloc), (yyvsp[0].pnd));}
#line 2616 "syntax.c" /* yacc.c:1646  */
    break;

  case 108:
#line 312 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_GOTO_ID_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2622 "syntax.c" /* yacc.c:1646  */
    break;

  case 109:
#line 313 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_ID_COLON, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2628 "syntax.c" /* yacc.c:1646  */
    break;

  case 110:
#line 314 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_CONTINUE_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2634 "syntax.c" /* yacc.c:1646  */
    break;

  case 111:
#line 315 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_BREAK_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2640 "syntax.c" /* yacc.c:1646  */
    break;

  case 112:
#line 316 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2646 "syntax.c" /* yacc.c:1646  */
    break;

  case 113:
#line 317 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2652 "syntax.c" /* yacc.c:1646  */
    break;

  case 114:
#line 318 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2658 "syntax.c" /* yacc.c:1646  */
    break;

  case 115:
#line 319 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2664 "syntax.c" /* yacc.c:1646  */
    break;

  case 116:
#line 320 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_SWITCH_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2670 "syntax.c" /* yacc.c:1646  */
    break;

  case 117:
#line 321 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_CASE_Exp_COLON_Stmt, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2676 "syntax.c" /* yacc.c:1646  */
    break;

  case 118:
#line 322 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_DEFAULT_COLON_Stmt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2682 "syntax.c" /* yacc.c:1646  */
    break;

  case 119:
#line 323 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2688 "syntax.c" /* yacc.c:1646  */
    break;

  case 120:
#line 324 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2694 "syntax.c" /* yacc.c:1646  */
    break;

  case 121:
#line 325 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_RP_Stmt, &(yyloc), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2700 "syntax.c" /* yacc.c:1646  */
    break;

  case 122:
#line 326 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_Exp_RP_Stmt, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2706 "syntax.c" /* yacc.c:1646  */
    break;

  case 123:
#line 330 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2712 "syntax.c" /* yacc.c:1646  */
    break;

  case 124:
#line 331 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NUM, &(yyloc), (yyvsp[0].pnd));}
#line 2718 "syntax.c" /* yacc.c:1646  */
    break;

  case 125:
#line 332 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NIL, &(yyloc), (yyvsp[0].pnd));}
#line 2724 "syntax.c" /* yacc.c:1646  */
    break;

  case 126:
#line 333 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_TRUE, &(yyloc), (yyvsp[0].pnd));}
#line 2730 "syntax.c" /* yacc.c:1646  */
    break;

  case 127:
#line 334 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_FALSE, &(yyloc), (yyvsp[0].pnd));}
#line 2736 "syntax.c" /* yacc.c:1646  */
    break;

  case 128:
#line 335 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_STRING, &(yyloc), (yyvsp[0].pnd));}
#line 2742 "syntax.c" /* yacc.c:1646  */
    break;

  case 129:
#line 336 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LITERAL, &(yyloc), (yyvsp[0].pnd));}
#line 2748 "syntax.c" /* yacc.c:1646  */
    break;

  case 130:
#line 337 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LP_Exp_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2754 "syntax.c" /* yacc.c:1646  */
    break;

  case 131:
#line 338 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2760 "syntax.c" /* yacc.c:1646  */
    break;

  case 132:
#line 339 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2766 "syntax.c" /* yacc.c:1646  */
    break;

  case 133:
#line 340 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LP_ExpList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2772 "syntax.c" /* yacc.c:1646  */
    break;

  case 134:
#line 341 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DOT_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2778 "syntax.c" /* yacc.c:1646  */
    break;

  case 135:
#line 342 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_PTR_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2784 "syntax.c" /* yacc.c:1646  */
    break;

  case 136:
#line 343 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_INC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2790 "syntax.c" /* yacc.c:1646  */
    break;

  case 137:
#line 344 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DEC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2796 "syntax.c" /* yacc.c:1646  */
    break;

  case 138:
#line 345 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_INC_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2802 "syntax.c" /* yacc.c:1646  */
    break;

  case 139:
#line 346 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_DEC_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2808 "syntax.c" /* yacc.c:1646  */
    break;

  case 140:
#line 347 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_AND_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2814 "syntax.c" /* yacc.c:1646  */
    break;

  case 141:
#line 348 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_MULT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2820 "syntax.c" /* yacc.c:1646  */
    break;

  case 142:
#line 349 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ADD_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2826 "syntax.c" /* yacc.c:1646  */
    break;

  case 143:
#line 350 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SUB_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2832 "syntax.c" /* yacc.c:1646  */
    break;

  case 144:
#line 351 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2838 "syntax.c" /* yacc.c:1646  */
    break;

  case 145:
#line 352 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LNOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2844 "syntax.c" /* yacc.c:1646  */
    break;

  case 146:
#line 353 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SIZEOF_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2850 "syntax.c" /* yacc.c:1646  */
    break;

  case 147:
#line 354 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SIZEOF_LP_TypeName_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2856 "syntax.c" /* yacc.c:1646  */
    break;

  case 148:
#line 355 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LP_TypeName_RP_Exp, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2862 "syntax.c" /* yacc.c:1646  */
    break;

  case 149:
#line 356 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MULT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2868 "syntax.c" /* yacc.c:1646  */
    break;

  case 150:
#line 357 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DIV_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2874 "syntax.c" /* yacc.c:1646  */
    break;

  case 151:
#line 358 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MOD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2880 "syntax.c" /* yacc.c:1646  */
    break;

  case 152:
#line 359 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ADD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2886 "syntax.c" /* yacc.c:1646  */
    break;

  case 153:
#line 360 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_SUB_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2892 "syntax.c" /* yacc.c:1646  */
    break;

  case 154:
#line 361 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LSHIFT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2898 "syntax.c" /* yacc.c:1646  */
    break;

  case 155:
#line 362 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_RSHIFT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2904 "syntax.c" /* yacc.c:1646  */
    break;

  case 156:
#line 363 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_RELOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2910 "syntax.c" /* yacc.c:1646  */
    break;

  case 157:
#line 364 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_EQ_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2916 "syntax.c" /* yacc.c:1646  */
    break;

  case 158:
#line 365 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_NE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2922 "syntax.c" /* yacc.c:1646  */
    break;

  case 159:
#line 366 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_AND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2928 "syntax.c" /* yacc.c:1646  */
    break;

  case 160:
#line 367 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_XOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2934 "syntax.c" /* yacc.c:1646  */
    break;

  case 161:
#line 368 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_OR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2940 "syntax.c" /* yacc.c:1646  */
    break;

  case 162:
#line 369 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LAND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2946 "syntax.c" /* yacc.c:1646  */
    break;

  case 163:
#line 370 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2952 "syntax.c" /* yacc.c:1646  */
    break;

  case 164:
#line 371 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_QOP_Exp_COLON_Exp, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2958 "syntax.c" /* yacc.c:1646  */
    break;

  case 165:
#line 372 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2964 "syntax.c" /* yacc.c:1646  */
    break;

  case 166:
#line 373 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_EQUOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2970 "syntax.c" /* yacc.c:1646  */
    break;

  case 167:
#line 374 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_COMMA_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2976 "syntax.c" /* yacc.c:1646  */
    break;


#line 2980 "syntax.c" /* yacc.c:1646  */
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

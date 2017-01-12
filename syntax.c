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
    CHAR = 311,
    SHORT = 312,
    INT = 313,
    LONG = 314,
    SIGNED = 315,
    UNSIGNED = 316,
    FLOAT = 317,
    DOUBLE = 318,
    VOID = 319,
    STRUCT = 320,
    UNION = 321,
    ENUM = 322,
    ELLIPSIS = 323,
    CASE = 324,
    DEFAULT = 325,
    IF = 326,
    SWITCH = 327,
    WHILE = 328,
    DO = 329,
    FOR = 330,
    GOTO = 331,
    CONTINUE = 332,
    BREAK = 333,
    RETURN = 334,
    LC = 335,
    RC = 336,
    LB = 337,
    RB = 338,
    LP = 339,
    RP = 340,
    SEMI = 341,
    BOOL = 342,
    INT8T = 343,
    INT16T = 344,
    INT32T = 345,
    INT64T = 346,
    UINT8T = 347,
    UINT16T = 348,
    UINT32T = 349,
    UINT64T = 350,
    SIZET = 351,
    UINTPTRT = 352,
    OFFT = 353,
    NIL = 354,
    TRUE = 355,
    FALSE = 356
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "syntax.y" /* yacc.c:355  */

	Node *pnd;

#line 221 "syntax.c" /* yacc.c:355  */
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

#line 252 "syntax.c" /* yacc.c:358  */

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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  360

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

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
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   102,   103,   107,   108,   112,   113,   114,
     115,   119,   120,   124,   125,   129,   130,   134,   135,   136,
     137,   141,   142,   146,   147,   151,   152,   153,   154,   155,
     156,   157,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   188,   189,   190,   194,
     195,   199,   200,   204,   205,   209,   210,   211,   212,   216,
     217,   221,   222,   223,   227,   228,   229,   233,   234,   238,
     239,   243,   244,   248,   249,   250,   251,   252,   253,   254,
     258,   259,   260,   261,   265,   266,   270,   271,   275,   276,
     280,   281,   282,   286,   287,   291,   292,   296,   297,   298,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   314,
     315,   316,   317,   321,   322,   326,   327,   331,   332,   333,
     337,   338,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420
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
  "STATIC", "AUTO", "REGISTER", "CONST", "VOLATILE", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID", "STRUCT",
  "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "LC", "RC", "LB",
  "RB", "LP", "RP", "SEMI", "BOOL", "INT8T", "INT16T", "INT32T", "INT64T",
  "UINT8T", "UINT16T", "UINT32T", "UINT64T", "SIZET", "UINTPTRT", "OFFT",
  "NIL", "TRUE", "FALSE", "$accept", "Program", "ExtDeclnList", "ExtDecln",
  "FuncDef", "ExpList", "Decln", "DeclnList", "DeclnSpec",
  "InitorDeclrList", "InitorDeclr", "TypeQulfr", "TypeSpec", "CompSpec",
  "CompType", "StructDeclnList", "StructDecln", "SpecQulfrList",
  "StructDeclrList", "StructDeclr", "EnumSpec", "EnumorList", "Enumor",
  "Declr", "DirectDeclr", "StarList", "TypeQulfrList", "ParaTypeList",
  "ParaList", "ParaDecln", "IdList", "TypeName", "AbstDeclr",
  "DirectAbstDeclr", "Initor", "InitorList", "StmtList", "ExpStmt",
  "CompSt", "Stmt", "Exp", YY_NULLPTR
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
     355,   356
};
# endif

#define YYPACT_NINF -171

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-171)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1076,  -171,  -171,   165,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,     1,    31,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,    24,  1076,  -171,  -171,
    -171,    16,  1604,  1604,  -171,    18,  -171,  1313,   -29,    33,
    -171,  -171,   165,   -36,    45,   -24,  -171,  -171,  -171,    -4,
    -171,  1255,  -171,  -171,   -18,  1604,   274,  -171,  1313,    16,
    -171,   190,  1139,   -29,  -171,  -171,    45,    52,    -3,  -171,
    -171,    31,  -171,   734,  1313,  -171,  1604,  1604,  1604,  1371,
    -171,     4,    59,  -171,  -171,  -171,   941,   960,   960,   960,
     960,   960,   960,   960,   960,   960,    65,    12,    28,    75,
     468,    77,   158,    80,    81,   752,  -171,   636,  -171,  -171,
    -171,  -171,  -171,   371,  -171,  -171,  1692,  -171,  -171,   148,
    -171,  -171,  2370,  -171,  -171,   109,    85,   160,  -171,    14,
      30,   960,    45,  -171,  -171,   734,   960,  -171,  2849,  -171,
    1429,  -171,  -171,  -171,  -171,   960,  -171,    11,  -171,   154,
    -171,   636,   143,  3122,   591,   591,   143,   143,   143,   143,
     143,  2444,   468,   960,   960,   960,    99,   565,    87,  -171,
    -171,  -171,  1768,   -30,    90,  1920,  -171,  -171,   960,   171,
     173,   960,   960,   960,   960,   960,   960,   960,   960,   960,
     960,   960,   960,   960,   960,   960,   960,   960,   960,   960,
     960,   960,   960,   960,   960,   960,   960,   960,   960,   960,
     960,  -171,  -171,   960,   814,  -171,  -171,   834,  1013,  -171,
       5,  -171,   -17,  -171,  1487,   175,  -171,  -171,  2849,  -171,
    -171,    84,  2518,  -171,  2849,    78,  -171,   960,   101,   468,
    -171,  1995,  2070,  2145,   100,  -171,  -171,   565,  1844,  -171,
    -171,  1197,    -5,  -171,   960,  -171,  2849,  -171,  -171,  2592,
    2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,  2849,
    2849,  2998,  2942,  3033,  3087,  3122,  1141,  1141,  1007,  1007,
    1007,  1007,  1256,  1256,   591,   591,   143,   143,   143,  2666,
    -171,    73,  2849,  -171,  2740,  -171,   123,   124,   -17,   861,
    1546,  -171,  -171,  -171,   707,  -171,   185,  -171,  2849,     9,
    -171,   468,   468,   468,   960,   879,  -171,  -171,   960,  -171,
     960,  -171,  -171,  -171,  -171,  -171,  2814,  -171,   125,  -171,
    -171,   960,   207,  -171,  -171,  2220,   468,  2295,  2907,  2849,
    -171,  -171,  2849,   468,   136,  -171,   468,  -171,  -171,  -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    55,    90,    25,    26,    27,    28,    29,    30,
      31,    34,    35,    36,    37,    40,    41,    38,    39,    32,
      59,    60,     0,     0,    33,    42,    43,    44,    45,    46,
      47,    48,    49,    51,    50,    52,     0,     2,     3,     5,
       6,     0,    19,    17,    53,     0,    54,     0,    82,     0,
      94,    92,    91,    76,     0,     0,     1,     4,    13,     0,
      21,    23,    20,    18,    58,     0,     0,    15,     0,     0,
      10,     0,     0,    81,    95,    93,     0,    79,     0,    77,
      84,     0,    14,     0,     0,     8,     0,    68,    66,     0,
      61,     0,   151,   152,   156,   157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,   132,   153,
     154,   155,   133,     0,   135,   125,     0,    16,     9,    23,
     151,    86,     0,   103,    89,   102,     0,    96,    98,     0,
       0,     0,     0,    74,    22,     0,     0,    24,   119,     7,
       0,    67,    65,    57,    62,     0,    63,     0,    69,    71,
     137,     0,   174,   168,   170,   171,   169,   166,   167,   173,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   140,     0,   105,     0,     0,   131,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   165,     0,     0,   134,    85,     0,     0,   100,
     107,   101,   108,    87,     0,     0,    88,    75,    80,    78,
     123,     0,     0,    56,    72,     0,    64,     0,     0,     0,
     146,     0,     0,     0,     0,   129,   127,     0,     0,   136,
     141,     0,   107,   106,     0,   158,   207,   162,   163,     0,
     196,   198,   197,   199,   200,   201,   202,   203,   204,   205,
     206,   193,   194,   192,   191,   190,   188,   189,   184,   186,
     187,   185,   182,   183,   180,   181,   177,   178,   179,     0,
     160,     0,    11,   111,     0,   115,     0,     0,   109,     0,
       0,    97,    99,   104,     0,   121,     0,    70,    73,   175,
     145,     0,     0,     0,     0,     0,   128,   176,     0,   159,
       0,   161,   112,   116,   110,   113,     0,   117,     0,   122,
     124,     0,   142,   144,   147,     0,     0,     0,   195,    12,
     114,   118,   120,     0,     0,   149,     0,   143,   148,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,   186,  -171,  -171,     2,   163,     0,  -171,
     159,   116,   761,  -171,  -171,   140,   -49,    95,  -171,    -2,
    -171,   166,   104,    25,   -45,    17,  -171,   -69,  -171,    13,
    -171,    89,  -124,  -170,  -140,  -171,  -171,    -9,   145,   -59,
     -70
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    36,    37,    38,    39,   301,   122,    68,    69,    59,
      60,    42,    43,    44,    45,    89,    90,    91,   157,   158,
      46,    78,    79,    47,    48,    49,    52,   306,   137,   138,
     139,   184,   307,   232,   147,   241,   123,   257,   124,   125,
     126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      41,   132,    40,   136,    73,   240,    53,    81,   142,     1,
       1,   231,     3,   148,   130,    93,    94,    95,    96,   155,
      51,     1,   245,    64,    56,   235,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     1,    41,     1,    40,
     154,   142,    62,    63,    76,   182,     3,   185,    55,    67,
      77,   176,   227,    71,   261,    72,   103,   104,     3,   263,
     308,    80,    86,    67,   187,   309,    61,   310,   141,    75,
     127,   238,   135,     3,   160,   148,   242,   227,   143,   261,
     172,    54,    82,     1,   330,   244,   127,   227,    23,   228,
     156,   185,   308,   155,   129,   314,   173,   246,    65,   236,
      23,   154,    58,   251,   252,   253,   129,   258,   119,   120,
     121,   237,   174,   250,     1,    23,   159,    23,   266,    50,
       3,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     3,   230,   299,   302,   189,   190,   304,   331,   175,
     229,   177,    23,   178,    83,   315,   179,   180,    74,   247,
     233,   234,   254,   259,   340,   264,   267,   318,   268,   256,
     313,    87,   151,   152,   324,    73,   319,   258,   221,   222,
     320,   227,    70,   228,   327,   130,    93,    94,    95,    96,
     262,   341,    87,    87,    87,    87,    85,     3,   333,   334,
     351,   353,   183,   128,     4,     5,     6,     7,     8,     9,
      10,    97,   358,    57,    84,   223,   150,   224,   135,   149,
      98,    99,   100,    87,   135,   101,   102,   103,   104,   336,
     144,   338,   140,   317,   148,   230,   239,   312,   325,   327,
     248,     0,     0,    55,   345,   347,   183,     0,   348,   256,
     349,   135,   342,   343,   344,     0,    87,     0,     0,     0,
     159,   352,     0,   131,   117,     0,     0,    87,   262,    92,
      93,    94,    95,    96,     2,     0,     0,   355,     0,   119,
     120,   121,     0,     0,   357,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
     135,     0,     0,     0,    98,    99,   100,     0,     0,   101,
     102,   103,   104,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    66,   116,     0,     0,   117,     0,
     118,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   119,   120,   121,    92,    93,    94,    95,
      96,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,     0,   101,   102,   103,   104,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    66,   186,     0,     0,   117,     0,   118,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     119,   120,   121,    92,    93,    94,    95,    96,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,     0,   101,   102,   103,   104,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    66,     0,
       0,     0,   117,     0,   118,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   119,   120,   121,
     130,    93,    94,    95,    96,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,   189,   190,    98,    99,   100,     0,     0,
     101,   102,   103,   104,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   218,   219,   220,   221,   222,     0,     0,
       0,   130,    93,    94,    95,    96,     2,     0,     0,   117,
       0,   255,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   119,   120,   121,    97,     0,     0,
       0,     0,     0,   223,     0,   224,    98,    99,   100,     0,
       0,   101,   102,   103,   104,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,   130,    93,    94,    95,    96,     0,     0,     0,
     117,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   119,   120,   121,    97,   130,
      93,    94,    95,    96,     0,     0,     0,    98,    99,   100,
       0,     0,   101,   102,   103,   104,     0,   130,    93,    94,
      95,    96,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,     0,   101,
     102,   103,   104,    97,     0,     0,     0,   145,   339,   146,
       0,   117,    98,    99,   100,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,     0,     0,   145,     0,   146,     0,   117,   130,
      93,    94,    95,    96,     0,     0,    88,     0,     0,     0,
       0,     0,     0,   119,   120,   121,   117,     0,   181,   130,
      93,    94,    95,    96,     0,    97,     0,    88,    88,    88,
      88,   119,   120,   121,    98,    99,   100,     0,     0,   101,
     102,   103,   104,     0,     0,    97,   130,    93,    94,    95,
      96,     0,     0,     0,    98,    99,   100,     0,    88,   101,
     102,   103,   104,     0,   130,    93,    94,    95,    96,     0,
       0,     0,    97,     0,     0,     0,     0,     0,   117,   300,
       0,    98,    99,   100,     0,     0,   101,   102,   103,   104,
      97,    88,     0,   119,   120,   121,     0,   303,   117,    98,
      99,   100,    88,     0,   101,   102,   103,   104,     0,     0,
       0,     0,     0,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,   335,   117,   130,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   120,   121,   117,   346,   130,    93,    94,    95,    96,
       0,     0,    97,     0,     0,     0,     0,     0,   119,   120,
     121,    98,    99,   100,     0,     0,   101,   102,   103,   104,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,     0,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   189,
     190,     0,     0,     2,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   120,   121,     0,   117,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     0,     3,     0,     0,     0,   119,
     120,   121,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     1,     0,     0,     0,     0,     2,     0,     0,   223,
       0,   224,     0,     0,     0,   227,     0,   228,   305,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   133,     0,     0,     0,     0,     2,
       0,     0,     0,   189,   190,     0,     0,     0,     0,     0,
      23,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,   134,   224,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     3,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     2,     0,     0,   189,   190,
       0,    83,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   261,   305,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   216,   217,   218,   219,
     220,   221,   222,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,   223,     0,
     224,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   311,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   337,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   188,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,   224,     0,   225,   188,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     223,     0,   224,     0,   260,   188,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,   224,     0,
     326,   188,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,     0,   224,   265,   188,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,     0,   224,
     321,   188,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,     0,   224,   322,   188,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,     0,   224,
     323,   188,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,     0,   224,   354,   188,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,     0,   224,
     356,   188,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,   226,   224,   188,   189,   190,   191,   249,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,   224,   188,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     223,   316,   224,   188,   189,   190,   191,   328,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,   224,   188,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   223,   329,
     224,   188,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,   332,   224,   188,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   350,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,     0,   224,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   189,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,   224,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   189,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   223,     0,   224,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   189,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,   224
};

static const yytype_int16 yycheck[] =
{
       0,    71,     0,    72,    49,   145,     5,    11,    11,     5,
       5,   135,    42,    83,     5,     6,     7,     8,     9,    15,
       3,     5,    11,     5,     0,    11,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     5,    37,     5,    37,
      89,    11,    42,    43,    80,   115,    42,   117,    23,    47,
       5,   110,    82,    82,    84,    84,    47,    48,    42,   183,
     230,    85,    80,    61,   123,    82,    41,    84,    16,    52,
      68,   141,    72,    42,    15,   145,   146,    82,    81,    84,
      15,    80,    86,     5,    11,   155,    84,    82,    84,    84,
      86,   161,   262,    15,    69,    11,    84,    86,    80,    85,
      84,   150,    86,   173,   174,   175,    81,   177,    99,   100,
     101,    81,    84,   172,     5,    84,    91,    84,   188,     3,
      42,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    42,   135,   223,   224,    12,    13,   227,    85,    84,
     135,    84,    84,     5,    16,    81,    86,    86,    52,    15,
      85,    11,    73,    86,   314,    85,     5,   247,     5,   177,
       5,    65,    87,    88,    84,   230,    85,   257,    45,    46,
     249,    82,    47,    84,   264,     5,     6,     7,     8,     9,
     183,    16,    86,    87,    88,    89,    61,    42,    85,    85,
      85,     4,   117,    68,    49,    50,    51,    52,    53,    54,
      55,    31,    86,    37,    61,    82,    86,    84,   228,    84,
      40,    41,    42,   117,   234,    45,    46,    47,    48,   309,
      81,   310,    76,   245,   314,   228,   142,   234,   257,   319,
     161,    -1,    -1,   228,   324,   325,   161,    -1,   328,   257,
     330,   261,   321,   322,   323,    -1,   150,    -1,    -1,    -1,
     245,   341,    -1,    83,    84,    -1,    -1,   161,   261,     5,
       6,     7,     8,     9,    10,    -1,    -1,   346,    -1,    99,
     100,   101,    -1,    -1,   353,    -1,    -1,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
     310,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    40,    41,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    42,    43,    44,    45,    46,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    -1,    -1,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    31,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,    40,    41,    42,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      84,    -1,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    31,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    45,    46,    47,    48,    -1,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    45,
      46,    47,    48,    31,    -1,    -1,    -1,    80,    81,    82,
      -1,    84,    40,    41,    42,    -1,    -1,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,     5,
       6,     7,     8,     9,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,    84,    -1,    86,     5,
       6,     7,     8,     9,    -1,    31,    -1,    86,    87,    88,
      89,    99,   100,   101,    40,    41,    42,    -1,    -1,    45,
      46,    47,    48,    -1,    -1,    31,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    40,    41,    42,    -1,   117,    45,
      46,    47,    48,    -1,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      31,   150,    -1,    99,   100,   101,    -1,    83,    84,    40,
      41,    42,   161,    -1,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,    84,    85,     5,     6,     7,     8,     9,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    12,
      13,    -1,    -1,    10,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,    -1,    84,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    42,    -1,    -1,    -1,    99,
     100,   101,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    82,    -1,    84,    85,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     5,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    85,    84,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    10,    -1,    -1,    12,    13,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    85,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    40,    41,    42,    43,
      44,    45,    46,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    82,    -1,
      84,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    -1,    86,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    84,    -1,    86,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    -1,
      86,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    85,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,
      85,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    85,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,
      85,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    85,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,
      85,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    84,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    10,    42,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    84,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   103,   104,   105,   106,
     108,   110,   113,   114,   115,   116,   122,   125,   126,   127,
     113,   127,   128,     5,    80,   125,     0,   105,    86,   111,
     112,   125,   110,   110,     5,    80,    80,   108,   109,   110,
     140,    82,    84,   126,   113,   127,    80,     5,   123,   124,
      85,    11,    86,    16,   109,   140,    80,   113,   114,   117,
     118,   119,     5,     6,     7,     8,     9,    31,    40,    41,
      42,    45,    46,    47,    48,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    81,    84,    86,    99,
     100,   101,   108,   138,   140,   141,   142,   108,   140,   125,
       5,    83,   142,     5,    85,   110,   129,   130,   131,   132,
     123,    16,    11,    81,   112,    80,    82,   136,   142,   140,
     117,   119,   119,    81,   118,    15,    86,   120,   121,   125,
      15,    84,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,    15,    84,    84,    84,   141,    84,     5,    86,
      86,    86,   142,   119,   133,   142,    81,   141,    11,    12,
      13,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    82,    84,    86,    83,    82,    84,   125,
     127,   134,   135,    85,    11,    11,    85,    81,   142,   124,
     136,   137,   142,    81,   142,    11,    86,    15,   133,    15,
     141,   142,   142,   142,    73,    86,   108,   139,   142,    86,
      86,    84,   127,   134,    85,    85,   142,     5,     5,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
      85,   107,   142,    83,   142,    85,   129,   134,   135,    82,
      84,    68,   131,     5,    11,    81,    83,   121,   142,    85,
     141,    85,    85,    85,    84,   139,    86,   142,    15,    83,
      11,    85,    83,    85,    85,    83,   142,    85,   129,    81,
     136,    16,   141,   141,   141,   142,    85,   142,   142,   142,
      83,    85,   142,     4,    85,   141,    85,   141,    86,   141
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   104,   105,   105,   106,   106,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   121,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   136,
     136,   136,   136,   137,   137,   138,   138,   139,   139,   139,
     140,   140,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     4,     3,     3,
       2,     1,     3,     2,     3,     1,     2,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       5,     3,     4,     1,     3,     1,     2,     1,     2,     1,
       2,     3,     1,     1,     2,     1,     3,     2,     2,     2,
       2,     3,     5,     7,     5,     4,     3,     5,     7,     6,
       7,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     4,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3
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
#line 2264 "syntax.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "syntax.y" /* yacc.c:1646  */
    {astroot=build_subast(AST_ExtDeclnList_is_ExtDecln, &(yyloc), (yyvsp[0].pnd));}
#line 2270 "syntax.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDeclnList_is_ExtDeclnList_ExtDecln, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2276 "syntax.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDecln_is_FuncDef, &(yyloc), (yyvsp[0].pnd));}
#line 2282 "syntax.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExtDecln_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 2288 "syntax.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_DeclnSpec_Declr_DeclnList_CompSt, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2294 "syntax.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_DeclnSpec_Declr_CompSt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2300 "syntax.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_Declr_DeclnList_CompSt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2306 "syntax.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_FuncDef_is_Declr_CompSt, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2312 "syntax.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpList_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 2318 "syntax.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpList_is_ExpList_COMMA_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2324 "syntax.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Decln_is_DeclnSpec_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2330 "syntax.c" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Decln_is_DeclnSpec_InitorDeclrList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2336 "syntax.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnList_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 2342 "syntax.c" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnList_is_DeclnList_Decln, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2348 "syntax.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2354 "syntax.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeSpec_DeclnSpec, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2360 "syntax.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeQulfr, &(yyloc), (yyvsp[0].pnd));}
#line 2366 "syntax.c" /* yacc.c:1646  */
    break;

  case 20:
#line 137 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DeclnSpec_is_TypeQulfr_DeclnSpec, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2372 "syntax.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclrList_is_InitorDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2378 "syntax.c" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclrList_is_InitorDeclrList_COMMA_InitorDeclr, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2384 "syntax.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclr_is_Declr, &(yyloc), (yyvsp[0].pnd));}
#line 2390 "syntax.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorDeclr_is_Declr_ASSIGNOP_Initor, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2396 "syntax.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfr_is_TYPEDEF, &(yyloc), (yyvsp[0].pnd));}
#line 2402 "syntax.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfr_is_EXTERN, &(yyloc), (yyvsp[0].pnd));}
#line 2408 "syntax.c" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfr_is_STATIC, &(yyloc), (yyvsp[0].pnd));}
#line 2414 "syntax.c" /* yacc.c:1646  */
    break;

  case 28:
#line 154 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfr_is_AUTO, &(yyloc), (yyvsp[0].pnd));}
#line 2420 "syntax.c" /* yacc.c:1646  */
    break;

  case 29:
#line 155 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfr_is_REGISTER, &(yyloc), (yyvsp[0].pnd));}
#line 2426 "syntax.c" /* yacc.c:1646  */
    break;

  case 30:
#line 156 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfr_is_CONST, &(yyloc), (yyvsp[0].pnd));}
#line 2432 "syntax.c" /* yacc.c:1646  */
    break;

  case 31:
#line 157 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfr_is_VOLATILE, &(yyloc), (yyvsp[0].pnd));}
#line 2438 "syntax.c" /* yacc.c:1646  */
    break;

  case 32:
#line 161 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_VOID, &(yyloc), (yyvsp[0].pnd));}
#line 2444 "syntax.c" /* yacc.c:1646  */
    break;

  case 33:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_BOOL, &(yyloc), (yyvsp[0].pnd));}
#line 2450 "syntax.c" /* yacc.c:1646  */
    break;

  case 34:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_CHAR, &(yyloc), (yyvsp[0].pnd));}
#line 2456 "syntax.c" /* yacc.c:1646  */
    break;

  case 35:
#line 164 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_SHORT, &(yyloc), (yyvsp[0].pnd));}
#line 2462 "syntax.c" /* yacc.c:1646  */
    break;

  case 36:
#line 165 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_INT, &(yyloc), (yyvsp[0].pnd));}
#line 2468 "syntax.c" /* yacc.c:1646  */
    break;

  case 37:
#line 166 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_LONG, &(yyloc), (yyvsp[0].pnd));}
#line 2474 "syntax.c" /* yacc.c:1646  */
    break;

  case 38:
#line 167 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_FLOAT, &(yyloc), (yyvsp[0].pnd));}
#line 2480 "syntax.c" /* yacc.c:1646  */
    break;

  case 39:
#line 168 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_DOUBLE, &(yyloc), (yyvsp[0].pnd));}
#line 2486 "syntax.c" /* yacc.c:1646  */
    break;

  case 40:
#line 169 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_SIGNED, &(yyloc), (yyvsp[0].pnd));}
#line 2492 "syntax.c" /* yacc.c:1646  */
    break;

  case 41:
#line 170 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_UNSIGNED, &(yyloc), (yyvsp[0].pnd));}
#line 2498 "syntax.c" /* yacc.c:1646  */
    break;

  case 42:
#line 171 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_INT8T, &(yyloc), (yyvsp[0].pnd));}
#line 2504 "syntax.c" /* yacc.c:1646  */
    break;

  case 43:
#line 172 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_INT16T, &(yyloc), (yyvsp[0].pnd));}
#line 2510 "syntax.c" /* yacc.c:1646  */
    break;

  case 44:
#line 173 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_INT32T, &(yyloc), (yyvsp[0].pnd));}
#line 2516 "syntax.c" /* yacc.c:1646  */
    break;

  case 45:
#line 174 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_INT64T, &(yyloc), (yyvsp[0].pnd));}
#line 2522 "syntax.c" /* yacc.c:1646  */
    break;

  case 46:
#line 175 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_UINT8T, &(yyloc), (yyvsp[0].pnd));}
#line 2528 "syntax.c" /* yacc.c:1646  */
    break;

  case 47:
#line 176 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_UINT16T, &(yyloc), (yyvsp[0].pnd));}
#line 2534 "syntax.c" /* yacc.c:1646  */
    break;

  case 48:
#line 177 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_UINT32T, &(yyloc), (yyvsp[0].pnd));}
#line 2540 "syntax.c" /* yacc.c:1646  */
    break;

  case 49:
#line 178 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_UINT64T, &(yyloc), (yyvsp[0].pnd));}
#line 2546 "syntax.c" /* yacc.c:1646  */
    break;

  case 50:
#line 179 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_UINTPTRT, &(yyloc), (yyvsp[0].pnd));}
#line 2552 "syntax.c" /* yacc.c:1646  */
    break;

  case 51:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_SIZET, &(yyloc), (yyvsp[0].pnd));}
#line 2558 "syntax.c" /* yacc.c:1646  */
    break;

  case 52:
#line 181 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_OFFT, &(yyloc), (yyvsp[0].pnd));}
#line 2564 "syntax.c" /* yacc.c:1646  */
    break;

  case 53:
#line 182 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_CompSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2570 "syntax.c" /* yacc.c:1646  */
    break;

  case 54:
#line 183 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_EnumSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2576 "syntax.c" /* yacc.c:1646  */
    break;

  case 55:
#line 184 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeSpec_is_TYPE_NAME, &(yyloc), (yyvsp[0].pnd));}
#line 2582 "syntax.c" /* yacc.c:1646  */
    break;

  case 56:
#line 188 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSpec_is_CompType_ID_LC_StructDeclnList_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2588 "syntax.c" /* yacc.c:1646  */
    break;

  case 57:
#line 189 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSpec_is_CompType_LC_StructDeclnList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2594 "syntax.c" /* yacc.c:1646  */
    break;

  case 58:
#line 190 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSpec_is_CompType_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2600 "syntax.c" /* yacc.c:1646  */
    break;

  case 59:
#line 194 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompType_is_STRUCT, &(yyloc), (yyvsp[0].pnd));}
#line 2606 "syntax.c" /* yacc.c:1646  */
    break;

  case 60:
#line 195 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompType_is_UNION, &(yyloc), (yyvsp[0].pnd));}
#line 2612 "syntax.c" /* yacc.c:1646  */
    break;

  case 61:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDeclnList_is_StructDecln, &(yyloc), (yyvsp[0].pnd));}
#line 2618 "syntax.c" /* yacc.c:1646  */
    break;

  case 62:
#line 200 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDeclnList_is_StructDeclnList_StructDecln, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2624 "syntax.c" /* yacc.c:1646  */
    break;

  case 63:
#line 204 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDecln_is_SpecQulfrList_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2630 "syntax.c" /* yacc.c:1646  */
    break;

  case 64:
#line 205 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDecln_is_SpecQulfrList_StructDeclrList_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2636 "syntax.c" /* yacc.c:1646  */
    break;

  case 65:
#line 209 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_SpecQulfrList_is_TypeSpec_SpecQulfrList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2642 "syntax.c" /* yacc.c:1646  */
    break;

  case 66:
#line 210 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_SpecQulfrList_is_TypeSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2648 "syntax.c" /* yacc.c:1646  */
    break;

  case 67:
#line 211 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_SpecQulfrList_is_TypeQulfr_SpecQulfrList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2654 "syntax.c" /* yacc.c:1646  */
    break;

  case 68:
#line 212 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_SpecQulfrList_is_TypeQulfr, &(yyloc), (yyvsp[0].pnd));}
#line 2660 "syntax.c" /* yacc.c:1646  */
    break;

  case 69:
#line 216 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDeclrList_is_StructDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2666 "syntax.c" /* yacc.c:1646  */
    break;

  case 70:
#line 217 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDeclrList_is_StructDeclrList_COMMA_StructDeclr, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2672 "syntax.c" /* yacc.c:1646  */
    break;

  case 71:
#line 221 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDeclr_is_Declr, &(yyloc), (yyvsp[0].pnd));}
#line 2678 "syntax.c" /* yacc.c:1646  */
    break;

  case 72:
#line 222 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDeclr_is_COLON_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2684 "syntax.c" /* yacc.c:1646  */
    break;

  case 73:
#line 223 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StructDeclr_is_Declr_COLON_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2690 "syntax.c" /* yacc.c:1646  */
    break;

  case 74:
#line 227 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_LC_EnumorList_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2696 "syntax.c" /* yacc.c:1646  */
    break;

  case 75:
#line 228 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2702 "syntax.c" /* yacc.c:1646  */
    break;

  case 76:
#line 229 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumSpec_is_ENUM_ID, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2708 "syntax.c" /* yacc.c:1646  */
    break;

  case 77:
#line 233 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumorList_is_Enumor, &(yyloc), (yyvsp[0].pnd));}
#line 2714 "syntax.c" /* yacc.c:1646  */
    break;

  case 78:
#line 234 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_EnumorList_is_EnumorList_COMMA_Enumor, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2720 "syntax.c" /* yacc.c:1646  */
    break;

  case 79:
#line 238 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Enumor_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2726 "syntax.c" /* yacc.c:1646  */
    break;

  case 80:
#line 239 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Enumor_is_ID_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2732 "syntax.c" /* yacc.c:1646  */
    break;

  case 81:
#line 243 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Declr_is_StarList_DirectDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2738 "syntax.c" /* yacc.c:1646  */
    break;

  case 82:
#line 244 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Declr_is_DirectDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2744 "syntax.c" /* yacc.c:1646  */
    break;

  case 83:
#line 248 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2750 "syntax.c" /* yacc.c:1646  */
    break;

  case 84:
#line 249 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_LP_Declr_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2756 "syntax.c" /* yacc.c:1646  */
    break;

  case 85:
#line 250 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2762 "syntax.c" /* yacc.c:1646  */
    break;

  case 86:
#line 251 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LB_RB, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2768 "syntax.c" /* yacc.c:1646  */
    break;

  case 87:
#line 252 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_ParaTypeList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2774 "syntax.c" /* yacc.c:1646  */
    break;

  case 88:
#line 253 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_IdList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2780 "syntax.c" /* yacc.c:1646  */
    break;

  case 89:
#line 254 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectDeclr_is_DirectDeclr_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2786 "syntax.c" /* yacc.c:1646  */
    break;

  case 90:
#line 258 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT, &(yyloc), (yyvsp[0].pnd));}
#line 2792 "syntax.c" /* yacc.c:1646  */
    break;

  case 91:
#line 259 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT_TypeQulfrList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2798 "syntax.c" /* yacc.c:1646  */
    break;

  case 92:
#line 260 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT_StarList, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2804 "syntax.c" /* yacc.c:1646  */
    break;

  case 93:
#line 261 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StarList_is_MULT_TypeQulfrList_StarList, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2810 "syntax.c" /* yacc.c:1646  */
    break;

  case 94:
#line 265 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfrList_is_TypeQulfr, &(yyloc), (yyvsp[0].pnd));}
#line 2816 "syntax.c" /* yacc.c:1646  */
    break;

  case 95:
#line 266 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeQulfrList_is_TypeQulfrList_TypeQulfr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2822 "syntax.c" /* yacc.c:1646  */
    break;

  case 96:
#line 270 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaTypeList_is_ParaList, &(yyloc), (yyvsp[0].pnd));}
#line 2828 "syntax.c" /* yacc.c:1646  */
    break;

  case 97:
#line 271 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaTypeList_is_ParaList_COMMA_ELLIPSIS, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2834 "syntax.c" /* yacc.c:1646  */
    break;

  case 98:
#line 275 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaList_is_ParaDecln, &(yyloc), (yyvsp[0].pnd));}
#line 2840 "syntax.c" /* yacc.c:1646  */
    break;

  case 99:
#line 276 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaList_is_ParaList_COMMA_ParaDecln, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2846 "syntax.c" /* yacc.c:1646  */
    break;

  case 100:
#line 280 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaDecln_is_DeclnSpec_Declr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2852 "syntax.c" /* yacc.c:1646  */
    break;

  case 101:
#line 281 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaDecln_is_DeclnSpec_AbstDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2858 "syntax.c" /* yacc.c:1646  */
    break;

  case 102:
#line 282 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ParaDecln_is_DeclnSpec, &(yyloc), (yyvsp[0].pnd));}
#line 2864 "syntax.c" /* yacc.c:1646  */
    break;

  case 103:
#line 286 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_IdList_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 2870 "syntax.c" /* yacc.c:1646  */
    break;

  case 104:
#line 287 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_IdList_is_IdList_COMMA_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2876 "syntax.c" /* yacc.c:1646  */
    break;

  case 105:
#line 291 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeName_is_SpecQulfrList, &(yyloc), (yyvsp[0].pnd));}
#line 2882 "syntax.c" /* yacc.c:1646  */
    break;

  case 106:
#line 292 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_TypeName_is_SpecQulfrList_AbstDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2888 "syntax.c" /* yacc.c:1646  */
    break;

  case 107:
#line 296 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_AbstDeclr_is_StarList, &(yyloc), (yyvsp[0].pnd));}
#line 2894 "syntax.c" /* yacc.c:1646  */
    break;

  case 108:
#line 297 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_AbstDeclr_is_DirectAbstDeclr, &(yyloc), (yyvsp[0].pnd));}
#line 2900 "syntax.c" /* yacc.c:1646  */
    break;

  case 109:
#line 298 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_AbstDeclr_is_StarList_DirectAbstDeclr, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2906 "syntax.c" /* yacc.c:1646  */
    break;

  case 110:
#line 302 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LP_AbstDeclr_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2912 "syntax.c" /* yacc.c:1646  */
    break;

  case 111:
#line 303 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LB_RB, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2918 "syntax.c" /* yacc.c:1646  */
    break;

  case 112:
#line 304 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LB_Exp_RB, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2924 "syntax.c" /* yacc.c:1646  */
    break;

  case 113:
#line 305 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_RB, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2930 "syntax.c" /* yacc.c:1646  */
    break;

  case 114:
#line 306 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2936 "syntax.c" /* yacc.c:1646  */
    break;

  case 115:
#line 307 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LP_RP, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2942 "syntax.c" /* yacc.c:1646  */
    break;

  case 116:
#line 308 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_LP_ParaTypeList_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2948 "syntax.c" /* yacc.c:1646  */
    break;

  case 117:
#line 309 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2954 "syntax.c" /* yacc.c:1646  */
    break;

  case 118:
#line 310 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_DirectAbstDeclr_is_DirectAbstDeclr_LP_ParaTypeList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2960 "syntax.c" /* yacc.c:1646  */
    break;

  case 119:
#line 314 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_Exp, &(yyloc), (yyvsp[0].pnd));}
#line 2966 "syntax.c" /* yacc.c:1646  */
    break;

  case 120:
#line 315 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_LB_Exp_RB_ASSIGNOP_Exp, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2972 "syntax.c" /* yacc.c:1646  */
    break;

  case 121:
#line 316 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_LC_InitorList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2978 "syntax.c" /* yacc.c:1646  */
    break;

  case 122:
#line 317 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Initor_is_LC_InitorList_COMMA_RC, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2984 "syntax.c" /* yacc.c:1646  */
    break;

  case 123:
#line 321 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorList_is_Initor, &(yyloc), (yyvsp[0].pnd));}
#line 2990 "syntax.c" /* yacc.c:1646  */
    break;

  case 124:
#line 322 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_InitorList_is_InitorList_COMMA_Initor, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 2996 "syntax.c" /* yacc.c:1646  */
    break;

  case 125:
#line 326 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_Stmt, &(yyloc), (yyvsp[0].pnd));}
#line 3002 "syntax.c" /* yacc.c:1646  */
    break;

  case 126:
#line 327 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_StmtList_is_StmtList_Stmt, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3008 "syntax.c" /* yacc.c:1646  */
    break;

  case 127:
#line 331 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpStmt_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 3014 "syntax.c" /* yacc.c:1646  */
    break;

  case 128:
#line 332 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpStmt_is_Exp_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3020 "syntax.c" /* yacc.c:1646  */
    break;

  case 129:
#line 333 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_ExpStmt_is_SEMI, &(yyloc), (yyvsp[0].pnd));}
#line 3026 "syntax.c" /* yacc.c:1646  */
    break;

  case 130:
#line 337 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSt_is_LC_RC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3032 "syntax.c" /* yacc.c:1646  */
    break;

  case 131:
#line 338 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_CompSt_is_LC_StmtList_RC, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3038 "syntax.c" /* yacc.c:1646  */
    break;

  case 132:
#line 342 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_SEMI, &(yyloc), (yyvsp[0].pnd));}
#line 3044 "syntax.c" /* yacc.c:1646  */
    break;

  case 133:
#line 343 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Decln, &(yyloc), (yyvsp[0].pnd));}
#line 3050 "syntax.c" /* yacc.c:1646  */
    break;

  case 134:
#line 344 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_Exp_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3056 "syntax.c" /* yacc.c:1646  */
    break;

  case 135:
#line 345 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_CompSt, &(yyloc), (yyvsp[0].pnd));}
#line 3062 "syntax.c" /* yacc.c:1646  */
    break;

  case 136:
#line 346 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_GOTO_ID_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3068 "syntax.c" /* yacc.c:1646  */
    break;

  case 137:
#line 347 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_ID_COLON, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3074 "syntax.c" /* yacc.c:1646  */
    break;

  case 138:
#line 348 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_CONTINUE_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3080 "syntax.c" /* yacc.c:1646  */
    break;

  case 139:
#line 349 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_BREAK_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3086 "syntax.c" /* yacc.c:1646  */
    break;

  case 140:
#line 350 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_SEMI, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3092 "syntax.c" /* yacc.c:1646  */
    break;

  case 141:
#line 351 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_RETURN_Exp_SEMI, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3098 "syntax.c" /* yacc.c:1646  */
    break;

  case 142:
#line 352 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3104 "syntax.c" /* yacc.c:1646  */
    break;

  case 143:
#line 353 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_IF_LP_Exp_RP_Stmt_ELSE_Stmt, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3110 "syntax.c" /* yacc.c:1646  */
    break;

  case 144:
#line 354 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_SWITCH_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3116 "syntax.c" /* yacc.c:1646  */
    break;

  case 145:
#line 355 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_CASE_Exp_COLON_Stmt, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3122 "syntax.c" /* yacc.c:1646  */
    break;

  case 146:
#line 356 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_DEFAULT_COLON_Stmt, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3128 "syntax.c" /* yacc.c:1646  */
    break;

  case 147:
#line 357 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_WHILE_LP_Exp_RP_Stmt, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3134 "syntax.c" /* yacc.c:1646  */
    break;

  case 148:
#line 358 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_DO_Stmt_WHILE_LP_Exp_RP_SEMI, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3140 "syntax.c" /* yacc.c:1646  */
    break;

  case 149:
#line 359 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_RP_Stmt, &(yyloc), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3146 "syntax.c" /* yacc.c:1646  */
    break;

  case 150:
#line 360 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Stmt_is_FOR_LP_ExpStmt_ExpStmt_Exp_RP_Stmt, &(yyloc), (yyvsp[-6].pnd), (yyvsp[-5].pnd), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3152 "syntax.c" /* yacc.c:1646  */
    break;

  case 151:
#line 364 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ID, &(yyloc), (yyvsp[0].pnd));}
#line 3158 "syntax.c" /* yacc.c:1646  */
    break;

  case 152:
#line 365 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NUM, &(yyloc), (yyvsp[0].pnd));}
#line 3164 "syntax.c" /* yacc.c:1646  */
    break;

  case 153:
#line 366 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NIL, &(yyloc), (yyvsp[0].pnd));}
#line 3170 "syntax.c" /* yacc.c:1646  */
    break;

  case 154:
#line 367 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_TRUE, &(yyloc), (yyvsp[0].pnd));}
#line 3176 "syntax.c" /* yacc.c:1646  */
    break;

  case 155:
#line 368 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_FALSE, &(yyloc), (yyvsp[0].pnd));}
#line 3182 "syntax.c" /* yacc.c:1646  */
    break;

  case 156:
#line 369 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_STRING, &(yyloc), (yyvsp[0].pnd));}
#line 3188 "syntax.c" /* yacc.c:1646  */
    break;

  case 157:
#line 370 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LITERAL, &(yyloc), (yyvsp[0].pnd));}
#line 3194 "syntax.c" /* yacc.c:1646  */
    break;

  case 158:
#line 371 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LP_Exp_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3200 "syntax.c" /* yacc.c:1646  */
    break;

  case 159:
#line 372 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LB_Exp_RB, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3206 "syntax.c" /* yacc.c:1646  */
    break;

  case 160:
#line 373 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LP_RP, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3212 "syntax.c" /* yacc.c:1646  */
    break;

  case 161:
#line 374 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LP_ExpList_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3218 "syntax.c" /* yacc.c:1646  */
    break;

  case 162:
#line 375 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DOT_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3224 "syntax.c" /* yacc.c:1646  */
    break;

  case 163:
#line 376 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_PTR_ID, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3230 "syntax.c" /* yacc.c:1646  */
    break;

  case 164:
#line 377 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_INC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3236 "syntax.c" /* yacc.c:1646  */
    break;

  case 165:
#line 378 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DEC, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3242 "syntax.c" /* yacc.c:1646  */
    break;

  case 166:
#line 379 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_INC_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3248 "syntax.c" /* yacc.c:1646  */
    break;

  case 167:
#line 380 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_DEC_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3254 "syntax.c" /* yacc.c:1646  */
    break;

  case 168:
#line 381 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_AND_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3260 "syntax.c" /* yacc.c:1646  */
    break;

  case 169:
#line 382 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_MULT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3266 "syntax.c" /* yacc.c:1646  */
    break;

  case 170:
#line 383 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_ADD_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3272 "syntax.c" /* yacc.c:1646  */
    break;

  case 171:
#line 384 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SUB_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3278 "syntax.c" /* yacc.c:1646  */
    break;

  case 172:
#line 385 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_NOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3284 "syntax.c" /* yacc.c:1646  */
    break;

  case 173:
#line 386 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LNOT_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3290 "syntax.c" /* yacc.c:1646  */
    break;

  case 174:
#line 387 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SIZEOF_Exp, &(yyloc), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3296 "syntax.c" /* yacc.c:1646  */
    break;

  case 175:
#line 388 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_SIZEOF_LP_TypeName_RP, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3302 "syntax.c" /* yacc.c:1646  */
    break;

  case 176:
#line 389 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_LP_TypeName_RP_Exp, &(yyloc), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3308 "syntax.c" /* yacc.c:1646  */
    break;

  case 177:
#line 390 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MULT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3314 "syntax.c" /* yacc.c:1646  */
    break;

  case 178:
#line 391 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DIV_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3320 "syntax.c" /* yacc.c:1646  */
    break;

  case 179:
#line 392 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MOD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3326 "syntax.c" /* yacc.c:1646  */
    break;

  case 180:
#line 393 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ADD_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3332 "syntax.c" /* yacc.c:1646  */
    break;

  case 181:
#line 394 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_SUB_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3338 "syntax.c" /* yacc.c:1646  */
    break;

  case 182:
#line 395 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LSHIFT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3344 "syntax.c" /* yacc.c:1646  */
    break;

  case 183:
#line 396 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_RSHIFT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3350 "syntax.c" /* yacc.c:1646  */
    break;

  case 184:
#line 397 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3356 "syntax.c" /* yacc.c:1646  */
    break;

  case 185:
#line 398 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GT_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3362 "syntax.c" /* yacc.c:1646  */
    break;

  case 186:
#line 399 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3368 "syntax.c" /* yacc.c:1646  */
    break;

  case 187:
#line 400 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_GE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3374 "syntax.c" /* yacc.c:1646  */
    break;

  case 188:
#line 401 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_EQ_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3380 "syntax.c" /* yacc.c:1646  */
    break;

  case 189:
#line 402 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_NE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3386 "syntax.c" /* yacc.c:1646  */
    break;

  case 190:
#line 403 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_AND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3392 "syntax.c" /* yacc.c:1646  */
    break;

  case 191:
#line 404 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_XOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3398 "syntax.c" /* yacc.c:1646  */
    break;

  case 192:
#line 405 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_OR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3404 "syntax.c" /* yacc.c:1646  */
    break;

  case 193:
#line 406 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LAND_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3410 "syntax.c" /* yacc.c:1646  */
    break;

  case 194:
#line 407 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LOR_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3416 "syntax.c" /* yacc.c:1646  */
    break;

  case 195:
#line 408 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_QOP_Exp_COLON_Exp, &(yyloc), (yyvsp[-4].pnd), (yyvsp[-3].pnd), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3422 "syntax.c" /* yacc.c:1646  */
    break;

  case 196:
#line 409 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ASSIGNOP_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3428 "syntax.c" /* yacc.c:1646  */
    break;

  case 197:
#line 410 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MULTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3434 "syntax.c" /* yacc.c:1646  */
    break;

  case 198:
#line 411 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_DIVE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3440 "syntax.c" /* yacc.c:1646  */
    break;

  case 199:
#line 412 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_MODE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3446 "syntax.c" /* yacc.c:1646  */
    break;

  case 200:
#line 413 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ADDE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3452 "syntax.c" /* yacc.c:1646  */
    break;

  case 201:
#line 414 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_SUBE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3458 "syntax.c" /* yacc.c:1646  */
    break;

  case 202:
#line 415 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_LSHIFTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3464 "syntax.c" /* yacc.c:1646  */
    break;

  case 203:
#line 416 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_RSHIFTE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3470 "syntax.c" /* yacc.c:1646  */
    break;

  case 204:
#line 417 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ANDE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3476 "syntax.c" /* yacc.c:1646  */
    break;

  case 205:
#line 418 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_XORE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3482 "syntax.c" /* yacc.c:1646  */
    break;

  case 206:
#line 419 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_ORE_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3488 "syntax.c" /* yacc.c:1646  */
    break;

  case 207:
#line 420 "syntax.y" /* yacc.c:1646  */
    {(yyval.pnd)=build_subast(AST_Exp_is_Exp_COMMA_Exp, &(yyloc), (yyvsp[-2].pnd), (yyvsp[-1].pnd), (yyvsp[0].pnd));}
#line 3494 "syntax.c" /* yacc.c:1646  */
    break;


#line 3498 "syntax.c" /* yacc.c:1646  */
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

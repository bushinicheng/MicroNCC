/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 12 "syntax.y" /* yacc.c:1909  */

	Node *pnd;

#line 167 "syntax.h" /* yacc.c:1909  */
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

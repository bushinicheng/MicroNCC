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
    BOOL = 318,
    CHAR = 319,
    SHORT = 320,
    INT = 321,
    UNSIGNED = 322,
    FLOAT = 323,
    DOUBLE = 324,
    INT8T = 325,
    INT16T = 326,
    INT32T = 327,
    INT64T = 328,
    UINT8T = 329,
    UINT16T = 330,
    UINT32T = 331,
    UINT64T = 332,
    SIZET = 333,
    OFFT = 334,
    UINTPTRT = 335,
    ENUM = 336,
    UNION = 337,
    STRUCT = 338,
    NUM = 339,
    STRING = 340,
    ID = 341
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "syntax.y" /* yacc.c:1909  */

	Node *pnd;

#line 145 "syntax.h" /* yacc.c:1909  */
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

#ifndef MACRO_H
#define MACRO_H

/* #define A
 * #define A()
 * #define A(a, b)
 * #define A(a, b, ...)
 * #define A(args...)
 *
 */

enum {
	MacroID = 0,
	MacroLP = 1,
	MacroRP = 2,
	MacroCOMMA = 3,
	MacroELLIPSIS = 4,
	MacroIDELLIPSIS = 5,
	MacroCONCAT = 6,
	MacroSTRINGIFY = 7,
	MacroNEWLINE = 8,
	MacroSPACE = 9,
	MacroOther = 10,
	MacroEOF = 11,
};

enum {
	MacroNormal,//#define M 12
	MacroArgs,//#define M(args...)
	MacroBad,
};

#define MacroTokenSize (MacroEOF + 1)

enum {
	MacroTokenConcatTT = 0,//## token token
	MacroTokenConcatTJ = 1,//(I) ## token
	MacroTokenConcatIT = 2,//(I) ## token
	MacroTokenConcatIJ = 3,//(I,J) ##
	MacroTokenCommon = 4,
	MacroTokenStringify = 5,
	MacroTokenArg = 6,
};

/* for macro_t
 *   common
 *   # arg[i]
 *   arg[i] ## arg[j]
 *   arg[i] ## token
 *   token  ## arg[i]
 *   token  ## token
 */
typedef struct macro_token_t {
	uint8_t mtt;//macro token type
	uint8_t i;
	uint8_t j;
	node_t *pnd;
} macro_token_t;

typedef struct macro_arg_t {
	int token;//ID ELLIPSIS IDELLIPSIS
	char *id;
} macro_arg_t;

typedef struct macro_t {
	int bt;//reg token, pnd(other node)
	char *id;
	/*---------*/
	size_t argc;
	macro_arg_t *argv;
	/*---------*/
	size_t mtlen;
	macro_token_t *mt;
} macro_t;


#endif

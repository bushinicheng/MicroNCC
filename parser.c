#include "common.h"

int yylex();

typedef struct tagTokenType{
	int token;
	Node *pnd;
} TokenType;

static uint32_t bufptr = 0;
TokenType token_buffer[102400];

void match(int token) {
	if(yylex() != token) {
		logw("encounter invalid token!\n");
	}
}

/* stack
 */
Node *match_exp() {
	return NULL;
}

/* IN:
 * OUT: Node *
 * function:
 *   match funcdef
 */
Node *match_funcdef(uint32_t subptr) {
	return NULL;
}

Node *match_extdecln(uint32_t subptr) {
	return NULL;
}

Node *match_declr(uint32_t subptr) {
	return NULL;
}

/* IN:
 * OUT:
 * function:
 *   match program:ExtDeclnList
 *   submatch: match_funcdef, match_extdecln
 * */
Node *wtparser() {
	int token = yylex();
	int subptr = -1;
	while(token != 0) {
		switch(token) {
			case MULT:token_buffer[bufptr++].token = token;
					  subptr = bufptr - 1;
					  match_declr(subptr);
					  break;
			default:
					  wt_assert(0);
		}
	}
}

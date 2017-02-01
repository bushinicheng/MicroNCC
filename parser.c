#include "common.h"

int yylex();

#define make_match_func(name) Node *match_##name(uint32_t subptr)

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

int store_token(int token) {
	token_buffer[bufptr++].token = token;
	wt_assert(bufptr < 102400);
	return token;
}

int store_next_token() {
	int token = yylex();
	token_buffer[bufptr++].token = token;
	wt_assert(bufptr < 102400);
	return token;
}

/* stack
 */
Node *match_exp() {
	return NULL;
}

int sub_next_token(int subptr) {
	if(subptr < 0 || subptr >= bufptr)
		return yylex();
	else
		return token_buffer[subptr].token;
}

/* IN:
 * OUT: Node *
 * function:
 *   match funcdef
 */
make_match_func(funcdef) {
	return NULL;
}

Node *match_structspec() {
}

Node *match_unionspec() {
}

Node *match_enumspec() {
}

make_match_func(extdecln) {
	return NULL;
}
/* Decln
 */
make_match_func(decln) {
	if(sub_next_token(subptr))
	return NULL;
}

make_match_func(declr) {
	if(subptr > 0) {
		//TODO:get_spec
	}

	if(sub_next_token(subptr) == MULT) {
	}
}

/* IN:
 * OUT:
 * function:
 *   match program:ExtDeclnList
 *   submatch: match_funcdef, match_extdecln
 *   fundef --> declnspec or declr
 *   vardef --> declnspec or declr
 *   declnspec --> typespec or typequlfr
 *   declr --> StarList ID LP
 * */
Node *wtparser() {
	int token = yylex();
	int subptr = -1;
	while(token != 0) {
		switch(token) {
			case MULT:
				//MULT ==> StarList
				//StarList ==> Declr
				//Declr [=|;]  ==>  Decln
				subptr = bufptr;
				store_token(token);
				match_declr(subptr);
				token = store_next_token();
				if(token == ASSIGNOP || token == SEMI) {
					match_decln(subptr);
				}else{
					match_funcdef(subptr);
				}
				//barrier
				break;
			case ID:
				subptr = bufptr;
				token_buffer[bufptr++].token = token;
				match_declr(subptr);
				break;
			case LP:
				subptr = bufptr;
				token_buffer[bufptr++].token = token;
				match_declr(subptr);
				break;
			default:
				wt_assert(0);
		}
	}
}

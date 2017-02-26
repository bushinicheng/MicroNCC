#include "front-com.h"

int yylex();

#define make_match_func(name) node_t *match_##name(uint32_t subptr)

typedef struct token_type_t{
	int token;
	node_t *pnd;
} token_type_t;

static uint32_t bufptr = 0;

void match(int token) {
	if(yylex() != token) {
		logw("encounter invalid token!\n");
	}
}

int store_token(int token) {
	return token;
}

int store_next_token() {
	int token = yylex();
	return token;
}

/* stack
 */
node_t *match_exp() {
	return NULL;
}

node_t *wtparser() {
}

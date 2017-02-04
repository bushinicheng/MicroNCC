#include "common.h"

bool is_syntax_error = false;
bool is_print_inter_code = false;
int last_syntax_error;

typedef struct tagVarElement {
	char *vn;
	Spec *type;//type system
	Node *node;//position
	VarAddr *va;//variale address, maybe :(
} VarElement;

static int actionlevel;
static MemPool varpool;//action scope of variable
Vector asv;//hash table vector


void push_variale(char *vn, Spec *type, Node *node) {
	VarElement *ve = mempool_new(&varpool);
	HashTable *ht = asv.p;
	ve->vn = vn;
	ve->type = type;
	ve->node = node;
	hash_push(&ht[actionlevel], vn, strlen(vn), ve);
}

void update_actionlevel() {
	actionlevel ++;
	HashTable *ht = asv.p;
}

void decrease_actionlevel() {
}

/* syntax analysis related function*/

void analyse_exp_is_id(Node *root) {
}

static SemanFunc analyse_function[] = {
	[AST_Exp_is_ID] = analyse_exp_is_id,
};

SemanFunc get_safe_seman_func(int reduce_rule) {
	if(reduce_rule < sizeof(analyse_function)/sizeof(analyse_function[0])) {
		return analyse_function[reduce_rule];
	}else{
		return NULL;
	}
}

void syntax_analysis(Node *root) {
	if(root->reduce_rule != 0) {
		int reduce_rule = root->reduce_rule;
		SemanFunc func = get_safe_seman_func(reduce_rule);
		if(func) func(root);
	}
}

int init_seman() {
	mempool_init(&varpool, sizeof(VarElement));
	vector_init(&asv, sizeof(HashTable));
}

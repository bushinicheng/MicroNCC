#include "common.h"

bool is_syntax_error = false;
bool is_print_inter_code = false;
int last_syntax_error;

typedef struct tagVarElement {
	char *varname;
	Spec *type;//type system
	Node *node;//position
	VarAddr *va;//variale address, maybe :(
} VarElement;

static int actionlevel = 0;
static MemPool varpool;//action scope of variable
Vector asv;//hash table vector


void push_variale(char *vn, Spec *type, Node *node) {
	VarElement *ve = mempool_new(&varpool);
	HashTable *ht = asv.p;
	ve->varname = vn;
	ve->type = type;
	ve->node = node;
	hash_push(&ht[actionlevel], vn, strlen(vn), ve);
}

void update_actionlevel() {
	actionlevel ++;
	HashTable *ht = vector_new(&asv);
	memset(ht, 0 ,sizeof(HashTable));
}

void decrease_actionlevel() {
	vector_pop(&asv);
}

VarElement *find_variable(char *vn) {
	HashTable *ht = asv.p;
	for(int i = actionlevel - 1; i >= 0; i--) {
		VarElement *ve = hash_get(&ht[actionlevel], vn, strlen(vn));
		if(ve) return ve;
	}
	return NULL;
}

/* syntax analysis related function*/

void analyse_decln_is_declnspec(Node *root) {
	Node *declnspec = get_child_node_w(root, DeclnSpec);
}

void analyse_typesepc_is_type(Node *root) {
	//FIXME
	Node *typenode = get_child_node_w(root, TYPE);
	root->dt = typenode->dt;
	root->cv.st |= 1;
}

void analyse_exp_is_id(Node *root) {
	char *vn = get_child_node_w(root, ID)->cv.sv.st;
	VarElement *ve = find_variable(vn);
	if(!ve) {
		yyerrtype(ErrorUndeclaredIdentifier, root->lineno, vn);
		root->dt = get_spec_by_btype(SpecTypeInt32, SpecLvalue);
	}else{
		root->dt = ve->type;
		root->va = ve->va;
	}
}

void analyse_exp_is_num(Node *root) {
	Node *numnode = get_child_node_w(root, NUM);
	root->dt = get_spec_by_btype(SpecTypeConst, SpecRvalue);
	root->cv.st = SpecTypeInt32;
	root->cv.sv._32 = numnode->cv.sv.i;
}

void analyse_exp_is_nil(Node *root) {
	root->dt = get_spec_by_btype(SpecTypeConst, SpecRvalue);
	root->cv.st = SpecTypeInt32;
	root->cv.sv._32 = 0;
}

void analyse_exp_is_false(Node *root) {
	root->dt = get_spec_by_btype(SpecTypeConst, SpecRvalue);
	root->cv.st = SpecTypeInt32;
	root->cv.sv._32 = 0;
}

void analyse_exp_is_true(Node *root) {
	root->dt = get_spec_by_btype(SpecTypeConst, SpecRvalue);
	root->cv.st = SpecTypeInt32;
	root->cv.sv._32 = 1;
}

void analyse_exp_is_string(Node *root) {
	//FIXME:
	Node *strnode = get_child_node_w(root, STRING);
	root->dt = get_spec_by_btype(SpecTypeString, SpecLvalue);
	root->cv.sv.st = strnode->cv.sv.st;
}

void analyse_exp_is_literal(Node *root) {
	Node *charnode = get_child_node_w(root, LITERAL);
	root->dt = get_spec_by_btype(SpecTypeConst, SpecRvalue);
	root->cv.st = SpecTypeInt8;
	root->cv.sv._8 = charnode->cv.sv._8;
}

void analyse_exp_is_lp_exp_rp(Node *root) {
	Node *exp = get_child_node_w(root, Exp);
	root->dt = exp->dt;
	root->cv = exp->cv;
}

void analyse_exp_is_function_call(Node *root) {
}

void analyse_exp_is_dot_member(Node *root) {
}

void analyse_exp_is_ptr_member(Node *root) {
}

void analyse_exp_is_inc_or_dec_exp(Node *root) {
}

void analyse_exp_is_exp_inc_or_dec(Node *root) {
}

void analyse_exp_is_take_addr(Node *root) {
}

void analyse_exp_is_indirection(Node *root) {
}

void analyse_exp_is_minus_exp(Node *root) {
}

void analyse_exp_is_add_exp(Node *root) {
}

void analyse_exp_is_logic_not(Node *root) {
}

void analyse_exp_is_arithmetic_not(Node *root) {
}

void analyse_exp_is_relop(Node *root) {
	Node *exp1 = get_child_node_w(root, Exp);
	Node *exp2 = get_child_node_with_skip_w(root, Exp, 1);
	int rel = get_type_relation(exp1->dt->bt, exp2->dt->bt);
	root->dt = get_spec_by_btype(SpecTypeInt32, SpecRvalue);
	if(!(rel & CRelop)) {
		yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp1->dt), type_format(exp2->dt));
	}
}

static SemanFunc analyse_function[] = {
	[AST_Exp_is_ID] = analyse_exp_is_id,
	[AST_Exp_is_Exp_RELOP_Exp] = analyse_exp_is_relop,
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

#include "common.h"

bool is_syntax_error = false;
bool is_print_inter_code = false;
int last_syntax_error;

//如何将类型池与变量池统一
//表现行为：
//	通过ID，查找得到入口，进一步判断是变量还是自定义类型
//	问题：未通过typedef的comptype如何处理
//		struct A {};
//		进行hash时，使用struct@A, union@A
typedef struct IdentInfo {
	char *id;
	Spec *type;//type system
	Node *node;//position
	VarInfo *vi;//vi->qulfr & QulfrConst == true for constant
	ExpConstPart cv;
} IdentInfo;

static int actionlevel = 0;
static MemPool vipool;
static MemPool idinfopool;
Vector asv;//hash table vector


void push_variable(char *vn, Spec *type, Node *node) {
	IdentInfo *ve = mempool_new(&idinfopool);
	VarInfo *vi = mempool_new(&vipool);
	HashTable *ht = asv.p;
	ve->id = vn;
	ve->type = type;
	ve->node = node;
	ve->vi = vi;
	node->vi = vi;
	hash_push(&ht[actionlevel], vn, strlen(vn), ve);
}

void increase_actionlevel() {
	actionlevel ++;
	HashTable *ht = vector_new(&asv);
	memset(ht, 0 ,sizeof(HashTable));
}

void decrease_actionlevel() {
	actionlevel --;
	vector_pop(&asv);
}

IdentInfo *find_variable(char *vn) {
	HashTable *ht = asv.p;
	for(int i = actionlevel - 1; i >= 0; i--) {
		IdentInfo *ve = hash_get(&ht[actionlevel], vn, strlen(vn));
		if(ve) return ve;
	}
	return NULL;
}

/* syntax analysis related function*/

void analyse_decln_is_declnspec(Node *root) {
	Node *declnspec = get_child_node_w(root, DeclnSpec);
}

void analyse_typesepc_is_type(Node *root) {
	Node *typenode = get_child_node_w(root, TYPE);
	root->dt = typenode->dt;
	root->cv.t = typenode->cv.t;
}

void analyse_enumor_is_id(Node *root) {
	Node *idnode = get_child_node_w(root, ID);
	char *vn = idnode->cv.str;
	root->cv.t = false;
	push_variable(vn, NULL, root);
	root->vi->qulfr = QulfrConst;
}

void analyse_enumor_is_id_assign_exp(Node *root) {
	Node *exp = get_child_node_w(root, Exp);
	Node *idnode = get_child_node_w(root, ID);
	char *vn = idnode->cv.str;
	int rel = get_type_relation(exp->dt->bt, exp->dt->bt);
	//FIXME
	if(exp->dt->bt == SpecTypeInt8) {
		if(rel & CBitop) {
			//valid case, register constant
			root->cv.t = true;
			root->cv._32 = exp->cv._32;
			push_variable(vn, exp->dt, root);
			root->vi->qulfr = QulfrConst;
		}else{
			//TODO:error
		}
	}else{
		//TODO:error
	}
}

void analyse_declnspec_is_typespec(Node *root) {
	Node *typespec = get_child_node_w(root, TypeSpec);
	root->cv.t = typespec->cv.t;
}

void analyse_declnspec_is_typespec_declnspec(Node *root) {
	Node *typespec = get_child_node_w(root, TypeSpec);
	Node *declnspec = get_child_node_w(root, DeclnSpec);
	if((typespec->cv.t & 1) && (declnspec->cv.t & 1)) {
		root->cv.t = typespec->cv.t | declnspec->cv.t;
	}else{
		root->cv.t |= CombineInvalid;
	}
}

void analyse_declnspec_is_typequlfr(Node *root) {
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	root->cv.ex = typequlfr->cv.ex;
	root->cv.t = 1;
}

void analyse_declnspec_is_typequlfr_declnspec(Node *root) {
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	Node *declnspec = get_child_node_w(root, DeclnSpec);
	root->cv.ex = typequlfr->cv.ex | declnspec->cv.ex;
	root->cv.t = declnspec->cv.t;
}

void analyse_exp_is_id(Node *root) {
	//FIXME
	char *vn = get_child_node_w(root, ID)->cv.str;
	IdentInfo *ve = find_variable(vn);
	if(!ve) {
		yyerrtype(ErrorUndeclaredIdentifier, root->lineno, vn);
		root->dt = get_spec_by_btype(SpecTypeInt32);
	}else{
		root->dt = ve->type;
		if(ve->vi->qulfr & QulfrConst) {
		}
	}
}

void analyse_exp_is_num(Node *root) {
	Node *numnode = get_child_node_w(root, NUM);
	root->lrv = SpecRvalue;
	root->dt = get_spec_by_btype(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = numnode->cv.i;
}

void analyse_exp_is_nil(Node *root) {
	root->lrv = SpecRvalue;
	root->dt = get_spec_by_btype(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = 0;
}

void analyse_exp_is_false(Node *root) {
	root->lrv = SpecRvalue;
	root->dt = get_spec_by_btype(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = 0;
}

void analyse_exp_is_true(Node *root) {
	root->lrv = SpecRvalue;
	root->dt = get_spec_by_btype(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = 1;
}

void analyse_exp_is_string(Node *root) {
	//FIXME:
	Node *strnode = get_child_node_w(root, STRING);
	root->lrv = SpecLvalue;
	root->dt = get_spec_by_btype(SpecTypeString);
	root->cv.str = strnode->cv.str;
}

void analyse_exp_is_literal(Node *root) {
	Node *charnode = get_child_node_w(root, LITERAL);
	root->lrv = SpecRvalue;
	root->dt = get_spec_by_btype(SpecTypeInt8);
	root->cv.t = PrConstValue;
	root->cv._8 = charnode->cv._8;
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
	//FIXME
	Node *exp1 = get_child_node_w(root, Exp);
	Node *exp2 = get_child_node_with_skip_w(root, Exp, 1);
	int rel = get_type_relation(exp1->dt->bt, exp2->dt->bt);
	root->lrv = SpecRvalue;
	root->dt = get_spec_by_btype(SpecTypeInt32);
	if(!(rel & CRelop)) {
		yyerrtype(ErrorInvalidOperand, root->lineno, type_format(exp1->dt), type_format(exp2->dt));
	}
}

static SemanFunc analyse_function[] = {
	[AST_Exp_is_ID] = analyse_exp_is_id,
	//[AST_Exp_is_Exp_RELOP_Exp] = analyse_exp_is_relop,
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

void free_seman() {
	mempool_free(&vipool);
	mempool_free(&idinfopool);
}

int init_seman() {
	mempool_init(&vipool, sizeof(VarInfo));
	mempool_init(&idinfopool, sizeof(IdentInfo));
	vector_init(&asv, sizeof(HashTable));
}

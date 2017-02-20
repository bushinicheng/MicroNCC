#include "common.h"

bool is_syntax_error = false;
bool is_print_inter_code = false;
int last_syntax_error;

typedef struct IdentInfo {
	char *id;
	Spec *type;//type system
	VarInfo *vi;//vi->qulfr & QulfrConst == true for constant
	ExpConstPart *cv;
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
	ve->vi = vi;
	ve->cv = &(node->cv);
	node->vi = vi;
	hash_push(&ht[actionlevel - 1], vn, strlen(vn), ve);
}

void increase_actionlevel() {
	actionlevel ++;
	HashTable *ht = vector_new(&asv);
	memset(ht, 0, sizeof(HashTable));
}

void decrease_actionlevel() {
	actionlevel --;
	vector_pop(&asv);
}

IdentInfo *find_variable(char *vn) {
	HashTable *ht = asv.p;
	for(int i = actionlevel - 1; i >= 0; i--) {
		IdentInfo *ve = hash_get(&ht[i], vn, strlen(vn));
		if(ve) return ve;
	}
	return NULL;
}

/* syntax analysis related function*/

void analyse_decln_is_declnspec(Node *root) {
	//FIXME
	Node *declnspec = get_child_node_w(root, DeclnSpec);
}

void analyse_typesepc_is_type(Node *root) {
	Node *typenode = get_child_node_w(root, TYPE);
	root->dt = typenode->dt;
	root->cv.t = typenode->cv.t;
}

int assign_value_of_enumorlist(Node *enumorlist, int st) {
	//first child: enumorlist
	if(enumorlist->reduce_rule == AST_EnumorList_is_EnumorList_COMMA_Enumor){
		Node *subenumorlist = get_child_node_w(enumorlist, EnumorList);
		st = assign_value_of_enumorlist(subenumorlist, st);
	}
	//next child: enumor
	Node *enumor = get_child_node_w(enumorlist, Enumor);
	if(enumor->reduce_rule == AST_Enumor_is_ID) {
		enumor->cv._32 = st;
		return st + 1;
	}else{
		Node *exp = get_child_node_w(enumor, Exp);
		st = exp->cv._32;
		enumor->cv._32 = st;
		return st + 1;
	}
}

void analyse_typespec(Node *root) {
	root->dt = root->child->dt;
}

void analyse_enumspec(Node *root) {
	root->dt = get_spec_by_btype(SpecTypeInt32);
	if(root->reduce_rule == AST_EnumSpec_is_ENUM_ID) {
		return;
	}
	Node *enumorlist = get_child_node_w(root, EnumorList);
	assign_value_of_enumorlist(enumorlist, 0);
}

void analyse_enumor_is_id(Node *root) {
	Node *idnode = get_child_node_w(root, ID);
	char *vn = idnode->cv.str;
	Spec *type = get_spec_by_btype(SpecTypeInt32);
	push_variable(vn, type, root);
}

void analyse_enumor_is_id_assign_exp(Node *root) {
	Node *exp = get_child_node_w(root, Exp);
	Node *idnode = get_child_node_w(root, ID);
	char *vn = idnode->cv.str;
	int rel = get_type_relation(exp->dt->bt, exp->dt->bt);
	Spec *type = get_spec_by_btype(SpecTypeInt32);
	//FIXME
	if(exp->cv.t == PrConstValue) {
		if(rel & CBitop) {
			//valid case, register constant
			root->cv = exp->cv;
			push_variable(vn, type, root);
		}else{
			//TODO:not a integer constant
		}
	}else{
		//TODO:not a constant
	}
}

void analyse_declnspec_is_typespec(Node *root) {
	Node *typespec = get_child_node_w(root, TypeSpec);
	root->dt = typespec->dt;
	root->cv.t = typespec->cv.t;//t record combine type
}

void analyse_declnspec_is_typespec_declnspec(Node *root) {
	Node *typespec = get_child_node_w(root, TypeSpec);
	Node *declnspec = get_child_node_w(root, DeclnSpec);
	root->cv.ex = declnspec->cv.ex;//transmit type qulfr
	if((typespec->cv.t & 1) && (declnspec->cv.t & 1)) {
		root->cv.t = typespec->cv.t | declnspec->cv.t;//t record combine type
		root->dt = get_spec_by_btype(convert_ctype2type(root->cv.t));
	}else{
		//TODO:invalid combination
		//may need some strategies to report error to upper node so to
		//  omit invalid id's register
		root->cv.t |= CombineInvalid;
		root->dt = get_spec_by_btype(SpecTypeInt32);
	}
}

void analyse_declnspec_is_typequlfr(Node *root) {
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	root->cv.ex = typequlfr->cv.ex;//ex record combine qulfr
	root->cv.t = 0;//0 means combinable
	root->dt = get_spec_by_btype(SpecTypeInt32);//default to be int32 if no typespec found
}

void analyse_declnspec_is_typequlfr_declnspec(Node *root) {
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	Node *declnspec = get_child_node_w(root, DeclnSpec);
	root->cv.ex = typequlfr->cv.ex | declnspec->cv.ex;//ex record combine qulfr
	root->cv.t = declnspec->cv.t;//deliver combine type to upper node
	root->dt = declnspec->dt;
}

void analyse_typespec_is_type(Node *root) {
	/* eg.
	 *  common type
	 *   void: reduce_rule = VOID, cv.t = WORD(SpecTypeVoid, false)
	 *   bool: reduce_rule = BOOL, cv.t = WORD(SpecTypeUint8, false)
	 *  combinable type
	 *   char: reduce_rule = CHAR, cv.t = DWORD(CombineTypeChar,
	 *         WORD(SpecTypeInt8, true))
	 */
	Node *typenode = get_child_node_w(root, TYPE);
	root->dt = typenode->dt;//dt record true data type
	if(typenode->cv.t & 1)
		root->cv.t = WORD_PART1(typenode->cv.t);
	else
		root->cv.t = CombineInvalid;
}

void analyse_type_spec_is_compspec(Node *root) {
	/*backfill offset and size of each member id by comptype's
	 *  information(struct or union)
	 *
	 * inner struct decl
	 *   struct A {
	 *       struct B {int a, b;};
	 *       struct B x;
	 *           // ^ inner struct decl
	 *       int y;
	 *   };
	 **/
}

void analyse_typespec_is_typename(Node *root) {
	//need information from context
	Node *typename = get_child_node_w(root, TYPE_NAME);
	root->dt = typename->dt;
	//TODO: and qulfr?
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
	[AST_EnumSpec_is_ENUM_LC_EnumorList_RC] = analyse_enumspec,
	[AST_EnumSpec_is_ENUM_LC_EnumorList_COMMA_RC] = analyse_enumspec,
	[AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC] = analyse_enumspec,
	[AST_EnumSpec_is_ENUM_ID_LC_EnumorList_COMMA_RC] = analyse_enumspec,
	[AST_Enumor_is_ID] = analyse_enumor_is_id,
	[AST_Enumor_is_ID_ASSIGNOP_Exp] = analyse_enumor_is_id_assign_exp,
	[AST_Exp_is_ID] = analyse_exp_is_id,
	[AST_Exp_is_NUM] = analyse_exp_is_num,
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
	vector_free(&asv);
}

int init_seman() {
	mempool_init(&vipool, sizeof(VarInfo));
	mempool_init(&idinfopool, sizeof(IdentInfo));
	vector_init(&asv, sizeof(HashTable));
	increase_actionlevel();
}

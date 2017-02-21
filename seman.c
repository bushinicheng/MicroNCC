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

/* push variable into current hash table
 * IN[0]: char *
 *    variabe name
 * IN[1]: Spec*
 *    type pointer
 * IN[2]: Node *
 *    AST node where variable bound to
 *
 * other influence:
 *    node->vi will be bound to a new vi.
 */
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
	root->cv.t = root->child->cv.t;//t records combine type
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
	root->cv.t = typespec->cv.t;//t records combine type
}

void analyse_declnspec_is_typespec_declnspec(Node *root) {
	//combine ct, transmit ex
	Node *typespec = get_child_node_w(root, TypeSpec);
	Node *declnspec = get_child_node_w(root, DeclnSpec);
	root->cv.ex = declnspec->cv.ex;//transmit type qulfr
	/* structure of cv.t
	 * +-----------------+---------------+
	 * |  SpecTypeVoid   |       0       |
	 * +-----------------+---------------+
	 * or
	 * +-----------------+---------------+
	 * | CombineTypeChar |       1       |
	 * +-----------------+---------------+
	 */
	if((typespec->cv.t & 1) && (declnspec->cv.t & 1)) {
		root->cv.t = typespec->cv.t | declnspec->cv.t;//t records combine type
		int btype = convert_ctype2type(root->cv.t);
		if(btype == -1) {//invalid combination
			root->cv.t &= ~1;
			root->dt = get_spec_by_btype(SpecTypeInt32);
		}else{
			root->dt = get_spec_by_btype(btype);
		}
	}else{
		//TODO:invalid combination
		//may need some strategies to report error to upper node so to
		//  omit further type combination
		root->cv.t &= ~1;
		//once fail to combine, transmit null spec to upper node
		root->dt = get_spec_by_btype(SpecTypeInt32);
	}
}

void analyse_declnspec_is_typequlfr(Node *root) {
	//default dt and ct, transmit ex
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	root->cv.ex = typequlfr->cv.ex;//ex records combine qulfr
	root->cv.t = 1;//1 means combinable
	root->dt = get_spec_by_btype(SpecTypeInt32);//default to be int32 if no typespec found
}

void analyse_declnspec_is_typequlfr_declnspec(Node *root) {
	//transmit dt and ct and combine qulfr
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	Node *declnspec = get_child_node_w(root, DeclnSpec);
	root->cv.ex = typequlfr->cv.ex | declnspec->cv.ex;//ex records combine qulfr
	root->cv.t = declnspec->cv.t;//deliver combine type to upper node
	root->dt = declnspec->dt;
}

//StarList
void analyse_starlist_is_mult(Node *root) {
	//cv.t records pointer level
	//ex records qulfr
	root->cv.t = 1;
}

void analyse_starlist_is_mult_typequlfrlist(Node *root) {
	//init pl, transmit qulfr
	Node *typequlfrlist = get_child_node_w(root, TypeQulfrList);
	root->cv.t = 1;//initial to be 1
	root->cv.ex = typequlfrlist->cv.ex;//transmit qulfr
}

void analyse_starlist_is_mult_starlist(Node *root) {
	//inc pl, transmit qulfr
	Node *starlist = get_child_node_w(root, StarList);
	root->cv.t = starlist->cv.t + 1;//initial to be 1
	root->cv.ex = starlist->cv.ex;
}

void analyse_starlist_is_mult_typequlfrlist_starlist(Node *root) {
	//inc pl, combine qulfr
	Node *starlist = get_child_node_w(root, StarList);
	Node *typequlfrlist = get_child_node_w(root, TypeQulfrList);
	root->cv.t = starlist->cv.t + 1;//initial to be 1
	root->cv.ex = starlist->cv.ex | typequlfrlist->cv.ex;//transmit qulfr
}

//TypeQulfrList
void analyse_typequlfrlist_is_typequlfr(Node *root) {
	//cv.ex records qulfr
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	root->cv.ex = typequlfr->cv.ex;
}

void analyse_typequlfrlist_is_typequlfrlist_typequlfr(Node *root) {
	Node *typequlfr = get_child_node_w(root, TypeQulfr);
	Node *typequlfrlist = get_child_node_w(root, TypeQulfrList);
	root->cv.ex = typequlfr->cv.ex | typequlfrlist->cv.ex;
}

//Declr
void analyse_declr_is_starlist_directdeclr(Node *root) {
	//for `StarList` node, cv.t records pointer level,
	//  cv.ex records qulfr
	//assume directdeclr return comp type
	Node *starlist = get_child_node_w(root, StarList);
	root->cv.t = starlist->cv.t + 1;//initial to be 1
	root->cv.ex = starlist->cv.ex;
}

void analyse_declr_is_directdeclr(Node *root) {
	//
}

//DirectDeclr
void analyse_directdeclr_is_id(Node *root) {
	//transmit id's name
	Node *idnode = get_child_node_w(root, ID);
	root->cv.str = idnode->cv.str;
}

void analyse_directdeclr_is_lp_declr_rp(Node *root) {
	Node *declr = get_child_node_w(root, Declr);
	root->dt = declr->dt;
	root->cv.str = declr->cv.str;//transmit id
}

void analyse_directdeclr_is_self_index(Node *root) {
	//array
	Node *directdeclr = get_child_node_w(root, DirectDeclr);
	root->cv.str = directdeclr->cv.str;//transmit id
}

void analyse_directdeclr_is_self_nullindex(Node *root) {
	//array
	Node *directdeclr = get_child_node_w(root, DirectDeclr);
	root->cv.str = directdeclr->cv.str;//transmit id
}

Spec *combine_datatype_of_directdeclr(Spec *ddt, Spec *exdt) {
	/*eg.
	 * DirectDeclr -> DirectDeclr LP IdList RP
	 *                     ^      \----------/
	 *                    ddt         exdt
	 */
	if(ddt) {
		if(ddt->bt == SpecTypeComplex) {
			//eg. int (*func[])(int, int)
			ddt->comp.dt = exdt;
		}else if(ddt->bt == SpecTypePointer){
			//eg. int (*func)(int, int)
			ddt->ptr.dt = exdt;
		}else{
			//invalid
			//TODO: call yyerrtype to format error information and
			//      set global variable is_syntax_error
			assert(0);
			//default behavior: use dt of DirectDeclr and discard
			//    other part in this production
		}
		return ddt;
	}else{
		//paralist->dt->btype = SpecTypeFunc
		//  the ret_spec of dt need to be backfilled in upper call
		return exdt;
	}
}

void analyse_directdeclr_is_func_paralist(Node *root) {
	//func
	//assume directdeclr's dt and paralist's dt have been filled
	Node *directdeclr = get_child_node_w(root, DirectDeclr);
	Node *paralist = get_child_node_w(root, ParaTypeList);
	root->cv.str = directdeclr->cv.str;//transmit id
	root->dt = combine_datatype_of_directdeclr(directdeclr->dt, paralist->dt);
}

void analyse_directdeclr_is_func_idlist(Node *root) {
	//func
	Node *directdeclr = get_child_node_w(root, DirectDeclr);
	Node *idlist = get_child_node_w(root, IdList);
	root->cv.str = directdeclr->cv.str;//transmit id
	root->dt = combine_datatype_of_directdeclr(directdeclr->dt, idlist->dt);
}

void analyse_directdeclr_is_func_lp_rp(Node *root) {
	//func
	Spec *funcdt = new_spec();
	Node *directdeclr = get_child_node_w(root, DirectDeclr);
	root->cv.str = directdeclr->cv.str;//transmit id
	funcdt->bt = SpecTypeFunc;
	funcdt->func.argc = 0;
	root->dt = combine_datatype_of_directdeclr(directdeclr->dt, funcdt);
}

void analyse_paratypelist(Node *root) {
	Node *paralist = get_child_node_w(root, ParaList);
	root->dt = paralist->dt;
	root->cv.pstr = paralist->cv.pstr;//pstr stores each argument's id
	if(get_child_node(root, ELLIPSIS)) {
		root->dt->func.ellipsis = 1;
	}
}

void analyse_paralist(Node *root) {
}

void analyse_paradecln(Node *root) {
	/* ParaDecln -> DeclnSpec Declr
	 *              DeclnSpec AbstDeclr
	 *              DeclnSpec
	 */
}

void analyse_idlist(Node *root) {
	//backfill, give up bottom-up fill
	if(root->parent->token == IdList) return;
	int cnt = 0;
	char **varname = get_memory_pointer();
	Node *idlist = get_child_node(root, IdList);
	while(idlist) {
		Node *idnode = get_child_node_w(idlist, ID);
		varname[cnt ++] = idnode->cv.str;
		idlist = get_child_node(root, IdList);
	}
	Node *idnode = get_child_node_w(root, ID);
	varname[cnt ++] = idnode->cv.str;
	root->cv.pstr = (char **)require_memory(sizeof(char *) * cnt);
	//set spec
	Spec *default_argtype = get_spec_by_btype(SpecTypeInt32);
	Spec **func_argv = (Spec **)malloc(sizeof(Spec *) * cnt);
	for(int i = 0; i < cnt; i++)
		func_argv[i] = default_argtype;
	root->dt = new_spec();
	root->dt->bt = SpecTypeFunc;
	root->dt->func.argc = cnt;
	root->dt->func.argv = func_argv;
}

void analyse_typespec_is_compspec(Node *root) {
	/*backfill offset and size of each member id by comptype's
	 *  information(struct or union)
	 *
	 * inner struct decl
	 *   struct A {
	 *       struct B {int a, b;};
	 *       struct B x;
	 *           // ^ inner struct decl and can be used in
	 *           //     this struct scope
	 *       int y;
	 *   };
	 **/
}

void analyse_compdecln_is_declnspec(Node *root) {
	Node *declnspec = get_child_node_w(root, DeclnSpec);
	root->dt = declnspec->dt;//transmit dt
}

void analyse_compdecln_is_declnspec_compdeclrlist(Node *root) {
	//TODO:
}

void analyse_compdeclrlist_is_compdeclr(Node *root) {
}

void analyse_compdeclr_is_declr() {
}

void analyse_compdeclr_is_colon_exp() {
}

void analyse_compdeclr_is_declr_colon_exp() {
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
	[AST_Decln_is_DeclnSpec_SEMI] = analyse_decln_is_declnspec,
	[AST_TypeSpec_is_TYPE] = analyse_typespec,
	[AST_TypeSpec_is_CompSpec] = analyse_typespec,
	[AST_TypeSpec_is_EnumSpec] = analyse_typespec,
	[AST_TypeSpec_is_TYPE_NAME] = analyse_typespec,
	[AST_EnumSpec_is_ENUM_LC_EnumorList_RC] = analyse_enumspec,
	[AST_EnumSpec_is_ENUM_LC_EnumorList_COMMA_RC] = analyse_enumspec,
	[AST_EnumSpec_is_ENUM_ID_LC_EnumorList_RC] = analyse_enumspec,
	[AST_EnumSpec_is_ENUM_ID_LC_EnumorList_COMMA_RC] = analyse_enumspec,
	[AST_Enumor_is_ID] = analyse_enumor_is_id,
	[AST_Enumor_is_ID_ASSIGNOP_Exp] = analyse_enumor_is_id_assign_exp,
	[AST_DeclnSpec_is_TypeSpec] = analyse_declnspec_is_typespec,
	[AST_DeclnSpec_is_TypeSpec_DeclnSpec] = analyse_declnspec_is_typespec_declnspec,
	[AST_DeclnSpec_is_TypeQulfr] = analyse_declnspec_is_typequlfr,
	[AST_DeclnSpec_is_TypeQulfr_DeclnSpec] = analyse_declnspec_is_typequlfr_declnspec,
	[AST_StarList_is_MULT] = analyse_starlist_is_mult,
	[AST_StarList_is_MULT_TypeQulfrList] = analyse_starlist_is_mult_typequlfrlist,
	[AST_StarList_is_MULT_StarList] = analyse_starlist_is_mult_starlist,
	[AST_StarList_is_MULT_TypeQulfrList_StarList] = analyse_starlist_is_mult_typequlfrlist_starlist,
	[AST_TypeQulfrList_is_TypeQulfr] = analyse_typequlfrlist_is_typequlfr,
	[AST_TypeQulfrList_is_TypeQulfrList_TypeQulfr] = analyse_typequlfrlist_is_typequlfrlist_typequlfr,
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

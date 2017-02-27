#include "front-com.h"

bool is_syntax_error = false;
bool is_print_inter_code = false;
int last_syntax_error;

typedef struct ident_info_t {
	char *id;
	type_t *type;//type system
	vi_t *vi;//vi->qulfr & QulfrConst == true for constant
	exp_const_part_t *cv;
} ident_info_t;

static int actionlevel = 0;
static mem_pool_t vipool;
static mem_pool_t idinfopool;
vec_t asv;//hash table vector

void backtrack_analyse_array_directdeclr(node_t *);

/* push variable into current hash table
 * IN[0]: char *
 *    variabe name
 * IN[1]: Spec*
 *    type pointer
 * IN[2]: node_t *
 *    AST node where variable bound to
 *
 * other influence:
 *    node->vi will be bound to a new vi.
 */
void push_variable(char *vn, type_t *type, node_t *node) {
	ident_info_t *ve = mempool_new(&idinfopool);
	vi_t *vi = mempool_new(&vipool);
	hash_table_t *ht = asv.p;
	ve->id = vn;
	ve->type = type;
	ve->vi = vi;
	ve->cv = &(node->cv);
	node->vi = vi;
	hash_push(&ht[actionlevel - 1], (void*)vn, strlen(vn), ve);
}

void increase_actionlevel() {
	actionlevel ++;
	hash_table_t *ht = vector_new(&asv);
	memset(ht, 0, sizeof(hash_table_t));
}

void decrease_actionlevel() {
	actionlevel --;
	vector_pop(&asv);
}

ident_info_t *find_variable(char *vn) {
	/* for struct and union: struct.id, union.id
	 * for actionlevel info, line@id
	 * combine: line@struct.id
	 */
	hash_table_t *ht = asv.p;
	for(int i = actionlevel - 1; i >= 0; i--) {
		ident_info_t *ve = hash_get(&ht[i], (void*)vn, strlen(vn));
		if(ve) return ve;
	}
	return NULL;
}

/* syntax analysis related function*/

void analyse_decln_is_declnspec(node_t *root) {
	//FIXME
	//node_t *declnspec = get_child_node_w(root, DeclnSpec);
	
}

int assign_value_of_enumorlist(node_t *enumorlist, int st) {
	//first child: enumorlist
	if(enumorlist->production == AST_EnumorList_is_EnumorList_COMMA_Enumor){
		node_t *subenumorlist = get_child_node_w(enumorlist, EnumorList);
		st = assign_value_of_enumorlist(subenumorlist, st);
	}
	//next child: enumor
	node_t *enumor = get_child_node_w(enumorlist, Enumor);
	if(enumor->production == AST_Enumor_is_ID) {
		enumor->cv._32 = st;
		return st + 1;
	}else{
		node_t *exp = get_child_node_w(enumor, Exp);
		st = exp->cv._32;
		enumor->cv._32 = st;
		return st + 1;
	}
}

void analyse_typespec(node_t *root) {
	root->dt = root->child->dt;
	root->cv.t = root->child->cv.t;//t records combine type
}

void analyse_enumspec(node_t *root) {
	root->dt = convert_btype_to_pointer(SpecTypeInt32);
	if(root->production == AST_EnumSpec_is_ENUM_ID) {
		return;
	}
	node_t *enumorlist = get_child_node_w(root, EnumorList);
	assign_value_of_enumorlist(enumorlist, 0);
}

void analyse_enumor_is_id(node_t *root) {
	node_t *idnode = get_child_node_w(root, ID);
	char *vn = idnode->cv.id;
	type_t *type = convert_btype_to_pointer(SpecTypeInt32);
	push_variable(vn, type, root);
}

void analyse_enumor_is_id_assign_exp(node_t *root) {
	node_t *exp = get_child_node_w(root, Exp);
	node_t *idnode = get_child_node_w(root, ID);
	char *vn = idnode->cv.id;
	int rel = get_type_relation(exp->dt->bt, exp->dt->bt);
	type_t *type = convert_btype_to_pointer(SpecTypeInt32);
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

void analyse_declnspec_is_typespec(node_t *root) {
	node_t *typespec = get_child_node_w(root, TypeSpec);
	root->dt = typespec->dt;
	root->cv.t = typespec->cv.t;//t records combine type
}

void analyse_declnspec_is_typespec_declnspec(node_t *root) {
	//combine ct, transmit ex
	node_t *typespec = get_child_node_w(root, TypeSpec);
	node_t *declnspec = get_child_node_w(root, DeclnSpec);
	root->cv.ex = declnspec->cv.ex;//transmit type qulfr
	/* structure of cv.t
	 * 31               15       7        0
	 * +----------------+--------+--------+
	 * |       ct       |   bt   |   0/1  |
	 * +----------------+--------+--------+
	 */
	if((typespec->cv.t & 1) && (declnspec->cv.t & 1)) {
		root->cv.t = typespec->cv.t | declnspec->cv.t;//t records combine type
		if((DWORD2_PART1(typespec->cv.t) & CombineTypeLong)
		&& (DWORD2_PART1(declnspec->cv.t) & CombineTypeLong)){
			root->cv.t |= (CombineTypeLongLong << 16);
		}
		int btype = convert_ctype2type(DWORD2_PART1(root->cv.t));
		if(btype == -1) {//invalid combination
			root->cv.t &= ~1;
			root->dt = convert_btype_to_pointer(SpecTypeBad);
		}else{
			root->dt = convert_btype_to_pointer(btype);
		}
	}else{
		//TODO:invalid combination
		//may need some strategies to report error to upper node so to
		//  omit further type combination
		root->cv.t &= ~1;
		//once fail to combine, transmit null spec to upper node
		root->dt = convert_btype_to_pointer(SpecTypeInt32);
		assert(0);
	}
}

void analyse_declnspec_is_typequlfr(node_t *root) {
	//default dt and ct, transmit ex
	node_t *typequlfr = get_child_node_w(root, TypeQulfr);
	root->cv.ex = typequlfr->cv.ex;//ex records combine qulfr
	root->cv.t = 1;//1 means combinable
	root->dt = convert_btype_to_pointer(SpecTypeInt32);//default to be int32 if no typespec found
}

void analyse_declnspec_is_typequlfr_declnspec(node_t *root) {
	//transmit dt and ct and combine qulfr
	node_t *typequlfr = get_child_node_w(root, TypeQulfr);
	node_t *declnspec = get_child_node_w(root, DeclnSpec);
	root->cv.ex = typequlfr->cv.ex | declnspec->cv.ex;//ex records combine qulfr
	root->cv.t = declnspec->cv.t;//deliver combine type to upper node
	root->dt = declnspec->dt;
}

//StarList
void analyse_starlist_is_mult(node_t *root) {
	//cv.t records pointer level
	//ex records qulfr
	root->dt = new_spec();
	root->dt->bt = SpecTypePointer;
	root->dt->comp.pl = 1;
}

void analyse_starlist_is_mult_typequlfrlist(node_t *root) {
	//StarList -> MULT TypeQulfrList
	//init pl, transmit qulfr
	node_t *typequlfrlist = get_child_node_w(root, TypeQulfrList);
	root->dt = new_spec();
	root->dt->bt = SpecTypePointer;
	root->dt->comp.pl = 1;
	root->cv.ex = typequlfrlist->cv.ex;//transmit qulfr
}

void analyse_starlist_is_mult_starlist(node_t *root) {
	//StarList -> MULT StarList
	//inc pl, transmit qulfr
	node_t *starlist = get_child_node_w(root, StarList);
	root->dt = starlist->dt;
	root->dt->comp.pl ++;
	root->cv.ex = starlist->cv.ex;//transmit qualifier
}

void analyse_starlist_is_mult_typequlfrlist_starlist(node_t *root) {
	//StarList -> MULT TypeQulfrList StarList
	//inc pl, combine qulfr
	node_t *starlist = get_child_node_w(root, StarList);
	node_t *typequlfrlist = get_child_node_w(root, TypeQulfrList);
	root->dt = starlist->dt;
	root->dt->comp.pl ++;
	root->cv.ex = starlist->cv.ex | typequlfrlist->cv.ex;//combine qulfr
}

//TypeQulfrList
void analyse_typequlfrlist_is_typequlfr(node_t *root) {
	//cv.ex records qulfr
	node_t *typequlfr = get_child_node_w(root, TypeQulfr);
	root->cv.ex = typequlfr->cv.ex;
}

void analyse_typequlfrlist_is_typequlfrlist_typequlfr(node_t *root) {
	node_t *typequlfr = get_child_node_w(root, TypeQulfr);
	node_t *typequlfrlist = get_child_node_w(root, TypeQulfrList);
	root->cv.ex = typequlfr->cv.ex | typequlfrlist->cv.ex;
}

//Declr
void analyse_declr_is_starlist_directdeclr(node_t *root) {
	//for `StarList` node, dt->comp->pl records pointer level,
	//  cv.ex records qulfr
	//assume directdeclr return comp type
	/* Declr
	 *   +--StarList --> pointer level and qualifier
	 *   |
	 *   +--DirectDeclr --> array, function, pure id
	 *
	 * note: array and pointer can be combined to complex type
	 */
	node_t *starlist = get_child_node_w(root, StarList);
	node_t *directdeclr = get_child_node_w(root, DirectDeclr);
	//FIXME: ex and str collide
	root->cv.ex = starlist->cv.ex;//qualifier
	root->cv.id = directdeclr->cv.id;
	//set dt, assume:
	//  1. DirectDeclr's dt has been filled
	//  2. StarList ...
	//since pointer's dt and array's dt hven't been backfilled,
	//here set default type `SpecTypeInt32` for them
	starlist->dt->comp.dt = convert_btype_to_pointer(SpecTypeUnknown);
	if(!directdeclr->dt) {
		root->dt = starlist->dt;
	}else if(directdeclr->dt->bt == SpecTypeFunction) {
		root->dt = starlist->dt;
		root->dt->func.ret = starlist->dt;
	}else if(directdeclr->dt->bt == SpecTypeArray){//array
		//  StarList(ptr)  +  DirectDeclr(arr)
		//FIXME:should be called by Decln
		backtrack_analyse_array_directdeclr(directdeclr);
		root->dt = directdeclr->dt;
		root->dt->bt = SpecTypeComplex;
		root->dt->comp.pl = starlist->dt->comp.pl;
	}else if(directdeclr->dt->bt == SpecTypePointer
		  || directdeclr->dt->bt == SpecTypeComplex){//pointer
		/* int * (* p);
		 *     ^ \---/
		 *     |   \->DirectDeclr
		 *     \->StarList  
		 */
		root->dt = directdeclr->dt;
		root->dt->comp.pl += starlist->dt->comp.pl;
	}else if(directdeclr->dt->bt == SpecTypeUnknown){
		// StarList(ptr) + pure id
		root->dt = starlist->dt;
		root->dt->comp.dt = convert_btype_to_pointer(SpecTypeUnknown);
	}else{
		//invalid
		assert(0);
		root->dt = convert_btype_to_pointer(SpecTypeBad);
	}
}

void analyse_declr_is_directdeclr(node_t *root) {
	//TODO: id and type
	node_t *directdeclr = get_child_node_w(root, DirectDeclr);
	type_t *drdt = directdeclr->dt;
	root->cv.ex = directdeclr->cv.ex;
	root->dt = drdt;//datatype
	root->cv.id = directdeclr->cv.id;//variable name
	//default type
	if(!drdt) {
		drdt = convert_btype_to_pointer(SpecTypeUnknown);
	}else if(drdt->bt == SpecTypeFunction){
		drdt->func.ret = convert_btype_to_pointer(SpecTypeUnknown);
	}else if(drdt->bt == SpecTypeArray){
		//FIXME:should be called by Decln
		backtrack_analyse_array_directdeclr(directdeclr);
		drdt->comp.dt = convert_btype_to_pointer(SpecTypeInt32);
	}
}


//IdList
void analyse_idlist(node_t *root) {
	if(root->production == AST_IdList_is_ID)
		root->cv.cnt = 1;
	else {
		node_t *child_idlist = get_child_node_w(root, IdList);
		root->cv.cnt = child_idlist->cv.cnt + 1;
	}
}

void backtrack_analyse_idlist(node_t *root) {
	//backfill, give up bottom-up fill
	//FIXME: root node has not yet set parent node while reducing
	//       algorithm using this production
	//need to be called by other analyse function who has
	//  nonterminal symbol IdList in its production
	int cnt = 0;
	type_t *default_argtype = convert_btype_to_pointer(SpecTypeInt32);
	char **varname = (char **)malloc(root->cv.cnt * sizeof(char *));
	type_t **funcarg = (type_t **)malloc(root->cv.cnt * sizeof(type_t *));
	node_t *idlist = root;
	//traverse child AST
	while(idlist) {
		node_t *idnode = get_child_node_w(idlist, ID);
		varname[cnt] = idnode->cv.id;
		funcarg[cnt] = default_argtype;
		//prepare for next iteration
		idlist = get_child_node(root, IdList);
		cnt ++;
	}
	//check cnt
	assert(root->cv.cnt == cnt);
	//set pstr
	root->cv.pid = varname;
	//set spec
	root->dt = new_spec();
	root->dt->bt = SpecTypeFunction;
	root->dt->func.argc = cnt;
	root->dt->func.argv = funcarg;
}


/* DirectDeclr
 *   -> ID {pure variable}
 *   -> ( Declr ) {nested declarator}
 *
 *   {array}
 *   -> self [ ConstExp ] {array}
 *   -> self [] {null array}
 *
 *   {function}
 *   -> self(ParaTypeList) {common function decalration}
 *   -> self(IdList) {argument's type default to be integer}
 *   -> self() {function without argument}
 *
 *   for DirectDeclr, node->vi need to be used,
 *     node->vi->qulfr store information of variable's qualifier
 *
 *   information needed for DirectDeclr:
 *     id: store the string of identifier
 *     cnt: record the number of array dimension
 *     t: identify this node is array or function, can be reached
 *        by node->dt
 *
 *   for DirectDeclr's production -> DirectDeclr' (...)
 *     if DirectDeclr' -> (Declr) and (Declr->dt == comp or ptr):
 *       note: report error if Declr->dt == array,
 *         no such type called function array
 *         error form: int (funcptr[2])(int, int);
 *       this is a function pointer [array]
 *     elif DirectDeclr' -> ID:
 *       this is pure function declarator:
 *     elif DirectDeclr' -> DirectDeclr index:
 *       invalid case, report error and terminate analysis
 *       or default behavior: set root->dt = DirectDeclr'->dt
 *     elif DirectDeclr' -> DirectDeclr (...)
 *       error form: int func(int, int)(int, int);
 *     fi
 *   endfor
 */
void analyse_directdeclr_is_id(node_t *root) {
	//transmit id's name
	node_t *idnode = get_child_node_w(root, ID);
	root->cv.id = idnode->cv.id;
	root->dt = convert_btype_to_pointer(SpecTypeUnknown);//need to be backfilled
}

void analyse_directdeclr_is_lp_declr_rp(node_t *root) {
	node_t *declr = get_child_node_w(root, Declr);
	root->dt = declr->dt;
	root->cv.id = declr->cv.id;//transmit id
}

type_t *combine_array_type_of_directdeclr(type_t *drdt, int production){
	/* DirectDeclr
	 *   ->  DirectDeclr [...]
	 *            |      \---/
	 *            |        \-> didt
	 *            \->drdt
	 *
	 *  bottom-up traverse
	 *  first null-index, then sized-index
	 *
	 *  first meet null-index, comp.nil = 1
	 *  then sized-index, comp.size ++, if null, error
	 *  if other production, error
	 *
	 *  FIXME:
	 *    int (a[2])[3];
	 */
	type_t *rtdt = drdt;
	if(!(drdt)) logw("check here!\n");

	if(production == AST_DirectDeclr_is_DirectDeclr_LB_RB) {
		//meet null-index
		if(drdt->bt == SpecTypeUnknown){//DirectDeclr' is ID
			//DirectDeclr -> id will set dt to SpecTypeUnknown
			//first meet
			rtdt = new_spec();
			rtdt->bt = SpecTypeArray;
			rtdt->comp.nil = 1;
		}else{
			//invalid case
			rtdt = convert_btype_to_pointer(SpecTypeBad);
			assert(0);
		}
	}else{
		if(drdt->bt == SpecTypeUnknown){
			//firstly meet sized index
			rtdt = new_spec();
			rtdt->bt = SpecTypeArray;
			rtdt->comp.size = 1;
			rtdt->comp.dt = convert_btype_to_pointer(SpecTypeUnknown);
		}else if(drdt->bt == SpecTypeArray){
			//n times to meet
			rtdt->comp.size ++;
		}else{
			//FIXME:invalid case
			assert(0);
			//default behavior:
			rtdt = convert_btype_to_pointer(SpecTypeBad);
		}
	}
	return rtdt;
}

void analyse_directdeclr_is_self_index(node_t *root) {
	//array
	//DirectDeclr -> DirectDeclr LB Exp RB
	//FIXME: record size of array
	node_t *directdeclr = get_child_node_w(root, DirectDeclr);
	root->cv.id = directdeclr->cv.id;//transmit id
	root->dt = combine_array_type_of_directdeclr(directdeclr->dt,
			AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB);
	//ConstValue of index will be checked in backtrack routine
}

void analyse_directdeclr_is_self_nullindex(node_t *root) {
	//array, use nullindex
	//FIXME
	node_t *directdeclr = get_child_node_w(root, DirectDeclr);
	root->cv.id = directdeclr->cv.id;//transmit id
	root->dt = combine_array_type_of_directdeclr(directdeclr->dt,
			AST_DirectDeclr_is_DirectDeclr_LB_RB);
}

void backtrack_analyse_array_directdeclr(node_t *root) {
	/* assume combine_array_type_of_directdeclr filter non-array
	 *  production, that means, traverse this child AST, the only
	 *  form of production is DirectDeclr -> DirectDeclr' index,
	 * but this can only be ensured in test stage
	 * eg. satisfy assumption
	 *   DirectDeclr -> DirectDeclr [...]
	 *                       |
	 *               /---------------\
	 *               DirectDeclr [...]
	 *                    \-> ID
	 *
	 * eg. dissatisfy assumption
	 *   DirectDeclr -> DirectDeclr [...]
	 *                       |
	 *               /---------------\
	 *               DirectDeclr (...)   DB: end analysis at here
	 *                    |                +------------------+
	 *            /---------------\        | note: DB donates |
	 *            DirectDeclr [...]        | default behavior |
	 *                 \-> ID              +------------------+
	 *
	 * end conditions from the above two examples
	 *    1. DirectDeclr non-index(report error)
	 *    2. DirectDeclr null-index
	 *
	 * rules of array:
	 *    1. the size of highest dimension can be null, which
	 *       occurs in Initor.
	 *       eg. int a[][2][3][4];
	 *    2. the size of all dimensions must be decided in common
	 *       variable declaration.
	 *
	 * another problem: who calls this function? 
	 *
	 * general principles:
	 *   once fail to deduce type of id, see it as int
	 */

	if(root->dt->bt != SpecTypeArray)
		return;
	int cnt = root->dt->comp.size;
	node_t *directdeclr = root;
	root->dt->comp.dim = (size_t *)malloc(directdeclr->dt->comp.size * sizeof(size_t));
	while(directdeclr) {
		if(directdeclr->production == AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB) {
			cnt --;
			node_t *exp = get_child_node_w(directdeclr, Exp);
			if(exp->cv.t == PrConstValue){
				root->dt->comp.dim[cnt] = exp->cv._32;
			} else {
				//FIXME
				assert(0);
			}
		}else if(directdeclr->production == AST_DirectDeclr_is_DirectDeclr_LB_RB) {
			root->dt->comp.nil = 1;
		}else{
			break;
		}
		directdeclr = get_child_node(directdeclr, DirectDeclr);
	}
	//check
	assert(cnt == 0);
}

type_t *combine_funcype_of_directdeclr(type_t *ddt, type_t *exdt) {
	/*eg.
	 * DirectDeclr -> DirectDeclr LP IdList RP
	 *                     ^      \----------/
	 *                    ddt         exdt
	 */
	if(ddt) {
		if(ddt->bt == SpecTypeUnknown){
			//eg. int (*func)(int, int)
			exdt->func.ret = ddt;
			ddt = exdt;
		}else if(ddt->bt == SpecTypeComplex
		      || ddt->bt == SpecTypePointer){
			//eg. int (*func[])(int, int)
			//eg. int (*func)(int, int)
			ddt->comp.dt = exdt;
		}else{
			//invalid
			//eg. int (a[2])(int, int);
			//    int a[2](int, int)
			//    int a(int, int)(int, int);
			//FIXME: call yyerrtype to format error information and
			//      set global variable is_syntax_error
			assert(0);
			//default behavior
			return convert_btype_to_pointer(SpecTypeBad);
		}
		return ddt;
	}else{
		//paralist->dt->btype = SpecTypeFunction
		//  the ret_spec of dt need to be backfilled in upper call
		return exdt;
	}
}

void analyse_directdeclr_is_func_paralist(node_t *root) {
	//func
	//assume directdeclr's dt and paralist's dt have been filled
	node_t *directdeclr = get_child_node_w(root, DirectDeclr);
	node_t *paralist = get_child_node_w(root, ParaTypeList);
	root->cv.id = directdeclr->cv.id;//transmit id
	root->dt = combine_funcype_of_directdeclr(directdeclr->dt, paralist->dt);
}

void analyse_directdeclr_is_func_idlist(node_t *root) {
	//func
	node_t *directdeclr = get_child_node_w(root, DirectDeclr);
	node_t *idlist = get_child_node_w(root, IdList);
	backtrack_analyse_idlist(idlist);
	root->cv.id = directdeclr->cv.id;//transmit id
	root->dt = combine_funcype_of_directdeclr(directdeclr->dt, idlist->dt);
}

void analyse_directdeclr_is_func_lp_rp(node_t *root) {
	//func
	type_t *funcdt = new_spec();
	node_t *directdeclr = get_child_node_w(root, DirectDeclr);
	root->cv.id = directdeclr->cv.id;//transmit id
	funcdt->bt = SpecTypeFunction;
	funcdt->func.argc = 0;
	root->dt = combine_funcype_of_directdeclr(directdeclr->dt, funcdt);
}

void analyse_paralist(node_t *root) {
	if(root->production == AST_ParaList_is_ParaDecln) {
		root->cv.cnt = 1;
	}else{
		node_t *child_paralist = get_child_node_w(root, ParaList);
		root->cv.cnt = child_paralist->cv.cnt + 1;
	}
}

void backtrack_analyse_paralist(node_t *root) {
	//declare !important: cv.pid <> cv.cnt
	//for each ParaDecln
	//    id and dt 
	int cnt = root->cv.cnt;
	//temporary strategy: traverse child AST twice
	//  since id and dt can't be put together
	node_t *paralist = root;
	char **varname = (char **)malloc(root->cv.cnt * sizeof(char *));
	type_t **funcarg = (type_t **)malloc(root->cv.cnt * sizeof(type_t *));
	while(paralist) {
		cnt --;
		node_t *paradecln = get_child_node_w(paralist, ParaDecln);
		varname[cnt] = paradecln->cv.id;
		funcarg[cnt] = paradecln->dt;
		//prepare for next iteration
		paralist = get_child_node(paralist, ParaList);
	}
	//check cnt
	assert(cnt == 0);
	//set root->cv.pid
	root->cv.pid = varname;
	//set root->dt
	root->dt = new_spec();
	root->dt->bt = SpecTypeFunction;
	root->dt->func.argc = root->cv.cnt;
	root->dt->func.argv = funcarg;
}

void analyse_paratypelist(node_t *root) {
	node_t *paralist = get_child_node_w(root, ParaList);
	backtrack_analyse_paralist(paralist);
	root->dt = paralist->dt;
	root->cv.pid = paralist->cv.pid;//pstr stores each argument's id
	if(get_child_node(root, ELLIPSIS)) {
		root->dt->func.ellipsis = 1;
	}
}

void backfill_declr_datatype(node_t *declnspec, node_t *declr) {
	/*  Spec  Declr
	 *   int   *p;
	 *    |     \->drdt
	 *    \-> supdt
	 */
	if(declr->dt) {
		//back fill declr->dt
		if(declr->dt->bt == SpecTypeUnknown) {
			declr->dt = declnspec->dt;
		}else if(declr->dt->bt == SpecTypeFunction) {
			declr->dt->func.ret = declnspec->dt;
		}else if(declr->dt->bt == SpecTypeComplex
			  || declr->dt->bt == SpecTypePointer
			  || declr->dt->bt == SpecTypeArray)
		{
			if(!declr->dt->comp.dt) {
				logw("check here :(\n");
			}else if(declr->dt->comp.dt->bt == SpecTypeUnknown){
				declr->dt->comp.dt = declnspec->dt;
			}else if(declr->dt->comp.dt->bt == SpecTypeFunction){
				declr->dt->comp.dt->func.ret = declnspec->dt;
			}else{
				logw("invalid case\n");
				assert(0);
			}
		}
	}else{
		logw("check here :(\n");
	}
}

/* ParaDecln -> DeclnSpec Declr --> id
 *                          ^---------+
 *              DeclnSpec AbstDeclr   |-> dt
 *                            ^-------+
 *                            +--> eg. *[3], *, [], no id
 *              DeclnSpec
 *                  ^---- for some specicial type,
 *                          eg. function pointer
 */

void analyse_paradecln_is_declnspec_declr(node_t *root) {
	node_t *declnspec = get_child_node_w(root, DeclnSpec);
	node_t *declr = get_child_node_w(root, Declr);
	root->cv.id = declr->cv.id;
	backfill_declr_datatype(declnspec, declr);
	root->dt = declr->dt;
}

void analyse_paradecln_is_declnspec_abstdeclr(node_t *root) {
	node_t *declnspec = get_child_node_w(root, DeclnSpec);
	node_t *abstdeclr = get_child_node_w(root, AbstDeclr);
	backfill_declr_datatype(declnspec, abstdeclr);
	root->dt = abstdeclr->dt;
}

void analyse_paradecln_is_declnspec(node_t *root) {
	node_t *declnspec = get_child_node_w(root, DeclnSpec);
	root->dt = declnspec->dt;
}

size_t register_member_to_uos_declnspec(type_t *dt, node_t *compdecln) {
	int top = dt->uos.size, off = 0;
	bool is_union = (dt->bt == SpecTypeUnion);
	node_t *declnspec = get_child_node_w(compdecln, DeclnSpec);
	node_t *typespec = find_child_node_w(declnspec, TypeSpec);
	uos_member_t *argv = &(dt->uos.argv[top]);
	if(typespec->production != AST_TypeSpec_is_CompSpec)
		return 0;

	if(dt->uos.size > 0) {
		if(is_union) {
			off = argv[-1].off;
		}else{
			off = argv[-1].off + argv[-1].w;
		}
		logd2("top.off:%d, top.w:%d, off:%d\n", argv[-1].off, argv[-1].w, off);
	}

	//anonymous struct
	//add member variables of compspec to dt
	node_t *compspec = get_child_node_w(typespec, CompSpec);
	type_t *ccdt = compspec->dt;
	uos_member_t *cc_argv = ccdt->uos.argv;
	for(int i = 0; i < ccdt->uos.size; i++) {
		argv[i].id = cc_argv[i].id;
		argv[i].off = off + cc_argv[i].off;
		argv[i].w = cc_argv[i].w;
		argv[i].dt = cc_argv[i].dt;
	}
	return ccdt->w;
}

size_t register_member_to_uos_compdeclr(type_t *dt, node_t *compdecln) {
	int top = dt->uos.size, cnt = 0;
	bool is_union = (dt->bt == SpecTypeUnion);
	int declr_w = 0, max_w = 0, off = 0, base = 0;
	uos_member_t *argv = &(dt->uos.argv[top]);
	node_t *compdeclrlist = get_child_node_w(compdecln, CompDeclrList);
	node_t *declnspec = get_child_node_w(compdecln, DeclnSpec);
	int bt = declnspec->dt->bt;
	if(dt->uos.size > 0) {
		if(is_union) {
			base = off = argv[-1].off;
		}else{
			base = off = argv[-1].off + argv[-1].w;
		}
		logd2("top.off=%d, top.w=%d, off=%d\n", argv[-1].off, argv[-1].w, off);
	}else{
		logd2("top=0, off=%d\n", off);
	}

	//traverse child node of compdeclrlist
	while(compdeclrlist) {
		node_t *compdeclr = get_child_node_w(compdeclrlist, CompDeclr);
		node_t *declr = get_child_node(compdeclr, Declr);
		node_t *exp = get_child_node(compdeclr, Exp);
		argv[cnt].off = off;
		argv[cnt].dt = compdeclr->dt;
		argv[cnt].id = declr ? declr->cv.id : NULL;
		switch(compdeclr->production) {
		case AST_CompDeclr_is_Declr:
			//int a;
			argv[cnt].w = 8 * compdeclr->dt->w;
			declr_w = 8 * compdeclr->dt->w;
			break;
		case AST_CompDeclr_is_COLON_Exp:
			//int :2;
			if(!(get_type_relation(bt, bt) & CBitop)){
				yyerr("error: bit-field '' has invalid type\n");
				assert(0);
			}else if(exp->cv._32 > declnspec->dt->w * 8) {
				yyerr("error: bit-field width exceeds type width\n");
				assert(0);
			}
			argv[cnt].w = exp->cv._32;
			declr_w = exp->cv._32;
			break;
		case AST_CompDeclr_is_Declr_COLON_Exp:
			//int a:2;
			//error: bitwise width exceeds type width
			if(!(get_type_relation(bt, bt) & CBitop)){
				yyerr("error: bit-field '' has invalid type\n");
				assert(0);
			}else if(exp->cv._32 > compdeclr->dt->w * 8) {
				yyerr("error: bit-field width exceeds type width\n");
				assert(0);
			}
			argv[cnt].w = exp->cv._32;
			declr_w = exp->cv._32;
			break;
		}

		cnt ++;
		if(is_union) {
			//union
			if(declr_w > max_w) max_w = declr_w;
		}else{
			off += declr_w;
		}
		compdeclrlist = get_child_node(compdeclrlist, CompDeclrList);
	}
	logd2("off=%d, declr_w=%d, max_w=%d, base=%d\n", off, declr_w, max_w, base);
	off = (is_union) ? max_w : off;
	return off - base;
}

size_t register_member_to_uos(type_t *dt, node_t *compdecln) {
	if(compdecln->production == AST_CompDecln_is_DeclnSpec_SEMI) {
		return register_member_to_uos_declnspec(dt, compdecln);
	}else{
		return register_member_to_uos_compdeclr(dt, compdecln);
	}
}

void analyse_compspec_is_comptype_id(node_t *root) {
	//TODO: transmit type by ID
	assert(0);
	printf("line %d: warning:\n", root->lineno);
}

void analyse_compspec_is_compdeclnlist(node_t *root) {
	int off = 0, max_w = 0, decln_w;
	type_t *stdt = new_spec();
	/*set root->dt*/
	root->dt = stdt;

	/* get CompType */
	node_t *comptype = get_child_node_w(root, CompType);

	/* flag of union */
	bool is_union = (comptype->child->token == UNION);

	/* set bt */
	stdt->bt = (is_union) ? SpecTypeUnion : SpecTypeStruct;

	/* get CompDeclnList child node */
	node_t *compdeclnlist = get_child_node_w(root, CompDeclnList);

	/*record number of member variable*/
	int memid_n = compdeclnlist->cv.cnt;

	/* alloc memory for type `stdt->uos.argv` */
	stdt->uos.argv = malloc(sizeof(uos_member_t) * memid_n);

	//FIXME: round address to times of 4
	while(compdeclnlist) {
		node_t *compdecln = get_child_node_w(compdeclnlist, CompDecln);
		decln_w = register_member_to_uos(stdt, compdecln);
		logd2("decln_w=%d\n", decln_w);
		compdeclnlist = get_child_node(compdeclnlist, CompDeclnList);
		stdt->uos.size += compdecln->cv.cnt;
		if(is_union) {
			//for union
			if(decln_w > max_w)
				max_w = decln_w;
		}else{
			off += decln_w;
		}
		logw("off=%d\n", off);
	}
	off = ((is_union) ? max_w : off);
	logd2("max_w=%d, decln_w=%d, off=%d\n", max_w, decln_w, off);
	stdt->w = ((off + 7) >> 3);
	node_t *idnode = get_child_node(root, ID);
	if(idnode) stdt->uos.id = idnode->cv.id;
	logd2("uos.size=%d, cv.cnt=%d\n", stdt->uos.size, memid_n);
	assert(stdt->uos.size == memid_n);
}

/* compdeclnlist, compdecln, compdeclrlist, compdeclr
 *  node->cv.cnt records number of member variable
 */
void analyse_compdeclnlist_is_compdecln(node_t *root) {
	node_t *compdecln = get_child_node_w(root, CompDecln);
	root->cv.cnt = compdecln->cv.cnt;
}

void analyse_compdeclnlist_is_compdeclnlist_compdecln(node_t *root) {
	node_t *compdeclnlist = get_child_node_w(root, CompDeclnList);
	node_t *compdecln = get_child_node_w(root, CompDecln);
	root->cv.cnt = compdeclnlist->cv.cnt + compdecln->cv.cnt;
}

void analyse_compdecln_is_declnspec(node_t *root) {
	//count anonymous struct/union
	node_t *declnspec = get_child_node_w(root, DeclnSpec);
	node_t *typespec = find_child_node_w(declnspec, TypeSpec);
	root->dt = declnspec->dt;//transmit dt
	assert(typespec != NULL);
	if(typespec->production == AST_TypeSpec_is_CompSpec) {
		char *uos = NULL;
		node_t *compspec = get_child_node_w(typespec, CompSpec);
		node_t *comptype = get_child_node_w(compspec, CompType);
		uos = comptype->production == AST_CompType_is_STRUCT ? 
			"struct" : "union";
		if(compspec->production == AST_CompSpec_is_CompType_ID_LC_CompDeclnList_RC) {
			node_t *idnode = get_child_node_w(compspec, ID);
			//inner struct declaration
			push_variable(sformat("%s@%s", uos, idnode->cv.id),
					compspec->dt, compspec);
		}else if(compspec->production == AST_CompSpec_is_CompType_LC_CompDeclnList_RC) {
			//anonymous inner struct
			node_t *compdeclnlist = get_child_node_w(compspec, CompDeclnList);
			root->cv.cnt = compdeclnlist->cv.cnt;
		}else{
			//struct ID;
			printf("line %d: warning:\n", root->lineno);
		}
	}else{
		//report warning
		printf("line %d: warning:\n", root->lineno);
	}
}

/* CompDecln -> DeclnSpec CompDeclrList SEMI
 *
 * DeclnSpec provides dt
 *
 * CompDeclrList -> CompDeclr
 *               -> CompDeclr COMMA CompDeclrList
 *
 * CompDeclr -> Declr
 *           -> COLON Exp //no influence
 *           -> Declr COLON Exp
 *
 */
void analyse_compdecln_is_declnspec_compdeclrlist(node_t *root) {
	node_t *declnspec = get_child_node_w(root, DeclnSpec);
	node_t *compdeclrlist = get_child_node_w(root, CompDeclrList);
	root->cv.cnt = compdeclrlist->cv.cnt;
	//backfill
	while(compdeclrlist) {
		node_t *compdeclr = get_child_node_w(compdeclrlist, CompDeclr);
		//omit case: COLON Exp
		backfill_declr_datatype(declnspec, compdeclr);
		compdeclrlist = get_child_node(compdeclrlist, CompDeclrList);
	}
}

void analyse_compdeclrlist_is_compdeclr(node_t *root) {
	node_t *compdeclr = get_child_node_w(root, CompDeclr);
	root->cv.cnt = compdeclr->cv.cnt;//in case of `COLON Exp`
}

void analyse_compdeclrlist_is_compdeclr_compdeclrlist(node_t *root) {
	node_t *compdeclrlist = get_child_node_w(root, CompDeclrList);
	root->cv.cnt = compdeclrlist->cv.cnt + 1;
}

void analyse_compdeclr_is_declr(node_t *root) {
	node_t *declr = get_child_node_w(root, Declr);
	root->cv.id = declr->cv.id;
	root->cv.cnt = 1;
	root->dt = declr->dt;
}

void analyse_compdeclr_is_colon_exp(node_t *root) {
	root->dt = convert_btype_to_pointer(SpecTypeUnknown);
	root->cv.cnt = 1;
}

void analyse_compdeclr_is_declr_colon_exp(node_t *root) {
	node_t *declr = get_child_node_w(root, Declr);
	root->cv.id = declr->cv.id;
	root->cv.cnt = 1;
	root->dt = declr->dt;
	/*-----*/
}

void analyse_exp_is_id(node_t *root) {
	//FIXME
	char *vn = get_child_node_w(root, ID)->cv.id;
	ident_info_t *ve = find_variable(vn);
	if(!ve) {
		yyerrtype(ErrorUndeclaredIdentifier, root->lineno, vn);
		root->dt = convert_btype_to_pointer(SpecTypeInt32);
	}else{
		root->dt = ve->type;
		if(ve->vi->qulfr & QulfrConst) {
		}
	}
}

void analyse_exp_is_num(node_t *root) {
	node_t *numnode = get_child_node_w(root, NUM);
	root->lrv = SpecRvalue;
	root->dt = convert_btype_to_pointer(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = numnode->cv.i;
}

void analyse_exp_is_nil(node_t *root) {
	root->lrv = SpecRvalue;
	root->dt = convert_btype_to_pointer(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = 0;
}

void analyse_exp_is_false(node_t *root) {
	root->lrv = SpecRvalue;
	root->dt = convert_btype_to_pointer(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = 0;
}

void analyse_exp_is_true(node_t *root) {
	root->lrv = SpecRvalue;
	root->dt = convert_btype_to_pointer(SpecTypeInt32);
	root->cv.t = PrConstValue;
	root->cv._32 = 1;
}

void analyse_exp_is_string(node_t *root) {
	//FIXME:
	node_t *strnode = get_child_node_w(root, STRING);
	root->lrv = SpecLvalue;
	root->dt = convert_btype_to_pointer(SpecTypeString);
	root->cv.str = strnode->cv.str;
}

void analyse_exp_is_literal(node_t *root) {
	node_t *charnode = get_child_node_w(root, LITERAL);
	root->lrv = SpecRvalue;
	root->dt = convert_btype_to_pointer(SpecTypeInt8);
	root->cv.t = PrConstValue;
	root->cv._8 = charnode->cv._8;
}

void analyse_exp_is_lp_exp_rp(node_t *root) {
	node_t *exp = get_child_node_w(root, Exp);
	root->dt = exp->dt;
	root->cv = exp->cv;
}

void analyse_exp_is_function_call(node_t *root) {
}

void analyse_exp_is_dot_member(node_t *root) {
}

void analyse_exp_is_ptr_member(node_t *root) {
}

void analyse_exp_is_inc_or_dec_exp(node_t *root) {
}

void analyse_exp_is_exp_inc_or_dec(node_t *root) {
}

void analyse_exp_is_take_addr(node_t *root) {
}

void analyse_exp_is_indirection(node_t *root) {
}

void analyse_exp_is_minus_exp(node_t *root) {
}

void analyse_exp_is_plus_exp(node_t *root) {
}

void analyse_exp_is_logic_not(node_t *root) {
}

void analyse_exp_is_arithmetic_not(node_t *root) {
}

void analyse_exp_is_relop(node_t *root) {
	//FIXME
	node_t *exp1 = get_child_node_w(root, Exp);
	node_t *exp2 = get_child_node_with_skip_w(root, Exp, 1);
	int rel = get_type_relation(exp1->dt->bt, exp2->dt->bt);
	root->lrv = SpecRvalue;
	root->dt = convert_btype_to_pointer(SpecTypeInt32);
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
	[AST_Declr_is_StarList_DirectDeclr] = analyse_declr_is_starlist_directdeclr,
	[AST_Declr_is_DirectDeclr] = analyse_declr_is_directdeclr,
	[AST_IdList_is_ID] = analyse_idlist,
	[AST_IdList_is_IdList_COMMA_ID] = analyse_idlist,
	[AST_DirectDeclr_is_ID] = analyse_directdeclr_is_id,
	[AST_DirectDeclr_is_LP_Declr_RP] = analyse_directdeclr_is_lp_declr_rp,
	[AST_DirectDeclr_is_DirectDeclr_LB_Exp_RB] = analyse_directdeclr_is_self_index,
	[AST_DirectDeclr_is_DirectDeclr_LB_RB] = analyse_directdeclr_is_self_nullindex,
	[AST_DirectDeclr_is_DirectDeclr_LP_ParaTypeList_RP] = analyse_directdeclr_is_func_paralist,
	[AST_DirectDeclr_is_DirectDeclr_LP_IdList_RP] = analyse_directdeclr_is_func_idlist,
	[AST_DirectDeclr_is_DirectDeclr_LP_RP] = analyse_directdeclr_is_func_lp_rp,
	[AST_ParaList_is_ParaDecln] = analyse_paralist,
	[AST_ParaList_is_ParaList_COMMA_ParaDecln] = analyse_paralist,
	[AST_ParaTypeList_is_ParaList] = analyse_paratypelist,
	[AST_ParaTypeList_is_ParaList_COMMA_ELLIPSIS] = analyse_paratypelist,
	[AST_ParaDecln_is_DeclnSpec_Declr] = analyse_paradecln_is_declnspec_declr,
	[AST_ParaDecln_is_DeclnSpec_AbstDeclr] = analyse_paradecln_is_declnspec_abstdeclr,
	[AST_ParaDecln_is_DeclnSpec] = analyse_paradecln_is_declnspec,
	[AST_CompSpec_is_CompType_ID_LC_CompDeclnList_RC] = analyse_compspec_is_compdeclnlist,
	[AST_CompSpec_is_CompType_LC_CompDeclnList_RC] = analyse_compspec_is_compdeclnlist,
	[AST_CompSpec_is_CompType_ID] = analyse_compspec_is_comptype_id,
	[AST_CompDeclnList_is_CompDecln_CompDeclnList] = analyse_compdeclnlist_is_compdeclnlist_compdecln,
	[AST_CompDeclnList_is_CompDecln] = analyse_compdeclnlist_is_compdecln,
	[AST_CompDecln_is_DeclnSpec_SEMI] = analyse_compdecln_is_declnspec,
	[AST_CompDecln_is_DeclnSpec_CompDeclrList_SEMI] = analyse_compdecln_is_declnspec_compdeclrlist,
	[AST_CompDeclrList_is_CompDeclr] = analyse_compdeclrlist_is_compdeclr,
	[AST_CompDeclrList_is_CompDeclr_COMMA_CompDeclrList] = analyse_compdeclrlist_is_compdeclr_compdeclrlist,
	[AST_CompDeclr_is_Declr] = analyse_compdeclr_is_declr,
	[AST_CompDeclr_is_COLON_Exp] = analyse_compdeclr_is_colon_exp,
	[AST_CompDeclr_is_Declr_COLON_Exp] = analyse_compdeclr_is_declr_colon_exp,
	
	[AST_Exp_is_ID] = analyse_exp_is_id,
	[AST_Exp_is_NUM] = analyse_exp_is_num,
	//[AST_Exp_is_Exp_RELOP_Exp] = analyse_exp_is_relop,
};

SemanFunc get_safe_seman_func(int production) {
	if(production < sizeof(analyse_function)/sizeof(analyse_function[0])) {
		return analyse_function[production];
	}else{
		return NULL;
	}
}

void syntax_analysis(node_t *root) {
	if(root->production != 0) {
		int production = root->production;
		SemanFunc func = get_safe_seman_func(production);
		if(func) func(root);
	}
}

void free_seman() {
	mempool_free(&vipool);
	mempool_free(&idinfopool);
	vector_free(&asv);
}

void scan_from_string(const char *string) {
	void yylex_destroy();
	void *yy_scan_string(const char *);
	void yy_switch_to_buffer(void *);
	void *buffer_state = yy_scan_string(string);
	yy_switch_to_buffer(buffer_state);
	yyparse();
	yylex_destroy();
}

int init_seman() {
	mempool_init(&vipool, sizeof(vi_t));
	mempool_init(&idinfopool, sizeof(ident_info_t));
	vector_init(&asv, sizeof(hash_table_t));
	increase_actionlevel();
#ifdef __DEBUG__
	UNIT_TEST_START;
	extern node_t *astroot;
	struct {
		int token;
		const char *sample;
		const char *format_string;
	} test_case[] = {
		//{DeclnSpec, "struct{int (*func)(int, int);int b;};", "void"},
		{CompSpec, "struct A {int a, b;};", "struct:8 {\n  int32_t a:0:32, b:32:32;\n}"},
		{CompSpec, "union {int a;int b;};", "union:4 {\n  int32_t a:0:32, b:0:32;\n}"},
		{CompSpec, "union {int a, b;};", "union:4 {\n  int32_t a:0:32, b:0:32;\n}"},
		{CompSpec, "union {int a, b:8, c; int d, e;};", "union:4 {\n  int32_t a:0:32, b:0:8, c:0:32, d:0:32, e:0:32;\n}"},
		{CompSpec, "struct {union {int a, b;}; int y;}x;", "struct:5 {\n  int32_t a:0:32, b:0:32, y:32:32;\n}"},
		{CompSpec, "struct {union {int a; int b;}; int y;}x;", "struct:5 {\n  int32_t a:0:32, b:0:32, y:32:32;\n}"},
		{CompSpec, "struct {struct {int a, b;} x, p; int y;}x;", "struct:20 {\n  struct:8 {\n    int32_t a:0:32, b:32:32;\n  } x:0:64, p:64:64;\n  int32_t y:128:32;\n}"},
		{CompSpec, "struct {union {int a, b;} x; int y;}x;", "struct:8 {\n  union:4 {\n    int32_t a:0:32, b:0:32;\n  } x:0:32;\n  int32_t y:32:32;\n}"},
		{CompSpec, "struct A {int a:8, :8;union{struct{int8_t x:8;} b;int8_t y;} y; int b;};", "struct:7 {\n  int32_t a:0:8, (null):8:8;\n  union:1 {\n    struct:1 {\n      char x:0:8;\n    } b:0:8;\n    char y:0:8;\n  } y:16:8;\n  int32_t b:24:32;\n}"},
		{CompSpec, "struct A {int a:8, :8;union{struct{int8_t x;};int8_t y;}; int b;};", "struct:7 {\n  int32_t a:0:8, (null):8:8;\n  char x:16:8, y:16:8;\n  int32_t b:24:32;\n}"},
		/*
		{DeclnSpec, "void a;", "void"},
		{DeclnSpec, "long long a;", "int64_t"},
		{DeclnSpec, "signed long a;", "int32_t"},
		{DeclnSpec, "unsigned long a;", "uint32_t"},
		{DeclnSpec, "signed long long a;", "int64_t"},
		{DeclnSpec, "unsigned long long a;", "uint64_t"},
		{Declr, "int * b;", "<TypeUnknown> *"},
		{Declr, "int (* b);", "<TypeUnknown> *"},
		{Declr, "int ** b;", "<TypeUnknown> **"},
		{Declr, "int *(* b);", "<TypeUnknown> **"},
		{Declr, "int ** b[];", "<NullType> **[]"},
		{Declr, "int *(* b[]);", "<NullType> **[]"},
		{Declr, "int ** b[2];", "<TypeUnknown> **[2]"},
		{Declr, "int *(* b[2]);", "<TypeUnknown> **[2]"},
		{Declr, "int ** b[][2];", "<NullType> **[][2]"},
		{Declr, "int ** b[1][2];", "<TypeUnknown> **[1][2]"},
		{Declr, "int ** b[][2][3];", "<NullType> **[][2][3]"},
		{Declr, "int func[];", "int32_t []"},
		{Declr, "int *func[];", "<NullType> *[]"},
		{Declr, "int *func[][2];", "<NullType> *[][2]"},
		{Declr, "int func[2];", "int32_t [2]"},
		{Declr, "int * extern *const *p;", "<TypeUnknown> ***"},
		{Declr, "int func(int, int);", "<TypeUnknown> (int32_t, int32_t)"},
		{Declr, "int (*func)(int, float);", "<UnknownType> (*)(int32_t, float)"},
		{Declr, "int (*func)(int(*p)(float,short), char);", "<UnknownType> (*)(int32_t (*)(float, int16_t), char)"},
		{Declr, "int (**func[2])(int, float);", "<UnknownType> (**[2])(int32_t, float)"},
		{Declr, "bool check_dupset(char *dupformat, void *set, size_t len, size_t unitsize, off_t off){}", "<TypeUnknown> (char *, void *, uint32_t, uint32_t, int32_t)"},
		*/
	};

	for(int i = 0; i < sizeof(test_case)/sizeof(test_case[0]); i++){
		//logw("at %d\n", i);
		scan_from_string(test_case[i].sample);
		node_t *target = find_child_node_w(astroot, test_case[i].token);
		char *sol = uos_format(target->dt);
		if(i == 9) {
			//print_ast(target);
			//printf("%s\n", sol);
		}
		if(strcmp(test_case[i].format_string, sol) != 0)
			logw("fail at %d\n", i);
		UNIT_TEST_STR_EQUAL(test_case[i].format_string, sol);
	}
	UNIT_TEST_END;
	assert(0);
#endif
}

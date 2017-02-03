#include "common.h"

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static uintptr_t specptr = 0;
Spec *specpool = NULL;
Spec *specindex = NULL;

void print_spec(Spec *type);
Spec *register_type_declnspec(Node *root);

Spec *get_spec_by_btype(int bt, int lv) {
	return NULL;
}

Spec *find_type_of_struct_member(Spec *type, char *vn, off_t *off){
	return NULL;
}

#define TYPE_CNT SpecTypeRen

static int type_relations[TYPE_CNT][TYPE_CNT];

void construct_type_relations() {
	for(int i = SpecTypeInt8; i < SpecTypeFloat64; i++) {
		for(int j = SpecTypeInt8; j < SpecTypeFloat64; j++) {
			type_relations[i][j] = CAssign | CAddSub | CMultDiv | CAndOr | CRelop | CLogic;
			if(i <= j) type_relations[i][j] |=CLessAccurate;
			if(i >= j) type_relations[i][j] |=CMoreAccurate;
		}
	}
	for(int i = SpecTypeInt8; i < SpecTypeFloat64; i++) {
		//float and/or bit
		type_relations[i][SpecTypeFloat32] &= ~CAndOr;
		type_relations[SpecTypeFloat32][i] &= ~CAndOr;
		type_relations[i][SpecTypeFloat64] &= ~CAndOr;
		type_relations[SpecTypeFloat64][i] &= ~CAndOr;
	}
	for(int i = SpecTypeInt8; i < SpecTypeUint64; i++) {
		//ptr op bit
		type_relations[i][SpecTypePointer] |= CAssign | CAddSub | CRelop | CLogic;
		type_relations[SpecTypePointer][i] |= CAssign | CAddSub | CRelop | CLogic;
		type_relations[i][SpecTypeFunc] |= CAssign | CAddSub | CRelop | CLogic;
		type_relations[SpecTypeFunc][i] |= CAssign | CAddSub | CRelop | CLogic;
		type_relations[i][SpecTypeString] |= CAssign | CAddSub | CRelop | CLogic;
		type_relations[SpecTypeString][i] |= CAssign | CAddSub | CRelop | CLogic;
	}
}

/*
 * function:
 *   return a new spec pointer point to a clean spec element
 */
Spec *new_spec() {
	wt_assert(specptr < MAX_SIZE);
	Spec *spec = &specpool[specptr ++];
	memset(spec, 0, sizeof(Spec));
	return spec;
}

void free_spec() {
}

/* function:
 *   return the basic size of bt
 */

void reset_spec_state() {
#define btype_register(_b, _w, _l) do {\
	specpool[specptr].bt = _b;\
	specpool[specptr].w = _w;\
	specpool[specptr].leftvalue  = _l;\
	specptr ++;\
} while(0)

	specptr = 0;
	btype_register(SpecTypeConst,    0, SpecLvalue);
	btype_register(SpecTypeConst,    0, SpecRvalue);
	btype_register(SpecTypeVoid,     4, SpecLvalue);
	btype_register(SpecTypeVoid,     4, SpecRvalue);
	btype_register(SpecTypeInt8,     1, SpecLvalue);
	btype_register(SpecTypeInt8,     1, SpecRvalue);
	btype_register(SpecTypeUint8,    1, SpecLvalue);
	btype_register(SpecTypeUint8,    1, SpecRvalue);
	btype_register(SpecTypeInt16,    2, SpecLvalue);
	btype_register(SpecTypeInt16,    2, SpecRvalue);
	btype_register(SpecTypeUint16,   2, SpecLvalue);
	btype_register(SpecTypeUint16,   2, SpecRvalue);
	btype_register(SpecTypeInt32,    4, SpecLvalue);
	btype_register(SpecTypeInt32,    4, SpecRvalue);
	btype_register(SpecTypeUint32,   4, SpecLvalue);
	btype_register(SpecTypeUint32,   4, SpecRvalue);
	btype_register(SpecTypeInt64,    8, SpecLvalue);
	btype_register(SpecTypeInt64,    8, SpecRvalue);
	btype_register(SpecTypeUint64,   8, SpecLvalue);
	btype_register(SpecTypeUint64,   8, SpecRvalue);
	btype_register(SpecTypeFloat32,  4, SpecLvalue);
	btype_register(SpecTypeFloat32,  4, SpecRvalue);
	btype_register(SpecTypeFloat64,  8, SpecLvalue);
	btype_register(SpecTypeFloat64,  8, SpecRvalue);
	specpool[specptr].leftvalue = SpecLvalue;
	specpool[specptr].actionlevel = 1;
	specpool[specptr].bt = SpecTypeComplex;
	specpool[specptr].comp.spec = &specpool[2 * SpecTypeInt8];
	specpool[specptr].comp.pl = 1;
	specptr ++;
	specpool[specptr].leftvalue = SpecRvalue;
	specpool[specptr].actionlevel = 1;
	specpool[specptr].bt = SpecTypeComplex;
	specpool[specptr].comp.spec = &specpool[2 * SpecTypeInt8];
	specpool[specptr].comp.pl = 1;
	specptr ++;
}

void init_spec() {
	reset_spec_state();
}

#include "common.h"

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static uintptr_t specptr = 0;
Spec specpool[MAX_SIZE];

void print_spec(Spec *type);
Spec *register_type_declnspec(Node *root);

Spec *get_spec_by_btype(int bt, int lv) {
	return NULL;
}

Spec *find_type_of_struct_member(Spec *type, char *vn, off_t *off){
	return NULL;
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

/* function:
 *   return the basic size of bt
 */

void reset_spec_state() {
#define bt_register(_b, _w, _l) do {\
	specpool[specptr].bt = _b;\
	specpool[specptr].w = _w;\
	specpool[specptr].leftvalue  = _l;\
	specptr ++;\
} while(0)

	specptr = 0;
	bt_register(SpecTypeConst,    0, SpecLvalue);
	bt_register(SpecTypeConst,    0, SpecRvalue);
	bt_register(SpecTypeVoid,     4, SpecLvalue);
	bt_register(SpecTypeVoid,     4, SpecRvalue);
	bt_register(SpecTypeInt8,     1, SpecLvalue);
	bt_register(SpecTypeInt8,     1, SpecRvalue);
	bt_register(SpecTypeUint8,    1, SpecLvalue);
	bt_register(SpecTypeUint8,    1, SpecRvalue);
	bt_register(SpecTypeInt16,    2, SpecLvalue);
	bt_register(SpecTypeInt16,    2, SpecRvalue);
	bt_register(SpecTypeUint16,   2, SpecLvalue);
	bt_register(SpecTypeUint16,   2, SpecRvalue);
	bt_register(SpecTypeInt32,    4, SpecLvalue);
	bt_register(SpecTypeInt32,    4, SpecRvalue);
	bt_register(SpecTypeUint32,   4, SpecLvalue);
	bt_register(SpecTypeUint32,   4, SpecRvalue);
	bt_register(SpecTypeInt64,    8, SpecLvalue);
	bt_register(SpecTypeInt64,    8, SpecRvalue);
	bt_register(SpecTypeUint64,   8, SpecLvalue);
	bt_register(SpecTypeUint64,   8, SpecRvalue);
	bt_register(SpecTypeFloat32,  4, SpecLvalue);
	bt_register(SpecTypeFloat32,  4, SpecRvalue);
	bt_register(SpecTypeFloat64,  8, SpecLvalue);
	bt_register(SpecTypeFloat64,  8, SpecRvalue);
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

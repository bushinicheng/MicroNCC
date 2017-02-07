#include "common.h"

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static MemPool specpool;

void print_spec(Spec *type);
Spec *register_type_declnspec(Node *root);

#define BTYPE_CNT (SpecTypeString + 1)

Spec *get_spec_by_btype(uint32_t bt) {
	if(bt >= BTYPE_CNT) {
		return NULL;
	}
	Spec *specptr = specpool.p[0];
	return &specptr[bt];
}

Spec *find_type_of_struct_member(Spec *type, char *vn, off_t *off){
	return NULL;
}

int convert_ctype2type(int ct) {
	if(ct & CombineTypeLongLong)
		ct &= ~CombineTypeLong;
	switch(ct) {
		case CombineTypeSigned|CombineTypeLong:
			return SpecTypeInt32;
		case CombineTypeUnsigned|CombineTypeLong:
			return SpecTypeUint32;
		case CombineTypeSigned|CombineTypeLongLong:
			return SpecTypeInt64;
		case CombineTypeUnsigned|CombineTypeLongLong:
			return SpecTypeUint64;
		case CombineTypeSigned|CombineTypeShort:
			return SpecTypeInt16;
		case CombineTypeUnsigned|CombineTypeShort:
			return SpecTypeUint16;
		case CombineTypeSigned|CombineTypeChar:
			return SpecTypeInt8;
		case CombineTypeUnsigned|CombineTypeChar:
			return SpecTypeUint8;
		case CombineTypeSigned|CombineTypeInt:
			return SpecTypeInt32;
		case CombineTypeUnsigned|CombineTypeInt:
			return SpecTypeUint32;
		case CombineTypeSigned|CombineTypeLongLong|CombineTypeInt:
			return SpecTypeInt64;
		case CombineTypeUnsigned|CombineTypeLongLong|CombineTypeInt:
			return SpecTypeUint64;
		case CombineTypeLongLong:
			return SpecTypeInt64;
		case CombineTypeLongLong|CombineTypeInt:
			return SpecTypeInt64;
		case CombineTypeLong|CombineTypeDouble:
			return SpecTypeFloat64;
	}
}


static const char *btype_format_string[] = {
	[SpecTypeInt8] = "char",
	[SpecTypeUint8] = "uchar",
	[SpecTypeInt16] = "int16_t",
	[SpecTypeUint16] = "uint16_t",
	[SpecTypeInt32] = "int32_t",
	[SpecTypeUint32] = "uint32_t",
	[SpecTypeInt64] = "int64_t",
	[SpecTypeUint64] = "uint64_t",
	[SpecTypeFloat32] = "float",
	[SpecTypeFloat64] = "double",
};

#define TYPE_CNT SpecTypeEnd

static int type_relations[TYPE_CNT][TYPE_CNT];

void construct_type_relations() {
	for(int i = SpecTypeInt8; i < SpecTypeFloat64; i++) {
		for(int j = SpecTypeInt8; j < SpecTypeFloat64; j++) {
			type_relations[i][j] = CAssign | CAddSub | CMultDiv | CBitop | CRelop | CLogic;
			if(i <= j) type_relations[i][j] |= CLessAccurate;
			if(i >= j) type_relations[i][j] |= CMoreAccurate;
		}
	}
	for(int i = SpecTypeInt8; i < SpecTypeFloat64; i++) {
		//float and/or bit
		type_relations[i][SpecTypeFloat32] &= ~CBitop;
		type_relations[SpecTypeFloat32][i] &= ~CBitop;
		type_relations[i][SpecTypeFloat64] &= ~CBitop;
		type_relations[SpecTypeFloat64][i] &= ~CBitop;
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

int get_type_relation(int btA, int btB) {
	if(btA < TYPE_CNT && btB < TYPE_CNT) {
		return type_relations[btA][btB];
	}
	return 0;
}

/*
 * function:
 *   return a new spec pointer point to a clean spec element
 */
Spec *new_spec() {
	Spec *spec = (Spec *)mempool_new(&specpool);
	memset(spec, 0, sizeof(Spec));
	return spec;
}

void free_spec() {
	mempool_free(&specpool);
}


/* IN[0]: struct tagSpec *
 *   type pointer
 * OUT[0]:char *
 *   string pointer
 * function:
 *   format given type to string
 */
char *type_format(Spec *type) {
	if(!type) return NULL;
	if(type->format_string) return type->format_string;
	if(type->bt == SpecTypeStruct)
		type->format_string = sformat("struct %s", type->struc.sn);
	else if(type->bt < SpecTypeString) {
		type->format_string = (char*)btype_format_string[type->bt];
	}

	if(type->bt == SpecTypeFunc)	{
		char **args_str = (char **)get_memory_pointer();
		require_memory(type->func.argc * sizeof(char *));
		char *ret_str = type_format(type->func.ret);
		for(int i = 0; i < type->func.argc; i++) {
			args_str[i] = type_format(type->func.argv[i]);
		}
		type->format_string = sformat("%s (%s)", ret_str, strjoin(args_str, type->func.argc, ", "));
	} else if(type->bt == SpecTypeComplex) {
		char *rawtype_str = type_format(type->comp.spec);
		char *star_str = strmul("*", type->comp.pl);

		int arr_size = 0;
		char *arr_str = (char *)get_memory_pointer();
		char *p = arr_str;
		for(int i = type->comp.size - 1; i >= 0; i--) {
			arr_size += sprintf(&p[arr_size], "[%lu]", type->comp.dim[i]);
		}
		require_memory(arr_size + 1);
		type->format_string = sformat("%s %s%s", rawtype_str, star_str, arr_str);
	}

	return type->format_string;
}

/* function:
 *   return the basic size of bt
 */

void reset_spec_state() {
#define btype_register(_b, _w) do {\
		spec = (Spec *)mempool_new(&specpool);\
		spec->bt = _b;\
		spec->w = _w;\
	} while(0)

	Spec *spec = NULL;
	Spec *specptr = (Spec *)specpool.p;
	btype_register(SpecTypeVoid,     4);
	btype_register(SpecTypeInt8,     1);
	btype_register(SpecTypeUint8,    1);
	btype_register(SpecTypeInt16,    2);
	btype_register(SpecTypeUint16,   2);
	btype_register(SpecTypeInt32,    4);
	btype_register(SpecTypeUint32,   4);
	btype_register(SpecTypeInt64,    8);
	btype_register(SpecTypeUint64,   8);
	btype_register(SpecTypeFloat32,  4);
	btype_register(SpecTypeFloat64,  8);
	//char*/string left value
	spec = (Spec *)mempool_new(&specpool);
	spec->bt = SpecTypePointer;
	spec->comp.spec = &specptr[2 * SpecTypeInt8];
	spec->comp.pl = 1;
}

void init_spec() {
	mempool_init(&specpool, sizeof(Spec));
	wt_assert(specpool.bs[0] > 32);
	construct_type_relations();
	reset_spec_state();
}

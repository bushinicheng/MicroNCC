#include "front-com.h"

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static MemPool specpool;

void print_spec(Spec *type);
Spec *register_type_declnspec(Node *root);

Spec *convert_btype_to_pointer(uint32_t bt) {
	if(bt >= SpecBTSeparator) return NULL;
	Spec *specptr = specpool.p[0];
	return &specptr[bt];
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
	return -1;
}

static size_t btype_width[] = {
	[SpecTypeInt8] = 1,
	[SpecTypeUint8] = 1,
	[SpecTypeInt16] = 2,
	[SpecTypeUint16] = 2,
	[SpecTypeInt32] = 4,
	[SpecTypeUint32] = 4,
	[SpecTypeInt64] = 8,
	[SpecTypeUint64] = 8,
	[SpecTypeFloat32] = 4,
	[SpecTypeFloat64] = 8,
	[SpecTypeString] = 4,
	[SpecTypeVoid] = 4,
	[SpecTypeBad] = 1,
	[SpecTypeUnknown] = 1,
};

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
	[SpecTypeVoid] = "void",
	[SpecTypeBad] = "<TypeBad>",
	[SpecTypeUnknown] = "<TypeUnknown>",
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
		type_relations[i][SpecTypeFunction] |= CAssign | CAddSub | CRelop | CLogic;
		type_relations[SpecTypeFunction][i] |= CAssign | CAddSub | CRelop | CLogic;
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
	if(!type) return "<NullType>";
#ifndef __DEBUG__
	if(type->format_string) return type->format_string;
#endif
	if(type->bt == SpecTypeStruct) {
		type->format_string = sformat("struct %s", type->uos.id);
		return type->format_string;
	}else if(type->bt == SpecTypeUnion){
		type->format_string = sformat("union %s", type->uos.id);
		return type->format_string;
	}else if(type->bt < SpecBTSeparator) {
		type->format_string = (char*)btype_format_string[type->bt];
		return type->format_string;
	}

	int total_length = 0;
	if(type->bt == SpecTypeFunction)	{
		char *retv_type = type_format(type->func.ret);
		char *func_type = (char *)get_memory_pointer();
		strcpy(func_type, retv_type);
		strcat(func_type, " (");
		for(int i = 0; i < type->func.argc; i++) {
			total_length = strlen(func_type);
			push_bpool_state(total_length + 1);
			char *arg_type = type_format(type->func.argv[i]);
			pop_bpool_state();
			strcat(func_type, arg_type);
			if(i != type->func.argc - 1)
				strcat(func_type, ", ");
			else
				strcat(func_type, ")");
		}
		total_length = strlen(func_type);
		type->format_string = require_memory(total_length + 1);
	} else if(type->bt == SpecTypePointer
			||type->bt == SpecTypeArray
			||type->bt == SpecTypeComplex) {
		/* some type of comp:
		 *   1. int **p[2];//dt => int
		 *   2. int (*func[3])(int a, int b);//dt => int(int, int)
		 *       ^  \--------/\------------/
		 *       |      !            \--> argv type
		 *       |  comp_type
		 *       +--return type
		 */
		Spec *dt = type->comp.dt;
		char *dt_type = type_format(dt);
		char *comp_type = get_memory_pointer();
		if(dt && dt->bt == SpecTypeFunction) {
			//case function pointer
			if(dt->func.ret) {
				strcpy(comp_type, type_format(dt->func.ret));
			}else{
				strcpy(comp_type, "<UnknownType>");
			}
			strcat(comp_type, " (");
			for(int i = 0; i < type->comp.pl; i++) {
				strcat(comp_type, "*");
			}
			total_length = strlen(comp_type);
			if(type->comp.nil)
				total_length += sprintf(comp_type + total_length, "[]");
			for(int i = 0; i < type->comp.size; i++) {
				//"[%d]" % (type->comp.dim[i])
				total_length += sprintf(comp_type + total_length, 
						"[%lu]", type->comp.dim[i]);
			}
			strcat(comp_type, ")");
			strcat(comp_type, strseek(dt_type, '('));
			total_length = strlen(comp_type);
			type->format_string = require_memory(total_length + 1);
		}else{
			strcpy(comp_type, dt_type);
			strcat(comp_type, " ");
			for(int i = 0; i < type->comp.pl; i++) {
				strcat(comp_type, "*");
			}
			total_length = strlen(comp_type);
			if(type->comp.nil)
				total_length += sprintf(comp_type + total_length, "[]");
			for(int i = 0; i < type->comp.size; i++) {
				//"[%d]" % (type->comp.dim[i])
				total_length += sprintf(comp_type + total_length, 
						"[%lu]", type->comp.dim[i]);
			}
			total_length = strlen(comp_type);
			type->format_string = require_memory(total_length + 1);
		}
	}

	return type->format_string;
}

/* function:
 *   return the basic size of bt
 */

void reset_spec_state() {
	Spec *specptr = specpool.p[0];
	int cnt = mempool_size(&specpool);
	for(int i = 0; i < (int)(SpecBTSeparator - cnt); i++)
		mempool_new(&specpool);
	for(int i = 0; i < SpecBTSeparator; i++) {
		specptr[i].bt = i;
		specptr[i].w = btype_width[i];
	}
	//char*/string
	specptr[SpecTypeString].bt = SpecTypePointer;
	specptr[SpecTypeString].comp.dt = &specptr[SpecTypeInt8];
	specptr[SpecTypeString].comp.pl = 1;
}

void init_spec() {
	mempool_init(&specpool, sizeof(Spec));
	assert(specpool.bs[0] > 32);//leave space for bt
	construct_type_relations();
	reset_spec_state();
#ifdef __DEBUG__
	UNIT_TEST_START;

	for(int i = 0; i < SpecBTSeparator; i++) {
		Spec *type = convert_btype_to_pointer(i);
		if(i != SpecTypeString){
			UNIT_TEST_EQUAL(type->bt, i);
			UNIT_TEST_EQUAL(type->w, btype_width[i]);
		}else{
			UNIT_TEST_EQUAL(type->bt, SpecTypePointer);
			UNIT_TEST_EQUAL(type->comp.pl, 1);
			UNIT_TEST_EQUAL(type->comp.dt->bt, SpecTypeInt8);
		}
	}

	Spec *func_type = new_spec();
	func_type->bt = SpecTypeFunction;
	func_type->func.ret = convert_btype_to_pointer(SpecTypeInt32);
	func_type->func.argc = 3;
	func_type->func.argv = (Spec **)malloc(sizeof(Spec *) * 3);
	func_type->func.argv[0] = convert_btype_to_pointer(SpecTypeInt32);
	func_type->func.argv[1] = convert_btype_to_pointer(SpecTypeInt32);
	func_type->func.argv[2] = convert_btype_to_pointer(SpecTypeInt32);
	UNIT_TEST_STR_EQUAL(type_format(func_type), "int32_t (int32_t, int32_t, int32_t)");

	Spec *ptr_type = new_spec();
	ptr_type->bt = SpecTypePointer;
	ptr_type->comp.pl = 4;
	ptr_type->comp.dt = convert_btype_to_pointer(SpecTypeInt32);
	UNIT_TEST_STR_EQUAL(type_format(ptr_type), "int32_t ****");

#ifndef __DEBUG__
	free(ptr_type->format_string);
#endif
	ptr_type->format_string = NULL;
	ptr_type->comp.dt = func_type;
	UNIT_TEST_STR_EQUAL(type_format(ptr_type), "int32_t (****)(int32_t, int32_t, int32_t)");

	Spec *arr_type = new_spec();
	arr_type->bt = SpecTypeArray;
	arr_type->comp.dt = convert_btype_to_pointer(SpecTypeInt32);
	arr_type->comp.size = 4;
	arr_type->comp.dim = (size_t *)malloc(sizeof(size_t) * 4);
	arr_type->comp.dim[0] = 1;
	arr_type->comp.dim[1] = 2;
	arr_type->comp.dim[2] = 3;
	arr_type->comp.dim[3] = 4;
	UNIT_TEST_STR_EQUAL(type_format(arr_type), "int32_t [1][2][3][4]");

	Spec *comp_type = new_spec();
	comp_type->bt = SpecTypeComplex;
	comp_type->comp.dt = convert_btype_to_pointer(SpecTypeInt32);
	comp_type->comp.pl = 1;
	comp_type->comp.size = 4;
	comp_type->comp.dim = (size_t *)malloc(sizeof(size_t) * 4);
	comp_type->comp.dim[0] = 1;
	comp_type->comp.dim[1] = 2;
	comp_type->comp.dim[2] = 3;
	comp_type->comp.dim[3] = 4;
	UNIT_TEST_STR_EQUAL(type_format(comp_type), "int32_t *[1][2][3][4]");

#ifndef __DEBUG__
	free(comp_type->format_string);
#endif
	comp_type->format_string = NULL;
	comp_type->comp.dt = func_type;
	UNIT_TEST_STR_EQUAL(type_format(comp_type), "int32_t (*[1][2][3][4])(int32_t, int32_t, int32_t)");

#ifndef __DEBUG__
	free(func_type->format_string);
#endif
	func_type->format_string = NULL;
	func_type = new_spec();
	func_type->bt = SpecTypeFunction;
	func_type->func.ret = convert_btype_to_pointer(SpecTypeInt32);
	func_type->func.argc = 3;
	func_type->func.argv = (Spec **)malloc(sizeof(Spec *) * 3);
	func_type->func.argv[0] = comp_type;
	func_type->func.argv[1] = convert_btype_to_pointer(SpecTypeInt32);
	func_type->func.argv[2] = convert_btype_to_pointer(SpecTypeInt32);
	UNIT_TEST_STR_EQUAL(type_format(func_type), "int32_t (int32_t (*[1][2][3][4])(int32_t, int32_t, int32_t), int32_t, int32_t)");

	UNIT_TEST_END;

#endif
}

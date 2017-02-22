#include "common.h"

//firstly need a pool for memory alloc

#define MAX_SIZE 1000000

static MemPool specpool;

void print_spec(Spec *type);
Spec *register_type_declnspec(Node *root);

#define BTYPE_CNT (SpecTypeString + 1)

Spec *get_spec_by_btype(uint32_t bt) {
	if(bt >= BTYPE_CNT) return NULL;
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
	if(!type) return NULL;
	if(type->format_string) return type->format_string;
	if(type->bt == SpecTypeStruct) {
		type->format_string = sformat("struct %s", type->uos.id);
		return type->format_string;
	}else if(type->bt == SpecTypeUnion){
		type->format_string = sformat("union %s", type->uos.id);
		return type->format_string;
	}else if(type->bt < SpecTypeString) {
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
	} else if(type->bt == SpecTypePointer) {
		/* some type of pointer:
		 *   1. int **p;//dt => int
		 *   2. int (*func)(int a, int b);//dt => int(int, int)
		 *       ^         \------------/
		 *       |                \--> argv type
		 *       +--return type
		 */
		Spec *dt = type->comp.dt;
		char *dt_type = type_format(dt);
		char *ptr_type = get_memory_pointer();
		if(dt->bt == SpecTypeFunction) {
			//case function pointer
			if(dt->func.ret) {
				strcpy(ptr_type, type_format(dt->func.ret));
			}else{
				strcpy(ptr_type, "int");
			}
			strcat(ptr_type, " (");
			for(int i = 0; i < type->comp.pl; i++) {
				strcat(ptr_type, "*");
			}
			strcat(ptr_type, ")");
			strcat(ptr_type, strseek(dt_type, '('));
			total_length = strlen(ptr_type);
			type->format_string = require_memory(total_length + 1);
		}else{
			//case common pointer
			strcpy(ptr_type, dt_type);
			strcat(ptr_type, " ");
			for(int i = 0; i < type->comp.pl; i++) {
				strcat(ptr_type, "*");
			}
			total_length = strlen(ptr_type);
			type->format_string = require_memory(total_length + 1);
		}
	} else if(type->bt == SpecTypeArray) {
		// int a[4][5]; //common array
		Spec *dt = type->comp.dt;
		char *dt_type = type_format(dt);
		if(!dt_type) dt_type = "<UnknownType>";
		char *arr_type = get_memory_pointer();
		strcpy(arr_type, dt_type);
		strcat(arr_type, " ");
		total_length = strlen(arr_type);
		for(int i = 0; i < type->comp.size; i++) {
			//"[%d]" % (type->comp.dim[i])
			total_length += sprintf(arr_type + total_length, 
					"[%lu]", type->comp.dim[i]);
		}
		total_length = strlen(arr_type);
		type->format_string = require_memory(total_length + 1);
	} else if(type->bt == SpecTypeComplex) {
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
		if(dt->bt == SpecTypeFunction) {
			//case function pointer
			if(dt->func.ret) {
				strcpy(comp_type, type_format(dt->func.ret));
			}else{
				strcpy(comp_type, "int");
			}
			strcat(comp_type, " (");
			for(int i = 0; i < type->comp.pl; i++) {
				strcat(comp_type, "*");
			}
			total_length = strlen(comp_type);
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
			//case common pointer
			strcpy(comp_type, dt_type);
			strcat(comp_type, " ");
			for(int i = 0; i < type->comp.pl; i++) {
				strcat(comp_type, "*");
			}
			total_length = strlen(comp_type);
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
	Spec *spec = NULL;
	Spec *specptr = (Spec *)specpool.p;
	for(int i = 0; i <= SpecTypeFloat64; i++) {
		spec = (Spec *)mempool_new(&specpool);
		spec->bt = i;
		spec->w = btype_width[i];
	}
	//char*/string
	spec = (Spec *)mempool_new(&specpool);
	spec->bt = SpecTypePointer;
	spec->comp.dt = &specptr[SpecTypeInt8];
	spec->comp.pl = 1;
	//void
	spec = (Spec *)mempool_new(&specpool);
	spec->bt = SpecTypeVoid;
	spec->w = 4;
}

void init_spec() {
	mempool_init(&specpool, sizeof(Spec));
	assert(specpool.bs[0] > 32);//leave space for bt
	construct_type_relations();
	reset_spec_state();

	UNIT_TEST_START;
	Spec *func_type = new_spec();
	func_type->bt = SpecTypeFunction;
	func_type->func.ret = get_spec_by_btype(SpecTypeInt32);
	func_type->func.argc = 3;
	func_type->func.argv = (Spec **)malloc(sizeof(Spec *) * 3);
	func_type->func.argv[0] = get_spec_by_btype(SpecTypeInt32);
	func_type->func.argv[1] = get_spec_by_btype(SpecTypeInt32);
	func_type->func.argv[2] = get_spec_by_btype(SpecTypeInt32);
	UNIT_TEST_STR_EQUAL(type_format(func_type), "int32_t (int32_t, int32_t, int32_t)");

	Spec *ptr_type = new_spec();
	ptr_type->bt = SpecTypePointer;
	ptr_type->comp.pl = 4;
	ptr_type->comp.dt = get_spec_by_btype(SpecTypeInt32);
	UNIT_TEST_STR_EQUAL(type_format(ptr_type), "int32_t ****");

	free(ptr_type->format_string);
	ptr_type->format_string = NULL;
	ptr_type->comp.dt = func_type;
	UNIT_TEST_STR_EQUAL(type_format(ptr_type), "int32_t (****)(int32_t, int32_t, int32_t)");

	Spec *arr_type = new_spec();
	arr_type->bt = SpecTypeArray;
	arr_type->comp.dt = get_spec_by_btype(SpecTypeInt32);
	arr_type->comp.size = 4;
	arr_type->comp.dim = (size_t *)malloc(sizeof(size_t) * 4);
	arr_type->comp.dim[0] = 1;
	arr_type->comp.dim[1] = 2;
	arr_type->comp.dim[2] = 3;
	arr_type->comp.dim[3] = 4;
	UNIT_TEST_STR_EQUAL(type_format(arr_type), "int32_t [1][2][3][4]");

	Spec *comp_type = new_spec();
	comp_type->bt = SpecTypeComplex;
	comp_type->comp.dt = get_spec_by_btype(SpecTypeInt32);
	comp_type->comp.pl = 1;
	comp_type->comp.size = 4;
	comp_type->comp.dim = (size_t *)malloc(sizeof(size_t) * 4);
	comp_type->comp.dim[0] = 1;
	comp_type->comp.dim[1] = 2;
	comp_type->comp.dim[2] = 3;
	comp_type->comp.dim[3] = 4;
	UNIT_TEST_STR_EQUAL(type_format(comp_type), "int32_t *[1][2][3][4]");

	free(comp_type->format_string);
	comp_type->format_string = NULL;
	comp_type->comp.dt = func_type;
	UNIT_TEST_STR_EQUAL(type_format(comp_type), "int32_t (*[1][2][3][4])(int32_t, int32_t, int32_t)");

	free(func_type->format_string);
	func_type->format_string = NULL;
	func_type->func.argv[0] = comp_type;
	UNIT_TEST_STR_EQUAL(type_format(func_type), "int32_t (int32_t (*[1][2][3][4])(int32_t, int32_t, int32_t), int32_t, int32_t)");

	UNIT_TEST_END;
}

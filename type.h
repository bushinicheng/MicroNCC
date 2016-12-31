#ifndef __TYPE_H__
#define __TYPE_H__

//basic data type
enum {
	SpecTypeConst,
	SpecTypeVoid,
	SpecTypeChar,
	SpecTypeInt,
	SpecTypeUnsigned,
	SpecTypeFloat,
	//the above is no need to spec
	SpecTypeStruct,
	SpecTypeUnion,
	SpecTypeFunc,
	SpecTypeArray
};

struct tagSpec;

typedef struct tagSinArg {
	struct tagSpec *type;
	char *varname;
} SinArg;

typedef struct tagSpec {
	int btype;
	int width;
	int plevel;//default to be zero
	union {
		struct {
			struct tagSpec *ret;
			SinArg *arglist;
			size_t argv;
		} func;//func type

		struct {
			struct tagSpec *spec;//actual spec,such as `struct A`
			size_t *dim;
			size_t size;//dimension
		} array;//for array

		struct {
			char *struc_name;
			struct {
				char *var_name;
				struct tagSpec *spec;
			} *varlist;
			size_t size;
		} struc;//for structure
	} type;
} Spec;


#endif

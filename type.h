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

typedef struct tagArgs {
	SinArg *arglist;
	size_t argv;
} Args;

typedef struct tagSpec {
	int btype;
	int width;
	union {
		struct {
			struct tagSpec *ret;
			Args *args;
		} func;//func type

		struct {
			size_t *dim;
			size_t size;//dimension
		} array;//for array

		struct {
			char *id;
			struct tagSpec *spec;
			size_t size;
		};//for structture
	} type;
} Spec;


#endif

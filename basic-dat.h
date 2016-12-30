#ifndef __BASIC_DAT_H__
#define __BASIC_DAT_H__

/* 表达式
 *
 */

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
	char *id;
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
			struct Spec *spec;
			size_t size;
		};//for structture
	} type;
} Spec;

typedef struct tagIdSet {
	char *id;
	char *idtype;
	Spec *type;
} IdSet;

typedef struct tagDebugInfo {
	int error;
	int first_line, first_column;
	int last_line, last_column;
} DebugInfo;

typedef struct tagNode {
	struct tagNode *sibling;
	struct tagNode *child;
	struct tagNode *parent;

	/* lex structure */
	int lexval;//token defined in lexical.l
	int syntaxval;//syntax value like `Program`
	int semanval;//semantic value like `AST_Exp_is_ID`

	/*type*/
	Spec *idtype;//const or not const all don't have idval
	//for variable
	int base_type;//0 for code area
				  //1 for global data
				  //2 for local stack
	uintptr_t base_addr;
	size_t var_size;//structure need size

	//for constant, such as "hello", 12, 5.1
	int idvaltype;
	union {
		int i;float f;double llf;void *p;
		char* st;
		uintptr_t da;//may be structure or function
	} idval;

	/* for debugging */
	int error;
	int lineno, column;
} Node, *PNode;

extern Node* astroot;
extern DebugInfo debug;


#endif

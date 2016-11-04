#ifndef __BASIC_DAT_H__
#define __BASIC_DAT_H__

/* 表达式
 *
 */

enum {
	SpecTypeNone,
	SpecTypeVoid,
	SpecTypeChar,
	SpecTypeInt,
	SpecTypeUnsigned,
	SpecTypeFloat,
	SpecTypeStruct,
	SpecTypeUnion,
	SpecTypeFunc,
	SpecTypeDef,
	SpecTypeArray,
	SpecTypePointer
};

typedef struct tagSpec {
	char *id;
	int type;
	int width;
	struct tagSpec *sibling;
	struct tagSpec *child;
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
	int specval;//spec token like `float` or `int` of token `NUM`
	union {
		int i;float f;double llf;void *p;
		char* st;
	} exval;

	/*type*/
	Spec *idtype;
	uintptr_t raddr;

	/* for debugging */
	int error;
	int lineno, column;
} Node, *PNode;

extern Node* astroot;
extern DebugInfo debug;

#endif

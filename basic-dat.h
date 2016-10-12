#ifndef __BASIC_DATA_H__
#define __BASIC_DATA_H__

#include "syntax.h"

/* 表达式
 *
 */

typedef struct tagNodeInfo {
	yytokentype lexval;
	union {
		int i;float f;double llf;void *p;
		int st;
	} val;
} NodeInfo;

typedef struct tagDebugInfo {
	int error;
	int first_line, first_column;
	int last_line, last_column;
} DebugInfo;

typedef struct tagNode {
	struct tagNode *sibling;
	struct tagNode *child;
	NodeInfo ni;
	DebugInfo di;
} Node, *PNode;

extern PNode astroot;
extern DebugInfo debug;

#endif

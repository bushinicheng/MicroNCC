#ifndef __BASIC_DAT_H__
#define __BASIC_DAT_H__

/* 表达式
 *
 */

typedef struct tagNodeInfo {
	int lexval;
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

extern Node astroot;
extern DebugInfo debug;

#endif

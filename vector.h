#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <malloc.h>

/* WARNING:
 * 1. the vector_init macro is'nt atmoic, 
 *    don't use it as a single statement.
 * 2. the action scope is binded to inputed varible p,
 *    any copy of p in other scope is useless.
 * */

#define vector_init(type, p) \
	struct { \
		int __vector_stack_size, __vector_stack_pointer; \
		type *__vector_stack; \
	} __vector_##p; \
	__vector_##p.__vector_stack_pointer = 0; \
	__vector_##p.__vector_stack_size = 8; \
	__vector_##p.__vector_stack = (type *)malloc(sizeof(type)*8);\
	p = __vector_##p.__vector_stack;

#define vector_push(type, p, e) \
	do { \
		if(__vector_##p.__vector_stack_pointer < __vector_##p.__vector_stack_size) \
		{\
			__vector_##p.__vector_stack[__vector_##p.__vector_stack_pointer ++] = e;\
		}\
		else \
		{\
			type *__new_p = (type *)malloc(sizeof(type)*__vector_##p.__vector_stack_size*2); \
			for(int i = 0; i < __vector_##p.__vector_stack_pointer; i++)\
			{\
				__new_p[i] = p[i];\
			}\
			free(p);\
			__vector_##p.__vector_stack = __new_p; \
			p = __new_p;\
			__vector_##p.__vector_stack_size *= 2; \
			__vector_##p.__vector_stack[__vector_##p.__vector_stack_pointer ++] = e;\
		}\
	} while(0)

#define vector_pop(p) \
	do {\
		if(__vector_##p.__vector_stack_pointer > 0) \
			__vector_##p.__vector_stack_pointer --; \
	}while(0)

#define vector_free(p) \
	free(p)

#endif

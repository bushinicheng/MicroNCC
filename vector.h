#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <malloc.h>

/* WARNING:
 * 1. the vector_init macro is'nt atmoic, 
 *    don't use it as a single statement.
 * 2. the action scope is binded to inputed varible p,
 *    any copy of p is invalid.
 * 3. ...
 * */

#define vector_init(type, p) \
	static int __vector_initializer_of_##p = 0;\
	static int __vector_pointer_of_##p = 0; \
	static int __vector_size_of_##p = 16;\
	if(__vector_initializer_of_##p == 0) \
	{ \
		p = (type *)malloc(sizeof(type)*__vector_size_of_##p); \
		__vector_initializer_of_##p = 1; \
	}

#define vector_push(p, e) \
	do { \
		if(__vector_pointer_of_##p >= __vector_size_of_##p) \
		{\
			__vector_size_of_##p *= 2; \
			__typeof__(e) *__new_p = (__typeof__(e) *)malloc(sizeof(__typeof__(e))*__vector_size_of_##p); \
			for(int i = 0; i < __vector_pointer_of_##p; i++)\
			{\
				__new_p[i] = p[i];\
			}\
			free(p);\
			p = __new_p;\
		}\
		p[__vector_pointer_of_##p ++] = (e);\
	} while(0)

#define vector_pop(p) \
	do {\
		if(__vector_pointer_of_##p > 0) \
			__vector_pointer_of_##p --; \
	}while(0)

#define vector_top(p) \
	p[__vector_pointer_of_##p - 1]

#define vector_size(p) __vector_pointer_of_##p

#define vector_free(p) \
	if(__vector_initializer_of_##p == 1) \
	{ \
		free(p); \
		__vector_initializer_of_##p = 0; \
	}

#endif

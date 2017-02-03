#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <malloc.h>

typedef struct Vector {
	size_t unit_size;
	size_t size;
	off_t ptr;
	void *p;
} Vector;

void vector_init(Vector *v, size_t unit_size);
void vector_push(Vector *v, void *t);
void *vector_pop(Vector *v);
void vector_resize(Vector *v, size_t size);
void vector_free(Vector *v);

#endif

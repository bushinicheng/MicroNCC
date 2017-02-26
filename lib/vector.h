#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <malloc.h>

typedef struct vec_t {
	size_t unit_size;
	size_t size;
	off_t ptr;
	void *p;
} vec_t;

void vector_init(vec_t *v, size_t unit_size);
void *vector_new(vec_t *v);
void vector_push(vec_t *v, void *t);
void *vector_pop(vec_t *v);
void vector_resize(vec_t *v, size_t size);
void vector_free(vec_t *v);

#endif

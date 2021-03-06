#include <time.h>

void vector_init(vec_t *v, size_t unit_size) {
	v->ptr = 0;
	v->unit_size = unit_size;
	v->size = 128 * v->unit_size;
	v->p = malloc(v->size);
}

void *vector_new(vec_t *v) {
	if(!v->size) return NULL;
	int oldptr = v->ptr;
	if(v->ptr >= v->size) {
		v->size *= 2;
		v->p = realloc(v->p, v->size);
	}
	v->ptr += v->unit_size;
	return (v->p + oldptr);
}

void vector_push(vec_t *v, void *t) {
	void *p = vector_new(v);
	memcpy(p, t, v->unit_size);
}

void *vector_pop(vec_t *v) {
	if(v->ptr > 0) {
		v->ptr -= v->unit_size;
		return (v->p + v->ptr);
	}else{
		return NULL;
	}
}

void *vector_ptr(vec_t *v) {
	return v->p;
}

void *vector_top(vec_t *v) {
	if(v->ptr > 0) {
		return (v->p + v->ptr - v->unit_size);
	}else{
		return NULL;
	}
}

void vector_resize(vec_t *v, size_t size) {
	v->size = v->unit_size * size;
	v->p = realloc(v->p, v->size);
}

size_t vector_size(vec_t *v) {
	return v->ptr / v->unit_size;
}

void vector_free(vec_t *v) {
	free(v->p);
	v->size = 0;
	v->ptr = 0;
}

int init_vector()
{
#ifdef __DEBUG__
	srand(time(NULL));
	UNIT_TEST_START;
	vec_t v;
	const int test_size = 65536;
	int ans[test_size], pans = 0, num;
	vector_init(&v, sizeof(int));
	for(int i = 0; i < test_size; i++) {
		num = rand();
		if(rand()%16==0 && pans > 0) {
			pans --;
			vector_pop(&v);
		}else{
			ans[pans++] = num;
			vector_push(&v, &num);
		}
	}

	/*test push operation*/
	int *p = (int*)(v.p);
	for(int i = 0; i < pans; i++) {
		UNIT_TEST_ASSERT(p[i] == ans[i], \
			"\nfail at case #%d, should be '%d' but got '%d'", i, ans[i], p[i]);
	}

	UNIT_TEST_ASSERT(pans == vector_size(&v), \
			"\ntest failed: inconsistent vector size..");
	vector_free(&v);
	UNIT_TEST_END;

#endif
	return 0;
}

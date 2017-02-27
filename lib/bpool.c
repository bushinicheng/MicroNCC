//#include "common.h"

/* memory can be alloced without size
 * act like variable-length array
 */

#define POOL_SIZE (1024*1024)
static int toggle_caller_state = 0;
static uint32_t ptr = 0;
static uint8_t bpool[POOL_SIZE];
static vec_t bpool_state_stack;

void *wt_alloc(size_t size) {
	void *ptr = malloc(size);
	memset(ptr, 0, size);
	if(!ptr) loge("memory shortage\n");
	return ptr;
}

void *wt_realloc(void *ptr, size_t oldsize, size_t newsize) {
	if(newsize <= oldsize) return ptr;
	void *ret = malloc(newsize);
	if(!ret) loge("memory shortage\n");
	memset(ret, 0, newsize);
	memcpy(ret, ptr, oldsize);
	free(ptr);
	return ret;
}

void mempool_init(mem_pool_t *mp, size_t unit_size) {
	mp->unit_size = unit_size;
	//index
	mp->index_ptr = 0;
	mp->block_ptr = 0;
	//index size
	mp->index_size = 1;
	mp->bs = (size_t*)malloc(sizeof(size_t) * mp->index_size);
	mp->p = (void **)malloc(sizeof(void*) * mp->index_size);
	//first block size
	mp->bs[0] = 1024 * unit_size;
	mp->p[0] = (void *)malloc(mp->bs[0]);
}

size_t mempool_size(mem_pool_t *mp) {
	if(mp->index_ptr == 0) {
		//most common case
		return mp->block_ptr / mp->unit_size;
	}else{
		int i, total_size = 0;
		for(i = 0; i < mp->index_ptr; i++)
			total_size += mp->bs[i];
		total_size += mp->bs[i];
		return total_size / mp->unit_size;
	}
}

void *mempool_new(mem_pool_t *mp) {
	if(!mp->index_size) return NULL;
	void *ret = NULL;
	if(mp->block_ptr < mp->bs[mp->index_ptr]) {
		//most common case
		ret = mp->p[mp->index_ptr] + mp->block_ptr;
		mp->block_ptr += mp->unit_size;
		memset(ret, 0, mp->unit_size);
		return ret;
	}else{
		if(mp->index_ptr >= mp->index_size) {
			mp->index_size *= 2;
			mp->bs = realloc(mp->bs, sizeof(size_t) * mp->index_size);
			mp->p = realloc(mp->p, sizeof(void*) * mp->index_size);
		}
		mp->block_ptr = 0;
		mp->index_ptr ++;
		mp->bs[mp->index_ptr] = mp->bs[mp->index_ptr - 1] * 2;
		mp->p[mp->index_ptr] = malloc(mp->bs[mp->index_ptr]);
		ret = mp->p[mp->index_ptr] + mp->block_ptr;
		mp->block_ptr += mp->unit_size;
		memset(ret, 0, mp->unit_size);
		return ret;
	}
}

void mempool_free(mem_pool_t *mp) {
	for(int i = 0; i < mp->index_size; i++) {
		if(mp->p[i]) free(mp->p[i]);
	}
	free(mp->p);
	free(mp->bs);
	mp->index_size = 0;
	mp->index_ptr = 0;
	mp->block_ptr = 0;
}

/* 320012162211825
 * 0--\
 *    get_memory_pointer
 * 1--<
 *    push_bpool_state
 * 2--<
 *    pop_bpool_state
 * 3--<
 *    require_memory
 * 0--/
 */

void *get_memory_pointer() {
	if(toggle_caller_state != 0 && toggle_caller_state != 2) {
		logw("state:%d, some function else has hold the memptr\n", toggle_caller_state);
	}
#ifdef __DEBUG_BPOOL__
	logd2("%s, ptr: %d.\n", __func__, ptr);
#endif
	toggle_caller_state = 1;
	return &bpool[ptr];
}

void push_bpool_state(off_t op) {
	toggle_caller_state = 2;
#ifdef __DEBUG_BPOOL__
	logd2("%s, ptr: %d --> %d.\n", __func__, ptr, ptr + op);
#endif
	vector_push(&bpool_state_stack, &ptr);
	ptr = ptr + op;
}

void pop_bpool_state() {
	int *p = vector_pop(&bpool_state_stack);
	if(!p) loge("bpool state stack should not be empty.\n");
	toggle_caller_state = 3;
#ifdef __DEBUG_BPOOL__
	logd2("%s, ptr: %d --> %d.\n", __func__, ptr, p[0]);
#endif
	ptr = p[0];
}

void *require_memory(size_t size) {
	toggle_caller_state = 0;
	if(!size) return NULL;
	void *ret = malloc(size);
#ifdef __DEBUG_BPOOL__
	logd2("%s, ptr:%d, size %d.\n", __func__, ptr, size);
#endif
	memcpy(ret, &bpool[ptr], size);
	assert(ptr + size <= POOL_SIZE);
	return ret;
}

int init_bpool() {
	vector_init(&bpool_state_stack, sizeof(off_t));
#ifdef __DEBUG__
	UNIT_TEST_START;
	mem_pool_t mp;
	mempool_init(&mp, sizeof(int));
	const int test_size = 65536;
	int *pt[test_size];
	for(int i = 0; i < test_size; i++) {
		pt[i] = mempool_new(&mp);
		pt[i][0] = i;
	}

	for(int i = 0; i < test_size; i++) {
		UNIT_TEST_EQUAL(pt[i][0], i);
	}
	mempool_free(&mp);
	UNIT_TEST_END;
#endif
	return 0;
}

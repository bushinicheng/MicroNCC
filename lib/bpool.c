//#include "common.h"

/* memory can be alloced without size
 * act like variable-length array
 */

#define POOL_SIZE (1024*1024)
static int toggle_caller_state = 0;
static uint32_t ptr = 0;
static uint8_t bpool[POOL_SIZE];
static Vector bpool_state_stack;

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

void mempool_init(MemPool *mp, size_t unit_size) {
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

size_t mempool_size(MemPool *mp) {
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

void *mempool_new(MemPool *mp) {
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

void *mempool_free(MemPool *mp) {
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
	toggle_caller_state = 1;
	return &bpool[ptr];
}

void push_bpool_state(off_t op) {
	toggle_caller_state = 2;
	vector_push(&bpool_state_stack, &ptr);
	ptr = op;
}

void pop_bpool_state() {
	int *p = vector_pop(&bpool_state_stack);
	if(!p) loge("bpool state stack should not be empty.\n");
	toggle_caller_state = 3;
	ptr = p[0];
}

void *require_memory(size_t size) {
	toggle_caller_state = 0;
	if(!size) return NULL;
	void *ret = malloc(size);
	memcpy(ret, &bpool[ptr], size);
	assert(ptr + size <= POOL_SIZE);
	return ret;
}

char *strmul(char *str, int dup) {
	int len = strlen(str);
	char *ret = get_memory_pointer();
	char *p = ret;
	for(int i = 0; i < dup; i++) {
		strcpy(p, str);
		p += len;
	}
	return require_memory(len * dup + 1);
}

char *strjoin(char **strlist, int size, char *delim) {
	char *ret = get_memory_pointer();
	char *p = ret;
	int delimlen = strlen(delim);
	for(int i = 0; i < size; i++) {
		strcpy(p, strlist[i]);
		p += strlen(strlist[i]);
		if(i != size - 1) {
			strcpy(p, delim);
			p += delimlen;
		}
	}
	return require_memory((size_t)p - (size_t)ret + 1);
}

int strcnt(const char *strin, char ch) {
	int ret = 0;
	char *p = (char*)strin;
	do{ret+=(*p==ch);}while(*p++);
	return ret;
}

char *strseek(const char *strin, char ch) {
	while(*strin && *strin != ch) {
		strin ++;
	}
	if(*strin == ch)
		return (char *)strin;
	else
		return NULL;
}

int init_bpool() {
	vector_init(&bpool_state_stack, sizeof(off_t));
#ifdef __DEBUG__
	UNIT_TEST_START;
	MemPool mp;
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
}

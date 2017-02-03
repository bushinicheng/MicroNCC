#include "common.h"

/* memory can be alloced without size
 * act like variable-length array
 */

#define POOL_SIZE (16*1024*1024)
static int toggle = 0;
static uintptr_t ptr = 0;
static uint8_t bpool[POOL_SIZE];

void *wt_alloc(size_t size) {
	void *ptr = malloc(size);
	if(!ptr) loge("memory shortage\n");
	return ptr;
}

void *wt_realloc(size_t size, void *prev_page) {
	void *ptr = realloc(ptr, size);
	if(!ptr) loge("memory shortage\n");
	return ptr;
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
	mp->bs[0] = 1 * unit_size;
	mp->p[0] = (void *)malloc(mp->bs[0]);
}

void *mempool_new(MemPool *mp) {
	void *ret = NULL;
	if(mp->block_ptr < mp->bs[mp->index_ptr]) {
		//most common case
		ret = mp->p[mp->index_ptr] + mp->block_ptr;
		mp->block_ptr += mp->unit_size;
		return ret;
	}else{
		if(mp->index_ptr >= mp->index_size) {
			mp->index_size *= 2;
			mp->bs = realloc(mp->bs, sizeof(size_t) * mp->index_size);
			mp->p = realloc(mp->p, sizeof(void*) * mp->index_size);
		}
		mp->block_ptr = 0;
		mp->index_ptr ++;
		if(!mp->p[mp->index_ptr]) {
			mp->bs[mp->index_ptr] = mp->bs[mp->index_ptr - 1] * 2;
			mp->p[mp->index_ptr] = malloc(mp->bs[mp->index_ptr]);
		}
		ret = mp->p[mp->index_ptr] + mp->block_ptr;
		mp->block_ptr += mp->unit_size;
	}
	return ret;
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

void wt_free(void *ptr) {
	assert(0);
}


void *get_memory_pointer() {
	toggle ++;
	return &bpool[ptr];
}

void require_memory(size_t size) {
	ptr += size;
	toggle --;
	if(toggle > 0) {
		logw("some function else has hold the memptr\n");
	} else if(toggle < 0) {
		logw("this should not happen!\n");
	}
	assert(ptr <= POOL_SIZE);
}

char *strmul(char *str, int dup) {
	int len = strlen(str);
	char *ret = get_memory_pointer();
	char *p = ret;
	for(int i = 0; i < dup; i++) {
		strcpy(p, str);
		p += len;
	}
	require_memory(len * dup + 1);
	return ret;
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
	require_memory((size_t)p - (size_t)ret + 1);
	return ret;
}

int strcnt(const char *strin, char ch)
{
	int ret = 0;
	char *p = (char*)strin;
	do{ret+=(*p==ch);}while(*p++);
	return ret;
}

void init_bpool() {
#ifdef __DEBUG__
	MemPool mp;
	mempool_init(&mp, sizeof(int));
	const int test_size = 65536;
	int *p[test_size];
	for(int i = 0; i < test_size; i++) {
		p[i] = mempool_new(&mp);
		p[i][0] = i;
	}

	for(int i = 0; i < test_size; i++) {
	}
	mempool_free(&mp);
#endif
}

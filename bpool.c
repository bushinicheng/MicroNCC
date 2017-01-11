#include "common.h"

/* memory can be alloced without size
 * act like variable-length array
 */

/* memory model:
 *
 *  NULL
 *   ^
 *   |
 * +-----------------------------------------------------+
 * | p |                                                 |
 * +-----------------------------------------------------+
 *   ^
 *   |
 * +-----------------------------------------------------+
 * | p |                                                 |
 * +-----------------------------------------------------+
 *
 * extend memory by realloc
 *
 */

#define POOL_SIZE (16*1024*1024)
static int toggle = 0;
static uintptr_t ptr = 0;
static uint8_t bpool[POOL_SIZE];

void *wt_alloc(size_t size) {
	void *ptr = malloc(size + sizeof(void *));
	((void **)ptr)[0] = NULL;
	if(!ptr) loge("memory shortage\n");
	return ptr + sizeof(void *);
}

void *wt_realloc(size_t size, void *prev_page) {
	void *ptr = malloc(size + sizeof(void *));
	((void **)ptr)[0] = prev_page;
	if(!ptr) loge("memory shortage\n");
	return ptr + sizeof(void *);
}

void *wt_prevpage(void *nowpage) {
	if(!ptr) logw("check here\n");
	return ((void **)(ptr - sizeof(void *)))[0];
}

void wt_free(void *ptr) {
	if(!ptr) logw("check here\n");
	free(ptr - sizeof(void *));
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
	do{ret+=*p==ch;}while(*p++);
	return ret;
}

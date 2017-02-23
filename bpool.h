#ifndef __BPOOL_H__
#define __BPOOL_H__

/*  index                            block
 * +-----+     +------------------------------------------------+
 * |index| --> |      |      |      |      |      |      |      |
 * +-----+     +------------------------------------------------+
 * |index| --> |      |      |      |      |      |      |      |
 * +-----+     +------------------------------------------------+
 * |index| --> |      |      |      |      |      |      |      |
 * +-----+     +------------------------------------------------+
 * |index| --> |      |      |      |      |      |      |      |
 * +-----+     +------------------------------------------------+
 * ...
 *
 * size, ptr
 */

typedef struct MemPool {
	size_t unit_size;
	off_t index_ptr;
	off_t block_ptr;
	size_t index_size;
	size_t *bs;//block size array
	void **p;//buffer
} MemPool;


void *wt_alloc(size_t size);
void *wt_realloc(void *ptr, size_t oldsize, size_t newsize);
void mempool_init(MemPool *mp, size_t unit_size);
void *mempool_new(MemPool *mp);
size_t mempool_size(MemPool *mp);
void *mempool_free(MemPool *mp);
void *get_memory_pointer();
void *require_memory(size_t size);
char *strmul(char *str, int dup);
char *strjoin(char **strlist, int size, char *delim);
int strcnt(const char *strin, char ch);
void push_bpool_state(off_t op);
void pop_bpool_state();
char *strseek(const char *strin, char ch);

#endif

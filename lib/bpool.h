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

typedef struct mem_pool_t {
	size_t unit_size;
	off_t index_ptr;
	off_t block_ptr;
	size_t index_size;
	size_t *bs;//block size array
	void **p;//buffer
} mem_pool_t;

/* function wrap the original malloc and realloc */
void *wt_alloc(size_t size);
void *wt_realloc(void *ptr, size_t oldsize, size_t newsize);

/* mempool API */
void mempool_init(mem_pool_t *mp, size_t unit_size);
void *mempool_new(mem_pool_t *mp);
size_t mempool_size(mem_pool_t *mp);
void mempool_free(mem_pool_t *mp);

/* bpool API */
void *get_memory_pointer();
void *require_memory(size_t size);
void push_bpool_state(off_t op);
void pop_bpool_state();

#endif

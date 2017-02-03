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
	void **p;
} MemPool;

#endif

#include "common.h"

/* memory can be alloced without size
 */

#define POOL_SIZE (16*1024*1024)
static uintptr_t ptr = 0;
static uint8_t bpool[POOL_SIZE];

void *get_memory_pointer() {
	return &bpool[ptr];
}

void require_memory(size_t size) {
	ptr += size;
	assert(ptr <= POOL_SIZE);
}

#ifndef __HASH_H__
#define __HASH_H__

#define HASH_SIZE (128 * 1024)

typedef struct HashElement {
	uint8_t *keybuf;
	size_t size;
	void *value;
	struct HashElement *next;
	struct HashElement *sibling;
} HashElement;

typedef struct HashTable {
	HashElement *pool[HASH_SIZE];
	HashElement *free_ptr;
	HashElement *full_ptr;
} HashTable;


#endif

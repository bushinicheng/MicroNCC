#ifndef __HASH_H__
#define __HASH_H__

#define HASH_SIZE (128 * 1024)

typedef struct HashElement {
	uint8_t *keybuf;
	size_t size;
	void *value;
	struct HashElement *next;
} HashElement;

typedef struct HashTable {
	HashElement *pool[HASH_SIZE];
} HashTable;

void hash_init(HashTable *ht);
void hash_push(HashTable *ht, uint8_t *keybuf, size_t size, void *value);
void *hash_get(HashTable *ht, uint8_t *keybuf, size_t size);

#endif

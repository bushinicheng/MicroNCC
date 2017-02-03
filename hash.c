#include "common.h"

static MemPool hashpool;

int hash(uint8_t *keybuf, size_t size) {
	int h = 0;
    for(int i = 0; i < size; i++) {
        h = h * 131 + keybuf[i];
    }
    return (h & 0x7FFFFFFF) % HASH_SIZE;
}

void hash_init(HashTable *ht) {
	memset(ht, 0, sizeof(HashTable));
}

void hash_push(HashTable *ht, uint8_t *keybuf, size_t size, void *value) {
	int key = hash(keybuf, size);
	HashElement *he = (HashElement *)mempool_new(&hashpool);
	he->keybuf = keybuf;
	he->size = size;
	he->next = ht->pool[key];
	he->value = value;
	ht->pool[key] = he;
}

void *hash_get(HashTable *ht, uint8_t *keybuf, size_t size) {
	int key = hash(keybuf, size);
	HashElement *he = ht->pool[key];
	while(he) {
		if(he->size == size && memcmp(he->keybuf, keybuf, size) == 0) {
			return he->value;
		}
		he = he->next;
	}
	return NULL;
}

void hash_destroy_element(HashTable *ht) {
	wt_assert(0);
}

HashTable *new_hash_table() {
	return NULL;
}

void free_hash() {
	mempool_free(&hashpool);
}

int init_hash() {
	mempool_init(&hashpool, sizeof(HashElement));
	return 0;
}

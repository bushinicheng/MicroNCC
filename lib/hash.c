//#include "common.h"

static mem_pool_t hashpool;

int hash(uint8_t *keybuf, size_t size) {
	int h = 0;
    for(int i = 0; i < size; i++) {
        h = h * 131 + keybuf[i];
    }
    return (h & 0x7FFFFFFF) % HASH_SIZE;
}

void hash_init(hash_table_t *ht) {
	memset(ht, 0, sizeof(hash_table_t));
}

void hash_push(hash_table_t *ht, uint8_t *keybuf, size_t size, void *value) {
	int key = hash(keybuf, size);
	hash_element_t *he = (hash_element_t *)mempool_new(&hashpool);
	he->keybuf = keybuf;
	he->size = size;
	he->next = ht->pool[key];
	he->value = value;
	ht->pool[key] = he;
}

void *hash_get(hash_table_t *ht, uint8_t *keybuf, size_t size) {
	int key = hash(keybuf, size);
	hash_element_t *he = ht->pool[key];
	while(he) {
		if(he->size == size && memcmp(he->keybuf, keybuf, size) == 0) {
			return he->value;
		}
		he = he->next;
	}
	return NULL;
}

void hash_destroy_element(hash_table_t *ht) {
	memset(ht, 0, sizeof(hash_table_t));
}

void free_hash() {
	mempool_free(&hashpool);
}

int init_hash() {
	mempool_init(&hashpool, sizeof(hash_element_t));
	return 0;
}

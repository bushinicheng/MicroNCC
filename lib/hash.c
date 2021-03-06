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
	vector_init(&(ht->full), sizeof(int));
	memset(ht, 0, sizeof(hash_table_t));
}

void hash_push(hash_table_t *ht, uint8_t *keybuf, size_t size, void *value) {
	int key = hash(keybuf, size);
	if(!ht->pool[key]) vector_push(&(ht->full), &key);
	hash_element_t *he = (hash_element_t *)mempool_new(&hashpool);
	he->keybuf = keybuf;
	he->size = size;
	he->next = ht->pool[key];
	he->value = value;
	ht->pool[key] = he;
	/**/
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

/* cost too much */
void hash_destroy_element(hash_table_t *ht) {
	size_t vec_n = vector_size(&(ht->full));
	if(vec_n * 4 > HASH_SIZE) {
		memset(&(ht->pool), 0, sizeof(ht->pool));
	}else{
		int *p = ht->full.p;
		for(int i = 0; i < vec_n; i++) {
			ht->pool[p[i]] = NULL;
		}
	}
}

void free_hash() {
	mempool_free(&hashpool);
}

int init_hash() {
	mempool_init(&hashpool, sizeof(hash_element_t));
#ifdef __DEBUG__
#endif
	return 0;
}

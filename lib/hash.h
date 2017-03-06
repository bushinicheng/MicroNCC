#ifndef HASH_H
#define HASH_H

#define HASH_SIZE (4 * 1024)

typedef struct hash_element_t {
	uint8_t *keybuf;
	size_t size;
	void *value;
	struct hash_element_t *next;
} hash_element_t;

typedef struct hash_table_t {
	vec_t full;
	hash_element_t *pool[HASH_SIZE];
} hash_table_t;

/* init a hash table */
void hash_init(hash_table_t *ht);

/* push a element into hash table */
void hash_push(hash_table_t *ht, uint8_t *keybuf, size_t size, void *value);

/* find element from hash table */
void *hash_get(hash_table_t *ht, uint8_t *keybuf, size_t size);

/* destroy all elements in a hash table */
void hash_destroy_element(hash_table_t *ht);

#endif

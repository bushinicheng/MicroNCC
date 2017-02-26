#ifndef __HASH_H__
#define __HASH_H__

#define HASH_SIZE (128 * 1024)

typedef struct hash_element_t {
	uint8_t *keybuf;
	size_t size;
	void *value;
	struct hash_element_t *next;
} hash_element_t;

typedef struct hash_table_t {
	hash_element_t *pool[HASH_SIZE];
} hash_table_t;

void hash_init(hash_table_t *ht);
void hash_push(hash_table_t *ht, uint8_t *keybuf, size_t size, void *value);
void *hash_get(hash_table_t *ht, uint8_t *keybuf, size_t size);

#endif

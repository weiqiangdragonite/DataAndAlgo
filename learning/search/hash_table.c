/*
 * Hash Table
 */


#include <stdio.h>



#define MAXSIZE		100	/* maximum size of hash table */
#define NULLKEY		-32768


struct hash_table {
	int *elem;	/* data arrays */
	int count;	/* current data numbers */
};
typedef hash_table HashTable;


/*
 * init hash table
 */
int
init_hashtable(HashTable *table)
{
	int i;

	table->elem = (int *) malloc(sizeof(int) * MAXSIZE);
	for (i = 0; i < MAXSIZE; ++i)
		table->elem[i] = NULLKEY;

	return 0;
}

/*
 * hash function for int key
 */
int
hash(int key)
{
	return key % MAXSIZE;
}

/*
 * hash for string
 */
int
hash(const char *key, int table_size)
{
	unsigned int h = 0;
	while (*key != '\0')	/* h << 5 == h * 32 */
		h = (h << 5) + *key++;
	return h % table_size;
}



/*
 *
 */
void
insert(HashTable *table, int key)
{
	int addr = hash(key);

	/* collision */
	while (table->elem[addr] != NULLKEY)
		addr = (addr+1) % m;	/* 线性探测 */
	table->elem[addr] = key;
}


/*
 * 
 */
int
search(HashTable *table, int key, int *addr)
{
	*addr = hash(key);
	/* if not empty, is collision */
	while (table->elem[*addr] != key) {
		*addr = (*addr+1) % m;
		if (table->elem[*addr] == NULLKEY || *addr == hash(key))
			return -1;
	}
	return 0;
}



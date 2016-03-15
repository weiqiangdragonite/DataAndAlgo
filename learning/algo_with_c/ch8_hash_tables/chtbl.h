/*
 * chtbl.h
 * header for the Chained Hash Table abstract datatype (链式哈希表)
 */

#ifndef CHTBL_H
#define CHTBL_H

#include "list.h"


/*
 * defined a structure for chained hash tables
 */
typedef struct CHTbl_ {
	int	buckets;
	int	(*h)(const void *key);
	int	(*match)(const void *key1, const void *key2);
	void	(*destroy)(void *data);
	int	size;
	List	*table;
} CHTbl;


/*
 * public interface
 */
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key),
	int (*match)(const void *key1, const void *key2),
	void (*destroy)(void *data));

void chtbl_destroy(CHTbl *htbl);

int chtbl_insert(CHTbl *htbl, const void *data);

int chtbl_remove(CHTbl *htbl, void **data);

int chtbl_lookup(const CHTbl *htbl, void **data);

/* int chtbl_size(CHTbl *htbl); */
#define chtbl_size(htbl)	((htbl)->size)


#endif

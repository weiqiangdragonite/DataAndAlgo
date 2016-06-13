/*
 * set.h
 * header for the set abstract datatype
 */

#ifndef SET_H
#define SET_H


#include "list.h"


/*
 * implement sets as linked list
 */
typedef List Set;


/*
 * public interface
 */

void set_init(Set *set, int (*match)(const void *key1, const void *key2),
	void (*destroy)(void *data));

/* void set_destroy(Set *set); */
#define set_destroy	list_destroy

int set_insert(Set *set, const void *data);

int set_remove(Set *Set, void **data);

/* union 并集 */
int set_union(Set *setu, const Set *set1, const Set *set2);

/* intersection 交集 */
int set_intersection(Set *seti, const Set *set1, const Set *set2);

/* 差集 */
int set_difference(Set *setd, const Set *set1, const Set *set2);

int set_is_member(const Set *set, const void *data);

/* 子集 */
int set_is_subset(const Set *set1, const Set *set2);

int set_is_equal(const Set *set1, const Set *set2);

/* int set_size(const Set *set); */
#define set_size(set)	((set)->size)


#endif

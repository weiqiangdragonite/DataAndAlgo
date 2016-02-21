/*
 * dlist.h
 * header for the doubly-linked list abstract datatype
 */

#ifndef DLIST_H
#define DLIST_H


/*
 * define a structure for doubly-linked list elements
 */
typedef struct DListElmt_ {
	void			*data;
	struct DListElmt_	*prev;
	struct DListElmt_	*next;
} DListElmt;


/*
 * define a structure for doubly-linked lists
 */
typedef struct List_ {
	int		size;

	int		(*match)(const void *key1, const void *key2);
	void		(*destroy)(void *data);

	DListElmt	*head;
	DListElmt	*tail;
} DList;


/*
 * public interface
 */

void dlist_init(DList *list, void (*destroy)(void *data));

void dlist_destroy(DList *list);

int dlist_insert_next(DList *list, DListElmt *element, const void *data);

int dlist_insert_prev(DList *list, DListElmt *element, const void *data);

int dlist_remove(DList *list, DListElmt *element, void **data);

/* int dlist_size(const DList *list); */
#define dlist_size(list)		((list)->size)

/* DListElmt *dlist_head(const DList *list); */
#define dlist_head(list)		((list)->head)

/* DListElmt *dlist_size(const DList *list); */
#define dlist_tail(list)		((list)->tail)

/* int dlist_is_head(const DListElmt *element); */
#define dlist_is_head(element)		((element)->prev == NULL ? 1 : 0)

/* int dlist_is_tail(const DListElmt *element); */
#define dlist_is_tail(element)		((element)->next == NULL ? 1 : 0)

/* void *dlist_data(const DListElmt *element); */
#define dlist_data(element)		((element)->data)

/* DListElmt *dlist_next(const DListElmt *element); */
#define dlist_next(element)		((element)->next)

/* DListElmt *dlist_prev(const DListElmt *element); */
#define dlist_prev(element)		((element)->prev)


#endif

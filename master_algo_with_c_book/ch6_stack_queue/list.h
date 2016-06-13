/*
 * list.h
 * header for the linked list abstract datatype
 */

#ifndef LIST_H
#define LIST_H


/*
 * define a structure for linked list elements
 */
typedef struct ListElmt_ {
	void			*data;
	struct ListElmt_	*next;
} ListElmt;


/*
 * define a structure for linked lists
 */
typedef struct List_ {
	int		size;

	int		(*match)(const void *key1, const void *key2);
	void		(*destroy)(void *data);

	ListElmt	*head;
	ListElmt	*tail;
} List;


/*
 * public interface
 */

void list_init(List *list, void (*destroy)(void *data));

void list_destroy(List *list);

int list_insert_next(List *list, ListElmt *element, const void *data);

int list_remove_next(List *list, ListElmt *element, void **data);

/* int list_size(const List *list); */
#define list_size(list)			((list)->size)

/* ListElmt *list_head(const List *list); */
#define list_head(list)			((list)->head)

/* ListElmt *list_size(const List *list); */
#define list_tail(list)			((list)->tail)

/* int list_is_head(const List *list, const ListElmt *element); */
#define list_is_head(list, element)	((element) == (list)->head ? 1 : 0)

/* int list_is_tail(const ListElmt *element); */
#define list_is_tail(element)		((element)->next == NULL ? 1 : 0)

/* void *list_data(const ListElmt *element); */
#define list_data(element)		((element)->data)

/* ListElmt *list_next(const ListElmt *element); */
#define list_next(element)		((element)->next)


#endif

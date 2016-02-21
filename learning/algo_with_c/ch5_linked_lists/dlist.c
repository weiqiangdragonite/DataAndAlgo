/*
 * dlist.c
 * implementation of the doubly-linked list abstract datatype
 */

#include <stdlib.h>
#include <string.h>

#include "dlist.h"


/*
 * initialize the list
 */
void
dlist_init(DList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->match = NULL;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}


/*
 * destroys a doubly-linked list, remove each element
 */
void
dlist_destroy(DList *list)
{
	void *data;

	while (dlist_size(list) > 0) {
		if (dlist_remove(list, dlist_tail(list), (void **) &data) == 0
		&& list->destroy != NULL) {
			list->destroy(data);
		}
	}

	memset(list, 0, sizeof(DList));
}


/*
 *
 */
int
dlist_insert_next(DList *list, DListElmt *element, const void *data)
{
	DListElmt *new_element = (DListElmt *) malloc(sizeof(DListElmt));
	if (new_element == NULL)
		return -1;
	new_element->data = (void *) data;

	/* insert at the head */
	if (element == NULL) {
		if (dlist_size(list) == 0)
			list->tail = new_element;
		else
			list->head->prev = new_element;

		new_element->prev = NULL;
		new_element->next = list->head;
		list->head = new_element;
	/* insert after element */
	} else {
		if (element->next == NULL)
			list->tail = new_element;

		new_element->prev = element;
		new_element->next = element->next;
		element->next->prev = new_element;
		element->next = new_element;
	}

	++list->size;
	return 0;
}


/*
 *
 */
int
list_remove_next(List *list, ListElmt *element, void **data)
{
	ListElmt *old_element;

	if (list_size(list) == 0)
		return -1;

	/* remove head element */
	if (element == NULL) {
		*data = list->head->data;
		old_element = list->head;
		list->head = old_element->next;

		if (list_size(list) == 1)
			list->tail = NULL;
	/* remove after element */
	} else {
		if (element->next == NULL)
			return -1;

		*data = element->next->data;
		old_element = element->next;
		element->next = old_element->next;

		if (element->next == NULL)
			list->tail = NULL;
	}

	free(old_element);
	--list->size;

	return 0;
}

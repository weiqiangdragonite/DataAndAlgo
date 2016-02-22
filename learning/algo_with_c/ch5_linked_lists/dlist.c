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
	DListElmt *new_element;

	if (element == NULL && dlist_size(list) != 0)
		return -1;

	new_element = (DListElmt *) malloc(sizeof(DListElmt));
	if (new_element == NULL)
		return -1;
	new_element->data = (void *) data;

	/* insert in the empty list */
	if (dlist_size(list) == 0) {
		list->head = new_element;
		new_element->prev = NULL;
		new_element->next = NULL;
		list->tail = new_element;

	/* insert after element */
	} else {
		new_element->prev = element;
		new_element->next = element->next;

		if (element->next == NULL)
			list->tail = new_element;
		else
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
dlist_insert_prev(DList *list, DListElmt *element, const void *data)
{
	DListElmt *new_element;

	if (element == NULL && dlist_size(list) != 0)
		return -1;

	new_element = (DListElmt *) malloc(sizeof(DListElmt));
	if (new_element == NULL)
		return -1;
	new_element->data = (void *) data;

	/* insert in the empty list */
	if (dlist_size(list) == 0) {
		list->head = new_element;
		new_element->prev = NULL;
		new_element->next = NULL;
		list->tail = new_element;

	/* insert before element */
	} else {
		new_element->prev = element->prev;
		new_element->next = element;

		if (element->prev == NULL)
			list->head = new_element;
		else
			element->prev->next = new_element;

		element->prev = new_element;
	}

	++list->size;
	return 0;
}


/*
 *
 */
int
dlist_remove(DList *list, DListElmt *element, void **data)
{
	if (element == NULL || dlist_size(list) == 0)
		return -1;

	*data = element->data;

	/* remove head element */
	if (element == list->head) {
		list->head = element->next;
		if (list->head == NULL)
			list->tail = NULL;
		else
			element->next->prev = NULL;
	/* remove element */
	} else {
		element->prev->next = element->next;

		if (element->next == NULL)
			list->tail = element->prev;
		else
			element->next->prev = element->prev;
	}

	free(element);
	--list->size;

	return 0;
}

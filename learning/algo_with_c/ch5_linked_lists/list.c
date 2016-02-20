/*
 * list.c
 */

#include <stdlib.h>
#include <string.h>

#include "list.h"


/*
 * initialize the list
 */
void
list_init(List *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}


/*
 * destroys a linked list, remove each element
 */
void
list_destroy(List *list)
{
	void *data;

	while (list_size(list) > 0) {
		if (list_remove_next(list, NULL, (void **) &data) == 0 &&
		list->destroy != NULL) {
			list->destroy(data);
		}
	}

	memset(list, 0, sizeof(List));
}


/*
 *
 */
int
list_insert_next(List *list, ListElmt *element, const void *data)
{
	ListElmt *new_element = (ListElmt *) malloc(sizeof(ListElmt));
	if (new_element == NULL)
		return -1;
	new_element->data = data;

	/* insert at the head */
	if (element == NULL) {
		if (list_size(list) == 0)
			list->tail = new_element;

		new_element->next = list->head;
		list->head = new_element;
	/* insert after element */
	} else {
		if (element->next == NULL)
			list->tail = new_element;

		new_element->next = element->next;
		element->next = new_element;
	}

	++list->size;
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
		list->head = list->head_next;

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
}

/*
 * clist.c
 * implementation of the circular list abstract datatype
 */

#include <stdlib.h>
#include <string.h>

#include "clist.h"


/*
 * initialize the list
 */
void
clist_init(CList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->match = NULL;
	list->destroy = destroy;
	list->head = NULL;
}


/*
 * destroys a linked list, remove each element
 */
void
clist_destroy(CList *list)
{
	void *data;

	while (clist_size(list) > 0) {
		if (clist_remove_next(list, list->head, (void **) &data) == 0
		&& list->destroy != NULL) {
			list->destroy(data);
		}
	}

	memset(list, 0, sizeof(CList));
}


/*
 *
 */
int
clist_insert_next(CList *list, CListElmt *element, const void *data)
{
	CListElmt *new_element;

	if (element == NULL && clist_size(list) != 0)
		return -1;

	new_element = (CListElmt *) malloc(sizeof(CListElmt));
	if (new_element == NULL)
		return -1;
	new_element->data = (void *) data;

	/* insert insert in the empty list */
	if (clist_size(list) == 0) {
		new_element->next = new_element;
		list->head = new_element;
	/* insert after element */
	} else {
		new_element->next = element->next;
		element->next = new_element;
	}

	++list->size;
	return 0;
}


/*
 *
 */
int
clist_remove_next(CList *list, CListElmt *element, void **data)
{
	CListElmt *old_element;

	if (element == NULL || clist_size(list) == 0)
		return -1;

	*data = element->next->data;

	/* remove one element */
	if (element->next == element) {
		old_element = element;
		list->head = NULL;
	/* remove after element */
	} else {
		old_element = element->next;
		element->next = old_element->next;

		if (old_element == clist_head(list))
			list->head = element;
	}

	free(old_element);
	--list->size;

	return 0;
}

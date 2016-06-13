/*
 * clist.h
 * header for the circular list abstract datatype
 */

#ifndef CLIST_H
#define CLIST_H


/*
 * define a structure for circular list elements
 */
typedef struct CListElmt_ {
	void			*data;
	struct CListElmt_	*next;
} CListElmt;


/*
 * define a structure for circular lists
 */
typedef struct CList_ {
	int		size;

	int		(*match)(const void *key1, const void *key2);
	void		(*destroy)(void *data);

	CListElmt	*head;
} CList;


/*
 * public interface
 */

void clist_init(CList *list, void (*destroy)(void *data));

void clist_destroy(CList *list);

int clist_insert_next(CList *list, CListElmt *element, const void *data);

int clist_remove_next(CList *list, CListElmt *element, void **data);

/* int clist_size(const CList *list); */
#define clist_size(list)			((list)->size)

/* CListElmt *clist_head(const CList *list); */
#define clist_head(list)			((list)->head)

/* void *clist_data(const CListElmt *element); */
#define clist_data(element)		((element)->data)

/* CListElmt *clist_next(const CListElmt *element); */
#define clist_next(element)		((element)->next)


#endif

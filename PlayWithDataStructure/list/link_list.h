/*
 *
 */

#ifndef LINK_LIST_H
#define LINK_LIST_H

/*
 *
 */
struct link_list {
	ElemType data;
	struct link_list next;
};

typedef link_list link_list_t;

#endif	/* LINK_LIST_H */

/*
 *
 */

#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef int ElemType;

/*
 *
 */
struct link_list {
	ElemType data;
	struct link_list *next;
};

typedef struct link_list link_list_t;

void init_link_list(link_list_t *list);
void free_link_list(link_list_t *list);
int get_link_list(link_list_t *list, unsigned int pos, ElemType *item);
int insert_link_list(link_list_t *list, unsigned int pos, ElemType item);
int delete_link_list(link_list_t *list, unsigned int pos, ElemType *item);


#endif	/* LINK_LIST_H */


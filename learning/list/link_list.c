/*
 * 此代码暂时只提供一个思路，貌似比较有问题
 */

#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

/*
 * 不带头结点的定义
 * link_list_t *list;
 *
 */




/*
 * 带头结点
 * link_list_t list;
 * init_link_list(&list);
 */
void
init_link_list(link_list_t *list)
{
	/* 创建头节点 */
	//list = (link_list_t *) malloc(sizeof(link_list_t));
	list->data = (ElemType) 0;
	list->next = NULL;
}

/*
 *
 */
void
free_link_list(link_list_t *list)
{
	link_list_t *ptr, *next;
	/* 指向第一个，头结点不删除*/
	ptr = list->next;
	/* 第二个结点 */
	next = ptr->next;

	while (ptr) {
		free(ptr);
		ptr = next;
		if (ptr == NULL)
			break;
		next = next->next;
	}

	list->next = NULL;
}

/*
 * 带头结点的链表
 */
int
get_link_list(link_list_t *list, unsigned int pos, ElemType *item)
{
	int i;
	link_list_t *ptr;

	/* point to the first */
	ptr = list->next;

	i = 1;
	while (ptr) {
		if (i == pos) {
			*item = ptr->data;
			return pos;
		}
		ptr = ptr->next;
		++i;
	}

	return -1;
}

/*
 *
 */
int
insert_link_list(link_list_t *list, unsigned int pos, ElemType item)
{
	int i;
	link_list_t *ptr;
	/* point to the head */
	ptr = list;

	i = 1;
	while (ptr->next && (i < pos)) {
		ptr = ptr->next;
		++i;
	}
	if (ptr == NULL || i > pos)
		return -1;

	link_list_t *newptr;
	newptr = (link_list_t *) malloc(sizeof(link_list_t));
	newptr->data = item;
	newptr->next = ptr->next;
	ptr->next = newptr;

	return pos;
}

/*
 *
 */
int
delete_link_list(link_list_t *list, unsigned int pos, ElemType *item)
{
	int i;
	link_list_t *ptr;

	/* point to the head, not the first */
	ptr = list;

	i = 1;
	while (ptr && (i < pos)) {
		ptr = ptr->next;
		++i;
	}
	if (ptr->next == NULL || i > pos)
		return -1;

	link_list_t *nextptr;
	nextptr = ptr->next;
	ptr->next = nextptr->next;
	if (item != NULL)
		*item = nextptr->data;
	free(nextptr);

	return pos;
}


/*
 * 单链表
 * 参考大话数据结构和Weiss "DSAAC"
 *
 * Don't compile this file.
 */

/*
 * ADT
 *
 * make_empty();
 * isempty();
 * islast();
 * find();
 * delete();
 * find_previous();
 * insert()
 * delete_list();
 * header();
 * first();
 * advance();
 * retrieve();
 *
 */



#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;


/*
 *
 */
struct node {
	ElemType data;
	struct node *next;
};

typedef struct node list_t;



void init_link_list(link_list_t *list);
void free_link_list(link_list_t *list);
int get_link_list(link_list_t *list, unsigned int pos, ElemType *item);
int insert_link_list(link_list_t *list, unsigned int pos, ElemType item);
int delete_link_list(link_list_t *list, unsigned int pos, ElemType *item);



/*

with header linked list - default
list
+--+-+   +----+-+   +----+-+           +----+------+
|  | +-->| a1 | +-->| a2 | +--> ... -->| an | NULL |
+--+-+   +----+-+   +----+-+           +----+------+
         a1 = list->next

no header
         +----+-+   +----+-+           +----+------+
 list -->| a1 | +-->| a2 | +--> ... -->| an | NULL |
         +----+-+   +----+-+           +----+------+
         a1 = list
*/



int
main(int argc, char *argv[])
{
	int i;
	int item;

	/* with header */
	list_t list;
	init_list(&list);	/* must call this */

	/* no header */
	//list_t *list = NULL;


	for (i = 0; i < 10; ++i)
		insert_link_list(&list, i+1, i);


	printf("After insert [1-10]:\n");
	for (i = 0; i < 10; ++i) {
		get_link_list(&list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}


	insert_link_list(&list, 5, 100);
	printf("Insert 100 at [5], after insert:\n");
	for (i = 0; i < 11; ++i) {
		get_link_list(&list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}

	delete_link_list(&list, 5, NULL);
	printf("Delete 100 at [5], after delete:\n");
	for (i = 0; i < 10; ++i) {
		get_link_list(&list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}

	free_link_list(&list);
	if (list.next == NULL)
		printf("list is empty\n");
	else
		printf("list is not empty\n");

	return 0;

}



/******************************************************************************/


/*
 * only for header linked list
 *
 * list_t list;
 * init_list(&list);
 */
void
init_list(list_t *list)
{
	list->data = (ElemType) 0;
	list->next = NULL;
}


/*
 * only for header linked list.
 * return 1 if list is empty
 *
 * if no header linked list, you can just test if (list == NULL)
 */
int
isempty(list_t *list)
{
	return (list->next == NULL);
}


/*
 * test if the current element is the last element in linked list.
 * both for header linked list and no header linked list.
 *
 * the item must be in the linked list
 */
int
islast(list_t *item)
{
	return (item->next == NULL);
}







/*
 * find the element position in the linked list
 *
 * I don't think this function has any meaning.
 */
list_t *
find(list_t *list, ElemType item)
{
	list_t *ptr;

	/* point to the first item */
	ptr = list->next;
	/* 如果是不带头结点的链表，直接 ptr = list 即可 */

	while (ptr != NULL && ptr->data != item)
		ptr = ptr->next;

	return ptr;
}

/*
 * just for with header linked list
 */
list_t *
find_previous(list_t *list, ElemType item)
{
	list_t *ptr;

	/* point to header */
	ptr = list;

	while (ptr->next != NULL && ptr->next->data != item)
		ptr = ptr->next;

	return ptr;
}


/*
 * delete item in list
 */
void
delete(list_t *list, ElemType item)
{
	list_t prev, ptr;

	prev = find_previous(list, item);

	if (!islast(prev)) {
		ptr = prev->next;
		prev->next = ptr->next;
		free(ptr);
	}
}

/*
 * delete entire list, with header
 */
void
delete_list(list_t *list)
{
	list_t *ptr, *tmp;

	ptr = list->next;
	while (ptr != NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	list->next = NULL;
}


/*
 * insert item after the specific element
 */
void
insert(list_t *list, list_t *elem, ElemType item)
{
	list_t *ptr;

	ptr = malloc(list_t);
	ptr->data = item;
	ptr->next = elem->next;

	elem->next = ptr;
}







/*
 * 单链表整表创建的算法思路:
 * 1.声明一结点 p 和计数器变量 i;
 * 2.初始化一空链表L;
 * 3.让 L 的头结点的指针指向NULL，即建立一个带头结点的单链表
 * 4.循环:
     生成一新结点赋值给 p;
     随机生成一数字赋值给 p 的数据域 p->data;
     将 p 插入到头结点与前一新结点之间。(头插法 或 尾插法)
 */





/*
 * 单链表整表删除的算法思路如下:
 * 1.声明一结点 p 和q ;
 * 2.将第一个结点赋值给p;
 * 3.循环:
 *   将下一结点赋值给q;
 *   释放p;
 *   将 q 赋值给p
 *
 * 此处链表为带头结点链表
 */
void
free_link_list(link_list_t *list)
{
	link_list_t *ptr, *next;

	/* 指向第一个结点，头结点不删除*/
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
 * 获取第i个位置的元素
 *
 * 获得单链表第 i 个数据的算法思路:
 * 1.声明一个结点 p 指向链表第一个结点，初始化 j 从 1 开始;
 * 2.当 j<i 时，就遍历链表，让 p 的指针向后移动，不断指向下一结点，j 累加 1;
 * 3.若到链表末尾 p 为空，则说明第 i 个元素不存在;
 * 4.否则查找成功，返回结点 p 的数据。
 *
 * 此处链表为带头结点链表
 * 查找成功，返回pos；否则返回-1
 *
 * 时间复杂度为 O(n)
 */
int
get_list(list_t *list, unsigned int pos, ElemType *item)
{
	int i;
	list_t *ptr;

	/* point to the first item */
	ptr = list->next;
	/* 如果是不带头结点的链表，直接 ptr = list 即可 */

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
 * 单链表第 i 个数据插入结点的算法思路:
 * 1.声明一结点 p 指向链表第一个结点，初始化 j 从 1 开始
 * 2.当 j<i 时，就遍历链表，让 p 的指针向后移动，不断指向下一结点，j 累加 1;
 * 3.若到链表末尾 p 为空，则说明第 i 个元素不存在
 * 4.否则查找成功，在系统中生成一个空结点 s;
 * 5.将数据元素 e 赋值给 s->data ;
 * 6.单链表的插入标准语句 s->next=p->next, p->next=s
 * 7.返回成功。
 *
 * 此处链表可以带头结点，也可以不带头结点
 * 成功返回pos
 *
 * 时间复杂度为 O(n)
 */
int
insert_link_list(link_list_t *list, unsigned int pos, ElemType item)
{
	int i;
	link_list_t *ptr;
	link_list_t *newptr;

	/* point to the head */
	ptr = list;

	i = 1;
	while (ptr->next && (i < pos)) {
		ptr = ptr->next;
		++i;
	}
	if (ptr == NULL || i > pos)
		return -1;


	newptr = (link_list_t *) malloc(sizeof(link_list_t));
	if (newptr == NULL)
		return -2;

	newptr->data = item;
	newptr->next = ptr->next;
	ptr->next = newptr;

	return pos;
}

/*
 * 单链表第 i 个数据删除结点的算法思路:
 * 1.声明一结点 p 指向链表第一个结点， 初始化 j 从1 开始
 * 2.当 j<i 时，就遍历链表， 让 p 的指针向后移动，不断指向下一个结点，j 累加 1
 * 3.若到链表末尾 p 为空，则说明第 i 个元素不存在;
 * 4.否则查找成功，将欲删除的结点 p->next 赋值给q;
 * 5.单链表的删除标准语句 p->next=q->next;
 * 6.将 q 结点中的数据赋值给 e ，作为返回;
 * 7.释放 q 结点;
 * 8.返回成功。
 *
 * 此处链表可以带头结点，也可以不带头结点
 * 成功返回pos
 *
 * 时间复杂度为 O(n)
 */
int
delete_link_list(link_list_t *list, unsigned int pos, ElemType *item)
{
	int i;
	link_list_t *ptr;
	link_list_t *nextptr;

	/* point to the head */
	ptr = list;

	i = 1;
	while (ptr && (i < pos)) {
		ptr = ptr->next;
		++i;
	}
	if (ptr->next == NULL || i > pos)
		return -1;

	nextptr = ptr->next;
	ptr->next = nextptr->next;
	if (item != NULL)
		*item = nextptr->data;
	free(nextptr);

	return pos;
}


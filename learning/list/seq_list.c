/*
 * 顺序存储线性表
 */

#include <stdio.h>
#include <string.h>


#define LISTSIZE 1024


/* type */
typedef int ElemType;


/*
 *
 */
struct seq_list {
	ElemType data[LISTSIZE];	/* number of elements can store */
	unsigned int length;		/* current length of list */
};

typedef struct seq_list seq_list_t;


void init_seq_list(seq_list_t *list);
int seq_list_length(seq_list_t *list);
void free_seq_list(seq_list_t *list);
int get_seq_list(seq_list_t *list, unsigned int pos, ElemType *item);
int insert_seq_list(seq_list_t *list, unsigned int pos, ElemType item);
int delete_seq_list(seq_list_t *list, unsigned int pos, ElemType *item);
int find_seq_list(seq_list_t *list, ElemType item);





int
main(int argc, char *argv[])
{
	seq_list_t list;
	int i;
	int item;

	/* 10 element */
	init_seq_list(&list);
	printf("seq length = %d\n", seq_list_length(&list));

	for (i = 0; i < 10; ++i)
		insert_seq_list(&list, i+1, i);

	printf("After insert [1-10]:\n");
	for (i = 0; i < list.length; ++i) {
		get_seq_list(&list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}

	insert_seq_list(&list, 5, 100);
	printf("Insert 100 at [5], after insert:\n");
	for (i = 0; i < list.length; ++i) {
		get_seq_list(&list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}

	printf("Find 7 in list, pos = %d\n", find_seq_list(&list, 7));

	delete_seq_list(&list, 5, NULL);
	printf("Delete 100 at [5], after delete:\n");
	for (i = 0; i < list.length; ++i) {
		get_seq_list(&list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}

	free_seq_list(&list);
	printf("After free list, length = %d\n", list.length);

	return 0;
}



/******************************************************************************/



/*
 * 可以考虑为宏定义或inline函数
 * 或者直接自己初始化
 */
void
init_seq_list(seq_list_t *list)
{
	memset(list, 0, sizeof(seq_list_t));
}

/*
 * 返回线性表的个数
 * 可以自己直接读list->length
 */
int
seq_list_length(seq_list_t *list)
{
	return list->length;
}

/*
 * 清空线性表
 */
void
free_seq_list(seq_list_t *list)
{
	memset(list, 0, sizeof(seq_list_t));
}

/*
 * 将第i个位置的元素返回
 * pos的范围是 [1, length]
 * 不是从0开始哦！
 * 成功返回0
 *
 * 时间复杂度为 O(1)
 */
int
get_seq_list(seq_list_t *list, unsigned int pos, ElemType *item)
{
	if (list->length == 0)
		return -1;
	if (pos == 0 || pos > list->length)
		return -2;
	if (item == NULL)
		return -3;

	/* 注意要 pos-1 */
	*item = list->data[pos-1];

	return 0;
}

/*
 * 插入算法的思路;
 * 1. 如果插入位置不合理，抛出异常;
 * 2. 如果线性表长度大于等于数组长度，则抛出异常或动态增加容量;
 * 3. 从最后一个元素开始向前遍历到第 i 个位置，分别将它们都向后移动一个位置;
 * 4. 将要插入元素填入位置 i 处;
 * 5. 表长加1。
 *
 * pos:     1 2 3 4 5
 * data:    x x x x x
 * index:   0 1 2 3 4 5 6
 * length = 5
 *
 * 返回插入元素后表的长度
 *
 * 时间复杂度为 O(n)
 */
int
insert_seq_list(seq_list_t *list, unsigned int pos, ElemType item)
{
	int i;

	/* list is full */
	if (list->length >= LISTSIZE)
		return -1;

	/* position is wrong, [1, length+1] */
	if (pos < 1 || pos > (list->length + 1))
		return -2;

	/* if not insert at tail */
	if (pos < list->length) {
		/* 从插入位置的数据开始，往后移 */
		for (i = list->length - 1; i >= pos - 1; --i)
			list->data[i+1] = list->data[i];
	}
	list->data[pos-1] = item;

	++(list->length);

	return list->length;
}

/*
 * 删除算法的思路:
 * 1. 如果删除位置不合理，抛出异常；
 * 2. 取出删除元素;
 * 3. 从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置;
 * 4. 表长减1。
 *
 * pos:     1 2 3 4 5
 * data:    x x x x x
 * index:   0 1 2 3 4 5 6
 * length = 5
 *
 * 返回删除元素后表的长度
 *
 * 时间复杂度为 O(n)
 */
int
delete_seq_list(seq_list_t *list, unsigned int pos, ElemType *item)
{
	int i;

	/* list is empty */
	if (list->length == 0)
		return -1;

	/* position is wrong, [1, length] */
	if (pos < 1 || pos > list->length)
		return -2;

	if (item != NULL)
		*item = list->data[pos-1];

	/* if not delete at tail */
	if (pos < list->length) {
		/* 从删除位置的数据后一位开始，往前移 */
		for (i = pos; i < list->length; ++i)
			list->data[i-1] = list->data[i];
	}
	/* 原来的最后一位清零 */
	list->data[list->length - 1] = 0;

	--(list->length);

	return list->length;
}

/*
 * 查找元素在表中的位置
 * 返回的位置为[1, length]，若找不到返回0
 *
 * 时间复杂度为 O(n)
 */
int
find_seq_list(seq_list_t *list, ElemType item)
{
	int i;
	for (i = 0; i < list->length; ++i) {
		if (list->data[i] == item)
			return i+1;
	}

	return 0;
}


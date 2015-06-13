/*
 *
 */

#include <string.h>

#include "seq_list.h"


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
 * pos的范围是 [1, length]
 * 不是从0开始哦！
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
 *
 * pos:     1 2 3 4 5
 * data:    x x x x x
 * index:   0 1 2 3 4 5 6
 * pos = 2
 * length = 5
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
		/* 从插入位置的数据开始，往后移*/
		for (i = list->length - 1; i >= pos - 1; --i)
			list->data[i+1] = list->data[i];
	}
	list->data[pos-1] = item;

	++(list->length);

	return list->length;
}

/*
 *
 * pos:     1 2 3 4 5
 * data:    x x x x x
 * index:   0 1 2 3 4 5 6
 * pos = 2
 * length = 5
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

	/* if not delete tail */
	if (pos < list->length) {
		/* 从删除位置的数据后一位开始，往前移*/
		for (i = pos; i < list->length; ++i)
			list->data[i-1] = list->data[i];
	}
	/* 原来的最后一位清零 */
	list->data[list->length - 1] = 0;

	--(list->length);

	return list->length;
}

/*
 *
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


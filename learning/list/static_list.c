/*
 * 静态链表(游标实现法)
 *
 * 基本实现，但有些地方没有优化，还是有些问题
 */

#include <stdio.h>
#include <string.h>


#define LISTSIZE 100


/* type */
typedef int ElemType;


/*
 *
 */
struct sta_list {
	ElemType data;
	int cur;		/* cursor, 0 point to nothing */
};

typedef struct sta_list sta_list_t;



void init_sta_list(sta_list_t list[]);
int sta_list_length(sta_list_t list[]);
void free_seq_list(sta_list_t list[]);
int get_sta_list(sta_list_t list[], unsigned int index, ElemType *item);
int malloc_list(sta_list_t list[]);
void free_list(sta_list_t list[], int i);
int insert_sta_list(sta_list_t list[], unsigned int pos, ElemType item);
int insert(sta_list_t list[], ElemType item);
int delete_sta_list(sta_list_t list[], unsigned int pos, ElemType *item);
int find_sta_list(sta_list_t list[], ElemType item);





int
main(int argc, char *argv[])
{
	sta_list_t list[LISTSIZE];
	int i;
	int item;


	memset(list, 0, sizeof(list));
	init_sta_list(list);
	printf("sta list length = %d (%d)\n", sta_list_length(list), list[0].data);

	for (i = 0; i < 10; ++i)
		insert(list, i);


	printf("After insert [1-10]:\n");
	printf("sta list length = %d (%d)\n", sta_list_length(list), list[0].data);
	for (i = 0; i < list[0].data; ++i) {
		get_sta_list(list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}

	insert_sta_list(list, 5, 100);
	printf("Insert 100 at [5], after insert:\n");
	printf("sta list length = %d (%d)\n", sta_list_length(list), list[0].data);
	for (i = 0; i < list[0].data; ++i) {
		get_sta_list(list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}

	printf("100 index is = %d\n", find_sta_list(list, 100));

	printf("Traverse list:\n");
	for (i = 0; i < list[0].data; ++i)
		printf("[%d] = %d\n", i+1, list[i+1].data);


	delete_sta_list(list, 5, NULL);
	printf("Delete 100 at [5], after delete:\n");
	for (i = 0; i < list[0].data; ++i) {
		get_sta_list(list, i+1, &item);
		printf("[%d] = %d\n", i+1, item);
	}


	return 0;
}



/******************************************************************************/



/*
 * 初始化静态链表

length: n

index    0    1    2    3              n-2  n-1
        +----+----+----+----+         +----+----+
data    |    |    |    |    |         |    |    |
        +----+----+----+----+ ... ... +----+----+
cur     | 1  | 2  | 3  | 4  |         | 0  | 0  |
        +----+----+----+----+         +----+----+

 *
 * 数组0的游标存放下一个可插入元素的数组下标，
 * 数组0的data存放链表已插入元素的个数
 *
 * 接着从1 ~ n-1的data存放数据，
 * 数组1的游标存放下一个结点的下标，即数组2，以此类推
 *
 * 最后一个数组的游标存放第一个插入元素的数组下标，即作为头结点，如果游标为0，
 * 即链表为空。data可以存放链表最后一个元素的的下标。
 */
void
init_sta_list(sta_list_t list[])
{
	int i;
	/* [0, N-1) */
	for (i = 0; i < LISTSIZE - 1; ++i)
		list[i].cur = i + 1;
	list[i - 1].cur = 0;
	/* 最后一个数组的游标设为0 */
	list[LISTSIZE - 1].cur = 0;
}

/*
 * 返回静态链表的个数
 */
int
sta_list_length(sta_list_t list[])
{
	int i, k;

	/* the last array index, which point to the first item */
	k = LISTSIZE - 1;

	i = 0;
	while ((k = list[k].cur) != 0) {
		++i;
		//printf("[%d].cur = %d\n", k, list[k].cur);
	}

	return i;
}

/*
 * 清空线性表
 */
void
free_seq_list(sta_list_t list[])
{
	
}


/*
 * 将第i个位置的元素返回
 * pos的范围是 [1, length]
 * 不是从0开始哦！
 * 成功返回0
 *
 */
int
get_sta_list(sta_list_t list[], unsigned int index, ElemType *item)
{
	int i, k;

	/* the last array index, which point to the first item */
	k = list[LISTSIZE - 1].cur;

	/* 判断pos的位置 */
	if (index < 1 || index >= (list[0].data + 1))
		return -1;

	/* 找到第i个元素 */
	for (i = 1; i < index; ++i)
		k = list[k].cur;

	*item = list[k].data;
	return 0;
}

/*
 * 申请静态链表下一个空的数组序号
 */
int
malloc_list(sta_list_t list[])
{
	int i;

	i = list[0].cur;

	if (list[0].cur)
		list[0].cur = list[i].cur;

	return i;
}

/*
 * 释放静态链表所占用的某个数组序号
 */
void
free_list(sta_list_t list[], int i)
{
	list[i].cur = list[0].cur;
	list[0].cur = i;
}

/*
 * 插入算法的思路
 *
 * 只能是紧凑的插，不能前面插一部分，中间一部分，后面一部分，即整个链表都是
 * 集中的，不是分散的
 */
int
insert_sta_list(sta_list_t list[], unsigned int pos, ElemType item)
{
	int i, j, k;

	/* the last array index, which point to the first item */
	k = LISTSIZE - 1;

	/* 判断pos的位置 */
	if (pos < 1 || pos >= (list[0].data + 1))
		return -1;

	/* get the empty array index */
	i = malloc_list(list);
	if (i) {
		list[i].data = item;
		/* 找到插入元素之前的位置 */
		for (j = 1; j <= pos - 1; ++j)
			k = list[k].cur;
		printf("insert: i = %d, j = %d, k = %d\n", i, j, k);// j=5, k=4
		list[i].cur = list[k].cur;
		list[k].cur = i;

		list[0].data += 1;

		return 0;
	}

	return -2;
}

/*
 * 尾插法
 */
int
insert(sta_list_t list[], ElemType item)
{
	int i, j, k;

	/* the last array index, which point to the first item */
	k = LISTSIZE - 1;


	j = list[k].data;
	/* get the next empty index */
	i = malloc_list(list);
	if (i) {
		list[i].data = item;
		/* 数组0游标指向下一个空的数组 */
		list[0].cur = list[i].cur;
		/* 数组i的游标设为0，表示结束 */
		list[i].cur = 0;

		/* 第1次插入元素 */
		if (list[0].data == 0)
			list[k].cur = i;
		else
			list[j].cur = i;

		/* 长度+1 */
		list[0].data += 1;

		list[LISTSIZE - 1].data = i;

		//printf("[%d] = %d\n", i, list[i].data);

		return 0;
	}

	return -1;
}


/*
 * 删除算法的思路:
 */
int
delete_sta_list(sta_list_t list[], unsigned int pos, ElemType *item)
{
	int j, k;

	/* the last array index, which point to the first item */
	k = LISTSIZE - 1;

	if (pos < 1 || pos >= (list[0].data + 1))
		return -1;

	if (item != NULL)
		*item = list[pos].data;

	/* 找出删除元素的前一个元素 */
	for (j = 1; j <= pos - 1; ++j)
		k = list[k].cur;

	/* 删除元素的下一个游标 */
	j = list[k].cur;
	printf("delete: k = %d, j = %d\n", k, j);//k = 4, j = 11
	printf("list[%d].cur = %d\n", j, list[j].cur);
	list[k].cur = list[j].cur;

	free_list(list, j);

	list[0].data -= 1;

	return 0;
}

/*
 * 查找元素在表中的位置
 * 返回的位置为[1, length]，若找不到返回-1
 *
 * 时间复杂度为
 */
int
find_sta_list(sta_list_t list[], ElemType item)
{
	int i, k;

	k = LISTSIZE - 1;

	i = 0;
	while (list[k].cur != 0) {
		k = list[k].cur;
		if (list[k].data == item)
			return k;
		++i;
	}

	return -1;
}


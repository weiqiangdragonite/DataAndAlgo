/*
 * 堆是用数组来存放的完全二叉树
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct heap {
	int *data;
	int count;	/* 当前元素个数 */
	int size;	/* 堆最大容量 */
};


/*
 * 初始化堆
 */
void
create_heap(struct heap *h, int size)
{
	h->data = (int *) malloc(size * sizeof(int));
	h->size = size;
	h->count = 0;
}

/*
 * 释放堆
 */
void
free_heap(struct heap *h)
{
	if (h->data != NULL)
		free(h->data);
}


/*
 * 大顶堆插入
 * 数组从0开始存起，先把元素与要存放的位置的父结点比较，
 * 如果比父结点小，直接存放，如果比父结点大，则把父结点存到该位置，
 * 再继续与父结点的父结点进行对比
 */
void
insert(struct heap *h, int item)
{
	int i;

	if (h->count >= h->size) {
		printf("heap is full\n");
		return;
	}

	i = (h->count)++;	/* 取出要存放的位置 */
	for (; i > 0 && h->data[(i-1)/2] < item; i = (i-1)/2)
		h->data[i] = h->data[(i-1)/2];	/* 与父结点比较并交换位置 */
	h->data[i] = item;
}

/*
 * 大顶堆删除
 * 取出跟结点（最大值），把数组最后的一个元素移到根结点位置，
 * 然后把它与它的儿子进行对比，如果比儿子小，则交换位置，再继续比较
 */
void
delete(struct heap *h, int *item)
{
	int i, j, tmp;

	if (h->count == 0)
		return;
	if (item != NULL)
		*item = h->data[0];
	h->data[0] = h->data[h->count - 1];
	--h->count;

	/* 以下也就是heap_sort()里面的heap_adjust() */
	/* 根结点为i，左右儿子分别为 2i+1 和 2i+2 */
	i = 0;
	tmp = h->data[i];
	for (j = 2*i + 1; j < h->count; j = 2*i + 1) {
		/* 比较左右孩子，沿较大的节点向下筛选 */
		if ((j + 1) < h->count && h->data[j] < h->data[j + 1])	/* 左比右小 */
			++j;

		/* 父结点大于等于子结点，跳出 */
		if (tmp >= h->data[j])
			break;

		/* 孩子结点比父结点大，上位，进行下一轮筛选 */
		h->data[i] = h->data[j];
		i = j;	/* 指向该子结点 */
	}
	h->data[i] = tmp;
}

/*
 * 对已存在的数组（不是大顶堆）调用heap_adjust()来构成大顶堆
 * 这里省略
 */


/*
 * 创建大顶堆：
 * 方法1：就是把元素逐个通过插入操作来创建，时间代价最大为 O(NlogN)
 * 方法2：先把元素按顺序存入（不是排序），再调整为大顶堆
 *        具体如下，从最后一个存在孩子结点的结点开始调整，
 *        也就是heap_sort()里面的第一部分
	for (i = n / 2 - 1; i >= 0; --i)
		heap_adjust(a, i, n);
 */



int
main(int argc, char *argv[])
{
	//int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int a[] = {50, 35, 44, 25, 20};
	struct heap h;
	int i;

	create_heap(&h, 10);
	for (i = 0; i < sizeof(a)/sizeof(int); ++i)
		insert(&h, a[i]);

	//insert(&h, 200);

	printf("After init, count = %d\n", h.count);
	for (i = 0; i < h.count; ++i)
		printf("[%d]", h.data[i]);
	printf("\n");

	delete(&h, NULL);
	for (i = 0; i < h.count; ++i)
		printf("[%d]", h.data[i]);
	printf("\n");

	free_heap(&h);

	return 0;
}

/*
 * Heap Sort - 堆排序，不稳定算法
 * O(nlogn)
 */

#include <stdio.h>


void heap_sort_v1(int a[], int n);
void heap_sort_v2(int a[], int n);

/*
 * 构成大顶堆 - 根结点从0开始
 */
void
heap_adjust(int a[], int i, int n)
{
/* print info:
	int k;
	printf("Before heap adjust (i = %d, n = %d) : ", i, n);
	for (k = 0; k < n; ++k)
		printf("%d ", a[k]);
	printf("\n");
*/


	int j, tmp;

	/* 保存父结点的值 */
	tmp = a[i];

	/* 循环遍历结点的孩子 */
	/* 根结点是从0开始的，因为是二叉树的性质，完全二叉树，
	当前结点序号为i，其左孩子的序号一定是2i+1，右孩子序号一定是2i+2，它们的
	孩子也是以2i+1的位数增加 */
	/* 如果根结点是从1开始，则: (j=2*i; j<=n; j=2*i) */
	for (j = 2 * i + 1; j < n; j = 2 * i + 1) {
		/* 比较左右孩子，沿较大的节点向下筛选 */
		if ((j + 1) < n && a[j] < a[j + 1])	/* 左比右小 */
			++j;

		/* 父结点大于等于子结点，跳出 */
		if (tmp >= a[j])
			break;

		/* 孩子结点比父结点大，上位，进行下一轮筛选 */
		a[i] = a[j];
		i = j;	/* 指向该子结点 */
	}
	/* 如果孩子结点上位，此处父结点和孩子结点的值交换，如果是因为父结点
	大于等于子结点跳出循环的，此处可忽略 */
	a[i] = tmp;
	/* 最后到这里时父结点的值是最大的，形成一个大顶堆 */


/* print info:
	printf("After heap adjust (i = %d, n = %d) : ", i, n);
	for (k = 0; k < n; ++k)
		printf("%d ", a[k]);
	printf("\n\n");
*/
}

/*
 * 从小到大排列
 */
void
heap_sort_v1(int a[], int n)
{
	int i, tmp;

	/* 构成一个大顶堆 */
	/* 根结点是从0开始的，要从n/2-1开始，因为它们都是有孩子的结点 */
	/* 如果根结点是从1开始，则从n/2开始，即: (i=n/2; i>0; --i) */
	for (i = n / 2 - 1; i >= 0; --i)
		heap_adjust(a, i, n);

	/* 开始排序 */
	for (i = n - 1; i > 0; --i) {
		/* 将最后一个元素和第一个元素(最大值)交换 */
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;

		/* 将剩下的元素重新构造大顶堆 */
		heap_adjust(a, 0, i);
	}
}


int
main(int argc, char *argv[])
{
	int i, n;
	//int num[] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
	//int num[] = {49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
	int num[] = {0, 49, 38, 65, 97, 26, 13, 27, 49, 55, 4};

	n = sizeof(num) / sizeof(int);
	printf("Before heap sort: ");
	for (i = 1; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");


	heap_sort_v2(num, n-1);	/* 注意是n-1 */

	printf("After heap sort: ");
	for (i = 1; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}





/******************************************************************************/



void
swap(int a[], int x, int y)
{
	int tmp;

	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

int
cmp_func(int a, int b)
{
	if (a == b)
		return 0;
	else if (a < b)
		return -1;
	else if (a > b)
		return 1;
}



/*
 * 数组从1开始
 * 从下至上的重新建堆操作
 */
void
swim(int a[], int n, int k)
{
	/* 如果元素比其父元素大，则交换 */
	while (k > 1 && cmp_func(a[k], a[k/2]) > 0) {
		swap(a, k, k/2);
		k /= 2;
	}
}

/*
 * 数组从1开始
 * 由上至下的重新建堆操作
 */
void
sink(int a[], int n, int k)
{
	int j;

	while (2*k < n) {	/* 有子结点 */
		j = 2 * k;
		/* 找出最大的子结点 */
		if (cmp_func(a[j], a[j+1]) < 0)
			++j;
		/* 如果父结点比子结点大，表示满足要求 */
		if (cmp_func(a[k], a[j]) > 0)
			break;
		/* 否则与子结点交换位置 */
		swap(a, k, j);
		k = j;
	}
}


void
insert(int a[], int n, int item)
{
	/* 将元素添加到数组末尾 */
	a[++n] = item;
	/* 然后让该元素从下至上重建堆 */
	swim(a, n, n);
}

int
del_max(int a[], int n)
{
	/* 根结点从1开始 */
	int max = a[1];
	/* 将最后一个元素和根结点元素进行交换 */
	swap(a, 1, n);
	/* 对根结点从上至下重新建堆 */
	sink(a, n, 1);
	/* 将最后一个元素置空 */
	a[n--] = 0;	/* 这里假设0为置空 */

	return max;
}



/*
 * 数组从1开始
 */
void
heap_sort_v2(int a[], int n)
{
	int k;

	/* 创建大顶堆 */
	for (k = n / 2; k >= 1; --k)
		sink(a, n, k);

	/* 排序 */
	/* 循环移除顶部元素到数组末尾，然后利用Sink重建堆的操作 */
	while (n > 1) {
		swap(a, 1, n--);
		sink(a, n, 1);
	}
}





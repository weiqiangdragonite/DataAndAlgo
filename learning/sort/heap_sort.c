/*
 * Heap Sort - 堆排序，不稳定算法
 */

#include <stdio.h>


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
	for (j = 2 * i + 1; j < n; j = 2 * i + 1) {
		/* 比较左右孩子，沿较大的节点向下筛选 */
		if (a[j] < a[j + 1] && (j + 1) < n)
			++j;

		/* 父结点大于等于子结点，跳出 */
		if (tmp >= a[j])
			break;

		/* 孩子结点上位，进行下一轮筛选 */
		a[i] = a[j];
		i = j;
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
 *
 */
void
heap_sort(int a[], int n)
{
	int i, tmp;

	/* 构成一个大顶堆 */
	/* 根结点是从0开始的，要从n/2-1开始，因为它们都是有孩子的结点 */
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
	int num[] = {49, 38, 65, 97, 26, 13, 27, 49, 55, 4};

	n = sizeof(num) / sizeof(int);
	printf("Before heap sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	heap_sort(num, n);

	printf("After heap sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}

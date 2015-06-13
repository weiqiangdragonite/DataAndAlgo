/*
 * Quick Sort - 不稳定算法
 */

#include <stdio.h>

inline void
swap(int a[], int x, int y)
{
	int tmp;

	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

/*
 * 从数组中选取一个元素，并放到一个位置，使得它左边的值比它小，右边的值比它大，
 * 返回这个元素的位置。
 */
int
partition(int a[], int low, int high)
{
	int key;

	/* 将第一个记录作为关键记录 */
	key = a[low];
	/* 从两端交替向中间扫描 */
	while (low < high) {
		/* 找出比关键记录小的元素并交换到低端 */
		while (low < high && a[high] >= key)
			--high;
		swap(a, low, high);

		/* 找出比关键记录大的元素并交换到高端 */
		while (low < high && a[low] <= key)
			++low;
		swap(a, low, high);
	}

	/* 返回关键记录的位置 */
	return low;
}

/*
 *
 */
void
qsort(int a[], int low, int high)
{
	int i;
	int pivot;
	if (low < high) {
		/* 将a[low ... heigh]一分为二，中间值为pivot */
		pivot = partition(a, low, high);
		printf("After partition, pivot = %d\n", pivot);
		printf("a[%d] ~ a[%d] = ", low, high);
		for (i = low; i <= high; ++i)
			printf("%d ", a[i]);
		printf("\n");

		/* 对前半部分递归排序 */
		qsort(a, low, pivot - 1);
		/* 对后半部分递归排序 */
		qsort(a, pivot + 1, high);
	}
}


/*
 * 快速排序 - 递归调用
 */
void
quick_sort(int a[], int n)
{
	/* 从下标0开始到下标n-1 */
	qsort(a, 0, n - 1);
}


int
main(int argc, char *argv[])
{
	int i, n;
	int a[] = {50, 10, 90, 30, 70, 40, 80, 60, 20, 110, 100};

	n = sizeof(a) / sizeof(int);

	printf("Before quick sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");

	quick_sort(a, n);

	printf("After quick sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}


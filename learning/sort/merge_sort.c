/*
 * Merge Sort
 */

#include <stdio.h>

int count = 0;

/*
 * 将有序的b[start ... mid]和有序的b[mid+1 ... end]归并为有序的a[start ... end]
 * a为原数组，也是准备归并为有序的数组
 * b为有序的临时数组
 *
 * merge运算正确，但我的msort设计有问题，所以merge也有点问题
 */
void
merge(int a[], int b[], int start, int mid, int end)
{
	int i, j;

	/* 将b中记录由小到大地并入a */
	for (i = start, j = mid + 1; start <= mid && j <= end; ++i) {
		if (b[start] <= b[j])
			a[i] = b[start++];
		else
			a[i] = b[j++];
	}

	/* 将剩余的b[start ... mid]复制到a[] */
	while (start <= mid)
		a[i++] = b[start++];

	/* 将剩余的b[mid ... end]复制到a[] */
	while (j <= end)
		a[i++] = b[j++];
}

/*
 * 将[n ... m]归并排序为[n ... m]
 * 注意n为数组的开始下标，m为数组的结束下标，是[n, m]不是[n, m)。
 * 即9个元素的话,m=8
 */
void
msort(int a[], int b[], int n, int m)
{
	int i, mid;

	if (n == m) {
		b[n] = a[n];
	} else {
		mid = (n + m) / 2;

		/* 将a[n ... mid]归并为有序的b[n ... mid] */
		msort(a, b, n, mid);

		/* 将a[mid+1 ... m]归并为有序的b[mid+1 ... m] */
		msort(a, b, mid + 1, m);

		/* 将b[n ... mid]和b[mid+1 ... m]归并到a[n ... m] */
		merge(a, b, n, mid, m);

		/* 此时a[n .. m]为有序，但b[n .. m]还是无序的，所以要复制一下 */
		for (i = n; i <= m; ++i)
			b[i] = a[i];
	}
}

/*
 * 使用递归调用 - 形式简单，实用性差
 * a为原数组，b为临时数组
 * 数组从0开始
 */
void
merge_sort_v1(int a[], int n)
{
	int b[n];
	msort(a, b, 0, n - 1);
}





/*
 * 非递归调用
 * 注意n不是数组结束的下标，是数组的长度
 */
void
merge_pass(int a[], int b[], int gap, int n)
{
	int i, start;

	start = 0;
	/* 对数组a两两归并 */
	while (start <= n - 2 * gap) {
		merge(a, b, start, start + gap - 1, start + 2 * gap - 1);

		//for (i = start; i <= start + 2 * gap - 1; ++i) {
		//	b[i] = a[i];
		//	++count;
		//}

		start += 2 * gap;
	}

	/* 此时a[0 .. n]为有序，但b[0 .. n]还是无序的，所以要复制一下。
	这一步可以放到while里面去? 好像不行，最后两个序列没排好*/
	for (i = 0; i < n; ++i) {
		b[i] = a[i];
		++count;
	}

	/* 归并最后两个序列 */
	if (start < n - gap + 1) {
		merge(a, b, start, start + gap - 1, n - 1);
	}
}

/*
 * 非递归调用
 */
void
merge_sort_v2(int a[], int n)
{
	int b[n];
	int i, gap;

	/* 复制数组a为临时数组b */
	for (i = 0; i < n; ++i)
		b[i] = a[i];

	gap = 1;
	/* 两两循环归并 */
	while (gap < n) {
		merge_pass(a, b, gap, n);
		gap *= 2;
	}
}


int
main(int argc, char *argv[])
{
	int i, n;
	int a[] = {50, 10, 90, 30, 70, 40, 80, 60, 20, 110, 100};
	//int a[] = {6, 202, 100, 301, 38, 8, 1};

	n = sizeof(a) / sizeof(int);

	printf("Before merge sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");

	merge_sort_v2(a, n);

	printf("After merge sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");

	printf("count = %d\n", count);

	return 0;
}


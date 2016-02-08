/*
 * Bubble Sort - 属于稳定算法
 * 推荐使用大数向下沉
 * 最坏: 逆序 O(n^2)
 * 最好: 顺序 O(n)
 */

#include <stdio.h>

/*
 * 初级版 - 小数向上升
 * 比如有10个数，总共要比较 n-1 轮，即要比较9轮；
 * 每轮从最后开始比较；
 * 每比较i轮，前面的i个元素就排序好。
 */
void
bubble_sort_v1(int a[], int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; ++i) {
		for (j = n - 1; j > i; --j) {
			if (a[j] < a[j-1]) {
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}

/*
 * 优化版 - 小数向上升
 * 比如有10个数，总共要比较 n-1 轮，即要比较9轮；
 * 每轮从最后开始比较；
 * 每比较i轮，前面的i个元素就排序好。
 */
void
bubble_sort_v2(int a[], int n)
{
	int i, j, tmp;
	unsigned char is_sorted;

	for (i = 0; i < n - 1; ++i) {
		is_sorted = 0;

		for (j = n - 1; j > i; --j) {
			if (a[j] < a[j-1]) {
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;

				is_sorted = 1;
			}
		}

		if (!is_sorted)
			break;
	}
}

/*
 * 初级版 - 大数向下沉
 * 比如有10个数，总共要比较 n-1 轮，即要比较9轮；
 * 每轮从前面开始比较；
 * 每比较i轮，最后的i个元素就排序好，即每轮要比较 n-1-i 次。
 */
void
bubble_sort_v3(int a[], int n)
{
/* a better way:
	int i, j;
	for (i = n-1; i > 0; --i) {
		for (j = 0; j < i; ++j) {
			if (a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}
	}
*/



	int i, j, tmp;

	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < (n-1-i); ++j) {
			if (a[j] > a[j+1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

/*
 * 优化版 - 大数向下沉
 * 比如有10个数，总共要比较 n-1 轮，即要比较9轮；
 * 每轮从前面开始比较；
 * 每比较i轮，最后的i个元素就排序好，即每轮要比较 n-1-i 次。
 */
void
bubble_sort_v4(int a[], int n)
{
	int i, j, tmp;
	unsigned char is_sorted;

	for (i = 0; i < n - 1; ++i) {
		is_sorted = 0;

		for (j = 0; j < (n-1-i); ++j) {
			if (a[j] > a[j+1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;

				is_sorted = 1;
			}
		}

		/* 如果经过1轮的比较都没有发生交换，说明数组已经排序好了 */
		if (!is_sorted)
			break;
	}
}


int
main(int argc, char *argv[])
{
	int i, n;
	int num[] = {1, 2, 3, 4, 5, 6, 7, 7, 9, 8};

	n = sizeof(num) / sizeof(int);
	printf("Before bubble sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	bubble_sort_v2(num, n);

	printf("After bubble sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}

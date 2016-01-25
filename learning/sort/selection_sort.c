/*
 * Simple Selection Sort - 属于稳定算法
 * 时间复杂度: O(n^2)
 */

#include <stdio.h>

/*
 * 比如有n个数，总共要比较 n - 1 轮；
 * 每轮选出最小的数，按顺序放在前面。
 */
void
selection_sort(int a[], int n)
{
	int i, j, min, tmp;

	for (i = 0; i < n - 1; ++i) {
		min = i;
		for (j = i + 1; j < n; ++j) {
			if (a[j] < a[min])
				min = j;
		}

		if (min != i) {
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
}

int
main(int argc, char *argv[])
{
	int i, n;
	int num[] = {9, 1, 5, 7, 8, 3, 7, 4, 6, 2};

	n = sizeof(num) / sizeof(int);
	printf("Before selection sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	selection_sort(num, n);

	printf("After selection sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}





/*
 * cmp_func是比较函数
 */
void
selection_sort(ElemType a[], int n)
{
	for (i = 0; i < n; ++i) {
		min = i;
		/* 从第i+1个元素开始查找最小值 */
		for (j = i + 1; j < n; ++j) {
			if (cmp_func(a[j], a[min]) < 0)
				min = j;
		}

		if (min != i)
			swap(a, i, min);
	}
}


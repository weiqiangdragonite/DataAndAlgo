/*
 * Insertion Sort - 稳定算法
 * 时间复杂度: O(n^2)
 */

#include <stdio.h>

/*
 * 直接插入排序算法
 */
void
straight_insertion_sort_v1(int a[], int n)
{
	int i, j, k, tmp;

	for (i = 1; i < n; ++i) {

		// 首先要找到元素a[i]需要插入的位置
		j = 0;
		while ((a[j] < a[i]) && (j < i))
			++j;

		// 将元素插入到正确的位置
		// 若i == j说明a[i]刚好在正确的位置
		// 否则将元素往后移
		if (i != j) {
			tmp = a[i];
			for (k = i; k > j; --k)
				a[k] = a[k-1];
			a[j] = tmp;
		}
	}
}

/*
 *
 */
void
straight_insertion_sort_v2(int a[], int n)
{
	int i, j, tmp;

	for (i = 1; i < n; ++i) {
		// 将a[i]插入到正确的位置
		if (a[i] < a[i-1]) {
			tmp = a[i];
			// 元素后移
			for (j = i - 1; a[j] > tmp && j >= 0; --j)
				a[j+1] = a[j];
			/* 可用下面替换
			j = i - 1;
			while (j >= 0 && a[j] > tmp) {
				a[j+1] = a[j];
				--j;
			}
			*/
			a[j+1] = tmp;
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

	straight_insertion_sort_v2(num, n);

	printf("After selection sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}



void
insertion_sort(ElemType a[], int n)
{
	/* 从第二个元素开始 */
	for (i = 1; i < n; ++i) {
		/* 从第i个元素开始，和前面已经排好序的i-1个元素比较 */
		for (j = i; j > 0; --j) {
			if (cmp_func(a[j], a[j-1]) < 0)
				swap(a, j, j-1);
			/* 如果大于，则不用继续往前比较了，因为前面的元素
			 * 已经是排好序的了。*/
			else
				break;
		}
	}
}



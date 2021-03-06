/*
 * Shell Sort - 不稳定算法
 * 时间复杂度: 
 * 最坏: O(n^2)
 */

#include <stdio.h>

/*
 * 希尔排序 - 原始算法
 */
void
shell_sort_v1(int a[], int n)
{
	int i, j, k, tmp, gap;

	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = 0; i < gap; ++i) {
			// 直接插入排序
			for (j = i + gap; j < n; j += gap) {
				if (a[j] < a[j - gap]) {
					tmp = a[j];
					for (k = j - gap; a[k] > tmp && k >=0; k -= gap)
						a[k + gap] = a[k];
					a[k + gap] = tmp;
				}
			}
		}
	}
}

/*
 * 希尔排序 - 优化版
 */
void
shell_sort_v2(int a[], int n)
{
	int i, k, tmp, gap;

	for (gap = n / 2; gap > 0; gap /= 2) {
		// 从数组第gap个元素开始
		for (i = gap; i < n; ++i) {
			// 每个元素和自己组内的数据进行直接插入排序
			if (a[i] < a[i - gap]) {
				tmp = a[i];
				for (k = i - gap; a[k] > tmp && k >= 0; k -= gap)
					a[k + gap] = a[k];
				a[k + gap] = tmp;
			}
		}
	}
}



typedef int ElemType;

int
cmp_func(ElemType a, ElemType b)
{
	if (a == b)
		return 0;
	else if (a < b)
		return -1;
	else if (a > b)
		return 1;
}

void
swap(ElemType a[], int i, int j)
{
	ElemType tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void
shell_sort(ElemType a[], int n)
{
	int gap, i, j;

	/* gap从中间开始，直至为1 */
	for (gap = n / 2; gap > 0; gap /= 2) {
		/* 从数组第gap个元素开始(插入排序) */
		for (i = gap; i < n; ++i) {
			/* 每个元素和自己组内的数据进行直接插入排序 */
			/* 从第i个元素开始，和前面已经排好序的i/gap个元素比较 */
			for (j = i; j >= gap; j -= gap) {
				if (cmp_func(a[j], a[j-gap]) < 0)
					swap(a, j, j-gap);
				else
					break;
			}
		}


		printf("gap = %d: ", gap);
		for (i = 0; i < n; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
}


int
main(int argc, char *argv[])
{
	int i, n;
	int num[] = {49, 38, 65, 97, 26, 13, 27, 49, 55, 4};

	n = sizeof(num) / sizeof(int);
	printf("Before shell sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	shell_sort(num, n);

	printf("After shell sort: ");
	for (i = 0; i < n; ++i)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}

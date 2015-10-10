/*
 * Selection Problem from Chapter 1 in Page 1(English version)
 *
 * Problem: There have N numbers, find out the k largest number.
 */


/*
 * use python to create random number:
 *
 * >>> import random
 * >>> print random.randint(a, b) ---> return number[a, b]
 * print "%d," % random.randint(0, 30),
 */

#include <stdio.h>


/*
 * solution 1: use bubble sort
 *
 * sort from largest to smallest;(decrease)
 * need to compare n - 1 turns; (10 numbers, need compare 9 turns)
 */
void
bubble_sort(int array[], int size)
{
	int i, j, tmp, sorted;

	for (i = 0; i < size - 1; ++i) {
		sorted = 0;
		for (j = 1; j < size - i; ++j) {
			if (array[j - 1] < array[j]) {
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				sorted = 1;
			}
		}
		if (!sorted)
			break;
	}
}


/*
 * insert num in its right sorted position, and delete the other smaller one
 */
void
insert(int array[], int size, int num)
{
	int i, j;

	/* find num position */
	for (i = 0; i < size; ++i) {
		if (num > array[i])
			break;
	}
	if (i >= size)
		return;

	for (j = size - 1; j > i; --j) {
		array[j] = array[j - 1];
	}
	array[j] = num;
}


/*
 * solution 2:
 * first read k numbers into array and sorted by decrease;
 * then read next number, if it smaller than the k sorted number, ignore;
 * otherwise put it in the right position
 *
 * Be careful, the k number in array is array[k-1]
 */
int
solution2(int array[], int size, int k)
{
	int tmp[k];	/* not sure, it's right in C99, but not recommed */
	int i;

	for (i = 0; i < k; ++i)
		tmp[i] = array[i];
	bubble_sort(tmp, k);

	/* i start form k, not k+1 */
	for (i = k; i < size; ++i) {
		if (array[i] > tmp[k - 1])
			insert(tmp, k, array[i]);
	}

	return tmp[k - 1];
}


int
main(int argc, char *argv[])
{
	int i;
	//int array[] = {9, 8, 7, 7, 6, 5, 4, 3, 2, 1};
	//int array[] = {1, 2, 3, 4, 5, 6, 7, 7, 9, 8};
	int array[] = {15, 17, 11, 7, 3, 15, 24, 28, 30, 16, 9, 7, 24, 2, 0, 8, 25, 18, 3, 13, 2, 0, 4, 9, 20, 28, 21, 25, 3, 25};
	int size = sizeof(array) / sizeof(int);
	int k_max;

	k_max = solution2(array, size, 28);
	printf("k_max = %d\n", k_max);

	bubble_sort(array, size);

	for (i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}




/*
 *
 */

/*
1. Find pair with given sum in the array

Given an unsorted array of integers, find a pair with given sum in it.

For example,

Input:
arr = [8, 7, 2, 5, 3, 1]
sum = 10

Output: 
Pair found at index 0 and 2 (8 + 2)
OR
Pair found at index 1 and 4 (7 + 3)
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int arr[] = { 8, 7, 2, 5, 3, 1 };
	int sum = 10;
	int times = 0;
	int i, j;
	int len = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < len - 1; ++i) {
		for (j = i + 1; j < len; ++j) {
			if (arr[i] + arr[j] == sum) {
				if (times)
					printf("Or\n");
				printf("Pair found at index %d and %d (%d + %d)\n", i, j, arr[i], arr[j]);
				times += 1;
			}
		}
	}

	return 0;
}

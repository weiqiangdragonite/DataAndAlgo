/*

中国大学MOOC-陈越、何钦铭-数据结构基础习题集


01-复杂度2. Maximum Subsequence Sum (25)


Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence 
is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum 
Subsequence is the continuous subsequence which has the largest sum of its 
elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum 
subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the 
last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first 
line contains a positive integer K (<= 10000). The second line contains K 
numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first 
and the last numbers of the maximum subsequence. The numbers must be separated 
by one space, but there must be no extra space at the end of a line. In case 
that the maximum subsequence is not unique, output the one with the smallest 
indices i and j (as shown by the sample case). If all the K numbers are 
negative, then its maximum sum is defined to be 0, and you are supposed to 
output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4


--------------------------------------------------------------------------------

8
-1 3 -2 4 -6 1 6 -1


*/

#include <stdio.h>

void max_subseq_sum(int a[], int n);


int
main(int argc, char *argv[])
{
	int i, j, sum, max, max_i, max_j;
	int k, negative;

	negative = 1;
	scanf("%d", &k);
	int num[k];

	for (i = 0; i < k; ++i) {
		scanf("%d", &num[i]);
		if (num[i] >= 0)
			negative = 0;
	}

	//if (negative) {
	//	printf("0 %d %d\n", num[0], num[k - 1]);
	//	return 0;
	//}


	/* 效率: O(n^2) */
/*
	max = num[0];
	max_i = max_j = 0;
	for (i = 0; i < k; ++i) {
		sum = 0;
		for (j = i; j < k; ++j) {
			sum += num[j];
			if (sum > max) {
				max = sum;
				max_i = i;
				max_j = j;
			}
		}
	}
*/

	/*
	printf("max: i = %d, j = %d\n", max_i, max_j);
	for (i = max_i; i <= max_j; ++i)
		printf("%d ", num[i]);
	printf("\n");
	*/

	//printf("%d %d %d\n", max, num[max_i], num[max_j]);


	max_subseq_sum(num, k);

	return 0;
}


/*
 * 算法2：分而治之
 * 把大问题分成小问题逐一解决，最后把结果合并。
 *
 * 1.把数组分成两半，递归解决左右两边的问题；
 * 2.递归解决左边的问题：得到最大子列和；
 * 3.递归解决右边得到右边最大的子列和；
 * 4.找出左右两边跨越边界的最大子列和；
 * 5.数组最大的子列和就是上面三个数中的一个；
 *
 * 效率：O(nlogn)
 */



/*
 * 算法3：在线处理
 *
 * 效率：O(n)
 */
void
max_subseq_sum(int a[], int n)
{
	int i, sum, max_sum;
	sum = max_sum = 0;

	int max_i, max_j;
	max_i = max_j = 0;

	for (i = 0; i < n; ++i) {
		sum += a[i];

		/* 发现更大的和，更新当前最大值 */
		if (sum > max_sum) {
			max_sum = sum;
			// 没写出
			//max_i = i - max_j;
			max_j = i;

		/* 如果当前子列和为负，则不能使后面的部分和增大，抛弃 */
		} else if (sum < 0) {
			sum = 0;
			//max_i = i + 1;
		}

	}

	//printf("%d %d %d\n", max_sum, max_i, max_j);
}


/*


中国大学MOOC-翁恺-C语言程序设计习题集


04-3. 统计素数并求和(20)


本题要求统计给定整数M和N区间内素数的个数并对它们求和。

输入格式：

输入在一行中给出2个正整数M和N（1<=M<=N<=500）。

输出格式：

在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。

输入样例：
10 31
输出样例：
7 143


素数一般指质数
除了1和它本身外，不能被其他自然数整除（除0以外）的数称之为素数（质数）；否则称为合数。
最小的质数是2

*/

#include <stdio.h>


/* 抄了一个判断素数的:
   把n除以从2到n的平方根之间的每一个数，只要有一个余数为0，n就不是素数 */
int
is_prime(int n)
{
	int d;
	if (n <= 1)
		return 0;
	for (d = 2; d * d <= n; ++d) {
		if (n % d == 0)
			return 0;
	}
	return 1;
}


int
main(int argc, char *argv[])
{
	int m, n;
	int num, sum, count;
	int i, j;
	unsigned char is_prime_num;

	scanf("%d %d", &m, &n);

	sum = count = 0;
	// [m, n]
	for (i = m; i <= n; ++i) {
		num = i;
		is_prime_num = 0;

		// 效率太低了
		for (j = 2; j <= num; j++) {
			if (j == num)
				is_prime_num = 1;
			if (num % j == 0)
				break;
		}
		if (is_prime_num) {
			++count;
			sum += num;
			//printf("%d\n", num);
		}
	}

	printf("%d %d\n", count, sum);

	return 0;
}




/*


中国大学MOOC-翁恺-C语言程序设计习题集


07-3. 数素数 (20)


令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103


5 - 27
即第5个素数 到第27个素数之间的所有素数
范围是从第M个素数到第N个素数（最大是第10000个素数）

*/

#include <stdio.h>
#include <math.h>


int
main(int argc, char *argv[])
{
	int m, n, i, j;
	int num, is_prime_num, count, counter, tmp;

	scanf("%d %d", &m, &n);

	int prime[10000];
	count = counter = 0;
	for (i = 2; count < 10000; ++i) {
		num = i;
		is_prime_num = 0;

		tmp = (int) sqrt(num);
		for (j = 2; j <= num; j++) {
			if (j > tmp) {
				is_prime_num = 1;
				break;
			}
			if (num % j == 0)
				break;
		}
		if (is_prime_num) {
			prime[count++] = num;
			//sum += num;
			//printf("%d\n", num);
		}
	}

	for (i = m; i <= n; ++i) {
		//printf("%d ", prime[i-1]);
		++counter;

		if (counter % 10 == 1)
			printf("%d", prime[i-1]);
		else if (counter % 10 == 0)
			printf(" %d\n", prime[i-1]);
		else
			printf(" %d", prime[i-1]);

	}
	if (counter % 10 != 0)
		printf("\n");

	return 0;

/*
	count = counter = 0;
	for (i = 1; counter < n; ++i) {
		num = i;
		is_prime_num = 0;

		for (j = 2; j <= num; j++) {
			if (j == num)
				is_prime_num = 1;
			if (num % j == 0)
				break;
		}
		if (is_prime_num) {
			++counter;
			if (counter < m)
				continue;
			//else if (counter > n)
			//	break;

			++count;
			if (count % 10 == 1)
				printf("%d", num);
			else if (count % 10 == 0)
				printf(" %d\n", num);
			else
				printf(" %d", num);
		}
	}
	if (count % 10 != 0)
		printf("\n");
*/

	return 0;
}





/*

中国大学MOOC-陈越、何钦铭-数据结构基础习题集


00-自测2. 素数对猜想 (20)


让我们定义 dn 为：dn = p(n+1) - pn，其中 pi 是第i个素数。
显然有 d1=1 且对于n>1有 dn 是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4

--------------------------------------------------------------------------------

质数（prime number）又称素数

2    3   5   7  11  13  17  19
23  29  31  37  41  43  47  53
59  61  67  71  73  79  83  89
97 101 103 107 109 113 127 131


d1 = p2 - p1 = 3 - 2 = 1
d2 = p3 - p2 = 5 - 3 = 2
d3 = p4 - p3 = 7 - 5 = 2
d4 = p5 - p4 = 11 - 7 = 4
d5 = p6 - p5 = 13 - 11 = 2
d6 = p7 - p6 = 17 - 13 = 4
d7 = p8 - p7 = 19 - 17 = 2



*/

#include <stdio.h>
#include <math.h>

int get_prime(int num, const char op);
int is_prime(const int num);

int
main(int argc, char *argv[])
{
	int i, j, n, counter;

	scanf("%d", &n);

	i = get_prime(n, '-');		/* the largest prime */
	j = get_prime(i - 1, '-');	/* the second largest */

	counter = 0;
	while (i && j) {
		if (i - j == 2)
			++counter;

		i = j;
		j = get_prime(i - 1, '-');
	}
	printf("%d\n", counter);

	return 0;
}

/*
 *
 */
int
get_prime(int num, const char op)
{
	while (num) {
		if (is_prime(num))
			return num;

		if (op == '+')
			++num;
		else if (op == '-')
			--num;
		else
			break;
	}

	return 0;
}

/*
 * 效率有点低
 */
int
is_prime(const int num)
{
	if (num < 2)
		return 0;

	int i, n;
	n = (int) sqrt(num);

	for (i = 2; i <= n; ++i) {
		if (num % i == 0)
			return 0;
	}

	return 1;
}



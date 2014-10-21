/*


中国大学MOOC-翁恺-C语言程序设计习题集


04-1. 水仙花数(20)


水仙花数是指一个N位正整数（N>=3），它的每个位上的数字的N次幂之和等于它本身。
例如：153 = 1^3 + 5^3+ 3^3。 本题要求编写程序,计算所有N位水仙花数。

输入格式：

输入在一行中给出一个正整数N（3<=N<=7）。

输出格式：

按递增顺序输出所有N位水仙花数，每个数字占一行。

输入样例：
3
输出样例：
153
370
371
407


总结一下：
调用函数很花时间的，即使是系统库函数
可以将经常要计算的数抽出来，先计出结果，用时就可以直接拿答案了

*/



#include <stdio.h>
#include <math.h>

double cache(int x, int n);

int
main(int argc, char *argv[])
{
	int n, start, end, num, sum, tmp, res, i, j;
	int cache[10] = { 0 };

	scanf("%d", &n);

	//start = pow(10, n - 1);
	start = 1;
	for (i = 1; i < n; ++i)
		start *= 10;
	end = start * 10;


	for (i = 1; i < 10; ++i) {
		res = 1;
		for (j = 0; j < n; ++j)
			res *= i;
		cache[i] = res;
	}

	while (1) {
		num = start;
		sum = 0;

		while (num != 0) {
			tmp = num % 10;
			//sum += cache(tmp, n);
			//res = 1;
			//for (i = 0; i < n; ++i)
			//	res *= tmp;
			sum += cache[tmp];
			num /= 10;
		}
		if (sum == start)
			printf("%d\n", start);

		if (++start >= end)
			break;
	}

	return 0;
}

double
cache(int x, int n)
{
	static double res1, res2, res3, res4, res5, res6, res7, res8, res9;
	static double i = 0;

	if (i == 0) {
		res1 = pow(1, n);
		res2 = pow(2, n);
		res3 = pow(3, n);
		res4 = pow(4, n);
		res5 = pow(5, n);
		res6 = pow(6, n);
		res7 = pow(7, n);
		res8 = pow(8, n);
		res9 = pow(9, n);
		++i;
	}

	switch (x) {
	case 1:
		return res1;
	case 2:
		return res2;
	case 3:
		return res3;
	case 4:
		return res4;
	case 5:
		return res5;
	case 6:
		return res6;
	case 7:
		return res7;
	case 8:
		return res8;
	case 9:
		return res9;
	default:
		return 0;
	}
}

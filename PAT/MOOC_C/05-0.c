/*


中国大学MOOC-翁恺-C语言程序设计习题集


05-0. 求序列前N项和(15)


本题要求编写程序,计算序列 2/1+3/2+5/3+8/5+... 的前N项之和。注意该序列从第2项起，每一项的
分子是前一项分子与分母的和，分母是前一项的分子。

输入格式：

输入在一行中给出一个正整数N。

输出格式：

在一行中输出部分和的值，精确到小数点后2位。题目保证计算结果不超过双精度范围。

输入样例：
20
输出样例：
32.66


numerator 分子
denominator 分母

*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int n;
	double tmp, i;
	double num, sum, den;

	scanf("%d", &n);

	num = 2;
	den = 1;
	sum = 0;
	for (i = 1; i <= n; ++i) {
		sum += (num / den);

		tmp = num;
		num += den;
		den = tmp;
	}
	// printf("%.2lf", sum);
	// I copy it from http://www.cnblogs.com/aexin/p/3874222.html
	printf("%.2lf\n", sum);

	return 0;
}

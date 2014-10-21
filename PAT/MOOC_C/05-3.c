/*


中国大学MOOC-翁恺-C语言程序设计习题集


05-3. 求a的连续和(15)


输入两个整数a和n，a的范围是[0,9]，n的范围是[1,8]，
求数列之和S = a+aa+aaa+...+aaa...a（n个a）。 
如a为2、n为8时输出的是2+22+222+...+22222222的和。

输入格式：

输入在一行中给出两个整数，先后表示a和n。

输出格式：

在一行中输出要求的数列之和。

输入样例：
2 4
输出样例：
2468


2 + 22 + 222 + 2222 = 2468


2
2 * 10 + 2
22 * 10 + 2
222 * 10 + 2
*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int a, n;
	int sum, num, i;


	scanf("%d %d", &a, &n);

	sum = 0;
	num = a;
	for (i = 1; i <= n; ++i) {
		sum += num;
		num = num * 10 + a;
	}
	printf("%d\n", sum);

	return 0;
}

/*


中国大学MOOC-翁恺-C语言程序设计习题集


07-1. 换个格式输出整数 (15)


让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出
任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123


*/

#include <stdio.h>


int
main(int argc, char *argv[])
{
	int num, tmp, i;

	scanf("%d", &num);

	/* n < 1000 */
	if (num >= 100) {
		tmp = num / 100;
		for (i = 0; i < tmp; ++i)
			printf("B");
		num = num - tmp * 100;
	}
	if (num < 100 && num >= 10) {
		tmp = num / 10;
		for (i = 0; i < tmp; ++i)
			printf("S");
		num = num - tmp * 10;
	}
	if (num < 10 && num > 0) {
		for (i = 0; i < num; ++i)
			printf("%d", i+1);
	}
	printf("\n");

	return 0;
}





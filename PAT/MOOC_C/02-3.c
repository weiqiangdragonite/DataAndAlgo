/*


中国大学MOOC-翁恺-C语言程序设计习题集


02-3. 逆序的三位数(10)


程序每次读入一个正3位数，然后输出按位逆序的数字。注意：当输入的数字含有结尾的0时，输出不应带有
前导的0。比如输入700，输出应该是7。

输入格式：

每个测试是一个3位的正整数。

输出格式：

输出按位逆序的数。

输入样例：
123
输出样例：
321

*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int num, i, j;

	scanf("%d", &num);

	for (i = 0; i < 3; ++i) {
		j = num % 10;
		if (j != 0)
			printf("%d", j);
		num /= 10;
	}
	printf("\n");

	return 0;
}

/*


中国大学MOOC-翁恺-C语言程序设计习题集


10-4. 字符串循环左移(20)


输入一个字符串和一个非负整数N，要求将字符串循环左移N次。

输入格式：

输入在第1行中给出一个不超过100个字符长度的、以回车结束的非空字符串；第2行给出非负整数N。

输出格式：

在一行中输出循环左移N次后的字符串。

输入样例：
Hello World!
2
输出样例：
llo World!He

Hello World!Hello Wo rld!Hello World! -> rld!Hello Wo

20 % 12 = 8
2 % 12 = 2

*/

#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char str[256];
	int n, i, len, start;

	fgets(str, sizeof(str), stdin);
	scanf("%d", &n);

	// remove '\n'
	str[strlen(str) - 1] = '\0';

	len = strlen(str);

	start = n % len;

	for (i = start; i < len; ++i)
		printf("%c", str[i]);
	for (i = 0; i < start; ++i)
		printf("%c", str[i]);
	printf("\n");

	return 0;
}



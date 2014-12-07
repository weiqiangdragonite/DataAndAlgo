/*


中国大学MOOC-翁恺-C语言程序设计习题集


10-1. 在字符串中查找指定字符(15)


输入一个字符串S，再输入一个字符c，要求在字符串S中查找字符c。如果找不到则输出“Not found”；
若找到则输出字符串S中从c开始的所有字符。

输入格式：

输入在第1行中给出一个不超过80个字符长度的、以回车结束的非空字符串；在第2行中给出一个字符。

输出格式：

在一行中按照题目要求输出结果。

输入样例1：
It is a black box
b
输出样例1：
black box
输入样例2：
It is a black box
B
输出样例2：
Not found

*/

#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char line[256];
	char ch;
	int i, is_found;

	fgets(line, sizeof(line), stdin);
	scanf("%c", &ch);

	is_found = 0;
	for (i = 0; line[i] != '\0'; ++i) {
		if (line[i] == ch)
			is_found = 1;

		if (is_found)
			printf("%c", line[i]);
	}
	if (!is_found)
		printf("Not found\n");

	return 0;
}





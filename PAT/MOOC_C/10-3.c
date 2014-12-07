/*


中国大学MOOC-翁恺-C语言程序设计习题集


10-3. 字符串逆序(15)


输入一个字符串，对该字符串进行逆序，输出逆序后的字符串。

输入格式：

输入在一行中给出一个不超过80个字符长度的、以回车结束的非空字符串。

输出格式：

在一行中输出逆序后的字符串。

输入样例：
Hello World!
输出样例：
!dlroW olleH

*/

#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char str[256];
	int i;

	fgets(str, sizeof(str), stdin);

	// because have '\n', and start from 0, so we need to reduce 2
	for (i = strlen(str) - 2; i >= 0; --i)
		printf("%c", str[i]);
	printf("\n");

	return 0;
}



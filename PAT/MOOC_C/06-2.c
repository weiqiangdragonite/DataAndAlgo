/*


中国大学MOOC-翁恺-C语言程序设计习题集


06-2. 字符串字母大小写转换(10)


输入一个以#结束的字符串，本题要求将小写字母全部转换成大写字母，把大写字母全部转换成小写字母，
其它字符不变。

输入格式：

输入在一行中给出一个长度不超过40的、以#结束的非空字符串。

输出格式：

在一行中按照要求输出转换后的字符串。

输入样例：
Hello World! 123#
输出样例：
hELLO wORLD! 123


*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
main(int argc, char *argv[])
{
	char line[256];
	int i;

	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), stdin);

	i = 0;
	while (line[i] != '\0' && line[i] != '#') {
		if (islower(line[i]))
			printf("%c", toupper(line[i]));
		else if (isupper(line[i]))
			printf("%c", tolower(line[i]));
		else
			printf("%c", line[i]);
		++i;
	}
	printf("\n");

	return 0;
}





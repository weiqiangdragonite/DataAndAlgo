/*


中国大学MOOC-翁恺-C语言程序设计习题集


10-0. 说反话 (20)


给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和
若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，
输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello

*/

#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char line[256];
	int count, start, i, j;

	fgets(line, sizeof(line), stdin);

	/* include \n */
	count = strlen(line) - 1;
	line[count] = '\0';

	for (i = count - 1; i >= 0; --i) {
		/* find the last world */
		if (line[i] != ' ' && i != 0)
			continue;

		start = i;
		if (i)
			j = start + 1;
		else
			j = start;

		for (; line[j] != ' ' && line[j] != '\0'; ++j)
			printf("%c", line[j]);

		if ((line[j] == ' ' || line[j] == '\0') && i != 0)
			printf(" ");
	}
	printf("\n");

	return 0;
}





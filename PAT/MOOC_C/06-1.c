/*


中国大学MOOC-翁恺-C语言程序设计习题集


06-1. 简单计算器(20)


模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，4种运算符的优先级
相同，按从左到右的顺序计算。

输入格式：

输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。

输出格式：

在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。

输入样例：
1+2*10-10/2=
输出样例：
10


好吧，我错了，请看题目
4种运算符的优先级相同，按从左到右的顺序计算


*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>


static int
get_num(const char *line, int *index)
{
	int num, i;

	num = 0;
	i = *index;
	while (isdigit(line[i]))
		num = num * 10 + (line[i++] - '0');
	*index = i;

	return num;
}


int
main(int argc, char *argv[])
{
	char line[256];
	int i, num, res;
	char op;
	
	fgets(line, sizeof(line), stdin);
	/* remove the last '='
	because the last two character is: = \n  */
	line[strlen(line) - 2] = '\0';

	i = 0;
	if (isdigit(line[i]))
		res = get_num(line, &i);

	while (line[i]) {
		op = line[i++];

		if (isdigit(line[i]))
			num = get_num(line, &i);

		if (op == '+')
			res += num;
		else if (op == '-')
			res -= num;
		else if (op == '*')
			res *= num;
		else if (op == '/' && num != 0)
			res /= num;
		else {
			printf("ERROR\n");
			return 0;
		}
	}

	printf("%d\n", res);

	return 0;
}




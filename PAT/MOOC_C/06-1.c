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


参考 大话数据结构

Tips:
用逆波兰表示法（RPN），也叫后缀表达式
如 9+(3-1)*3+10/2 --> 9 3 1 - 3 * + 10 2 / +


中缀表达式(infix expression) 转 后缀表达式(postfix expression)
规则: 从左到右遍历中缀表达式的每个数字和符号，若是数字就输出，即成为后
缀表达式的一部分；若是符号，则判断其与栈顶符号的优先级，是右括号或优先级低
于前一个符号(乘除优先加减)则栈顶元素依次出栈并输出， 并将当前符号进栈，一直
到最终输出后缀表达式为止。


*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack {
	vo;
	unsigned int top;	/* the top of the stack */
};

struct stack array;

push(struct stack *s, void *item)
{
	/* stack is full */
	if (s->top == (s->size - 1))
		return -1;

	/* first time, top is 0 */
	++(s->top);
	//*(s->item) = item;
	//++(s->item);

	return 0;
}

#define GET_NUM()	{ num = 0; \
			while (isdigit(line[i])) \
				num = num * 10 + line[i++]; }

int
main(int argc, char *argv[])
{
	char line[256];
	int a, b, res;
	char op;
	int i;
	int num;

	//fgets(line, sizeof(line), stdin);

	i = 0;
	/* the first character is not a digit */
	if (!isdigit(line[i])) {
		printf("ERROR\n");
		return -1;
	}


	int size = 256;
	array.item = calloc(size, sizeof(void *));
	arrat.size = size;


	while (1) {
		num = get_num(line, &i);
		
		op = line[i];
		if (op == '+' || op == '-')
	}

	return 0;
}

static int
get_num(const char *line, int *index)
{
	int num, i;

	num = 0;
	i = *index;
	while (isdigit(line[i]))
		num = num * 10 + line[i++];
	*index = i;

	return num;
}

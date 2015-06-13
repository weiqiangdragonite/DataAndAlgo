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
#include <string.h>
#include <ctype.h>

/* -------------------------------------------------------------------------- */

#define STACK_SIZE 256

typedef int ElemType;

struct stack {
	ElemType data[STACK_SIZE];
	int top;	/* the top of the stack */
};
typedef struct stack stack_t;

/*
 *
 */
int
push(stack_t *stack, ElemType item)
{
	/* if full */
	if (stack->top == STACK_SIZE - 1)
		return 0;

	/* point to the next empty position */
	++stack->top;

	stack->data[stack->top] = item;

	return stack->top;
}

/*
 *
 */
int
pop(stack_t *stack, ElemType *item)
{
	/* if empty */ 
	if (stack->top == -1)
		return -1;

	*item = stack->data[stack->top--];

	return stack->top;
}

/* -------------------------------------------------------------------------- */


struct expression {
	int num;
	char op;
	unsigned char flag;	/* 0: char, 1: int */
};

static int get_num(const char *line, int *index);



int
main(int argc, char *argv[])
{
	char line[256];
	struct expression exp[256];
	char op, tmp_op;
	int i, j;
	int num;

	
	fgets(line, sizeof(line), stdin);
	/* remove the last '='
	because the last two character is: = \n  */
	line[strlen(line) - 2] = '\0';


	/* init seq stack */
	stack_t stack;
	memset(&stack, 0, sizeof(stack_t));
	stack.top = -1;


	i = 0;
	j = 1;	/* 不知是什么bug，如果从0开始存，最后时第0位数据变为0 */
	memset(exp, 0, sizeof(exp));

	/* covert to postfix expression */
	while (line[i]) {
		if (isdigit(line[i])) {
			num = get_num(line, &i);
			//printf("j = %d, num = %d\n", j, num);
			exp[j].flag = 1;
			exp[j++].num = num;
		}

		/* end */
		if (line[i] == '\0')
			break;

		op = line[i++];

		if (op != '+' && op != '-' && op != '*' && op != '/' &&
		op != '(' && op != ')') {
			printf("ERROR\n");
			return 0;
		}

		/* stack is empty, so just push op */
		if (stack.top == -1)
			push(&stack, (ElemType) op);

		/* if is ')', then pop until '(' */
		else if (op == ')') {
			while (1) {
				pop(&stack, (ElemType *) &tmp_op);
				if (tmp_op == '(')
					break;

				exp[j].flag = 0;
				exp[j++].op = tmp_op;
			}

		/* 判断优先级 低于/高于 栈顶符号 */
		} else if (op == '+' || op == '-') {
			tmp_op = (char) stack.data[stack.top];
			if (tmp_op == '*' || tmp_op == '/') {
				/* pop until find the '+' or '-' */
				while (1) {
					pop(&stack, (ElemType *) &tmp_op);

					exp[j].flag = 0;
					exp[j++].op = tmp_op;

					if (tmp_op == '+' || tmp_op == '-')
						break;
				}
			}
			push(&stack, (ElemType) op);
				
		/* op = * / ( */
		} else
			push(&stack, (ElemType) op);
	}

	/* pop all the op */
	while (stack.top != -1) {
		pop(&stack, (ElemType *) &tmp_op);
		exp[j].flag = 0;
		exp[j++].op = tmp_op;
	}

/*
	printf("postfix expression: ");
	for (i = 1; i <= j; ++i) {
		if (exp[i].flag)
			printf("%d ", exp[i].num);
		else
			printf("%c ", exp[i].op);
	}
	printf("\n");
*/


	/* compute the postfix expression */

	memset(&stack, 0, sizeof(stack_t));
	stack.top = -1;


	int a, b, res;
	a = b = res = 0;
	for (i = 1; i < j; ++i) {
		/* if number, push */
		if (exp[i].flag) {
			push(&stack, exp[i].num);
			continue;
		}

		/* else if op */
		/*
		a + b -> a b +
		a - b -> a b -
		a * b -> a b *
		a / b -> a b /
		*/
		op = exp[i].op;
		a = b = 0;
		/* pop two numbers and caculate it */
		pop(&stack, &b);
		pop(&stack, &a);

		if (op == '/' && b == 0) {
			printf("ERROR\n");
			return 0;
		} else if (op == '+')
			res = a + b;
		else if (op == '-')
			res = a - b;
		else if (op == '*')
			res = a * b;
		else if (op == '/')
			res = a / b;

		/* push */
		push(&stack, res);
	}

	/* the result is we want */

	/* after get the result, pop it */
	if (stack.top != 0) {
		printf("ERROR\n");
		return 0;
	}

	printf("%d\n", stack.data[0]);
	

	return 0;
}


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


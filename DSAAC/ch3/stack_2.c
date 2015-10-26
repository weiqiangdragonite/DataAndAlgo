/*
 * 中缀表达式 infix
 * 后缀表达式 postfix - 逆波兰记法reverse Polish
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



/******************************************************************************/

struct node {
	char data;
	struct node *next;
};

typedef struct node stack_t;
/* with header */

stack_t *
create_stack(void)
{
	stack_t *s;
	s = malloc(sizeof(stack_t));
	s->next = NULL;
	return s;
}

int
isempty(stack_t *s)
{
	return (s->next == NULL);
}

void
push(stack_t *s, char item)
{
	stack_t *ptr = malloc(sizeof(stack_t));

	ptr->data = item;
	ptr->next = s->next;
	s->next = ptr;
}

char
top(stack_t *s)
{
	if (isempty(s))
		return 0;
	return s->next->data;
}

void
pop(stack_t *s)
{
	if (isempty(s))
		return;

	stack_t *ptr = s->next;
	s->next = ptr->next;
	free(ptr);
}


/******************************************************************************/



/*
 * a + b * c + (d * e + f) * g
 * = a b c * + d e * f + g * +
 */
char *
infix2postfix(const char *exp)
{
	/* we need to check for the bad expression first, but this code is just
	 * a example, so we ignored and assume the expression is correct */
	if (exp == NULL)
		return NULL;

	stack_t *s = create_stack();
	char *output = malloc(strlen(exp) + 1);
	char tmp;
	int i = 0;

	/* the reality is more complex, a number may more than one character,
	 * but in this code, we assume a number is just one character */
	/* we just process '+ - * / ( )' */
	while (*exp != '\0') {
		printf("exp = %c\n", *exp);
		if (*exp == '+' || *exp == '-') {
			/* 弹出栈元素直到发现优先级更低的 */
			tmp = top(s);
			while (tmp && tmp != '(') {
				output[i++] = tmp;
				pop(s);
				tmp = top(s);
			}
			/* push this operator to stack */
			push(s, *exp);

		} else if (*exp == '*' || *exp == '/' || *exp == '(') {
			/* just push it */
			push(s, *exp);

		} else if (*exp == ')') {
			/* pop until find the '(' */
			tmp = top(s);
			while (tmp && tmp != '(') {
				output[i++] = tmp;
				pop(s);
				tmp = top(s);
			}
			/* now tmp == '(' */
			pop(s);

		} else {
			/* number */
			output[i++] = *exp;
		}

		exp++;
	}
	/* pop all */
	tmp = top(s);
	while (tmp) {
		output[i++] = tmp;
		pop(s);	
		tmp = top(s);
	}
	output[i] = '\0';

	return output;
}



int
calculate(const char *exp)
{
	stack_t *s = create_stack();
	int ret, a, b;
	char ch;

	while (*exp != '\0') {
		ch = *exp;
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			b = top(s) - '0';
			pop(s);
			a = top(s) - '0';
			pop(s);

			switch (ch) {
			case '+':
				ret = a + b;
				printf("%d + %d = %d\n", a, b, ret);
				break;
			case '-':
				ret = a - b;
				printf("%d - %d = %d\n", a, b, ret);
				break;
			case '*':
				ret = a * b;
				printf("%d * %d = %d\n", a, b, ret);
				break;
			case '/':
				ret = a / b;
				printf("%d / %d = %d\n", a, b, ret);
				break;
			}

			push(s, ret + '0');
		} else {
			push(s, ch);
		}

		++exp;
	}

	ret = top(s) - '0';
	pop(s);
	return ret;
}



int
main(void)
{
	char exp[] = "1+2*3+(4*5-6)/7";
	char *s;

	s = infix2postfix(exp);
	printf("s = %s\n", s);
	printf("ret = %d\n", calculate(s));
	free(s);

	return 0;
}










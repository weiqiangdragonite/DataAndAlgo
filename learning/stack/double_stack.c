/*
 * 两栈共享空间
 */

#include <stdio.h>
#include <string.h>


#define STACK_SIZE	1024

typedef int ElemType;


/*
 *
 */
struct double_stack {
	ElemType data[STACK_SIZE];
	int top1;
	int top2;
};

typedef struct double_stack stack_t;


void
init_stack(stack_t *stack)
{
	memset(stack, 0, sizeof(stack_t));
	stack->top1 = -1;
	stack->top2 = STACK_SIZE;
}

int
length(stack_t *stack, int stack_number)
{
	if (stack_number == 1)
		return stack->top1 + 1;
	else if (stack_number == 2)
		return STACK_SIZE - stack->top2;
	else
		return -1;
}


/*
 *
 */
int
push(stack_t *stack, ElemType item, int stack_number)
{
	/* if full */
	if (stack->top1 + 1 == stack->top2)
		return -1;

	if (stack_number == 1)
		stack->data[++stack->top1] = item;
	else if (stack_number == 2)
		stack->data[--stack->top2] = item;

	return 0;
}

/*
 *
 */
int
pop(stack_t *stack, ElemType *item, int stack_number)
{
	if (stack_number == 1) {
		/* if empty */ 
		if (stack->top1 == -1)
			return -1;

		*item = stack->data[stack->top1--];
	} else if (stack_number == 2) {
		if (stack->top2 == STACK_SIZE)
			return -1;
		*item = stack->data[stack->top2++];
	}

	return 0;
}


/******************************************************************************/


int
main(void)
{
	stack_t stack;
	int i, item;

	init_stack(&stack);

	for (i = 0; i < 5; ++i) {
		push(&stack, i, 1);
		push(&stack, i, 2);
	}
	printf("After push, stack 1 length = %d, stack 2 length = %d\n",
		length(&stack, 1), length(&stack, 2));

	while (pop(&stack, &item, 1) != -1)
		printf("head[%d] = %d\n", length(&stack, 1), item);
	while (pop(&stack, &item, 2) !=-1)
		printf("tail[%d] = %d\n", length(&stack, 2), item);

	return 0;
}





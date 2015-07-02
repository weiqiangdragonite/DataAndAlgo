/*
 * 顺序存储
 */

#include <stdio.h>
#include <string.h>



#define STACK_SIZE	1024

typedef int ElemType;


/*
 *
 */
struct stack {
	ElemType data[STACK_SIZE];
	int top;
};

typedef struct stack stack_t;




void
init_stack(stack_t *stack)
{
	memset(stack, 0, sizeof(stack_t));
	stack->top = -1;
}

int
length(stack_t *stack)
{
	return stack->top + 1;
}


/*
 *
 */
int
push(stack_t *stack, ElemType item)
{
	/* if full */
	if (stack->top == STACK_SIZE - 1)
		return -1;

	/* point to the next empty position */
	stack->data[++stack->top] = item;

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

	*item = stack->data[stack->top];

	return stack->top--;
}





/******************************************************************************/


int
main(void)
{
	stack_t stack;
	int item, i;

	init_stack(&stack);

	for (i = 0; i < 5; ++i)
		push(&stack, i);
	printf("After push, length = %d\n", length(&stack));

	pop(&stack, &item);
	printf("pop top item = %d\n", item);
	printf("After pop, length = %d\n", length(&stack));

	for (i = 0; i < 5; ++i)
		push(&stack, i + 10);
	printf("After push, length = %d\n", length(&stack));

	while ((pop(&stack, &item)) != -1)
		printf("item = %d\n", item);
	printf("After pop, length = %d\n", length(&stack));

	return 0;
}


/*
 *
 */

#include "seq_stack.h"


/*
 *
 */
int
push(stack_t *stack, ElemType *item)
{
	/* if full */
	if (stack->top == STACK_SIZE - 1)
		return -1;

	/* point to the next empty position */
	++stack->top;

	stack->data[stack->top] = *item;

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

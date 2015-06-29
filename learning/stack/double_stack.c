/*
 *
 */


#define STACK_SIZE	1024;

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






/*
 *
 */
int
push(stack_t *stack, ElemType item, int stack_number)
{
	/* if full */
	if (stack->top1 + 1 == stack->top2)
		return -1;

	/* point to the next empty position */
	++stack->top;

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
	} else if (stack_number == -2) {
		if (stack->top2 == STACK_SIZE - 1)
			return -1;
		*item = stack->data[stack->top2++];
	}

	return 0;
}


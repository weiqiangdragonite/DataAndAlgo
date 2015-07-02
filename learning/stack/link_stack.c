/*
 * 栈的链式存储
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


struct node {
	ElemType data;
	struct node *next;
};

struct link_stack {
	struct node *top;
	unsigned int count;
};

typedef struct link_stack link_stack_t;



void
init_stack(link_stack_t *stack)
{
	stack->top = NULL;
	stack->count = 0;
}


/*
 * 不需要头结点
 */
int
push(link_stack_t *stack, ElemType item)
{
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));

	ptr->next = stack->top;
	ptr->data = item;
	stack->top = ptr;
	++stack->count;

	return 0;
}

/*
 *
 */
int
pop(link_stack_t *stack, ElemType *item)
{
	/* if empty */
	if (stack->count == 0)
		return -1;

	struct node *ptr;
	ptr = stack->top;

	*item = ptr->data;
	stack->top = ptr->next;
	free(ptr);
	--stack->count;

	return 0;
}



/******************************************************************************/


int
main(void)
{
	link_stack_t stack;
	int i, item;

	init_stack(&stack);

	for (i = 0; i < 5; ++i)
		push(&stack, i);
	printf("After push, length = %d\n", stack.count);

	while (pop(&stack, &item) != -1)
		printf("[%d] = %d\n", stack.count, item);

	return 0;
}





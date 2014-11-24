/*
 *
 */

#include "stdlib.h"
#include "link_stack.h"

/*
 *
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
int pop(link_stack_t *stack, ElemType *item)
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

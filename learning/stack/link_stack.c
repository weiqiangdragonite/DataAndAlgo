/*
 *
 */


typedef int ElemType;


struct node {
	ElemType data;
	struct node *next;
};

struct link_stack {
	struct node *top;
	unsigned int count;
};

typedef link_stack link_stack_t;


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

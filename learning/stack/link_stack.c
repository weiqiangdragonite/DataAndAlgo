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


/*
 * 初始化栈
 */
void
init_stack(link_stack_t *stack)
{
	stack->top = NULL;
	stack->count = 0;
}


/*
 * 入栈：不需要头结点
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
 * 出栈：不需要头结点
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



/*******************************************************************************
* DSAAC
*******************************************************************************/

struct node {
	int data;
	struct node *next;
};

typedef struct node stack_t;


int
isempty(stack_t *stack)
{
	return (stack->next == NULL);
}

stack_t *
create_stack()
{
	stack_t *s;
	s = malloc(stack_t);
	s->next = NULL;
	make_empty(s);
	return s;
}

void
make_empty(stack_t *s)
{
	if (s == NULL)
		error();

	while (!isempty(s))
		pop(s);
}

void
push(stack_t *s, int x)
{
	stack_t *p = malloc(sizeof(stack_t));
	p->data = x;
	p->next = s->next;
	s->next = p;
}

int
top(stack_t *s)
{
	if (isempty(s))
		error

	return s->next->data;
}

void
pop(stack_t *s)
{
	if (isempty(s))
		error

	stack_t *ptr;

	ptr = s->next;
	s->next = s->next->next;
	free(ptr);
}












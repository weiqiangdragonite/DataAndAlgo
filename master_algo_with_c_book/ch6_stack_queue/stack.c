/*
 * stack.c
 * implementation of the stack abstract datatype
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"


/*
 * push the data onto the stack
 */
int
stack_push(Stack *stack, const void *data)
{
	return list_insert_next(stack, NULL, data);
}

/*
 * pop the data off the stack
 */
int
stack_pop(Stack *stack, void **data)
{
	return list_remove_next(stack, NULL, data);
}


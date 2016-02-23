/*
 * stack.h
 * header for the stack abstract datatype
 */

#ifndef STACK_H
#define STACK_H

#include "list.h"

/*
 * implement stack as linked list
 */
typedef List Stack;


/*
 * public interface
 */

/* void stack_init(Stack *stack, void (*destroy)(void *data)); */
#define stack_init		list_init

/* void stack_destroy(Stack *stack); */
#define stack_destroy		list_destroy

int stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack, void **data);

/* void *stack_peek(const Stack *stack); */
#define stack_peek(stack)	((stack)->head == NULL ? \
					NULL : (stack)->head->data)

/* int stack_size(const Stack *stack); */
#define stack_size		list_size


#endif




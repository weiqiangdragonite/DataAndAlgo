/*
 *
 */

#ifndef STACK_H
#define STACK_H


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

#endif	/* STACK_H */

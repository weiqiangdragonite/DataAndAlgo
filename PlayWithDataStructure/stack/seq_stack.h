/*
 *
 */

#ifndef STACK_H
#define STACK_H


#define STACK_SIZE	1024;

typedef int ElemType;


/*
 *
 */
struct stack {
	ElemType data[STACK_SIZE];
	int top;
};

typedef struct stack stack_t;



#endif	/* STACK_H */

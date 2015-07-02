/*
 *
 */
#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;


struct node {
	ElemType data;
	struct node *next;
};

struct link_queue {
	struct node *front;
	struct node *rear;
};

typedef struct link_queue link_queue_t;




void
init_queue(link_queue_t *q)
{
	q->front = NULL;
	q->rear = NULL;
}



/*
 * 不带头结点
 */
int
enter(link_queue_t *q, ElemType item)
{
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));

	ptr->next = NULL;
	ptr->data = item;


	if (q->front == NULL) {
		q->front = q->rear = ptr;
	} else {
		q->rear->next = ptr;
		q->rear = ptr;
	}

	return 0;
}

/*
 * 不带头结点
 */
int
delete(link_queue_t *q, ElemType *item)
{
	/* if empty */
	if (q->front == NULL)
		return -1;

	struct node *ptr;
	ptr = q->front;

	*item = ptr->data;
	q->front = ptr->next;

	/* delete the last item, rear point to head */
	if (q->rear == ptr)
		q->rear = q->front;
	free(ptr);

	return 0;
}


/******************************************************************************/


int
main(void)
{
	link_queue_t queue;
	int i, item;

	init_queue(&queue);
	for (i = 0; i < 5; ++i)
		enter(&queue, i);

	while (delete(&queue, &item) != -1)
		printf("q = %d\n", item);

	return 0;
}





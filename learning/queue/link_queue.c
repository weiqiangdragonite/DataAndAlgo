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



/*
 * 初始化队列
 */
void
init_queue(link_queue_t *q)
{
	q->front = NULL;
	q->rear = NULL;
}



/*
 * 入队：不带头结点
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
 * 出对：不带头结点
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

	/* after delete the last item, rear point to head */
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


/******************************************************************************/

struct node {
	int data;
	struct node *front;
	struct node *rear;
	struct node *next;
};


/* with headr */
queue_t *
create_queue(void)
{
	queue_t *q;
	q = malloc(sizeof(queue_t));

	q->front = q->rear = q->next = NULL;
}

int
isempty(queue_t *q)
{
	return (q->front == NULL);
}

void
enqueue(queue_t *q, int item)
{
	queue_t *ptr = malloc(sizeof(queue_t));

	ptr->data = item;
	ptr->front = ptr->rear = ptr->next = NULL;

	if (isempty(q))
		q->front = ptr;
	else
		q->rear->next = ptr;
	q->rear = ptr;
}

void
dequeue(queue_t *q)
{
	if (isempty(q))
		error();

	queue_t *ptr = q->front;

	q->front = q->front->next;
	free(ptr);
}





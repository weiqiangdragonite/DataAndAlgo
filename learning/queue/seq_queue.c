/*
 * 循环队列 - 只能存储n-1个元素
 */
#include <stdio.h>
#include <string.h>


#define QUEUE_SIZE	5

typedef int ElemType;


/*
 *
 */
struct queue {
	ElemType data[QUEUE_SIZE];
	int front;
	int rear;
};

typedef struct queue queue_t;



/*
 * not need
 */
void
init_queue(queue_t *queue)
{
	memset(queue, 0, sizeof(queue_t));
	queue->front = 0;
	queue->rear = 0;
}


int
length(queue_t *q)
{
	return (q->rear - q->front + QUEUE_SIZE) % QUEUE_SIZE;
}


/*
 *
 */
int
enter(queue_t *q, ElemType item)
{
	/* if full */
	if ((q->rear + 1) % QUEUE_SIZE == q->front)
		return -1;

	q->data[q->rear] = item;
	q->rear = (q->rear + 1) % QUEUE_SIZE;

	return 0;
}

/*
 *
 */
int
delete(queue_t *q, ElemType *item)
{
	/* if empty */ 
	if (q->front == q->rear)
		return -1;

	*item = q->data[q->front];
	q->front = (q->front + 1) % QUEUE_SIZE;

	return 0;
}


/******************************************************************************/


int
main(void)
{
	queue_t queue;
	int i, item;

	init_queue(&queue);

	for (i = 0; i < 10; ++i)
		enter(&queue, i);
	printf("after enter, length = %d\n", length(&queue));

	while (delete(&queue, &item) != -1)
		printf("q = %d\n", item);

	return 0;
}


/******************************************************************************/

struct node {
	int capacity;
	int front;
	int rear;
	int size;
	int *array;
};

typedef struct node queue_t;

queue_t *
create_queue(int size)
{
	queue_t *q;

	q = malloc(sizeof(queue_t));
	q->capacity = size;
	q->array = malloc(sizeof(int) * size);
	make_empty(q);
}

int
isempty(queue_t *q)
{
	return (q->size == 0);
}

voif
make_empty(queue_t *q)
{
	q->size = 0;
	q->front = 1;
	q->rear = 0;
}

int
isfull(queue_t *q)
{
	return (q->size == q->capacity);
}

int
succ(queue_t *q, int value)
{
	if (++value == q->capacity)
		return 0;
	return value;
}

void
enqueue(queue_t *q, int item)
{
	if (isfull(q))
		error;
	else {
		q->size++;
		q->rear = succ(q, q->rear);
		q->array[q->rear] = item;
	}
}

int
dequeue(queue_t *q)
{
	int tmp;
	if (isempty(q))
		error;
	else {
		q->size--;
		tmp = q->array[q->front];
		q->front = succ(q, q->front);
	}
	return tmp;
}





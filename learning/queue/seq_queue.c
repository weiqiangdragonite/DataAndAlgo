/*
 *
 */


#define QUEUE_SIZE	1024;

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
	queue->front = 0;
	queue->rear = 0;
}

int
queue_length(queue_t *q)
{
	return (q->rear - q->front + QUEUE_SIZE) % QUEUE_SIZE
}


/*
 *
 */
int
enter(queue_t *q, ElemType item)
{
	/* if full */
	if (q->rear + 1 == q->front)
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


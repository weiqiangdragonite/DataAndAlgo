/*
 *
 */


typedef int ElemType;


struct node {
	ElemType data;
	struct node *next;
};

struct link_queue {
	struct node *front;
	struct node *rear;
};

typedef link_queue link_queue_t;


/*
 *
 */
int
enter(link_queue_t *q, ElemType item)
{
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));

	ptr->next = NULL;
	ptr->data = item;

	q->rear->next = ptr;
	q->rear = ptr;

	return 0;
}

/*
 *
 */
int
delete(link_queue_t *q, ElemType *item)
{
	/* if empty */
	if (q->rear == q->front)
		return -1;

	struct node *ptr;
	ptr = q->front->next;

	*item = ptr->data;
	q->front->next = ptr->next;

	/*  */
	if (q->rear == ptr)
		q->rear = q->front;
	free(ptr);

	return 0;
}

/*
 * queue.c
 * implementation of the queue abstract datatype
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "queue.h"


/*
 * enqueue the data
 */
int
queue_enqueue(Queue *queue, const void *data)
{
	return list_insert_next(queue, list_tail(queue), data);
}

/*
 * dequeue the data
 */
int
queue_dequeue(Queue *queue, void **data)
{
	return list_remove_next(queue, NULL, data);
}


/*
 * queue.h
 * header for the queue abstract datatype
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

/*
 * implement queue as linked list
 */
typedef List Queue;


/*
 * public interface
 */

/* void queue(Queue *queue, void (*destroy)(void *data)); */
#define queue_init		list_init

/* void queue_destroy(Queue *queue); */
#define queue_destroy		list_destroy

int queue_enqueue(Queue *queue, const void *data);

int queue_dequeue(Queue *queue, void **data);

/* void *queue_peek(const Queue *queue); */
#define queue_peek(queue)	((queue)->head == NULL ? \
					NULL : (queue)->head->data)

/* int queue_size(const Queue *queue); */
#define queue_size		list_size


#endif




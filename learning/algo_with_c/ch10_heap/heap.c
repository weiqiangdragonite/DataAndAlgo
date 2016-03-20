/*
 * implementation of the heap abstract datatype
 */

#include <stdlib.h>
#include <string.h>

#include "heap.h"


/* define private macros used by the heap implementation */
#define heap_parent(npos)	((int)(((npos) - 1) / 2))
#define heap_left(npos)		(((npos) * 2) + 1)
#define heap_right(npos)	(((npos) * 2) + 2)



void
heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2),
	void (*destroy)(void *data))
{
	heap->size = 0;
	heap->compare = compare;
	heap->destroy = destroy;
	heap->tree = NULL;
}

void
heap_destroy(Heap *heap)
{
	int i;
	/* remove all the nodes form the heap */
	if (heap->destroy != NULL) {
		for (i = 0; i < heap_size(heap); ++i)
			heap->destroy(heap->tree[i]);
	}

	free(heap->tree);
	memset(heap, 0, sizeof(Heap));
}


int
heap_insert(Heap *heap, const void *data)
{
	void *temp;
	int ipos, ppos;

	/* allocate storage for the node */
	if ((temp = (void **) realloc(heap->tree, (heap_size(heap) + 1) * sizeof(void *))) == NULL)
		return -1;
	else
		heap->tree = temp;

	/* insert the node after the last node */
	heap->tree[heap_size(heap)] = (void *) data;

	/* heapify the tree by pushing the contents of the now node upward */
	ipos = heap_size(heap);
	ppos = heap_parent(ipos);

	/* new node bigger than parent, upward */
	while (ipos > 0 && heap->compare(heap->tree[ppos], heap->tree[ipos]) < 0) {
		/* swap the contents of the current node and its parent */
		temp = heap->tree[ppos];
		heap->tree[ppos] = heap->tree[ipos];
		heap->tree[ipos] = temp;

		/* move up one level in the tree to cintinue heapifying */
		ipos = ppos;
		ppos = heap_parent(ipos);
	}

	/* adjust the size of the heap to account for the inserted node */
	++heap->size;
	return 0;
}

int
heap_extract(Heap *heap, void **data)
{
	void *save, *temp;
	int ipos, lpos, rpos, mpos;

	/* do noet allow extraction from an empty heap */
	if (heap_size(heap) == 0)
		return -1;

	/* extract the node at the top of the heap */
	*data = heap->tree[0];

	/* adjust the storage used by the heap */
	save = heap->tree[heap_size(heap) - 1];

	if (heap_size(heap) - 1 > 0) {
		if ((temp = (void **) realloc(heap->tree, (heap_size(heap) - 1) * sizeof(void *))) == NULL)
			return -1;
		else
			heap->tree = temp;

		/* adjust the size */
		--heap->size;
	} else {
		/* manage the heap when extracting the last node */
		free(heap->tree);
		heap->tree = NULL;
		heap->size = 0;
		return 0;
	}

	/* copy the last node to the top */
	heap->tree[0] = save;

	/* heapify the tree by pushing the contents of the new top downward */
	ipos = 0;

	while (1) {
		/* select the child to swap with the current node */
		lpos = heap_left(ipos);
		rpos = heap_right(ipos);

		/* left child bigger than parent */
		if (lpos < heap_size(heap) && heap->compare(heap->tree[lpos], heap->tree[ipos]) > 0)
			mpos = lpos;
		/* parent bigger than left child */
		else
			mpos = ipos;

		if (rpos < heap_size(heap) && heap->compare(heap->tree[rpos], heap->tree[mpos]) > 0)
			mpos = rpos;

		/* when mpos is ipos, the heap property has been restored */
		if (mpos == ipos)
			break;
		else {
			/* swap the contents of the current node and the selected child */
			temp = heap->tree[mpos];
			heap->tree[mpos] = heap->tree[ipos];
			heap->tree[ipos] = temp;

			/* move down one leven in the tree to continue heapifying */
			ipos = mpos;
		}
	}

	return 0;
}




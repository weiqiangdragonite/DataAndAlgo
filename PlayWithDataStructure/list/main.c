/*
 *
 */

#include <stdio.h>

#include "seq_list.h"

int
main(int argc, char *argv[])
{
	seq_list_t list;
	int i;
	int item;

	/* 10 element */
	init_seq_list(&list);
	printf("seq length = %d\n", seq_list_length(&list));

	for (i = 0; i < 10; ++i)
		insert_seq_list(&list, i+1, i);

	printf("After insert:\n");
	for (i = 0; i < list.length; ++i) {
		get_seq_list(&list, i+1, &item);
		printf("[%d] %d\n", i+1, item);
	}

	insert_seq_list(&list, 5, 100);
	printf("Insert 100 at 5, after insert:\n");
	for (i = 0; i < list.length; ++i) {
		get_seq_list(&list, i+1, &item);
		printf("[%d] %d\n", i+1, item);
	}

	printf("Find 7 in list, pos = %d\n", find_seq_list(&list, 7));

	delete_seq_list(&list, 5, NULL);
	printf("Delete 100 at 5, after delete:\n");
	for (i = 0; i < list.length; ++i) {
		get_seq_list(&list, i+1, &item);
		printf("[%d] %d\n", i+1, item);
	}

	free_seq_list(&list);
	printf("After free list, length = %d\n", list.length);

	return 0;
}


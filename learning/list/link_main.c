/*
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int
main(int argc, char *argv[])
{
	int i;
	int item;

	link_list_t list;
	init_link_list(&list);

	for (i = 0; i < 10; ++i)
		insert_link_list(&list, i+1, i);


	printf("After insert\n");
	for (i = 0; i < 10; ++i) {
		get_link_list(&list, i+1, &item);
		printf("[%d] %d\n", i+1, item);
	}

	delete_link_list(&list, 5, NULL);
	printf("After delete\n");
	for (i = 0; i < 9; ++i) {
		get_link_list(&list, i+1, &item);
		printf("[%d] %d\n", i+1, item);
	}

	free_link_list(&list);

	return 0;

}


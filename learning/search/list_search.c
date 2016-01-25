/*
 * 用无序链表实现查找表
 * just a simple example
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef char Key;
typedef int Value;

struct node {
	Key k;
	Value v;
	struct node *next;
};

typedef struct node ST;





void
put(ST **list, Key k, Value v)
{
	ST *st = *list;
	/* find the key */
	/* insert at the head if key not found */
	/* otherwise update the value */
	while (st != NULL) {
		if (st->k == k) {
			st->v = v;
			return;
		}
		st = st->next;
	}
	ST *ptr = malloc(sizeof(ST));
	ptr->k = k;
	ptr->v = v;
	ptr->next = *list;
	*list = ptr;
}

Value
get(ST *list, Key k)
{
	ST *st = list;
	while (st != NULL)  {
		if (st->k == k)
			return st->v;
		st = st->next;
	}
	return -1;
}

void
delete(ST **list, Key k)
{
	ST *st = *list;
	ST *old_st = st;

	while (st != NULL ) {
		if (st->k == k) {
			old_st->next = st->next;
			free(st);
			return;
		}

		old_st = st;
		st = st->next;
	}
}

void
delete_all(ST **list)
{
	ST *st = *list;
	ST *old_st = NULL;
	while (st != NULL) {
		old_st = st->next;
		free(st);
		st = old_st;
	}
	*list = NULL;
}

void
print(ST *list)
{
	ST *st = list;
	while (st != NULL) {
		printf("[%c - %d]", st->k, st->v);
		if (st->next != NULL)
			printf("->");
		st = st->next;
	}
	printf("\n");
}




int
main(void)
{
	ST *st = NULL;

	put(&st, 'S', 0);
	print(st);

	put(&st, 'E', 1);
	print(st);

	put(&st, 'A', 2);
	print(st);

	put(&st, 'R', 3);
	print(st);

	put(&st, 'C', 4);
	print(st);

	put(&st, 'H', 5);
	print(st);

	put(&st, 'E', 6);
	print(st);

	put(&st, 'X', 7);
	print(st);

	put(&st, 'A', 8);
	print(st);

	put(&st, 'M', 9);
	print(st);

	put(&st, 'P', 10);
	print(st);

	put(&st, 'L', 11);
	print(st);

	put(&st, 'E', 12);
	print(st);

	delete(&st, 'M');
	print(st);

	delete_all(&st);
	print(st);

	return 0;
}




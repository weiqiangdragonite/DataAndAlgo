/*
 * chapter 2, 游标实现法
 */


struct node {
	int data;
	int next;
};

struct node CursorSpace[SPACE_SIZE];



void
init()
{
	for (i = 0; i < SPACE_SIZE;)
		CursorSpace[i].next = i++;
	CursorSpace[i - 1] = 0;	/* the last is NULL */
}


int
cursor_alloc()
{
	int pos;
	pos = CursorSpace[0].next;
	CursorSpace[0].next = CursorSpace[pos].next;

	return pos;
}


void
cursor_free(int pos)
{
	CursorSpace[pos].Next = CursorSpace[0].next;
	CursorSpace[0].next = pos;
}


int
isempty(list_t list)
{
	return (CursorSpace[list].next == 0);
}

int
islast(int pos)
{
	return (CursorSpace[pos].next == 0);
}


int
find(list_t list, int item)
{
	int pos;

	pos = CursorSpace[list].next;
	while (pos && CursorSpace[pos].data != item)
		pos = CursorSpace[pos].next;

	return pos;
}

int
find_previous(list_t list, int item)
{
	int p1, p2;

	p1 = CursorSpace[list].next;
	p2 = p1;

	while (p1 && CursorSpace[p1].data != item) {
		p2 = p1;
		p1 = CursorSpace[p1].next;
	}

	return p2;
}

void
delete(list_t list, int item)
{
	int pos, tmp;

	pos = find_previous(list, item);

	if (islast(pos) != 0) {
		tmp = CursorSpace[pos].next;
		CursorSpace[pos].next = CursorSpace[tmp].next;
		cursor_free(tmp);
	}
}


/*
 * insert after legal position: pos
 */
void
insert(int item, int pos)
{
	int tmp;

	tmp = cursor_alloc();
	if (tmp == 0)
		fprintf(stderr, "Out of space\n");

	CursorSpace[tmp].data = item;
	CursorSpace[tmp].next = CursorSpace[pos].next;
	CursorSpace[pos].next = tmp;
}




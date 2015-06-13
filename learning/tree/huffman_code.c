/*
 * Huffman Code
 */

#include <stdio.h>
#include <stdlib.h>

/* 哈夫曼树结点 */
struct huffman_node {
	char data;
	int weight;
	struct huffman_node *lchild;
	struct huffman_node *rchild;
};

/* 哈夫曼树结点链表 */
struct huffman_list {
	struct huffman_node *tree;
	struct huffman_list *next;
};

struct huffman_table {
	char data;
	char code[30];
};

struct huffman_table hash[26];


/*
 * 从小到大插入，相等的按先到的排前
 */
void
insert_into_list(struct huffman_list **list, struct huffman_list *node)
{
	/* 链表为空 */
	if (*list == NULL) {
		*list = node;
		return;
	}

	struct huffman_list *ptr, *oldptr;

	ptr = oldptr = *list;

	while (ptr) {
		if (ptr->tree->weight > node->tree->weight)
			break;
		oldptr = ptr;
		ptr = ptr->next;
	}

	/* 插尾 */
	if (ptr == NULL) {
		oldptr->next = node;
	/* 插头 */
	} else if (ptr == *list) {
		node->next = *list;
		*list = node;
	/* 插中间 */
	} else {
		node->next = oldptr->next;
		oldptr->next = node;
	}
}

/*
 * pop the first item form list
 */
struct huffman_node *
pop_from_list(struct huffman_list **list, int *counter)
{
	if (*list == NULL)
		return NULL;

	struct huffman_list *ptr;
	ptr = *list;

	*list = ptr->next;
	ptr->next = NULL;

	--*counter;

	return ptr->tree;
}


/*
 * 构造哈夫曼树，从有序的集合(按权值从大到小排)，选取两颗权值最小的树构造一颗
 * 新的二叉树，删除集合中的那两颗树，把新树放进集合中，重复步骤，直到剩下一颗树
 */
void
create_huffman_tree(struct huffman_list **list, int *counter)
{
	if (*counter <= 1)
		return;

	struct huffman_node *lchild, *rchild;
	lchild = pop_from_list(&(*list), counter);
	rchild = pop_from_list(&(*list), counter);

	/* create new huffman node */
	struct huffman_node *tree;
	tree = (struct huffman_node *) malloc(sizeof(struct huffman_node));
	if (tree == NULL) {
		fprintf(stderr, "malloc() huffman_node failed\n");
		return;
	}

	tree->data = 0;
	tree->weight = lchild->weight + rchild->weight;
	//printf("new tree weight = %d\n", tree->weight);
	tree->lchild = lchild;
	tree->rchild = rchild;
	//rintf("lchild.weight = %d\n", tree->lchild->weight);
	//printf("rchild.weight = %d\n", tree->rchild->weight);

	struct huffman_list *ptr;
	ptr = (struct huffman_list *) malloc(sizeof(struct huffman_list));
	if (ptr == NULL) {
		fprintf(stderr, "malloc() huffman_list failed\n");
		return;
	}
	ptr->tree = tree;
	ptr->next = NULL;

	insert_into_list(&(*list), ptr);
	++*counter;

	create_huffman_tree(&(*list), counter);
}

/*
 * 输入结点的值和权值
 * 假如有A,B,C,D,E五个字符，出现的频率（即权值）分别为5,4,3,2,1,
 * 则依次输入: A5B4C3D2E1#
 */
int
init_huffman_list(struct huffman_list **list)
{
	char ch;
	int num, counter;

	counter = 0;
	while (1) {
		scanf("%c", &ch);

		if (ch == '#')
			break;
		else
			scanf("%d", &num);

		struct huffman_node *tree;
		tree = (struct huffman_node *) malloc(sizeof(struct huffman_node));
		if (tree == NULL) {
			fprintf(stderr, "malloc() huffman_node failed\n");
			return -1;
		}

		tree->data = ch;
		tree->weight = num;
		tree->lchild = NULL;
		tree->rchild = NULL;

		struct huffman_list *ptr;
		ptr = (struct huffman_list *) malloc(sizeof(struct huffman_list));
		if (ptr == NULL) {
			fprintf(stderr, "malloc() huffman_list failed\n");
			return -1;
		}
		ptr->tree = tree;
		ptr->next = NULL;

		insert_into_list(&(*list), ptr);
		++counter;
	}

	return counter;
}


/*
 * 中序遍历：先遍历左子树，然后显示结点数据，再遍历右子树
 */
void
in_order_traverse(struct huffman_node *tree)
{
	/* 树的最大深度，也是哈夫曼编码的最大长度，自己设定 */
	static char path[10];
	/* 树的深度从1开始，根在第一层 */
	static int deep = 1;

	if (tree == NULL)
		return;

	/* traverse left tree */
	if (tree->lchild != NULL) {
		path[deep++] = '0';
		in_order_traverse(tree->lchild);
	}

	/* 显示结点路径 */
	if (tree->data != 0) {
		int i;
		int num = tree->data - 'A';
		for (i = 1; i < deep; ++i) {
			printf("%c", path[i]);
			hash[num].code[i - 1] = path[i];
		}
		hash[num].data = tree->data;
		printf(" --> %c\n", tree->data);
	/* 返回上一层 */
	} else {
		--deep;
	}

	/* traverse right tree */
	if (tree->rchild != NULL) {
		path[deep++] = '1';
		in_order_traverse(tree->rchild);
	}
	if (tree->data == 0)
		--deep;
}

/*
 *
 */
void
huffman_encode(char *str)
{
	char ch;

	printf("\nstring = %s, after encode = ", str);
	while (1) {
		ch = *str;
		if (ch == '\0')
			break;
		printf("%s", hash[ch - 'A'].code);
		++str;
	}
	printf("\n");
}

/*
 *
 */
void
huffman_decode(struct huffman_node *tree, const char const *str)
{
	static int pos = 0;
	static int deep = 0;
	static char end = 0;

	if (*(str + pos) == '0' && tree->lchild != NULL) {
		++deep;
		printf("%c", *(str + pos));
		++pos;
		huffman_decode(tree->lchild, str);
		//printf("return lchild: deep = %d, pos = %d\n", deep, pos);
		--deep;
	} else if (*(str + pos) == '1' && tree->rchild != NULL) {
		++deep;
		printf("%c", *(str + pos));
		++pos;
		huffman_decode(tree->rchild, str);
		//printf("return rchild: deep = %d, pos = %d\n", deep, pos);
		--deep;
	} else {
		++deep;
		printf(" --> %c\n", tree->data);
		--deep;

		if (*(str + pos) == '\0')
			end = 1;
		return;
	}

	if (deep != 0) {
		//printf("deep = %d, pos = %d\n", deep, pos);
		return;
	}
	//printf("deep = %d, pos = %d\n", deep, pos);

	if (end != 1)
		huffman_decode(tree, str);
}



int
main(int argc, char *argv[])
{
	struct huffman_list *list;
	int counter;

	list = NULL;

	printf("Please enter tree\n>>> ");
	counter = init_huffman_list(&list);
	printf("\n");

	if (list == NULL)
		fprintf(stderr, "list is null\n");
	else
		printf("list is not null, counter = %d\n", counter);


	printf("before create huffman tree\n");
	struct huffman_list *ptr;
	ptr = list;
	while (ptr) {
		printf("data = %c, weight = %d\n", ptr->tree->data, ptr->tree->weight);
		ptr = ptr->next;
	}

	create_huffman_tree(&list, &counter);
	printf("after create huffman tree\n");

	ptr = list;
	while (ptr) {
		printf("data = %c, weight = %d\n", ptr->tree->data, ptr->tree->weight);
		ptr = ptr->next;
	}

	printf("huffman code:\n");
	in_order_traverse(list->tree);
	printf("\n");

	printf("huffman hash table:\n");
	int i;
	for (i = 0; i < 26; ++i) {
		if (hash[i].data == 0)
			continue;
		printf("%c : %s\n", hash[i].data, hash[i].code);
	}

	char *str = "AAABBCCDDEE";
	huffman_encode(str);

	printf("after decode:\n");
	huffman_decode(list->tree, "11111110100000011011010010");
	printf("\n");

	return 0;
}


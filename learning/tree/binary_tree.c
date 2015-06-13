/*
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct binary_tree {
	char data;
	struct binary_tree *lchild;
	struct binary_tree *rchild;
};

/* 栈 */
struct stack {
	void *node;
	struct stack *next;
};

/* 如果是空栈，返回1 */
int
is_stack_empty(struct stack **top)
{
	return *top == NULL ? 1 : 0;
}

/* 入栈 */
void
push(struct stack **top, struct binary_tree *node)
{
	struct stack *ptr = (struct stack *) malloc(sizeof(struct stack));
	ptr->node = (void *) node;
	ptr->next = *top;

	*top = ptr;
	//printf("push -> %c\n", ((struct binary_tree *) (*top)->node)->data);
}

/* 出栈 */
void
pop(struct stack **top, struct binary_tree **node)
{
	struct stack *ptr = *top;

	*node = (struct binary_tree *) (*top)->node;
	*top = (*top)->next;

	free(ptr);

	//printf("pop -> %c\n", (*node)->data);
}




/*
 * 前序遍历：先显示结点数据，然后遍历左子树，再遍历右子树
 */
void
pre_order_traverse(struct binary_tree *tree)
{
	if (tree == NULL)
		return;

	/* show the node data */
	printf("%c", tree->data);
	/* traverse left tree */
	pre_order_traverse(tree->lchild);
	/* traverse right tree */
	pre_order_traverse(tree->rchild);
}

/*
 * 中序遍历：先遍历左子树，然后显示结点数据，再遍历右子树
 */
void
in_order_traverse(struct binary_tree *tree)
{
	if (tree == NULL)
		return;

	/* traverse left tree */
	in_order_traverse(tree->lchild);
	/* show the node data */
	printf("%c", tree->data);
	/* traverse right tree */
	in_order_traverse(tree->rchild);
}

/*
 * 中序遍历的非递归调用
 */
void
in_order_traverse_v2(struct binary_tree *tree)
{
	struct binary_tree *ptr;
	struct binary_tree *node;
	struct stack *top;

	ptr = tree;
	top = NULL;

	// 当结点不为空，或栈不为空
	while (ptr != NULL || !is_stack_empty(&top)) {
		if (ptr != NULL) {
			// 结点入栈
			push(&top, ptr);
			// 进入结点的左子树
			ptr = ptr->lchild;
		} else {
			node = NULL;
			// 取出结点
			pop(&top, &node);
			printf("%c", node->data);
			// 进入结点的右子树
			ptr = node->rchild;
		}
	}
}

/*
 * 后序遍历：先遍历左子树，然后遍历右子树，最后显示结点数据
 */
void
post_order_traverse(struct binary_tree *tree)
{
	if (tree == NULL)
		return;

	/* traverse left tree */
	post_order_traverse(tree->lchild);
	/* traverse right tree */
	post_order_traverse(tree->rchild);
	/* show the node data */
	printf("%c", tree->data);
}

/*
 * 按前序输入方式构造二叉树
 * 注意是指向指针的指针
 * ABDH##I##E##CF##G##
 */
void
create_binary_tree(struct binary_tree **tree)
{
	char ch;
	scanf("%c", &ch);

	if (ch == '#') {
		*tree = NULL;
	} else {
		*tree = (struct binary_tree *) malloc(sizeof(struct binary_tree));
		if (*tree == NULL) {
			fprintf(stderr, "malloc() failed\n");
			return;
		}
		(*tree)->data = ch;

		create_binary_tree(&((*tree)->lchild));
		create_binary_tree(&((*tree)->rchild));
	}
}


int
main(int argc, char *argv[])
{
	struct binary_tree *tree;

	tree = NULL;
	printf("Enter binary tree\n");
	create_binary_tree(&tree);
	printf("\n");

	if (tree == NULL)
		fprintf(stderr, "tree is null\n");

	printf("pre order traverse: ");
	pre_order_traverse(tree);

	printf("\nin order traverse: ");
	in_order_traverse(tree);
	printf("\nin order traverse v2: ");
	in_order_traverse_v2(tree);

	printf("\npost order traverse: ");
	post_order_traverse(tree);

	printf("\n");

	return 0;
}




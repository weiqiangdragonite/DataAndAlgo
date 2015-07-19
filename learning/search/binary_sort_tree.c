/*
 * 二叉排序树
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct bst {
	int data;
	struct bst *lchild;
	struct bst *rchild;
};


/*
 * 递归查找二叉排序树中是否存在key
 * 若查找成功，指针p指向该结点，并返回0，
 * 否则指针p指向访问的最后一个结点，并返回-1
 */
int
search_bst(struct bst *tree, int key, struct bst *node, struct bst **ptr)
{
	if (tree == NULL) {
		/* 查找不成功 */
		*ptr = node;
		return -1;
	} else if (key < tree->data) {
		/* 往左子树查找 */
		return search_bst(tree->lchild, key, tree, ptr);
	} else if (key > tree->data) {
		/* 往右子树查找 */
		return search_bst(tree->rchild, key, tree, ptr);
	} else {
		/* key == tree->data */
		*ptr = tree;
		return 0;
	} 
}


/*
 *
 */
int
insert_bst(struct bst **tree, int item)
{
	struct bst *ptr = NULL;
	struct bst *node = NULL;

	/* 查找不成功，进行插入 */
	if (search_bst(*tree, item, NULL, &ptr) != 0) {
		node = (struct bst *) malloc(sizeof(struct bst));
		node->data = item;
		node->lchild = node->rchild = NULL;

		/* 插入为新的根结点 */
		if (ptr == NULL)
			*tree = node;

		/* 插入为左孩子 */
		else if (item < ptr->data)
			ptr->lchild = node;

		/* 插入为右孩子 */
		else if (item > ptr->data)
			ptr->rchild = node;

		return 0;
	}
	/* 元素已存在树中 */
	return -1;
}



/*
 * 递归
 * 中序遍历：先遍历左子树，然后显示结点数据，再遍历右子树
 */
void
in_order_traverse(struct bst *tree)
{
	if (tree == NULL)
		return;

	/* traverse left tree */
	in_order_traverse(tree->lchild);
	/* show the node data */
	printf("[%i]", tree->data);
	/* traverse right tree */
	in_order_traverse(tree->rchild);
}


int
main(int argc, char *argv[])
{
	int i;
	int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
	struct bst *tree = NULL;
	for (i = 0; i < 10; ++i)
		insert_bst(&tree, a[i]);

	in_order_traverse(tree);
	printf("\nAfter insert:\n");

	insert_bst(&tree, 71);
	in_order_traverse(tree);
	printf("\n");

	return 0;
}











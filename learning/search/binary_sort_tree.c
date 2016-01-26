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
 * 查找效率决定于树的高度
 * 平均 O(logN)
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
 * 非递归
 */
int
search_bst_v2(struct bst *tree, int key, struct bst *node, struct bst **ptr)
{
	while (tree) {
		if (key < tree->data)
			tree = tree->lchild;
		else if (key > tree->data)
			tree = tree->rchild;
		else if (key == tree->data) {
			*ptr = tree;
			return 0;
		}
	}
	*ptr = node;
	return -1;
}

/*
 * 递归查找最小元素
 */
struct bst *
find_min(struct bst *tree)
{
	if (tree == NULL)
		return NULL;
	else if (tree->lchild == NULL)
		return tree;
	else
		return find_min(tree->lchild);
}

/*
 * 迭代查找最大元素
 */
struct bst *
find_max(struct bst *tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->rchild) {
		tree = tree->rchild;
	}
	return tree;
}




/*
 * 插入元素
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
 * 对当前结点进行删除操作，由delete_bst()调用
 */
int
delete(struct bst **tree)
{
	struct bst *ptr;
	struct bst *s;

	printf("delete(): data = %d\n", (*tree)->data);


	/* 删除的是叶子节点 或 右子树为空，将左子树接过来 */
	if ((*tree)->rchild == NULL) {
		ptr = *tree,
		*tree = (*tree)->lchild;
		free(ptr);

	/* 左子树为空，将右子树接过来 */
	} else if ((*tree)->lchild == NULL) {
		ptr = *tree;
		*tree = (*tree)->rchild;
		free(ptr);

	/* 左右子树均不为空 */
	} else {
		ptr = *tree;
		s = (*tree)->lchild;
		/* 寻找删除结点的前驱 */
		while (s->rchild) {
			ptr = s;
			s = s->rchild;
		}
		/* 用前驱结点替换 */
		(*tree)->data = s->data;

		if (ptr != *tree)	/* 重接为ptr的右子树 */
			ptr->rchild = s->lchild;
		else	/* 重接为ptr的左子树 */
			ptr->lchild = s->lchild;
		free(s);
	}
	return 0;
}

/*
 * 删除结点(递归)：
 * 叶子结点、
 * 仅有左或右子树的结点、
 * 左右子树都有结点
 */
int
delete_bst(struct bst **tree, int key)
{
	if (*tree != NULL) {
		/* 找到关键字 */
		if (key == (*tree)->data)
			return delete(tree);
		else if (key < (*tree)->data)
			return delete_bst(&(*tree)->lchild, key);
		else if (key > (*tree)->data)
			return delete_bst(&(*tree)->rchild, key);
	}

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
	//int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
	int a[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
	int n = sizeof(a) / sizeof(int);
	struct bst *tree = NULL;
	for (i = 0; i < n; ++i)
		insert_bst(&tree, a[i]);

	in_order_traverse(tree);
	//printf("\nAfter insert 71:\n");

	//insert_bst(&tree, 71);
	//in_order_traverse(tree);
	printf("\n");

	printf("After delete 93:\n");
	delete_bst(&tree, 93);
	in_order_traverse(tree);
	printf("\n");

	return 0;
}















/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LH	1	/* 左高 */
#define EH	0	/* 等高 */
#define RH	-1	/* 右高 */

struct avl {
	int data;
	int bf;	/* 平衡因子 */
	struct avl *lchild, *rchild;
};


/*
 * 右旋转操作
 * 对以tree为根的二叉排序树作右旋处理，
 * 处理之后tree指向新的树根结点，即旋转处理之前的左子树的根结点
 */
void
rotate_right(struct avl **tree)
{
	struct avl *ptr;
	ptr = (*tree)->lchild;
	(*tree)->lchild = ptr->rchild;
	ptr->rchild = (*tree);
	*tree = ptr;
}

/*
 * 左旋转操作
 * 对以tree为根的二叉排序树作左旋处理，
 * 处理之后tree指向新的树根结点，即旋转处理之前的右子树的根结点
 */
void
rotate_left(struct avl **tree)
{
	struct avl *ptr;
	ptr = (*tree)->rchild;
	(*tree)->rchild = ptr->lchild;
	ptr->lchild = (*tree);
	*tree = ptr;
}


/*
 * 左平衡旋转处理
 * 新插入一个结点后，左子树高度大于右子树高度
 */
void
left_balance(struct avl **tree)
{
	struct avl *left, *lr;
	left = (*tree)->lchild;

	switch (left->bf) {
	case LH:
		/* 左子树的BF为1，与根结点的BF值2符号相同，进行右旋操作 */
		/* 即:平衡二叉树某一节点的左孩子的左子树上插入一个新的节点 */
		(*tree)->bf = left->bf = EH;	/* BF值设为0 */
		rotate_right(tree);
		break;

	case RH:
		/* 左子树的BF为-1，与根结点的BF值2符号相反，进行双旋转处理 */
		lr = left->rchild;	/* lr指向left的右子树 */

		switch (lr->bf) {	/* 修改tree和它的左孩子的BF */
		case LH:
			(*tree)->bf = RH;
			left->bf = EH;
			break;
		case EH:		/* 这个应该不会出现吧 */
			(*tree)->bf = left->bf = EH;
			break;
		case RH:
			(*tree)->bf = EH;
			left->bf = LH;
			break;
		}
		lr->bf = EH;

		/* 先对tree的左子树进行左旋处理 */
		rotate_left(&(*tree)->lchild);
		/* 最后是对tree进行右旋处理 */
		rotate_right(tree);
		break;
	}
}

/*
 * 右平衡旋转处理
 * 新插入一个结点后，右子树高度大于左子树高度
 */
void
right_balance(struct avl **tree)
{
	struct avl *right, *rl;
	right = (*tree)->rchild;

	switch (right->bf) {
	case RH:
		/* 右子树的BF为-1，与根结点的BF值-2符号相同，进行左旋操作 */
		/* 即:平衡二叉树某一节点的右孩子的右子树上插入一个新的结点 */
		(*tree)->bf = right->bf = EH;	/* BF值设为0 */
		rotate_left(tree);
		break;

	case LH:
		/* 右子树的BF为1，与根结点的BF值-2符号相反，进行双旋转处理 */
		rl = right->lchild;	/* rl指向right的左子树 */

		switch (rl->bf) {	/* 修改tree和它的右孩子的BF */
		case LH:
			(*tree)->bf = EH;
			right->bf = RH;
			break;
		case EH:		/* 这个应该不会出现吧 */
			(*tree)->bf = right->bf = EH;
			break;
		case RH:
			(*tree)->bf = LH;
			right->bf = EH;
			break;
		}
		rl->bf = EH;

		/* 先对tree的右子树进行右旋处理 */
		rotate_right(&(*tree)->rchild);
		/* 最后是对tree进行左旋处理 */
		rotate_left(tree);
		break;
	}
}


/*
 * 插入结点到AVL树
 *
 * 结点已存在，返回0；出错，返回-1，成功返回1
 */
int
insert_avl(struct avl **tree, int item, int *taller)
{
	int ret = 0;

	if (*tree == NULL) {
		/* 树为空，插入为根结点 */
		*tree = (struct avl *) malloc(sizeof(struct avl));
		if (*tree == NULL)
			return -1;
		(*tree)->data = item;
		(*tree)->lchild = (*tree)->rchild = NULL;
		(*tree)->bf = EH;
		*taller = 1;	/* 树长高了 */
	} else {
		/* 结点已经存在 */
		if (item == (*tree)->data) {
			*taller = 0;
			return 0;
		}

		/* 结点小于根结点，往左子树查找，递归 */
		if (item < (*tree)->data) {
			ret = insert_avl(&(*tree)->lchild, item, taller);
			if (ret != 1)	/* 未插入 */
				return ret;

			/* 新插入结点到左子树，且左子树长高了 */
			if (*taller == 1) {
				/* 检查树的平衡度 */
				switch ((*tree)->bf) {
				case LH:
					/* 插入结点后，左子树比右子树高，作左平衡处理 */
					left_balance(tree);
					*taller = 0;
					break;
				case EH:
					/* 原本左右子树等高，插入新结点后，根增高 */
					(*tree)->bf = LH;
					*taller = 1;
					break;
				case RH:
					/* 原本右子树比左子树高，插入后等高 */
					(*tree)->bf = EH;
					*taller = 0;
					break;
				}
			}

		/* 结点大于根结点，往右子树查找，递归 */
		} else if (item > (*tree)->data) {
			ret = insert_avl(&(*tree)->rchild, item, taller);
			if (ret != 1)	/* 未插入 */
				return ret;

			/* 新插入结点到右子树，且右子树长高了 */
			if (*taller == 1) {
				/* 检查树的平衡度 */
				switch ((*tree)->bf) {
				case LH:
					/* 原本左子树比右子树高，插入后等高 */
					(*tree)->bf = EH;
					*taller = 0;
					break;
				case EH:
					/* 原本左右子树等高，插入结点后，树增高 */
					(*tree)->bf = RH;
					*taller = 1;
					break;
				case RH:
					/* 插入后右子树比左子树高，作右平衡处理 */
					right_balance(tree);
					*taller = 0;
					break;
				}
			}
		}
	}

	return 1;
}

/*
 * 从avl树中删除结点
 */
void
delete_avl()
{

}

/*
 * 递归
 * 中序遍历：先遍历左子树，然后显示结点数据，再遍历右子树
 */
void
in_order_traverse(struct avl *tree)
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
	int a[10] = {3, 2, 1, 4, 5, 6, 7, 20, 16, 10};
	struct avl *tree = NULL;
	int taller = 0;
	for (i = 0; i < 10; ++i)
		insert_avl(&tree, a[i], &taller);

	in_order_traverse(tree);
	printf("\nAfter insert 12:\n");
	insert_avl(&tree, 12, &taller);
	in_order_traverse(tree);
	printf("\n");


	return 0;
}







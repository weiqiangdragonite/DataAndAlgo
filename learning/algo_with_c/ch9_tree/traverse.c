/*
 * traverse.c
 * implementation of functions for traversing a binary tree
 */

#include "list.h"
#include "traverse.h"

/*
 * 前序遍历：中 - 前 - 后
 */
int
preorder(const BiTreeNode *node, List *list)
{
	/* load the list with a preorder listing of the tree */
	if (!bitree_is_eob(node)) {
		if (list_insert_next(list, list_tail(list), bitree_data(node)) != 0)
			return -1;

		if (!bitree_is_eob(bitree_left(node))) {
			if (preorder(bitree_left(node), list) != 0)
				return -1;
		}

		if (!bitree_is_eob(bitree_right(node))) {
			if (preorder(bitree_right(node), list) != 0)
				return -1;
		}
	}
	return 0;
}



/*
 * 中序遍历：前 - 中 - 后
 */
int
inorder(const BiTreeNode *node, List *list)
{
	/* load the list with a inorder listing of the tree */
	if (!bitree_is_eob(node)) {
		if (!bitree_is_eob(bitree_left(node))) {
			if (inorder(bitree_left(node), list) != 0)
				return -1;
		}

		if (list_insert_next(list, list_tail(list), bitree_data(node)) != 0)
			return -1;

		if (!bitree_is_eob(bitree_right(node))) {
			if (inorder(bitree_right(node), list) != 0)
				return -1;
		}
	}
	return 0;
}




/*
 * 后序遍历：前 - 后 - 中
 */
int
postorder(const BiTreeNode *node, List *list)
{
	/* load the list with a postorder listing of the tree */
	if (!bitree_is_eob(node)) {
		if (!bitree_is_eob(bitree_left(node))) {
			if (postorder(bitree_left(node), list) != 0)
				return -1;
		}

		if (!bitree_is_eob(bitree_right(node))) {
			if (postorder(bitree_right(node), list) != 0)
				return -1;
		}

		if (list_insert_next(list, list_tail(list), bitree_data(node)) != 0)
			return -1;
	}
	return 0;
}






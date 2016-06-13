/*
 * bitree.c
 * implementation of the binary tree abstract datatype
 */


#include <stdlib.h>
#include <string.h>

#include "bitree.h"


void
bitree_init(BiTree *tree, void (*destroy)(void *data))
{
	/* initialize the binary tree */
	tree->size = 0;
	tree->compare = NULL;
	tree->destroy = destroy;
	tree->root = NULL;
}


void
bitree_destroy(BiTree *tree)
{
	/* remove all the nodes form the tree */
	bitree_remove_left(tree, NULL);

	/* no operations are allowed now, but clear the structure as a precatuion */
	memset(tree, 0, sizeof(BiTree));
}


int
bitree_insert_left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node;
	BiTreeNode **position;

	/* determine where to insert the node */
	if (node == NULL) {
		/* allow insertion at the root only in an empty tree */
		if (bitree_size(tree) != 0)
			return -1;

		position = &tree->root;
	} else {
		/* normally allow insertion only at the end of a branch */
		if (bitree_left(node) != NULL)
			return -1;

		position = &node->left;
	}

	/* allocate storage for the node */
	if ((new_node = (BiTreeNode *) malloc(sizeof(BiTreeNode))) != NULL)
		return -1;

	/* insert the node into the tree */
	new_node->data = (void *) data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	/* adjust the size of the tree to account for the inserted node */
	++tree->size;

	return 0;
}



int
bitree_insert_right(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node;
	BiTreeNode **position;

	/* determine where to insert the node */
	if (node == NULL) {
		/* allow insertion at the root only in an empty tree */
		if (bitree_size(tree) > 0)
			return -1;

		position = &tree->root;
	} else {
		/* normally allow insertion only at the end of a branch */
		if (bitree_right(node) != NULL)
			return -1;

		position = &node->right;
	}

	/* allocate storage for the node */
	if ((new_node = (BiTreeNode *) malloc(sizeof(BiTreeNode))) != NULL)
		return -1;

	/* insert the node into the tree */
	new_node->data = (void *) data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	/* adjust the size of the tree to account for the inserted node */
	++tree->size;

	return 0;
}


void
bitree_remove_left(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	/* do not allow removal from an empty tree */
	if (bitree_size(tree) == 0)
		return;

	/* determine where to remove nodes */
	if (node == NULL)
		position = &tree->root;
	else
		position = &node->left;

	/* remove the nodes - recursive */
	if (*position != NULL) {
		bitree_remove_left(tree, *position);
		bitree_remove_right(tree, *position);

		if (tree->destroy != NULL) {
			/* call a user defined function to free dynamically allocated data */
			tree->destroy((*position)->data);
		}

		free(*position);
		*position = NULL;

		/* adjust the size of the tree to account for the remoced node */
		--tree->size;
	}
}



void
bitree_remove_right(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	/* do not allow removal from an empty tree */
	if (bitree_size(tree) == 0)
		return;

	/* determine where to remove nodes */
	if (node == NULL)
		position = &tree->root;
	else
		position = &node->right;

	/* remove the nodes - recursive */
	if (*position != NULL) {
		bitree_remove_left(tree, *position);
		bitree_remove_right(tree, *position);

		if (tree->destroy != NULL) {
			/* call a user defined function to free dynamically allocated data */
			tree->destroy((*position)->data);
		}

		free(*position);
		*position = NULL;

		/* adjust the size of the tree to account for the remoced node */
		--tree->size;
	}
}


int
bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
	/* initialize the merged tree */
	bitree_init(merge, left->destroy);

	/* insert the data for the root node of the merged tree */
	if (bitree_insert_left(merge, NULL, data) != 0) {
		bitree_destroy(merge);
		return -1;
	}

	/* merge the two binary trees into a single binary tree */
	bitree_root(merge)->left = bitree_root(left);
	bitree_root(merge)->right = bitree_root(right);

	/* adjust the size of the new binary tree */
	merge->size = merge->size + bitree_size(left) + bitree_size(right);

	/* do not let the original trees access the merged nodes */
	left->root = NULL;
	left->size = 0;
	right->root = NULL;
	right->size = 0;

	return 0;
}


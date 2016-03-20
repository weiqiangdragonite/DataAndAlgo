/*
 * bitree.h
 * header for the binary tree abstract datatype
 */

#ifndef BITREE_H
#define BITREE_H


/*
 * define a structure for binary tree nodes 
 */
typedef struct BiTreeNode_ {
	void *data;
	struct BiTreeNode_ *left;
	struct BiTreeNode_ *right;
} BiTreeNode;


/*
 * define a structure fot binary trees
 */
typedef struct BiTree_ {
	int size;
	int (*compare)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	BiTreeNode *root;
} BiTree;


/*
 * public interface
 */

void bitree_init(BiTree *tree, void (*destroy)(void *data));

void bitree_destroy(BiTree *tree);

int bitree_insert_left(BiTree *tree, BiTreeNode *node, const void *data);

int bitree_insert_right(BiTree *tree, BiTreeNode *node, const void *data);

void bitree_remove_left(BiTree *tree, BiTreeNode *node);

void bitree_remove_right(BiTree *tree, BiTreeNode *node);

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

/* int bitree_size(const BiTree *tree); */
#define bitree_size(tree)	((tree)->size)

/* BiTreeNode *bitree_root(const BiTree *tree); */
#define bitree_root(tree)	((tree)->root)

/* int bitree_is_eob(const BiTreeNode *node); */
#define bitree_is_eob(node)	((node) == NULL)

/* int bitree_is_leaf(const BiTreeBode *node); */
#define bitree_is_leaf(node)	((node)->left == NULL && (node)->right == NULL)

/* void *bitree_data(const BiTreeNode *node); */
#define bitree_data(node)	((node)->data)

/* BiTreeNode *bitree_left(const BiTreeNode *node); */
#define bitree_left(node)	((node)->left)

/* BiTreeNode *bitree_right(const BiTreeNode *node); */
#define bitree_right(node)	((node)->right)



#endif

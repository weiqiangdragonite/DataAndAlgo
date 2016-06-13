/*
 * traverse.h
 * header for traversing a binary tree
 */

#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "list.h"
#include "bitree.h"


/*
 * public interface
 */
int preorder(const BiTreeNode *node, List *list);

int inorder(const BiTreeNode *node, List *list);

int postorder(const BiTreeNode *node, List *list);


#endif

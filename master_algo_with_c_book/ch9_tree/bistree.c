/*
 * bistree.c
 * implementation of the binary search tree abstract datatype
 */




static void
rotate_left(BiTreeNode **node)
{
	BiTreeNode *left, *grandchild;

	left = bitree_left(*node);

	if (((AvlNode *) bitree_data(left))->factor == AVL_LEFT_HEAVY)
}




static int
insert(BisTree *tree, BiTreeNode **node, const void *data, int *balanced)
{
	AvlNode *avl_data;
	int cmpval, retval;

	/* insert the data into the tree */
	if (bitree_is_eob(*node)) {
		/* handle insertion into an empty tree */
		if ((avl_data = (AvlNode *) malloc(sizeof(AvlNode))) == NULL)
			return -1;

		avl_data->factor = AVL_BALANCED;
		avl_data->hidden = 0;
		avl_data->data = (void *) data;

		return bitree_insert_left(tree, *node, avl_data);

	} else {
		/* handle insertion into a tree that is not empty */
		cmpval = tree->compare(data, ((AvlNode *) bitree_data(*node))->data);

		if (cmpval < 0) {
			/* move to the left */
			if (bitree_is_eob(bitree_left(*node)) {
				avl_data = (AvlNode *) malloc(AvlNode);
				if (avl_data == NULL)
					return -1;

				avl_data->factor = AVL_BALANCED;
				avl_data->hidden = 0;
				avl_data->data = (void *) data;

				if (bitree_insert_left(tree, *node, avl_data) != 0)
					return -1;
			}
		}
	}
}









/*
 * initialize the tree
 */
void
bistree_init(BisTree *tree, int (*compare)(const void *key1, const void *key2),
	void (*destroy)(void *data))
{
	bistree_init(tree, destroy);
	tree->compare = compare;
}

/*
 * destroy all nodes in the tree
 */
void
bistree_destroy(BisTree *tree)
{
	destroy_left(tree, NULL);

	/* no operations are allowed now, but clear the structure as a precaution */
	memset(tree, 0, sizeof(BisTree));
}


int
bistree_insert(BisTree *tree, const void *data)
{
	int balanced = 0;
	return insert(tree, &bitree_root(tree), data, &banlanced);
}

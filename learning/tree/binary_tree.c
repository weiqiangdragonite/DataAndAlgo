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


/******************************************************************************/

typedef void * ElemType;

struct node {
	ElemType data;
	struct node *next;
};

struct link_stack {
	struct node *top;
	unsigned int count;
};

typedef struct link_stack link_stack_t;

struct link_queue {
	struct node *front;
	struct node *rear;
};

typedef struct link_queue link_queue_t;

/******************************************************************************/

/* 初始化栈 */
void
init_stack(link_stack_t *stack)
{
	stack->top = NULL;
	stack->count = 0;
}

/* 如果是空栈，返回1 */
int
is_stack_empty(link_stack_t *s)
{
	return s->count == 0 ? 1 : 0;
}


/*
 * 入栈：不需要头结点
 */
int
push(link_stack_t *stack, struct binary_tree *item)
{
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));

	ptr->next = stack->top;
	ptr->data = item;
	stack->top = ptr;
	++stack->count;

	return 0;
}

/* 返回栈顶元素，不同pop哦 */
int
top(link_stack_t *stack, struct binary_tree **item)
{
	/* if empty */
	if (stack->count == 0)
		return -1;

	struct node *ptr;
	ptr = stack->top;

	*item = (struct binary_tree *) ptr->data;

	return 0;
}

/*
 * 出栈：不需头结点
 */
int
pop(link_stack_t *stack, struct binary_tree **item)
{
	/* if empty */
	if (stack->count == 0)
		return -1;

	struct node *ptr;
	ptr = stack->top;

	*item = (struct binary_tree *) ptr->data;
	stack->top = ptr->next;
	free(ptr);
	--stack->count;

	return 0;
}

/******************************************************************************/

/* 初始化队列 */
void
init_queue(link_queue_t *q)
{
	q->front = NULL;
	q->rear = NULL;
}

/* 如果队列为空，返回1 */
int
is_queue_empty(link_queue_t *q)
{
	return q->front == NULL ? 1 : 0;
}

/*
 * 入队，不带头结点
 */
int
enter(link_queue_t *q, struct binary_tree *item)
{
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));

	ptr->next = NULL;
	ptr->data = item;


	if (q->front == NULL) {
		q->front = q->rear = ptr;
	} else {
		q->rear->next = ptr;
		q->rear = ptr;
	}

	return 0;
}

/*
 * 出对，不带头结点
 */
int
delete(link_queue_t *q, struct binary_tree **item)
{
	/* if empty */
	if (q->front == NULL)
		return -1;

	struct node *ptr;
	ptr = q->front;

	*item = (struct binary_tree *) ptr->data;
	q->front = ptr->next;

	/* after delete the last item, rear point to head */
	if (q->rear == ptr)
		q->rear = q->front;
	free(ptr);

	return 0;
}

/******************************************************************************/




/*
 * 递归
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
 * 前序遍历的非递归调用（使用堆栈）
 * 1.遇到一个结点，先访问这个结点，然后压栈，并去遍历它的左子树；
 * 2.当左子树遍历结束后，从栈顶弹出这个结点；
 * 3.然后按其右指针再去前序遍历该结点的右子树。
 */
void
pre_order_traverse_v2(struct binary_tree *tree)
{
	struct binary_tree *ptr;
	link_stack_t s;

	ptr = tree;
	init_stack(&s);

	/* 当结点不为空，或栈不为空 */
	while (ptr != NULL || !is_stack_empty(&s)) {
		if (ptr != NULL) {
			printf("%c", ptr->data);
			/* 结点入栈 */
			push(&s, ptr);
			/* 进入结点的左子树 */
			ptr = ptr->lchild;
		} else {
			/* 取出结点 */
			pop(&s, &ptr);
			/* 进入结点的右子树 */
			ptr = ptr->rchild;
		}
	}
}



/*
 * 递归
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
 * 中序遍历的非递归调用（使用堆栈）
 * 1.遇到一个结点，就把它压栈，并去遍历它的左子树；
 * 2.当左子树遍历结束后，从栈顶弹出这个结点并访问它；
 * 3.然后按其右指针再去中序遍历该结点的右子树。
 */
void
in_order_traverse_v2(struct binary_tree *tree)
{
	struct binary_tree *ptr;
	link_stack_t s;

	ptr = tree;
	init_stack(&s);

	/* 当结点不为空，或栈不为空 */
	while (ptr != NULL || !is_stack_empty(&s)) {
		if (ptr != NULL) {
			/* 结点入栈 */
			push(&s, ptr);
			/* 进入结点的左子树 */
			ptr = ptr->lchild;
		} else {
			/* 取出结点 */
			pop(&s, &ptr);
			printf("%c", ptr->data);
			/* 进入结点的右子树 */
			ptr = ptr->rchild;
		}
	}
}

/*
 * 递归
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
 * 后序遍历的非递归调用（使用堆栈）
 * 
 */
void
post_order_traverse_v2(struct binary_tree *tree)
{
	struct binary_tree *ptr = NULL;
	struct binary_tree *node = NULL;
	link_stack_t s;

	ptr = tree;
	init_stack(&s);

	/* 当结点不为空，或栈不为空 */
	while (ptr != NULL || !is_stack_empty(&s)) {
		if (ptr != NULL) {
			/* 结点入栈 */
			push(&s, ptr);
			/* 进入结点的左子树 */
			ptr = ptr->lchild;


		} else {
			/* 返回栈顶结点 */
			top(&s, &ptr);

			/* 当前结点的右孩子如果为空或者已经被访问，则访问当前结点 */
			if (ptr->rchild == NULL || ptr->rchild == node) {
				printf("%c", ptr->data);
				node = ptr;
				pop(&s, &ptr);
				ptr = NULL;
			} else {
				/* 进入结点的右子树 */
				ptr = ptr->rchild;
			}
		}
	}
}

/*
 * 层序遍历
 * 队列实现：遍历从根结点开始，首先将根结点入队，然后开始执行循环：
 * 结点出队、访问该结点、其左右儿子入队。
 */
void
level_order_traverse(struct binary_tree *tree)
{
	struct binary_tree *ptr;
	link_queue_t q;

	ptr = tree;
	init_queue(&q);
	enter(&q, ptr);

	while (!is_queue_empty(&q)) {
		delete(&q, &ptr);
		printf("%c", ptr->data);
		if (ptr->lchild)
			enter(&q, ptr->lchild);
		if (ptr->rchild)
			enter(&q, ptr->rchild);
	}
}



/*
 * 递归：按前序输入方式构造二叉树
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

	printf("\npre order traverse v2: ");
	pre_order_traverse_v2(tree);

	printf("\nin order traverse: ");
	in_order_traverse(tree);

	printf("\nin order traverse v2: ");
	in_order_traverse_v2(tree);

	printf("\npost order traverse: ");
	post_order_traverse(tree);

	printf("\npost order traverse v2: ");
	post_order_traverse_v2(tree);

	printf("\nlevel order traverse: ");
	level_order_traverse(tree);

	printf("\n");

	return 0;
}




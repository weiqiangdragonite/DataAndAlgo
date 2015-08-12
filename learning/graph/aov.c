/*
 *
 */



/* 边表结点 */
struct edge_node {
	int adjvex;
	int weight;
	struct edge_node *next;
};

/* 顶点表结点 */
struct vertex_node {
	int in;	/* 顶点入度 */
	int data;
	struct edge_node *first_edge;
};

struct adj_list {
	struct vertex_node list[MAX_VEX];
	int num_vertexes;
	int num_edges;
};


/*
 *
 */
aov()
{
	struct edge_node *edge;

	/* 将入度为0的顶点入栈 */
	for (i = 0; i < grapg->num_vertexes; ++i) {
		if (graph->list[i].in == 0)
			push(i);
	}

	while () {
		/* 出栈 */
		top = pop();

		/* 打印此顶点 */
		printf();

		++counter;	/* 统计输出顶点数 */

		for (edge = graph->list[top].first_edge; edge; edge = edge->next) {
			/* 对此顶点弧表遍历 */
			k = edge->adjvex;
			if (--(graph->list[k].in) == 0)	/* 将k号顶点邻接点的入度减1 */
				push(k);	/* 若为0则入栈 */
		}
	}

	/* 如果counter小于顶点数，说明存在环 */
	if (counter < graph->num_vertexes)
		// error
	else
		// ok
}





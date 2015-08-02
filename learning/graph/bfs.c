/*
 * 广度优先搜索
 */


#define MAX_VEX		100	/* 最大顶点数 */
#define INFINITY	65535	/* 大于所有边的权值 ∞ */

typedef char VertexType;	/* 顶点类型 */
typedef int  EdgeType;		/* 边上权值类型 */


struct matrix {
	VertexType vertex[MAX_VEX];	/* 顶点表 */
	EdgeType arc[MAX_VEX][MAX_VEX];	/* 邻接矩阵，边表 */
	int num_vertexes;		/* 图中当前的顶点数 */
	int num_edges;			/* 图中当前的边数 */
};


/* 已经被访问过的顶点数组，初始化为0 */
int visited[MAX_VEX];


/*
 * 邻接矩阵的广度遍历算法
 */
void
bfs()
{
	int i, j;

	/* 初始化访问顶点数组为0 */
	memset(visited, 0, sizeof(visited));

	/* 初始化队列 */
	init_queue();

	for (i = 0; i < graph->num_vertexes; ++i) {
		if (visited[i])
			continue;	/*顶点已访问过*/

		visited[i] = 1;	/* 标记顶点已被访问 */
		printf("%c", graph->vertex[i]);	/* 打印顶点 */

		/* 将此顶点入队 */
		enter_queue();

		/* 若当前队列不为空 */
		while (!is_queue_empty()) {
			/* 将队列中元素出队列 */
			delete_queue();

			/* 将该顶点所在那行扫一遍 */
			for (j = 0; j < graph->num_vertexes; ++j) {
				if (graph->arc[i][j] == 1 && visited[j] == 0) {
					visited[j] = 1;
					printf("%c", graph->vertex[j]);
					enter_queue();
				}
			}
		}
	}
}



/*
 * 邻接表的广度遍历算法
 */
void
bfs()
{
	int i;
	struct edge_node *ptr;

	/* 初始化访问顶点数组为0 */
	memset(visited, 0, sizeof(visited));

	/* 初始化队列 */
	init_queue();

	for (i = 0; i < graph->num_vertexes; ++i) {
		if (visited[i] == 1)
			continue;	/* 该顶点已被访问 */

		visited[i] = 1;	/* 标记顶点已被访问 */
		printf("%c", graph->vertex[i]);	/* 打印顶点 */

		/* 将该顶点入队 */
		enter_queue();

		/* 若当前队列不为空 */
		while (!is_queue_empty()) {
			/* 将队列中元素出队列 */
			delete_queue();

			/* 指向该顶点边表头指针 */
			ptr = graph->adj_list[i].first_edge;
			while (ptr) {
				if (visited[ptr->adjvex] == 0) {
					visited[ptr->adjvex] = 1;
					printf("%c", graph->vertex[ptr->adjvex]);
					enter_queue();
				}
				ptr = ptr->next;
			}
		}
	}
}









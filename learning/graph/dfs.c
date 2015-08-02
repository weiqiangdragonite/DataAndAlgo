/*
 * 深度优先搜索
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
 * 邻接矩阵的深度优先搜索，递归
 * 由 dfs_traverse() 调用
 * 效率: O(n^2)
 */
void
dfs(struct matrix *graph, int i)
{
	int j;

	visited[i] = 1;	/* 标记顶点已被访问 */
	printf("%c", graph->vertex[i]);	/* 打印顶点 */

	for (j = 0; j < graph->num_vertexes; ++j) {
		if (graph->arc[i][j] == 1 && visited[j] == 0)
			dfs(graph, j);	/* 递归访问 */
	}

}

/*
 * 邻接表的深度优先递归算法
 * n个顶点，e条边，效率: O(n+e)
 */
void
dfs(struct adj_list *graph)
{
	struct edge_node *ptr;

	visited[i] = 1;	/* 标记顶点已被访问 */
	printf("%c", graph->list[i].data);	/* 打印顶点 */

	ptr = graph->list[i].first_edge;
	while (ptr) {
		if (visited[ptr->adjvex] == 0)
			dfs(graph, ptr->adjvex);
		ptr = ptr->next;
	}
}


/*
 * 邻接矩阵的深度优先遍历操作
 * 邻接表也是一样，把 struct matrix 换成 struct adj_list 即可
 */
void
dfs_traverse(struct matrix *graph)
{
	int i;

	/* 初始化访问顶点数组为0 */
	memset(visited, 0, sizeof(visited));

	for (i = 0; i < graph->num_vertexes; ++i) {
		/* 对未访问过的顶点调用dfs，若是连通图，只会执行一次 */
		if (visited[i] == 0)
			dfs(graph, i);
	}
		
}

/*******************************************/










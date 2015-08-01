/*
 * 邻接矩阵存储
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

/*
 * 建立无向网图的邻接矩阵
 * 时间复杂度为 O(n + n^2 + e)
 */
void
create_graph(struct matrix *graph)
{
	int i, j, k, w;

	printf("input number of vertexes and edges:\n");
	scanf("%d %d", &graph->num_vertexes, &graph->num_edges);

	/* 读入顶点信息，建立顶点表 */
	printf("\ninput all the vertexes:\n");
	for (i = 0; i < graph->num_vertexes; ++i)
		scanf("%d", &graph->vertex[i]);

	/* 邻接矩阵初始化 */
	for (i = 0; i < graph->num_vertexes; ++i) {
		for (j = 0; j < graph->num_vertexes; ++j)
			graph->arc[i][j] = INFINITY;
	}

	/* 读入边信息，建立邻接矩阵 */
	printf("\ninput (Vi, Vj) and weight:\n");
	for (k = 0; k < graph->num_edges; ++k) {
		scanf("%d %d %d", &i, &j, &w);
		graph->arc[i][j] = w;
		graph->arc[j][i] = w;	/* 无向图，矩阵对称 */
	}
}








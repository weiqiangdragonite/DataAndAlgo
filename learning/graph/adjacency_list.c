/*
 * 邻接表存储
 */


#define MAX_VEX		100	/* 最大顶点数 */
#define INFINITY	65535	/* 大于所有边的权值 ∞ */


typedef char VertexType;	/* 顶点类型 */
typedef int  EdgeType;		/* 边上权值类型 */


/* 边表结点 */
struct edge_node {
	int adjvex;	/* 邻接点域，存储该顶点对应的下标 */
	EdgeType weight;	/* 权值 */
	struct edge_node *next;	/* 指向下一个邻接点 */
};


/* 顶点表结点 */
struct vertex_node {
	VertexType data;	/* 顶点域，存储顶点信息 */
	struct edge_node *first_edge;	/* 边表头指针 */
};


/* 邻接表 */
struct adj_list {
	struct vertex_node list[MAX_VEX];
	int num_vertexes;		/* 图中当前的顶点数 */
	int num_edges;			/* 图中当前的边数 */
};


/*
 * 无向图的邻接表创建
 * n个顶点，e条边，时间复杂度: O(n+e)
 */
void
create_graph(struct adj_list *graph)
{
	int i, j, k;

	printf("input number of vertexes and edges:\n");
	scanf("%d %d", &graph->num_vertexes, &graph->num_edges);

	/* 读入顶点信息，建立顶点表 */
	printf("\ninput all the vertexes:\n");
	for (i = 0; i < graph->num_vertexes; ++i) {
		scanf("%d", &graph->list[i].data);
		graph->list[i].first_edge = NULL;	/* 边表置空 */
	}

	/* 建立边表 */
	/* 一条边，对应两个顶点 */
	printf("\ninput edge (Vi, Vj) index:\n");
	for (k = 0; k < graph->num_edges; ++k) {
		/* 输入边(Vi, Vj)上的顶点序号 */
		scanf("%d %d", &i, &j);

		/* 用头插法插入结点 */

		e = (struct edge_node *) malloc(sizeof(struct edge_node));
		e->adjvex = j;	/* 邻接序号为 j */
		e->next = graph->adj_list[i].first_edge;	/* 指向表头 */
		graph->adj_list[i].first_edge = e;	/* 表头指向当前结点 */

		/* 对应的另一半 */
		e = (struct edge_node *) malloc(sizeof(struct edge_node));
		e->adjvex = i;	/* 邻接序号为 i */
		e->next = graph->adj_list[j].first_edge;
		graph->adj_list[j].first_edge = e;
	}

}












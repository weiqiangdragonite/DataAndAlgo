/*
 *
 */



/*
 * Prim算法
 * 邻接矩阵
 * 复杂度为 O(n^2)
 */
void
prim()
{
	int i, j, k, min;

	int adjvex[MAX_VEX];	/* 保存相关顶点下标 */
	int lowcost[MAX_VEX];	/* 保存相关顶点间边的权值 */

	/* 初始化第一个权值为0，即V0加入生成树 */
	/* lowcost的值为0，表示此下标的顶点已加入生成树 */
	lowcost[0] = 0;

	/* 初始化第一个顶点下标为0 */
	adjvex[0] = 0;


	/* 初始化，循环顶点 */
	/* 读取邻接矩阵的第一行数据，将值存到 lowcost 数组里 */
	for (i = 1; i < graph->num_vertexes; ++i) {
		/* 将与V0顶点有边的权值存入数组 */
		lowcost[i] = graph->arc[0][i];
		adjvex[i] = 0;
	}

	/* 开始构造最小生成树 */
	for (i = 1; i < graph->num_vertexes; ++i) {
		min = INFINITY;		/* 初始化最小权值 */

		j = 1;	/* 顶点下标循环的变量 */
		k = 0;	/* 存储最小权值的顶点下标 */

		/* 循环全部顶点，找出最小权值的顶点下标 */
		while (j < graph->num_vertexes) {
			/* 如果权值不为0 且 权值小于min */
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];	/* 当前权值存为最小值 */
				k = j;			/* 当前顶点存入下标 */
			}
			++j;
		}

		/* 打印当前顶点边中权值最小边 */
		printf("(%d, %d)", adjvex[k], k);

		lowcost[k] = 0;	/* 此顶点已加入生成树 */

		/* 循环所有顶点 */
		for (j = 1; j < graph->num_vertexes; ++j) {
			if (lowcost[j] != 0 && graph->arc[k][j] < lowcost[j]) {
				lowcost[j] = graph->arc[k][j];	/* 存入较小权值 */
				adjvex[j] = k;	/* 存入下标 */
			}
		}
	}

}


/******************************************************************************/


#define MAX_EDGE	100	/* 边数最大值 */
#define MAX_VEX		100

/*
 * 边集数组
 */
struct edge {
	int begin;
	int end;
	int weight;
};


/*
 * 查找连线顶点的尾部下标
 */
int find(int parent[], int i)
{
	while (parent[i] > 0)
		i = parent[i];

	return i;
}


/*
 *
 */
void
kruskal()
{


	struct edge edges[MAX_EDGE];	/* 定义边集数组 */
	int parent[MAX_VEX];		/* 定义数组来判断边与边是否形成环路 */

	/* 将边集数组按权值由小到大排列 */
	sort();

	memset(parent, 0, sizeof(parent));

	/* 循环每一条边 */
	for (i = 0; i < graph->num_edges; ++i) {
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);

		/* n != m 说明此边没有与现有生成树形成环路 */
		if (n != m) {
			/* 将次边的结尾顶点放入下标为起点的parent中 */
			/* 表示此顶点已经在生成树集合中 */
			parent[n] = m;

			printf("(%d, %d) - %d", edges[i].begin, edges[i].end
				edges[i].weight);
		}
	}
}



















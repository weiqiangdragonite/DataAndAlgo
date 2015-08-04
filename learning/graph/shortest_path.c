/*
 * 求最短路径
 */



int path_array[MAX_VEX];	/* 用于存储最短路径下标的数组 */
int weight_array[MAX_VEX];	/* 用于存储到顶点最短路径的权值和 */



/*
 * Dijkstra算法
 * 求有向网G的V0顶点到其余顶点V最短路径P[v]及带权长度D[v]，P[v]的值为
 * 前驱顶点下标，D[v]表示v0到v的最短路径长度和
 */
void
dijkstra( *graph, int v0, int p[], int d[])
{

	/* final[w] = 1 表示求得顶点V0到Vw的最短路径 */
	int final[MAX_VEX];

	/* 初始化 */
	for (i = 0; i < grapg->num_vertexes; ++i) {
		final[i] = 0;	/* 所有的点都未求得最短路径 */
		d[i] = graph->arc[v0][i];	/* 与v0有连线的顶点的权值 */
		p[i] = 0;	/* 目前没有路径 */
	}

	d[v0] = 0;	/* v0到v0路径为0*/
	final[v0] = 1;	/* v0到v0不需要求路径 */

	/* 开始循环，每次求得v0到某个顶点的最短路径 */
	for (i = 1; i < graph->num_vertexes; ++i) {
		min = INFINITY;

		/* 寻找离V0最近的顶点 */
		for (j = 0; j < graph->num_vertexes; ++j) {
			if (final[j] == 0 && d[j] < min) {
				k = j;
				min = d[j];	/* 顶点j离v0更近 */
			}
		}
		final[k] = 1;	/* 将目前找到的最近的顶点置1 */

		/* 修正当前最短路径及距离 */
		for (j = 0; j < graph->num_vertexes; ++j) {
			/* 如果经过v顶点的路径比现在这条路径的长度短的话 */
			if (final[j] == 0 && (min + graph->arc[k][j] < d[j])) {
				/* 说明找到了更短的路径 */
				d[j] = min + graph->arc[k][j];
				p[j] = k;
			}
		}
	}
}



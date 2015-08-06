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



/*
 * 弗洛伊德算法，求网图G中各定点v到其余顶点w最短路径p[v][w]及带权长度d[v][w]
 */
void
floyd()
{

	/* 初始化d与p */
	for (v = 0; v < graph->num_vertexes; ++v) {
		for (w = 0; w < graph->num_vertexes; ++w) {
			d[v][w] = graph->arc[v][w];	/* d为对应点间的权值 */
			p[v][w] = w;
		}
	}

	for (k = 0; k < graph->num_vertexes; ++k) {
		for (v = 0; v < graph->num_vertexes; ++v) {
			for (w = 0; w < graph->num_vertexes; ++w) {
				/* 如果经过下标为k顶点路径比原两点间路径更短，*/
				/* 将当前两点间权值设为更小的一个 */
				if (d[v][w] > d[v][k] + d[k][w]) {
					d[v][w] = d[v][k] + d[k][w];
					p[v][w] = p[v][k];/* 路径设为经过下标为k的顶点 */
				}
			}
		}
	}
}









/*


中国大学MOOC-翁恺-C语言程序设计习题集


04-0. 求符合给定条件的整数集(15)


给定不超过6的正整数A，考虑从A开始的连续4个数字。请输出所有由它们组成的无重复数字的3位数。

输入格式：

输入在一行中给出A。

输出格式：

输出满足条件的的3位数，要求从小到大，每行6个整数。整数间以空格分隔，但行末不能有多余空格。

输入样例：
2
输出样例：
234 235 243 245 253 254
324 325 342 345 352 354
423 425 432 435 452 453
523 524 532 534 542 543

*/


#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i, j, k, num;
	int a[4], b[3];

	scanf("%d", &num);

	a[0] = num;
	a[1] = num + 1;
	a[2] = num + 2;
	a[3] = num + 3;


	for (i = 0; i < 4; ++i) {

		//printf("a = %d, ", a[i]);

		/* get the second array: such 2[3, 4, 5], 3[2, 4, 5], ... */
		for (j = 0, k = 0; j < 4; ++j) {
			if (j != i)
				b[k++] = a[j];
		}

		//printf("b = [%d, %d, %d]", b[0], b[1], b[2]);

		for (j = 0; j < 3; ++j) {
			for (k = 0; k < 3; ++k) {
				if (k != j) {
					printf("%d%d%d", a[i], b[j], b[k]);
					if (j == 2 && k == 1)
						printf("\n");	/* last one */
					else
						printf(" ");
				}
			}
		}
	}

	return 0;
}

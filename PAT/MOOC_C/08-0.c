/*


中国大学MOOC-翁恺-C语言程序设计习题集


08-0. 查找整数(10)


本题要求从输入的N个整数中查找给定的X。如果找到，输出X的位置（从0开始数）；如果没有找到，
输出“Not Found”。

输入格式：

输入在第1行中给出2个正整数N（<=20）和X，第2行给出N个整数。数字均不超过长整型，其间以空格分隔。

输出格式：

在一行中输出X的位置，或者“Not Found”。

输入样例1：
5 7
3 5 7 1 9
输出样例1：
2
输入样例2：
5 7
3 5 8 1 9
输出样例2：
Not Found

*/

#include <stdio.h>


int
main(int argc, char *argv[])
{
	long int x;
	long int num[20];
	int i, n;

	scanf("%d %ld", &n, &x);
	for (i = 0; i < n; ++i)
		scanf("%ld", &num[i]);

	for (i = 0; i < n; ++i) {
		if (x == num[i]) {
			printf("%d\n", i);
			break;
		}
		if (i == n-1)
			printf("Not Found\n");
	}

	return 0;
}





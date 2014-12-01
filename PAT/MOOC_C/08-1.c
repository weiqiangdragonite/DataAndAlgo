/*


中国大学MOOC-翁恺-C语言程序设计习题集


08-1. 求一批整数中出现最多的个位数字(20)


给定一批整数，分析每个整数的每一位数字，求出现次数最多的个位数字。
例如给定3个整数1234、2345、3456，其中出现最多次数的数字是3和4，均出现了3次。

输入格式：

输入在第1行中给出正整数N（<=1000），在第2行中给出N个不超过整型范围的正整数，数字间以空格分隔。

输出格式：

在一行中按格式“M: n1 n2 ...”输出，其中M是最大次数，n1、n2、……为出现次数最多的个位数字，
按从小到大的顺序排列。数字间以空格分隔，但末尾不得有多余空格。

输入样例：
3
1234 2345 3456
输出样例：
3: 3 4

*/

#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	int n, i;
	int num[1000];
	int number, tmp;
	int counter[10];
	int large;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &num[i]);

	memset(counter, 0, sizeof(counter));
	for (i = 0; i < n; ++i) {
		number = num[i];
		/* count the number */
		while (number) {
			tmp = number % 10;
			counter[tmp] += 1;
			number /= 10;
		}
	}

	/* find the largest */
	large = counter[0];
	for (i = 1; i < 10; ++i) {
		if (counter [i] > large)
			large = counter[i];
	}

	printf("%d:", large);
	for (i =0; i < 10; ++i) {
		if (counter[i] == large)
			printf(" %d", i);
	}
	printf("\n");

	return 0;
}





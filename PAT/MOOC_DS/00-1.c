/*

中国大学MOOC-陈越、何钦铭-数据结构基础习题集


00-自测1. 打印沙漏(20)

本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，
要求按下列格式打印

*****
 ***
  *
 ***
*****

所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；
符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。


输入样例：
19 *

输出样例：
*****
 ***
  *
 ***
*****
2

--------------------------------------------------------------------------------

正整数为大于0的整数。自然数中，除了0就是正整数。
line = the large number in the first line



*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i, j, k, n, tmp, num;
	int lines, blank, op;
	char c;

	scanf("%d %c", &n, &c);

	tmp = n - 1;
	num = 1;
	/* use the most stupid method to caculate the large number */
	while (1) {
		if (tmp == 0)
			break;

		num += 2;
		tmp = tmp - 2 * num;

		if (tmp < 0) {
			tmp = tmp + 2 * num;
			num -= 2;
			break;
		}
	}
	/* printf("large num = %d, left = %d\n", num, tmp); */


	/**/
	lines = num;
	op = 0;
	for (i = 0; i < lines; ++i) {
		blank = (lines - num) / 2;
		k = blank + num;
		/* printf("num = %d, blank = %d, num + blank = %d\n", num, blank, k); */
		for (j = 0; j < k; ++j) {
			if (blank > 0) {
				printf(" ");
				--blank;
			} else {
				printf("%c", c);
			}
		}
		if (op)
			num += 2;
		else
			num -= 2;
		if (num == 1)
			op = 1;
		printf("\n");
	}
	//if (tmp != 0)
	printf("%d\n", tmp);

	return 0;
}



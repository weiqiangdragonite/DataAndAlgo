/*


中国大学MOOC-翁恺-C语言程序设计习题集


03-1. 三天打鱼两天晒网(15)


中国有句俗语叫“三天打鱼两天晒网”。假设某人从某天起，开始“三天打鱼两天晒网”，问这个人在以后的
第N天中是“打鱼”还是“晒网”？

输入格式：

输入在一行中给出1个不超过1000的正整数N。

输出格式：

在一行中输出此人在第N天中是“Fishing”（即“打鱼”）还是“Drying”（即“晒网”），
并且输出“in day N”。

输入样例1：
103
输出样例1：
Fishing in day 103
输入样例2：
34
输出样例2：
Drying in day 34

*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int day, res;

	scanf("%d", &day);

	res = day % 5;
	printf("%s in day %d\n", (res == 0 || res == 4) ? "Drying" : "Fishing",
		day);

	return 0;
}

/*


中国大学MOOC-翁恺-C语言程序设计习题集


03-0. 超速判断(10)


模拟交通警察的雷达测速仪。输入汽车速度，如果速度超出60 mph，则显示“Speeding”，否则显示“OK”。

输入格式：

输入在一行中给出1个不超过500的非负整数，即雷达测到的车速。

输出格式：

在一行中输出测速仪显示结果，格式为：“Speed: V - S”，其中V是车速，S或者是Speeding、或者是OK。

输入样例1：
40
输出样例1：
Speed: 40 - OK
输入样例2：
75
输出样例2：
Speed: 75 - Speeding

*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int speed;

	scanf("%d", &speed);

	printf("Speed: %d - %s\n", speed, (speed > 60) ? "Speeding" : "OK");

	return 0;
}

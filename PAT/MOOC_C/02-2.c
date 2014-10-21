/*

中国大学MOOC-翁恺-C语言程序设计习题集


02-2. 然后是几点(15)


有时候人们用四位数字表示一个时间，比如1106表示11点零6分。现在，你的程序要根据起始时间和流逝的
时间计算出终止时间。 读入两个数字，第一个数字以这样的四位数字表示当前时间，第二个数字表示分钟数，
计算当前时间经过那么多分钟后是几点，结果也表示为四位数字。当小时为个位数时，没有前导的零，
即5点30分表示为530。注意，第二个数字表示的分钟数可能超过60，也可能是负数。

输入格式：

输入在一行中给出2个整数，分别是四位数字表示的起始时间、以及流逝的分钟数，其间以空格分隔。
注意：在起始时间中，当小时为个位数时，没有前导的零，即5点30分表示为530；
流逝的分钟数可能超过60，也可能是负数。

输出格式：

输出四位数字表示的终止时间。题目保证起始时间和终止时间在同一天内。

输入样例：
1120 110
输出样例：
1310

*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int start, st_hour, st_minute;
	int past, pa_hour, pa_minute;
	int end_hour, end_minute;

	/* input */
	scanf("%d %d", &start, &past);

	st_hour = start / 100;
	st_minute = start % 100;

	pa_hour = past / 60;
	pa_minute = past % 60;

	end_minute = st_minute + pa_minute;
	if (end_minute >= 60) {
		end_minute -= 60;
		end_hour = 1 + st_hour + pa_hour;
	} else if (end_minute < 0) {
		end_minute = 60 + end_minute;
		end_hour = -1 + st_hour + pa_hour;
	} else
		end_hour = st_hour + pa_hour;

	/* output */
	printf("%d\n", end_hour * 100 + end_minute);

	return 0;
}

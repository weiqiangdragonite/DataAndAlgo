/*

PAT (Basic Level) Practise （中文）


1002. 写出这个数 (20)


读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，
但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu

--------------------------------------------------------------------------------

自然数是非负整数


测试点1通过不了

*/


#include <stdio.h>

int reverse(int *i);
void spell(int i);

int
main(int argc, char *argv[])
{
	char n[128];
	int i, ret, sum;

	fgets(n, sizeof(n), stdin);

	sum = i = 0;
	// PS: no error checking
	while (n[i] != '\n')
		sum += n[i++] - '0';

	ret = reverse(&sum);
	while (sum > 0) {
		spell(sum % 10);
		sum /= 10;
		if (sum == 0 && ret == 0)
			break;
		printf(" ");
	}
	if (ret)
		spell(0);
	printf("\n");

	return 0;
}


/*
 * reverse num: 135 --> 531
 * 180 --> 018
 * 用指针来传递，如果转换后前头有0，返回1，否则返回0，出错-1
 */
int
reverse(int *i)
{
	int n = *i;
	int num = 0;
	int j = 0;

	if (n == 0)
		return 1;

	if (n % 10 == 0 && n >= 10)
		j = 1;
	while (n > 0) {
		num = (n % 10) + num * 10;
		n /= 10;
	}
	*i = num;

	return j;
}

void
spell(int i)
{
	switch (i) {
	case 1:
		printf("yi");
		break;
	case 2:
		printf("er");
		break;
	case 3:
		printf("san");
		break;
	case 4:
		printf("si");
		break;
	case 5:
		printf("wu");
		break;
	case 6:
		printf("liu");
		break;
	case 7:
		printf("qi");
		break;
	case 8:
		printf("ba");
		break;
	case 9:
		printf("jiu");
		break;
	case 0:
	default:
		printf("ling");
		break;
	}
}



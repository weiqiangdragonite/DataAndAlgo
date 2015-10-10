/*

PAT (Basic Level) Practise （中文）


1003. 我要通过！(20)


“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送
 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，
或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者
是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，
是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，
且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，
则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：
YES
YES
YES
YES
NO
NO
NO
NO


--------------------------------------------------------------------------------




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
		if (sum != 0)
			printf(" ");
	}
	if (ret) {
		printf(" ");
		spell(0);
	}
	printf("\n");

	return 0;
}


/*
 * reverse num: 135 --> 531
 * 180 --> 018
 * 用指针来传递，如果转换后前头有0，返回1，否则返回0，出错-1
 * 不考虑数本身为0
 */
int
reverse(int *i)
{
	int n = *i;
	int num = 0;
	int j = 0;

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



/*


中国大学MOOC-翁恺-C语言程序设计习题集


07-0. 写出这个数 (20)


读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，
但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu



自然数（natural number），可以是指正整数（1, 2, 3, 4），亦可以是非负整数（0, 1, 2, 3, 4）。
在数论通常用前者，而集合论和计算机科学则多数使用后者。认为自然数不包含零的其中一个理由是因为
人们（尤其是小孩）在开始学习数字的时候是由“一、二、三...”开始，而不是由“零、一、二、三...”开始, 
因为这样是非常不自然的。


10^100 = 1.e+100

64位机：
long 长 8 byte，足以容纳


*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int
main(int argc, char *argv[])
{
	char line[512];
	char num[512];
	int i, tmp, count;
	long res;


	memset(line, 0, sizeof(line));
	memset(num, 0, sizeof(num));
	fgets(line, sizeof(line), stdin);

	i = 0;
	res = 0;
	while (line[i]) {
		if (isdigit(line[i]))
			res += toascii(line[i]) - '0';
		++i;
	}
	//printf("res = %ld\n", res);

	i = count = 0;
	while (res) {
		tmp = res % 10;
		num[i++] = tmp + '0';
		++count;
		res /= 10;
	}
	//printf("num[0] = %d\n", num[0]);

	for (i = count - 1; i >= 0; --i) {
		switch (num[i]) {
		case '0':
			printf("%s", "ling");
			break;
		case '1':
			printf("%s", "yi");
			break;
		case '2':
			printf("%s", "er");
			break;
		case '3':
			printf("%s", "san");
			break;
		case '4':
			printf("%s", "si");
			break;
		case '5':
			printf("%s", "wu");
			break;
		case '6':
			printf("%s", "liu");
			break;
		case '7':
			printf("%s", "qi");
			break;
		case '8':
			printf("%s", "ba");
			break;
		case '9':
			printf("%s", "jiu");
			break;
		}

		if (i)
			printf(" ");
	}
	printf("\n");
	

	return 0;
}





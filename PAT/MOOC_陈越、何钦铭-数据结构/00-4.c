/*

中国大学MOOC-陈越、何钦铭-数据结构基础习题集


00-自测4. Have Fun with Numbers (20)


Notice that the number 123456789 is a 9-digit number consisting exactly the 
numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, 
which happens to be another 9-digit number consisting exactly the numbers from 
1 to 9, only in a different permutation. Check to see the result if we double 
it again!

(duplication - 重复; permutation - 排列)

Now you are suppose to check if there are more numbers with this property. 
That is, double a given number with k digits, you are to tell if the resulting 
number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer 
with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number 
gives a number that consists of only a permutation of the digits in the original
number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798

--------------------------------------------------------------------------------


20位的整数unsigned long long都存不了，用double存精度会丢失。
用数组存20位数，然后每位乘2





*/

#include <stdio.h>
#include <string.h>

void mul(int n[], int len);
void print(int n[], int len);
void compute(int n[], int len, int a[]);
int compare(int a[], int b[]);

int
main(int argc, char *argv[])
{
	int i, j;
	int num[21], old[10], new[10];
	char s[100];

	memset(old, 0, sizeof(old));
	memset(new, 0, sizeof(new));
	memset(num, 0, sizeof(num));
	memset(s, 0, sizeof(s));

	/* get the number, and then copy to the array */
	fgets(s, sizeof(s), stdin);
	s[strlen(s) - 1] = '\0';

	for (i = 20, j = strlen(s) - 1; i >= 0 && j >= 0; --i, --j)
		num[i] = s[j] - '0';


	compute(num, 21, old);
	mul(num, 21);
	compute(num, 21, new);

	//for (i = 0; i < 10; ++i)
	//	printf("old[%d] = %d\n", i, old[i]);
	//printf("\n");
	//for (i = 0; i < 10; ++i)
	//	printf("new[%d] = %d\n", i, new[i]);
	//printf("\n");

	if (compare(old, new))
		printf("Yes\n");
	else
		printf("No\n");
	print(num, 21);
	printf("\n");


	return 0;
}

/*
 *
 */
void
mul(int n[], int len)
{
	int i, res, carry;

	//printf("ori = ");
	//for (i = 0; i < len; ++i)
	//	printf("%d", n[i]);
	//printf("\n");

	carry = res = 0;
	for (i = len - 1; i >= 0; --i) {
		res = n[i] * 2;
		//printf("res[%d] = %d\n", i, res);
		if (res > 9) {
			res -= 10;
			n[i] = res + carry;
			carry = 1;
		} else {
			n[i] = res + carry;
			carry = 0;
		}
	}

	//printf("res = ");
	//for (i = 0; i < len; ++i)
	//	printf("%d", n[i]);
	//printf("\n");
}

/*
 *
 */
void
print(int n[], int len)
{
	int i, start;

	start = 0;
	for (i = 0; i < len; ++i) {
		if (start == 0 && n[i] == 0)
			continue;
		start = 1;
		printf("%d", n[i]);
	}
}

/*
 * a[0] --> 0
 * ...
 * a[9] --> 9
 */
void
compute(int n[], int len, int a[])
{
	int i, start;

	start = 0;
	for (i = 0; i < len; ++i) {
		if (start == 0 && n[i] == 0)
			continue;
		start = 1;
		a[n[i]] += 1;
	}
}


/*
 *
 */
int
compare(int a[], int b[])
{
	int i;
	for (i = 0; i < 10; ++i) {
		if (a[i] != b[i])
			return 0;
	}

	return 1;
}





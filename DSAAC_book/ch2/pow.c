/*
 * 用递归实现幂
 */

int
iseven(int n)
{
	if (n % 2 == 0)
		return 1;
	else
		return 0;
}

long int
pow(long int x, unsigned int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	if (iseven(n))
		return pow(x * x, n / 2);
	else
		return pow(x * x, n / 2) * x;
}


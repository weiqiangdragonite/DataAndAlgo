/*
 * O(log N)
 * 求最大公约数
 */

unsigned int
gcd(unsigned int m, unsigned int n)
{
	unsigned int rem;

	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;
}
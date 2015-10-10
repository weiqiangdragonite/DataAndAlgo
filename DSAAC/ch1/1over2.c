/*
 * compute
 *
 *  1    1     1     1     1           1
 *  - + --- + --- + --- + --- + ... + --- = ?
 *  2   2^2   2^3   2^4   2^5         2^N
 *
 *
 * numerator
 * ----------
 * denominator
 */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	int i, N;
	double sum;


	N = 10;
	i = 0;
	sum = 0;
	while (i <= N)
		sum += 1.0 / (2 << i++);

	printf("sum = %f\n", sum);

	return 0;
}



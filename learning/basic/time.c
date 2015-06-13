/*
 *
 */

#include <stdio.h>
#include <time.h>

clock_t start, stop;
double duration;


int
main(int argc, char *argv[])
{
	start = clock();
	printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
	stop = clock();
	duration = (double) (stop - start) / CLOCKS_PER_SEC;

	return 0;
}
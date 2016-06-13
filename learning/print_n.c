/*
 *
 */

#include <stdio.h>

void for_print(int n);
void recursion_print(int n);

int
main(int argc, char *argv[])
{
	int i, n;

	printf("Which function do u want to use:\n");
	printf("1 - for\n");
	printf("2 - recursion\n");
	printf(">>> ");

	scanf("%d", &i);

	printf("\nPlease input the N:\n>>> ");
	scanf("%d", &n);
	printf("\n");

	if (i == 1)
		for_print(n);
	else if (i == 2)
		recursion_print(n);

	return 0;
}

void
for_print(int n)
{
	int i;
	for (i = 1; i <= n; ++i)
		printf("%d\n", i);
}

void
recursion_print(int n)
{
	if (n > 0) {
		recursion_print(n - 1);
		printf("%d\n", n);
	}
}


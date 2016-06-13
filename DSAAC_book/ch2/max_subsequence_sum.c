/*
 * Max subsequence sum problem from chapter 2.
 *

{ -2, 11, -4, 13, -5, -2 }

subsequence:
{ -2 } -> -2
{ -2, 11 } -> 9
{ -2, 11, -4 } -> 5
{ -2, 11, -4, 13 } -> 18
{ -2, 11, -4, 13, -5 } -> 13
{ -2, 11, -4, 13, -5, -2 } -> 11

{ 11 } -> 11
{ 11, -4 } -> 7
{ 11, -4, 13 } -> 20
{ 11, -4, 13, -5 } -> 15
{ 11, -4, 13, -5, -2 } -> 13

{ -4 } -> -4
{ -4, 13 } -> 9
{ -4, 13, -5 } -> 4
{ -4, 13, -5, -2 } -> 2

{ 13 } -> 13
{ 13, -5 } -> 8
{ 13, -5, -2 } -> 6

{ -5 } -> -5
{ -5, -2 } -> -7

{ -2 } -> -2
 */


/*
 * algorithm 1: O(n^3)
 */
int
max_subsequence_sum_v1(const int a[], int n)
{
	int this_sum, max_sum, i, j, k;

	max_sum = 0;
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			this_sum = 0;
			for (k = i; k <= j; ++k)
				this_sum += a[k];

			if (this_sum > max_sum)
				max_sum = this_sum;
		}
	}
	return max_sum;
}

/*
 * algorithm 2: O(n^2)
 */
int
max_subsequence_sum_v2(const int a[], int n)
{
	int this_sum, max_sum, i, j;

	max_sum = 0;
	for (i = 0; i < n; ++i) {
		this_sum = 0;
		for (j = i; j < n; ++j) {
			this_sum += a[j];

			if (this_sum > max_sum)
				max_sum = this_sum;
		}
	}
	return max_sum;
}



static int
max3(int a, int b, int c)
{
	if (a > b)
		return (a > c ? a : c);
	else
		return (b > c ? b : c);
}

/*
 * resursive
 */
static int
max_sub_sum(const int a[], int left, int right)
{

	/* base case */
	if (left == right)
		return (a[left] > 0 ? a[left] : 0);

	center = (left + right) / 2;
	max_left_sum = max_sub_sum(a, left, center);
	max_right_sum = max_sub_sum(a, center + 1, right);

	max_left_border_sum = left_border_sum = 0;
	for (i = center; i >= left; --i) {
		left_border_sum += a[i];
		if (left_border_sum > max_left_border_sum)
			max_left_border_sum = left_border_sum;
	}

	max_right_border_sum = right_border_sum = 0;
	for (i = center + 1; i <= right; ++i) {
		right_border_sum += a[i];
		if (right_border_sum > max_right_border_sum)
			max_right_border_sum = right_border_sum;
	}

	return max3(max_left_sum, max_right_sum,
		max_left_border_sum + max_right_border_sum);
}


/*
 * algorithm 3: divide-and-conquer, O(nlogn)
 */
int
max_subsequence_sum_v3(const int a[], int n)
{
	return max_sub_sum(a, 0, n - 1);
}



/*
 * algorithm 4: online algorithm, O(N)
 */
int
max_subsequence_sum_v4(const int a[], int n)
{
	int this_sum, max_sum, i;

	this_sum = max_sum = 0;
	for (i = 0; i < n; ++i) {
		this_sum += a[i];

		if (this_sum > max_sum)
			max_sum = this_sum;
		else if (this_sum < 0)
			this_sum = 0;
	}
	return max_sum;
}




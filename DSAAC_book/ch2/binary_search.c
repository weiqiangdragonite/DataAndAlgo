/*
 * binary search from chapter 2
 * O(log N)
 */

int
binary_search(const int a[], int x, int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] < x)
			low = mid + 1;
		else if (a[mix] > x)
			high = mid - 1;
		else
			return mid;	/* found */
	}
}


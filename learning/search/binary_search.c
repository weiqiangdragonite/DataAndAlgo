/*
 * 折半查找
 */


/*
 * 数组从0开始存起
 * 若找到，返回关键字的位置，否则返回-1
 */
int
binary_search(int a[], int n, int key)
{
	int low, high, mid;

	low = 0;	/* low = 1; 数组从1开始 */
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
		else if (key == a[mid])
			return mid;
	}

	return -1;
}
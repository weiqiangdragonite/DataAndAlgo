/*
 * 顺序查找
 */


/*
 * 适用于数组a从0开始存数据的
 * a为数组，n为数组长度，key为要查找的关键字
 */
int
seq_search_v1(int a[], int n, int key)
{
	int i;
	for (i = 0; i < n; ++i) {
		if (a[i] == key)
			return i;
	}
	return -1;
}

/*
 * 适用于数组a从a[1]开始存数据的，且a[0]没有用作其它用途的
 * a为数组，n为数组长度，key为要查找的关键字
 */
int
seq_search_v2(int a[], int n, int key)
{
	int n;

	a[0] = key;
	i = n;
	while (a[i] != key)
		--i;

	return i;
}











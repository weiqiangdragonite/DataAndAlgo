/*
 * 基数排序
 */




void
radix_sort(const int A[], const int N, const int M)
{
	int i;
	int bucket[M];

	memset(count, 0, sizeof(count));
	for (i = 0; i < N; ++i)
		count[A[i]] += 1;
}

void
print(const int count[], const int M)
{

}


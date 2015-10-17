/*
 * 桶式排序
 */




void
bucket_sort(const int A[], const int N, const int M)
{
	int i;
	int count[M];

	memset(count, 0, sizeof(count));
	for (i = 0; i < N; ++i)
		count[A[i]] += 1;
}

void
print(const int count[], const int M)
{
	for (i = 0; i < M; ++i) {
		if (count[i])
			printf("%d", count[i]);
	}
}


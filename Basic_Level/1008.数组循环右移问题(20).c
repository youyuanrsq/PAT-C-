#include<stdio.h>

/* 数组右移问题在不借助其他数组的情况下可以通过多次反转数组元素来实现 */
// get it!

void Reverse_d(int A[], int left, int right);
int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	int A[N];
	int i;

	for (i = 0; i < N; i++)
		A[i] = 0;
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	if (M != 0 && M != N) {
		if (M > N)
			M = M - N;
		Reverse_d(A, 0, N);
		Reverse_d(A, 0, M);
		Reverse_d(A, M, N);
	}
	for (i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}

void Reverse_d(int A[], int left, int right)
{
	int i, j, t;

	for (i = left, j = right-1; i < j; i++, j--) {
		t = A[i];
		A[i] = A[j];
		A[j] = t;
	}
}


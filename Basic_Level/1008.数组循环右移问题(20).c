
1008. 数组元素循环右移问题 (20)
一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个
位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）
（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动
的方法？
输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数,
之间用空格分隔。
输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
输入样例：
6 2
1 2 3 4 5 6
输出样例：
5 6 1 2 3 4

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


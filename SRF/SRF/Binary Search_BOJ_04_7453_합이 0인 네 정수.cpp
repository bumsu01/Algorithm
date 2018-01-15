#define _CRT_SECURE_NO_WARNINGS
#define SUM(x,y) ((x) + (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define SWAP(x,y,type) do{type tmp=x; x=y; y=tmp;}while(0)

#include <stdio.h>
#include <malloc.h>

const int inf = 4000;

int N, M;
int AB[inf * inf + 1], CD[inf * inf + 1];
int A[inf + 1], B[inf + 1], C[inf + 1], D[inf + 1];

void merge(int len)
{
	M = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			AB[M] = A[i] + B[j];
			M++;
		}
	M = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			CD[M] = C[i] + D[j];
			M++;
		}
}

void qSort(int *arr, int left, int right)
{
	if (left > right) return;

	int L = left, R = right;
	int pivot = arr[(L + R) / 2];

	while (L <= R)
	{
		while (arr[L] < pivot) L++;
		while (pivot < arr[R]) R--;

		if (L <= R)
		{
			SWAP(arr[L], arr[R], int);
			L++; R--;
		}
	}
	if (left < R) qSort(arr, left, R);
	if (L < right) qSort(arr, L, right);
}

long long zeroSearch()
{
	long long ret = 0;
	long long ab_cnt, cd_cnt;

	for (int i = 0; i < M;)
	{
		for (int j = M - 1; j >= 0;)
		{
			if (AB[i] + CD[j] < 0) i++;
			else if (AB[i] + CD[j] > 0) j--;
			else
			{
				ab_cnt = cd_cnt = 0;
				while (i + ab_cnt < M && AB[i] == AB[i + ab_cnt]) ab_cnt++;
				while (j - cd_cnt >= 0 && CD[j] == CD[j - cd_cnt]) cd_cnt++;

				ret += (ab_cnt * cd_cnt);
				i += ab_cnt;
				j -= cd_cnt;
			}
			if (i >= M) return ret;
		}
		return ret;
	}

	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);

	merge(N);
	qSort(AB, 0, M - 1);
	qSort(CD, 0, M - 1);

	printf("%ld\n", zeroSearch());

	return 0;
}
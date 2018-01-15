#define _CRT_SECURE_NO_WARNINGS

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define SWAP(x,y,type) do{type t=x;x=y;y=t;}while(0)
#define CUTCOUNT(x, y) ((x) / (y))

#include <stdio.h>
#include <malloc.h>

const int inf = 10000;

int K, N, LAN[inf + 1];
int max;

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

int cutting(int *arr, long long len)
{
	int sum = 0;
	for (int i = 0; i < K; i++)
		sum += CUTCOUNT(arr[i], len);
	return sum;
}

long long bSearch(int *arr, int target)
{
	long long L = 0, mid, R = max;

	while (L < R)
	{
		mid = (L + R) / 2;
		if (mid == 0) break;

		if (cutting(arr, mid) < target) R = mid - 1;
		else L = mid + 1;
	}
	if (mid == 0) L = R = mid = 1;

	if (cutting(arr, L) >= target && cutting(arr, R) >= target) return L;
	else if (cutting(arr, L) >= target) return L;
	else if (cutting(arr, R) >= target) return R;
	else return R - 1;
	// 특이 예제 적어놓기
}

int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &LAN[i]);
		max = MAX(max, LAN[i]);
	}

	qSort(LAN, 0, K - 1);

	printf("%ld\n", bSearch(LAN, N));

	return 0;
}
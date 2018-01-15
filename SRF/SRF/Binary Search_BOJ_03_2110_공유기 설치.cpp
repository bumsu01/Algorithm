#define _CRT_SECURE_NO_WARNINGS

#define SWAP(x,y,type) do{type t=x;x=y;y=t;}while(0)
#define MAX(x,y) ((x) > (y) ? (x):(y))
#define MIN(x,y) ((x) < (y) ? (x):(y))

#include <stdio.h>
#include <malloc.h>

const int inf = 200000;

int N, C, maxHouse, diff;
long long house[inf + 1];
long long L, R, mid;

void findMaximum()
{
	for (int i = 0; i < N; i++)
		maxHouse = MAX(maxHouse, house[i]);
}

int installWIFI(long long *arr, int len)
{
	int prev = arr[0], cnt = 1;

	diff = maxHouse;
	for (int i = 1; i < N; i++)
	{
		if (prev + len > arr[i]) continue;
		diff = MIN(diff, arr[i] - prev);
		prev = arr[i];
		cnt++;
	}
	return cnt;
}

void qSort(long long *arr, int left, int right)
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

int bSearch(long long *arr, int target)
{
	int ret = 0, tmp;
	L = 1; R = maxHouse;

	while (L <= R)
	{
		mid = (L + R) / 2;
		if (R == 0) break;

		tmp = installWIFI(arr, mid);
		if (tmp < target) R = mid - 1;
		else
		{
			L = mid + 1;
			ret = MAX(ret, diff);
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%d", &house[i]);

	findMaximum();
	qSort(house, 0, N - 1);

	printf("%d", bSearch(house, C));

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SWAP(x,y,type) do{type tmp=x; x=y; y=tmp;}while(0)

const bool qCmp(int *a, int *b)
{
	if (a[0] < b[0]) return true;
	else if (a[0] == b[0])
	{
		if (a[1] < b[1]) return true;
		else return false;
	}
	else false;
	//return a < b ? true : false;
}
const void qSwap(int *a, int *b)
{
	SWAP(a[0], b[0], int);
	SWAP(a[1], b[1], int);
}

void qSort(int arr[5][2], int left, int right)
{
	if (left > right) return;

	int L = left, R = right;

	int *pivot = arr[(L + R) / 2];

	while (L <= R)
	{
		while (qCmp(arr[L], pivot)) L++;
		while (qCmp(pivot, arr[R])) R--;

		if (L <= R)
		{
			qSwap(arr[L], arr[R]);
			L++;
			R--;
		}
	}

	if (left < R) qSort(arr, left, R);
	if (L < right) qSort(arr, L, right);
}

int main()
{
	int arr1[5] = { 1,3,2,4,5 };
	int arr2[5][2] = { { 1,2 },{ 3,5 },{ 2,1 },{ 3,4 },{ 1,3 } };

	//qSort(arr1, 0, 4);
	qSort(arr2, 0, 4);

	for (int i = 0; i < 5; i++)
		printf("%d ", arr1[i]);
	printf("\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++)
			printf("%d ", arr2[i][j]);
		printf("\n");
	}

	return 0;
}
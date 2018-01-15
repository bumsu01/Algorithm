#define _CRT_SECURE_NO_WARNINGS
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define SWAP(x,y,type) do{type tmp=x; x=y; y=tmp;}while(0)

#include <stdio.h>
#include <malloc.h>

const int inf = 1000000;
long long getTree;
int N, M, tree[inf + 1];
int max = 0;

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
			L++;
			R--;
		}
	}

	if (left < R) qSort(arr, left, R);
	if (L < right) qSort(arr, L, right);
}

int bSearch(int arr[inf + 1], int start, int end, int wannaTree)
{
	int mid, loop;

	while (getTree != wannaTree && start <= end)
	{
		getTree = 0;
		mid = (start + end) / 2;
		loop = N - 1;

		while (loop >= 0 && mid <= arr[loop])
			getTree = getTree + (arr[loop--] - mid);

		if (getTree < wannaTree) end = mid - 1;
		else if (getTree > wannaTree) start = mid +1;
	}  
	if (getTree < wannaTree) return MIN(start, end);
	else return mid;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tree[i]);
		max = MAX(max, tree[i]);
	}

	qSort(tree, 0, N - 1);

	printf("%d\n", bSearch(tree, 0, max, M));

	return 0;
}
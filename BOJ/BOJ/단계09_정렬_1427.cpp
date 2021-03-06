#define _CRT_SECURE_NO_WARNINGS
#define MAXN 10
#include <stdio.h>
#include <malloc.h>

char N[MAXN + 1];
int heap[MAXN + 1];
int hCnt = 1;

void swapHeap(int *aNum, int *bNum)
{
	int tmp = *aNum;
	*aNum = *bNum;
	*bNum = tmp;
}

bool heapCmp(int aNum, int bNum)
{
	return (aNum >= bNum);
}

void insertHeap(int num)
{
	heap[hCnt] = num;
	int cur = hCnt;
	int parent = cur / 2;
	while (cur > 1)
	{
		if (heapCmp(heap[cur], heap[parent]))
			swapHeap(&heap[cur], &heap[parent]);
		else break;
		cur = parent;
		parent = cur / 2;
	}
	hCnt++;
}

void popHeap()
{
	hCnt--;
	printf("%d", heap[1]);
	swapHeap(&heap[1], &heap[hCnt]);
	heap[hCnt] = 9999;

	int cur = 1;
	int child = cur * 2;
	while (child < hCnt)
	{
		if (heap[child + 1] == 9999) {
			if (heapCmp(heap[child], heap[cur]))
				swapHeap(&heap[child], &heap[cur]);
			else break;
			cur = child;
			child = cur * 2;
		}
		else {
			if (heapCmp(heap[child + 1], heap[cur]) && heapCmp(heap[child + 1], heap[child])) {
				swapHeap(&heap[child + 1], &heap[cur]);
				cur = child + 1;
				child = cur * 2;
			}
			else if (heapCmp(heap[child], heap[cur]) && heapCmp(heap[child], heap[child + 1])) {
				swapHeap(&heap[child], &heap[cur]);
				cur = child;
				child = cur * 2;
			}
			else break;
		}
	}
}

int main()
{
	scanf("%s", N);
	for (int i = 0; N[i]; i++)
		insertHeap(N[i] - '0');

	while (hCnt > 1)
		popHeap();
	printf("\n");

	return 0;
}
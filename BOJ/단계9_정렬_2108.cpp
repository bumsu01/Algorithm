#define _CRT_SECURE_NO_WARNINGS
#define MAXN 500000
#define MID 4000
#include <stdio.h>
#include <malloc.h>

// printf("%.0lf\n", (double)sum / N);
// 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
// 라는 문제는 %d 를 출력하면 안된다. (입력 정수값이 음수일 경우)
// 이상한 값이 들어가게 된다.
// Heap 정렬을 할때 heapCmp 에서 = 등호를 잘 넣어줘야한다.
// 문제의 조건에 따라, 같은 값이 나올 수 있는 경우 무조건 = 를 넣을수 있도록 신경쓰자.
// 겹치는것이 없으면 = 는 생략가능.
// 보통 Heap 소트는 == 일경우 예외처리.

int N, number;
int heap[MAXN + 1];
int countSort[MID * 2 + 1];
int hCnt = 1, cnt;
int min, middle, max, maxCnt;
long long sum;

bool minmaxFlag = false;

void swapHeap(int *aNum, int *bNum)
{
	int tmp = *aNum;
	*aNum = *bNum;
	*bNum = tmp;
}

bool heapCmp(int aNum, int bNum)
{
	return (aNum <= bNum);
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

void insertCount(int num)
{
	num += 4000;
	countSort[num]++;
}

void popHeap()
{
	hCnt--;
	if (!minmaxFlag) min = heap[1];
	if (hCnt == 1) max = heap[1];
	if (cnt == (N + 1) / 2) middle = heap[1];
	minmaxFlag = true;
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
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number);
		insertHeap(number);
		insertCount(number);
		sum += number;
	}

	for (int i = 0; i < MID * 2 + 1; i++)
		if (maxCnt < countSort[i])
			maxCnt = countSort[i];

	int Flag = -9999999;
	for (int i = 0; i < MID * 2 + 1; i++) {
		if (maxCnt == countSort[i])
		{
			if (Flag != -9999999) {
				Flag = i - MID;
				break;
			}
			Flag = i - MID;
		}
	}
	maxCnt = Flag;

	while (hCnt > 1)
	{
		cnt++;
		popHeap();
	}

	printf("%.0lf\n", (double)sum / N);
	printf("%d\n", middle);
	printf("%d\n", maxCnt);
	printf("%d\n", max - min);

	return 0;
}
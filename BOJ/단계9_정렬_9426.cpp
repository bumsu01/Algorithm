#define _CRT_SECURE_NO_WARNINGS
#define MAXN 65535
#include <stdio.h>
#include <malloc.h>

// 처음 아이디어 -> Heap.
// But, 불가능.. 시간 초과
// AVL Tree 구현.. (일반 BT로 구현 해본 후 시간 초과 -> AVL)
// 시간이 꽤 걸린다 --- 빨리 구현하도록!
// 세그먼트 트리!!!! -> 리프 노드는 N ~ N+N 까지 로 각 데이터 세팅
// 부모는 그 자식의 횟수의 합을 가지고 있는다.
// 세그먼트 트리 (유용함) -> 개념은 Counting Sort + Heap(바이너리 완전 트리)

int N, K, number[250001];
int Segment[MAXN + MAXN + 2];
long long sum = 0;

void insertTree(int num)
{
	Segment[MAXN + 1 + num]++;
	int cur = MAXN + 1 + num;
	int parent = cur / 2;
	while (cur > 1)
	{
		Segment[parent] = Segment[parent * 2] + Segment[parent * 2 + 1];
		cur = parent;
		parent = cur / 2;
	}
}

void delTree(int num)
{
	Segment[MAXN + 1 + num]--;
	int cur = MAXN + 1 + num;
	int parent = cur / 2;
	while (cur > 1)
	{
		Segment[parent] = Segment[parent * 2] + Segment[parent * 2 + 1];
		cur = parent;
		parent = cur / 2;
	}
}

int findMid(int index)
{
	int cur = 1;
	int child = cur * 2;
	while (child < MAXN + MAXN + 2)
	{
		if (Segment[child] < index) {
			index -= Segment[child];
			cur = child + 1;
		}
		else if (Segment[child] >= index)
			cur = child;
		child = cur * 2;
	}
	return cur - (MAXN + 1);
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &number[i]);

	for (int i = 0; i < K; i++)
		insertTree(number[i]);
	sum += findMid((K + 1) / 2);

	for (int i = K; i < N; i++)
	{
		delTree(number[i - K]);
		insertTree(number[i]);
		sum += findMid((K + 1) / 2);
	}

	printf("%lld\n", sum);

	return 0;
}
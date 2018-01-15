#define _CRT_SECURE_NO_WARNINGS
#define MAX(x,y) ((x) > (y) ? (x):(y))
#define SWAP(x,y,type) do{type tmp = x; x=y; y=tmp;}while(0)
#define MAX_MAP 25
#define MAX_ANS 625

// 오른쪽, 아래, 왼쪽, 위로 -> 그래프 탐색 시

#include <stdio.h>
#include <malloc.h>

int answer[MAX_ANS + 1], ansCnt;

class DATA {
public:
	int x, y;
};
class Queue {
	class Node {
	public:
		DATA data;
		Node *next;
		Node(int dx, int dy) {
			data.x = dx; data.y = dy;
		}
	};
public:
	Node *front = 0, *rear = 0;
	int size = 0;

	void push(int x, int y)	{
		Node *newNode = new Node(x, y);
		if (size == 0)
			front = rear = newNode;
		else {
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}
	void pop() {
		size--;
		Node *delNode = front;
		front = front->next;
		delete delNode;
	}
	DATA getFront() { return front->data; }
	DATA getRear() { return rear->data; }
	int getSize() { return size; }
	bool empty() { return size == 0; }
	void clear() {
		while (size) {
			Node *delNode = front;
			front = front->next;
			size--;
			delete delNode;
		}
	}
};

void qSort(int arr[MAX_ANS], int left, int right)
{
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
void _bfs(int arr[MAX_MAP + 1][MAX_MAP + 1], int N)
{
	bool visit[MAX_MAP + 1][MAX_MAP + 1] = { false };
	int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 }, cnt;
	register int i, j, d;
	DATA qData;
	Queue bQueue;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (!visit[i][j] && arr[i][j] != 0)
			{
				cnt = 1;
				bQueue.push(i, j);
				visit[i][j] = true;
				while (bQueue.empty() == false)
				{
					qData = bQueue.getFront();
					bQueue.pop();
					for (d = 0; d < 4; d++)
						if (0 <= qData.x + dx[d] && qData.x + dx[d] < N && 0 <= qData.y + dy[d] && qData.y + dy[d] < N)
							if (!visit[qData.x + dx[d]][qData.y + dy[d]] && arr[qData.x + dx[d]][qData.y + dy[d]] != 0)
							{
								cnt++;
								bQueue.push(qData.x + dx[d], qData.y + dy[d]);
								visit[qData.x + dx[d]][qData.y + dy[d]] = true;
							}
				}
				answer[ansCnt++] = cnt;
			}
		}
	}
}

int main()
{
	register int i, j;
	int map[MAX_MAP + 1][MAX_MAP + 1];
	int N;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	_bfs(map, N);
	qSort(answer, 0, ansCnt - 1);

	printf("%d\n", ansCnt);
	for (i = 0; i < ansCnt; i++)
		printf("%d\n", answer[i]);

	return 0;
}
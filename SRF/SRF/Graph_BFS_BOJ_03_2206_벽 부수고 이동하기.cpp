#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000

#include <stdio.h>
#include <malloc.h>

typedef struct DATA {
	int x, y;
};

typedef struct NODE {
	DATA data;
	NODE *next;
	NODE(int x, int y) {
		data.x = x;
		data.y = y;
		next = NULL;
	}
}node;

class queue {
	node *front = NULL;
	node *rear = NULL;
public:
	int size = 0;

	void enQueue(int x, int y) {
		node *newNode = new node(x, y);
		if (front == NULL)
			front = rear = newNode;
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}

	DATA deQueue() {
		DATA ret = front->data;

		if (front == rear) {
			delete front;
			front = rear = NULL;
		}
		else {
			node *delNode = front;
			front = front->next;
			delete delNode;
		}
		size--;
		return ret;
	}
};

int N, M, map[MAXN + 1][MAXN + 1];
int distArr[MAXN + 1][MAXN + 1][2];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int answer = -1;

queue blockQueue; // blockQueue is what has block(1)
queue loadQueue; // loadQueue is what has load(0)
DATA qData; // queue output

void updateToBFS(int x, int y, int standard)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M)
		{
			if (distArr[x + dx[i]][y + dy[i]][standard] == 0)
			{
				if (map[x + dx[i]][y + dy[i]] == 0)
				{
					loadQueue.enQueue(x + dx[i], y + dy[i]);
					distArr[x + dx[i]][y + dy[i]][standard] = distArr[x][y][standard] + 1;
				}
				else blockQueue.enQueue(x + dx[i], y + dy[i]);
			}
		}
	}
	if (loadQueue.size == 0) return;
	else {
		qData = loadQueue.deQueue();
		updateToBFS(qData.x, qData.y, standard);
	}
}

int solve()
{
	int minA, minB;
	int ret = MAXN * MAXN;

	while (blockQueue.size > 0)
	{
		qData = blockQueue.deQueue();

		minA = minB = MAXN * MAXN;
		for (int i = 0; i < 4; i++)
		{
			if (qData.x + dx[i] >= 0 && qData.x + dx[i] < N && qData.y + dy[i] >= 0 && qData.y + dy[i] < M)
			{
				if (distArr[qData.x + dx[i]][qData.y + dy[i]][0] != 0)
					if (minA > distArr[qData.x + dx[i]][qData.y + dy[i]][0])
						minA = distArr[qData.x + dx[i]][qData.y + dy[i]][0];
				if (distArr[qData.x + dx[i]][qData.y + dy[i]][1] != 0)
					if (minB > distArr[qData.x + dx[i]][qData.y + dy[i]][1])
						minB = distArr[qData.x + dx[i]][qData.y + dy[i]][1];
			}
		}
		if (minA != MAXN * MAXN && minB != MAXN * MAXN)
			if (minA + minB < ret)
				ret = minA + minB;
	}

	ret += 1;
	if (ret == MAXN * MAXN + 1 && distArr[N - 1][M - 1][0] == 0) return -1;
	else if (ret != MAXN * MAXN + 1 && distArr[N - 1][M - 1][0] == 0) return ret;
	else if (ret <= distArr[N - 1][M - 1][0]) return ret;
	else if (ret > distArr[N - 1][M - 1][0]) return distArr[N - 1][M - 1][0];
}

void print()
{
	printf("MAP----------------\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}

	printf("\n\nDIST A----------------\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", distArr[i][j][0]);
		printf("\n");
	}

	printf("\n\nDIST B----------------\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", distArr[i][j][1]);
		printf("\n");
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	distArr[0][0][0] = distArr[N - 1][M - 1][1] = 1;

	updateToBFS(0, 0, 0);
	updateToBFS(N - 1, M - 1, 1);

	//print();
	printf("%d\n", solve());

	return 0;
}
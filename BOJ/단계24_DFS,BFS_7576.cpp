#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int x, y;
	Node *next;
} *QUEUE;
QUEUE qBot, qTop, qTmp;

int map[MAXN + 1][MAXN + 1];
int N, M, qx, qy, cnt, day;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void qInsert(int x, int y)
{
	QUEUE NewNode = (QUEUE)malloc(sizeof(Node));
	NewNode->x = x;
	NewNode->y = y;
	NewNode->next = NULL;
	if (qBot == NULL) qBot = qTop = NewNode;
	else {
		qTop->next = NewNode;
		qTop = qTop->next;
	}
}

int qPop()
{
	if (qTop == NULL) return 0;
	else qTmp = qBot;

	qx = qBot->x;
	qy = qBot->y;
	qBot = qBot->next;
	free(qTmp);
	if (qBot == NULL) qTop = NULL;
	return 1;
}

void dayday()
{
	while (qPop())
	{
		cnt = map[qx][qy];
		if (day < cnt) day = cnt;
		for (int i = 0; i < 4; i++)
		{
			if (qx + dx[i] >= 0 && qx + dx[i] < N && qy + dy[i] >= 0 && qy + dy[i] < M)
			{
				if (map[qx + dx[i]][qy + dy[i]] == 0)
				{
					map[qx + dx[i]][qy + dy[i]] = cnt + 1;
					qInsert(qx + dx[i], qy + dy[i]);
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				qInsert(i, j);
		}
	}
	dayday();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0)
				day = -1;

	if (day > 0) printf("%d\n", day - 1);
	else printf("%d\n", day);

	return 0;
}
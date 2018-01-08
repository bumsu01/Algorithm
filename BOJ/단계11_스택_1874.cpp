#define _CRT_SECURE_NO_WARNINGS
#define MAXN 100000
#include <stdio.h>
#include <malloc.h>

// 문제.. 좀 .. 잘 읽자..

char answer[MAXN + MAXN + 1];
int visit[MAXN + 1];
int aCnt, n, number;

typedef struct Node {
	int num;
	Node *prev;
};
Node *sTop;

void pushStack(int num)
{
	if (sTop == NULL) {
		sTop = (Node *)malloc(sizeof(Node));
		sTop->num = num;
		sTop->prev = NULL;
	}
	else {
		Node *New = (Node *)malloc(sizeof(Node));
		New->num = num;
		New->prev = sTop;
		sTop = New;
	}
}

int popStack()
{
	if (sTop == NULL) return -1;
	else {
		int num = sTop->num;
		Node *tmp = sTop;
		sTop = sTop->prev;
		free(tmp); tmp = NULL;
		return num;
	}
}

int topStack()
{
	return sTop->num;
}

int nextVisit(int num)
{
	while (num <= MAXN && visit[num]) num++;
	if (num <= MAXN) visit[num] = 1;
	return num;
}

int main()
{
	int index;
	bool Flag;
	visit[0] = 1;
	pushStack(0);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);

		index = topStack();
		if (index < number) Flag = false;
		if (index > number) Flag = true;
		while (index != number)
		{
			if (Flag) {
				popStack();
				index = topStack();
				answer[aCnt++] = '-';
			}
			else {
				index = nextVisit(index);
				if (index > number) break;
				answer[aCnt++] = '+';
				pushStack(index);
			}
		}
		if (topStack() == number)
		{
			answer[aCnt++] = '-';
			popStack();
		}
		else
		{
			index = -1;
			break;
		}
	}
	if (index == -1) printf("NO\n");
	else {
		for (int i = 0; i < aCnt; i++)
			printf("%c\n", answer[i]);
	}
	return 0;
}


/* 
// 간략한 소스
#define _CRT_SECURE_NO_WARNINGS
#define MAXN 100000
#include <stdio.h>
#include <malloc.h>

char answer[MAXN + MAXN + 1];
int aCnt, n, number;

typedef struct Node {
	int num;
	Node *prev;
};
Node *sTop;

void pushStack(int num)
{
	if (sTop == NULL) {
		sTop = (Node *)malloc(sizeof(Node));
		sTop->num = num;
		sTop->prev = NULL;
	}
	else {
		Node *New = (Node *)malloc(sizeof(Node));
		New->num = num;
		New->prev = sTop;
		sTop = New;
	}
}

int popStack()
{
	int num = sTop->num;
	Node *tmp = sTop;
	sTop = sTop->prev;
	free(tmp); tmp = NULL;
	return num;
}

int topStack()
{
	if (sTop == NULL) return 0;
	else return sTop->num;
}

int main()
{
	int index = 1;
	bool Flag = true;
	pushStack(0);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		if (topStack() && topStack() > number) {
			printf("NO\n");
			return 0;
		}
		for (; index <= number; index++) {
			answer[aCnt++] = '+';
			pushStack(index);
		}
		popStack();
		answer[aCnt++] = '-';
	}

	for (int i = 0; i < aCnt; i++)
		printf("%c\n", answer[i]);
	return 0;
}
*/
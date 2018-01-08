#define _CRT_SECURE_NO_WARNINGS
#define MAXN 50
#include <stdio.h>
#include <malloc.h>

// stack은 prev 링크만 가지고 있으면 된다.
// stack은 *sTop 만 가지고 있으면 된다.

typedef struct Node {
	char str;
	Node *prev;
} Stack;
Stack *sTop;

int N;
char query[MAXN + 1];
bool Flag;

void pushStack(char bind)
{
	Node *New = (Node *)malloc(sizeof(Node));
	New->str = bind;
	New->prev = NULL;

	if (sTop == NULL) sTop = New;
	else {
		New->prev = sTop;
		sTop = New;
	}
}

void popStack()
{
	Node *tmp = sTop->prev;
	free(sTop);
	sTop = tmp;
}

bool emptyStack()
{
	if (sTop == NULL) return true;
	else return false;
}

void Init()
{
	Node *tmp;
	while (sTop != NULL)
	{
		tmp = sTop->prev;
		free(sTop);
		sTop = tmp;
	}
	Flag = true;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", query);

		Init();
		for (int j = 0; query[j]; j++)
		{
			if (query[j] == '(') pushStack('(');
			else if (!emptyStack()) popStack();
			else Flag = false;
			if (!Flag) break;
		}
		if (!Flag || !emptyStack()) printf("NO\n");
		else printf("YES\n"); 
	}

	return 0;
}
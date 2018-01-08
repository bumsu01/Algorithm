#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

// ��ũ�� ����Ʈ�� ����ؼ� �����Ҵ��� �� �� ���� �� ��.
// free �� �� or ���õ� ���� ���� ���� ���� �Ҵ��� ���־�� ��밡�� (NULL ���� �ƴϰ� �ʱ� ���� �ƿ� ���� �����Ⱚ)
// �׸��� free�� �� ����, NULL�� ��ü ����� �����ϱ� ���ϴ�.
// �����Ҵ��� ����ϸ� ������ Free�� ���ִ� ������ ������, ���������� �޸� ������ ���ϴ�.(�ǹ�������)

typedef struct Node
{
	int num;
	Node *prev;
	Node *next;
};
Node *sBot, *sTop;

int N;
char query[10];

void pushStack(int num)
{
	if (sBot == NULL) {
		sBot = (Node *)malloc(sizeof(Node));
		sBot->num = num;
		sBot->prev = NULL;
		sBot->next = NULL;
		sTop = sBot;
	}
	else {
		Node *New = (Node *)malloc(sizeof(Node));
		New->num = num;
		New->prev = sTop;
		New->next = NULL;
		sTop->next = New;
		sTop = sTop->next;
	}
}

void popStack()
{
	if (sBot == NULL) printf("-1\n");
	else {
		printf("%d\n", sTop->num);
		Node *tmp = sTop->prev;
		if (tmp == NULL) sTop = sBot = NULL;
		else {
			free(sTop);
			sTop = tmp;
			sTop->next = NULL;
		}
	}
}

void sizeStack()
{
	Node *cur = sBot;
	int cnt = 0;
	while (cur != NULL)
	{
		cnt++;
		cur = cur->next;
	}
	printf("%d\n", cnt);
}

void emptyStack()
{
	if (sBot == NULL) printf("1\n");
	else printf("0\n");
}

void topStack()
{
	if (sBot == NULL) printf("-1\n");
	else printf("%d\n", sTop->num);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", query);
		switch (query[0])
		{
		case 'p':
			if (query[1] == 'u') {
				int number;
				scanf("%d", &number);
				pushStack(number);
			}
			else popStack();
			break;
		case 's':
			sizeStack();
			break;
		case 'e':
			emptyStack();
			break;
		case 't':
			topStack();
			break;
		default:
			break;
		}
	}

	return 0;
}
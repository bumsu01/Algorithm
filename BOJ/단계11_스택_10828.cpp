#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

// 링크드 리스트를 사용해서 동적할당을 할 때 주의 할 점.
// free 한 곳 or 사용시도 조차 되지 않은 곳은 할당을 해주어야 사용가능 (NULL 값도 아니고 초기 값은 아예 없는 쓰래기값)
// 그리고 free를 한 곳은, NULL로 교체 해줘야 구분하기 편하다.
// 동적할당을 사용하면 무조건 Free를 해주는 습관을 가지고, 하지않으면 메모리 누수가 심하다.(실무에서도)

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
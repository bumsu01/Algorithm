#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	Node *prev;
	char text;
	Node *next;
};
Node *head, *cursur, *tail;

int T, cnt;
char query[1000001];

void addNode(char m)
{
	Node *NEW, *temp;
	NEW = (Node *)malloc(sizeof(Node));
	NEW->text = m;

	temp = cursur;
	NEW->next = cursur->next;
	cursur->next->prev = NEW;
	cursur->next = NEW;
	NEW->prev = cursur;
	cursur = NEW;
}

void initNode()
{
	head = (Node *)malloc(sizeof(Node));
	cursur = (Node *)malloc(sizeof(Node));
	tail = (Node *)malloc(sizeof(Node));
	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	tail->next = NULL;
	cursur = head;
	cnt = 0;
}

void printNode()
{
	Node *Now;
	for (Now = head->next; Now != tail; Now = Now->next) {
		printf("%c", Now->text);
		free(Now->prev);
	}
	printf("\n");
}

void eraseNode()
{
	Node *del;
	del = cursur;
	if (cursur != head) {
		cursur = cursur->prev;
		cursur->next = del->next;
		del->next->prev = cursur;
		free(del);
	}
}

int main()
{
	Node *pass;

	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%s", query);
		initNode();
		while (query[cnt] != '\0')
		{
			if (query[cnt] == '<')
			{
				if (cursur->prev != NULL && cursur != head)
					cursur = cursur->prev;
			}
			else if (query[cnt] == '>')
			{
				if (cursur->next != NULL && cursur->next != tail)
					cursur = cursur->next;
			}
			else if (query[cnt] == '-')
			{
				eraseNode();
			}
			else
			{
				addNode(query[cnt]);
			}
			cnt++;
		}
		printNode();
	}


	return 0;
}
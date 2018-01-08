#define _CRT_SECURE_NO_WARNINGS
#define MAXN 100

#include <stdio.h>
#include <malloc.h>

typedef struct DATA {
	int number;
};

typedef struct NODE {
	DATA data;
	NODE *next;
	NODE(int number) {
		data.number = number;
		next = NULL;
	}
}node;

class queue {
	node *front = NULL, *rear = NULL;
public:
	int size = 0;

	void enQueue(int num) {
		node *newNode = new node(num);
		if (front == NULL)
			front = rear = newNode;
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}

	DATA dequeue() {
		DATA ret = front->data;

		if (front == rear) {
			delete front;
			front = rear = NULL;
		}
		else {
			node *delnode = front;
			front = front->next;
			delete delnode;
		}
		size--;
		return ret;
	}

	DATA frontPrint() {
		DATA ret;
		if (front == NULL) ret.number = -1;
		else ret = front->data;

		return ret;
	}
	  
	DATA rearPrint() {
		DATA ret;
		if (rear == NULL) ret.number = -1;
		else ret = rear->data;

		return ret;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);

	char query[10];
	int N, X;
	queue que;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", query);
		switch (query[1]) {
		case 'u':
			scanf("%d", &X);
			que.enQueue(X);
			break;
		case 'o':
			if (que.size == 0) printf("-1\n");
			else printf("%d\n", que.dequeue());
			break;
		case 'i':
			printf("%d\n", que.size);
			break;
		case 'm':
			if (que.size == 0) printf("1\n");
			else printf("0\n");
			break;
		case 'r':
			printf("%d\n", que.frontPrint());
			break;
		case 'a':
			printf("%d\n", que.rearPrint());
			break;
		default:
			break;
		}
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define MAXN 20000
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	char word[51];
	int length;
};
Node *Heap[MAXN + 1];

int N, hCnt = 1;
char string[51];
char before[51];

int _strlen(char *str)
{
	int cnt;
	for (cnt = 0; str[cnt]; cnt++);
	return cnt;
}

int _strcmp(char *aStr, char *bStr)
{
	while (*bStr) {
		if (*aStr != *bStr) break;
		aStr++; bStr++;
	}
	return *aStr - *bStr;
}

void _strcpy(char *aStr, char *bStr) {
	while (*bStr) {
		*aStr = *bStr;
		aStr++; bStr++;
	}
	*aStr = 0;
}

void swapNode(Node *aNode, Node *bNode)
{
	Node tmp = *aNode;
	*aNode = *bNode;
	*bNode = tmp;
}

bool heapCmp(Node *aNode, Node *bNode)
{
	if (aNode->length < bNode->length) return true;
	else if (aNode->length == bNode->length) {
		if (_strcmp(aNode->word, bNode->word) <= 0) return true;
		else return false;
	}
	else return false;
}

void insertHeap(char *str)
{
	Heap[hCnt] = (Node *)malloc(sizeof(Node));
	_strcpy(Heap[hCnt]->word, str);
	Heap[hCnt]->length = _strlen(str);

	int cur = hCnt;
	int parent = cur / 2;
	while (cur > 1)
	{
		if (heapCmp(Heap[cur], Heap[parent]))
			swapNode(Heap[cur], Heap[parent]);
		else break;
		cur = parent;
		parent = cur / 2;
	}
	hCnt++;
}

void popHeap()
{
	hCnt--;
	if (_strcmp(before, Heap[1]->word) != 0)
		printf("%s\n", Heap[1]->word);
	_strcpy(before, Heap[1]->word);
	swapNode(Heap[1], Heap[hCnt]);
	free(Heap[hCnt]);
	Heap[hCnt] = NULL;

	int cur = 1;
	int child = cur * 2;
	while (child < hCnt)
	{
		if (Heap[child + 1] == NULL) {
			if (heapCmp(Heap[child], Heap[cur]))
				swapNode(Heap[child], Heap[cur]);
			else break;
			cur = child;
			child = cur * 2;
		}
		else {
			if (heapCmp(Heap[child], Heap[cur]) && heapCmp(Heap[child], Heap[child + 1])) {
				swapNode(Heap[child], Heap[cur]);
				cur = child;
				child = cur * 2;
			}
			else if (heapCmp(Heap[child + 1], Heap[cur]) && heapCmp(Heap[child + 1], Heap[child])) {
				swapNode(Heap[child + 1], Heap[cur]);
				cur = child + 1;
				child = cur * 2;
			}
			else break;
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", string);
		insertHeap(string);
	}

	while (hCnt > 1)
		popHeap();

	return 0;
}

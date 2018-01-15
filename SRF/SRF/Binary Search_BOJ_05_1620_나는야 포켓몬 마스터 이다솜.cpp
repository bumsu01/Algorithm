#define _CRT_SECURE_NO_WARNINGS
#define MAX(x,y) ((x)>(y)?(x):(y))
#define SWAP(x,y,type) do{type t=x;x=y;y=t;}while(0)
#define nameInf 20
#define arrInf 100000

#include <stdio.h>
#include <malloc.h>

 int _atoi(int num, char *str)
{
	for (; *str; num *= 10) { num += (*str - '0'); str++; }
	return num / 10;
}
const void _strcpy(char *aStr, char *bStr)
{
	while (*bStr) { *aStr = *bStr; aStr++; bStr++; }
	*aStr = '\0';
}
const int _strcmp(char *aStr, char *bStr)
{
	while (*aStr) { if (*aStr != *bStr) break; aStr++; bStr++; }
	return *aStr - *bStr;
}
const bool _qCmp(char *aStr, char *bStr)
{
	if (_strcmp(aStr, bStr) < 0) return true;
	else return false;
}
//Tip 위치 바꾸기 + 전역 변수, 지역 변수 선언 위치 차이로 속도 갈림

typedef struct PocketMon
{
	char name[nameInf + 1];
	int index;
public:
	void cacha(char *monster, int dex)
	{
		_strcpy(name, monster);
		index = dex;
	}
};
PocketMon Book[arrInf + 1];

int N, M;
char origin[arrInf + 1][nameInf + 1];
char query[nameInf + 1];

void Init()
{
	for (int i = 0; i < N; i++)
		Book[i].cacha(origin[i + 1], i + 1);
}

void qSort(int left, int right)
{
	if (left > right) return;

	int L = left, R = right;
	PocketMon pivot;
	pivot.cacha(Book[(L + R) / 2].name, Book[(L + R) / 2].index);

	while (L <= R)
	{
		while (_qCmp(Book[L].name, pivot.name)) L++;
		while (_qCmp(pivot.name, Book[R].name)) R--;

		if (L <= R)
		{
			SWAP(Book[L], Book[R], PocketMon);
			L++; R--;
		}
	}
	if (left < R) qSort(left, R);
	if (L < right) qSort(L, right);
}

int findMonster(char *monster)
{
	int L = 0, R = N - 1;
	int mid = (L + R) / 2;

	while (L <= R)
	{
		mid = (L + R) / 2;
		if (_strcmp(Book[mid].name, monster) > 0) R = mid - 1;
		else
		{
			L = mid + 1;
			if (_strcmp(Book[mid].name, monster) == 0)
				return Book[mid].index;
		}
	}

	return Book[mid].index;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", origin[i + 1]);

	Init();
	qSort(0, N - 1);

	for (int i = 0; i < M; i++)
	{
		scanf("%s", query);
		if ('0' <= query[0] && query[0] <= '9')
			printf("%s\n", origin[_atoi(0, query)]);
		else
			printf("%d\n", findMonster(query));
	}

	return 0;
}
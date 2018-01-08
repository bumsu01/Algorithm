#define _CRT_SECURE_NO_WARNINGS
#define MAXN 10000
#include <stdio.h>
#include <malloc.h>

int countingSort[MAXN + 1];
int N, number;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number);
		countingSort[number]++;
	}

	for (int i = 1; i <= MAXN; i++)
		for (int j = 0; j < countingSort[i]; j++)
			printf("%d\n", i);

	return 0;
}
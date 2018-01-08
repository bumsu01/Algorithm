#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N - i; j++)
			printf(" ");
		for (int j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}
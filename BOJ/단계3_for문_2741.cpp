#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		printf("%d\n", i + 1);

	return 0;
}
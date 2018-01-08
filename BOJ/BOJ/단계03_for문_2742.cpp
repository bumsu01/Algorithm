#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;

int main()
{
	scanf("%d", &N);
	for (int i = N; i >= 1; i--)
		printf("%d\n", i);

	return 0;
}
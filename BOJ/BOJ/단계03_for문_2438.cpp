#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}
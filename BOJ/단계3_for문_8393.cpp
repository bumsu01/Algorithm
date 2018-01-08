#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N, sum;

int main()
{	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		sum += i;
	printf("%d\n", sum);

	return 0;
}
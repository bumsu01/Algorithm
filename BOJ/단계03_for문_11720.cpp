#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;
char text[101];
int sum;

int main()
{
	scanf("%d", &N);
	scanf("%s", text);

	for (int i = 0; i < N; i++)
		sum += text[i] - '0';

	printf("%d\n", sum);

	return 0;
}
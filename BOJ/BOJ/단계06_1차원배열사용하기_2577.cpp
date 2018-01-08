#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int A, B, C;
int numCnt[10];
long long sum;

void getCount(long long parm)
{
	if (parm == 0) return;
	else numCnt[parm % 10]++;
	getCount(parm / 10);
}

int main()
{
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	sum = A * B * C;

	getCount(sum);

	for (int i = 0; i < 10; i++)
		printf("%d\n", numCnt[i]);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int T, k, n;
int apart[15][15];

void setApart()
{
	for (int i = 0; i < 15; i++)
		apart[0][i] = i;
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			int sum = 0;
			for (int k = 1; k <= j; k++)
				sum += apart[i - 1][k];
			apart[i][j] = sum;
		}
	}
}

int main()
{
	setApart();

	scanf("%d", &T);
	for (int testCase = 0; testCase < T; testCase++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", apart[k][n]);
	}

	return 0;
}
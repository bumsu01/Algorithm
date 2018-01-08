#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N, X, tmp;

int main()
{
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		if (tmp < X)
			printf("%d ", tmp);
	}

	return 0;
}
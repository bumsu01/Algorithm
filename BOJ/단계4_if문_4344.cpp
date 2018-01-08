#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int C, N;
double score[1001];
int cnt;
double sum;

int main()
{
	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		scanf("%d", &N);

		cnt = sum = 0;
		for (int j = 0; j < N; j++)
		{
			scanf("%lf", &score[j]);
			sum += score[j];
		}

		for (int j = 0; j < N; j++)
			if (score[j] > sum / N)
				cnt++;

		printf("%.3lf%%\n", cnt / double(N) * 100);
	}

	return 0;
}
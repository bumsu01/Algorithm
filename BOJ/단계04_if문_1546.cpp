#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;
double score[1001];
double sum, max;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &score[i]);
		if (max < score[i])
			max = score[i];
	}

	for (int i = 0; i < N; i++)
	{
		score[i] = score[i] / max * 100;
		sum += score[i];
	}

	printf("%.2lf\n", (double)sum / N);

	return 0;
}
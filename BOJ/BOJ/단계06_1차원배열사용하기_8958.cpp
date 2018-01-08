#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N, sum;
int conScore;
char score;

int main()
{
	scanf("%d\n", &N);
	for (int testCase = 0; testCase < N; testCase++)
	{
		sum = conScore = 0;
		while (scanf("%c", &score) != EOF)
		{
			if (score == '\n') break;
			else if (score == 'O') sum += (++conScore);
			else if (score == 'X') conScore = 0;
		}
		printf("%d\n", sum);
	}

	return 0;
}
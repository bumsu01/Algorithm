#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int sum, score;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score);
		if (score < 40) sum += 40;
		else sum += score;
	}

	printf("%d\n", sum / 5);

	return 0;
}
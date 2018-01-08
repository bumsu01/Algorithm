#define _CRT_SECURE_NO_WARNINGS
#define MAXN 20
#include <stdio.h>
#include <malloc.h>

int T, loopCnt;
char strings[MAXN + 1];

void print(char *str)
{
	while (*str) {
		for (int i=0; i<loopCnt; i++)
			printf("%c", *str);
		str++;
	}
	printf("\n");
}

int main()
{
	scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d %s", &loopCnt, strings);
		print(strings);			
	}

	return 0;
}
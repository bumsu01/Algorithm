#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000000
#include <stdio.h>
#include <malloc.h>

char string[MAXN + 1];
int cnt;

int main()
{
	freopen("input.txt", "r", stdin);
	while (scanf("%s", string) != EOF)
		cnt++;
	printf("%d\n", cnt);

	return 0;
}
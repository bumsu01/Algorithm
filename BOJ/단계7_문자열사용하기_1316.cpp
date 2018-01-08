#define _CRT_SECURE_NO_WARNINGS
#define MAXN 100
#include <stdio.h>
#include <malloc.h>

int N, alpha[30], result;
char strings[MAXN + 1];

void findGroupWord(char *str)
{
	for (int i = 0; i < 30; i++) alpha[i] = 0;
	while (*str)
	{
		if (alpha[*str - 'a'] != 0 && *(str - 1) != *str)
			return;
		if (alpha[*str - 'a'] == 0)
			alpha[*str - 'a'] = 1;
		str++;
	}
	result++;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", strings);
		findGroupWord(strings);
	}
	printf("%d\n", result);

	return 0;
}
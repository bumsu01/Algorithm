#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000
#include <stdio.h>
#include <malloc.h>

char string[MAXN + 1];
int Loc[30];

void getLocation(char *str)
{
	for (int i = 0; i < 30; i++) Loc[i] = -1;
	for (int i = 0; str[i]; i++)
		if (Loc[str[i] - 'a'] == -1)
			Loc[str[i] - 'a'] = i;
}

int main()
{
	scanf("%s", string);
	getLocation(string);

	for (int i = 0; i < 26; i++)
		printf("%d ", Loc[i]);
	printf("\n");

	return 0;
}
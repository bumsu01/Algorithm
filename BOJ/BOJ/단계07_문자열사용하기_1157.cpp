#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000000
#include <stdio.h>
#include <malloc.h>

char strings[MAXN + 1];
int alphaCnt[30];
int result, max;

void getCount(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z') alphaCnt[*str - 'a']++;
		else if (*str >= 'A' && *str <= 'Z') alphaCnt[*str - 'A']++;
		str++;
	}

	for (int i = 0; i < 28; i++)
		if (max < alphaCnt[i]) {
			max = alphaCnt[i];
			result = i;
		}
	
	int Flag = 0;
	for (int i = 0; i < 28; i++)
		if (max == alphaCnt[i])
			Flag++;
	if (Flag != 1)
		result = -1;
}

int main()
{
	scanf("%s", strings);

	getCount(strings);

	if (result != -1) printf("%c\n", 'A' + result);
	else printf("?\n");

	return 0;
}
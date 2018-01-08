#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int num[10];

bool ascend()
{
	for (int i = 1; i <= 8; i++)
		if (num[i] != i) return false;
	return true;
}

bool descend()
{
	for (int i = 1; i <= 8; i++)
		if (num[i] != 9 - i) return false;
	return true;
}

int main()
{
	for (int i = 1; i <= 8; i++)
		scanf("%d", &num[i]);

	if (ascend()) printf("ascending\n");
	else if (descend()) printf("descending\n");
	else printf("mixed\n");

	return 0;
}
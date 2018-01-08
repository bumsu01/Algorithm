#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

char text[101];
int cnt;

int main()
{
	scanf("%s", text);

	while (text[cnt++] != '\0')
	{
		printf("%c", text[cnt - 1]);
		if (cnt % 10 == 0) printf("\n");
	}
	
	return 0;
}
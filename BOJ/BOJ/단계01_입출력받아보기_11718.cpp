#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

char text[101];

int main()
{
	while (fgets(text, 101, stdin) != NULL)
		printf("%s", text);

	return 0;
}
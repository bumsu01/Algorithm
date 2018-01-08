#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;

int main()
{
	scanf("%d", &N);

	if (90 <= N && N <= 100) printf("A");
	else if (80 <= N && N <= 89) printf("B");
	else if (70 <= N && N <= 79) printf("C");
	else if (60 <= N && N <= 69) printf("D");
	else printf("F");
	
	return 0;
}
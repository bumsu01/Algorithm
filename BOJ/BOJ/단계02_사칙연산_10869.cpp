#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int A, B;

int main()
{
	scanf("%d %d", &A, &B);
	
	printf("%d\n", A + B);
	printf("%d\n", A - B);
	printf("%d\n", A * B);
	printf("%d\n", A / B);
	printf("%d\n", A%B);

	return 0;
}
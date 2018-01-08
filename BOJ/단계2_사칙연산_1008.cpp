#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

double A, B;

int main()
{
	scanf("%lf %lf", &A, &B);
	printf("%.9lf", A / B);

	return 0;
}
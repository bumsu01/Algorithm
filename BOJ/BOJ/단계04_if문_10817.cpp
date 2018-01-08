#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int A, B, C;

int main()
{
	scanf("%d %d %d", &A, &B, &C);

	if (A <= B && B <= C) printf("%d\n", B);
	else if (C <= B && B <= A) printf("%d\n", B);
	else if (A <= C && C <= B) printf("%d\n", C);
	else if (B <= C && C <= A) printf("%d\n", C);
	else if (B <= A && A <= C) printf("%d\n", A);
	else if (C <= A && A <= B) printf("%d\n", A);

	return 0;
}
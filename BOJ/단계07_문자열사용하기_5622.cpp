#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

char phoneNumber[20];
int dial[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };

int getTime(char *str) {
	int sum = 0;
	while (*str) {
		sum += dial[*str - 'A'] + 1;
		str++;
	}
	return sum;
}

int main()
{
	scanf("%s", phoneNumber);
	printf("%d\n", getTime(phoneNumber));

	return 0;
}
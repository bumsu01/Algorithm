#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

char roomNumber[10];
int numCount[10];

void setNumCount()
{
	for (int i = 0; i < 10; i++)
		numCount[i] += 1;
	numCount[6]++;
	numCount[9]++;
}

int saleSet(char *str)
{
	int result = 0;

	while (*str) {
		if (numCount[*str - '0'] - 1 < 0) {
			result++;
			setNumCount();
		}
		numCount[*str - '0']--;
		if (*str - '0' == 6) numCount[9]--;
		if (*str - '0' == 9) numCount[6]--;
		str++;
	}

	return result;
}

int main()
{
	scanf("%s", roomNumber);
	printf("%d\n", saleSet(roomNumber));

	return 0;
}
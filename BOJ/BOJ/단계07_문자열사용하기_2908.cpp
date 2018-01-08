#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

char aStr[5], bStr[5];
int aNum, bNum;

void swapStr(char *str)
{
	char tmp[5];
	for (int i = 0; i < 3; i++) tmp[i] = str[i];
	for (int i = 2; i >= 0; i--) str[2 - i] = tmp[i];
}

int strToInt(char *str)
{
	int ret = 0;
	for (int i = 0; str[i]; i++)
		ret = (ret * 10) + (str[i] - '0');
	return ret;
}

int main()
{
	scanf("%s %s", aStr, bStr);

	swapStr(aStr);
	swapStr(bStr);
	aNum = strToInt(aStr);
	bNum = strToInt(bStr);

	if (aNum > bNum) printf("%d\n", aNum);
	else printf("%d\n", bNum);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define MAXN 100
#include <stdio.h>
#include <malloc.h>

char strings[MAXN + 1];
char croatia[8][4] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
int croatiaCnt[8] = { 2,2,3,2,2,2,2,2 };

bool _strcmp(char *aStr, char *bStr)
{
	while (*bStr) {
		if (*aStr != *bStr) break;
		aStr++; bStr++;
	}
	return *aStr - *bStr;
}

int getCroatia(char *str)
{
	int ret = 0;
	char tmp[4];
	bool Flag;

	while (*str) {
		Flag = true;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < croatiaCnt[i]; j++) tmp[j] = *(str + j);
			tmp[croatiaCnt[i]] = 0;
			if (_strcmp(tmp, croatia[i]) == 0) {
				str += croatiaCnt[i];
				Flag = false;
				ret++;
				break;
			}
		}
		if (Flag) { str++; ret++; }
	}
	return ret;
}

int main()
{
	scanf("%s", strings);
	printf("%d\n", getCroatia(strings));

	return 0;
}
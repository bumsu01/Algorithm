#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int arr[10001];

int drKaprekar(int n, int divCnt)
{
	int storage, sum = n;

	for (int i = 1; i <= divCnt; i *= 10)
	{
		storage = n;
		for (int j = 1; j < i; j*= 10)
			storage /=  10;
		sum += (storage % 10);
	}

	return sum;
}

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == 0)
		{
			int flg = 1, tmp = i;
			while (flg <= 10000)
			{
				if (tmp < 10) flg = drKaprekar(tmp, 1);
				else if (10 <= tmp && tmp < 100) flg = drKaprekar(tmp, 10);
				else if (100 <= tmp && tmp < 1000) flg = drKaprekar(tmp, 100);
				else if (1000 <= tmp && tmp < 10000) flg = drKaprekar(tmp, 1000);
				else flg = drKaprekar(tmp, 10000);

				tmp = flg;
				if (flg == i) break;
				else if (flg <= 10000) arr[flg] = 1;
				else break;
			}
		}
	}

	for (int i = 1; i <= 10000; i++)
		if (arr[i] == 0)
			printf("%d\n", i);

	return 0;
}
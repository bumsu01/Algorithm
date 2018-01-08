#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;
int  hansu[1001];

bool findHansu(int n)
{
	int arr[3];

	if (n < 100) return true;
	else {
		for (int i = 0; i < 3; i++)
		{
			int tmp = n;
			for (int j = 0; j < i; j++)
				tmp /= 10;
			arr[i] = tmp % 10;
		}

		if (arr[0] - arr[1] == arr[1] - arr[2]) return true;
		else return false;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i < 1000; i++)
	{
		if (findHansu(i) == true) hansu[i] = hansu[i - 1] + 1;
		else hansu[i] = hansu[i - 1];
	}
	hansu[1000] = hansu[999];

	printf("%d\n", hansu[N]);

	return 0;
}
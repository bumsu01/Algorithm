#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;
int arr[5001];

void InitDp()
{
	arr[3] = arr[5] = 1;

	for (int i = 5; i <= 5000; i++)
	{
		if (arr[i - 3] != 0 && arr[i - 5] != 0)
		{
			if (arr[i - 3] < arr[i - 5])
				arr[i] = arr[i - 3] + 1;
			else arr[i] = arr[i - 5] + 1;
		}
		else if (arr[i - 3] != 0 && arr[i - 5] == 0)
			arr[i] = arr[i - 3] + 1;
		else if (arr[i - 5] != 0 && arr[i - 3] == 0)
			arr[i] = arr[i - 5] + 1;
	}
}

int main()
{
	InitDp();

	scanf("%d", &N);
	
	if (arr[N] == 0)
		printf("%d", -1);
	else
		printf("%d\n", arr[N]);

	return 0;
}
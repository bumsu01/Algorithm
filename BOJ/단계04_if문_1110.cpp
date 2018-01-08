#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;
int original, cycle, cnt;

int main()
{
	scanf("%d", &N);

	original = N;
	while (cycle != original)
	{
		cycle = 0;
		if (N < 10) cycle = N;
		else {
			cycle += N / 10;
			cycle += N % 10;
		}
		cycle %= 10;
		cycle += (N % 10) * 10;

		N = cycle;
		cnt++;
	}

	if (cnt == 0) printf("1\n");
	else printf("%d\n", cnt);

	return 0;
}
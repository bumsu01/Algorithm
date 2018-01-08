#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000
#include <stdio.h>
#include <malloc.h>

int Prime[MAXN + 1];
int cnt, index, N;

void setPrime()
{
	Prime[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (Prime[i] == 0) {
			for (int j = i + i; j <= MAXN; j += i)
				Prime[j] = 1;
		}
	}
}

int main()
{
	setPrime();

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &index);
		if (Prime[index] == 0)
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
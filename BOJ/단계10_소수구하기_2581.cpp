#define _CRT_SECURE_NO_WARNINGS
#define MAXN 10000
#include <stdio.h>
#include <malloc.h>

int Prime[MAXN + 1];
int index, N, M;
int min = -1, sum;

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

	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++)
	{
		if (Prime[i] == 0) {
			if (min == -1) min = i;
			sum += i;
		}
	}
	if (min == -1) printf("-1\n");
	else printf("%d\n%d\n", sum, min);

	return 0;
}
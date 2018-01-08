#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int T, H, W, N;
int cnt;

int main()
{
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; testCase++)
	{
		scanf("%d %d %d", &H, &W, &N);
		cnt = 0;
		for (int i = 1; i <= W; i++) {
			for (int j = 1; j <= H; j++) {
				cnt++;
				if (cnt == N) {
					printf("%d", j);
					if (i < 10) printf("0");
					printf("%d\n", i);
					break;
				}
			}
			if (cnt == N) break;
		}
	}

	return 0;
}
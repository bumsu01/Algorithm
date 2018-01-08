#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000000000
#include <stdio.h>
#include <malloc.h>

long long start[100000], end[100000];
int arrCnt = 1, tmp = 6, N;

void setArray()
{
	start[0] = end[0] = 1;
	start[1] = 2;
	end[1] = 7;

	while (start[arrCnt] < MAXN)
	{
		arrCnt++;
		start[arrCnt] = start[arrCnt - 1] + tmp;
		end[arrCnt] = end[arrCnt - 1] + (tmp + 6);
		tmp += 6;
	}
}

int main()
{
	setArray();

	scanf("%d", &N);
	for (int i = 0; i < arrCnt; i++) {
		if (start[i] <= N && N <= end[i]) {
			printf("%d\n", i + 1);
			break;
		}
	}

	return 0;
}
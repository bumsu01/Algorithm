#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

long long MAXN;
int T, N, M, x, y;
int xYear, yYear;

int getGCD(int x, int y)
{
	if (y == 0) return x;
	return getGCD(y, x % y);
}

int getYear()
{
	int cnt = 0;
	xYear = x; yYear = y;
	while (xYear + N <= MAXN || yYear + M <= MAXN) {
		if (xYear > yYear) yYear += M;
		else if (xYear< yYear) xYear += N;
		else return xYear;
	}
	if (xYear == yYear) return xYear;
	return -1;
}

int main()
{
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; testCase++)
	{
		scanf("%d %d %d %d", &N, &M, &x, &y);
		int gcd = getGCD(N, M);
		MAXN = gcd * (N / gcd) * (M / gcd);
		printf("%d\n", getYear());
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000000
#include <stdio.h>
#include <malloc.h>

// 비트 마스크 를 사용한 최대 필요한 배열의 크기 줄이기.
// int형의 배열은 32bit 이기 때문에 (크기/32) 만큼의 수로 줄일 수 있다.
// 비트마스크 연산자 암기
// 비트마스크인 경우, -1과 ^ 연산자, 그리고 0부터 시작인지 1부터 시작인지 신경 쓸 것.

int N, M;
int prime[(MAXN / 32) + 1];
int deb[32];

int _sqrt(int num)
{
	int cnt = 1;
	while (cnt * cnt <= MAXN)
		cnt++;
	return cnt;
}

void makePrime()
{
	prime[0] = (1 << 1);
	int s = _sqrt(MAXN);

	for (int i = 2; i <= s; i++)
	{
		for (int j = i * i; j <= MAXN; j += i)
		{
			int pCnt = j / 32;
			prime[pCnt] |= (1 << (j % 32));
		}
	}
}

void debug(int n)
{
	for (int i = 0; i < 32; i++) {
		if (n & (1 << i)) deb[i] = 1;
		else deb[i] = 0;
	}
}

int main()
{
	makePrime();

	scanf("%d %d", &N, &M);
	for (int i = N; i <= M; i++)
	{
		int pCnt = i / 32;
		//debug(prime[pCnt]);
		//debug(1 << (i % 32));
		if ((prime[pCnt] & (1 << (i % 32))) == 0)
			printf("%d\n", i);
	}

	return 0;
}
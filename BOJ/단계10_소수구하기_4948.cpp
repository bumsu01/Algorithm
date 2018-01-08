#define _CRT_SECURE_NO_WARNINGS
#define MAXN 300000
#include <stdio.h>
#include <malloc.h>

// ��Ʈ ����ũ �� ����� �ִ� �ʿ��� �迭�� ũ�� ���̱�.
// int���� �迭�� 32bit �̱� ������ (ũ��/32) ��ŭ�� ���� ���� �� �ִ�.
// ��Ʈ����ũ ������ �ϱ�
// ��Ʈ����ũ�� ���, -1�� ^ ������, �׸��� 0���� �������� 1���� �������� �Ű� �� ��.

int n, cnt;
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
		for (int j = i + i; j <= MAXN; j += i)
		{
			int pCnt = j / 32;
			prime[pCnt] |= (1 << (j % 32));
		}
	}
}

int main()
{
	makePrime();

	while (scanf("%d", &n) != EOF)
	{
		if (n == 0) break;
		else cnt = 0;
		for (int i = n + 1; i <= n * 2; i++)
		{
			int pCnt = i / 32;
			if ((prime[pCnt] & (1 << (i % 32))) == 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define MAXN 10000
#include <stdio.h>
#include <malloc.h>

// ��Ʈ ����ũ �� ����� �ִ� �ʿ��� �迭�� ũ�� ���̱�.
// int���� �迭�� 32bit �̱� ������ (ũ��/32) ��ŭ�� ���� ���� �� �ִ�.
// ��Ʈ����ũ ������ �ϱ�
// ��Ʈ����ũ�� ���, -1�� ^ ������, �׸��� 0���� �������� 1���� �������� �Ű� �� ��.

int n, goldbach;
int prime[(MAXN / 32) + 1];
int number[MAXN + 1], nCnt;

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

void InitNum()
{
	for (int i = 0; i < nCnt; i++)
		number[i] = 0;
	nCnt = 0;
}

void findGoldbach(int num)
{
	int aNum = 0, bNum = 0;
	for (int i = 0; i < nCnt; i++)
	{
		for (int j = nCnt - 1; j >= i; j--)
		{
			if (number[i] + number[j] == num)
			{
				if (aNum == 0 && bNum == 0) {
					aNum = number[i];
					bNum = number[j];
				}
				else if (bNum - aNum >= number[j] - number[i])
				{
					aNum = number[i];
					bNum = number[j];
				}
			}
			else if (number[i] + number[j] < num) break;
		}
	}
	printf("%d %d\n", aNum, bNum);
}

int main()
{
	makePrime();

	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &goldbach);

		InitNum();
		for (int i = 2; i <= goldbach; i++)
		{
			int pCnt = i / 32;
			if ((prime[pCnt] & (1 << (i % 32))) == 0)
				number[nCnt++] = i;
		}
		findGoldbach(goldbach);
	}

	return 0;
}
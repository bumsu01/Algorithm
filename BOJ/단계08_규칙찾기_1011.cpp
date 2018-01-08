#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

long long N, start, end;
long long cnt, tmp, result;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld %lld", &start, &end);

		cnt = 1;
		result = 0;
		while (start + cnt < end - cnt) {
			start += cnt;
			end -= cnt;
			cnt += 1;
			result += 2;
		}

		tmp = end - start;
		while (tmp != 0) {
			result += tmp / cnt;
			tmp %= cnt;
			if (cnt - 1 > 0) cnt--;
			else break;
		}
		printf("%d\n", result);
	}

	return 0;
}
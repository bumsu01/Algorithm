#define _CRT_SECURE_NO_WARNINGS
#define MAXN 10000000
#include <stdio.h>
#include <malloc.h>

int arr[3500][3500][2], cnt;
int N, start, end, tmp = 1;

void setArray()
{
	for (int i = 1; i <= 3300; i++)
		for (int j = 1; j <= 3300; j++) {
			arr[i][j][0] = i;
			arr[i][j][1] = j;
		}
	start = end = 1;
}

int main()
{
	setArray();

	scanf("%d", &N);
	while (N > end)
	{
		start += tmp;
		end += (tmp + 1);
		tmp++;
	}

	tmp += 1;
	cnt = N - start + 1;
	if (tmp % 2 == 0) printf("%d/%d\n", arr[tmp - cnt][cnt][0], arr[tmp - cnt][cnt][1]);
	else printf("%d/%d\n", arr[cnt][tmp - cnt][0], arr[cnt][tmp - cnt][1]);

	return 0;
}
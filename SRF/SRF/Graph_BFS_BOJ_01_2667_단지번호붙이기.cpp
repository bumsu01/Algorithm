#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char input[26];
int n, arr[26][26], check[26][26], cnt[1000], c;

int dfs(int x, int y) {
	if (arr[x + 1][y] == 1 && check[x + 1][y] == 0) {
		check[x + 1][y] = 1;
		cnt[c]++;
		dfs(x + 1, y);
	} if (arr[x - 1][y] == 1 && check[x - 1][y] == 0) {
		check[x - 1][y] = 1;
		cnt[c]++;
		dfs(x - 1, y);
	} if (arr[x][y + 1] == 1 && check[x][y + 1] == 0) {
		check[x][y + 1] = 1;
		cnt[c]++;
		dfs(x, y + 1);
	} if (arr[x][y - 1] == 1 && check[x][y - 1] == 0) {
		check[x][y - 1] = 1;
		cnt[c]++;
		dfs(x, y - 1);
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", input);
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}

	c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && check[i][j] == 0) {
				cnt[c] = check[i][j] = 1;
				dfs(i, j);
				c++;
			}
		}
	}

	for (int i = 0; i < c; i++)
	{
		for (int j = i; j < c; j++)
		{
			if (cnt[i] > cnt[j]) {
				int tmp = cnt[i];
				cnt[i] = cnt[j];
				cnt[j] = tmp;
			}
		}
	}

	printf("%d\n", c);
	for (int i = 0; i < c; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}
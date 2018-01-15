#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, max, cnt;
int flag[55][55], map[55][55];

void dfs(int x, int y) {
	int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

	for (int i = 0; i < 8; i++)
	{
		if (map[x + dx[i]][y + dy[i]] == 1 && flag[x + dx[i]][y + dy[i]] == 0 && x + dx[i] >= 0 && y + dy[i] >= 0) {
			flag[x + dx[i]][y + dy[i]] = 1;
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main()
{
	while (scanf("%d %d", &m, &n))
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &map[i][j]);

		cnt = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 1 && flag[i][j] == 0) {
					cnt++;
					flag[i][j] = 1;
					dfs(i, j);
				}

		printf("%d\n", cnt);

		for (int i = 0; i < 55; i++)
			for (int j = 0; j < 55; j++)
				map[i][j] = flag[i][j] = 0;
	}
	return 0;
}
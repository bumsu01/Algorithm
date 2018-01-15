#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int n, m, cnt;
int arr[51][51], end_s, end_e;
int queD[2501][2], dqs, dqe;
int queW[2501][2], wqs, wqe;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		char ch[51];
		scanf("%s", ch);
		for (int j = 0; j < m; j++) {
			if (ch[j] == '.')
				arr[i][j] = 0;
			if (ch[j] == 'X')
				arr[i][j] = -2;
			if (ch[j] == 'D') {
				arr[i][j] = 2;
				end_s = i;
				end_e = j;
			}
			if (ch[j] == 'S') {
				arr[i][j] = 1;
				queD[dqe][0] = i;
				queD[dqe++][1] = j;
			}
			if (ch[j] == '*') {
				arr[i][j] = -1;
				queW[wqe][0] = i;
				queW[wqe++][1] = j;
			}
		}
	}

	while (dqs < dqe)
	{
		if (arr[end_s][end_e] == 1)
			break;
		cnt++;
		int s = wqs;
		int e = wqe;
		for (int w = s; w < e; w++)
			for (int i = 0; i < 4; i++)
			{
				if (queW[w][0] + dx[i] >= 0 && queW[w][0] + dx[i] < n && queW[w][1] + dy[i] >= 0 && queW[w][1] + dy[i] < m)
				{
					if (arr[queW[w][0] + dx[i]][queW[w][1] + dy[i]] == 0 || arr[queW[w][0] + dx[i]][queW[w][1] + dy[i]] == 1) {
						arr[queW[w][0] + dx[i]][queW[w][1] + dy[i]] = -1;
						queW[wqe][0] = queW[w][0] + dx[i];
						queW[wqe++][1] = queW[w][1] + dy[i];
					}
				}
			}
		wqs = e;

		s = dqs;
		e = dqe;
		for (int d = s; d < e; d++)
			for (int i = 0; i < 4; i++)
			{
				if (queD[d][0] + dx[i] >= 0 && queD[d][0] + dx[i] < n && queD[d][1] + dy[i] >= 0 && queD[d][1] + dy[i] < m)
				{
					if (arr[queD[d][0] + dx[i]][queD[d][1] + dy[i]] == 0 || arr[queD[d][0] + dx[i]][queD[d][1] + dy[i]] == 2) {
						arr[queD[d][0] + dx[i]][queD[d][1] + dy[i]] = 1;
						queD[dqe][0] = queD[d][0] + dx[i];
						queD[dqe++][1] = queD[d][1] + dy[i];
					}
				}
			}
		dqs = e;
	}

	if (arr[end_s][end_e] == 2 || (n == 1 && m == 1)) printf("KAKTUS\n");
	else printf("%d\n", cnt);

	return 0;
}
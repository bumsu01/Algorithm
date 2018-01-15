#include <iostream>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int t, m, n, k, x, y, cnt;
int table[55][55], visit[55][55];
int cx[4] = { 0, 0, 1, -1 }, cy[4] = { 1, -1, 0, 0 };
queue<int> quex;
queue<int> quey;

void find(int ty, int tx) {
	if (tx >= m || ty >= n || tx < 0 || ty < 0) return;
	visit[ty][tx] = 1;
	for (int i = 0; i < 4; i++) {
		int tempx = tx + cx[i];
		int tempy = ty + cy[i];
		if (tempx < 0 || tempy < 0 || tempy >= n || tempx >= m) {
			continue;
		}
		if (table[tempy][tempx] == 1 && visit[tempy][tempx] == 0)
		{
			find(tempy, tempx);
			visit[tempy][tempx] = 1;
		}

	}

}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			table[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (table[i][j] == 1 && visit[i][j] == 0) {
					find(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
		for (int i = 0; i < 55; i++) {
			for (int j = 0; j < 55; j++) {
				table[i][j] = 0; visit[i][j] = 0;
			}
		}

	}
	return 0;
}
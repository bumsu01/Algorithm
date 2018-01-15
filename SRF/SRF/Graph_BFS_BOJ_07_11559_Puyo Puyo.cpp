#define _CRT_SECURE_NO_WARNINGS
#define Horizontal 6
#define Vertical 12

#include <stdio.h>
#include <malloc.h>

char board[Vertical + 1][Horizontal + 1];
int calcArr[Vertical + 1][Horizontal + 1];
int bSucc = 1, answer, sum;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void InitStorage(bool del)
{
	for (int i = 0; i < Vertical; i++)
		for (int j = 0; j < Horizontal; j++) {
			if (calcArr[i][j] != 0) {
				calcArr[i][j] = 0;
				if (del) board[i][j] = '.';
			}
		}
	sum = 0;
}

void delPuyo(char color, int x, int y)
{
	sum++;
	calcArr[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (dx[i] + x >= 0 && dx[i] + x < Vertical && dy[i] + y >= 0 && dy[i] + y < Horizontal)
		{
			if (board[dx[i] + x][dy[i] + y] == color && calcArr[dx[i] + x][dy[i] + y] == 0) {
				delPuyo(color, dx[i] + x, dy[i] + y);
			}
		}
}

void bomb(char findColor)
{
	for (int i = 0; i < Vertical; i++)
		for (int j = 0; j < Horizontal; j++)
			if (board[i][j] == findColor)
			{
				delPuyo(findColor, i, j);
				if (sum >= 4) {
					bSucc = 1;
					InitStorage(true);
				}
				else InitStorage(false);
			}
}

void downPuyo()
{
	for (int j = 0; j < Horizontal; j++)
		for (int i = 0; i < Vertical - 1; i++)
			if (board[i][j] != '.' && board[i + 1][j] == '.') {
				for (int dCnt = i + 1; dCnt >= 1; dCnt--)
					board[dCnt][j] = board[dCnt - 1][j];
				board[0][j] = '.';
			}
}

int main()
{
	for (int i = 0; i < Vertical; i++)
		scanf("%s", board[i]);

	while (bSucc)
	{
		bSucc = 0;
		bomb('R');
		bomb('G');
		bomb('B');
		bomb('P');
		bomb('Y');
		downPuyo();
		answer += bSucc;
	}
	printf("%d\n", answer);

	return 0;
}
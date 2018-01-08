#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N;

char star[3][7] = { "  *   ",
							" * *  ",
							"***** " };
char board[4000][7000];

void startInsert(int startX, int endX, int startY, int endY)
{
	if (endX - startX < 6)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 6; j++)
				board[startX + i][startY + j] = star[i][j];
	}
	else
	{
		startInsert(startX + (endX - startX) / 2, endX, startY, startY + (endY - startY) / 2);
		startInsert(startX + (endX - startX) / 2, endX, startY + (endY - startY) / 2, endY);
		startInsert(startX, startX + (endX - startX) / 2, startY + (endY - startY) / 4, endY - (endY - startY) / 4);
	}
}

int main()
{
	scanf("%d", &N);

	// 별을 그릴 판(board)을 공백으로 초기화
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N * 2; j++)
			board[i][j] = ' ';

	// 재귀 함수
	startInsert(0, N, 0, N * 2);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N * 2; j++)
			printf("%c", board[i][j]);
		printf("\n");
	}

	return 0;
}
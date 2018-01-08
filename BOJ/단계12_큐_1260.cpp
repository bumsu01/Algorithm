#define _CRT_SECURE_NO_WARNINGS
#define MAXN 1000

#include <stdio.h>
#include <malloc.h>

int N, M, V, x, y;
int flag[MAXN + 1];
int graph[MAXN + 1][MAXN + 1];
int dx[4] = { 1,-1, 0, 0 }, dy[4] = { 0,0,1,-1 };

void sol_dfs(int vertex)
{ 
	for (int i = 0; i < 4; i++)
	{
		if (graph[vertex][i] && flag[vertex] == 0)
		{

		}
	}
}

void sol_bfs(int vertex)
{ 

}

int main()
{
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		graph[x][y] = graph[y][x] = 1;
	}

	sol_dfs(V);
	sol_bfs(V);

	return 0;
}
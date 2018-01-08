#define _CRT_SECURE_NO_WARNINGS
#define SQUARE(x) ((x) * (x))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define DIST(x) ((x)>2 ?1: (x)>1 ?2: (x)>0 ?3:0)
#define NEXTDIST(x) ((x)>2 ?1: (x)>1 ?2: (x)>0 ?3:0)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#define SWAP(x,y,type) do{type tmp=x; x=y; y=tmp;}while(0)

#include <stdio.h>
#include <malloc.h>

const int inf = 50;

typedef struct DATA
{
	int x, y, dist;
	DATA() { x = y = dist = 0; }
	void nextLoc(int dx, int dy, int cnt)
	{
		int nextDist[8] = { 3,2,1,0,3,2,1,0 };
		x += dx; y += dy;
		dist = nextDist[cnt];
	}
	void backLoc(int dx, int dy, int ddist)
	{
		x = dx; y = dy; dist = ddist;
	}
};

int N, M;
int map[inf + 1][inf + 1], count;
int dx[8] = { 0,1,0,-1, 0,1,0,-1 };
int dy[8] = { -1,0,1,0, -1,0,1,0 };
bool flag;
DATA robot;

void print()
{
	printf("-----------------------------\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == robot.x && j == robot.y) printf("г└");
			else if (map[i][j] == 0) printf("бр");
			else if (map[i][j] == 1) printf("бс");
			else printf("б┌");
		}
		printf("\n");
	}
}

bool exitBack(int dist)
{
	if (dist == 2 && map[robot.x - 1][robot.y] == 1) return true;
	else if(dist == 3 && map[robot.x][robot.y + 1] == 1) return true;
	else if (dist == 0 && map[robot.x + 1][robot.y] == 1) return true;
	else if (dist == 1 && map[robot.x][robot.y - 1] == 1) return true;
	else return false;
}

void rulePlay(int x, int y, int dist)
{
	if (flag) return;
	//else print();

	if (map[robot.x][robot.y] == 0)
	{
		map[robot.x][robot.y] = 2;
		count++;
	}

	for (int i = DIST(dist); i < DIST(dist) + 4; i++)
	{
		if (map[robot.x + dx[i]][robot.y + dy[i]] == 0)
		{
			robot.nextLoc(dx[i], dy[i], i);
			rulePlay(robot.x, robot.y, robot.dist);
			robot.backLoc(x, y, dist);
		}
	}

	if (!exitBack(robot.dist))
	{
		if (robot.dist == 0) robot.x += 1;
		else if (robot.dist == 1) robot.y -= 1;
		else if (robot.dist == 2) robot.x -= 1;
		else if (robot.dist == 3) robot.y += 1;
		rulePlay(robot.x, robot.y, robot.dist);
	}
	else flag = true;
}

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &robot.x, &robot.y, &robot.dist);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	rulePlay(robot.x, robot.y, robot.dist);

	printf("%d\n", count);

	return 0;
}
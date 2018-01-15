#define INIT 1
#define SET_BLOCK 2
#define SET_SPEICAL_BLOCK 3
#define ROTATIOIN 4
#define REPLACE 5
#define LAND 6
#define EXIT 7

#define MAX_HEIGHT 900
#define MAX_WIDTH 10
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define SWAP(x,y,type) do{type t=x;x=y;y=t;}while(0)
#define boxInit(x) do{(x)[0]=(x)[1]=(x)[2]=0;}while(0)
#define JockerInit(x) for(int i=0;i<8;i++) {(x)[i]=0;}

#include<stdio.h>

extern void init(int width);
extern void setBlock(int* block);
extern void setSpecialBlock();
extern void rotation(int repeat);
extern void replace(int position);
extern int land();

const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
const int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
const int jdx[4] = { 1,-1,0,0 };
const int jdy[4] = { 0,0,1,-1 };

int map[MAX_HEIGHT + 1][MAX_WIDTH + 1];
int dfsChk[MAX_HEIGHT + 1][MAX_WIDTH + 1];
int wLen, hLen[MAX_WIDTH + 1], shootLoc;
int box[3], maxBox, dfsCnt;

bool flag[MAX_HEIGHT + 1][MAX_WIDTH + 1];
bool jocker[8], delBoxNum[MAX_HEIGHT * MAX_WIDTH];

void dfsInit(int width)
{
	int maxHeight = 0;
	register int i, j;

	for (i = 0; i <= dfsCnt; i++)
		delBoxNum[i] = 0;
	for (int i = 0; i < width; i++)
		maxHeight = MAX(maxHeight, hLen[i]);
	for (int i = 0; i < maxHeight; i++)
		for (int j = 0; j < width; j++)
			flag[i][j] = dfsChk[i][j] = 0;
	dfsCnt = 0;
}
void delJocker()
{
	register int i, j;
	for (i = 0; i < wLen; i++)
		for (j = 0; j < hLen[i]; j++)
			if (jocker[map[j][i]])
				map[j][i] = 0;
}
void fallDown()
{
	register int i, j, l;
	int maxLen;
	for (i = 0; i < wLen; i++)
	{
		for (j = 0; j < hLen[i]; j++)
		{
			if (map[j][i] != 0)
			{
				for (l = j; l > 0; l--)
					if (map[l - 1][i] == 0)
						SWAP(map[l - 1][i], map[l][i], int);
			}
		}

		for (maxLen = 0; maxLen < hLen[i]; maxLen++)
			if (map[maxLen][i] == 0) break;
		hLen[i] = maxLen;
	}
}
void _dfs(int x, int y, int target, int height)
{
	flag[x][y] = true;
	dfsChk[x][y] = dfsCnt;
	maxBox++;
	register int i;
	for (i = 0; i < 8; i++)
		if (0 <= x + dx[i] && x + dx[i] < height && 0 <= y + dy[i] && y + dy[i] < wLen)
			if (dfsChk[x+dx[i]][y+dy[i]] == 0 && map[x + dx[i]][y + dy[i]] == target)
				_dfs(x + dx[i], y + dy[i], target, height);
}
bool _checkDel()
{
	register int i, j;
	bool checkFlag = false;
	int maxHeight = 0;

	for (int i = 0; i < wLen; i++)
		maxHeight = MAX(maxHeight, hLen[i]);

	for (i = 0; i < wLen; i++) {
		for (j = 0; j < hLen[i]; j++) {
			if (flag[j][i] == false && map[j][i] != 0)
			{
				dfsCnt++;
				maxBox = 0;
				_dfs(j, i, map[j][i], maxHeight);
				if (maxBox >= 3)
				{
					checkFlag = true;
					delBoxNum[dfsCnt] = true;
				}
			}
		}
	}
	return checkFlag;
}
void delBox()
{
	register int i, j;
	for (i = 0; i < wLen; i++)
		for (j = 0; j < hLen[i]; j++)
			if (delBoxNum[dfsChk[j][i]])
				map[j][i] = 0;
}
void playShoot()
{
	register int i, j;
	if (box[2] == 7)
	{
		int x = hLen[shootLoc];
		int y = shootLoc;
		for (i = 0; i < 4; i++)
			if (0 <= x + jdx[i] && x + jdx[i] < MAX_HEIGHT && 0 <= y + jdy[i] && y + jdy[i] < wLen)
				if (map[x + jdx[i]][y + jdy[i]] != 0)
					jocker[map[x + jdx[i]][y + jdy[i]]] = true;
		delJocker();
		JockerInit(jocker);
	}
	else
	{
		map[hLen[shootLoc]++][shootLoc] = box[2];
		map[hLen[shootLoc]++][shootLoc] = box[1];
		map[hLen[shootLoc]++][shootLoc] = box[0];
	}
	fallDown();
	dfsInit(wLen);
	while (_checkDel())
	{
		delBox();
		fallDown();
		dfsInit(wLen);
	}
}

void print(int ord,int ret)
{
	printf("%d ", ord);
	if (ord == 1) printf("%s\n", "초기화");
	else if (ord == 2) {
		printf("%s\n", "블럭 생성");
		for (int i = 0; i < 3; i++)
		{
			if (box[i] == 0) printf("□");
			else if (box[i] == 1) printf("●");
			else if (box[i] == 2) printf("■");
			else if (box[i] == 3) printf("◆");
			else if (box[i] == 4) printf("♣");
			else if (box[i] == 5) printf("♠");
			else if (box[i] == 6) printf("★");
			printf("\n");
		}
	}
	else if (ord == 3) printf("%s\n", "스페셜 블럭 생성");
	else if (ord == 4) {
		printf("%s\n", "회전");

		for (int i = 0; i < 3; i++)
		{
			if (box[i] == 0) printf("□");
			else if (box[i] == 1) printf("●");
			else if (box[i] == 2) printf("■");
			else if (box[i] == 3) printf("◆");
			else if (box[i] == 4) printf("♣");
			else if (box[i] == 5) printf("♠");
			else if (box[i] == 6) printf("★");
			printf("\n");
		}
	}
	else if (ord == 5) printf("%s -> %d\n", "이동", shootLoc);
	else if (ord == 6) {
		printf("%s\nret = %d\n", "내리기", ret);

		for (int i = 20; i>=0; i--) {
			for (int j = 0; j < wLen; j++)
				if (map[i][j] == 0) printf("□");
				else if (map[i][j] == 1) printf("●");
				else if (map[i][j] == 2) printf("■");
				else if (map[i][j] == 3) printf("◆");
				else if (map[i][j] == 4) printf("♣");
				else if (map[i][j] == 5) printf("♠");
				else if (map[i][j] == 6) printf("★");
				printf("\n");
		}
	}
	else if (ord == 7) printf("%s\n", "종료");
}

int main() {
	int ret, cnt = 0;
	//freopen("0112_input.txt", "r", stdin);
	//freopen("0112_output.txt", "w", stdout);
	int order, n, b[3];
	while (1) {
		ret = 0;
		scanf("%d", &order);
		if (order == EXIT)
			break;
		switch (order) {
		case INIT:
			scanf("%d", &n);
			init(n);
			break;
		case SET_BLOCK:
			scanf("%d %d %d", &b[0], &b[1], &b[2]);
			setBlock(b);
			break;
		case SET_SPEICAL_BLOCK:
			setSpecialBlock();
			break;
		case ROTATIOIN:
			scanf("%d", &n);
			rotation(n);
			break;
		case REPLACE:
			scanf("%d", &n);
			replace(n);
			break;
		case LAND:
			printf("%d\n", land());
			break;
		}
		//print(order, ret);
	}
	return 0;
}

extern void init(int width)
{
	register int i, j;
	for (i = 0; i < MAX_HEIGHT; i++)
		for (j = 0; j < width; j++)
			map[i][j] = 0;
	for (i = 0; i < MAX_WIDTH; i++) hLen[i] = 0;
	for (i = 0; i < 3; i++) box[i] = 0;
	for (i = 0; i < 8; i++) jocker[i] = 0;
	wLen = width;
	shootLoc = 0;
}

extern void setBlock(int* block)
{
	boxInit(box);
	box[0] = block[0];
	box[1] = block[1];
	box[2] = block[2];
}

extern void setSpecialBlock()
{
	boxInit(box);
	box[0] = 0; box[1] = 0; box[2] = 7;
}

extern void rotation(int repeat)
{
	register int i;
	int tmp[3];

	for (int rep = 0; rep < repeat; rep++)
	{
		for (i = 2; i < 5; i++)
			tmp[i - 2] = box[i % 3];
		for (i = 0; i < 3; i++)
			box[i] = tmp[i];
	}
}

extern void replace(int position)
{
	if (0 <= shootLoc + position && shootLoc + position < wLen)
		shootLoc += position;
	else if (shootLoc + position < 0)
		shootLoc = 0;
	else if (shootLoc + position >= wLen)
		shootLoc = wLen - 1;
}

extern int land()
{
	playShoot();

	register int i, j;
	int cnt = 0;

	for (i = 0; i < wLen; i++)
		for (j = 0; j < hLen[i]; j++)
			if (map[j][i] != 0)
				cnt++;

	return cnt;
}
#include <stdio.h>
#include <stdlib.h>
#define PENALTY			10000000
#define MAX_FILE_SIZE	1000000
#define MAX_DELETE		1000
#define ORIGNAL			1
#define MODIFIDE		2


int File_Size;
int Seed;
int DeleteCnt;
int DEL_DATA[MAX_DELETE];
int ORIGNAL_FILE[MAX_FILE_SIZE];
int MODIFIDE_FILE[MAX_FILE_SIZE];
int getCount;
typedef struct
{
	int count;
	int delDataList[MAX_DELETE];
}RESULT;

extern RESULT compareFile();


void MixFile(void) {
	srand(Seed);
	for (int i = 0; i < File_Size; i++) {
		int index1 = (rand()*rand()) % File_Size;
		int index2 = (rand()*rand()) % File_Size;
		int temp = ORIGNAL_FILE[index1];
		ORIGNAL_FILE[index1] = ORIGNAL_FILE[index2];
		ORIGNAL_FILE[index2] = temp;
	}
}


void MakeFile() {
	int DelData;
	int DEL_INDEX[MAX_DELETE];
	for (int i = 0; i < DeleteCnt; i++) {
		scanf("%d", &DEL_INDEX[i]);
	}

	for (int i = 0; i < File_Size; i++)
		ORIGNAL_FILE[i] = i + 1;

	MixFile();

	for (int i = 0, j = 0; i < File_Size; i++) {
		if (DEL_INDEX[j] == i) {
			DEL_DATA[j++] = ORIGNAL_FILE[i];
			continue;
		}
		MODIFIDE_FILE[i - j] = ORIGNAL_FILE[i];
	}

}

int get(int file, int index) {
	getCount++;

	if (getCount >= File_Size * 2)
		return -1;


	if (file == ORIGNAL) {

		if (index >= File_Size) {
			return 0;
		}

		return ORIGNAL_FILE[index];
	}
	else if (file == MODIFIDE) {
		if (index >= (File_Size - DeleteCnt)) {
			return 0;
		}
		return MODIFIDE_FILE[index];
	}
	else
		return 0;
}

int grade(RESULT result) {
	int score;
	if (result.count != DeleteCnt) {
		return PENALTY;
	}
	else {
		for (int i = 0; i < DeleteCnt; i++) {
			if (result.delDataList[i] == DEL_DATA[i]) {
			}
			else {
				return PENALTY;
			}
		}
		return getCount;
	}
}
int main(void) {

	int testCase;
	int TotalScore = 0;
	freopen("testInput.txt", "r", stdin);
	scanf("%d", &testCase);

	for (int tc = 0; tc < testCase; tc++) {
		getCount = 0;
		scanf("%d %d %d", &Seed, &File_Size, &DeleteCnt);

		MakeFile();

		RESULT result = compareFile();
		int score = grade(result);
		TotalScore += score;
		printf("#%d: %d\n", tc + 1, score);
		/*
		if (result.count != DeleteCnt)
			for (int i = 0; i < DeleteCnt; i++)
				if (result.delDataList[i] != DEL_DATA[i])
					printf("[%d] -> %d\n", i, DEL_DATA[i]);
		*/
	}

	printf("Total Score %d\n", TotalScore);
	return 0;
}

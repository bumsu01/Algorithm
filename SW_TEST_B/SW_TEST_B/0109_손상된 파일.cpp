#include <stdio.h>
#include <stdlib.h>
#define PENALTY			10000000
#define MAX_FILE_SIZE	1000000
#define MAX_DELETE		1000
#define ORIGNAL			1
#define MODIFIDE		2

#define MAX_DELETE		1000
#define MAX_FILE		1000000
#define PIVOT			1000
#define SUM(x,y)		((x) + (y))
#define SUB(x,y)		((x) - (y))
#define MIN(x,y)		((x) < (y) ? (x) : (y))
#define MAX(x,y)		((x) > (y) ? (x) : (y))

// ORIGIN     -- 1 ~
// MODIFIDE   -- 2 ~

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

int findLastIndex(int left, int right, int target)
{
	int L = left, R = right;
	int mid, ret = 0;

	// when file max index is MAX_FILE
	if (get(target, R - 1) != 0 && get(target, R) == 0)
		return R - 1;
	// when file max index is not MAX_FILE , then find Last index
	while (L <= R)
	{
		mid = (L + R) / 2;
		if (get(target, mid) == 0) R = mid - 1;
		else
		{
			L = mid + 1;
			ret = MAX(ret, mid);
		}
	}
	return ret;
}

bool findDiffData(int oL, int oR, int mL, int mR)
{
	return (get(1, oL) == get(2, mL) && get(1, oR) == get(2, mR));
}

RESULT process(int originLastIndex, int modifyLastIndex, RESULT res)
{
	int oL = 0, oR, oLast = originLastIndex;
	int mL = 0, mR, mLast = modifyLastIndex;
	int mDiff, oDiff, cnt, same;

	while (oL <= oLast && mL <= mLast)
	{
		oR = MIN(oL + PIVOT, oLast);
		mR = MIN(mL + PIVOT, mLast);
		// when same with first Data and last Data (between origin and modify)
		if (oR != oLast && findDiffData(oL, oR, mL, mR))
		{
			oL = oR + 1;
			mL = mR + 1;
		}
		else
		{
			// when exist differnt data, Let's Binary Search
			// standard is orgin Data
			int L = oL, R = oR;
			int mid;
			while (L <= R)
			{
				mid = (L + R) / 2;
				if (get(1, mid) == get(2, mL + SUB(mid, oL))) L = mid + 1;
				else {
					R = mid - 1;
					same = mid;
				}
			}
			// mid is first diffrent data
			// So update result
			cnt = 0;
			oDiff = get(1, same + cnt);
			mDiff = get(2, mL + SUB(same, oL));
			// Increase differnet origin data (Linear)
			while (oDiff != mDiff) {
				cnt++;
				res.delDataList[res.count++] = oDiff;
				oDiff = get(1, same + cnt);
			}
			mL = mL + SUB(same, oL) + 1;
			oL = same + cnt + 1;
			if (res.count == oLast - mLast)
				return res;
		}
	}

	return res;
}

RESULT compareFile() {
	RESULT result;

	int originLen = findLastIndex(0, MAX_FILE, 1);
	int modiLen = findLastIndex(0, MAX_FILE, 2);
	result.count = 0;

	result = process(originLen, modiLen, result);

	return result;
}


void MixFile(void) {
	srand(Seed);
	for (int i = 0; i < File_Size; i++) {
		int index1 = ((rand() % 32767)*(rand() % 32767)) % File_Size;
		int index2 = ((rand() % 32767)*(rand() % 32767)) % File_Size;
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
	}

	printf("Total Score %d\n", TotalScore);
	return 0;
}
/*
어느 기준에서 나눠지는 경우 이분 탐색 사용 가능
log M * N

(중요)
Binary search 는 data를 찾는 알고리즘만 뜻하는 것이 아니다.
전체적인 1~N까지의 수를 이분적으로 나누어서 "정답"을 찾는 과정 또한
Binary Search라고 할 수 있다.

Input Data에 얽매이지 말자.
*/
#define MAX(x,y) ((x) > (y) ? (x):(y))
#define CUTCOUNT(x, y) ((x) / (y))

const int maxData  = 10000;
int L, R, mid;
int diff, N;

int installWIFI(int *arr, long long len)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += CUTCOUNT(arr[i], len);
	return sum;
}

int bSearch(int *arr, int target)
{
	int ret = 0, tmp;
	L = 1; R = maxData;

	while (L <= R)
	{
		mid = (L + R) / 2;
		if (R == 0) break;

		tmp = installWIFI(arr, mid);
		if (tmp < target) R = mid - 1;
		else
		{
			L = mid + 1;
			ret = MAX(ret, diff);
		}
	}
	return ret;
}
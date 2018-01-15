/*
��� ���ؿ��� �������� ��� �̺� Ž�� ��� ����
log M * N

(�߿�)
Binary search �� data�� ã�� �˰��� ���ϴ� ���� �ƴϴ�.
��ü���� 1~N������ ���� �̺������� ����� "����"�� ã�� ���� ����
Binary Search��� �� �� �ִ�.

Input Data�� �������� ����.
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
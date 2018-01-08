#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int x, y, cur;
char day[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main()
{
	scanf("%d %d", &x, &y);

	cur += y;
	for (int i = 1; i < x; i++)
	{
		if (i == 2) cur += 28;
		else if (i == 4 || i == 6 || i == 9 || i == 11) cur += 30;
		else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) cur += 31;
	}
	cur %= 7;

	printf("%s\n", day[cur]);
	
	return 0;
}
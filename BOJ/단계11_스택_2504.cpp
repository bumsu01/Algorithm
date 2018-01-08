#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

char text[31];
int stack[31];
int sTop, cnt, answer;

int main()
{
	scanf("%s", &text);
	while (text[cnt] != '\0')
	{
		if (text[cnt] == '(')
			stack[sTop++] = -1;
		else if (text[cnt] == '[')
			stack[sTop++] = -3;
		else if (text[cnt] == ')')
		{
			if (stack[sTop - 1] == -1)
				stack[sTop - 1] = 2;
			else {
				int save = 0;
				while (stack[sTop - 1] != -1 && sTop > 0)
				{
					if (stack[sTop - 1] == -2 && stack[sTop - 1] == -3 && stack[sTop - 1] == -4) {
						cnt = -1;
						break;
					}
					save += stack[sTop - 1];
					stack[sTop - 1] = '\0';
					sTop--;
				}
				stack[sTop - 1] = save * 2;
			}
		}
		else if (text[cnt] == ']')
		{
			if (stack[sTop - 1] == -3)
				stack[sTop - 1] = 3;
			else {
				int save = 0;
				while (stack[sTop - 1] != -3 && sTop > 0)
				{
					if (stack[sTop - 1] == -1 && stack[sTop - 1] == -2 && stack[sTop - 1] == -4) {
						cnt = -1;
						break;
					}
					save += stack[sTop - 1];
					stack[sTop - 1] = '\0';
					sTop--;
				}
				stack[sTop - 1] = save * 3;
			}
		}
		if (cnt == -1)
			printf("0\n");
		else
			cnt++;
	}

	for (int i = 0; i < sTop; i++) {
		if (stack[i] == -1 || stack[i] == -2 || stack[i] == -3 || stack[i] == -4)
		{
			printf("0\n");
			return 0;
		}
		else
			answer += stack[i];
	}

	printf("%d\n", answer);

	return 0;
}
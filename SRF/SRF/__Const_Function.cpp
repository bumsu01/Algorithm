
const int MAXN = 100000; 
const int arrInf = 100000;
const int nameInf = 20;

// BASIC CODE
const void _strcpy(char *aStr, char *bStr)
{
	while (*bStr) { *aStr = *bStr; aStr++; bStr++; }
	*aStr = '\0';
}

const int _strcmp(char *aStr, char *bStr)
{
	while (*aStr) { if (*aStr != *bStr) break; aStr++; bStr++; }
	return *aStr - *bStr;
}

const int _atoi(int num, char *str)
{
	for (; *str; num *= 10) { num += (*str - '0'); str++; }
	return num;
}

const int _strswap(char *aStr, char *bStr)
{
	char *tmp;
	_strcpy(tmp, aStr);
	_strcpy(aStr, bStr);
	_strcpy(bStr, tmp);
}

// HASH CODE - function
const int calcHash(int num)
{
	int res = 0;
	for (int i = 0; i < num; i++)
		res = ((res * 17) + 17) % MAXN;
	return res;
}

// QUICK SORT - function
const bool _qCmp(char *aStr, char *bStr)
{
}

#define	ARRAY_SIZE(x)	( sizeof((x))/sizeof((x)[0]) ) // �迭 ����
#define	ABS(x)			( ((x)<0)?-(x):(x) )	// ���� ��
#define	SQUARE(x)		( (x)*(x) )	// ������
#define	MAX(x,y)		( (x) > (y) ? (x) : (y) )	// �ִ� ��
#define	MIN(x,y)		( (x) < (y) ? (x) : (y) )	// �ּ� ��
#define	UPCASE(c)		( ( (c)>='a' && (c)<='z') ? (c)-('a'-'A') : (c) )	// �ҹ���->�빮��
#define LOWCASE(c)		( ( (c)>='A' && (c)<='Z') ? (c)+('a'-'A') : (c) )	// �빮��->�ҹ���
#define SWAP(x,y,type) do { type tmp = x; x = y; y = t; } while(0)
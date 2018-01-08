#define	ARRAY_SIZE(x)	( sizeof((x))/sizeof((x)[0]) ) // 배열 길이
#define	ABS(x)			( ((x)<0)?-(x):(x) )	// 절대 값
#define	SQUARE(x)		( (x)*(x) )	// 제곱근
#define	MAX(x,y)		( (x) > (y) ? (x) : (y) )	// 최대 값
#define	MIN(x,y)		( (x) < (y) ? (x) : (y) )	// 최소 값
#define	UPCASE(c)		( ( (c)>='a' && (c)<='z') ? (c)-('a'-'A') : (c) )	// 소문자->대문자
#define LOWCASE(c)		( ( (c)>='A' && (c)<='Z') ? (c)+('a'-'A') : (c) )	// 대문자->소문자



// 공부 해야할 것 -- 13일 전까지
// 1. typedef struct DATA 사용 방법 및 function으로 넘기고 받을 때 실제 값과 주소 값을 사용해서 활용하는 방법
// 2. quick sort 사용 방법과 1을 연동하여 DATA 값으로 가지고 있을 때 정렬, 그리고 데이터 정렬 조건이 여러 개일 때 정렬하는 방법
// 3. segment tree 를 사용한 구간 합 구하기 및 세그먼트 트리 Class형으로 구현하는 방법
// 4. queue를 class 형으로 구현하는 방법과 class 대신 c 언어에서 queue 함수까지 구현하는 방법
// 5. HASH clac 함수 변형 및 최적의 HASH 사용과 그 최적이 되고 있는지 아는 방법
// 6. 우선순위 큐를 class 형으로 구현 및 작성 그리고 문제 풀기
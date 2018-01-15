#define QUEUE_SIZE 100

typedef struct {
	char name[128];
	int age;
	int average;
}Student;

Student queueData[QUEUE_SIZE];
int front = 0;
int rear = 0;

void push(Student s) {
	rear++;
	rear = rear % QUEUE_SIZE;
	queueData[rear] = s;
}

Student pop()
{
	int pp = front;
	front++;
	front = front % QUEUE_SIZE;
	return queueData[pp];
}
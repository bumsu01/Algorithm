// Class�� �տ� �빮�� + �ҹ��� ���� (������ Ŭ������)
// Class ������ �Լ���� �������� { �� �� �ٿ� �鿩���� ����

// queue
class Queue
{
	class Node
	{
	public:
		int data; // x,y�̸� change <-> struct ����ü�� ����ϰ� ������ template<typename xx>
		Node *next;
	};
	Node *front = 0, *rear = 0;
	int size = 0;

	void push(int data)
	{
		size++;
		Node *newNode = new Node();
		newNode->data = data;
		if (front == 0)
			front = rear = newNode;
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	int pop()
	{
		if (size == 0) return;
		else size--;

		Node *delNode = front;
		front = front->next;
		delete delNode;
	}
	
	int front()
	{
		if (size == 0) return -1;
		return front->data;
	}

	int rear()
	{
		if (size == 0) return -1;
		return rear->data;
	}

	int size() { return size; }
	bool empty() { return size == 0; }

	void clear()
	{
		while (size)
		{
			Node *delNode = front;
			front = front->next;
			size--;
			delete delNode;
		}
	}
};

// stack
class Stack
{

};
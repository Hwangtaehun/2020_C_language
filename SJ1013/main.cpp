#include <iostream>
#include <iomanip>

using namespace std;

#define QUEUE_SIZE 4
typedef int ELEMENT;

ELEMENT queue[QUEUE_SIZE];
int front, rear;

void PutQueue(ELEMENT data);
ELEMENT GetQueue();
void PrintQueue();

int main(int ac, char** av)
{
	ELEMENT data;
	front = rear = 0;
	cout << "����ִ� �ܿ� GetQueue ���� : ";
	data = GetQueue();
	PutQueue(1);
	PutQueue(2);
	PutQueue(3);
	PutQueue(4);
	cout << "�� �� ��� PutQueue ���� : ";
	PutQueue(5);
	cout << "�� �� ��� : ";
	PrintQueue();
	data = GetQueue();
	cout << "ù���� �ڷ� ���� : " << data << endl;
	data = GetQueue();
	cout << "�ι��� �ڷ� ���� : " << data << endl;
	cout << "�ΰ� ���� ��";
	PrintQueue();
	PutQueue(6);
	PutQueue(7);
	PutQueue(8);
	cout << "�߰� �� ";
	PrintQueue();
	return 0;
}

void PutQueue(ELEMENT data)
{
    if(front == (rear+1) % QUEUE_SIZE)
	//if (rear == QUEUE_SIZE)
	{
		cout << "Queue�� OverFlow �߻�.\n";
		return;
	}
	queue[rear] = data;
	// rear++;
	rear = (rear + 1) % QUEUE_SIZE;
}

ELEMENT GetQueue()
{
	ELEMENT temp = -1;
	if (front == rear)
	{
		cout << "Queue�� �ڷᰡ �����.\n";
		return temp;
	}
	temp = queue[front];
	// front++;
	front = (front + 1) % QUEUE_SIZE;
	return temp;
}

void PrintQueue()
{
	int head = front;
	while (head != rear)
	{
		cout << setw(5) << queue[head];
		// head++;
		head = (head + 1) % QUEUE_SIZE;
	}
	cout << endl;
}

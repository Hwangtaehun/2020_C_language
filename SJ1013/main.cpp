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
	cout << "비어있는 겨우 GetQueue 실행 : ";
	data = GetQueue();
	PutQueue(1);
	PutQueue(2);
	PutQueue(3);
	PutQueue(4);
	cout << "꽉 찬 경우 PutQueue 실행 : ";
	PutQueue(5);
	cout << "꽉 찬 경우 : ";
	PrintQueue();
	data = GetQueue();
	cout << "첫번쩨 자료 추출 : " << data << endl;
	data = GetQueue();
	cout << "두번쩨 자료 추출 : " << data << endl;
	cout << "두개 추출 후";
	PrintQueue();
	PutQueue(6);
	PutQueue(7);
	PutQueue(8);
	cout << "추가 후 ";
	PrintQueue();
	return 0;
}

void PutQueue(ELEMENT data)
{
    if(front == (rear+1) % QUEUE_SIZE)
	//if (rear == QUEUE_SIZE)
	{
		cout << "Queue에 OverFlow 발생.\n";
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
		cout << "Queue에 자료가 없어요.\n";
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

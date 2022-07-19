#include <iostream>
#include "SjList.h"
using namespace std;

typedef struct tag_SUNGJUK
{
	char name[10];
	int kor;
	int eng;
	int mat;
} SUNGJUK;

void PrintList(CSjList list);

int main(void)
{
	SUNGJUK s[] = { {"�հ�", 100, 100, 100 }, {"����", 60, 50, 80}, {"�ÿ�", 50, 90, 80}, {"�ڼ�ȸ", 50, 60, 40}, {"�ż���", 70, 60, 90}, {"����", 90, 90, 90} };
	CSjList list;
	SUNGJUK* pData;

	cout << "�ڷ� ���� �� \n";
	PrintList(list);

	list.addTail((void*)&s[0]);
	list.addTail((void*)&s[1]);
	list.addTail((void*)&s[2]);
	cout << "�ڷ� 3�� ���� �� \n";
	PrintList(list);

	pData = new SUNGJUK;
	*pData = s[5];
	list.addNode((void*)pData, 2);
	list.addNode((void*)&s[4], 1);
	cout << "�ڷ�(����, 2/ �ż���, 1) �߰� �� \n";
	PrintList(list);

	list.deleteNode(2);
	list.deleteNode(3);
	cout << "2, 3��° �ڷ� ���� �� \n";
	PrintList(list);
	cout << "�ڷ��� �� : " << list.GetCount() << endl;

	return 0;
}

void PrintList(CSjList list)
{
	SUNGJUK* pData;
	int pos = 0;
	while ((pData = (SUNGJUK*)list.GetNode(pos)) != NULL)
	{
		cout << pos - 1 << " " << pData->name << endl;
	}
}
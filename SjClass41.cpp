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
	SUNGJUK s[] = { {"왕건", 100, 100, 100 }, {"견휜", 60, 50, 80}, {"궁예", 50, 90, 80}, {"박술회", 50, 60, 40}, {"신숭겸", 70, 60, 90}, {"세종", 90, 90, 90} };
	CSjList list;
	SUNGJUK* pData;

	cout << "자료 대입 전 \n";
	PrintList(list);

	list.addTail((void*)&s[0]);
	list.addTail((void*)&s[1]);
	list.addTail((void*)&s[2]);
	cout << "자료 3개 대입 후 \n";
	PrintList(list);

	pData = new SUNGJUK;
	*pData = s[5];
	list.addNode((void*)pData, 2);
	list.addNode((void*)&s[4], 1);
	cout << "자료(세종, 2/ 신숭겸, 1) 추가 후 \n";
	PrintList(list);

	list.deleteNode(2);
	list.deleteNode(3);
	cout << "2, 3번째 자료 제거 후 \n";
	PrintList(list);
	cout << "자료의 수 : " << list.GetCount() << endl;

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
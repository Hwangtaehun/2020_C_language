/*Ȯ�� �ٶ�*/
#include "my.h"

typedef struct tag_SUNGJUK
{
	char name[10];
	int kor;
	int eng;
	int mat;
} SUNGJUK;

typedef struct tag_LIST
{
	SUNGJUK data;
	struct tag_LIST* link;
}LIST;

void addTail(LIST* pNode, SUNGJUK data);
void addNode(LIST* pNode, SUNGJUK data, int cnt);
void deleteNode(LIST* pNode, char* pStr);
void PrintList(LIST* pNode);

int main(int argc, char** argv)
{
	SUNGJUK s[] = { {"�հ�", 100, 100, 100},
				{"����", 60, 50, 80},
				{"�ÿ�", 50, 90, 80},
				{"�ڼ�ȸ", 50, 60, 40},
				{"�ż���", 70, 60, 90} };

	int i;
	LIST* head;
	head = new LIST;
	head->link = NULL;

	for (i = 0; i < 5; i++)
	{
		addTail(head, s[i]);
	}
	PrintList(head->link);
	deleteNode(head, "�ÿ�");
	PrintList(head->link);
	deleteNode(head, "�ż���1");
	addNode(head, s[5], 2);
	PrintList(head->link);
	
	return 0;
}

void addTail(LIST* pNode, SUNGJUK data)
{
	LIST* temp;
	while (pNode->link != NULL)
	{
		pNode = pNode->link;
	}
	temp = new LIST;
	temp->data = data;
	temp->link = NULL;
	pNode->link = temp;
}

void addNode(LIST* pNode, SUNGJUK data, int cnt)
{
	LIST* temp;
	int i;
	for (i = 0; i < cnt; i++)
	{
		pNode = pNode->link;
		if (pNode->link == NULL)
			break;
	}
	temp = new LIST;
	temp->data = data;
	temp->link = pNode->link;
	pNode->link = temp;
}

void deleteNode(LIST* pNode, char* pStr)
{
	LIST* temp;
	while (pNode->link != NULL)
	{
		if (strcmp(pNode->link->data.name, pStr) == 0)
			break;
		pNode = pNode->link;
	}
	while (pNode->link != NULL)
	{
		printf("������� �ڷᰡ �����!!\n");
		return;
	}
	temp = pNode->link;
	pNode->link = pNode->link->link;
	delete temp;
}

void PrintList(LIST* pNode)
{
	printf("%18s\n", "���� ��Ȳ");
	Line(28, '=');
	printf(" �� ��  ���� ���� ���� \n");
	Line(28, '=');
	while (pNode != NULL)
	{
		printf(" %-8s %5d %5d %5d \n", pNode->data.name, pNode->data.kor, pNode->data.eng, pNode->data.mat);
		pNode = pNode->link;
	}
	Line(28, '=');
}
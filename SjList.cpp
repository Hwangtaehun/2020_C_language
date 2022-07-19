#include "SjList.h"
CSjList::CSjList()
{
	head = new SjNode;
	head->pNext = NULL;
}

void CSjList::addTail(void* pData)
{
	pNode = head;
	while (pNode->pNext != NULL)
	{
		pNode = pNode->pNext;
	}
	temp = new SjNode;
	temp->pData = pData;
	temp->pNext = NULL;
	pNode->pNext = temp;
}

void CSjList::addNode(void* pData, int cnt)
{
	pNode = head;
	for (int i = 0; i < cnt; i++)
	{
		if (pNode->pNext == NULL)
			break;
		pNode = pNode->pNext;
	}
	temp = new SjNode;
	temp->pData = pData;
	temp->pNext = pNode->pNext;
	pNode->pNext = temp;
}

int CSjList::deleteNode(int cnt)
{
	if (head->pNext == NULL)
	{
		cout << "List가 비었어요.!!\n";
		return -1;
	}
	pNode = head;
	for (int i = 0; i < cnt; i++)
	{
		pNode = pNode->pNext;
		if (pNode->pNext == NULL)
		{
			cout << "지우려는 자료가 없어요.!!\n";
			return -1;
		}
	}
	temp = pNode->pNext;
	pNode->pNext = temp->pNext;
	delete temp;
	return 0;
}

void* CSjList::GetNode(int& pos)
{
	if (head->pNext == NULL)
	{
		cout << "List가 비었어요.!!\n";
		return NULL;
	}
	pNode = head;
	for (int i = 0; i < pos; i++)
	{
		pNode = pNode->pNext;
	}
	if (pNode->pNext == NULL)
	{
		return NULL;
	}
	pos++;
	return pNode->pNext->pData;
}

int CSjList::GetCount()
{
	int cnt = 0;
	pNode = head;
	while (pNode->pNext != NULL)
	{
		pNode = pNode->pNext;
		cnt++;
	}
	return cnt;
}
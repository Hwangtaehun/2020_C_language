#pragma once

#include<iostream>
using namespace std;

struct SjNode
{
	void* pData;
	SjNode* pNext;
};

class CSjList
{
private:
	SjNode* head;
	SjNode* pNode, * temp;
public:
	CSjList();
	void addTail(void* pData);
	void addNode(void* pData, int cnt);
	int deleteNode(int cnt);
	void* GetNode(int& pos);
	int GetCount();
};
#include <iostream>
using namespace std;

typedef struct tagPOINT
{
	int x;
	int y;
} POINT;

typedef struct tagRECT
{
	int x1;
	int y1;
	int x2;
	int y2;
} RECT;

class CRect
{
public:
	int left;
	int top;
	int right;
	int bottom;
	CRect();
	CRect(int x1, int y1, int x2, int y2);
	~CRect();
	bool PtlnRect(POINT pt);
	int Height();
	int Width();
};

CRect::CRect()
{

}

CRect::CRect(int x1, int y1, int x2, int y2)
{
	left = x1;
	top = y1;
	right = x2;
	bottom = y2;
}

CRect::~CRect()
{

}

bool CRect::PtlnRect(POINT pt)
{
	if (pt.x >= left && pt.x <= right && pt.y >= top && pt.y <= bottom)
		return true;
	else
		return false;
}

int CRect::Height()
{
	return (bottom - top);
}

int CRect::Width()
{
	return (right - left);
}

int main(int argc, char* argv[])
{
	RECT ra = { 10, 20, 30, 40 };
	cout << "�簢���� �ʺ� = " << ra.x2 - ra.x1 << " ���� = " << ra.y2 - ra.y1 << endl;

	POINT pa = { 100, 200 }, pb = { 99, 200 };
	CRect rc(100, 200, 300, 400);
	cout << "�簢���� �ʺ� = " << rc.Width() << " ���� = " << rc.Height() << endl;

	if (rc.PtlnRect(pa))
		cout << "pa�� rc ���� �ȿ� �ִ� ��ǥ�Դϴ�.\n";
	else
		cout << "pa�� rc ���� �ۿ� �ִ� ��ǥ�Դϴ�.\n";
	if (rc.PtlnRect(pb))
		cout << "pb�� rc ���� �ȿ� �ִ� ��ǥ�Դϴ�.\n";
	else
		cout << "pb�� rc ���� �ۿ� �ִ� ��ǥ�Դϴ�.\n";
	return 0;
}
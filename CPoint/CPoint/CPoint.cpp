#include <iostream>
using namespace std;

typedef struct tagPOINT {
	int x;
	int y;
}POINT;

class CPoint
{
public:
	int x;
	int y;
	CPoint();
	CPoint(int dx, int dy);
	~CPoint();

	void Offset(int xOffset, int yOffset);

	void operator += (CPoint pt);
	bool operator == (CPoint point) const;
};

CPoint::CPoint()
{

}

CPoint::CPoint(int dx, int dy)
{
	this->x = dx;
	this->y = dy;
}

CPoint::~CPoint()
{

}

void CPoint::Offset(int xOffset, int yOffset)
{
	this->x += xOffset;
	this->y += yOffset;
}

void CPoint::operator += (CPoint pt)
{
	this->x += pt.x;
	this->y += pt.y;
}

bool CPoint::operator == (CPoint point) const
{
	if (x == point.x && y == point.y)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	POINT pa = { 100,200 }, pb = { 100, 100 };
	cout << "�̵� �� pa x��ǥ = " << pa.x << " y��ǥ = " << pa.y << endl;
	pa.x += 10;
	pa.y -= 10;
	cout << "�̵� �� pa x��ǥ = " << pa.x << " y��ǥ = " << pa.y << endl;
	pa.x += pb.x;
	pa.y += pb.y;
	cout << "���� �� pa x��ǥ = " << pa.x << " y��ǥ = " << pa.y << endl;

	CPoint pc(100, 200), pd(100, 100), pe(100, 100);
	cout << "�̵� �� pa x��ǥ = " << pc.x << " y��ǥ = " << pc.y << endl;
	pc.Offset(10, -10);
	cout << "�̵� �� pa x��ǥ = " << pc.x << " y��ǥ = " << pc.y << endl;
	pc += pd;
	cout << "���� �� pa x��ǥ = " << pc.x << " y��ǥ = " << pc.y << endl;
	if (pc == pd)
		cout << "pc�� pd�� ����" << endl;
	else
		cout << "pc�� pd�� �ٸ���" << endl;
	if (pd == pe)
		cout << "pd�� pe�� ����" << endl;
	else
		cout << "pd�� pe�� �ٸ���" << endl;

	return 0;
}
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
	cout << "ÀÌµ¿ Àü pa xÁÂÇ¥ = " << pa.x << " yÁÂÇ¥ = " << pa.y << endl;
	pa.x += 10;
	pa.y -= 10;
	cout << "ÀÌµ¿ ÈÄ pa xÁÂÇ¥ = " << pa.x << " yÁÂÇ¥ = " << pa.y << endl;
	pa.x += pb.x;
	pa.y += pb.y;
	cout << "Áõ°¡ ÈÄ pa xÁÂÇ¥ = " << pa.x << " yÁÂÇ¥ = " << pa.y << endl;

	CPoint pc(100, 200), pd(100, 100), pe(100, 100);
	cout << "ÀÌµ¿ Àü pa xÁÂÇ¥ = " << pc.x << " yÁÂÇ¥ = " << pc.y << endl;
	pc.Offset(10, -10);
	cout << "ÀÌµ¿ ÈÄ pa xÁÂÇ¥ = " << pc.x << " yÁÂÇ¥ = " << pc.y << endl;
	pc += pd;
	cout << "Áõ°¡ ÈÄ pa xÁÂÇ¥ = " << pc.x << " yÁÂÇ¥ = " << pc.y << endl;
	if (pc == pd)
		cout << "pc¿Í pd´Â °°´Ù" << endl;
	else
		cout << "pc¿Í pd´Â ´Ù¸£´Ù" << endl;
	if (pd == pe)
		cout << "pd¿Í pe´Â °°´Ù" << endl;
	else
		cout << "pd¿Í pe´Â ´Ù¸£´Ù" << endl;

	return 0;
}
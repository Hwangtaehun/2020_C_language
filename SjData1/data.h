#pragma once

// CData 명령 대상입니다.

class CData : public CObject
{
public:
	CData();
	CData(const CData & param);
	CData& operator=(const CData& param);
	virtual ~CData();
private:
	CPoint m_Point;
	int m_nSize;
	int m_nWidth;
	COLORREF m_penColor;
	COLORREF m_burshColor;
public:
	void Serialize(CArchive & ar);
	void SetData(CPoint point, int nSize, int nWidth, COLORREF penColor, COLORREF brushColor);
	void ModifyPoint(int x, int y);
	CPoint GetPoint();
	int GetSize();
	int GetWidth();
	COLORREF GetPenColor();
	COLORREF GetBurshColor();
};



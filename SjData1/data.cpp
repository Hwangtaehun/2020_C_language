// data.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjData1.h"
#include "data.h"


// CData

CData::CData()
{
	m_nSize = 0;
	m_nWidth = 0;
}

CData::CData(const CData& param)
{
	TRACE(_T("복사 생성자 실행\n"));
	m_Point = param.m_Point;
	m_nSize = param.m_nSize;
	m_nWidth = param.m_nWidth;
	m_penColor = param.m_penColor;
	m_burshColor = param.m_burshColor;
}

CData& CData::operator=(const CData& param)
{
	TRACE(_T("대입연산자 실행\n"));
	if (this != &param)
	{
		m_Point = param.m_Point;
		m_nSize = param.m_nSize;
		m_nWidth = param.m_nWidth;
		m_penColor = param.m_penColor;
		m_burshColor = param.m_burshColor;
	}
	return *this;
}

CData::~CData()
{
}


// CData 멤버 함수


void CData::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		ar << m_Point;
		ar << m_nSize;
		ar << m_nWidth;
		ar << m_penColor;
		ar << m_burshColor;
	}
	else
	{
		ar >> m_Point;
		ar >> m_nSize;
		ar >> m_nWidth;
		ar >> m_penColor;
		ar >> m_burshColor;
	}
}


void CData::SetData(CPoint point, int nSize, int nWidth, COLORREF penColor, COLORREF brushColor)
{
	m_Point = point;
	m_nSize = nSize;
	m_nWidth = nWidth;
	m_penColor = penColor;
	m_burshColor = brushColor;
}


void CData::ModifyPoint(int x, int y)
{
	m_Point.x += x;
	m_Point.y += y;
}


CPoint CData::GetPoint()
{
	return CPoint(m_Point);
}


int CData::GetSize()
{
	return m_nSize;
}


int CData::GetWidth()
{
	return m_nWidth;
}


COLORREF CData::GetPenColor()
{
	return COLORREF(m_penColor);
}


COLORREF CData::GetBurshColor()
{
	return COLORREF(m_burshColor);
}

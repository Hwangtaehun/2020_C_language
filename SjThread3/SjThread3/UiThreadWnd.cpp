// UiThreadWnd.cpp: 구현 파일
//
//#include "stdafx.h"
#include "pch.h"
#include "SjThread3.h"
#include "UiThreadWnd.h"


// CUiThreadWnd

IMPLEMENT_DYNCREATE(CUiThreadWnd, CFrameWnd)

CUiThreadWnd::CUiThreadWnd()
{
	Create(NULL, _T("User Interface Thread"));
	MoveWindow(300, 200, 300, 200);
	SetTimer(0, 300, NULL);
}

CUiThreadWnd::~CUiThreadWnd()
{
}


BEGIN_MESSAGE_MAP(CUiThreadWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CUiThreadWnd 메시지 처리기


void CUiThreadWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	PostMessage(WM_CLOSE, 0, 0);
	CFrameWnd::OnLButtonDown(nFlags, point);
}


void CUiThreadWnd::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CPoint point = { 100, 100 };
	static int m_nSize = 10;
	dc.Ellipse(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
	if (m_nSize > 100)
	{
		dc.SelectObject(GetStockObject(WHITE_PEN));
		dc.Ellipse(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
		dc.SelectObject(GetStockObject(BLACK_PEN));
		m_nSize = 5;
	}
	else
	{
		m_nSize += 5;
	}
	CFrameWnd::OnTimer(nIDEvent);
}

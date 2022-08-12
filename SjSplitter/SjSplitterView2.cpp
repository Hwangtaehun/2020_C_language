// SjSplitterView2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjSplitter.h"
#include "SjSplitterDoc.h"
#include "SjSplitterView2.h"


// CSjSplitterView2

IMPLEMENT_DYNCREATE(CSjSplitterView2, CView)

CSjSplitterView2::CSjSplitterView2()
{
	m_nSize = 20;
}

CSjSplitterView2::~CSjSplitterView2()
{
}

BEGIN_MESSAGE_MAP(CSjSplitterView2, CView)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_ONE, &CSjSplitterView2::OnOne)
	ON_COMMAND(IDM_TWO, &CSjSplitterView2::OnTwo)
	ON_COMMAND(IDM_THREE, &CSjSplitterView2::OnThree)
END_MESSAGE_MAP()

#ifdef _DEBUG
CSjSplitterDoc* CSjSplitterView2::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjSplitterDoc)));
	return (CSjSplitterDoc*)m_pDocument;
}
#endif //_DEBUG

// CSjSplitterView2 그리기입니다.

void CSjSplitterView2::OnDraw(CDC* pDC)
{
	CSjSplitterDoc* pDoc = GetDocument();
	for (int i = 0; i < pDoc->m_nCnt; i++)
	{
		DrawEllipse(pDC, pDoc->m_Data[i]);
	}
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CSjSplitterView2 진단입니다.

#ifdef _DEBUG
void CSjSplitterView2::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSjSplitterView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSjSplitterView2 메시지 처리기입니다.


void CSjSplitterView2::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC  dc(this);
	DrawEllipse(&dc, point);
	CSjSplitterDoc* pDoc = GetDocument();
	if (pDoc->m_nCnt < 30)
	{
		pDoc->m_Data[pDoc->m_nCnt] = point;
		pDoc->m_nCnt++;
	}
	/*Invalidate(TRUE);*/
	pDoc->UpdateAllViews(NULL);
	CView::OnRButtonDown(nFlags, point);
}


void CSjSplitterView2::DrawEllipse(CDC * pDC, CPoint point)
{
	pDC->Ellipse(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
}


void CSjSplitterView2::OnOne()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 10;
	Invalidate();
}


void CSjSplitterView2::OnTwo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 20;
	Invalidate();
}


void CSjSplitterView2::OnThree()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 30;
	Invalidate();
}

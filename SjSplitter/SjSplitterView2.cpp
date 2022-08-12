// SjSplitterView2.cpp : ���� �����Դϴ�.
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
CSjSplitterDoc* CSjSplitterView2::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjSplitterDoc)));
	return (CSjSplitterDoc*)m_pDocument;
}
#endif //_DEBUG

// CSjSplitterView2 �׸����Դϴ�.

void CSjSplitterView2::OnDraw(CDC* pDC)
{
	CSjSplitterDoc* pDoc = GetDocument();
	for (int i = 0; i < pDoc->m_nCnt; i++)
	{
		DrawEllipse(pDC, pDoc->m_Data[i]);
	}
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CSjSplitterView2 �����Դϴ�.

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


// CSjSplitterView2 �޽��� ó�����Դϴ�.


void CSjSplitterView2::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 10;
	Invalidate();
}


void CSjSplitterView2::OnTwo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 20;
	Invalidate();
}


void CSjSplitterView2::OnThree()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 30;
	Invalidate();
}

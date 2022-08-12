
// SjSplitterView.cpp : CSjSplitterView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjSplitter.h"
#endif

#include "SjSplitterDoc.h"
#include "SjSplitterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjSplitterView

IMPLEMENT_DYNCREATE(CSjSplitterView, CView)

BEGIN_MESSAGE_MAP(CSjSplitterView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_ONE, &CSjSplitterView::OnOne)
	ON_COMMAND(IDM_TWO, &CSjSplitterView::OnTwo)
	ON_COMMAND(IDM_THREE, &CSjSplitterView::OnThree)
END_MESSAGE_MAP()

// CSjSplitterView ����/�Ҹ�

CSjSplitterView::CSjSplitterView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_nSize = 10;
}

CSjSplitterView::~CSjSplitterView()
{
}

BOOL CSjSplitterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjSplitterView �׸���

void CSjSplitterView::OnDraw(CDC* pDC)
{
	CSjSplitterDoc* pDoc = GetDocument();
	for (int i = 0; i < pDoc->m_nCnt; i++)
	{
		DrawRect(pDC, pDoc->m_Data[i]);
	}
	/*ASSERT_VALID(pDoc);
	if (!pDoc)
		return;*/

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjSplitterView �μ�

BOOL CSjSplitterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjSplitterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjSplitterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjSplitterView ����

#ifdef _DEBUG
void CSjSplitterView::AssertValid() const
{
	CView::AssertValid();
}

void CSjSplitterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjSplitterDoc* CSjSplitterView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjSplitterDoc)));
	return (CSjSplitterDoc*)m_pDocument;
}
#endif //_DEBUG


// CSjSplitterView �޽��� ó����


void CSjSplitterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC  dc(this);
	DrawRect(&dc, point);
	CSjSplitterDoc* pDoc = GetDocument();
	if (pDoc->m_nCnt < 30)
	{
		pDoc->m_Data[pDoc->m_nCnt] = point;
		pDoc->m_nCnt++;
	}
	/*Invalidate(TRUE);*/
	pDoc->UpdateAllViews(NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CSjSplitterView::DrawRect(CDC * pDC, CPoint point)
{
	pDC->Rectangle(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
}


void CSjSplitterView::OnOne()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 10;
	Invalidate();
}


void CSjSplitterView::OnTwo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 20;
	Invalidate();
}


void CSjSplitterView::OnThree()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 30;
	Invalidate();
}

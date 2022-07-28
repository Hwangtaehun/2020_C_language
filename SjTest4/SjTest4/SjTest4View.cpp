
// SjTest4View.cpp : CSjTest4View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjTest4.h"
#endif

#include "SjTest4Doc.h"
#include "SjTest4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjTest4View

IMPLEMENT_DYNCREATE(CSjTest4View, CView)

BEGIN_MESSAGE_MAP(CSjTest4View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSjTest4View ����/�Ҹ�

CSjTest4View::CSjTest4View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSjTest4View::~CSjTest4View()
{
}

BOOL CSjTest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjTest4View �׸���

void CSjTest4View::OnDraw(CDC* /*pDC*/)
{
	CSjTest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjTest4View �μ�

BOOL CSjTest4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjTest4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjTest4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjTest4View ����

#ifdef _DEBUG
void CSjTest4View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest4Doc* CSjTest4View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest4Doc)));
	return (CSjTest4Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest4View �޽��� ó����


void CSjTest4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	SetTimer(0, 50, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CSjTest4View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	KillTimer(0);
	CView::OnRButtonDown(nFlags, point);
}


void CSjTest4View::OnTimer(UINT nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//MessageBeep(1);
	CDC *pDC = GetDC();
	CRect rr;
	GetClientRect(&rr);
	CPen pen, *pPen;
	pen.CreatePen(PS_SOLID, rand() % 5 + 1, RGB(rand() % 256, rand() % 256, rand() % 256));
	pPen = (CPen*)pDC->SelectObject(&pen);
	CBrush br, *pBr;
	br.CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
	pBr = (CBrush *)pDC->SelectObject(&br);
	//pDC->Rectangle(rand() % 400, rand() % 200, rand() % 400, rand() % 200);
	//pDC->Rectangle(rand() % rr.Width(), rand() % rr.Height(), rand() % rr.Width(), rand() % rr.Height());
	if (nIDEvent == 0)
	{
		pDC->Rectangle(rand() % rr.Width(), rand() % rr.Height(), rand() % rr.Width(), rand() % rr.Height());
	}
	else
	{
		pDC->Ellipse(rand() % rr.Width(), rand() % rr.Height(), rand() % rr.Width(), rand() % rr.Height());
	}
	pDC->SelectObject(pPen);
	pDC->SelectObject(pBr);
	pen.DeleteObject();
	br.DeleteObject();
	ReleaseDC(pDC);
	CView::OnTimer(nIDEvent);
}


void CSjTest4View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(1, 100, NULL);
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


void CSjTest4View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

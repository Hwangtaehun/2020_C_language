
// SjData1View.cpp : CSjData1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjData1.h"
#endif

#include "SjData1Doc.h"
#include "SjData1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjData1View

IMPLEMENT_DYNCREATE(CSjData1View, CView)

BEGIN_MESSAGE_MAP(CSjData1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_PEN_WIDTH1, &CSjData1View::OnPenWidth1)
	ON_COMMAND(IDM_PEN_WIDTH2, &CSjData1View::OnPenWidth2)
	ON_COMMAND(IDM_PEN_WIDTH3, &CSjData1View::OnPenWidth3)
	ON_COMMAND(IDM_PEN_RED, &CSjData1View::OnPenRed)
	ON_COMMAND(IDM_PEN_GREEN, &CSjData1View::OnPenGreen)
	ON_COMMAND(IDM_PEN_BLUE, &CSjData1View::OnPenBlue)
	ON_COMMAND(IDM_BRUSH_RED, &CSjData1View::OnBrushRed)
	ON_COMMAND(IDM_BRUSH_GREEN, &CSjData1View::OnBrushGreen)
	ON_COMMAND(IDM_BRUSH_BLUE, &CSjData1View::OnBrushBlue)
	ON_COMMAND(IDM_PEN_CUSTOM, &CSjData1View::OnPenCustom)
	ON_COMMAND(IDM_BRUSH_CUSTOM, &CSjData1View::OnBrushCustom)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_ONE, &CSjData1View::OnOne)
	ON_COMMAND(IDM_TWO, &CSjData1View::OnTwo)
	ON_COMMAND(IDM_THREE, &CSjData1View::OnThree)
END_MESSAGE_MAP()

// CSjData1View ����/�Ҹ�

CSjData1View::CSjData1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_nSize = 10;
	m_nWidth = 3;
	m_penColor = RGB(0, 0, 0);
	m_brushColor = RGB(255, 255, 255);
}

CSjData1View::~CSjData1View()
{
}

BOOL CSjData1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjData1View �׸���

void CSjData1View::OnDraw(CDC* pDC)
{
	CSjData1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->m_nCnt; i++)
	{
		DrawRect(pDC, pDoc->m_aPoint[i], pDoc->m_aSize[i], pDoc->m_aWidth[i], pDoc->m_aPenColor[i], pDoc->m_aBurshColor[i]);
	}

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjData1View �μ�

BOOL CSjData1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjData1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjData1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjData1View ����

#ifdef _DEBUG
void CSjData1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjData1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjData1Doc* CSjData1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjData1Doc)));
	return (CSjData1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjData1View �޽��� ó����


void CSjData1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CSjData1Doc* pDoc = GetDocument();
	if (pDoc->m_nCnt < 30)
	{
		pDoc->m_aPoint[pDoc->m_nCnt] = point;
		pDoc->m_aSize[pDoc->m_nCnt] = m_nSize;
		pDoc->m_aWidth[pDoc->m_nCnt] = m_nWidth;
		pDoc->m_aPenColor[pDoc->m_nCnt] = m_penColor;
		pDoc->m_aBurshColor[pDoc->m_nCnt] = m_brushColor;
		DrawRect(&dc, pDoc->m_aPoint[pDoc->m_nCnt], pDoc->m_aSize[pDoc->m_nCnt], pDoc->m_aWidth[pDoc->m_nCnt], pDoc->m_aPenColor[pDoc->m_nCnt], pDoc->m_aBurshColor[pDoc->m_nCnt]);
		pDoc->m_nCnt++;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CSjData1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_nSize += 5;
	CView::OnRButtonDown(nFlags, point);
}



void CSjData1View::DrawRect(CDC * pDC, CPoint point)
{
	pDC->Rectangle(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
}


void CSjData1View::DrawRect(CDC * pDC, CPoint point, int nSize)
{
	pDC->Rectangle(point.x - nSize, point.y - nSize, point.x + nSize, point.y + nSize);
}


void CSjData1View::DrawRect(CDC* pDC, CPoint point, int nSize, int nWidth, COLORREF penColor, COLORREF brushColor)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	CPen pen, * pPen;
	pen.CreatePen(PS_SOLID, nWidth, penColor);
	pPen = (CPen*)pDC->SelectObject(&pen);

	CBrush brush, * pBrush;
	brush.CreateSolidBrush(brushColor);
	pBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(point.x - nSize, point.y - nSize, point.x + nSize, point.y + nSize);
	pDC->SelectObject(pPen);
	pDC->SelectObject(pBrush);
}


void CSjData1View::OnPenWidth1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nWidth = 1;
}


void CSjData1View::OnPenWidth2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nWidth = 2;
}


void CSjData1View::OnPenWidth3()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nWidth = 3;
}


void CSjData1View::OnPenRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(255, 0, 0);
}


void CSjData1View::OnPenGreen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(0, 255, 0);
}


void CSjData1View::OnPenBlue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(0, 0, 255);
}


void CSjData1View::OnBrushRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_brushColor = RGB(255, 0, 0);
}


void CSjData1View::OnBrushGreen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_brushColor = RGB(0, 255, 0);
}


void CSjData1View::OnBrushBlue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_brushColor = RGB(0, 0, 255);
}


void CSjData1View::OnPenCustom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog dlg(m_penColor);

	if (dlg.DoModal() == IDOK)
	{
		m_penColor = dlg.GetColor();
	}
}


void CSjData1View::OnBrushCustom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog dlg(m_brushColor);

	if (dlg.DoModal() == IDOK)
	{
		m_brushColor = dlg.GetColor();
	}
}


void CSjData1View::OnOne()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 10;
}


void CSjData1View::OnTwo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 20;
}


void CSjData1View::OnThree()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 30;
}

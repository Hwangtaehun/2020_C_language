
// SjTest6View.cpp : CSjTest6View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjTest6.h"
#endif

#include "SjTest6Doc.h"
#include "SjTest6View.h"
#include "TestDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjTest6View

IMPLEMENT_DYNCREATE(CSjTest6View, CView)

BEGIN_MESSAGE_MAP(CSjTest6View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_RED, &CSjTest6View::OnRed)
	ON_COMMAND(IDM_GREEN, &CSjTest6View::OnGreen)
	ON_COMMAND(IDM_BLUE, &CSjTest6View::OnBlue)
	ON_COMMAND(IDM_ONE, &CSjTest6View::OnOne)
	ON_COMMAND(IDM_THREE, &CSjTest6View::OnThree)
	ON_COMMAND(IDM_FIVE, &CSjTest6View::OnFive)
	ON_COMMAND(IDM_LINE1, &CSjTest6View::OnLine1)
	ON_COMMAND(IDM_DIAMOND, &CSjTest6View::OnDiamond)
	ON_COMMAND(IDM_ROSE, &CSjTest6View::OnRose)
	ON_COMMAND(IDM_LISSAJOUS, &CSjTest6View::OnLissajous)
	ON_COMMAND(IDM_CUSTOM, &CSjTest6View::OnCustom)
	ON_COMMAND(IDM_Custom1, &CSjTest6View::OnCustom1)
END_MESSAGE_MAP()

// CSjTest6View ����/�Ҹ�

CSjTest6View::CSjTest6View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_nSize = 0;
	m_nPattern = 0;
}

CSjTest6View::~CSjTest6View()
{
}

BOOL CSjTest6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjTest6View �׸���

void CSjTest6View::OnDraw(CDC* pDC)
{
	CSjTest6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen, *pPen;
	pen.CreatePen(PS_SOLID, m_nSize, m_penColor);
	pPen = (CPen *)pDC->SelectObject(&pen);
	switch (m_nPattern)
	{
	case 1:
		GeoLine(pDC);
		break;
	case 2:
		GeoDiamond(pDC);
		break;
	case 3:
		GeoRose(pDC);
		break;
	case 4:
		GeoLissajous(pDC);
		break;
	}
	m_nPattern = 0;
	pDC->SelectObject(pPen);
	pen.DeleteObject();
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjTest6View �μ�

BOOL CSjTest6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjTest6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjTest6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjTest6View ����

#ifdef _DEBUG
void CSjTest6View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest6Doc* CSjTest6View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest6Doc)));
	return (CSjTest6Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest6View �޽��� ó����


void CSjTest6View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nFlags & MK_LBUTTON)
	{
		CClientDC dc(this);
		CPen pen, *pPen;
		pen.CreatePen(PS_SOLID, m_nSize, m_penColor);
		pPen = (CPen *)dc.SelectObject(&pen);

		dc.MoveTo(m_pt1);
		dc.LineTo(point);
		m_pt1 = point;
		dc.SelectObject(pPen);
		pen.DeleteObject();
	}
	CView::OnMouseMove(nFlags, point);
}


void CSjTest6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_pt1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CSjTest6View::OnRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(255, 0, 0); 
}


void CSjTest6View::OnGreen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(0, 255, 0);
}


void CSjTest6View::OnBlue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(0, 0, 255);
}


void CSjTest6View::OnOne()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 1;
}


void CSjTest6View::OnThree()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 3;
}


void CSjTest6View::OnFive()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 5;
}

#define PI 3.141593
#define RD (PI/180.0)
#include "math.h"

void CSjTest6View::OnLine1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nPattern = 1;
	Invalidate();
}


void CSjTest6View::OnDiamond()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nPattern = 2;
	Invalidate();
}


void CSjTest6View::OnRose()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nPattern = 3;
	Invalidate();
}


void CSjTest6View::OnLissajous()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nPattern = 4;
	Invalidate();
}


int CSjTest6View::CenterLine(CDC * pDC, CRect rect)
{
	pDC->MoveTo(0, rect.Height() / 2);
	pDC->LineTo(rect.Width(), rect.Height() / 2);
	pDC->MoveTo(rect.Width() / 2, 0);
	pDC->LineTo(rect.Width() / 2, rect.Height());
	return 0;
}


void CSjTest6View::GeoLine(CDC * pDC)
{
	int angle;
	int radius = 150;
	int x1, y1, x2, y2;
	POINT center = { 200, 300 };
	CRect rect;
	GetClientRect(&rect);
	center.x = rect.Width() / 2;
	center.y = rect.Height() / 2;
	CenterLine(pDC, rect);
	for ( angle = 0; angle <= 360; angle += 5)
	{
		x1 = (int)(radius*cos(angle*RD));
		y1 = (int)(radius*sin(angle*RD));
		x2 = (int)(radius*cos((angle + 120)*RD));
		y2 = (int)(radius*sin((angle + 120)*RD));
		pDC->MoveTo(x1 + center.x, y1 + center.y);
		pDC->LineTo(x2 + center.x, y2 + center.y);
		Sleep(10);
	}
}


void CSjTest6View::GeoDiamond(CDC * pDC)
{
	int radius = 200;
	int x1, y1, x2, y2;
	int i, j;
	double angle = 360.0 / 16.0;
	POINT center = { 200, 300 };
	CRect rect;
	GetClientRect(&rect);
	center.x = rect.Width() / 2;
	center.y = rect.Height() / 2;
	CenterLine(pDC, rect);
	for ( i = 0; i <= 14; i++)
	{
		x1 = (int)(radius*cos(i*angle*RD));
		y1 = (int)(radius*sin(i*angle*RD));
		for ( j = 0; j <= 15; j++)
		{
			x2 = (int)(radius*cos((j * angle)*RD));
			y2 = (int)(radius*sin((j * angle)*RD));
			pDC->MoveTo(x1 + center.x, y1 + center.y);
			pDC->LineTo(x2 + center.x, y2 + center.y);
			Sleep(100);
		}
	}
}


void CSjTest6View::GeoRose(CDC * pDC)
{
	CRect rect;
	GetClientRect(&rect);
	POINT center = { 200, 300 };
	center.x = rect.Width() / 2;
	center.y = rect.Height() / 2;
	int d;
	double x, y, radi;

	for (d = 0; d <= 1080; d += 4)
	{
		radi = 100 * sin(4 * d / 3 * RD);
		x = radi * cos(d * RD);
		y = radi * sin(d * RD);

		if (d == 0)
			pDC->MoveTo((int)x + center.x, (int)y + center.y);
		else
			pDC->LineTo((int)x + center.x, (int)y + center.y);
		Sleep(10);
	}
}


void CSjTest6View::GeoLissajous(CDC * pDC)
{
	int d;
	short x, y;
	for (x = 0; x <= 250; x += 20)
	{
		pDC->MoveTo(x, 100);
		pDC->LineTo(x, 300);
	}
	for (y = 100; y <= 300; y += 20)
	{
		pDC->MoveTo(50, y);
		pDC->LineTo(250, y);
	}
	for (d = 0; d <= 360; d += 2)
	{
		x = (int)(100 * sin(2 * d * RD) + 150);
		y = (int)(-100 * sin(3 * d * RD) + 200);
		if (d == 0)
			pDC->MoveTo(x, y);
		else
			pDC->LineTo(x, y);
		Sleep(10);
	}
}


void CSjTest6View::OnCustom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog dlg(m_penColor);
	if (dlg.DoModal() == IDOK)
	{
		m_penColor = dlg.GetColor();
	}
}



void CSjTest6View::OnCustom1()
{
	/*CFontDialog dlg(&m_logFont);
	if (dlg.DoModal() == IDOK)
	{
		dlg.GetCurrentFont(&m_logFont);
	}*/
	CTestDlg0 dd;
	dd.DoModal();
}

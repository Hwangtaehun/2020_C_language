
// SjTest6View.cpp : CSjTest6View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CSjTest6View 생성/소멸

CSjTest6View::CSjTest6View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nSize = 0;
	m_nPattern = 0;
}

CSjTest6View::~CSjTest6View()
{
}

BOOL CSjTest6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjTest6View 그리기

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
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjTest6View 인쇄

BOOL CSjTest6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjTest6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjTest6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjTest6View 진단

#ifdef _DEBUG
void CSjTest6View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest6Doc* CSjTest6View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest6Doc)));
	return (CSjTest6Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest6View 메시지 처리기


void CSjTest6View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pt1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CSjTest6View::OnRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_penColor = RGB(255, 0, 0); 
}


void CSjTest6View::OnGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_penColor = RGB(0, 255, 0);
}


void CSjTest6View::OnBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_penColor = RGB(0, 0, 255);
}


void CSjTest6View::OnOne()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 1;
}


void CSjTest6View::OnThree()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 3;
}


void CSjTest6View::OnFive()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 5;
}

#define PI 3.141593
#define RD (PI/180.0)
#include "math.h"

void CSjTest6View::OnLine1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nPattern = 1;
	Invalidate();
}


void CSjTest6View::OnDiamond()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nPattern = 2;
	Invalidate();
}


void CSjTest6View::OnRose()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nPattern = 3;
	Invalidate();
}


void CSjTest6View::OnLissajous()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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

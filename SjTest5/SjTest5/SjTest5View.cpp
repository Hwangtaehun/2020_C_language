
// SjTest5View.cpp : CSjTest5View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjTest5.h"
#endif

#include "SjTest5Doc.h"
#include "SjTest5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjTest5View

IMPLEMENT_DYNCREATE(CSjTest5View, CView)

BEGIN_MESSAGE_MAP(CSjTest5View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSjTest5View 생성/소멸

#define RADIUS 10
#define STEP 5

CSjTest5View::CSjTest5View()
: m_sw(0)
, nX(RADIUS)
, nY(RADIUS)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	nCX = STEP;
	nCY = STEP;
	m_nHeight = 0;
	m_nWidth = 0;
	m_nRx = 0;
	m_nRy = 0;
}

CSjTest5View::~CSjTest5View()
{
}

BOOL CSjTest5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjTest5View 그리기

void CSjTest5View::OnDraw(CDC* /*pDC*/)
{
	CSjTest5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	m_sw = 0;
	GetClientRect(&m_Rect);
	m_nWidth = m_Rect.Width();
	m_nHeight = m_Rect.Height();
	DrawRacket(TRUE);
	DrawRacketOther(TRUE);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjTest5View 인쇄

BOOL CSjTest5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjTest5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjTest5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjTest5View 진단

#ifdef _DEBUG
void CSjTest5View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest5Doc* CSjTest5View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest5Doc)));
	return (CSjTest5Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest5View 메시지 처리기


void CSjTest5View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(0, 30, NULL);
	GetClientRect(&m_Rect);
	m_nWidth = m_Rect.Width();
	m_nHeight = m_Rect.Height();
	m_nRx = m_nHeight / 2 - 50;
	m_nRy = m_nHeight / 2 - 50;
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CSjTest5View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(0);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CSjTest5View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	//static int nX = RADIUS, nY = RADIUS;
	//static int nCX = STEP, nCY = STEP;
	//static int m_sw = 0;
	//CRect rect;
	//GetClientRect(&rect);
	//dc.SelectStockObject(WHITE_BRUSH);
	//dc.SelectStockObject(WHITE_PEN);

	CBrush brush, *pOldBrush;
	brush.CreateSolidBrush(RGB(255, 0, 0));
	pOldBrush = (CBrush*)dc.SelectObject(&brush);
	dc.SetROP2(R2_XORPEN);

	if (m_sw == 0)
		m_sw = 1;
	else
		dc.Ellipse(nX - RADIUS, nY - RADIUS, nX + RADIUS, nY + RADIUS);

	if (nX < RADIUS)
	{
		if(nY > m_nRx - RADIUS && nY < m_nRx + RADIUS + 100)
			nCX = STEP;
		else
		{
			MessageBeep(1);
			nX = RADIUS;
			nY = RADIUS;
			nCX = STEP;
			nCY = STEP;
		}
	}
		
	else if (nX > m_nWidth - RADIUS)
	{
		if(nY > m_nRy - RADIUS && nY < m_nRy + RADIUS + 100)
			nCX = -STEP;
		else
		{
			MessageBeep(1);
			nX = RADIUS;
			nY = RADIUS;
			nCX = STEP;
			nCY = STEP;
		}
	}	
	nX += nCX;
	
	if (nY < RADIUS)
		nCY = STEP;
	else if (nY > m_nHeight - RADIUS)
		nCY = -STEP;
	nY += nCY;

	dc.Ellipse(nX - RADIUS, nY - RADIUS, nX + RADIUS, nY + RADIUS);

	dc.SelectObject(pOldBrush);
	brush.DeleteObject();
	CView::OnTimer(nIDEvent);
}


void CSjTest5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nX < point.x)
		nCX = STEP;
	else if (nX > point.x)
		nCX = -STEP;
	if (nY < point.y)
		nCY = STEP;
	else if (nY >point.y)
		nCY = -STEP;
	CView::OnLButtonDown(nFlags, point);
}


BOOL CSjTest5View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->wParam)
	{
	case 'W':
		MoveLeft();
		return TRUE;

	case 'S':
		MoveRight();
		return TRUE;

	case VK_UP:
		MoveUp();
		return TRUE;
	case VK_DOWN:
		MoveDown();
		return TRUE;
	}
	return CView::PreTranslateMessage(pMsg);
}

void CSjTest5View::MoveLeft()
{
	DrawRacket(false);
	m_nRx -= 10;
	DrawRacket(TRUE);
}

void CSjTest5View::MoveRight()
{
	DrawRacket(false);
	m_nRx += 10;
	DrawRacket(TRUE);
}

void CSjTest5View::DrawRacket(bool bFlag)
{
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);

	if (bFlag)
		dc.SelectStockObject(LTGRAY_BRUSH);
	else
		dc.SelectStockObject(WHITE_BRUSH);

	dc.Rectangle(0, m_nRx + 100, 20, m_nRx);
}


void CSjTest5View::MoveUp()
{
	// TODO: 여기에 구현 코드 추가.
	DrawRacketOther(false);
	m_nRy -= 10;
	DrawRacketOther(TRUE);
}


void CSjTest5View::MoveDown()
{
	// TODO: 여기에 구현 코드 추가.
	DrawRacketOther(false);
	m_nRy += 10;
	DrawRacketOther(TRUE);
}


void CSjTest5View::DrawRacketOther(bool bFlag)
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);

	if (bFlag)
		dc.SelectStockObject(LTGRAY_BRUSH);
	else
		dc.SelectStockObject(WHITE_BRUSH);

	dc.Rectangle(m_nWidth, m_nRy + 100, m_nWidth - 20, m_nRy);
}

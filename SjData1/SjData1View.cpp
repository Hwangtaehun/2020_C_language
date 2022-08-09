
// SjData1View.cpp : CSjData1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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
END_MESSAGE_MAP()

// CSjData1View 생성/소멸

CSjData1View::CSjData1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nSize = 10;
}

CSjData1View::~CSjData1View()
{
}

BOOL CSjData1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjData1View 그리기

void CSjData1View::OnDraw(CDC* pDC)
{
	CSjData1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->m_nCnt; i++)
	{
		DrawRect(pDC, pDoc->m_aPoint[i], pDoc->m_aSize[i]);
	}

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjData1View 인쇄

BOOL CSjData1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjData1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjData1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjData1View 진단

#ifdef _DEBUG
void CSjData1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjData1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjData1Doc* CSjData1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjData1Doc)));
	return (CSjData1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjData1View 메시지 처리기


void CSjData1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CSjData1Doc* pDoc = GetDocument();
	if (pDoc->m_nCnt < 30)
	{
		pDoc->m_aPoint[pDoc->m_nCnt] = point;
		pDoc->m_aSize[pDoc->m_nCnt] = m_nSize;
		DrawRect(&dc, pDoc->m_aPoint[pDoc->m_nCnt], pDoc->m_aSize[pDoc->m_nCnt]);
		pDoc->m_nCnt++;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CSjData1View::DrawRect(CDC * pDC, CPoint point)
{
	pDC->Rectangle(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
}


void CSjData1View::DrawRect(CDC * pDC, CPoint point, int nSize)
{
	pDC->Rectangle(point.x - nSize, point.y - nSize, point.x + nSize, point.y + nSize);
}


void CSjData1View::OnPenWidth1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnPenWidth2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnPenWidth3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnPenRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnPenGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnPenBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnBrushRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnBrushGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnBrushBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnPenCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CSjData1View::OnBrushCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


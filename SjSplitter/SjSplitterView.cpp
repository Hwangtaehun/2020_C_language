
// SjSplitterView.cpp : CSjSplitterView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_ONE, &CSjSplitterView::OnOne)
	ON_COMMAND(IDM_TWO, &CSjSplitterView::OnTwo)
	ON_COMMAND(IDM_THREE, &CSjSplitterView::OnThree)
END_MESSAGE_MAP()

// CSjSplitterView 생성/소멸

CSjSplitterView::CSjSplitterView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nSize = 10;
}

CSjSplitterView::~CSjSplitterView()
{
}

BOOL CSjSplitterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjSplitterView 그리기

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

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjSplitterView 인쇄

BOOL CSjSplitterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjSplitterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjSplitterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjSplitterView 진단

#ifdef _DEBUG
void CSjSplitterView::AssertValid() const
{
	CView::AssertValid();
}

void CSjSplitterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjSplitterDoc* CSjSplitterView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjSplitterDoc)));
	return (CSjSplitterDoc*)m_pDocument;
}
#endif //_DEBUG


// CSjSplitterView 메시지 처리기


void CSjSplitterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 10;
	Invalidate();
}


void CSjSplitterView::OnTwo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 20;
	Invalidate();
}


void CSjSplitterView::OnThree()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 30;
	Invalidate();
}

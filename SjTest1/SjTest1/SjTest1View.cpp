
// SjTest1View.cpp: CSjTest1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjTest1.h"
#endif

#include "SjTest1Doc.h"
#include "SjTest1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjTest1View

IMPLEMENT_DYNCREATE(CSjTest1View, CView)

BEGIN_MESSAGE_MAP(CSjTest1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSjTest1View 생성/소멸

CSjTest1View::CSjTest1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nCnt = 0;
	m_nSize = 10;
}

CSjTest1View::~CSjTest1View()
{
}

BOOL CSjTest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjTest1View 그리기

void CSjTest1View::OnDraw(CDC* pDC)
{
	CSjTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < m_nCnt; i++)
	{
		DrawRect(pDC, m_Data[i]);
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjTest1View 인쇄

BOOL CSjTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjTest1View 진단

#ifdef _DEBUG
void CSjTest1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest1Doc* CSjTest1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest1Doc)));
	return (CSjTest1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest1View 메시지 처리기


void CSjTest1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC* pDC = GetDC();
	DrawRect(pDC, point);
	if (m_nCnt < 10)
	{
		m_Data[m_nCnt] = point;
		m_nCnt++;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CSjTest1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_nSize += 5;
	CView::OnRButtonDown(nFlags, point);
}


void CSjTest1View::DrawRect(CDC* pDC, CPoint point)
{
	// TODO: 여기에 구현 코드 추가.
	pDC->Rectangle(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
}

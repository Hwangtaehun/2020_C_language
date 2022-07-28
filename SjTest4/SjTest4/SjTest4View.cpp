
// SjTest4View.cpp : CSjTest4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSjTest4View 생성/소멸

CSjTest4View::CSjTest4View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjTest4View::~CSjTest4View()
{
}

BOOL CSjTest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjTest4View 그리기

void CSjTest4View::OnDraw(CDC* /*pDC*/)
{
	CSjTest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjTest4View 인쇄

BOOL CSjTest4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjTest4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjTest4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjTest4View 진단

#ifdef _DEBUG
void CSjTest4View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest4Doc* CSjTest4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest4Doc)));
	return (CSjTest4Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest4View 메시지 처리기


void CSjTest4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetTimer(0, 50, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CSjTest4View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	KillTimer(0);
	CView::OnRButtonDown(nFlags, point);
}


void CSjTest4View::OnTimer(UINT nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CSjTest4View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

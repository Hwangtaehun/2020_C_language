
// SjModelessView.cpp: CSjModelessView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjModeless.h"
#endif

#include "SjModelessDoc.h"
#include "SjModelessView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjModelessView

IMPLEMENT_DYNCREATE(CSjModelessView, CView)

BEGIN_MESSAGE_MAP(CSjModelessView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_VIEW, &CSjModelessView::OnView)
END_MESSAGE_MAP()

// CSjModelessView 생성/소멸

CSjModelessView::CSjModelessView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_strView = _T("CSjModelessView");
}

CSjModelessView::~CSjModelessView()
{
}

BOOL CSjModelessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjModelessView 그리기

void CSjModelessView::OnDraw(CDC* pDC)
{
	CSjModelessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CSjModelessApp* pApp = (CSjModelessApp*)AfxGetApp();

	CMainFrame* pFrm = (CMainFrame*)GetParentFrame();
	pDC->TextOut(10, 10, _T("m_strApp = ") + pApp->m_strApp);
	pDC->TextOut(10, 30, _T("m_strFrm = ") + pFrm->m_strFrm);
	pDC->TextOut(10, 50, _T("m_strDoc = ") + pDoc->m_strDoc);
	pDC->TextOut(10, 70, _T("m_strView = ") + this->m_strView);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjModelessView 인쇄

BOOL CSjModelessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjModelessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjModelessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjModelessView 진단

#ifdef _DEBUG
void CSjModelessView::AssertValid() const
{
	CView::AssertValid();
}

void CSjModelessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjModelessDoc* CSjModelessView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjModelessDoc)));
	return (CSjModelessDoc*)m_pDocument;
}
#endif //_DEBUG


// CSjModelessView 메시지 처리기


//void CSjModelessView::OnApp()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}


//void CSjModelessView::OnFrm()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}


//void CSjModelessView::OnDoc()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}


void CSjModelessView::OnView()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSjModelessApp* pApp = (CSjModelessApp*)AfxGetApp();
	CMainFrame* pFrm = (CMainFrame*)AfxGetMainWnd();
	CSjModelessDoc* pDoc = (CSjModelessDoc*)GetDocument();

	pApp->m_strApp = _T("View에서 대입");
	pFrm->m_strFrm = _T("View에서 대입");
	pDoc->m_strDoc = _T("View에서 대입");
	this->m_strView = _T("View에서 대입");

	Invalidate(TRUE);
}

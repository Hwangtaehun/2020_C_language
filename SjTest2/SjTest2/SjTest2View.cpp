
// SjTest2View.cpp: CSjTest2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjTest2.h"
#endif

#include "SjTest2Doc.h"
#include "SjTest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjTest2View

IMPLEMENT_DYNCREATE(CSjTest2View, CView)

BEGIN_MESSAGE_MAP(CSjTest2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSjTest2View 생성/소멸

CSjTest2View::CSjTest2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjTest2View::~CSjTest2View()
{
}

BOOL CSjTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjTest2View 그리기

void CSjTest2View::OnDraw(CDC* /*pDC*/)
{
	CSjTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjTest2View 인쇄

BOOL CSjTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjTest2View 진단

#ifdef _DEBUG
void CSjTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest2Doc* CSjTest2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest2Doc)));
	return (CSjTest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest2View 메시지 처리기


void CSjTest2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//CClientDC dc(this);
	//CFont font, * pFont;
	//LOGFONT LogFont;
	//LogFont.lfHeight = 100;
	//LogFont.lfEscapement = 200;
	//LogFont.lfItalic = TRUE;
	//LogFont.lfUnderline = 0;
	//LogFont.lfStrikeOut = 0;

	//font.CreateFontIndirect(&LogFont);
	//pFont = dc.SelectObject(&font);
	//dc.TextOut(point.x, point.y, _T("Sejong세종"), 8);
	//dc.SelectObject(pFont);
	//font.DeleteObject();

	CClientDC dc(this);
	int a, b;
	CString buf;
	CFont font, * pFont;
	font.CreatePointFont(120, _T("굴림체"), &dc);
	//font.CreatePointFont(120, _T("굴림"), &dc);
	pFont = (CFont*)dc.SelectObject(&font);
	a = 5;
	for (b = 0; b <= 9; b++)
	{
		buf.Format(_T(" % d * %d = %2d"), a, b, a * b);
		dc.TextOut(point.x, point.y + (b - 1) * 20, buf);
	}
	dc.SelectObject(pFont);
	font.DeleteObject();

	CView::OnLButtonDown(nFlags, point);
}

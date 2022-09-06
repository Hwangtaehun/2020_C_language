
// SjThread2View.cpp : CSjThread2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjThread2.h"
#endif

#include "SjThread2Doc.h"
#include "SjThread2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct DATA
{
	//HWND hWnd;
	CWnd* hWnd;
	CPoint point;
	int nSize;
};
BOOL g_bEnd = FALSE;
CWinThread *pThread;

UINT TestThread5(LPVOID IParam);

// CSjThread2View

IMPLEMENT_DYNCREATE(CSjThread2View, CView)

BEGIN_MESSAGE_MAP(CSjThread2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CSjThread2View 생성/소멸

CSjThread2View::CSjThread2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjThread2View::~CSjThread2View()
{
}

BOOL CSjThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjThread2View 그리기

void CSjThread2View::OnDraw(CDC* /*pDC*/)
{
	CSjThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjThread2View 인쇄

BOOL CSjThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjThread2View 진단

#ifdef _DEBUG
void CSjThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CSjThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjThread2Doc* CSjThread2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjThread2Doc)));
	return (CSjThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjThread2View 메시지 처리기

UINT TestThread5(LPVOID IParam)
{
	DATA *pData = (DATA *)IParam;
	//HDC hDC = ::GetDC(pData->hWnd);
	CClientDC dc(pData->hWnd);
	CPoint pt = pData->point;
	int size = 10;
	while (!g_bEnd)
	{
		Sleep(100);
		//Ellipse(hDC, pt.x - size, pt.y - size, pt.x + size, pt.y + size);
		dc.Ellipse(pt.x - size, pt.y - size, pt.x + size, pt.y + size);
		if (size > pData->nSize)
		{
			//SelectObject(hDC, GetStockObject(WHITE_PEN));
			dc.SelectObject(GetStockObject(WHITE_PEN));
			//Ellipse(hDC, pt.x - size, pt.y - size, pt.x + size, pt.y + size);
			dc.Ellipse(pt.x - size, pt.y - size, pt.x + size, pt.y + size);
			//SelectObject(hDC, GetStockObject(BLACK_PEN));
			dc.SelectObject(GetStockObject(BLACK_PEN));
			Sleep(1000);
			size = 5;
		}
		else
		{
			size += 5;
		}
	}
	delete pData;
	//::ReleaseDC(pData->hWnd, hDC);
	return 0;
}

void CSjThread2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	DATA *pData = new DATA;
	//pData->hWnd = this->m_hWnd;
	pData->hWnd = this;
	pData->point = point;
	pData->nSize = rand() % 100 + 30;
	g_bEnd = FALSE;

	pThread = AfxBeginThread(TestThread5, pData);
	if (pThread == NULL)
	{
		MessageBox(_T("Thread 생성오류"));
	}
	CView::OnLButtonDown(nFlags, point);
}


void CSjThread2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	g_bEnd = TRUE;
	CView::OnRButtonDown(nFlags, point);
}


void CSjThread2View::OnSuspend()
{
	//SuspendThread(pThread->m_hThread);
	pThread->SuspendThread();
}


void CSjThread2View::OnResume()
{
	ResumeThread(pThread->m_hThread);
	//pThread->ResumeThread();
}


void CSjThread2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON)
	{
		DATA *pData = new DATA;
		//pData->hWnd = this->m_hWnd;
		pData->hWnd = this;
		pData->point = point;
		pData->nSize = rand() % 100 + 30;
		g_bEnd = FALSE;
		pThread = AfxBeginThread(TestThread5, pData);
	}
	CView::OnMouseMove(nFlags, point);
}

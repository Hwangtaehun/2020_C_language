
// SjThead1View.cpp : CSjThead1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjThead1.h"
#endif

#include "SjThead1Doc.h"
#include "SjThead1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HANDLE hThread1;
struct DATA
{
	HWND hWnd;
	CPoint point;
};

DWORD WINAPI TestThread2(LPVOID IParam);
DWORD WINAPI TestThread3(LPVOID IParam);

// CSjThead1View

IMPLEMENT_DYNCREATE(CSjThead1View, CView)

BEGIN_MESSAGE_MAP(CSjThead1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSjThead1View 생성/소멸

CSjThead1View::CSjThead1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjThead1View::~CSjThead1View()
{
}

BOOL CSjThead1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjThead1View 그리기

void CSjThead1View::OnDraw(CDC* /*pDC*/)
{
	CSjThead1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjThead1View 인쇄

BOOL CSjThead1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjThead1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjThead1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjThead1View 진단

#ifdef _DEBUG
void CSjThead1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjThead1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjThead1Doc* CSjThead1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjThead1Doc)));
	return (CSjThead1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjThead1View 메시지 처리기


void CSjThead1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CClientDC dc(this);
	int size = 10;
	while (size < 100)
	{
		dc.Ellipse(point.x - size, point.y - size, point.x + size, point.y + size);
		size += 5;
		Sleep(200);
	}*/

	/*TestThread1(&point);
	DWORD ThreadID;
	hThread1 = CreateThread(NULL, 0, TestThread1, (LPVOID)&point, 0, &ThreadID);*/

	/*DWORD ThreadID;
	hThread1 = CreateThread(NULL, 0, TestThread2, (LPVOID)this->m_hWnd, 0, &ThreadID);*/

	DWORD ThreadID;
	DATA *pData = new DATA;

	pData->hWnd = this->m_hWnd;
	pData->point = point;
	hThread1 = CreateThread(NULL, 0, TestThread3, (LPVOID)pData, 0, &ThreadID);

	CView::OnLButtonDown(nFlags, point);
}


DWORD CSjThead1View::TestThread1(LPVOID IParam)
{
	CClientDC dc(this);
	int size = 10;
	CPoint *pt = (CPoint *)IParam;
	while (size < 100)
	{
		dc.Ellipse(pt->x - size, pt->y - size, pt->x + size, pt->y + size);
		size += 5;
		Sleep(200);
	}
	return 0;
}

DWORD WINAPI TestThread2(LPVOID IParam)
{
	HWND hWnd = (HWND)IParam;
	HDC hDC = ::GetDC(hWnd);
	int x, y;
	int size = 10;
	srand((unsigned int)time(NULL));
	rand(); rand();
	x = rand() % 400;
	y = rand() % 400;
	while (size < 100)
	{
		Ellipse(hDC, x - size, y - size, x + size, y + size);
		size += 5;
		Sleep(200);
	}
	::ReleaseDC(hWnd, hDC);
	return 0;
}

DWORD WINAPI TestThread3(LPVOID IParam)
{
	DATA *pData = (DATA *)IParam;
	HWND hWnd = pData->hWnd;
	int x = pData->point.x;
	int y = pData->point.y;
	HDC hDC = ::GetDC(hWnd);
	int size = 10;
	while (size < 100)
	{
		Ellipse(hDC, x - size, y - size, x + size, y + size);
		size += 5;
		Sleep(200);
	}
	delete pData;
	::ReleaseDC(hWnd, hDC);
	return 0;
}

void CSjThead1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	DWORD dwExitCode;
	GetExitCodeThread(hThread1, &dwExitCode);
	if (dwExitCode == STILL_ACTIVE)
	{
		TerminateThread(hThread1, NULL);
		CloseHandle(hThread1);
	}
	CView::OnRButtonDown(nFlags, point);
}


void CSjThead1View::OnSuspend()
{
	SuspendThread(hThread1);
}


void CSjThead1View::OnResume()
{
	ResumeThread(hThread1);
}

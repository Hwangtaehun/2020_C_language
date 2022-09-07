
// SjThread4View.cpp : CSjThread4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjThread4.h"
#endif

#include "SjThread4Doc.h"
#include "SjThread4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct DATA
{
	CWnd* hWnd;
	CPoint point;
	int nSize;
};

BOOL g_bEnd = FALSE;
int g_nSize = 10;
CWinThread *g_pThread1 = NULL;
CWinThread *g_pThread2 = NULL;
CWinThread *g_pThread3 = NULL;
CWinThread *g_pThread4 = NULL;

CCriticalSection gCsetion1, gCsetion2;
UINT TestCritical1(LPVOID IParam);
UINT TestCritical2(LPVOID IParam);

//CEvent gEvent;
CEvent gEventF(FALSE, FALSE);
CEvent gEventT(FALSE, TRUE);

UINT TestEvent1(LPVOID IParam);
UINT TestEvent2(LPVOID IParam);

// CSjThread4View

IMPLEMENT_DYNCREATE(CSjThread4View, CView)

BEGIN_MESSAGE_MAP(CSjThread4View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_CRITICALSECTIONTHREAD1, &CSjThread4View::OnCriticalSection1)
	ON_COMMAND(IDM_CRITICALSECTIONTHREAD2, &CSjThread4View::OnCriticalSection2)
	ON_COMMAND(IDM_CRITICALSECTIONTHREAD_EXIT, &CSjThread4View::OnCriticalSection3)
	ON_COMMAND(IDM_EVENT1, &CSjThread4View::OnEvent1)
	ON_COMMAND(IDM_EVENT2, &CSjThread4View::OnEvent2)
	ON_COMMAND(IDM_PULSE_EVENT, &CSjThread4View::OnPulseEvent)
	ON_COMMAND(IDM_RESETEVENT, &CSjThread4View::OnResetevent)
	ON_COMMAND(IDM_SETEVENT, &CSjThread4View::OnSetEvent)
END_MESSAGE_MAP()

// CSjThread4View 생성/소멸

CSjThread4View::CSjThread4View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjThread4View::~CSjThread4View()
{
}

BOOL CSjThread4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjThread4View 그리기

void CSjThread4View::OnDraw(CDC* /*pDC*/)
{
	CSjThread4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjThread4View 인쇄

BOOL CSjThread4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjThread4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjThread4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjThread4View 진단

#ifdef _DEBUG
void CSjThread4View::AssertValid() const
{
	CView::AssertValid();
}

void CSjThread4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjThread4Doc* CSjThread4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjThread4Doc)));
	return (CSjThread4Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjThread4View 메시지 처리기
UINT TestCritical1(LPVOID IParam)
{
	DATA *pData = (DATA *)IParam;
	CClientDC dc(pData->hWnd);
	CPoint pt = pData->point;
	while (!g_bEnd)
	{
		dc.Rectangle(pt.x - 10, pt.y - 10, pt.x + 10, pt.y + 10);
		gCsetion1.Lock();
		while (g_nSize < 100)
		{
			g_nSize += 5;
			dc.Ellipse(pt.x - g_nSize, pt.y - g_nSize, pt.x + g_nSize, pt.y + g_nSize);
			Sleep(100);
		}
		g_nSize = 5;
		gCsetion1.Unlock();
		Sleep(1000);
	}
	delete pData;
	return 0;
}

UINT TestCritical2(LPVOID IParam)
{
	DATA *pData = (DATA *)IParam;
	CClientDC dc(pData->hWnd);
	CPoint pt = pData->point;
	int size = 10;
	while (!g_bEnd)
	{
		dc.Rectangle(pt.x - 50, pt.y - 50, pt.x + 50, pt.y + 50);
		//gCsetion1.Lock();
		gCsetion2.Lock();
		while (size < 100)
		{
			size += 5;
			dc.Ellipse(pt.x - size, pt.y - size, pt.x + size, pt.y + size);
			Sleep(100);
		}
		dc.SelectObject(GetStockObject(WHITE_PEN));
		dc.Ellipse(pt.x - size, pt.y - size, pt.x + size, pt.y + size);
		dc.SelectObject(GetStockObject(BLACK_PEN));
		size = 5;
		//gCsetion1.Unlock();
		gCsetion2.Unlock();
		Sleep(1000);
	}
	delete pData;
	return 0;
}



void CSjThread4View::OnCriticalSection1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	DATA *pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 100;
	pData->point.y = 100;
	g_bEnd = FALSE;
	g_pThread1 = AfxBeginThread(TestCritical1, pData);
	pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 300;
	pData->point.y = 100;
	g_pThread2 = AfxBeginThread(TestCritical1, pData);
}


void CSjThread4View::OnCriticalSection2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	DATA *pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 100;
	pData->point.y = 300;
	g_bEnd = FALSE;
	g_pThread3 = AfxBeginThread(TestCritical2, pData);
	pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 300;
	pData->point.y = 300;
	g_pThread4 = AfxBeginThread(TestCritical2, pData);
}


void CSjThread4View::OnCriticalSection3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	g_bEnd = TRUE;
	/*if (g_pThread1 != NULL)
		TerminateThread(g_pThread1->m_hThread, NULL);
	if (g_pThread2 != NULL)
		TerminateThread(g_pThread2->m_hThread, NULL);*/
}

UINT TestEvent1(LPVOID IParam)
{
	DATA *pData = (DATA *)IParam;
	CClientDC dc(pData->hWnd);
	CPoint pt = pData->point;
	while (!g_bEnd)
	{
		dc.Rectangle(pt.x - 10, pt.y - 10, pt.x + 10, pt.y + 10);
		Sleep(1000);
		gEventF.Lock();
		while (g_nSize < 100)
		{
			g_nSize += 5;
			dc.Ellipse(pt.x - g_nSize, pt.y - g_nSize, pt.x + g_nSize, pt.y + g_nSize);
			Sleep(100);
		}
		g_nSize = 5;
		Sleep(1000);
	}
	delete pData;
	return 0;
}

UINT TestEvent2(LPVOID IParam)
{
	DATA *pData = (DATA *)IParam;
	CClientDC dc(pData->hWnd);
	CPoint pt = pData->point;
	while (!g_bEnd)
	{
		dc.Rectangle(pt.x - 10, pt.y - 10, pt.x + 10, pt.y + 10);
		Sleep(1000);
		gEventT.Lock();
		while (g_nSize < 100)
		{
			g_nSize += 5;
			dc.Ellipse(pt.x - g_nSize, pt.y - g_nSize, pt.x + g_nSize, pt.y + g_nSize);
			Sleep(100);
		}
		g_nSize = 5;
		Sleep(1000);
	}
	delete pData;
	return 0;
}

void CSjThread4View::OnEvent1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	g_bEnd = FALSE;
	DATA *pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 100;
	pData->point.y = 100;
	g_pThread1 = AfxBeginThread(TestEvent1, pData);

	pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 300;
	pData->point.y = 100;
	g_pThread2 = AfxBeginThread(TestEvent1, pData);

	pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 100;
	pData->point.y = 300;
	g_pThread3 = AfxBeginThread(TestEvent2, pData);

	pData = new DATA;
	pData->hWnd = this;
	pData->point.x = 300;
	pData->point.y = 300;
	g_pThread4 = AfxBeginThread(TestEvent2, pData);
}


void CSjThread4View::OnEvent2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	g_bEnd = TRUE;
}


void CSjThread4View::OnPulseEvent()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	gEventF.PulseEvent();
	gEventT.PulseEvent();
}


void CSjThread4View::OnSetEvent()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	gEventF.SetEvent();
	gEventT.SetEvent();
}


void CSjThread4View::OnResetevent()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	gEventF.ResetEvent();
	gEventT.ResetEvent();
}

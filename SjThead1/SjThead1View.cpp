
// SjThead1View.cpp : CSjThead1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSjThead1View ����/�Ҹ�

CSjThead1View::CSjThead1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSjThead1View::~CSjThead1View()
{
}

BOOL CSjThead1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjThead1View �׸���

void CSjThead1View::OnDraw(CDC* /*pDC*/)
{
	CSjThead1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjThead1View �μ�

BOOL CSjThead1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjThead1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjThead1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjThead1View ����

#ifdef _DEBUG
void CSjThead1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjThead1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjThead1Doc* CSjThead1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjThead1Doc)));
	return (CSjThead1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjThead1View �޽��� ó����


void CSjThead1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

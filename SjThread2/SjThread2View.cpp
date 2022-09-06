
// SjThread2View.cpp : CSjThread2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CSjThread2View ����/�Ҹ�

CSjThread2View::CSjThread2View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSjThread2View::~CSjThread2View()
{
}

BOOL CSjThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjThread2View �׸���

void CSjThread2View::OnDraw(CDC* /*pDC*/)
{
	CSjThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjThread2View �μ�

BOOL CSjThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjThread2View ����

#ifdef _DEBUG
void CSjThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CSjThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjThread2Doc* CSjThread2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjThread2Doc)));
	return (CSjThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjThread2View �޽��� ó����

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	DATA *pData = new DATA;
	//pData->hWnd = this->m_hWnd;
	pData->hWnd = this;
	pData->point = point;
	pData->nSize = rand() % 100 + 30;
	g_bEnd = FALSE;

	pThread = AfxBeginThread(TestThread5, pData);
	if (pThread == NULL)
	{
		MessageBox(_T("Thread ��������"));
	}
	CView::OnLButtonDown(nFlags, point);
}


void CSjThread2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

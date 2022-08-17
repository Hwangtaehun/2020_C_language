
// SjBitmap1View.cpp : CSjBitmap1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjBitmap1.h"
#endif

#include "SjBitmap1Doc.h"
#include "SjBitmap1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjBitmap1View

IMPLEMENT_DYNCREATE(CSjBitmap1View, CView)

BEGIN_MESSAGE_MAP(CSjBitmap1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CSjBitmap1View ����/�Ҹ�

CSjBitmap1View::CSjBitmap1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_nX = 100;
	m_nY = 100;
	m_xPos = 0;
	m_yPos = 0;
}

CSjBitmap1View::~CSjBitmap1View()
{
}

BOOL CSjBitmap1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjBitmap1View �׸���

void CSjBitmap1View::OnDraw(CDC* pDC)
{
	CSjBitmap1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/*CDC memDC;*/
	/*CBitmap bitMap, *pBitmap;*/
	CBitmap* pBitmap;
	/*memDC.CreateCompatibleDC(pDC);
	bitMap.LoadBitmap(IDB_BACKGROUND);*/
	pBitmap = (CBitmap *)m_memDC.SelectObject(&m_bitBack);
	pDC->BitBlt(0, 0, 1024, 680, &m_memDC, 0, 0, SRCCOPY);
	m_memDC.SelectObject(pBitmap);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjBitmap1View �μ�

BOOL CSjBitmap1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjBitmap1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjBitmap1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjBitmap1View ����

#ifdef _DEBUG
void CSjBitmap1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjBitmap1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjBitmap1Doc* CSjBitmap1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjBitmap1Doc)));
	return (CSjBitmap1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjBitmap1View �޽��� ó����


void CSjBitmap1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CDC memDC;
	CBitmap bitMap, *pBitmap;
	CClientDC dc(this);
	BITMAP bmInfo;

	memDC.CreateCompatibleDC(&dc);
	bitMap.LoadBitmap(IDB_SJMARK);
	bitMap.GetBitmap(&bmInfo);

	pBitmap = (CBitmap *)memDC.SelectObject(&bitMap);

	//dc.BitBlt(0, 0, 211, 120, &memDC, 0, 0, SRCCOPY);
	//dc.BitBlt(100, 100, 211, 120, &memDC, 50, 30, SRCCOPY);
	//dc.BitBlt(point.x, point.y, 211, 120, &memDC, 0, 0, SRCCOPY);
	dc.BitBlt(point.x, point.y, bmInfo.bmWidth, bmInfo.bmHeight, &memDC, 0, 0, SRCCOPY);

	TRACE("bmWidth = %d. bmHeight = %d \n", bmInfo.bmWidth, bmInfo.bmHeight);
	memDC.SelectObject(pBitmap);
	CView::OnLButtonDown(nFlags, point);
}


void CSjBitmap1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CDC memDC;
	CBitmap bitMap, *pBitmap;
	CClientDC dc(this);
	memDC.CreateCompatibleDC(&dc);
	bitMap.LoadBitmap(IDB_SJMARK);
	pBitmap = (CBitmap *)memDC.SelectObject(&bitMap);
	
	dc.StretchBlt(0, 0, 211, 120, &memDC, 0, 0, 211, 120, SRCCOPY);
	dc.StretchBlt(0, 150, 211 / 2, 120 / 2, &memDC, 0, 0, 211, 120, SRCCOPY);
	dc.StretchBlt(0, 250, 211, 120, &memDC, 210, 119, -211, -120, SRCCOPY);
	dc.StretchBlt(250, 250, 211, 120, &memDC, 210, 119, -211, -120, SRCCOPY);

	memDC.SelectObject(pBitmap);
	CView::OnRButtonDown(nFlags, point);
}


void CSjBitmap1View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(0, 300, NULL);
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


void CSjBitmap1View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(0);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CSjBitmap1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	/*CDC memDC;*/
	CBitmap *pBitmap;
	static int preX = 100, preY = 100;
	CClientDC dc(this);
	/*memDC.CreateCompatibleDC(&dc);
	static int xPos = 0;
	bitMap.LoadBitmap(IDB_WALK); 
	bitMask.LoadBitmap(IDB_SHADOW);
	bitBack.LoadBitmap(IDB_BACKGROUND);*/
	pBitmap = (CBitmap *)m_memDC.SelectObject(&m_bitBack);
	dc.BitBlt(preX, preY, 72, 72, &m_memDC, preX, preY, SRCCOPY);
	preX = m_nX;
	preY = m_nY;
	m_memDC.SelectObject(&m_bitMask);
	dc.BitBlt(m_nX, m_nY, 72, 72, &m_memDC, 72 * m_xPos, 72 * m_yPos, SRCAND);
	m_memDC.SelectObject(&m_bitMap);
	dc.BitBlt(m_nX, m_nY, 72, 72, &m_memDC, 72 * m_xPos, 72 * m_yPos, SRCPAINT);
	if (++m_xPos > 3)
		m_xPos = 0;
	m_memDC.SelectObject(pBitmap);
	CView::OnTimer(nIDEvent);
}


int CSjBitmap1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	CClientDC dc(this);
	m_memDC.CreateCompatibleDC(&dc);
	m_bitMap.LoadBitmap(IDB_WALK);
	m_bitMask.LoadBitmap(IDB_SHADOW);
	m_bitBack.LoadBitmap(IDB_BACKGROUND);
	return 0;
}


void CSjBitmap1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar)
	{
	case VK_LEFT:
		m_nX -= 10;
		if (++m_yPos > 2)
			m_yPos = 2;
		break;
	case VK_RIGHT:
		m_nX += 10;
		if (--m_yPos < 0)
			m_yPos = 0;
		break;
	case VK_UP:
		m_nY -= 10;
		break;
	case VK_DOWN:
		m_nY += 10;
		break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

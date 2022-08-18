
// SjBitmapShowView.cpp : CSjBitmapShowView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjBitmapShow.h"
#endif

#include "SjBitmapShowDoc.h"
#include "SjBitmapShowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjBitmapShowView

IMPLEMENT_DYNCREATE(CSjBitmapShowView, CView)

BEGIN_MESSAGE_MAP(CSjBitmapShowView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CSjBitmapShowView ����/�Ҹ�

CSjBitmapShowView::CSjBitmapShowView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	srand((unsigned int)time(NULL));
	m_nBitmap = IDB_BITMAP1 + rand() % BMP_COUNT;
}

CSjBitmapShowView::~CSjBitmapShowView()
{
}

BOOL CSjBitmapShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjBitmapShowView �׸���

void CSjBitmapShowView::OnDraw(CDC* /*pDC*/)
{
	CSjBitmapShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjBitmapShowView �μ�

BOOL CSjBitmapShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjBitmapShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjBitmapShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjBitmapShowView ����

#ifdef _DEBUG
void CSjBitmapShowView::AssertValid() const
{
	CView::AssertValid();
}

void CSjBitmapShowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjBitmapShowDoc* CSjBitmapShowView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjBitmapShowDoc)));
	return (CSjBitmapShowDoc*)m_pDocument;
}
#endif //_DEBUG


// CSjBitmapShowView �޽��� ó����


int CSjBitmapShowView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	CClientDC dc(this);
	m_memDC.CreateCompatibleDC(&dc);
	return 0;
}


void CSjBitmapShowView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(0);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CSjBitmapShowView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(0, 1000, NULL);
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


void CSjBitmapShowView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nBitmap;
	int m_nViewType;
	CBitmap *pOldBItmap;

	CClientDC dc(this);
	KillTimer(0);
	do
	{
		nBitmap = IDB_BITMAP1 + rand() % BMP_COUNT;
	} while (nBitmap == m_nBitmap);

	m_nBitmap = nBitmap;
	m_Bitmap.DeleteObject();
	m_Bitmap.LoadBitmap(m_nBitmap);
	pOldBItmap = (CBitmap *)m_memDC.SelectObject(&m_Bitmap);

	m_nViewType = rand() % 10;
	switch (m_nViewType)
	{
	case 0:
		Random(&dc);
		break;
	case 1:
		Vertical1(&dc);
		break;
	case 2:
		Vertical2(&dc);
		break;
	case 3:
		Vertical3(&dc);
		break;
	case 4:
		Horizontal1(&dc);
		break;
	case 5:
		Horizontal2(&dc);
		break;
	case 6:
		Horizontal3(&dc);
		break;
	case 7:
		In(&dc);
	case 8:
		Out(&dc);
	case 9:
		Snail(&dc);
	}
	SetTimer(0, 1000, NULL);
	m_memDC.SelectObject(pOldBItmap);

	CView::OnTimer(nIDEvent);
}


void CSjBitmapShowView::Vertical1(CDC * pDC)
{
	for (int y = 0; y < 20; y++)
	{
		pDC->BitBlt(0, y * 34, BMP_WIDTH, 34, &m_memDC, 0, y * 34, SRCCOPY);
		Sleep(50);
	}
}


void CSjBitmapShowView::Vertical2(CDC * pDC)
{
	for (int y = 20; y >= 0; y--)
	{
		pDC->BitBlt(0, y * 34, BMP_WIDTH, 34, &m_memDC, 0, y * 34, SRCCOPY);
		Sleep(20);
	}
}


void CSjBitmapShowView::Vertical3(CDC * pDC)
{
	int y, i;
	for (i = 0; i < 17; i++)
	{
		for (y = 0; y < 8; y++)
		{
			pDC->BitBlt(0, (y * 85 + i * 5), BMP_WIDTH, 5, &m_memDC, 0, y * 85 + i * 5, SRCCOPY);
			Sleep(20);
		}
	}
}


void CSjBitmapShowView::Horizontal1(CDC * pDC)
{
	for (int x = 0; x < 32; x++)
	{
		pDC->BitBlt(x * 32, 0, 32, BMP_HEIGHT, &m_memDC, x * 32, 0, SRCCOPY);
		Sleep(50);
	}
}


void CSjBitmapShowView::Horizontal2(CDC * pDC)
{
	for (int x = 31; x >= 0; x--)
	{
		pDC->BitBlt(x * 32, 0, 32, BMP_HEIGHT, &m_memDC, x * 32, 0, SRCCOPY);
		Sleep(50);
	}
}


void CSjBitmapShowView::Horizontal3(CDC * pDC)
{
	int x, i;
	for (i = 0; i < 13; i++)
	{
		for (x = 0; x < 16; x++)
		{
			pDC->BitBlt((x * 64 + i * 5), 0, 5, BMP_HEIGHT, &m_memDC, x * 64 + i * 5, 0, SRCCOPY);
			Sleep(20);
		}
	}
}


void CSjBitmapShowView::In(CDC * pDC)
{
	int sx = 15, ex = 16, sy = 15, ey = 16;
	int nWidth = 32, nHeight = 22;
	while (sx >= 0)
	{
		pDC->BitBlt(sx * nWidth, sy * nHeight, (ex - sx + 1)*nWidth, nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		pDC->BitBlt(sx * nWidth, sy * nHeight, (ex - sx + 1)*nWidth, nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		pDC->BitBlt(sx * nWidth, sy * nHeight, nWidth, (ey - sy + 1)*nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		pDC->BitBlt(sx * nWidth, sy * nHeight, nWidth, (ey - sy + 1)*nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		sx--;
		ex++;
		sy--;
		ey++;
		Sleep(20);
	}
}


void CSjBitmapShowView::Out(CDC * pDC)
{
	int nWidth = 32, nHeight = 22;
	int sx = 0, ex = 32, sy = 0, ey = 32;
	while (ex >= sx && ey >= sy)
	{
		pDC->BitBlt(sx * nWidth, sy * nHeight, (ex - sx + 1)*nWidth, nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		pDC->BitBlt(sx * nWidth, sy * nHeight, (ex - sx + 1)*nWidth, nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		pDC->BitBlt(sx * nWidth, sy * nHeight, nWidth, (ey - sy + 1)*nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		pDC->BitBlt(sx * nWidth, sy * nHeight, nWidth, (ey - sy + 1)*nHeight, &m_memDC, sx * nWidth, sy *nHeight, SRCCOPY);
		sx++;
		ex--;
		sy++;
		ey--;
		Sleep(20);
	}
}


void CSjBitmapShowView::Snail(CDC * pDC)
{
	int i, num = 0, cnt = 16, x = -1, y = 0, s = 1;
	int nWidth = 64, nHeight = 44;
	
	while (1)
	{
		for (i = 0; i < cnt; i++)
		{
			x += s;
			num++;
			pDC->BitBlt(x*nWidth, y*nHeight, nWidth, nHeight, &m_memDC, x*nWidth, y*nHeight, SRCCOPY);
			Sleep(5);
		}
		cnt--;
		if (cnt == 0)
			break;
		for (i = 0; i < cnt; i++)
		{
			y += s;
			num++;
			pDC->BitBlt(x*nWidth, y*nHeight, nWidth, nHeight, &m_memDC, x*nWidth, y*nHeight, SRCCOPY);
			Sleep(5);
		}
		s = -s;
	}
}


void CSjBitmapShowView::Random(CDC * pDC)
{
	BOOL bState[32][20] = { FALSE }; 
	int x, y, cnt = 0;

	while (1)
	{
		do
		{
			x = rand() % 32;
			y = rand() % 20;
		} while (bState[x][y]);
		bState[x][y] = TRUE;

		pDC->BitBlt(x * 32, y * 34, 32, 34, &m_memDC, x * 32, y * 34, SRCCOPY);
		Sleep(2);
		if (++cnt >= 32 * 20)
			break;
	}
}




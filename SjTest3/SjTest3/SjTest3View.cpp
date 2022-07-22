
// SjTest3View.cpp: CSjTest3View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjTest3.h"
#endif

#include "SjTest3Doc.h"
#include "SjTest3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ARRAY_SIZE 5

// CSjTest3View

IMPLEMENT_DYNCREATE(CSjTest3View, CView)

BEGIN_MESSAGE_MAP(CSjTest3View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_SNAILSEQUENCE, &CSjTest3View::OnSnailsequence)
	ON_COMMAND(IDM_MAGICSQUARE, &CSjTest3View::OnMagicsquare)
END_MESSAGE_MAP()

// CSjTest3View 생성/소멸

CSjTest3View::CSjTest3View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjTest3View::~CSjTest3View()
{
}

BOOL CSjTest3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjTest3View 그리기

void CSjTest3View::OnDraw(CDC* /*pDC*/)
{
	CSjTest3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjTest3View 인쇄

BOOL CSjTest3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjTest3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjTest3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjTest3View 진단

#ifdef _DEBUG
void CSjTest3View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest3Doc* CSjTest3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest3Doc)));
	return (CSjTest3Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest3View 메시지 처리기


void CSjTest3View::PrintNumber(CDC& dc, int px, int py, int num)
{
	// TODO: 여기에 구현 코드 추가.
	int startX = 50, startY = 50, nSpace = 50;
	CString buf;
	if (num == 0)
	{
		buf = "     ";
	}
	else
	{
		buf.Format(_T(" %2d "), num);
		Sleep(200);
	}
	dc.TextOut(px * nSpace + startX, py * nSpace + startY, buf);
}


void CSjTest3View::ClearNumber(CDC& dc)
{
	// TODO: 여기에 구현 코드 추가.
	int x, y;
	for ( x = 0; x < ARRAY_SIZE; x++)
	{
		for ( y = 0; y < ARRAY_SIZE; y++)
		{
			PrintNumber(dc, x, y, 0);
		}
	}
}


void CSjTest3View::OnSnailsequence()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CClientDC dc(this);
	int i, num = 0, cnt = ARRAY_SIZE, x = -1, y = 0, s = 1;
	ClearNumber(dc);
	while (1)
	{
		for ( i = 0; i < cnt; i++)
		{
			x += s;
			num++;
			PrintNumber(dc, x, y, num);
		}
		cnt--;
		if (cnt == 0)
			break;
		for ( i = 0; i < cnt; i++)
		{
			y += s;
			num++;
			PrintNumber(dc, x, y, num);
		}
		s = -s;
	}
}


void CSjTest3View::OnMagicsquare()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CClientDC dc(this);
	int num = 0, x = ARRAY_SIZE / 2, y = 0;
	ClearNumber(dc);
	while (1)
	{
		num++;
		PrintNumber(dc, x, y, num);
		dc.SetTextColor(RGB(0, 0, 0));

		if (num >= ARRAY_SIZE * ARRAY_SIZE)
			break;
		if (num % ARRAY_SIZE == 0)
		{
			y = y + 1;
			dc.SetTextColor(RGB(255, 0, 0));
			continue;
		}
		if (y > 0)
			y--;
		else
			y = ARRAY_SIZE - 1;

		if (x < ARRAY_SIZE - 1)
			x++;
		else
			x = 0;
	}
}

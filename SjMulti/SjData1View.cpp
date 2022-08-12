
// SjData1View.cpp : CSjData1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjMulti.h"
#endif

#include "SjData1Doc.h"
#include "SjData1View.h"
#include "sizeinputdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjData1View

IMPLEMENT_DYNCREATE(CSjData1View, CView)

BEGIN_MESSAGE_MAP(CSjData1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_PEN_WIDTH1, &CSjData1View::OnPenWidth1)
	ON_COMMAND(IDM_PEN_WIDTH2, &CSjData1View::OnPenWidth2)
	ON_COMMAND(IDM_PEN_WIDTH3, &CSjData1View::OnPenWidth3)
	ON_COMMAND(IDM_PEN_RED, &CSjData1View::OnPenRed)
	ON_COMMAND(IDM_PEN_GREEN, &CSjData1View::OnPenGreen)
	ON_COMMAND(IDM_PEN_BLUE, &CSjData1View::OnPenBlue)
	ON_COMMAND(IDM_BRUSH_RED, &CSjData1View::OnBrushRed)
	ON_COMMAND(IDM_BRUSH_GREEN, &CSjData1View::OnBrushGreen)
	ON_COMMAND(IDM_BRUSH_BLUE, &CSjData1View::OnBrushBlue)
	ON_COMMAND(IDM_PEN_CUSTOM, &CSjData1View::OnPenCustom)
	ON_COMMAND(IDM_BRUSH_CUSTOM, &CSjData1View::OnBrushCustom)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_ONE, &CSjData1View::OnOne)
	ON_COMMAND(IDM_TWO, &CSjData1View::OnTwo)
	ON_COMMAND(IDM_THREE, &CSjData1View::OnThree)
	ON_COMMAND(IDM_SIZE_CUSTOM, &CSjData1View::OnSizeCustom)
	ON_COMMAND(IDM_PEN_WIDTH_CUSTOM, &CSjData1View::OnPenWidthCustom)
END_MESSAGE_MAP()

// CSjData1View 생성/소멸

CSjData1View::CSjData1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nSize = 10;
	m_nWidth = 3;
	m_penColor = RGB(0, 0, 0);
	m_brushColor = RGB(255, 255, 255);
}

CSjData1View::~CSjData1View()
{
}

BOOL CSjData1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjData1View 그리기

void CSjData1View::OnDraw(CDC* pDC)
{
	CSjData1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//for (int i = 0; i < pDoc->m_nCnt; i++)
	//{
	//	//DrawRect(pDC, pDoc->m_aPoint[i], pDoc->m_aSize[i], pDoc->m_aWidth[i], pDoc->m_aPenColor[i], pDoc->m_aBurshColor[i]);
	//	DrawRect(pDC, &pDoc->m_bData[i]);
	//}

	//CData* pNode;
	CData data;
	for (POSITION pos = pDoc->m_List.GetHeadPosition(); pos != NULL; )
	{
		/*pNode = (CData*)pDoc->m_List.GetNext(pos);*/
		data = pDoc->m_List.GetNext(pos);
		//DrawRect(pDC, pNode);
		DrawRect(pDC, &data);
	}

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjData1View 인쇄

BOOL CSjData1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjData1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjData1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjData1View 진단

#ifdef _DEBUG
void CSjData1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjData1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjData1Doc* CSjData1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjData1Doc)));
	return (CSjData1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjData1View 메시지 처리기


void CSjData1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CSjData1Doc* pDoc = GetDocument();
	CData *pNode;
	pNode = new CData;
	pNode->SetData(point, m_nSize, m_nWidth, m_penColor, m_brushColor);
	
	
	//pDoc->m_List.AddTail(pNode);
	pDoc->m_List.AddTail(*pNode);
	DrawRect(&dc, pNode);
	//if (pDoc->m_nCnt < 30)
	//{
	//	/*pDoc->m_bData[pDoc->m_nCnt].m_Point = point;
	//	pDoc->m_bData[pDoc->m_nCnt].m_nSize = m_nSize;
	//	pDoc->m_bData[pDoc->m_nCnt].m_nWidth = m_nWidth;
	//	pDoc->m_bData[pDoc->m_nCnt].m_penColor = m_penColor;
	//	pDoc->m_bData[pDoc->m_nCnt].m_burshColor = m_brushColor;*/

	//	pDoc->m_bData[pDoc->m_nCnt].SetData(point, m_nSize, m_nWidth, m_penColor, m_brushColor);
	//	DrawRect(&dc, &pDoc->m_bData[pDoc->m_nCnt]);
	//	pDoc->m_nCnt++;
	//}
	pDoc->UpdateAllViews(NULL);
	delete pNode;
	CView::OnLButtonDown(nFlags, point);
}


void CSjData1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//m_nSize += 5;
	//TRACE(_T("%d, %d\n"), point.x, point.y);

	/*CString str;
	int n = 5;
	TRACE(_T("Trace n = %d \n"), n);
	str.Format(_T("Output n = %d\n"), n);
	OutputDebugString(str);

	TRACE0("인수없다\n");
	TRACE1("정수 = %d\n", n);
	TRACE2("문자열 = %s, %d\n", _T("Sejong세종"), n);

	ASSERT(n < 0);
	VERIFY(n < 0);*/

	//CUIntArray uArr;
	/*CArray <UINT, UINT> uArr;

	int i;
	uArr.SetSize(3);
	uArr[0] = 1;
	uArr[1] = 2;
	uArr.Add(11);
	uArr.Add(22);
	uArr.InsertAt(3, 111);
	uArr.SetAtGrow(4, 222);
	uArr.RemoveAt(1);

	for (i = 0; i < uArr.GetCount(); i++)
	{
		TRACE(_T("uArr[%d] = %d\n"), i, uArr[i]);
	}*/

	//CMapStringToString map;
	CMap <CString, LPCTSTR, CString, LPCTSTR> map;
	CString key, value;
	map.SetAt(_T("k1"), _T("세종"));
	map[_T("k2")] = _T("컴퓨터");
	map.SetAt(_T("k2"), _T("학원"));
	TRACE(_T("map[\"k1\"] = %s\n"), map[_T("k1")]);
	TRACE(_T("map[\"k2\"] = %s\n"), map[_T("k2")]);
	map.Lookup(_T("k1"), value);
	TRACE(_T("value = %s\n"), value);

	POSITION pos = map.GetStartPosition();
	while (pos != NULL)
	{
		map.GetNextAssoc(pos, key, value);
		TRACE(_T("key = %s, value = %s\n"), key, value);
	}
	TRACE(_T("map 요소 수 = %d\n"), map.GetCount());
	map.RemoveKey(_T("k1"));
	TRACE(_T("map 요소 수 = %d\n"), map.GetCount());
	CView::OnRButtonDown(nFlags, point);
}



void CSjData1View::DrawRect(CDC * pDC, CPoint point)
{
	pDC->Rectangle(point.x - m_nSize, point.y - m_nSize, point.x + m_nSize, point.y + m_nSize);
}


void CSjData1View::DrawRect(CDC * pDC, CPoint point, int nSize)
{
	pDC->Rectangle(point.x - nSize, point.y - nSize, point.x + nSize, point.y + nSize);
}


void CSjData1View::DrawRect(CDC* pDC, CPoint point, int nSize, int nWidth, COLORREF penColor, COLORREF brushColor)
{
	// TODO: 여기에 구현 코드 추가.
	CPen pen, * pPen;
	pen.CreatePen(PS_SOLID, nWidth, penColor);
	pPen = (CPen*)pDC->SelectObject(&pen);

	CBrush brush, * pBrush;
	brush.CreateSolidBrush(brushColor);
	pBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(point.x - nSize, point.y - nSize, point.x + nSize, point.y + nSize);
	pDC->SelectObject(pPen);
	pDC->SelectObject(pBrush);
}


void CSjData1View::DrawRect(CDC * pDC, /*DATA*/CData * pData)
{
	CPen pen, *pPen;
	//pen.CreatePen(PS_SOLID, pData->m_nWidth, pData->m_penColor);
	pen.CreatePen(PS_SOLID, pData->GetWidth(), pData->GetPenColor());
	pPen = (CPen*)pDC->SelectObject(&pen);

	CBrush brush, *pBrush;
	//brush.CreateSolidBrush(pData->m_burshColor);
	brush.CreateSolidBrush(pData->GetBurshColor());
	pBrush = (CBrush*)pDC->SelectObject(&brush);

	/*CPoint point = pData->m_Point;
	int nSize = pData->m_nSize;*/
	CPoint point = pData->GetPoint();
	int nSize = pData->GetSize();
	pDC->Rectangle(point.x - nSize, point.y - nSize, point.x + nSize, point.y + nSize);
	pDC->SelectObject(pPen);
	pDC->SelectObject(pBrush);
}


void CSjData1View::OnPenWidth1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nWidth = 1;
}


void CSjData1View::OnPenWidth2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nWidth = 2;
}


void CSjData1View::OnPenWidth3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nWidth = 3;
}


void CSjData1View::OnPenRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_penColor = RGB(255, 0, 0);
}


void CSjData1View::OnPenGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_penColor = RGB(0, 255, 0);
}


void CSjData1View::OnPenBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_penColor = RGB(0, 0, 255);
}


void CSjData1View::OnBrushRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_brushColor = RGB(255, 0, 0);
}


void CSjData1View::OnBrushGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_brushColor = RGB(0, 255, 0);
}


void CSjData1View::OnBrushBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_brushColor = RGB(0, 0, 255);
}


void CSjData1View::OnPenCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg(m_penColor);

	if (dlg.DoModal() == IDOK)
	{
		m_penColor = dlg.GetColor();
	}
}


void CSjData1View::OnBrushCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg(m_brushColor);

	if (dlg.DoModal() == IDOK)
	{
		m_brushColor = dlg.GetColor();
	}
}


void CSjData1View::OnOne()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 10;
}


void CSjData1View::OnTwo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 20;
}


void CSjData1View::OnThree()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSize = 30;
}


void CSjData1View::OnSizeCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSizeInPutDlg dlg(this, 10, 50);
	dlg.m_strTitle = "사각형 크기입력";
	if (dlg.DoModal() == IDOK)
	{
		m_nSize = dlg.m_nEdit;
	}
}


void CSjData1View::OnPenWidthCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSizeInPutDlg dlg(this, 1, 10);
	dlg.m_strTitle = "선의 굵기 입력";
	if (dlg.DoModal() == IDOK)
	{
		m_nWidth = dlg.m_nEdit;
	}
}

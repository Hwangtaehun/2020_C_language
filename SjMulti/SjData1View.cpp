
// SjData1View.cpp : CSjData1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CSjData1View ����/�Ҹ�

CSjData1View::CSjData1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjData1View �׸���

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

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjData1View �μ�

BOOL CSjData1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjData1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjData1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjData1View ����

#ifdef _DEBUG
void CSjData1View::AssertValid() const
{
	CView::AssertValid();
}

void CSjData1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjData1Doc* CSjData1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjData1Doc)));
	return (CSjData1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjData1View �޽��� ó����


void CSjData1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//m_nSize += 5;
	//TRACE(_T("%d, %d\n"), point.x, point.y);

	/*CString str;
	int n = 5;
	TRACE(_T("Trace n = %d \n"), n);
	str.Format(_T("Output n = %d\n"), n);
	OutputDebugString(str);

	TRACE0("�μ�����\n");
	TRACE1("���� = %d\n", n);
	TRACE2("���ڿ� = %s, %d\n", _T("Sejong����"), n);

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
	map.SetAt(_T("k1"), _T("����"));
	map[_T("k2")] = _T("��ǻ��");
	map.SetAt(_T("k2"), _T("�п�"));
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
	TRACE(_T("map ��� �� = %d\n"), map.GetCount());
	map.RemoveKey(_T("k1"));
	TRACE(_T("map ��� �� = %d\n"), map.GetCount());
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
	// TODO: ���⿡ ���� �ڵ� �߰�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nWidth = 1;
}


void CSjData1View::OnPenWidth2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nWidth = 2;
}


void CSjData1View::OnPenWidth3()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nWidth = 3;
}


void CSjData1View::OnPenRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(255, 0, 0);
}


void CSjData1View::OnPenGreen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(0, 255, 0);
}


void CSjData1View::OnPenBlue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_penColor = RGB(0, 0, 255);
}


void CSjData1View::OnBrushRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_brushColor = RGB(255, 0, 0);
}


void CSjData1View::OnBrushGreen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_brushColor = RGB(0, 255, 0);
}


void CSjData1View::OnBrushBlue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_brushColor = RGB(0, 0, 255);
}


void CSjData1View::OnPenCustom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog dlg(m_penColor);

	if (dlg.DoModal() == IDOK)
	{
		m_penColor = dlg.GetColor();
	}
}


void CSjData1View::OnBrushCustom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog dlg(m_brushColor);

	if (dlg.DoModal() == IDOK)
	{
		m_brushColor = dlg.GetColor();
	}
}


void CSjData1View::OnOne()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 10;
}


void CSjData1View::OnTwo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 20;
}


void CSjData1View::OnThree()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSize = 30;
}


void CSjData1View::OnSizeCustom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CSizeInPutDlg dlg(this, 10, 50);
	dlg.m_strTitle = "�簢�� ũ���Է�";
	if (dlg.DoModal() == IDOK)
	{
		m_nSize = dlg.m_nEdit;
	}
}


void CSjData1View::OnPenWidthCustom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CSizeInPutDlg dlg(this, 1, 10);
	dlg.m_strTitle = "���� ���� �Է�";
	if (dlg.DoModal() == IDOK)
	{
		m_nWidth = dlg.m_nEdit;
	}
}

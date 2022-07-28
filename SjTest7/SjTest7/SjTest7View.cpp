
// SjTest7View.cpp : CSjTest7View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjTest7.h"
#endif

#include "SjTest7Doc.h"
#include "SjTest7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "testDig1.h"
#include "testDlg2.h"
#include "testDlg3.h"
#include "testDlg4.h"
#include "calculator1dlg.h"
#include "calculator2dlg.h"
#include "converdlg.h"
#include "inputdlg.h"
// CSjTest7View

IMPLEMENT_DYNCREATE(CSjTest7View, CView)

BEGIN_MESSAGE_MAP(CSjTest7View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_DLG1, &CSjTest7View::OnDlg1)
	ON_COMMAND(IDM_DLG2, &CSjTest7View::OnDlg2)
	ON_COMMAND(IDM_CONTROL, &CSjTest7View::OnControl)
	ON_COMMAND(IDM_LIST, &CSjTest7View::OnList)
	ON_COMMAND(IDM_CALCULATOR1, &CSjTest7View::OnCalculator1)
	ON_COMMAND(IDM_CALCULATOR2, &CSjTest7View::OnCalculator2)
	ON_COMMAND(IDM_CONVERT, &CSjTest7View::OnConvert)
	ON_COMMAND(IDM_INPUT, &CSjTest7View::OnInput)
END_MESSAGE_MAP()

// CSjTest7View ����/�Ҹ�

CSjTest7View::CSjTest7View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSjTest7View::~CSjTest7View()
{
}

BOOL CSjTest7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSjTest7View �׸���

void CSjTest7View::OnDraw(CDC* /*pDC*/)
{
	CSjTest7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSjTest7View �μ�

BOOL CSjTest7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjTest7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjTest7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjTest7View ����

#ifdef _DEBUG
void CSjTest7View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest7Doc* CSjTest7View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest7Doc)));
	return (CSjTest7Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest7View �޽��� ó����


void CSjTest7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	/*testDig1 dlg;
	dlg.DoModal();*/

	CView::OnLButtonDown(nFlags, point);
}


void CSjTest7View::OnDlg1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	testDig1 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnDlg2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	testDlg2 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnControl()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	testDlg3 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnList()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	testDlg4 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnCalculator1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	calculator1dlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnCalculator2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	calculator2dlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnConvert()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	converdlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnInput()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	inputdlg dlg;
	dlg.DoModal();
}


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
#include "testDlg1.h"
#include "testDlg2.h"
#include "testDlg3.h"
#include "testDlg4.h"
#include "calculator1dlg.h"
#include "calculator2dlg.h"
#include "covertdlg.h"
#include "inputdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjTest7View

IMPLEMENT_DYNCREATE(CSjTest7View, CView)

BEGIN_MESSAGE_MAP(CSjTest7View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
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


void CSjTest7View::OnDlg1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTestDlg1 dlg;
	dlg.DoModal();

	CClientDC dc(this);
	CString Buf;
	Buf.Format(_T("�̸� = %s. ���� = %d, ���� = %d"), dlg.m_strName, dlg.m_nAge, dlg.m_nScore);
	dc.TextOut(10, 10, Buf);
}


void CSjTest7View::OnDlg2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTestDlg2 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnControl()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTestDlg3 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnList()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTestDlg4 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnCalculator1()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CCalculator1Dlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnCalculator2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CCalculator2Dlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnConvert()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CCovertDlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnInput()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CInputDlg dlg;
	dlg.DoModal();
}

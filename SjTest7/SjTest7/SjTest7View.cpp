
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


// CSjTest7View

IMPLEMENT_DYNCREATE(CSjTest7View, CView)

BEGIN_MESSAGE_MAP(CSjTest7View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
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


// SjOdbc1View.cpp : CSjOdbc1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjOdbc1.h"
#endif

#include "SjOdbc1Set.h"
#include "SjOdbc1Doc.h"
#include "SjOdbc1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjOdbc1View

IMPLEMENT_DYNCREATE(CSjOdbc1View, CRecordView)

BEGIN_MESSAGE_MAP(CSjOdbc1View, CRecordView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSjOdbc1View ����/�Ҹ�

CSjOdbc1View::CSjOdbc1View()
	: CRecordView(CSjOdbc1View::IDD)
{
	m_pSet = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSjOdbc1View::~CSjOdbc1View()
{
}

void CSjOdbc1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_strCode, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_strName, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_nKor, m_pSet);
	// ��Ʈ���� �����ͺ��̽� �ʵ忡 '����'�ϱ� ���� ���⿡ DDX_Field* �Լ��� ������ �� �ֽ��ϴ�. ��:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �ڼ��� ������ MSDN �� ODBC ������ �����Ͻʽÿ�.
}

BOOL CSjOdbc1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CRecordView::PreCreateWindow(cs);
}

void CSjOdbc1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_SjOdbc1Set;
	CRecordView::OnInitialUpdate();

}


// CSjOdbc1View �μ�

BOOL CSjOdbc1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSjOdbc1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSjOdbc1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSjOdbc1View ����

#ifdef _DEBUG
void CSjOdbc1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CSjOdbc1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CSjOdbc1Doc* CSjOdbc1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjOdbc1Doc)));
	return (CSjOdbc1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjOdbc1View �����ͺ��̽� ����
CRecordset* CSjOdbc1View::OnGetRecordset()
{
	return m_pSet;
}



// CSjOdbc1View �޽��� ó����

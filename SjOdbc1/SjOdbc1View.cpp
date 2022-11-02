
// SjOdbc1View.cpp : CSjOdbc1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSjOdbc1View 생성/소멸

CSjOdbc1View::CSjOdbc1View()
	: CRecordView(CSjOdbc1View::IDD)
{
	m_pSet = NULL;
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// 컨트롤을 데이터베이스 필드에 '연결'하기 위해 여기에 DDX_Field* 함수를 삽입할 수 있습니다. 예:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 자세한 내용은 MSDN 및 ODBC 샘플을 참조하십시오.
}

BOOL CSjOdbc1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CRecordView::PreCreateWindow(cs);
}

void CSjOdbc1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_SjOdbc1Set;
	CRecordView::OnInitialUpdate();

}


// CSjOdbc1View 인쇄

BOOL CSjOdbc1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjOdbc1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjOdbc1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjOdbc1View 진단

#ifdef _DEBUG
void CSjOdbc1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CSjOdbc1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CSjOdbc1Doc* CSjOdbc1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjOdbc1Doc)));
	return (CSjOdbc1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjOdbc1View 데이터베이스 지원
CRecordset* CSjOdbc1View::OnGetRecordset()
{
	return m_pSet;
}



// CSjOdbc1View 메시지 처리기

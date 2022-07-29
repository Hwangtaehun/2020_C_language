
// SjTest7View.cpp : CSjTest7View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CSjTest7View 생성/소멸

CSjTest7View::CSjTest7View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjTest7View::~CSjTest7View()
{
}

BOOL CSjTest7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSjTest7View 그리기

void CSjTest7View::OnDraw(CDC* /*pDC*/)
{
	CSjTest7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSjTest7View 인쇄

BOOL CSjTest7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSjTest7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSjTest7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSjTest7View 진단

#ifdef _DEBUG
void CSjTest7View::AssertValid() const
{
	CView::AssertValid();
}

void CSjTest7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSjTest7Doc* CSjTest7View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjTest7Doc)));
	return (CSjTest7Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjTest7View 메시지 처리기


void CSjTest7View::OnDlg1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTestDlg1 dlg;
	dlg.DoModal();

	CClientDC dc(this);
	CString Buf;
	Buf.Format(_T("이름 = %s. 나이 = %d, 점수 = %d"), dlg.m_strName, dlg.m_nAge, dlg.m_nScore);
	dc.TextOut(10, 10, Buf);
}


void CSjTest7View::OnDlg2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTestDlg2 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnControl()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTestDlg3 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnList()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTestDlg4 dlg;
	dlg.DoModal();
}


void CSjTest7View::OnCalculator1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CCalculator1Dlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnCalculator2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CCalculator2Dlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnConvert()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CCovertDlg dlg;
	dlg.DoModal();
}


void CSjTest7View::OnInput()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CInputDlg dlg;
	dlg.DoModal();
}

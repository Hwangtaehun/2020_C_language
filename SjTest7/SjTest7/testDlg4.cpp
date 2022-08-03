// testDlg4.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg4.h"
#include "afxdialogex.h"


// CTestDlg4 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTestDlg4, CDialogEx)

CTestDlg4::CTestDlg4(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg4::IDD, pParent)
	, m_strList(_T(""))
	, m_strSelected(_T(""))
{

}

CTestDlg4::~CTestDlg4()
{
}

void CTestDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_LBString(pDX, IDC_LIST1, m_strList);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlCombo);
	DDX_Text(pDX, IDC_SELECTED, m_strSelected);
}


BEGIN_MESSAGE_MAP(CTestDlg4, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CTestDlg4::OnSelchangeList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTestDlg4::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CTestDlg4 메시지 처리기입니다.


BOOL CTestDlg4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrlList.AddString(_T("현대자동차"));
	m_ctrlList.AddString(_T("대우자동차"));
	m_ctrlList.AddString(_T("쌍용자동차"));
	m_ctrlList.AddString(_T("삼성자동차"));
	m_ctrlList.AddString(_T("우리자동차"));
	m_ctrlList.AddString(_T("한성자동차"));
	m_ctrlList.AddString(_T("세종자동차"));

	m_ctrlCombo.AddString(_T("현대자동차"));
	m_ctrlCombo.AddString(_T("대우자동차"));
	m_ctrlCombo.AddString(_T("쌍용자동차"));
	m_ctrlCombo.AddString(_T("삼성자동차"));
	m_ctrlCombo.AddString(_T("우리자동차"));
	m_ctrlCombo.AddString(_T("한성자동차"));
	m_ctrlCombo.AddString(_T("세종자동차"));

	m_ctrlList.SetCurSel(0);
	m_ctrlCombo.SetCurSel(0);

	UpdateData(TRUE);
	m_strSelected = m_strList;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTestDlg4::OnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctrlCombo.SetCurSel(m_ctrlList.GetCurSel());
	UpdateData(TRUE);
	m_strSelected = m_strList;
	UpdateData(FALSE);
}


void CTestDlg4::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctrlList.SetCurSel(m_ctrlCombo.GetCurSel());
	UpdateData(TRUE);
	m_strSelected = m_strList;
	UpdateData(FALSE);
}

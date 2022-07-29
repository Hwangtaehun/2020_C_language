// testDlg1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg1.h"
#include "afxdialogex.h"


// CTestDlg1 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTestDlg1, CDialogEx)

CTestDlg1::CTestDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg1::IDD, pParent)
	, m_strName(_T(""))
	, m_nAge(0)
	, m_nScore(0)
{

}

CTestDlg1::~CTestDlg1()
{
}

void CTestDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	DDX_Text(pDX, IDC_SCORE, m_nScore);
}


BEGIN_MESSAGE_MAP(CTestDlg1, CDialogEx)
	ON_BN_CLICKED(IDC_CALC_BT, &CTestDlg1::OnClickedCalcBt)
END_MESSAGE_MAP()


// CTestDlg1 메시지 처리기입니다.


void CTestDlg1::OnClickedCalcBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nScore = m_nAge * 100;
	UpdateData(FALSE);
}

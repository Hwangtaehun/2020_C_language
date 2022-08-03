// testDlg1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg1.h"
#include "afxdialogex.h"


// CTestDlg1 ��ȭ �����Դϴ�.

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


// CTestDlg1 �޽��� ó�����Դϴ�.


void CTestDlg1::OnClickedCalcBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nScore = m_nAge * 100;
	UpdateData(FALSE);
}

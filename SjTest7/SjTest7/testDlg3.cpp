// testDlg3.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg3.h"
#include "afxdialogex.h"


// CTestDlg3 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTestDlg3, CDialogEx)

CTestDlg3::CTestDlg3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg3::IDD, pParent)
	, m_bShow(TRUE)
	, m_bEnable(TRUE)
{

}

CTestDlg3::~CTestDlg3()
{
}

void CTestDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit1);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlEdit2);
	DDX_Check(pDX, IDC_CHECK_SHOW, m_bShow);
	DDX_Check(pDX, IDC_CHECK_USE, m_bEnable);
}


BEGIN_MESSAGE_MAP(CTestDlg3, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_USE, &CTestDlg3::OnClickedCheckUse)
	ON_BN_CLICKED(IDC_CHECK_SHOW, &CTestDlg3::OnClickedCheckShow)
END_MESSAGE_MAP()


// CTestDlg3 메시지 처리기입니다.


void CTestDlg3::OnClickedCheckUse()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrlEdit1.EnableWindow(m_bEnable);
	m_ctrlEdit2.EnableWindow(m_bEnable);
}


void CTestDlg3::OnClickedCheckShow()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_bShow)
	{
		m_ctrlEdit2.ShowWindow(SW_SHOW);
		m_ctrlEdit1.ShowWindow(SW_SHOW);
	}	
	else
	{
		m_ctrlEdit2.ShowWindow(SW_HIDE);
		m_ctrlEdit1.ShowWindow(SW_HIDE);
	}
}

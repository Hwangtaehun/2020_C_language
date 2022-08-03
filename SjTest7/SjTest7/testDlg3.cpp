// testDlg3.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg3.h"
#include "afxdialogex.h"


// CTestDlg3 ��ȭ �����Դϴ�.

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


// CTestDlg3 �޽��� ó�����Դϴ�.


void CTestDlg3::OnClickedCheckUse()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_ctrlEdit1.EnableWindow(m_bEnable);
	m_ctrlEdit2.EnableWindow(m_bEnable);
}


void CTestDlg3::OnClickedCheckShow()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

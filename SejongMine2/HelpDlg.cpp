// HelpDlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SejongMine.h"
#include "HelpDlg.h"
#include "afxdialogex.h"


// CHelpDlg 대화 상자

IMPLEMENT_DYNAMIC(CHelpDlg, CDialogEx)

CHelpDlg::CHelpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HELPDIG, pParent)
	, m_strHelp(_T(""))
{

}

CHelpDlg::~CHelpDlg()
{
}

void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HELP, m_strHelp);
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialogEx)
END_MESSAGE_MAP()


// CHelpDlg 메시지 처리기

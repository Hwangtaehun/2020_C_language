// HelpDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LatinSquare.h"
#include "HelpDlg.h"
#include "afxdialogex.h"


// CHelpDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHelpDlg, CDialogEx)

CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHelpDlg::IDD, pParent)
	, m_strHelp(_T(""))
{

}

CHelpDlg::~CHelpDlg()
{
}

void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_HELP, m_strHelp);
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialogEx)
END_MESSAGE_MAP()


// CHelpDlg �޽��� ó�����Դϴ�.

// NameDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SejongMine.h"
#include "NameDlg.h"
#include "afxdialogex.h"


// CNameDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CNameDlg, CDialogEx)

CNameDlg::CNameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNameDlg::IDD, pParent)
	, m_strName(_T(""))
{

}

CNameDlg::~CNameDlg()
{
}

void CNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
}


BEGIN_MESSAGE_MAP(CNameDlg, CDialogEx)
END_MESSAGE_MAP()


// CNameDlg �޽��� ó�����Դϴ�.

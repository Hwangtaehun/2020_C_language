// inputdlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "inputdlg.h"
#include "afxdialogex.h"


// CInputDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputDlg::IDD, pParent)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
END_MESSAGE_MAP()


// CInputDlg 메시지 처리기입니다.

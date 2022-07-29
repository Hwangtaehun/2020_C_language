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
{

}

CTestDlg4::~CTestDlg4()
{
}

void CTestDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg4, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg4 메시지 처리기입니다.

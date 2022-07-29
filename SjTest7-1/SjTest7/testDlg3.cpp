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
{

}

CTestDlg3::~CTestDlg3()
{
}

void CTestDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg3, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg3 메시지 처리기입니다.

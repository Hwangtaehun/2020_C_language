// TestDlg0.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest6.h"
#include "TestDlg0.h"
#include "afxdialogex.h"


// CTestDlg0 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTestDlg0, CDialogEx)

CTestDlg0::CTestDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg0::IDD, pParent)
{

}

CTestDlg0::~CTestDlg0()
{
}

void CTestDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg0, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg0 메시지 처리기입니다.

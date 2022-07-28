// testDlg2.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SjTest7.h"
#include "testDlg2.h"
#include "afxdialogex.h"


// testDlg2 대화 상자

IMPLEMENT_DYNAMIC(testDlg2, CDialogEx)

testDlg2::testDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CTESTDLG2, pParent)
{

}

testDlg2::~testDlg2()
{
}

void testDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(testDlg2, CDialogEx)
END_MESSAGE_MAP()


// testDlg2 메시지 처리기

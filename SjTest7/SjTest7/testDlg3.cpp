// testDlg3.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SjTest7.h"
#include "testDlg3.h"
#include "afxdialogex.h"


// testDlg3 대화 상자

IMPLEMENT_DYNAMIC(testDlg3, CDialogEx)

testDlg3::testDlg3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CTESTDLG3, pParent)
{

}

testDlg3::~testDlg3()
{
}

void testDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(testDlg3, CDialogEx)
END_MESSAGE_MAP()


// testDlg3 메시지 처리기

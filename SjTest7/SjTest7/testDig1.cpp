// testDig1.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SjTest7.h"
#include "testDig1.h"
#include "afxdialogex.h"


// testDig1 대화 상자

IMPLEMENT_DYNAMIC(testDig1, CDialogEx)

testDig1::testDig1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CTESTDLG1, pParent)
{

}

testDig1::~testDig1()
{
}

void testDig1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(testDig1, CDialogEx)
END_MESSAGE_MAP()


// testDig1 메시지 처리기

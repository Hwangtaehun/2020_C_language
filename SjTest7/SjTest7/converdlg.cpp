// converdlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SjTest7.h"
#include "converdlg.h"
#include "afxdialogex.h"


// converdlg 대화 상자

IMPLEMENT_DYNAMIC(converdlg, CDialogEx)

converdlg::converdlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCONVERTDIG, pParent)
{

}

converdlg::~converdlg()
{
}

void converdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(converdlg, CDialogEx)
END_MESSAGE_MAP()


// converdlg 메시지 처리기

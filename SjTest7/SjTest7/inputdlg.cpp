// inputdlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SjTest7.h"
#include "inputdlg.h"
#include "afxdialogex.h"


// inputdlg 대화 상자

IMPLEMENT_DYNAMIC(inputdlg, CDialogEx)

inputdlg::inputdlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CINPUTDLG, pParent)
{

}

inputdlg::~inputdlg()
{
}

void inputdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(inputdlg, CDialogEx)
END_MESSAGE_MAP()


// inputdlg 메시지 처리기

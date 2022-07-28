// calculator2dlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SjTest7.h"
#include "calculator2dlg.h"
#include "afxdialogex.h"


// calculator2dlg 대화 상자

IMPLEMENT_DYNAMIC(calculator2dlg, CDialogEx)

calculator2dlg::calculator2dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCALCULATOR2DLG, pParent)
{

}

calculator2dlg::~calculator2dlg()
{
}

void calculator2dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(calculator2dlg, CDialogEx)
END_MESSAGE_MAP()


// calculator2dlg 메시지 처리기

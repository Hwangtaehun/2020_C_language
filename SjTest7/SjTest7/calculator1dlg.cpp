// calculator1dlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SjTest7.h"
#include "calculator1dlg.h"
#include "afxdialogex.h"


// calculator1dlg 대화 상자

IMPLEMENT_DYNAMIC(calculator1dlg, CDialogEx)

calculator1dlg::calculator1dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCALCULATOR1DLG, pParent)
{

}

calculator1dlg::~calculator1dlg()
{
}

void calculator1dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(calculator1dlg, CDialogEx)
END_MESSAGE_MAP()


// calculator1dlg 메시지 처리기

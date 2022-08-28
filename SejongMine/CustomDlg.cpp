// CustomDlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SejongMine.h"
#include "CustomDlg.h"
#include "afxdialogex.h"


// CustomDlg 대화 상자

IMPLEMENT_DYNAMIC(CustomDlg, CDialogEx)

CustomDlg::CustomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUSTOMDIG, pParent)
	, m_nHeight(0)
	, m_nWidth(0)
	, m_nMine(0)
{

}

CustomDlg::~CustomDlg()
{
}

void CustomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MINE, m_nMine);
	DDX_Text(pDX, IDC_HEIGHT, m_nHeight);
	DDV_MinMaxInt(pDX, m_nHeight, 1, 24);
	DDX_Text(pDX, IDC_WIDTH, m_nWidth);
	DDV_MinMaxInt(pDX, m_nWidth, 1, 30);
}


BEGIN_MESSAGE_MAP(CustomDlg, CDialogEx)
END_MESSAGE_MAP()


// CustomDlg 메시지 처리기

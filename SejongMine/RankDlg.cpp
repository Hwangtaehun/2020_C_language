// RankDlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SejongMine.h"
#include "RankDlg.h"
#include "afxdialogex.h"


// CRankDlg 대화 상자

IMPLEMENT_DYNAMIC(CRankDlg, CDialogEx)

CRankDlg::CRankDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANK, pParent)
{

	m_nld = 0;
}

CRankDlg::~CRankDlg()
{
}

void CRankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRankDlg, CDialogEx)
END_MESSAGE_MAP()


// CRankDlg 메시지 처리기

// modaldlg.cpp: 구현 파일
//

#include "pch.h"
#include "SjModeless.h"
#include "modaldlg.h"
#include "afxdialogex.h"


// CModalDlg 대화 상자

IMPLEMENT_DYNAMIC(CModalDlg, CDialogEx)

CModalDlg::CModalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MODALDLG, pParent)
{

}

CModalDlg::~CModalDlg()
{
}

void CModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModalDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BT_EXITDLG, &CModalDlg::OnBnClickedExitdlg)
END_MESSAGE_MAP()


// CModalDlg 메시지 처리기


void CModalDlg::OnBnClickedExitdlg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}

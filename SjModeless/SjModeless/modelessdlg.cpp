// modelessdlg.cpp: 구현 파일
//

#include "pch.h"
#include "SjModeless.h"
#include "modelessdlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"


// CModelessDlg 대화 상자

IMPLEMENT_DYNAMIC(CModelessDlg, CDialogEx)

CModelessDlg::CModelessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MODELESSDLG, pParent)
{

}

CModelessDlg::~CModelessDlg()
{
}

void CModelessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModelessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BT_EXITMODELESS, &CModelessDlg::OnBnClickedExitmodeless)
END_MESSAGE_MAP()


// CModelessDlg 메시지 처리기


void CModelessDlg::OnBnClickedExitmodeless()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DestroyWindow();
}


void CModelessDlg::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CMainFrame*)AfxGetMainWnd())->m_pDlg = NULL;
	delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CModelessDlg::Create(CWnd* pParentWnd)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::Create(IDD, pParentWnd);
}

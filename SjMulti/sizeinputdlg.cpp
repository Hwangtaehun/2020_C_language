// sizeinputdlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjMulti.h"
#include "sizeinputdlg.h"
#include "afxdialogex.h"


// CSizeInPutDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSizeInPutDlg, CDialogEx)

CSizeInPutDlg::CSizeInPutDlg(CWnd* pParent /*=NULL*/, int nStart, int nEnd)
	: CDialogEx(CSizeInPutDlg::IDD, pParent)
	, m_nEdit(nStart)
	, m_strTitle(_T(""))
{

	m_nStart = nStart;
	m_nEnd = nEnd;
}

CSizeInPutDlg::~CSizeInPutDlg()
{
}

void CSizeInPutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_SIZE, m_ctrlSpin);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_nEdit);
	DDX_Text(pDX, IDC_STATIC_TiTLE, m_strTitle);
}


BEGIN_MESSAGE_MAP(CSizeInPutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSizeInPutDlg 메시지 처리기입니다.


BOOL CSizeInPutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrlSpin.SetRange(m_nStart, m_nEnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

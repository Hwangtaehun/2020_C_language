// sizeinputdlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjMulti.h"
#include "sizeinputdlg.h"
#include "afxdialogex.h"


// CSizeInPutDlg ��ȭ �����Դϴ�.

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


// CSizeInPutDlg �޽��� ó�����Դϴ�.


BOOL CSizeInPutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrlSpin.SetRange(m_nStart, m_nEnd);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

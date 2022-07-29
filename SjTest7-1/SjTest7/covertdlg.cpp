// covertdlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "covertdlg.h"
#include "afxdialogex.h"


// CCovertDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCovertDlg, CDialogEx)

CCovertDlg::CCovertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCovertDlg::IDD, pParent)
	, m_nResult(_T(""))
{

}

CCovertDlg::~CCovertDlg()
{
}

void CCovertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nResult);
}


BEGIN_MESSAGE_MAP(CCovertDlg, CDialogEx)
	ON_COMMAND(IDC_HEX, &CCovertDlg::OnHex)
	ON_COMMAND(IDC_DEC, &CCovertDlg::OnDec)
	ON_COMMAND(IDC_OCT, &CCovertDlg::OnOct)
	ON_COMMAND(IDC_BIN, &CCovertDlg::OnBin)
END_MESSAGE_MAP()


// CCovertDlg �޽��� ó�����Դϴ�.


//void CCovertDlg::OnEnChangeEdit1()
//{
//	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
//	// CDialogEx::OnInitDialog() �Լ��� ������ 
//	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
//	// �� �˸� �޽����� ������ �ʽ��ϴ�.
//
//	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//}


void CCovertDlg::OnHex()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nResult = _T("16����");
	UpdateData(FALSE);
}


void CCovertDlg::OnDec()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nResult = _T("10����");
	UpdateData(FALSE);
}


void CCovertDlg::OnOct()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nResult = _T("8����");
	UpdateData(FALSE);
}


void CCovertDlg::OnBin()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nResult = _T("2����");
	UpdateData(FALSE);
}

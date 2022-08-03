// testDlg4.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg4.h"
#include "afxdialogex.h"


// CTestDlg4 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTestDlg4, CDialogEx)

CTestDlg4::CTestDlg4(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg4::IDD, pParent)
	, m_strList(_T(""))
	, m_strSelected(_T(""))
{

}

CTestDlg4::~CTestDlg4()
{
}

void CTestDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_LBString(pDX, IDC_LIST1, m_strList);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlCombo);
	DDX_Text(pDX, IDC_SELECTED, m_strSelected);
}


BEGIN_MESSAGE_MAP(CTestDlg4, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CTestDlg4::OnSelchangeList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTestDlg4::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CTestDlg4 �޽��� ó�����Դϴ�.


BOOL CTestDlg4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrlList.AddString(_T("�����ڵ���"));
	m_ctrlList.AddString(_T("����ڵ���"));
	m_ctrlList.AddString(_T("�ֿ��ڵ���"));
	m_ctrlList.AddString(_T("�Ｚ�ڵ���"));
	m_ctrlList.AddString(_T("�츮�ڵ���"));
	m_ctrlList.AddString(_T("�Ѽ��ڵ���"));
	m_ctrlList.AddString(_T("�����ڵ���"));

	m_ctrlCombo.AddString(_T("�����ڵ���"));
	m_ctrlCombo.AddString(_T("����ڵ���"));
	m_ctrlCombo.AddString(_T("�ֿ��ڵ���"));
	m_ctrlCombo.AddString(_T("�Ｚ�ڵ���"));
	m_ctrlCombo.AddString(_T("�츮�ڵ���"));
	m_ctrlCombo.AddString(_T("�Ѽ��ڵ���"));
	m_ctrlCombo.AddString(_T("�����ڵ���"));

	m_ctrlList.SetCurSel(0);
	m_ctrlCombo.SetCurSel(0);

	UpdateData(TRUE);
	m_strSelected = m_strList;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CTestDlg4::OnSelchangeList1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlCombo.SetCurSel(m_ctrlList.GetCurSel());
	UpdateData(TRUE);
	m_strSelected = m_strList;
	UpdateData(FALSE);
}


void CTestDlg4::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlList.SetCurSel(m_ctrlCombo.GetCurSel());
	UpdateData(TRUE);
	m_strSelected = m_strList;
	UpdateData(FALSE);
}

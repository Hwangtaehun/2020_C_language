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
	//, m_nResult(_T(""))
	, m_strDisplay(_T(""))
	, m_nRadix(0)
{

	m_nValue = 0;
	//  m_ctrlB6 = 0;
}

CCovertDlg::~CCovertDlg()
{
}

void CCovertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_nResult);
	DDX_Control(pDX, IDC_BT0, m_ctrlB0);
	DDX_Control(pDX, IDC_BT1, m_ctrlB1);
	DDX_Control(pDX, IDC_BT2, m_ctrlB2);
	DDX_Control(pDX, IDC_BT3, m_ctrlB3);
	DDX_Control(pDX, IDC_BT4, m_ctrlB4);
	DDX_Control(pDX, IDC_BT5, m_ctrlB5);
	DDX_Control(pDX, IDC_BT6, m_ctrlB6);
	DDX_Control(pDX, IDC_BT7, m_ctrlB7);
	DDX_Control(pDX, IDC_BT8, m_ctrlB8);
	DDX_Control(pDX, IDC_BT9, m_ctrlB9);
	DDX_Control(pDX, IDC_BTA, m_ctrlBa);
	DDX_Control(pDX, IDC_BTB, m_ctrlBb);
	DDX_Control(pDX, IDC_BTC, m_ctrlBc);
	DDX_Control(pDX, IDC_BTD, m_ctrlBd);
	DDX_Control(pDX, IDC_BTE, m_ctrlBe);
	DDX_Control(pDX, IDC_BTF, m_ctrlBf);
	DDX_Text(pDX, IDC_DISPLAY, m_strDisplay);
	DDX_Radio(pDX, IDC_HEX, m_nRadix);
}


BEGIN_MESSAGE_MAP(CCovertDlg, CDialogEx)
	ON_COMMAND(IDC_HEX, &CCovertDlg::OnHex)
	ON_COMMAND(IDC_DEC, &CCovertDlg::OnDec)
	ON_COMMAND(IDC_OCT, &CCovertDlg::OnOct)
	ON_COMMAND(IDC_BIN, &CCovertDlg::OnBin)
	ON_BN_CLICKED(IDC_BT_BACK, &CCovertDlg::OnClickedBtBack)
	ON_BN_CLICKED(IDC_BT_CLEAR, &CCovertDlg::OnClickedBtClear)
	ON_BN_CLICKED(IDC_BT0, &CCovertDlg::OnClickedBt0)
	ON_BN_CLICKED(IDC_BT1, &CCovertDlg::OnClickedBt1)
	ON_BN_CLICKED(IDC_BT2, &CCovertDlg::OnClickedBt2)
	ON_BN_CLICKED(IDC_BT3, &CCovertDlg::OnClickedBt3)
	ON_BN_CLICKED(IDC_BT4, &CCovertDlg::OnClickedBt4)
	ON_BN_CLICKED(IDC_BT5, &CCovertDlg::OnClickedBt5)
	ON_BN_CLICKED(IDC_BT6, &CCovertDlg::OnClickedBt6)
	ON_BN_CLICKED(IDC_BT7, &CCovertDlg::OnClickedBt7)
	ON_BN_CLICKED(IDC_BT8, &CCovertDlg::OnClickedBt8)
	ON_BN_CLICKED(IDC_BT9, &CCovertDlg::OnClickedBt9)
	ON_BN_CLICKED(IDC_BTA, &CCovertDlg::OnClickedBta)
	ON_BN_CLICKED(IDC_BTB, &CCovertDlg::OnClickedBtb)
	ON_BN_CLICKED(IDC_BTC, &CCovertDlg::OnClickedBtc)
	ON_BN_CLICKED(IDC_BTD, &CCovertDlg::OnClickedBtd)
	ON_BN_CLICKED(IDC_BTE, &CCovertDlg::OnClickedBte)
	ON_BN_CLICKED(IDC_BTF, &CCovertDlg::OnClickedBtf)
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
	//m_nResult = _T("16����");
	UpdateData(FALSE);
}


void CCovertDlg::OnDec()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	//m_nResult = _T("10����");
	UpdateData(FALSE);
}


void CCovertDlg::OnOct()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	//m_nResult = _T("8����");
	UpdateData(FALSE);
}


void CCovertDlg::OnBin()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	//m_nResult = _T("2����");
	UpdateData(FALSE);
}


void CCovertDlg::OnClickedBtBack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBtClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBt9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBta()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBtb()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBtc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBtd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBte()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCovertDlg::OnClickedBtf()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

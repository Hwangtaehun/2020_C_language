// covertdlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "covertdlg.h"
#include "afxdialogex.h"

char g_aRadix[4] = { 16,10, 8, 2 };

// CCovertDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCovertDlg, CDialogEx)

CCovertDlg::CCovertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCovertDlg::IDD, pParent)
	//, m_nResult(_T(""))
	, m_strDisplay(_T(""))
	, m_nRadix(0)
{

	m_nValue = 0;

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
	/*ON_COMMAND(IDC_HEX, &CCovertDlg::OnHex)
	ON_COMMAND(IDC_DEC, &CCovertDlg::OnDec)
	ON_COMMAND(IDC_OCT, &CCovertDlg::OnOct)
	ON_COMMAND(IDC_BIN, &CCovertDlg::OnBin)*/
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
	ON_CONTROL_RANGE(BN_CLICKED, IDC_HEX, IDC_BIN, OnConvert)
END_MESSAGE_MAP()


// CCovertDlg �޽��� ó�����Դϴ�.
//void CCovertDlg::OnHex()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	UpdateData(TRUE);
//	//m_nResult = _T("16����");
//	UpdateData(FALSE);
//}
//
//
//void CCovertDlg::OnDec()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	UpdateData(TRUE);
//	//m_nResult = _T("10����");
//	UpdateData(FALSE);
//}
//
//
//void CCovertDlg::OnOct()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	UpdateData(TRUE);
//	//m_nResult = _T("8����");
//	UpdateData(FALSE);
//}
//
//
//void CCovertDlg::OnBin()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	UpdateData(TRUE);
//	//m_nResult = _T("2����");
//	UpdateData(FALSE);
//}


void CCovertDlg::OnClickedBtBack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nValue > 0)
		m_nValue = m_nValue / g_aRadix[m_nRadix];
	Display();
}


void CCovertDlg::OnClickedBtClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nValue = 0;
	m_strDisplay.Empty();
	UpdateData(FALSE);
}


void CCovertDlg::OnClickedBt0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix];
	Display();
}


void CCovertDlg::OnClickedBt1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 1;
	Display();
}


void CCovertDlg::OnClickedBt2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 2;
	Display();
}


void CCovertDlg::OnClickedBt3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 3;
	Display();
}


void CCovertDlg::OnClickedBt4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 4;
	Display();
}


void CCovertDlg::OnClickedBt5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 5;
	Display();
}


void CCovertDlg::OnClickedBt6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 6;
	Display();
}


void CCovertDlg::OnClickedBt7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 7;
	Display();
}


void CCovertDlg::OnClickedBt8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 8;
	Display();
}


void CCovertDlg::OnClickedBt9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 9;
	Display();
}


void CCovertDlg::OnClickedBta()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 10;
	Display();
}


void CCovertDlg::OnClickedBtb()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 11;
	Display();
}


void CCovertDlg::OnClickedBtc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 12;
	Display();
}


void CCovertDlg::OnClickedBtd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 13;
	Display();
}


void CCovertDlg::OnClickedBte()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 14;
	Display();
}


void CCovertDlg::OnClickedBtf()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (ValueRange(m_nValue))
		m_nValue = m_nValue * g_aRadix[m_nRadix] + 15;
	Display();
}


BOOL CCovertDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	OnConvert(IDC_HEX);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CCovertDlg::Display()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	char buf[33] = "";
	IntToString(m_nValue, buf, g_aRadix[m_nRadix]);
	m_strDisplay = buf;
	UpdateData(FALSE);
}


bool CCovertDlg::ValueRange(int value)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (value <= 2147483647 / g_aRadix[m_nRadix])
		return true;
	MessageBox(_T("���ڰ� �ʹ� Ů�ϴ� !!"));
	return false;
}


void CCovertDlg::IntToString(int value, char* buf, int radix)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int weight, i = 0, num;
	weight = radix;
	while (weight <= value)
	{
		weight *= radix;
	}
	weight /= radix;
	while (weight != 0)
	{
		if (i % 5 == 4 && i != 0)
		{
			buf[i] = ' ';
			i++;
		}
		num = value / weight;
		value %= weight;
		weight /= radix;
		if (num < 10)
			buf[i] = num + '0';
		else
			buf[i] = num - 10 + 'A';
		i++;
	}
	buf[i] = NULL;
}


void CCovertDlg::OnConvert(UINT value)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	UpdateData(TRUE);
	m_ctrlB2.EnableWindow(TRUE);
	m_ctrlB3.EnableWindow(TRUE);
	m_ctrlB4.EnableWindow(TRUE);
	m_ctrlB5.EnableWindow(TRUE);
	m_ctrlB6.EnableWindow(TRUE);
	m_ctrlB7.EnableWindow(TRUE);
	m_ctrlB8.EnableWindow(TRUE);
	m_ctrlB9.EnableWindow(TRUE);
	m_ctrlBa.EnableWindow(TRUE);
	m_ctrlBb.EnableWindow(TRUE);
	m_ctrlBc.EnableWindow(TRUE);
	m_ctrlBd.EnableWindow(TRUE);
	m_ctrlBe.EnableWindow(TRUE);
	m_ctrlBf.EnableWindow(TRUE);
	switch(m_nRadix)
	{
	case 3:
		m_ctrlB2.EnableWindow(FALSE);
		m_ctrlB3.EnableWindow(FALSE);
		m_ctrlB4.EnableWindow(FALSE);
		m_ctrlB5.EnableWindow(FALSE);
		m_ctrlB6.EnableWindow(FALSE);
		m_ctrlB7.EnableWindow(FALSE);
	case 2:
		m_ctrlB8.EnableWindow(FALSE);
		m_ctrlB9.EnableWindow(FALSE);
	case 1:
		m_ctrlBa.EnableWindow(FALSE);
		m_ctrlBb.EnableWindow(FALSE);
		m_ctrlBc.EnableWindow(FALSE);
		m_ctrlBd.EnableWindow(FALSE);
		m_ctrlBe.EnableWindow(FALSE);
		m_ctrlBf.EnableWindow(FALSE);
		break;
	}
	Display();
}

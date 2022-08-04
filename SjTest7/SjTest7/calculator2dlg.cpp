// calculator2dlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "calculator2dlg.h"
#include "afxdialogex.h"


// CCalculator2Dlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCalculator2Dlg, CDialogEx)

CCalculator2Dlg::CCalculator2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator2Dlg::IDD, pParent)
	, m_strInFix(_T(""))
	, m_strPostFix(_T(""))
	, m_nResult(0)
{

	OpTop = 0;
	PostTop = 0;
	CompTop = 0;
}

CCalculator2Dlg::~CCalculator2Dlg()
{
}

void CCalculator2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INFIX, m_strInFix);
	DDX_Text(pDX, IDC_POSTFIX, m_strPostFix);
	DDX_Text(pDX, IDC_RESULT, m_nResult);
	DDX_Control(pDX, IDC_POSTFIX, m_ctrlPostfix);
	DDX_Control(pDX, IDC_RESULT, m_ctrlResult);
}


BEGIN_MESSAGE_MAP(CCalculator2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BT0, &CCalculator2Dlg::OnClickedBt0)
	ON_BN_CLICKED(IDC_BT1, &CCalculator2Dlg::OnClickedBt1)
	ON_BN_CLICKED(IDC_BT2, &CCalculator2Dlg::OnClickedBt2)
	ON_BN_CLICKED(IDC_BT3, &CCalculator2Dlg::OnClickedBt3)
	ON_BN_CLICKED(IDC_BT4, &CCalculator2Dlg::OnClickedBt4)
	ON_BN_CLICKED(IDC_BT5, &CCalculator2Dlg::OnClickedBt5)
	ON_BN_CLICKED(IDC_BT6, &CCalculator2Dlg::OnClickedBt6)
	ON_BN_CLICKED(IDC_BT7, &CCalculator2Dlg::OnClickedBt7)
	ON_BN_CLICKED(IDC_BT8, &CCalculator2Dlg::OnClickedBt8)
	ON_BN_CLICKED(IDC_BT9, &CCalculator2Dlg::OnClickedBt9)
	ON_BN_CLICKED(IDC_COMPUTE, &CCalculator2Dlg::OnClickedCompute)
	ON_BN_CLICKED(IDC_BT_SQUARE, &CCalculator2Dlg::OnClickedBtSquare)
	ON_BN_CLICKED(IDC_BT_PLUS, &CCalculator2Dlg::OnClickedBtPlus)
	ON_BN_CLICKED(IDC_BT_MINUS, &CCalculator2Dlg::OnClickedBtMinus)
	ON_BN_CLICKED(IDC_BT_MULTIPLY, &CCalculator2Dlg::OnClickedBtMultiply)
	ON_BN_CLICKED(IDC_BT_DIVIDE, &CCalculator2Dlg::OnClickedBtDivide)
	ON_BN_CLICKED(IDC_BT_CLEAR, &CCalculator2Dlg::OnClickedBtClear)
END_MESSAGE_MAP()


// CCalculator2Dlg �޽��� ó�����Դϴ�.


void CCalculator2Dlg::OnClickedBt0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '0';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '1';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '2';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '3';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '4';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '5';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '6';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '7';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '8';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBt9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '9';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBtClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strInFix.Empty();
	m_strPostFix.Empty();
	m_nResult = 0;
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedCompute()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	InToPost(m_strInFix);
	m_strPostFix.Empty();
	for (int i = 0; i <= PostTop; i++)
	{
		if (PostStack[i].ch == 'D')
		{
			char buf[30];
			sprintf_s(buf, 30, "%d ", PostStack[i].num);
			m_strPostFix += buf;
		}
		else
		{
			m_strPostFix += PostStack[i].ch;
			m_strPostFix += _T(" ");
		}
	}
	m_nResult = Compute();
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBtSquare()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '^';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBtPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '+';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBtMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '-';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBtMultiply()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '*';
	UpdateData(FALSE);
}


void CCalculator2Dlg::OnClickedBtDivide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_strInFix += '/';
	UpdateData(FALSE);
}


void CCalculator2Dlg::InToPost(CString s)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int i = 0, n = 0;
	char buf[100];
	OpTop = PostTop = -1;

	while (s[i] != NULL)
	{
		if (Priority(s[i]) != 0)
		{
			if (n != 0)
			{
				buf[n] = NULL;
				PostPush(buf, 'D');
				n = 0;
			}
			while (OpTop >= BOTTOM && PriCompare(s[i], OpStack[OpTop]) <= 0)
			{
				PostPush("0", OpPop());
			}
			OpPush(s[i]);
		}
		else
		{
			buf[n] = s[i];
			n++;
		}
		i++;
	}
	if (n != 0)
	{
		buf[n] = NULL;
		PostPush(buf, 'D');
		n = 0;
	}
	while (OpTop >= BOTTOM)
	{
		PostPush("0", OpPop());
	}
}


int CCalculator2Dlg::Priority(char ch)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '^')
		return 3;
	return 0;
}


int CCalculator2Dlg::PriCompare(char ch1, char ch2)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int a, b;
	a = Priority(ch1);
	b = Priority(ch2);
	return(a - b);
}


int CCalculator2Dlg::PostPush(char* p, char ch)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (PostTop >= STACK_SIZE - 1)
	{
		MessageBox(_T("PostStck OverFlow"));
		return -1;
	}
	PostTop++;
	PostStack[PostTop].num = atoi(p);
	PostStack[PostTop].ch = ch;
	return 0;
}


int CCalculator2Dlg::OpPush(char ch)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (OpTop >= STACK_SIZE - 1)
	{
		MessageBox(_T("OpStack OverFlow"));
		return -1;
	}
	OpTop++;
	OpStack[OpTop] = ch;
	return 0;
}


char CCalculator2Dlg::OpPop()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	char data;
	if (OpTop < BOTTOM)
	{
		MessageBox(_T("OpStack Underflow"));
		return -1;
	}
	data = OpStack[OpTop];
	OpTop--;
	return data;
}


int CCalculator2Dlg::Compute()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int i = 0, data1, data2, result = 0;
	CompTop = -1;
	for (i = 0; i <= PostTop; i++)
	{
		if (PostStack[i].ch != 'D')
		{
			data1 = CompPop();
			data2 = CompPop();
			switch (PostStack[i].ch)
			{
			case '+':
				result = data2 + data1;
				break;
			case '-':
				result = data2 - data1;
				break;
			case '*':
				result = data2 * data1;
				break;
			case '/':
				result = data2 / data1;
				break;
			case '^':
				result = (int)pow((double)data2, (double)data1);
				break;
			}
			CompPush(result);
		}
		else
		{
			CompPush(PostStack[i].num);
		}
	}
	return CompPop();
}


int CCalculator2Dlg::CompPush(int num)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (CompTop >= STACK_SIZE - 1)
	{
		MessageBox(_T("CompStack OverFlow"));
		return -1;
	}
	CompTop++;
	CompStack[CompTop] = num;
	return 0;
}


int CCalculator2Dlg::CompPop()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int data;
	if (CompTop < BOTTOM)
	{
		MessageBox(_T("CompStack Underflow"));
		return -1;
	}
	data = CompStack[CompTop];
	CompTop--;
	return data;
}

BOOL CCalculator2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrlPostfix.EnableWindow(FALSE);
	m_ctrlResult.EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

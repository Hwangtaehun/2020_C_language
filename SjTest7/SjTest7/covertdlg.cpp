// covertdlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "covertdlg.h"
#include "afxdialogex.h"


// CCovertDlg 대화 상자입니다.

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


// CCovertDlg 메시지 처리기입니다.


//void CCovertDlg::OnEnChangeEdit1()
//{
//	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
//	// CDialogEx::OnInitDialog() 함수를 재지정 
//	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
//	// 이 알림 메시지를 보내지 않습니다.
//
//	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


void CCovertDlg::OnHex()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//m_nResult = _T("16진수");
	UpdateData(FALSE);
}


void CCovertDlg::OnDec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//m_nResult = _T("10진수");
	UpdateData(FALSE);
}


void CCovertDlg::OnOct()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//m_nResult = _T("8진수");
	UpdateData(FALSE);
}


void CCovertDlg::OnBin()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//m_nResult = _T("2진수");
	UpdateData(FALSE);
}


void CCovertDlg::OnClickedBtBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBtClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBt9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBta()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBtb()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBtc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBtd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBte()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCovertDlg::OnClickedBtf()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

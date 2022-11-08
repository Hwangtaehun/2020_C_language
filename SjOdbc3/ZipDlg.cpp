// ZipDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjOdbc3.h"
#include "ZipDlg.h"
#include "afxdialogex.h"


// ZipDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(ZipDlg, CDialogEx)

ZipDlg::ZipDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ZipDlg::IDD, pParent)
	, m_strSearchName(_T(""))
	, m_strList(_T(""))
{

}

ZipDlg::~ZipDlg()
{
}

void ZipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCHNAME, m_ctrlSearchName);
	DDX_Text(pDX, IDC_SEARCHNAME, m_strSearchName);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_LBString(pDX, IDC_LIST1, m_strList);
}


BEGIN_MESSAGE_MAP(ZipDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_SEARCH_BT, &ZipDlg::OnClickedSearchBt)
	ON_LBN_DBLCLK(IDC_LIST2, &ZipDlg::OnLbnDblclkList2)
END_MESSAGE_MAP()


// ZipDlg 메시지 처리기입니다.


BOOL ZipDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_zipSet.Open();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void ZipDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_zipSet.Close();
}


void ZipDlg::OnClickedSearchBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_strSearchName.IsEmpty())
	{
		m_ctrlSearchName.SetFocus();
		return;
	}
	m_zipSet.m_strFilter.Format(_T("DONG LIKE '%s%%'"), m_strSearchName);
	m_zipSet.Requery();

	CString strAddress;
	while (!m_zipSet.IsEOF())
	{
		strAddress = m_zipSet.m_ZIPCODE + " " + m_zipSet.m_SIDO + m_zipSet.m_GUGUN + m_zipSet.m_DONG;
		if (!m_zipSet.m_RI.IsEmpty())
			strAddress += m_zipSet.m_RI;
		if (!m_zipSet.m_BLDG.IsEmpty())
			strAddress += m_zipSet.m_BLDG;
		if (!m_zipSet.m_ST_BUNJI.IsEmpty())
			strAddress += (m_zipSet.m_ST_BUNJI + _T("-"));
		if (!m_zipSet.m_ED_BUNJI.IsEmpty())
			strAddress += m_zipSet.m_ED_BUNJI;
		m_ctrlList.AddString(strAddress);
		m_zipSet.MoveNext();
	}
	if (m_zipSet.GetRecordCount() == 0)
	{
		m_ctrlSearchName.SetFocus();
	}
	else
	{
		m_ctrlList.SetFocus();
		m_ctrlList.SetCurSel(0);
		m_bSearch = TRUE;
	}
}


void ZipDlg::OnLbnDblclkList2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


BOOL ZipDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (m_bSearch)
			OnOK();
		else
			OnClickedSearchBt();
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

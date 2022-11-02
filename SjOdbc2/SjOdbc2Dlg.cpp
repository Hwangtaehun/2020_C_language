
// SjOdbc2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SjOdbc2.h"
#include "SjOdbc2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSjOdbc2Dlg ��ȭ ����



CSjOdbc2Dlg::CSjOdbc2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjOdbc2Dlg::IDD, pParent)
	, m_strList(_T(""))
	, m_strNumber(_T(""))
	, m_strName(_T(""))
	, m_nKor(0)
	, m_nEng(0)
	, m_nMat(0)
	, m_strSearchData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSjOdbc2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST1, m_strList);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_Text(pDX, IDC_NUMBER, m_strNumber);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_KOR, m_nKor);
	DDX_Text(pDX, IDC_ENG, m_nEng);
	DDX_Text(pDX, IDC_MAT, m_nMat);
	DDX_Text(pDX, IDC_SEARCH_DATA, m_strSearchData);
}

BEGIN_MESSAGE_MAP(CSjOdbc2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FIRST_BT, &CSjOdbc2Dlg::OnClickedFirstBt)
	ON_BN_CLICKED(IDC_PREVIOUS_BT, &CSjOdbc2Dlg::OnClickedPreviousBt)
	ON_BN_CLICKED(IDC_NEXT_BT, &CSjOdbc2Dlg::OnClickedNextBt)
	ON_BN_CLICKED(IDC_LAST_BT, &CSjOdbc2Dlg::OnClickedLastBt)
	ON_BN_CLICKED(IDC_NAME_BT, &CSjOdbc2Dlg::OnClickedNameBt)
	ON_BN_CLICKED(IDC_KOR_BT, &CSjOdbc2Dlg::OnClickedKorBt)
	ON_BN_CLICKED(IDC_ENG_BT, &CSjOdbc2Dlg::OnClickedEngBt)
	ON_LBN_SELCHANGE(IDC_LIST1, &CSjOdbc2Dlg::OnSelchangeList1)
	ON_BN_CLICKED(IDC_ADD_BT, &CSjOdbc2Dlg::OnClickedAddBt)
	ON_BN_CLICKED(IDC_MODIFY_BT, &CSjOdbc2Dlg::OnClickedModifyBt)
	ON_BN_CLICKED(IDC_DELETE_BT, &CSjOdbc2Dlg::OnClickedDeleteBt)
	ON_BN_CLICKED(IDC_TOTAL_BT, &CSjOdbc2Dlg::OnClickedTotalBt)
	ON_BN_CLICKED(IDC_ASCSORT_BT, &CSjOdbc2Dlg::OnClickedAscsortBt)
	ON_BN_CLICKED(IDC_DESCSORT_BT, &CSjOdbc2Dlg::OnClickedDescsortBt)
	ON_BN_CLICKED(IDC_RANK_BT, &CSjOdbc2Dlg::OnClickedRankBt)
	ON_BN_CLICKED(IDC_CLOSE_BT, &CSjOdbc2Dlg::OnClickedCloseBt)
END_MESSAGE_MAP()


// CSjOdbc2Dlg �޽��� ó����

BOOL CSjOdbc2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	if (!m_ScoreTable.Open())
	{
		MessageBox(_T("Score Table ���� ���� !!"));
		return TRUE;
	}
	/*m_strNumber = m_ScoreTable.m_strCode;
	m_strName = m_ScoreTable.m_strName;
	m_nKor = m_ScoreTable.m_nKor;
	m_nEng = m_ScoreTable.m_nEng;
	m_nMat = m_ScoreTable.m_nMat;
	UpdateData(FALSE);*/
	MoveData();
	ListDisplay();
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CSjOdbc2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CSjOdbc2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CSjOdbc2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjOdbc2Dlg::MoveData()
{
	m_strNumber = m_ScoreTable.m_strCode;
	m_strName = m_ScoreTable.m_strName;
	m_nKor = m_ScoreTable.m_nKor;
	m_nEng = m_ScoreTable.m_nEng;
	m_nMat = m_ScoreTable.m_nMat;
	UpdateData(FALSE);
}


void CSjOdbc2Dlg::OnClickedFirstBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.MoveFirst();
	MoveData();
}


void CSjOdbc2Dlg::OnClickedPreviousBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.MovePrev();
	if (m_ScoreTable.IsBOF())
	{
		m_ScoreTable.MoveFirst();
	}
	MoveData();
}


void CSjOdbc2Dlg::OnClickedNextBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.MoveNext();
	if (m_ScoreTable.IsEOF())
	{
		m_ScoreTable.MoveLast();
	}
	MoveData();
}


void CSjOdbc2Dlg::OnClickedLastBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.MoveLast();
	MoveData();
}


void CSjOdbc2Dlg::ListDisplay()
{
	CString Buf;
	m_ctrlList.ResetContent();
	m_ScoreTable.MoveFirst();
	while (!m_ScoreTable.IsEOF())
	{
		Buf.Format(_T("%-5s%-8s %5d %5d %5d %5d %6.2lf %5d"), m_ScoreTable.m_strCode, m_ScoreTable.m_strName, m_ScoreTable.m_nKor, m_ScoreTable.m_nEng, m_ScoreTable.m_nMat, m_ScoreTable.m_nTotal, m_ScoreTable.m_dAverage, m_ScoreTable.m_nRank);
		m_ctrlList.AddString(Buf);
		m_ScoreTable.MoveNext();
	}
	m_ctrlList.SetCurSel(0);
	m_ScoreTable.MoveFirst();
}


void CSjOdbc2Dlg::OnClickedNameBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	//m_ScoreTable.m_strFilter = "strName='�հ�'";
	//m_ScoreTable.m_strFilter.Format(_T("strName = '%s'"), m_strSearchData);
	m_ScoreTable.m_strFilter.Format(_T("strName Like '%s%%'"), m_strSearchData);
	m_ScoreTable.Requery();
	if (m_ScoreTable.GetRecordCount() == 0)
		MessageBox(_T("�˻��� ������ �����"));
	else
		ListDisplay();
}


void CSjOdbc2Dlg::OnClickedKorBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_strSearchData.IsEmpty())
	{
		MessageBox(_T("�˻� ������ �����"));
		return;
	}
	//m_ScoreTable.m_strFilter = "nKor>=60"; /*Ȯ��*/
	m_ScoreTable.m_strFilter.Format(_T("nKor>=%s"), m_strSearchData);
	m_ScoreTable.Requery();
	if (m_ScoreTable.GetRecordCount() == 0)
		MessageBox(_T("�˻��� ������ �����"));
	else
		ListDisplay();
}


void CSjOdbc2Dlg::OnClickedEngBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int data;
	UpdateData(TRUE);
	if (m_strSearchData.IsEmpty())
		m_ScoreTable.m_strFilter = "";
	else
	{
		data = _ttoi(m_strSearchData);
		m_ScoreTable.m_strFilter.Format(_T("nEng>=%d"), data);
		// m_ScoreTable.m_strFilter.Format(_T("nEng>=%d AND nKor>=%d"), data, data); /*Ȯ��*/
		// m_ScoreTable.m_strFilter.Format(_T("nEng>=%d OR nKor>=%d"), data, data); /*Ȯ��*/
	}
	m_ScoreTable.Requery();
	if (m_ScoreTable.GetRecordCount() == 0)
		MessageBox(_T("�˻��� ������ �����."));
	else
		ListDisplay();
}


void CSjOdbc2Dlg::OnSelchangeList1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_ScoreTable.m_strFilter.Format(_T("strCode=%s"), m_strList.Mid(0, 4));
	m_ScoreTable.Requery();
	MoveData();
}


void CSjOdbc2Dlg::OnClickedAddBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
	m_ScoreTable.AddNew();

	m_ScoreTable.m_strCode = m_strNumber;
	m_ScoreTable.m_strName = m_strName;
	m_ScoreTable.m_nKor = m_nKor;
	m_ScoreTable.m_nEng = m_nEng;
	m_ScoreTable.m_nMat = m_nMat;

	m_ScoreTable.Update();
	m_ScoreTable.m_strFilter = "";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedModifyBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_ScoreTable.Edit();
	
	m_ScoreTable.m_strCode = m_strNumber;
	m_ScoreTable.m_strName = m_strName;
	m_ScoreTable.m_nKor = m_nKor;
	m_ScoreTable.m_nEng = m_nEng;
	m_ScoreTable.m_nMat = m_nMat;

	m_ScoreTable.Update();
	m_ScoreTable.m_strFilter = "";
	m_ScoreTable.Requery();
	ListDisplay();

}


void CSjOdbc2Dlg::OnClickedDeleteBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.Delete();
	m_ScoreTable.m_strFilter = "";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedTotalBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.MoveFirst();
	while (!m_ScoreTable.IsEOF())
	{
		m_ScoreTable.Edit();
		m_ScoreTable.m_nTotal = m_ScoreTable.m_nKor + m_ScoreTable.m_nEng + m_ScoreTable.m_nMat;
		m_ScoreTable.m_dAverage = m_ScoreTable.m_nTotal / 3.0;
		m_ScoreTable.m_nRank = 0;
		m_ScoreTable.Update();
		m_ScoreTable.MoveNext();
	}
	m_ScoreTable.m_strFilter = "";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedAscsortBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.m_strSort = "strName";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedDescsortBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ScoreTable.m_strSort = "strName DESC";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedRankBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nRank1 = 0, nRank2 = 0, nTotal = 0;
	//m_ScoreTable.m_strSort = "nTotal ASC"; /*Ȯ��*/
	m_ScoreTable.m_strSort = "nTotal DESC";
	m_ScoreTable.Requery();
	m_ScoreTable.MoveFirst();
	while (!m_ScoreTable.IsEOF())
	{
		nRank1++;
		if (nTotal != m_ScoreTable.m_nTotal)
		{
			nTotal = m_ScoreTable.m_nTotal;
			nRank2 = nRank1;
		}
		m_ScoreTable.Edit();
		m_ScoreTable.m_nRank = nRank2;
		m_ScoreTable.Update();

		m_ScoreTable.MoveNext();
	}
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedCloseBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

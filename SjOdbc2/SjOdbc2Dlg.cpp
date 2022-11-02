
// SjOdbc2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SjOdbc2.h"
#include "SjOdbc2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CSjOdbc2Dlg 대화 상자



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


// CSjOdbc2Dlg 메시지 처리기

BOOL CSjOdbc2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	if (!m_ScoreTable.Open())
	{
		MessageBox(_T("Score Table 연결 실패 !!"));
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
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSjOdbc2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ScoreTable.MoveFirst();
	MoveData();
}


void CSjOdbc2Dlg::OnClickedPreviousBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ScoreTable.MovePrev();
	if (m_ScoreTable.IsBOF())
	{
		m_ScoreTable.MoveFirst();
	}
	MoveData();
}


void CSjOdbc2Dlg::OnClickedNextBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ScoreTable.MoveNext();
	if (m_ScoreTable.IsEOF())
	{
		m_ScoreTable.MoveLast();
	}
	MoveData();
}


void CSjOdbc2Dlg::OnClickedLastBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//m_ScoreTable.m_strFilter = "strName='왕건'";
	//m_ScoreTable.m_strFilter.Format(_T("strName = '%s'"), m_strSearchData);
	m_ScoreTable.m_strFilter.Format(_T("strName Like '%s%%'"), m_strSearchData);
	m_ScoreTable.Requery();
	if (m_ScoreTable.GetRecordCount() == 0)
		MessageBox(_T("검색된 내용이 없어요"));
	else
		ListDisplay();
}


void CSjOdbc2Dlg::OnClickedKorBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_strSearchData.IsEmpty())
	{
		MessageBox(_T("검색 조건이 없어요"));
		return;
	}
	//m_ScoreTable.m_strFilter = "nKor>=60"; /*확인*/
	m_ScoreTable.m_strFilter.Format(_T("nKor>=%s"), m_strSearchData);
	m_ScoreTable.Requery();
	if (m_ScoreTable.GetRecordCount() == 0)
		MessageBox(_T("검색된 내용이 없어요"));
	else
		ListDisplay();
}


void CSjOdbc2Dlg::OnClickedEngBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int data;
	UpdateData(TRUE);
	if (m_strSearchData.IsEmpty())
		m_ScoreTable.m_strFilter = "";
	else
	{
		data = _ttoi(m_strSearchData);
		m_ScoreTable.m_strFilter.Format(_T("nEng>=%d"), data);
		// m_ScoreTable.m_strFilter.Format(_T("nEng>=%d AND nKor>=%d"), data, data); /*확인*/
		// m_ScoreTable.m_strFilter.Format(_T("nEng>=%d OR nKor>=%d"), data, data); /*확인*/
	}
	m_ScoreTable.Requery();
	if (m_ScoreTable.GetRecordCount() == 0)
		MessageBox(_T("검색된 내용이 없어요."));
	else
		ListDisplay();
}


void CSjOdbc2Dlg::OnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ScoreTable.m_strFilter.Format(_T("strCode=%s"), m_strList.Mid(0, 4));
	m_ScoreTable.Requery();
	MoveData();
}


void CSjOdbc2Dlg::OnClickedAddBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ScoreTable.Delete();
	m_ScoreTable.m_strFilter = "";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedTotalBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ScoreTable.m_strSort = "strName";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedDescsortBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ScoreTable.m_strSort = "strName DESC";
	m_ScoreTable.Requery();
	ListDisplay();
}


void CSjOdbc2Dlg::OnClickedRankBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nRank1 = 0, nRank2 = 0, nTotal = 0;
	//m_ScoreTable.m_strSort = "nTotal ASC"; /*확인*/
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}

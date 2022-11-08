
// SjOdbc3View.cpp : CSjOdbc3View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjOdbc3.h"
#endif

#include "SjOdbc3Doc.h"
#include "SjOdbc3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjOdbc3View

IMPLEMENT_DYNCREATE(CSjOdbc3View, CFormView)

BEGIN_MESSAGE_MAP(CSjOdbc3View, CFormView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CSjOdbc3View::OnItemchangedList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CSjOdbc3View::OnClickList1)
	ON_BN_CLICKED(IDC_NEWRECORD_BT, &CSjOdbc3View::OnClickedNewrecordBt)
	ON_BN_CLICKED(IDC_ADD_BT, &CSjOdbc3View::OnClickedAddBt)
	ON_BN_CLICKED(IDC_ADDCANCEL_BT, &CSjOdbc3View::OnClickedAddcancelBt)
	ON_BN_CLICKED(IDC_MODIFY_BT, &CSjOdbc3View::OnClickedModifyBt)
	ON_BN_CLICKED(IDC_DELETE_BT, &CSjOdbc3View::OnClickedDeleteBt)
	ON_BN_CLICKED(IDC_ZIP_BT, &CSjOdbc3View::OnClickedZipBt)
END_MESSAGE_MAP()

// CSjOdbc3View 생성/소멸

CSjOdbc3View::CSjOdbc3View()
	: CFormView(CSjOdbc3View::IDD)
	, m_strName(_T(""))
	, m_strCode(_T(""))
	, m_strRegNumber(_T(""))
	, m_strEmail(_T(""))
	, m_strAddress(_T(""))
	, m_strLastAddress(_T(""))
	, m_strCellPhone(_T(""))
	, m_strHomePhone(_T(""))
	, m_strZipCode(_T(""))
	, m_BirthDay(COleDateTime::GetCurrentTime())
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSjOdbc3View::~CSjOdbc3View()
{
}

void CSjOdbc3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DELETE_BT, m_ctrlDeleteBt);
	DDX_Control(pDX, IDC_ADD_BT, m_ctrlAddBt);
	DDX_Control(pDX, IDC_ADDCANCEL_BT, m_ctrlAddCancel);
	DDX_Control(pDX, IDC_MODIFY_BT, m_ctrlModifyBt);
	DDX_Control(pDX, IDC_NEWRECORD_BT, m_ctrlNewRecordBt);
	DDX_Control(pDX, IDC_ZIP_BT, m_ctrlZipBt);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_CODE, m_strCode);
	DDX_Text(pDX, IDC_REG_NUMBER, m_strRegNumber);
	DDX_Text(pDX, IDC_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_LASTADDRESS, m_strLastAddress);
	DDX_Text(pDX, IDC_CELLPHONE, m_strCellPhone);
	DDX_Text(pDX, IDC_HOMEPHONE, m_strHomePhone);
	DDX_Text(pDX, IDC_ZIPCODE, m_strZipCode);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_BirthDay);
}

BOOL CSjOdbc3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CSjOdbc3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_ctrlList.InsertColumn(0, _T("번호"), LVCFMT_CENTER, 50);
	m_ctrlList.InsertColumn(1, _T("이름"), LVCFMT_LEFT, 70);
	m_ctrlList.InsertColumn(2, _T("휴대전화번호"), LVCFMT_LEFT, 100);
	m_ctrlList.InsertColumn(3, _T("Email"), LVCFMT_LEFT, 100);
	CRect rect;
	m_ctrlList.GetClientRect(&rect);
	m_ctrlList.InsertColumn(4, _T("주소"), LVCFMT_LEFT, rect.Width() - 320);
	m_ctrlList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_pStuSet = &GetDocument()->m_stuSet;
	m_pZipSet = &GetDocument()->m_zipSet;

	m_ctrlZipBt.EnableWindow(FALSE);
	m_ctrlAddCancel.EnableWindow(FALSE);
	m_ctrlAddBt.EnableWindow(FALSE);
	m_ctrlModifyBt.EnableWindow(FALSE);
	m_ctrlDeleteBt.EnableWindow(FALSE);

	MoveData(FALSE);
	DisplayList();
}


// CSjOdbc3View 진단

#ifdef _DEBUG
void CSjOdbc3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CSjOdbc3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSjOdbc3Doc* CSjOdbc3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSjOdbc3Doc)));
	return (CSjOdbc3Doc*)m_pDocument;
}
#endif //_DEBUG


// CSjOdbc3View 메시지 처리기


void CSjOdbc3View::DisplayList()
{
	int cnt = 0;
	m_pStuSet->m_strFilter = "";
	m_pStuSet->Requery();
	m_pStuSet->MoveFirst();

	m_ctrlList.DeleteAllItems();
	while (!m_pStuSet->IsEOF())
	{
		m_ctrlList.InsertItem(cnt, m_pStuSet->m_strCode);
		m_ctrlList.SetItemText(cnt, 1, m_pStuSet->m_strName);
		m_ctrlList.SetItemText(cnt, 2, m_pStuSet->m_strCellPhoneNumber);
		m_ctrlList.SetItemText(cnt, 3, m_pStuSet->m_strEmail);
		m_ctrlList.SetItemText(cnt, 4, m_pStuSet->m_strLastAddress);
		m_pStuSet->MoveNext();
		cnt++;
	}
}


void CSjOdbc3View::MoveData(bool bCheck)
{
	if (bCheck)
	{
		UpdateData(TRUE);
		m_pStuSet->m_strCode = m_strCode;
		m_pStuSet->m_strName = m_strName;
		m_pStuSet->m_RegistrationNumber = m_strRegNumber;
		m_pStuSet->m_strEmail = m_strEmail;
		m_pStuSet->m_strZipCode = m_strZipCode;
		m_pStuSet->m_strLastAddress = m_strLastAddress;
		m_pStuSet->m_dBirthDay = m_BirthDay;
		m_pStuSet->m_strCellPhoneNumber = m_strCellPhone;
		m_pStuSet->m_strHomePhoneNumber = m_strHomePhone;
	}
	else
	{
		m_strCode = m_pStuSet->m_strCode;
		m_strName = m_pStuSet->m_strName;
		m_strRegNumber = m_pStuSet->m_RegistrationNumber;
		m_strEmail = m_pStuSet->m_strEmail;
		m_strZipCode = m_pStuSet->m_strZipCode;
		m_strLastAddress = m_pStuSet->m_strLastAddress;
		m_BirthDay = m_pStuSet->m_dBirthDay;
		m_strCellPhone = m_pStuSet->m_strCellPhoneNumber;
		m_strHomePhone = m_pStuSet->m_strHomePhoneNumber;
		
		m_pZipSet->m_strFilter.Format(_T("ZIPCODE='%s'"), m_pStuSet->m_strZipCode);
		m_pZipSet->Requery();

		if (m_pZipSet->GetRecordCount() == 0)
			m_strAddress = "";
		else
		{
			m_strAddress = m_pZipSet->m_SIDO + m_pZipSet->m_GUGUN + m_pZipSet->m_DONG;
			if (!m_pZipSet->m_RI.IsEmpty())
				m_strAddress += m_pZipSet->m_RI;
			if (!m_pZipSet->m_BLDG.IsEmpty())
				m_strAddress += m_pZipSet->m_BLDG;
			if (!m_pZipSet->m_ST_BUNJI.IsEmpty())
				m_strAddress += (m_pZipSet->m_ST_BUNJI + _T("-"));
			if (!m_pZipSet->m_ED_BUNJI.IsEmpty())
				m_strAddress += m_pZipSet->m_ED_BUNJI;
		}
		UpdateData(FALSE);
	}
}


void CSjOdbc3View::OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MoveList();
	*pResult = 0;
}


void CSjOdbc3View::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MoveList();
	*pResult = 0;
}


void CSjOdbc3View::MoveList()
{
	int nSelect = m_ctrlList.GetSelectionMark();

	m_pStuSet->m_strFilter.Format(_T("strCode = '%s'"), m_ctrlList.GetItemText(nSelect, 0));
	m_pStuSet->Requery();

	if (m_pStuSet->GetRecordCount() == 0)
	{
		MessageBox(_T("검색된 내용이 없어요."));
	}
	else
	{
		m_ctrlModifyBt.EnableWindow(TRUE);
		m_ctrlDeleteBt.EnableWindow(TRUE);
		m_ctrlZipBt.EnableWindow(TRUE);
		m_ctrlAddCancel.EnableWindow(FALSE);
		m_ctrlAddBt.EnableWindow(FALSE);

		MoveData(FALSE);
	}
}


void CSjOdbc3View::OnClickedNewrecordBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pStuSet->AddNew();
	MoveData(FALSE); //확인
	m_ctrlZipBt.EnableWindow(TRUE);
	m_ctrlAddCancel.EnableWindow(TRUE);
	m_ctrlAddBt.EnableWindow(TRUE);
	m_ctrlModifyBt.EnableWindow(FALSE);
	m_ctrlDeleteBt.EnableWindow(FALSE);
	m_bAdd = TRUE;
}


void CSjOdbc3View::OnClickedAddBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bAdd)
	{
		MoveData(TRUE);
		m_pStuSet->Update();
		m_pStuSet->m_strFilter = "";
		m_pStuSet->Requery();
		DisplayList();
		OnClickedAddcancelBt();
	}
}


void CSjOdbc3View::OnClickedAddcancelBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctrlZipBt.EnableWindow(FALSE);
	m_ctrlAddCancel.EnableWindow(FALSE);
	m_ctrlAddBt.EnableWindow(FALSE);
	m_bAdd = FALSE;
	m_pStuSet->m_strFilter = "";
	m_pStuSet->Requery();
	MoveData(FALSE);
}


void CSjOdbc3View::OnClickedModifyBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pStuSet->Edit();
	MoveData(TRUE);
	m_pStuSet->Update();
	DisplayList();
	m_ctrlModifyBt.EnableWindow(FALSE);
	m_ctrlDeleteBt.EnableWindow(FALSE);
	m_ctrlZipBt.EnableWindow(FALSE);
}


void CSjOdbc3View::OnClickedDeleteBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pStuSet->Delete();
	DisplayList();
	m_pStuSet->MoveFirst();
	MoveData(FALSE);

	m_ctrlModifyBt.EnableWindow(FALSE);
	m_ctrlDeleteBt.EnableWindow(FALSE);
	m_ctrlZipBt.EnableWindow(FALSE);
}


void CSjOdbc3View::OnClickedZipBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다
	ZipDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_strZipCode = dlg.m_strList.Left(7);
		m_strAddress - dlg.m_strList.Mid(8);
		UpdateData(FALSE);
	}
}

// inputdlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "inputdlg.h"
#include "afxdialogex.h"


// CInputDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputDlg::IDD, pParent)
	, m_bCheckInform(FALSE)
	, m_strDay(_T(""))
	, m_strMonth(_T(""))
	, m_strYear(_T(""))
	, m_strName(_T(""))
	, m_nEng(0)
	, m_strID(_T(""))
	, m_nKor(0)
	, m_nMat(0)
	, m_strPassword1(_T(""))
	, m_strPassword2(_T(""))
	, m_radioArmy(0)
	, m_radioMale(0)
	, m_radioSolar(0)
	, m_strJumin1(_T(""))
	, m_strJumin2(_T(""))
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_INFORM, m_bCheckInform);
	DDX_Control(pDX, IDC_COMBO_DAY, m_ctrlDay);
	DDX_CBString(pDX, IDC_COMBO_DAY, m_strDay);
	DDX_Control(pDX, IDC_COMBO_MONTH, m_ctrlMonth);
	DDX_CBString(pDX, IDC_COMBO_MONTH, m_strMonth);
	DDX_Control(pDX, IDC_COMBO_YEAR, m_ctrlYear);
	DDX_CBString(pDX, IDC_COMBO_YEAR, m_strYear);
	DDX_Control(pDX, IDC_EDIT_NAME, m_ctrlName);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_ENG, m_nEng);
	DDX_Text(pDX, IDC_ID, m_strID);
	DDX_Control(pDX, IDC_JUMIN1, m_ctrlJumin1);
	DDX_Control(pDX, IDC_JUMIN2, m_ctrlJumin2);
	DDX_Text(pDX, IDC_KOR, m_nKor);
	DDX_Text(pDX, IDC_MAT, m_nMat);
	DDX_Text(pDX, IDC_PASSWORD1, m_strPassword1);
	DDX_Text(pDX, IDC_PASSWORD2, m_strPassword2);
	DDX_Control(pDX, IDC_PROGRESS_MAT, m_ctrlProgressMat);
	DDX_Radio(pDX, IDC_RADIO_ARMY1, m_radioArmy);
	DDX_Control(pDX, IDC_RADIO_ARMY1, m_ctrlArmy1);
	DDX_Control(pDX, IDC_RADIO_ARMY2, m_ctrlArmy2);
	DDX_Control(pDX, IDC_RADIO_ARMY3, m_ctrlArmy3);
	DDX_Control(pDX, IDC_RADIO_ARMY4, m_ctrlArmy4);
	DDX_Radio(pDX, IDC_RADIO_MALE, m_radioMale);
	DDX_Radio(pDX, IDC_RADIO_SOLAR, m_radioSolar);
	DDX_Control(pDX, IDC_SLIDER_ENG, m_ctrlSliderEng);
	DDX_Control(pDX, IDC_SLIDER_KOR, m_ctrlSliderKor);
	DDX_Control(pDX, IDC_SPIN_KOR, m_ctrlSpinKor);
	DDX_Control(pDX, IDC_SPIN_MAT, m_ctrlSpinMat);
	DDX_Control(pDX, IDC_RADIO_FEMALE, m_radioFemale);
	DDX_Text(pDX, IDC_JUMIN1, m_strJumin1);
	DDV_MaxChars(pDX, m_strJumin1, 6);
	DDX_Text(pDX, IDC_JUMIN2, m_strJumin2);
	DDV_MaxChars(pDX, m_strJumin2, 7);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_EN_KILLFOCUS(IDC_JUMIN2, &CInputDlg::OnKillfocusJumin2)
	ON_EN_KILLFOCUS(IDC_PASSWORD2, &CInputDlg::OnKillfocusPassword2)
	ON_CBN_SELCHANGE(IDC_COMBO_YEAR, &CInputDlg::OnSelchangeComboYear)
	ON_CBN_SELENDOK(IDC_COMBO_YEAR, &CInputDlg::OnSelendokComboYear)
	ON_CBN_SELCHANGE(IDC_COMBO_MONTH, &CInputDlg::OnSelchangeComboMonth)
ON_CBN_SELENDOK(IDC_COMBO_DAY, &CInputDlg::OnSelendokComboDay)
ON_BN_CLICKED(IDC_RADIO_MALE, &CInputDlg::OnClickedRadioMale)
ON_BN_CLICKED(IDC_RADIO_FEMALE, &CInputDlg::OnClickedRadioFemale)
ON_EN_KILLFOCUS(IDC_KOR, &CInputDlg::OnKillfocusKor)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_KOR, &CInputDlg::OnDeltaposSpinKor)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_KOR, &CInputDlg::OnCustomdrawSliderKor)
ON_EN_CHANGE(IDC_ENG, &CInputDlg::OnChangeEng)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_ENG, &CInputDlg::OnCustomdrawSliderEng)
ON_EN_KILLFOCUS(IDC_MAT, &CInputDlg::OnKillfocusMat)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MAT, &CInputDlg::OnDeltaposSpinMat)
END_MESSAGE_MAP()


// CInputDlg �޽��� ó�����Դϴ�.




BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	int i;
	CString str;
	CTime tt = CTime::GetCurrentTime();
	for ( i = 1900; i <= tt.GetYear(); i++)
	{
		str.Format(_T("%d"), i);
		m_ctrlYear.AddString(str);
	}
	for ( i = 1; i <= 12; i++)
	{
		str.Format(_T("%d"), i);
		m_ctrlMonth.AddString(str);
	}
	m_strYear.Format(_T("%d"), tt.GetYear());
	m_strMonth.Format(_T("%d"), tt.GetMonth());
	UpdateData(FALSE);
	OnSelchangeComboMonth();
	m_strDay.Format(_T("%d"), tt.GetDay());
	UpdateData(FALSE);
	m_ctrlSpinKor.SetRange(0, 100);
	m_ctrlSpinMat.SetRange(0, 100);
	m_ctrlProgressMat.SetRange(0, 100);
	m_ctrlSliderKor.SetRange(0, 100); 
	m_ctrlSliderEng.SetRange(0, 100);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CInputDlg::OnKillfocusJumin2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int i, tot = 0, na;
	int weight[12] = { 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5 };
	CString strJumin;
	UpdateData(TRUE);
	strJumin = m_strJumin1 + m_strJumin2;
	if (strJumin.GetLength() != 13)
	{
		MessageBox(_T("�ֹι�ȣ �Է� ����"));
		return;
	}
	for ( i = 0; i < 12; i++)
	{
		tot += weight[i] * (strJumin[i] - '0');
	}
	na = 11 - tot % 11;
	na %= 10;
	if (na != (strJumin[12] -'0'))
	{
		MessageBox(_T("Ʋ�� �ֹι�ȣ �Դϴ�."));
	}
}


void CInputDlg::OnKillfocusPassword2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_strPassword1 != m_strPassword2)
	{
		MessageBox(_T("Password�� Ʋ���ϴ�."));
	}
}


void CInputDlg::OnSelchangeComboYear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MessageBeep(1);
}


void CInputDlg::OnSelendokComboYear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnSelchangeComboMonth();
}


void CInputDlg::OnSelchangeComboMonth()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int i, yy, mm, dd[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	CString str;
	UpdateData(TRUE);
	yy = _ttoi(m_strYear);
	mm = _ttoi(m_strMonth);
	if (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0)
		dd[1] = 29;
	else
		dd[1] = 28;
	m_ctrlDay.ResetContent();
	for ( i = 1; i <= dd[mm - 1]; i++)
	{
		str.Format(_T("%d"), i);
		m_ctrlDay.AddString(str);
	}
	UpdateData(FALSE);
	m_ctrlDay.SetCurSel(0);
}


void CInputDlg::OnSelendokComboDay()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	m_ctrlDay.GetLBText(m_ctrlDay.GetCurSel(), str);
	MessageBox(str);
}


void CInputDlg::OnClickedRadioMale()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlArmy1.EnableWindow(true);
	m_ctrlArmy2.EnableWindow(true);
	m_ctrlArmy3.EnableWindow(true);
	m_ctrlArmy4.EnableWindow(true);
}


void CInputDlg::OnClickedRadioFemale()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlArmy1.EnableWindow(false);
	m_ctrlArmy2.EnableWindow(false);
	m_ctrlArmy3.EnableWindow(false);
	m_ctrlArmy4.EnableWindow(false);
}


void CInputDlg::OnKillfocusKor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_ctrlSliderKor.SetPos(m_nKor);

}


void CInputDlg::OnDeltaposSpinKor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	UpdateData(TRUE);
	m_ctrlSliderKor.SetPos(m_nKor);
}


void CInputDlg::OnCustomdrawSliderKor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	m_nKor = m_ctrlSliderKor.GetPos();
	UpdateData(FALSE);
}


void CInputDlg::OnChangeEng()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (UpdateData(TRUE))
	{
		m_ctrlSliderEng.SetPos(m_nEng);
	}
}


void CInputDlg::OnCustomdrawSliderEng(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	m_nEng = m_ctrlSliderEng.GetPos();
	UpdateData(FALSE);
}


void CInputDlg::OnKillfocusMat()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_ctrlProgressMat.SetPos(m_nMat);
}


void CInputDlg::OnDeltaposSpinMat(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	UpdateData(TRUE);
	m_ctrlProgressMat.SetPos(m_nMat);
}

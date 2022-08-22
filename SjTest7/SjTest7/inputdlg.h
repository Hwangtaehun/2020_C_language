#pragma once
#include "afxwin.h"
#include "EditNumber.h"
#include "afxcmn.h"


// CInputDlg ��ȭ �����Դϴ�.

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInputDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CINPUTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bCheckInform;
	CComboBox m_ctrlDay;
	CString m_strDay;
	CComboBox m_ctrlMonth;
	CString m_strMonth;
	CComboBox m_ctrlYear;
	CString m_strYear;
	CEdit m_ctrlName;
	CString m_strName;
	int m_nEng;
	CString m_strID;
	CEditNumber m_ctrlJumin1;
	CEditNumber m_ctrlJumin2;
	int m_nKor;
	int m_nMat;
	CString m_strPassword1;
	CString m_strPassword2;
	CProgressCtrl m_ctrlProgressMat;
	int m_radioArmy;
	CButton m_ctrlArmy1;
	CButton m_ctrlArmy2;
	CButton m_ctrlArmy3;
	CButton m_ctrlArmy4;
	int m_radioMale;
	int m_radioSolar;
	CSliderCtrl m_ctrlSliderEng;
	CSliderCtrl m_ctrlSliderKor;
	CSpinButtonCtrl m_ctrlSpinKor;
	CSpinButtonCtrl m_ctrlSpinMat;
	CButton m_radioFemale;
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusJumin2();
	afx_msg void OnKillfocusPassword2();
	afx_msg void OnSelchangeComboYear();
	afx_msg void OnSelendokComboYear();
	afx_msg void OnSelchangeComboMonth();
	afx_msg void OnSelendokComboDay();
	afx_msg void OnClickedRadioMale();
	afx_msg void OnClickedRadioFemale();
	afx_msg void OnKillfocusKor();
	afx_msg void OnDeltaposSpinKor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCustomdrawSliderKor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnChangeEng();
	afx_msg void OnCustomdrawSliderEng(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnKillfocusMat();
	afx_msg void OnDeltaposSpinMat(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strJumin1;
	CString m_strJumin2;
};

#pragma once


// CCovertDlg 대화 상자입니다.

class CCovertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCovertDlg)

public:
	CCovertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCovertDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CCONVERTDIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	int m_nRadio;
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnHex();
	afx_msg void OnDec();
	afx_msg void OnOct();
	afx_msg void OnBin();
	CString m_nResult;
};

#pragma once


// CCovertDlg ��ȭ �����Դϴ�.

class CCovertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCovertDlg)

public:
	CCovertDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCovertDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CCONVERTDIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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

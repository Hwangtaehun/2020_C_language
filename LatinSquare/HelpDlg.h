#pragma once


// CHelpDlg ��ȭ �����Դϴ�.

class CHelpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHelpDlg)

public:
	CHelpDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHelpDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HELP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strHelp;
};

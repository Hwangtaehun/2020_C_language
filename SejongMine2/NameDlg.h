#pragma once


// CNameDlg ��ȭ �����Դϴ�.

class CNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNameDlg)

public:
	CNameDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNameDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_NAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
};

#pragma once


// CRankDlg ��ȭ �����Դϴ�.

class CRankDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRankDlg)

public:
	CRankDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRankDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RANK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strLevel;
	CString m_strName1;
	CString m_strName2;
	CString m_strName3;
	int m_nTime1;
	int m_nTime2;
	int m_nTime3;
};

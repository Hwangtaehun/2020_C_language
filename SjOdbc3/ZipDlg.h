#pragma once
#include "ZipCode.h"

// ZipDlg ��ȭ �����Դϴ�.

class ZipDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ZipDlg)

public:
	ZipDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ZipDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CZipCode m_zipSet;
	BOOL m_bSearch;
	CEdit m_ctrlSearchName;
	CString m_strSearchName;
	CListBox m_ctrlList;
	CString m_strList;
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnClickedSearchBt();
	afx_msg void OnLbnDblclkList2();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

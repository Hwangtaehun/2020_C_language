#pragma once
#include "ZipCode.h"

// ZipDlg 대화 상자입니다.

class ZipDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ZipDlg)

public:
	ZipDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ZipDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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

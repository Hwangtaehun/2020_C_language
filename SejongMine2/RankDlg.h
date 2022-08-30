#pragma once


// CRankDlg 대화 상자입니다.

class CRankDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRankDlg)

public:
	CRankDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRankDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_RANK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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

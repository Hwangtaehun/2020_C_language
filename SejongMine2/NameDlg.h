#pragma once


// CNameDlg 대화 상자입니다.

class CNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNameDlg)

public:
	CNameDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CNameDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_NAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
};

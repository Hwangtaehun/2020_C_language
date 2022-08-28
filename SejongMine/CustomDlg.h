#pragma once


// CCustomDlg 대화 상자

class CCustomDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomDlg)

public:
	CCustomDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCustomDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nHeight;
	int m_nWidth;
	int m_nMine;
};

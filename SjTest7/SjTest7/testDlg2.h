#pragma once


// testDlg2 대화 상자

class testDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(testDlg2)

public:
	testDlg2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~testDlg2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTESTDLG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};

#pragma once


// testDlg3 대화 상자

class testDlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(testDlg3)

public:
	testDlg3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~testDlg3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTESTDLG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};

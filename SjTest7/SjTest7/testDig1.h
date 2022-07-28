#pragma once


// testDig1 대화 상자

class testDig1 : public CDialogEx
{
	DECLARE_DYNAMIC(testDig1)

public:
	testDig1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~testDig1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTESTDLG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};

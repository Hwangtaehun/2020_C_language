#pragma once


// CCalculator2Dlg 대화 상자입니다.

class CCalculator2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCalculator2Dlg)

public:
	CCalculator2Dlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCalculator2Dlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CCALCULATOR2DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};

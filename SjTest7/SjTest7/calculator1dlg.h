#pragma once


// calculator1dlg 대화 상자

class calculator1dlg : public CDialogEx
{
	DECLARE_DYNAMIC(calculator1dlg)

public:
	calculator1dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~calculator1dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCALCULATOR1DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};

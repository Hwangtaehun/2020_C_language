#pragma once

#define STACK_SIZE 30
#define BOTTOM 0
// CCalculator2Dlg 대화 상자입니다.

struct STACK {
	int num;
	char ch;
};

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
public:
	CString m_strInFix;
	CString m_strPostFix;
	int m_nResult;
	STACK PostStack [STACK_SIZE];
	char OpStack [STACK_SIZE];
	int CompStack[STACK_SIZE];
	afx_msg void OnClickedBt0();
	afx_msg void OnClickedBt1();
	afx_msg void OnClickedBt2();
	afx_msg void OnClickedBt3();
	afx_msg void OnClickedBt4();
	afx_msg void OnClickedBt5();
	afx_msg void OnClickedBt6();
	afx_msg void OnClickedBt7();
	afx_msg void OnClickedBt8();
	afx_msg void OnClickedBt9();
	afx_msg void OnClickedBtClear();
	afx_msg void OnClickedCompute();
	afx_msg void OnClickedBtSquare();
	afx_msg void OnClickedBtPlus();
	afx_msg void OnClickedBtMinus();
	afx_msg void OnClickedBtMultiply();
	afx_msg void OnClickedBtDivide();
	int OpTop;
	int PostTop;
	int CompTop;
	void InToPost(CString s);
	int Priority(char ch);
	int PriCompare(char ch1, char ch2);
	int PostPush(char* p, char ch);
	int OpPush(char ch);
	char OpPop();
	int Compute();
	int CompPush(int num);
	int CompPop();
};

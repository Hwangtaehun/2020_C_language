#pragma once


// CCalculator2Dlg ��ȭ �����Դϴ�.

class CCalculator2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCalculator2Dlg)

public:
	CCalculator2Dlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCalculator2Dlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CCALCULATOR2DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

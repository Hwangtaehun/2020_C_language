
// SjOdbc2Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "Score.h"

// CSjOdbc2Dlg ��ȭ ����
class CSjOdbc2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjOdbc2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJODBC2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strList;
	CListBox m_ctrlList;
	CString m_strNumber;
	CString m_strName;
	int m_nKor;
	int m_nEng;
	int m_nMat;
	CString m_strSearchData;
	CScore m_ScoreTable;
	void MoveData();
	afx_msg void OnClickedFirstBt();
	afx_msg void OnClickedPreviousBt();
	afx_msg void OnClickedNextBt();
	afx_msg void OnClickedLastBt();
	void ListDisplay();
	afx_msg void OnClickedNameBt();
	afx_msg void OnClickedKorBt();
	afx_msg void OnClickedEngBt();
	afx_msg void OnSelchangeList1();
	afx_msg void OnClickedAddBt();
	afx_msg void OnClickedModifyBt();
	afx_msg void OnClickedDeleteBt();
	afx_msg void OnClickedTotalBt();
	afx_msg void OnClickedAscsortBt();
	afx_msg void OnClickedDescsortBt();
	afx_msg void OnClickedRankBt();
	afx_msg void OnClickedCloseBt();
};

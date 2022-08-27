
// RandomWalkDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#define PIC_SIZE 500
#define START_X 8
#define START_Y 8
#define MAXCNT 30

// CRandomWalkDlg ��ȭ ����
class CRandomWalkDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CRandomWalkDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RANDOMWALK_DIALOG };

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
	CDC *m_pDC;
	CBitmap m_bitMain;
	CBitmap m_bitBack;
	CBitmap m_bitWalker;
	CDC m_mainDC;
	CDC m_backDC;
	CDC m_walkerDC;
	int m_aWalk[MAXCNT][MAXCNT];
	BOOL m_bGameStart;
	CRect m_mainRect;
	int m_nX;
	int m_nY;
	int m_nXsize;
	int m_nYsize;
	int m_nVisitCount;
//	BOOL m_bCheckVisit;
	int m_nXcnt;
	int m_nYcnt;
	int m_nMoveCnt;
	int m_nTime;
	int m_nSpeed;
	CString m_strVisit;
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	BOOL m_bCheckVisit;
	afx_msg void OnClickedButtonStart();
	afx_msg void OnClickedButtonStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedCheckVisit();
	void InitialData();
	void DrawRectAll();
	void DrawRect(int nX, int nY);
	void Walking();
	void DisplayAll();
	void DrawPicture(int nX, int nY);
	void DrawWalker(int nX, int nY);
	afx_msg void OnClickedButtonExit();
};

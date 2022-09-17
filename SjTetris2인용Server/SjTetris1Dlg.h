
// SjTetris1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "SjClientSocket.h"
#include "SjServerSocket.h"
#include "afxcoll.h"

#define COL_CNT 10
#define ROW_CNT 20
#define START_X 10
#define START_Y 10
#define BLOCK_SIZE 32
#define DATA_SIZE 201
#define STATE_INIT 0
#define STATE_LISTEN 1
#define STATE_CONNECT 2
#define STATE_GAME_START 3
#define STATE_GAME_DIE 4

// CSjTetris1Dlg ��ȭ ����
class CSjTetris1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjTetris1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJTETRIS1_DIALOG };

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
	CBitmap m_bmBlock;
	CBitmap m_bmBack;
	CDC m_BackDC;
	CDC m_BlockDC;
	CDC* m_pDC;
	char m_Table[ROW_CNT][COL_CNT];
	CRect m_nextRect;
	CRect m_mainRect;
	BOOL m_bStart;
	int m_nPattern;
	int m_nBitType;
	int m_nRot;
	int m_nX;
	int m_nY;
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	void DrawScr();
	void InitialGame();
	void DrawBlock(bool bFlag);
	BOOL BlockDown();
	BOOL IsAround(int nX, int nY);
	void SetTable();
	void RolateBlock(bool bFlag);
	void MoveDown();
	void MoveRight();
	void MoveLeft();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_nScore;
	int m_nNextPattern;
	void NextBlock(bool bFlag);
	CRect m_mainRect2;
	void DrawScr2();
	char m_Table2[ROW_CNT][COL_CNT];
	CSjServerSocket m_Server;
	CSjClientSocket m_Client;
	CObList m_List;
	CButton m_ctrlSVStartBt;
	CButton m_ctrlSVStopBt;
	CButton m_ctrlSendBt;
	//	CButton m_ctrlForcedBt;
	CString m_strIpAddress;
	CEdit m_ctrlIpAddress;
	int m_nPortNo;
	CString m_strName;
	CString m_strSendData;
	CEdit m_ctrlSendData;
	afx_msg void OnClickedServerStartBt();
	afx_msg void OnClickedServerStopBt();
	afx_msg void OnClickedSendBt();
	bool BroadCast(void* pStr);
	afx_msg LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnCloseMsg(WPARAM wParam, LPARAM IParam);
	int m_nState;
	CString m_arrMsg[10];
	void DisplayMsg(CString strMsg);
};

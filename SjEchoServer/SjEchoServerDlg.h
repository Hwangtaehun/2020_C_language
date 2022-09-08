
// SjEchoServerDlg.h : 헤더 파일
//

#pragma once
#include "MyServerSocket.h"
#include "MySocket.h"

// CSjEchoServerDlg 대화 상자
class CSjEchoServerDlg : public CDialogEx
{
// 생성입니다.
public:
	CSjEchoServerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SJECHOSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	int m_nPortNo;
	CEdit m_ctrlMsg;
	CString m_strMsg;
	CMyServerSocket m_Server;
	CMySocket m_Client;
	afx_msg void OnClickedStartBt();
	afx_msg void OnClickedStopBt();
	afx_msg LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
};

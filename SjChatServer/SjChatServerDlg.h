
// SjChatServerDlg.h : 헤더 파일
//

#pragma once
#include "SjServerSocket.h"
#include "SjClientSocket.h"
#include "afxcoll.h"
#include "afxwin.h"
#define DATA_SIZE 100

// CSjChatServerDlg 대화 상자
class CSjChatServerDlg : public CDialogEx
{
// 생성입니다.
public:
	CSjChatServerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SJCHATSERVER_DIALOG };

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
	CSjServerSocket m_Server;
	CSjClientSocket m_Client;
	CObList m_List;
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	CButton m_ctrlSendBt;
	CButton m_ctrlForcedBt;
	CListBox m_ctrlUserList;
	CString m_strUserList;
	CString m_strIpAddress;
	CEdit m_ctrlIpAddress;
	int m_nPortNo;
	CString m_strName;
	CString m_strSendData;
	CEdit m_ctrlSendData;
	CString m_strReceiveData;
	CEdit m_ctrlReceiveData;
	afx_msg void OnClickedStartBt();
	afx_msg void OnClickedStopBt();
	afx_msg void OnClickedSendBt();
	afx_msg void OnClickedForcedExitBt();
	afx_msg LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	bool BroadCast(void * pStr);
	afx_msg LRESULT OnCloseMsg(WPARAM wParam, LPARAM IParam);
	void UserList(CString strUser, char nFlag);
};

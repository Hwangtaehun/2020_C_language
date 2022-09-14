
// SjChatClientDlg.h : 헤더 파일
//

#pragma once
#include "SjClientSocket.h"
#define DATA_SIZE 100

// CSjChatClientDlg 대화 상자
class CSjChatClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CSjChatClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SJCHATCLIENT_DIALOG };

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
	CSjClientSocket m_Socket;
	CButton m_ctrlConnectBt;
	CButton m_ctrlDisConnectBt;
	CButton m_ctrlSendBt;
	CEdit m_ctrlIpAddress;
	CString m_strIpAddress;
	int m_nPortNo;
	CString m_strSendData;
	CEdit m_ctrlSendData;
	CEdit m_ctrlReceiveData;
	CString m_strReceiveData;
	CEdit m_ctrlName;
	CString m_strName;
	CListBox m_ctrlUserList;
	afx_msg void OnClickedDisconnectBt();
	afx_msg void OnClickedConnectBt();
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClickedSendBt();
	void UserList(CString strUser, char nFlag);
	bool m_bConnect;
};

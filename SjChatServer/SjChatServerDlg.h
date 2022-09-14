
// SjChatServerDlg.h : ��� ����
//

#pragma once
#include "SjServerSocket.h"
#include "SjClientSocket.h"
#include "afxcoll.h"
#include "afxwin.h"
#define DATA_SIZE 100

// CSjChatServerDlg ��ȭ ����
class CSjChatServerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjChatServerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJCHATSERVER_DIALOG };

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

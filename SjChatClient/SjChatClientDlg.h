
// SjChatClientDlg.h : ��� ����
//

#pragma once
#include "SjClientSocket.h"
#define DATA_SIZE 100

// CSjChatClientDlg ��ȭ ����
class CSjChatClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjChatClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJCHATCLIENT_DIALOG };

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

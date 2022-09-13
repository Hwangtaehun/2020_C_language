
// SjEchoServerMulti2Dlg.h : ��� ����
//

#pragma once
#include "SjClientSocket.h"
#include "SjServerSocket.h"
#include "afxwin.h"

// CSjEchoServerMulti2Dlg ��ȭ ����
class CSjEchoServerMulti2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjEchoServerMulti2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJECHOSERVERMULTI2_DIALOG };

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
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	int m_nPortNo;
	CString m_strMsg;
	CEdit m_ctrlMsg;
	CSjServerSocket m_Server;
	CSjClientSocket *m_pClient;
	int m_nCnt;
	afx_msg void OnClickedStartBt();
	afx_msg void OnClickedStopBt();
	afx_msg LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnCloseMsg(WPARAM wParam, LPARAM IParam);
};

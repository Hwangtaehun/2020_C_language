
// SjChatServer.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjChatServerApp:
// �� Ŭ������ ������ ���ؼ��� SjChatServer.cpp�� �����Ͻʽÿ�.
//

class CSjChatServerApp : public CWinApp
{
public:
	CSjChatServerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjChatServerApp theApp;
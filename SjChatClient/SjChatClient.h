
// SjChatClient.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjChatClientApp:
// �� Ŭ������ ������ ���ؼ��� SjChatClient.cpp�� �����Ͻʽÿ�.
//

class CSjChatClientApp : public CWinApp
{
public:
	CSjChatClientApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjChatClientApp theApp;
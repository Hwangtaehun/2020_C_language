
// SjEchoServerMulti2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjEchoServerMulti2App:
// �� Ŭ������ ������ ���ؼ��� SjEchoServerMulti2.cpp�� �����Ͻʽÿ�.
//

class CSjEchoServerMulti2App : public CWinApp
{
public:
	CSjEchoServerMulti2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjEchoServerMulti2App theApp;
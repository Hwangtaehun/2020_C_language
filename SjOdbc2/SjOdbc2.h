
// SjOdbc2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjOdbc2App:
// �� Ŭ������ ������ ���ؼ��� SjOdbc2.cpp�� �����Ͻʽÿ�.
//

class CSjOdbc2App : public CWinApp
{
public:
	CSjOdbc2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjOdbc2App theApp;
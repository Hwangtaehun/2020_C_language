
// SjTetris1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjTetris1App:
// �� Ŭ������ ������ ���ؼ��� SjTetris1.cpp�� �����Ͻʽÿ�.
//

class CSjTetris1App : public CWinApp
{
public:
	CSjTetris1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjTetris1App theApp;
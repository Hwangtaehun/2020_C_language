
// SjThread2.h : SjThread2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjThread2App:
// �� Ŭ������ ������ ���ؼ��� SjThread2.cpp�� �����Ͻʽÿ�.
//

class CSjThread2App : public CWinAppEx
{
public:
	CSjThread2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjThread2App theApp;

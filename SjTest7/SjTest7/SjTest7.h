
// SjTest7.h : SjTest7 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjTest7App:
// �� Ŭ������ ������ ���ؼ��� SjTest7.cpp�� �����Ͻʽÿ�.
//

class CSjTest7App : public CWinAppEx
{
public:
	CSjTest7App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjTest7App theApp;

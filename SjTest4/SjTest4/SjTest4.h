
// SjTest4.h : SjTest4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjTest4App:
// �� Ŭ������ ������ ���ؼ��� SjTest4.cpp�� �����Ͻʽÿ�.
//

class CSjTest4App : public CWinAppEx
{
public:
	CSjTest4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjTest4App theApp;

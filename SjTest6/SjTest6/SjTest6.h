
// SjTest6.h : SjTest6 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjTest6App:
// �� Ŭ������ ������ ���ؼ��� SjTest6.cpp�� �����Ͻʽÿ�.
//

class CSjTest6App : public CWinAppEx
{
public:
	CSjTest6App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjTest6App theApp;

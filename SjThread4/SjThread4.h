
// SjThread4.h : SjThread4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjThread4App:
// �� Ŭ������ ������ ���ؼ��� SjThread4.cpp�� �����Ͻʽÿ�.
//

class CSjThread4App : public CWinAppEx
{
public:
	CSjThread4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjThread4App theApp;


// SjBitmap1.h : SjBitmap1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjBitmap1App:
// �� Ŭ������ ������ ���ؼ��� SjBitmap1.cpp�� �����Ͻʽÿ�.
//

class CSjBitmap1App : public CWinAppEx
{
public:
	CSjBitmap1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjBitmap1App theApp;

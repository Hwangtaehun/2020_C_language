
// SjBitmapShow.h : SjBitmapShow ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjBitmapShowApp:
// �� Ŭ������ ������ ���ؼ��� SjBitmapShow.cpp�� �����Ͻʽÿ�.
//

class CSjBitmapShowApp : public CWinAppEx
{
public:
	CSjBitmapShowApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjBitmapShowApp theApp;

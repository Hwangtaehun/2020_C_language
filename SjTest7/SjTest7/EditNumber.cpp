// EditNumber.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "EditNumber.h"


// CEditNumber

IMPLEMENT_DYNAMIC(CEditNumber, CEdit)

CEditNumber::CEditNumber()
{

}

CEditNumber::~CEditNumber()
{
}


BEGIN_MESSAGE_MAP(CEditNumber, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CEditNumber �޽��� ó�����Դϴ�.

void CEditNumber::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if ((nChar >= '0' && nChar <= '9') || nChar == VK_BACK)
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	else
		MessageBeep(1);
}

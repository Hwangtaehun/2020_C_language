#include "stdafx.h"
#include "CEditNumber.h"
BEGIN_MESSAGE_MAP(CEditNumber, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()


void CEditNumber::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if ((nChar >= '0' && nChar <= '9') || nChar == VK_BACK)
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	else
		MessageBeep(1);
}

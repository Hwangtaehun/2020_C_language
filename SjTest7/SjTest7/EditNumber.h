#pragma once


// CEditNumber

class CEditNumber : public CEdit
{
	DECLARE_DYNAMIC(CEditNumber)

public:
	CEditNumber();
	virtual ~CEditNumber();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};



#pragma once


// CSjSplitterView2 ���Դϴ�.

class CSjSplitterView2 : public CView
{
	DECLARE_DYNCREATE(CSjSplitterView2)

protected:
	CSjSplitterView2();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CSjSplitterView2();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
	CSjSplitterDoc* GetDocument() const;
	int m_nSize;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void DrawEllipse(CDC * pDC, CPoint point);
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
};

#ifndef _DEBUG  // SjSplitterView.cpp�� ����� ����
inline CSjSplitterDoc* CSjSplitterView2::GetDocument() const
{
	return reinterpret_cast<CSjSplitterDoc*>(m_pDocument);
}
#endif



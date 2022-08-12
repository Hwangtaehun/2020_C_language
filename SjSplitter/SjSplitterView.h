
// SjSplitterView.h : CSjSplitterView Ŭ������ �������̽�
//

#pragma once


class CSjSplitterView : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjSplitterView();
	DECLARE_DYNCREATE(CSjSplitterView)

// Ư���Դϴ�.
public:
	CSjSplitterDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CSjSplitterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_nSize;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void DrawRect(CDC * pDC, CPoint point);
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
};

#ifndef _DEBUG  // SjSplitterView.cpp�� ����� ����
inline CSjSplitterDoc* CSjSplitterView::GetDocument() const
   { return reinterpret_cast<CSjSplitterDoc*>(m_pDocument); }
#endif


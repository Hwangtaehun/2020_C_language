
// SjTest4View.h : CSjTest4View Ŭ������ �������̽�
//

#pragma once


class CSjTest4View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjTest4View();
	DECLARE_DYNCREATE(CSjTest4View)

// Ư���Դϴ�.
public:
	CSjTest4Doc* GetDocument() const;

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
	virtual ~CSjTest4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // SjTest4View.cpp�� ����� ����
inline CSjTest4Doc* CSjTest4View::GetDocument() const
   { return reinterpret_cast<CSjTest4Doc*>(m_pDocument); }
#endif


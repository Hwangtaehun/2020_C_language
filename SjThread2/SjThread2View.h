
// SjThread2View.h : CSjThread2View Ŭ������ �������̽�
//

#pragma once


class CSjThread2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjThread2View();
	DECLARE_DYNCREATE(CSjThread2View)

// Ư���Դϴ�.
public:
	CSjThread2Doc* GetDocument() const;

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
	virtual ~CSjThread2View();
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
	void OnSuspend();
	void OnResume();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SjThread2View.cpp�� ����� ����
inline CSjThread2Doc* CSjThread2View::GetDocument() const
   { return reinterpret_cast<CSjThread2Doc*>(m_pDocument); }
#endif


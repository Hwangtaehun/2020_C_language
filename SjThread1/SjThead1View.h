
// SjThead1View.h : CSjThead1View Ŭ������ �������̽�
//

#pragma once


class CSjThead1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjThead1View();
	DECLARE_DYNCREATE(CSjThead1View)

// Ư���Դϴ�.
public:
	CSjThead1Doc* GetDocument() const;

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
	virtual ~CSjThead1View();
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
	DWORD TestThread1(LPVOID IParam);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void OnSuspend();
	void OnResume();
};

#ifndef _DEBUG  // SjThead1View.cpp�� ����� ����
inline CSjThead1Doc* CSjThead1View::GetDocument() const
   { return reinterpret_cast<CSjThead1Doc*>(m_pDocument); }
#endif


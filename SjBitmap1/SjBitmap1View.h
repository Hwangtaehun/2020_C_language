
// SjBitmap1View.h : CSjBitmap1View Ŭ������ �������̽�
//

#pragma once


class CSjBitmap1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjBitmap1View();
	DECLARE_DYNCREATE(CSjBitmap1View)

// Ư���Դϴ�.
public:
	CSjBitmap1Doc* GetDocument() const;

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
	virtual ~CSjBitmap1View();
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
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CDC m_memDC;
	CBitmap m_bitMap;
	CBitmap m_bitMask;
	CBitmap m_bitBack;
	int m_nX;
	int m_nY;
	int m_xPos;
	int m_yPos;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // SjBitmap1View.cpp�� ����� ����
inline CSjBitmap1Doc* CSjBitmap1View::GetDocument() const
   { return reinterpret_cast<CSjBitmap1Doc*>(m_pDocument); }
#endif


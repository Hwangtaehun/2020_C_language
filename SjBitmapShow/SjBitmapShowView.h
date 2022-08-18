
// SjBitmapShowView.h : CSjBitmapShowView Ŭ������ �������̽�
//

#pragma once
#define BMP_COUNT 12
#define BMP_WIDTH 1024
#define BMP_HEIGHT 680

class CSjBitmapShowView : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjBitmapShowView();
	DECLARE_DYNCREATE(CSjBitmapShowView)

// Ư���Դϴ�.
public:
	CSjBitmapShowDoc* GetDocument() const;

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
	virtual ~CSjBitmapShowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CBitmap m_Bitmap;
	CDC m_memDC;
	int m_nBitmap;
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnDestroy();
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Vertical1(CDC * pDC);
	void Vertical2(CDC * pDC);
	void Vertical3(CDC * pDC);
	void Horizontal1(CDC * pDC);
	void Horizontal2(CDC * pDC);
	void Horizontal3(CDC * pDC);
	void In(CDC * pDC);
	void Out(CDC * pDC);
	void Snail(CDC * pDC);
	void Random(CDC * pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // SjBitmapShowView.cpp�� ����� ����
inline CSjBitmapShowDoc* CSjBitmapShowView::GetDocument() const
   { return reinterpret_cast<CSjBitmapShowDoc*>(m_pDocument); }
#endif


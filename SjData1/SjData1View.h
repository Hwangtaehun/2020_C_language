
// SjData1View.h : CSjData1View Ŭ������ �������̽�
//

#pragma once


class CSjData1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjData1View();
	DECLARE_DYNCREATE(CSjData1View)

// Ư���Դϴ�.
public:
	CSjData1Doc* GetDocument() const;

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
	virtual ~CSjData1View();
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
	void DrawRect(CDC * pDC, CPoint point, int nSize);
	afx_msg void OnPenWidth1();
	afx_msg void OnPenWidth2();
	afx_msg void OnPenWidth3();
	afx_msg void OnPenRed();
	afx_msg void OnPenGreen();
	afx_msg void OnPenBlue();
	afx_msg void OnBrushRed();
	afx_msg void OnBrushGreen();
	afx_msg void OnBrushBlue();
	afx_msg void OnPenCustom();
	afx_msg void OnBrushCustom();
};

#ifndef _DEBUG  // SjData1View.cpp�� ����� ����
inline CSjData1Doc* CSjData1View::GetDocument() const
   { return reinterpret_cast<CSjData1Doc*>(m_pDocument); }
#endif



// SjThread4View.h : CSjThread4View Ŭ������ �������̽�
//

#pragma once


class CSjThread4View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjThread4View();
	DECLARE_DYNCREATE(CSjThread4View)

// Ư���Դϴ�.
public:
	CSjThread4Doc* GetDocument() const;

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
	virtual ~CSjThread4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCriticalSection1();
	afx_msg void OnCriticalSection2();
	afx_msg void OnCriticalSection3();
	afx_msg void OnEvent1();
	afx_msg void OnEvent2();
	afx_msg void OnPulseEvent();
	afx_msg void OnResetevent();
	afx_msg void OnSetEvent();
};

#ifndef _DEBUG  // SjThread4View.cpp�� ����� ����
inline CSjThread4Doc* CSjThread4View::GetDocument() const
   { return reinterpret_cast<CSjThread4Doc*>(m_pDocument); }
#endif


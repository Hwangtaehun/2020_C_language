
// SjTest7View.h : CSjTest7View Ŭ������ �������̽�
//

#pragma once


class CSjTest7View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjTest7View();
	DECLARE_DYNCREATE(CSjTest7View)

// Ư���Դϴ�.
public:
	CSjTest7Doc* GetDocument() const;

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
	virtual ~CSjTest7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDlg1();
	afx_msg void OnDlg2();
	afx_msg void OnControl();
	afx_msg void OnList();
	afx_msg void OnCalculator1();
	afx_msg void OnCalculator2();
	afx_msg void OnConvert();
	afx_msg void OnInput();
};

#ifndef _DEBUG  // SjTest7View.cpp�� ����� ����
inline CSjTest7Doc* CSjTest7View::GetDocument() const
   { return reinterpret_cast<CSjTest7Doc*>(m_pDocument); }
#endif


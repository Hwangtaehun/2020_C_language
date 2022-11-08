
// SjOdbc3View.h : CSjOdbc3View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "ATLComTime.h"
#include "Student.h"
#include "ZipCode.h"
#include "ZipDlg.h"


class CSjOdbc3View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CSjOdbc3View();
	DECLARE_DYNCREATE(CSjOdbc3View)

public:
	enum{ IDD = IDD_SJODBC3_FORM };

// Ư���Դϴ�.
public:
	CSjOdbc3Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CSjOdbc3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_ctrlDeleteBt;
	CButton m_ctrlAddBt;
	CButton m_ctrlAddCancel;
	CButton m_ctrlModifyBt;
	CButton m_ctrlNewRecordBt;
	CButton m_ctrlZipBt;
	CListCtrl m_ctrlList;
	CString m_strName;
	CString m_strCode;
	CString m_strRegNumber;
	CString m_strEmail;
	CString m_strAddress;
	CString m_strLastAddress;
	CString m_strCellPhone;
	CString m_strHomePhone;
	CString m_strZipCode;
	COleDateTime m_BirthDay;
	CStudent *m_pStuSet;
	CZipCode *m_pZipSet;
	bool m_bAdd;
	void DisplayList();
	void MoveData(bool bCheck);
	afx_msg void OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	void MoveList();
	afx_msg void OnClickedNewrecordBt();
	afx_msg void OnClickedAddBt();
	afx_msg void OnClickedAddcancelBt();
	afx_msg void OnClickedModifyBt();
	afx_msg void OnClickedDeleteBt();
	afx_msg void OnClickedZipBt();
};

#ifndef _DEBUG  // SjOdbc3View.cpp�� ����� ����
inline CSjOdbc3Doc* CSjOdbc3View::GetDocument() const
   { return reinterpret_cast<CSjOdbc3Doc*>(m_pDocument); }
#endif


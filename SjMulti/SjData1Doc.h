
// SjData1Doc.h : CSjData1Doc Ŭ������ �������̽�
//


#pragma once
#include "data.h"

//struct DATA
//{
//	CPoint m_Point;
//	int m_nSize;
//	int m_nWidth;
//	COLORREF m_penColor;
//	COLORREF m_burshColor;
//
//	void LoadSave(CArchive &ar)
//	{
//		if (ar.IsStoring())
//		{
//			ar << m_Point;
//			ar << m_nSize;
//			ar << m_nWidth;
//			ar << m_penColor;
//			ar << m_burshColor;
//		}
//		else
//		{
//			ar >> m_Point;
//			ar >> m_nSize;
//			ar >> m_nWidth;
//			ar >> m_penColor;
//			ar >> m_burshColor;
//		}
//	}
//};

class CSjData1Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CSjData1Doc();
	DECLARE_DYNCREATE(CSjData1Doc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CSjData1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	int m_nCnt;
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	/*CPoint m_aPoint[30];
	int m_aSize[30];
	int m_aWidth[30];
	COLORREF m_aPenColor[30];
	COLORREF m_aBurshColor[30];*/
	//DATA m_bData[30];
	//CData m_bData[30];
	//CObList m_List;
	//CTypedPtrList <CObList, CData*> m_List;
	CList<CData, CData&> m_List;
};

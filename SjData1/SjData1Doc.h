
// SjData1Doc.h : CSjData1Doc Ŭ������ �������̽�
//


#pragma once


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
	CPoint m_aPoint[30];
	int m_aSize[30];
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	int m_aWidth[30];
	COLORREF m_aPenColor[30];
	COLORREF m_aBurshColor[30];
};

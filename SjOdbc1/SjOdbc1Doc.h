
// SjOdbc1Doc.h : CSjOdbc1Doc Ŭ������ �������̽�
//


#pragma once
#include "SjOdbc1Set.h"


class CSjOdbc1Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CSjOdbc1Doc();
	DECLARE_DYNCREATE(CSjOdbc1Doc)

// Ư���Դϴ�.
public:
	CSjOdbc1Set m_SjOdbc1Set;

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
	virtual ~CSjOdbc1Doc();
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
};

// ZipCode.h : CZipCode�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2022�� 11�� 8�� ȭ����, ���� 3:41

class CZipCode : public CRecordset
{
public:
	CZipCode(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CZipCode)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
// ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	CStringW	m_ZIPCODE;	//�����ȣ
	CStringW	m_SIDO;	//�õ��̸�
	CStringW	m_GUGUN;	//�����̸�
	CStringW	m_DONG;	//���̸�
	CStringW	m_RI;	//���̸�
	CStringW	m_BLDG;	//�˹�/����Ʈ�̸�
	CStringW	m_ST_BUNJI;	//���۹���
	CStringW	m_ED_BUNJI;	//����������
	CStringW	m_SEQ;	//Primarykey

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};



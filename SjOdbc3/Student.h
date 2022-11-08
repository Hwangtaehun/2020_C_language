// Student.h : CStudent�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2022�� 11�� 8�� ȭ����, ���� 3:39

class CStudent : public CRecordset
{
public:
	CStudent(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudent)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
// ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	CStringW	m_strCode;	//��ȣ(4), Primary Key
	CStringW	m_strName;	//�̸� (10)
	CStringW	m_strZipCode;	//�����ȣ (7)
	CStringW	m_strLastAddress;	//�������ּ� �ּ� (30)
	CStringW	m_strCellPhoneNumber;	//�޴���ȭ��ȣ(15)
	CStringW	m_strHomePhoneNumber;	//����ȭ��ȣ(15)
	//CTime	m_dBirthDay;	//����(Data)
	COleDateTime	m_dBirthDay;	//����(Data)
	CStringW	m_strEmail;	//Email(30)
	CStringW	m_RegistrationNumber;	//�ֹι�ȣ(14)

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



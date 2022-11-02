// Score.h : CScore�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2022�� 11�� 2�� ������, ���� 3:59

class CScore : public CRecordset
{
public:
	CScore(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CScore)

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
	long	m_nKor;	//�������� Long
	long	m_nMat;	//�������� Long
	long	m_nEng;	//�������� Long
	long	m_nTotal;	//���� Long
	double	m_dAverage;	//��� Double
	long	m_nRank;	//���� Long

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



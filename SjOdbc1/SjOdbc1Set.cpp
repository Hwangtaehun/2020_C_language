
// SjOdbc1Set.cpp : CSjOdbc1Set Ŭ������ ����
//

#include "stdafx.h"
#include "SjOdbc1.h"
#include "SjOdbc1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjOdbc1Set ����

// �ڵ� ���� ��ġ 2022�� 11�� 2�� ������, ���� 3:21

IMPLEMENT_DYNAMIC(CSjOdbc1Set, CRecordset)

CSjOdbc1Set::CSjOdbc1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_strCode = L"";
	m_strName = L"";
	m_nKor = 0;
	m_nMat = 0;
	m_nEng = 0;
	m_nTotal = 0;
	m_dAverage = 0.0;
	m_nRank = 0;
	m_nFields = 8;
	m_nDefaultType = dynaset;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CSjOdbc1Set::GetDefaultConnect()
{
	return _T("DSN=SjTestDB;DBQ=C:\\\xc218\xac15\xc0dd\\\xd669\xd0dc\xd6c8\\Database\\SjTestDB.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CSjOdbc1Set::GetDefaultSQL()
{
	return _T("[Score]");
}

void CSjOdbc1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Text(pFX, _T("[strCode]"), m_strCode);
	RFX_Text(pFX, _T("[strName]"), m_strName);
	RFX_Long(pFX, _T("[nKor]"), m_nKor);
	RFX_Long(pFX, _T("[nMat]"), m_nMat);
	RFX_Long(pFX, _T("[nEng]"), m_nEng);
	RFX_Long(pFX, _T("[nTotal]"), m_nTotal);
	RFX_Double(pFX, _T("[dAverage]"), m_dAverage);
	RFX_Long(pFX, _T("[nRank]"), m_nRank);

}
/////////////////////////////////////////////////////////////////////////////
// CSjOdbc1Set ����

#ifdef _DEBUG
void CSjOdbc1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSjOdbc1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


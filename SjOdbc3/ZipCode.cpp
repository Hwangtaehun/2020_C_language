// ZipCode.h : CZipCode Ŭ������ �����Դϴ�.



// CZipCode �����Դϴ�.

// �ڵ� ���� ��ġ 2022�� 11�� 8�� ȭ����, ���� 3:41

#include "stdafx.h"
#include "ZipCode.h"
IMPLEMENT_DYNAMIC(CZipCode, CRecordset)

CZipCode::CZipCode(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ZIPCODE = L"";
	m_SIDO = L"";
	m_GUGUN = L"";
	m_DONG = L"";
	m_RI = L"";
	m_BLDG = L"";
	m_ST_BUNJI = L"";
	m_ED_BUNJI = L"";
	m_SEQ = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
// #error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CZipCode::GetDefaultConnect()
{
	return _T("DSN=SjTestDB;DBQ=C:\\\xc218\xac15\xc0dd\\\xd669\xd0dc\xd6c8\\Database\\SjTestDB.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CZipCode::GetDefaultSQL()
{
	return _T("[ZipCode]");
}

void CZipCode::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Text(pFX, _T("[ZIPCODE]"), m_ZIPCODE);
	RFX_Text(pFX, _T("[SIDO]"), m_SIDO);
	RFX_Text(pFX, _T("[GUGUN]"), m_GUGUN);
	RFX_Text(pFX, _T("[DONG]"), m_DONG);
	RFX_Text(pFX, _T("[RI]"), m_RI);
	RFX_Text(pFX, _T("[BLDG]"), m_BLDG);
	RFX_Text(pFX, _T("[ST_BUNJI]"), m_ST_BUNJI);
	RFX_Text(pFX, _T("[ED_BUNJI]"), m_ED_BUNJI);
	RFX_Text(pFX, _T("[SEQ]"), m_SEQ);

}
/////////////////////////////////////////////////////////////////////////////
// CZipCode ����

#ifdef _DEBUG
void CZipCode::AssertValid() const
{
	CRecordset::AssertValid();
}

void CZipCode::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG



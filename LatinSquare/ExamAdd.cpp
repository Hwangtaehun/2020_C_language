// ExamAdd.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LatinSquare.h"
#include "ExamAdd.h"
#include "afxdialogex.h"


// CExamAdd 대화 상자입니다.

IMPLEMENT_DYNAMIC(CExamAdd, CDialogEx)

CExamAdd::CExamAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExamAdd::IDD, pParent)
	, m_strCheck1(_T(""))
	, m_strCheck2(_T(""))
	, m_strCheck3(_T(""))
	, m_strCheck4(_T(""))
	, m_strCheck5(_T(""))
	, m_strCheck6(_T(""))
	, m_strCheck7(_T(""))
	, m_strCheck8(_T(""))
	, m_strCheck9(_T(""))
	, m_strExam1(_T(""))
	, m_strExam2(_T(""))
	, m_strExam3(_T(""))
	, m_strExam4(_T(""))
	, m_strExam5(_T(""))
	, m_strExam6(_T(""))
	, m_strExam7(_T(""))
	, m_strExam8(_T(""))
	, m_strExam9(_T(""))
{

}

CExamAdd::~CExamAdd()
{
}

void CExamAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CHECK1, m_strCheck1);
	DDV_MaxChars(pDX, m_strCheck1, 9);
	DDX_Text(pDX, IDC_CHECK2, m_strCheck2);
	DDV_MaxChars(pDX, m_strCheck2, 9);
	DDX_Text(pDX, IDC_CHECK3, m_strCheck3);
	DDV_MaxChars(pDX, m_strCheck3, 9);
	DDX_Text(pDX, IDC_CHECK4, m_strCheck4);
	DDV_MaxChars(pDX, m_strCheck4, 9);
	DDX_Text(pDX, IDC_CHECK5, m_strCheck5);
	DDV_MaxChars(pDX, m_strCheck5, 9);
	DDX_Text(pDX, IDC_CHECK_6, m_strCheck6);
	DDV_MaxChars(pDX, m_strCheck6, 9);
	DDX_Text(pDX, IDC_CHECK7, m_strCheck7);
	DDV_MaxChars(pDX, m_strCheck7, 9);
	DDX_Text(pDX, IDC_CHECK8, m_strCheck8);
	DDV_MaxChars(pDX, m_strCheck8, 9);
	DDX_Text(pDX, IDC_CHECK9, m_strCheck9);
	DDV_MaxChars(pDX, m_strCheck9, 9);
	DDX_Text(pDX, IDC_EXAM1, m_strExam1);
	DDV_MaxChars(pDX, m_strExam1, 9);
	DDX_Text(pDX, IDC_EXAM2, m_strExam2);
	DDV_MaxChars(pDX, m_strExam2, 9);
	DDX_Text(pDX, IDC_EXAM3, m_strExam3);
	DDV_MaxChars(pDX, m_strExam3, 9);
	DDX_Text(pDX, IDC_EXAM4, m_strExam4);
	DDV_MaxChars(pDX, m_strExam4, 9);
	DDX_Text(pDX, IDC_EXAM5, m_strExam5);
	DDV_MaxChars(pDX, m_strExam5, 9);
	DDX_Text(pDX, IDC_EXAM6, m_strExam6);
	DDV_MaxChars(pDX, m_strExam6, 9);
	DDX_Text(pDX, IDC_EXAM7, m_strExam7);
	DDV_MaxChars(pDX, m_strExam7, 9);
	DDX_Text(pDX, IDC_EXAM8, m_strExam8);
	DDV_MaxChars(pDX, m_strExam8, 9);
	DDX_Text(pDX, IDC_EXAM9, m_strExam9);
	DDV_MaxChars(pDX, m_strExam9, 9);
}


BEGIN_MESSAGE_MAP(CExamAdd, CDialogEx)
END_MESSAGE_MAP()


// CExamAdd 메시지 처리기입니다.

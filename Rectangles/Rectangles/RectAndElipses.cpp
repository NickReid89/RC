// RectAndElipses.cpp : implementation file
//

#include "stdafx.h"
#include "Rectangles.h"
#include "RectAndElipses.h"
#include "afxdialogex.h"


// CRectAndElipses dialog

IMPLEMENT_DYNAMIC(CRectAndElipses, CDialogEx)

CRectAndElipses::CRectAndElipses(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRectAndElipses::IDD, pParent)
	, m_txtNumRect(10)
	, m_txtNumOfEclipses(10)
{
	CRectAndElipses::SettextBoxes10();
}

CRectAndElipses::~CRectAndElipses()
{
}

void CRectAndElipses::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_txtNumOfRec, m_txtNumRect);
	DDV_MinMaxUInt(pDX, m_txtNumRect, 0, 10);
	DDX_Text(pDX, IDC_txtNumOfElipses, m_txtNumOfEclipses);
	DDV_MinMaxUInt(pDX, m_txtNumOfEclipses, 0, 10);
}


BEGIN_MESSAGE_MAP(CRectAndElipses, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRectAndElipses::OnBnClickedOk)
END_MESSAGE_MAP()


// CRectAndElipses message handlers


void CRectAndElipses::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	//if(m_NumOfRect > 10){
	//	MessageBox("Error, can only be between zero and ten.");
	//}
	CDialogEx::OnOK();	
}


// Sets text boxes to 10
void CRectAndElipses::SettextBoxes10(void)
{
	//m_numOfElipses = 10;
	//m_NumOfRect = 10;
}

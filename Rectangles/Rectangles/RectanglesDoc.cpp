
// RectanglesDoc.cpp : implementation of the CRectanglesDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Rectangles.h"
#endif

#include "RectanglesDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "RectAndElipses.h"

// CRectanglesDoc

IMPLEMENT_DYNCREATE(CRectanglesDoc, CDocument)

BEGIN_MESSAGE_MAP(CRectanglesDoc, CDocument)
END_MESSAGE_MAP()


// CRectanglesDoc construction/destruction

CRectanglesDoc::CRectanglesDoc()
	: m_NumberOfClicks(0)
	//, m_ClickedHereRight(0)
	, m_NumOfRightClicks(0)
	, m_maxRect(0)
	, m_maxElipse(0)
{
	// TODO: add one-time construction code here

}

CRectanglesDoc::~CRectanglesDoc()
{
}

BOOL CRectanglesDoc::OnNewDocument()
{
	
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	CRectAndElipses dlg;	

	if(dlg.DoModal() == IDOK){
		 
		  m_maxElipse = dlg.m_txtNumOfEclipses;
		  m_maxRect = dlg.m_txtNumRect;
	}
	else{
		return FALSE;
	}
		
	m_NumberOfClicks = 0;
	m_NumOfRightClicks = 0;
	
	return TRUE;
}




// CRectanglesDoc serialization

void CRectanglesDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CRectanglesDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CRectanglesDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CRectanglesDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CRectanglesDoc diagnostics

#ifdef _DEBUG
void CRectanglesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRectanglesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRectanglesDoc commands


// RectanglesDoc.h : interface of the CRectanglesDoc class
//


#pragma once
#include "atltypes.h"


class CRectanglesDoc : public CDocument
{
protected: // create from serialization only
	CRectanglesDoc();
	DECLARE_DYNCREATE(CRectanglesDoc)	

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CRectanglesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CPoint m_ClickedHere[10];
	unsigned int m_NumberOfClicks;
	// Right mouse clicks(elipses)
	//CPoint m_ClickedHereRight;
	// Number of times user right clicked
	unsigned int m_NumOfRightClicks;
	// Holds maximum amount of rectangles
	CPoint m_ClickedHereRight[10];
	// Holds maximum amount of rectangles
	UINT m_maxRect;
	// Holds max amount of Elipses
	UINT m_maxElipse;
};

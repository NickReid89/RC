
// RectanglesView.h : interface of the CRectanglesView class
//

#pragma once


class CRectanglesView : public CView
{
protected: // create from serialization only
	CRectanglesView();
	DECLARE_DYNCREATE(CRectanglesView)

// Attributes
public:
	CRectanglesDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CRectanglesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	// Switches shape layer
	bool switchLayer;
	// Flips the layer
	bool m_flipChecked;
};

#ifndef _DEBUG  // debug version in RectanglesView.cpp
inline CRectanglesDoc* CRectanglesView::GetDocument() const
   { return reinterpret_cast<CRectanglesDoc*>(m_pDocument); }
#endif


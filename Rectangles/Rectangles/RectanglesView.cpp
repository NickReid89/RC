
// RectanglesView.cpp : implementation of the CRectanglesView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Rectangles.h"
#endif

#include "RectanglesDoc.h"
#include "RectanglesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRectanglesView

IMPLEMENT_DYNCREATE(CRectanglesView, CView)

BEGIN_MESSAGE_MAP(CRectanglesView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRectanglesView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CRectanglesView construction/destruction

CRectanglesView::CRectanglesView()
	: switchLayer(false)
	, m_flipChecked(false)
{
	// TODO: add construction code here

}

CRectanglesView::~CRectanglesView()
{
}

BOOL CRectanglesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRectanglesView drawing

void CRectanglesView::OnDraw(CDC* pDC)
{
	
	CRectanglesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	UINT i, x, y;
	// Loop to draw a Rectangle for each point stored in our array...
	if(switchLayer == true){

		for (i=0; i < pDoc->m_NumberOfClicks; i++ ) {
				y = pDoc->m_ClickedHere[i].y;
				x = pDoc->m_ClickedHere[i].x;
				pDoc->m_ClickedHere[i].y += 10;
				pDoc->m_ClickedHere[i].x += 10;
				pDC->Rectangle(x,y, x+80, y+20);
		}// end of for loop

		for (i=0; i < pDoc->m_NumOfRightClicks;i++) {
				y = pDoc->m_ClickedHereRight[i].y;
				x = pDoc->m_ClickedHereRight[i].x;
				pDoc->m_ClickedHereRight[i].y -= 10;
				pDoc->m_ClickedHereRight[i].x -= 10;
				pDC->Ellipse(x,y,x+30,y+60);
		}// end of for loop

	}//end of if statement.

	else{
		
		for (i=0; i < pDoc->m_NumOfRightClicks;i++) {

				y = pDoc->m_ClickedHereRight[i].y;
				x = pDoc->m_ClickedHereRight[i].x;
				pDoc->m_ClickedHereRight[i].y -= 10;
				pDoc->m_ClickedHereRight[i].x -= 10;
				pDC->Ellipse(x,y,x+30,y+60);
 
		}// end of for loop
		for (i=0; i < pDoc->m_NumberOfClicks; i++ ) {

				y = pDoc->m_ClickedHere[i].y;
				x = pDoc->m_ClickedHere[i].x;
				pDoc->m_ClickedHere[i].y += 10;
				pDoc->m_ClickedHere[i].x += 10;
				pDC->Rectangle(x,y, x+80, y+20);
		}// end of for loop
	}// end of else

}// end of method


// CRectanglesView printing


void CRectanglesView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRectanglesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRectanglesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRectanglesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CRectanglesView::OnRButtonUp(UINT nFlags , CPoint point)
{
	
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
}

void CRectanglesView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRectanglesView diagnostics

#ifdef _DEBUG
void CRectanglesView::AssertValid() const
{
	CView::AssertValid();
}

void CRectanglesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRectanglesDoc* CRectanglesView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRectanglesDoc)));
	return (CRectanglesDoc*)m_pDocument;
}
#endif //_DEBUG


// CRectanglesView message handlers


void CRectanglesView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Declare and initialize a pointer to the Document class.
		CRectanglesDoc* pDoc = GetDocument();
	// Have I clicked 10 times? The array can’t store any more points
		if (pDoc->m_NumberOfClicks >= pDoc->m_maxRect) {
			MessageBox("Cannot store any more points");
			return;
		}
	// Storing the “point” passed through the parameter list into our array.
		pDoc->m_ClickedHere[pDoc->m_NumberOfClicks] = point;
	// Incrementing the array index
		pDoc->m_NumberOfClicks++;
	// Telling Windows that something has happened on the screen,
	// and that it should “redraw” the screen.
		pDoc->SetModifiedFlag();
		Invalidate();
	// You’re done with your custom code, pass control to base class method
	CView::OnLButtonDown(nFlags, point);
}


void CRectanglesView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// Declare and initialize a pointer to the Document class.
		CRectanglesDoc* pDoc = GetDocument();
	// Have I clicked 10 times? The array can’t store any more points
		if (pDoc->m_NumOfRightClicks >= pDoc->m_maxElipse) {
			MessageBox("Cannot store any more points");
			return;
		}
	// Storing the “point” passed through the parameter list into our array.
		pDoc->m_ClickedHereRight[pDoc->m_NumOfRightClicks] = point;
	// Incrementing the array index
		pDoc->m_NumOfRightClicks++;
	// Telling Windows that something has happened on the screen,
	// and that it should “redraw” the screen.
		pDoc->SetModifiedFlag();
		Invalidate();
	// You’re done with your custom code, pass control to base class method
	CView::OnLButtonDown(nFlags, point);

	//CView::OnRButtonDown(nFlags, point);
}


void CRectanglesView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CRectanglesDoc* pDoc = GetDocument(); 
	// TODO: Add your message handler code here and/or call default
	if(switchLayer == true){
		switchLayer = false;
	}
	else{
		switchLayer = true;
	}	

	//m_flipChecked = true;

	pDoc->SetModifiedFlag();
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

#pragma once


// CRectAndElipses dialog

class CRectAndElipses : public CDialogEx
{
	DECLARE_DYNAMIC(CRectAndElipses)

public:
	CRectAndElipses(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRectAndElipses();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// number of rectangles user wants.
	//unsigned int m_NumOfRect;
	// Number of Elipses user wants.
	//unsigned int m_numOfElipses;
	afx_msg void OnBnClickedOk();
	// Sets text boxes to 10
	void SettextBoxes10(void);
	// number of rectangles you can create
	UINT m_txtNumRect;
	// Number of eclipses you can create
	UINT m_txtNumOfEclipses;
};
// number of rectangles you can create

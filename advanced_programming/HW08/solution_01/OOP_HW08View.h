
// OOP_HW08View.h : interface of the COOPHW08View class
//

#pragma once


class COOPHW08View : public CScrollView
{
protected: // create from serialization only
	COOPHW08View() noexcept;
	DECLARE_DYNCREATE(COOPHW08View)

// Attributes
public:
	COOPHW08Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~COOPHW08View();
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
	afx_msg void OnPlotGridon();
	afx_msg void OnPlotLog();
	afx_msg void OnPlotCos();
	afx_msg void OnPlotSin();
	afx_msg void OnPlotPolynomial();

private:
	bool drawGrid = false;
	bool drawSin = false;
	bool drawCos = false;
	bool drawLog = false;
	bool drawPolynomial = false;
	bool holdOn = false;
	bool redCheck = false;
	bool blueCheck = false;
	bool greenCheck = false;
public:
	afx_msg void OnPlotHoldon();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
};

#ifndef _DEBUG  // debug version in OOP_HW08View.cpp
inline COOPHW08Doc* COOPHW08View::GetDocument() const
   { return reinterpret_cast<COOPHW08Doc*>(m_pDocument); }
#endif


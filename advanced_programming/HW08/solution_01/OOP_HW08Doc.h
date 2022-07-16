
// OOP_HW08Doc.h : interface of the COOPHW08Doc class
//


#pragma once


class COOPHW08Doc : public CDocument
{
protected: // create from serialization only
	COOPHW08Doc() noexcept;
	DECLARE_DYNCREATE(COOPHW08Doc)

// Attributes
public:
	CImage img;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~COOPHW08Doc();
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
	afx_msg void OnPlotLog();
	afx_msg void OnPlotSin();
	afx_msg void OnPlotGridon();
};

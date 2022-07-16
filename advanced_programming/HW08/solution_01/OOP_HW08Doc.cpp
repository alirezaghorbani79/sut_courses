
// OOP_HW08Doc.cpp : implementation of the COOPHW08Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OOP_HW08.h"
#endif

#include "OOP_HW08Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COOPHW08Doc

IMPLEMENT_DYNCREATE(COOPHW08Doc, CDocument)

BEGIN_MESSAGE_MAP(COOPHW08Doc, CDocument)
	ON_COMMAND(ID_PLOT_LOG, &COOPHW08Doc::OnPlotLog)
	ON_COMMAND(ID_PLOT_SIN, &COOPHW08Doc::OnPlotSin)
	ON_COMMAND(ID_PLOT_GRIDON, &COOPHW08Doc::OnPlotGridon)
END_MESSAGE_MAP()


// COOPHW08Doc construction/destruction

COOPHW08Doc::COOPHW08Doc() noexcept
{
	// TODO: add one-time construction code here

}

COOPHW08Doc::~COOPHW08Doc()
{
}

BOOL COOPHW08Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

BOOL COOPHW08Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!img.IsNull())
		img.Detach();
	img.Load(lpszPathName);
	UpdateAllViews(0);

	return 0;
}


// COOPHW08Doc serialization

void COOPHW08Doc::Serialize(CArchive& ar)
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
void COOPHW08Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void COOPHW08Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void COOPHW08Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// COOPHW08Doc diagnostics

#ifdef _DEBUG
void COOPHW08Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void COOPHW08Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COOPHW08Doc commands


void COOPHW08Doc::OnPlotLog()
{
	AfxMessageBox(L"HI");
}


void COOPHW08Doc::OnPlotSin()
{

}

void COOPHW08Doc::OnPlotGridon()
{
	UpdateAllViews(0);
}


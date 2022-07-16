
	// OOP_HW08View.cpp : implementation of the COOPHW08View class
	//

	#include "pch.h"
	#include "framework.h"
	#include <math.h>
	// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
	// and search filter handlers and allows sharing of document code with that project.
	#ifndef SHARED_HANDLERS
	#include "OOP_HW08.h"
	#endif

	#include "OOP_HW08Doc.h"
	#include "OOP_HW08View.h"

	#ifdef _DEBUG
	#define new DEBUG_NEW
	#endif


	// COOPHW08View

	IMPLEMENT_DYNCREATE(COOPHW08View, CScrollView)

	BEGIN_MESSAGE_MAP(COOPHW08View, CScrollView)
		// Standard printing commands
		ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COOPHW08View::OnFilePrintPreview)
		ON_WM_CONTEXTMENU()
		ON_WM_RBUTTONUP()
		ON_COMMAND(ID_PLOT_GRIDON, &COOPHW08View::OnPlotGridon)
		ON_COMMAND(ID_PLOT_LOG, &COOPHW08View::OnPlotLog)
		ON_COMMAND(ID_PLOT_COS, &COOPHW08View::OnPlotCos)
		ON_COMMAND(ID_PLOT_SIN, &COOPHW08View::OnPlotSin)
		ON_COMMAND(ID_PLOT_POLYNOMIAL, &COOPHW08View::OnPlotPolynomial)
		ON_COMMAND(ID_PLOT_HOLDON, &COOPHW08View::OnPlotHoldon)
		ON_COMMAND(ID_COLOR_RED, &COOPHW08View::OnColorRed)
		ON_COMMAND(ID_COLOR_GREEN, &COOPHW08View::OnColorGreen)
		ON_COMMAND(ID_COLOR_BLUE, &COOPHW08View::OnColorBlue)
	END_MESSAGE_MAP()

	// COOPHW08View construction/destruction

	COOPHW08View::COOPHW08View() noexcept
	{
		// TODO: add construction code here

	}

	COOPHW08View::~COOPHW08View()
	{
	}

	BOOL COOPHW08View::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: Modify the Window class or styles here by modifying
		//  the CREATESTRUCT cs

		return CScrollView::PreCreateWindow(cs);
	}

	// COOPHW08View drawing

	void COOPHW08View::OnDraw(CDC* pDC)
	{
		COOPHW08Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

	
		CImage img2;
		CRect rc;
		GetClientRect(&rc);
		img2.Create(rc.Width(), rc.Height(), 24);

		CFont f;
		f.CreatePointFont(200, L"Times New Roman");
		pDC->SelectObject(&f);
		pDC->SetTextColor(RGB(127, 127, 127));
		pDC->TextOutW(img2.GetWidth() / 2 - 100, img2.GetHeight() - 50, L"Simple Plot App");


		if (drawGrid)
		{
			CBrush br(RGB(255, 255, 210));
			pDC->FillRect(&rc, &br);
			const int cell = 20;
			int rows = rc.Height() / cell;
			int cols = rc.Width() / cell;

			CPen pen(PS_DOT, 1, RGB(150, 150, 250));
			pDC->SelectObject(&pen);

			for (size_t y = 1; y < rows; y++)
			{
				pDC->MoveTo(0, y * cell);
				pDC->LineTo(rc.Width(), y * cell);
			}
			for (size_t x = 1; x < cols; x++)
			{
				pDC->MoveTo(x * cell, 0);
				pDC->LineTo(x * cell, rc.Height());
			}
		}
		if (drawSin)
		{
			if (redCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -sin(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (blueCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 0, 255));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -sin(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (greenCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 255, 0));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -sin(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
		}
		if (drawCos)
		{
			if (redCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -cos(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (blueCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 0, 255));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -cos(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (greenCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 255, 0));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -cos(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}

		}
		if (drawLog)
		{
			if (redCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -log10(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (blueCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 0, 255));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -log10(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (greenCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 255, 0));
				pDC->SelectObject(&pen);
				int xoff = 0;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);
				for (int x = 0; x < rc.Width(); x++)
				{
					double newX = x * 3.14 / 100;
					double y = -log10(newX) * 200;
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
		}
		if (drawPolynomial)
		{
			int minVal = -3;
			int maxVal = 3;
			int randomNum[5];

			for (int i = 0; i < 5; i++)
				randomNum[i] = minVal + rand() % (maxVal - minVal + 1);

			if (redCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
				pDC->SelectObject(&pen);

				int xoff = rc.Width() / 2;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);

				for (int x = 0; x < rc.Width(); x++)
				{
					double new_x = x * 3.14 / 180;
					double y = randomNum[0] + randomNum[1] * pow(new_x, 4) + randomNum[2] * pow(new_x, 3) + randomNum[3] * pow(new_x, 2) + randomNum[4] * pow(new_x, 1);
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (blueCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 0, 255));
				pDC->SelectObject(&pen);

				int xoff = rc.Width() / 2;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);

				for (int x = 0; x < rc.Width(); x++)
				{
					double new_x = x * 3.14 / 180;
					double y = randomNum[0] + randomNum[1] * pow(new_x, 4) + randomNum[2] * pow(new_x, 3) + randomNum[3] * pow(new_x, 2) + randomNum[4] * pow(new_x, 1);
					pDC->LineTo(x + xoff, y + yoff);
				}
			}
			if (greenCheck)
			{
				CPen pen(PS_SOLID, 2, RGB(0, 255, 0));
				pDC->SelectObject(&pen);

				int xoff = rc.Width() / 2;
				int yoff = rc.Height() / 2;
				pDC->MoveTo(xoff, yoff);

				for (int x = 0; x < rc.Width(); x++)
				{
					double new_x = x * 3.14 / 180;
					double y = randomNum[0] + randomNum[1] * pow(new_x, 4) + randomNum[2] * pow(new_x, 3) + randomNum[3] * pow(new_x, 2) + randomNum[4] * pow(new_x, 1);
					pDC->LineTo(x + xoff, y + yoff);
				}
			}

		}
		/*pDoc->img.Draw(pDC->GetSafeHdc(), 0, 0);

		CSize sz;
		// TODO: calculate the total size of this view
		sz.cx = pDoc->img.GetWidth();
		sz.cy = pDoc->img.GetHeight();
		SetScrollSizes(MM_TEXT, sz);*/

	}

	void COOPHW08View::OnInitialUpdate()
	{
		CScrollView::OnInitialUpdate();

		CSize sizeTotal;
		// TODO: calculate the total size of this view
		sizeTotal.cx = sizeTotal.cy = 200;
		SetScrollSizes(MM_TEXT, sizeTotal);
	}


	// COOPHW08View printing


	void COOPHW08View::OnFilePrintPreview()
	{
	#ifndef SHARED_HANDLERS
		AFXPrintPreview(this);
	#endif
	}

	BOOL COOPHW08View::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// default preparation
		return DoPreparePrinting(pInfo);
	}

	void COOPHW08View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: add extra initialization before printing
	}

	void COOPHW08View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: add cleanup after printing
	}

	void COOPHW08View::OnRButtonUp(UINT /* nFlags */, CPoint point)
	{
		ClientToScreen(&point);
		OnContextMenu(this, point);
	}

	void COOPHW08View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
	{
	#ifndef SHARED_HANDLERS
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	#endif
	}


	// COOPHW08View diagnostics

	#ifdef _DEBUG
	void COOPHW08View::AssertValid() const
	{
		CScrollView::AssertValid();
	}

	void COOPHW08View::Dump(CDumpContext& dc) const
	{
		CScrollView::Dump(dc);
	}

	COOPHW08Doc* COOPHW08View::GetDocument() const // non-debug version is inline
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COOPHW08Doc)));
		return (COOPHW08Doc*)m_pDocument;
	}
	#endif //_DEBUG


	// COOPHW08View message handlers


	void COOPHW08View::OnPlotGridon()
	{
		if (holdOn == false)
		{
			drawGrid = true;
			drawSin = false;
			drawCos = false;
			drawLog = false;
			drawPolynomial = false;
		}
		else
		{
			drawGrid = true;
			drawSin = true;
			drawCos = true;
			drawLog = true;
			drawPolynomial = true;
		}
		Invalidate();
		UpdateWindow();
	}

	void COOPHW08View::OnPlotSin()
	{
		if (holdOn == false)
		{
			drawSin = true;
			drawGrid = false;
			drawCos = false;
			drawLog = false;
			drawPolynomial = false;
		}
		else
		{
			drawGrid = true;
			drawSin = true;
			drawCos = true;
			drawLog = true;
			drawPolynomial = true;
		}
		Invalidate();
		UpdateWindow();
	}

	void COOPHW08View::OnPlotCos()
	{
		if (holdOn == false)
		{
			drawCos = true;
			drawSin = false;
			drawGrid = false;
			drawLog = false;
			drawPolynomial = false;
		}
		else
		{
			drawGrid = true;
			drawSin = true;
			drawCos = true;
			drawLog = true;
			drawPolynomial = true;
		}
		Invalidate();
		UpdateWindow();
	}


	void COOPHW08View::OnPlotLog()
	{
		if (holdOn == false)
		{
			drawLog = true;
			drawCos = false;
			drawSin = false;
			drawGrid = false;
			drawPolynomial = false;
		}
		else
		{
			drawGrid = true;
			drawSin = true;
			drawCos = true;
			drawLog = true;
			drawPolynomial = true;
		}
		Invalidate();
		UpdateWindow();
	}


	void COOPHW08View::OnPlotPolynomial()
	{
		if (holdOn == false)
		{
			drawPolynomial = true;
			drawLog = false;
			drawCos = false;
			drawSin = false;
			drawGrid = false;
		}
		else
		{
			drawGrid = true;
			drawSin = true;
			drawCos = true;
			drawLog = true;
			drawPolynomial = true;
		}
		Invalidate();
		UpdateWindow();
	}


	void COOPHW08View::OnPlotHoldon()
	{
		drawPolynomial = true;
		drawGrid = true;
		drawSin = true;
		drawCos = true;
		drawLog = true;
	}


	void COOPHW08View::OnColorRed()
	{
		redCheck = true;
		blueCheck = false;
		greenCheck = false;
		Invalidate();
		UpdateWindow();
	}


	void COOPHW08View::OnColorGreen()
	{
		greenCheck = true;
		redCheck = false;
		blueCheck = false;
		Invalidate();
		UpdateWindow();
	}


	void COOPHW08View::OnColorBlue()
	{
		blueCheck = true;
		greenCheck = false;
		redCheck = false;
		Invalidate();
		UpdateWindow();
	}
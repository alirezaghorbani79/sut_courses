
// OOP_HW06Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OOP_HW06.h"
#include "OOP_HW06Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COOPHW06Dlg dialog



COOPHW06Dlg::COOPHW06Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOP_HW06_DIALOG, pParent)
	, X3(0)
	, x2(0)
	, x(0)
	, c(0)
	, firstPoint(0)
	, endPoint(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COOPHW06Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRAPH, graph);
	DDX_Text(pDX, IDC_EDIT_X3, X3);
	DDX_Text(pDX, IDC_EDIT_X2, x2);
	DDX_Text(pDX, IDC_EDIT_X, x);
	DDX_Text(pDX, IDC_EDIT_C, c);
	DDX_Text(pDX, IDC_EDIT_FROM, firstPoint);
	DDX_Text(pDX, IDC_EDIT_TO, endPoint);
}

BEGIN_MESSAGE_MAP(COOPHW06Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_X3, &COOPHW06Dlg::OnEnChangeEditX3)
	ON_BN_CLICKED(IDC_BTN_PLOT, &COOPHW06Dlg::OnBnClickedBtnPlot)
	ON_EN_CHANGE(IDC_EDIT_X2, &COOPHW06Dlg::OnEnChangeEditX2)
	ON_EN_CHANGE(IDC_EDIT_X, &COOPHW06Dlg::OnEnChangeEditX)
	ON_EN_CHANGE(IDC_EDIT_C, &COOPHW06Dlg::OnEnChangeEditC)
	ON_EN_CHANGE(IDC_EDIT_FROM, &COOPHW06Dlg::OnEnChangeEditFrom)
	ON_EN_CHANGE(IDC_EDIT_TO, &COOPHW06Dlg::OnEnChangeEditTo)
END_MESSAGE_MAP()


// COOPHW06Dlg message handlers

BOOL COOPHW06Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COOPHW06Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COOPHW06Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDC* pDC = graph.GetDC();

		CRect rc;
		graph.GetClientRect(&rc);

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

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COOPHW06Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COOPHW06Dlg::OnEnChangeEditX3()
{
	UpdateData(true);
}

void COOPHW06Dlg::OnEnChangeEditX2()
{
	UpdateData(true);
}

void COOPHW06Dlg::OnEnChangeEditX()
{
	UpdateData(true);
}

void COOPHW06Dlg::OnEnChangeEditC()
{
	UpdateData(true);
}

void COOPHW06Dlg::OnEnChangeEditFrom()
{
	UpdateData(true);
}

void COOPHW06Dlg::OnEnChangeEditTo()
{
	UpdateData(true);
}


void COOPHW06Dlg::OnBnClickedBtnPlot()
{
	CDC* pDC = graph.GetDC();
	CRect rc;
	graph.GetClientRect(&rc);

	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(&pen);

	int xoff = rc.Width() / 2;
	int yoff = rc.Height() / 2;
	pDC->MoveTo(firstPoint * 180 / 3.14, endPoint * 180 / 3.14);

	for (int i = firstPoint*180/3.14; i < endPoint*180/3.14; i++)
	{
		double new_x = i * 3.14 / 180;
		double y = -15 * (X3 * pow(new_x, 3) + x2 * pow(new_x, 2) + x * pow(new_x, 1) + c);
		pDC->LineTo(i + xoff, y + yoff);
	}

	CFont font;
	font.CreatePointFont(200, L"Times New Roman");
	pDC->SelectObject(&font);
	pDC->SetBkMode(TRANSPARENT);
	CString str, xLabel[30];
	str.Format(_T("%.1fx^3+%.1fx^2+%.1fx+%.1f"), X3, x2, x, c);

	for (int i = -10; i < 10; i++)
	{
		xLabel[i+10].Format(_T("%d"), i);
		pDC->TextOutW((rc.Width() / 2) + i * 180 / 3.14, (rc.Height() / 2) + 200, xLabel[i+10]);
	}

	pDC->TextOutW(10, 20, str);
	
}
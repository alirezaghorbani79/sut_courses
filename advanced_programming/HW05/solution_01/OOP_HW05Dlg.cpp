
// OOP_HW05Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OOP_HW05.h"
#include "OOP_HW05Dlg.h"
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


// COOPHW05Dlg dialog



COOPHW05Dlg::COOPHW05Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOP_HW05_DIALOG, pParent)
	, numA(0), numB(0), numC(0), numX(0), numY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COOPHW05Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A, numA);
	DDX_Text(pDX, IDC_EDIT_B, numB);
	DDX_Text(pDX, IDC_EDIT_C, numC);
	DDX_Text(pDX, IDC_EDIT_X, numX);
	DDX_Text(pDX, IDC_EDIT_Y, numY);
}

BEGIN_MESSAGE_MAP(COOPHW05Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_OUTPUT, &COOPHW05Dlg::OnEnChangeEditOutput)
	ON_EN_CHANGE(IDC_EDIT_INPUT, &COOPHW05Dlg::OnEnChangeEditInput)
	ON_BN_CLICKED(IDC_BUTTON_UPCONVERT, &COOPHW05Dlg::OnBnClickedButtonUpconvert)
	ON_EN_CHANGE(IDC_EDIT_A, &COOPHW05Dlg::OnEnChangeEditA)
	ON_EN_CHANGE(IDC_EDIT_B, &COOPHW05Dlg::OnEnChangeEditB)
	ON_EN_CHANGE(IDC_EDIT_C, &COOPHW05Dlg::OnEnChangeEditC)
	ON_EN_CHANGE(IDC_EDIT_X, &COOPHW05Dlg::OnEnChangeEditX)
	ON_EN_CHANGE(IDC_EDIT_Y, &COOPHW05Dlg::OnEnChangeEditY)
END_MESSAGE_MAP()


// COOPHW05Dlg message handlers

BOOL COOPHW05Dlg::OnInitDialog()
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

void COOPHW05Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COOPHW05Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COOPHW05Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void COOPHW05Dlg::OnBnClickedButtonUpconvert()
{
	CString inStr, outStr;
	GetDlgItemText(IDC_EDIT_INPUT, inStr);
	outStr = inStr.MakeUpper();
	SetDlgItemText(IDC_EDIT_OUTPUT, outStr);
}
void COOPHW05Dlg::OnEnChangeEditInput()
{

}

void COOPHW05Dlg::OnEnChangeEditOutput()
{

}
//============================================// part2 //============================================//
void COOPHW05Dlg::OnEnChangeEditA()
{
	UpdateData(true);
	numY = numA * numX * numX + numB * numX + numC;
	UpdateData(false);
}

void COOPHW05Dlg::OnEnChangeEditB()
{
	UpdateData(true);
	numY = numA * numX * numX + numB * numX + numC;
	UpdateData(false);
}

void COOPHW05Dlg::OnEnChangeEditC()
{
	UpdateData(true);
	numY = numA * numX * numX + numB * numX + numC;
	UpdateData(false);
}

void COOPHW05Dlg::OnEnChangeEditX()
{
	UpdateData(true);
	numY = numA * numX * numX + numB * numX + numC;
	UpdateData(false);
}

void COOPHW05Dlg::OnEnChangeEditY()
{

}
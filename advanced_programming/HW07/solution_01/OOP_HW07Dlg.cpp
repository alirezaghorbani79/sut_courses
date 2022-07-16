
// OOP_HW07Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OOP_HW07.h"
#include "OOP_HW07Dlg.h"
#include <algorithm>
#include "afxdialogex.h"
#include <chrono>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std::chrono;

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


// COOPHW07Dlg dialog



COOPHW07Dlg::COOPHW07Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOP_HW07_DIALOG, pParent)
	, blueCheck(false)
	, sliderCheck(false)
	, staticTime(_T(""))
	, LPF3Cheack(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COOPHW07Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BTN_OPENIMG, orgImg);
	//DDX_Control(pDX, IDC_BTN_OPENIMG, copyImg);
	//DDX_Control(pDX, IDC_BTN_REMOVE_BLUE, blueCheck);
	DDX_Control(pDX, IDC_SLIDER, sliderNum);
	//DDX_Slider(pDX, IDC_SLIDER, sliderCheck);
	DDX_Text(pDX, IDC_STATIC_TIME, staticTime);
	//DDX_Control(pDX, IDC_BTN_LPF3, LPF3Cheack);
}

BEGIN_MESSAGE_MAP(COOPHW07Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OPENIMG, &COOPHW07Dlg::OnBnClickedBtnOpenimg)
	ON_BN_CLICKED(IDC_BTN_REMOVE_BLUE, &COOPHW07Dlg::OnBnClickedBtnRemoveBlue)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, &COOPHW07Dlg::OnNMCustomdrawSlider)
	ON_BN_CLICKED(IDC_BTN_REST, &COOPHW07Dlg::OnBnClickedBtnRest)
	ON_BN_CLICKED(IDC_BTN_SAVE, &COOPHW07Dlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LPF3, &COOPHW07Dlg::OnBnClickedBtnLpf3)
END_MESSAGE_MAP()


// COOPHW07Dlg message handlers

BOOL COOPHW07Dlg::OnInitDialog()
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
	sliderNum.SetRange(0, 10);
	sliderNum.SetPos(0);
	sliderNum.UpdateWindow();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COOPHW07Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COOPHW07Dlg::OnPaint()
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
		if (!orgImg.IsNull())
		{
			HDC dc = GetDlgItem(IDC_STATIC_ORGINAL)->GetDC()->GetSafeHdc();
			RECT rc;
			GetDlgItem(IDC_STATIC_ORGINAL)->GetClientRect(&rc);
			copyImg.Draw(dc, rc, Gdiplus::InterpolationMode::InterpolationModeBilinear);

			HDC dcChange = GetDlgItem(IDC_STATIC_CHANGE)->GetDC()->GetSafeHdc();
			RECT rcChange;
			GetDlgItem(IDC_STATIC_CHANGE)->GetClientRect(&rcChange);

			if (blueCheck)
			{
				orgImg.Draw(dcChange, rcChange, Gdiplus::InterpolationMode::InterpolationModeBilinear);
				//blueCheck = false;
			}
			if (sliderCheck)
			{
				orgImg.Draw(dcChange, rcChange, Gdiplus::InterpolationMode::InterpolationModeBilinear);
				//sliderCheck = false;
			}
			if (LPF3Cheack)
			{
				orgImg.Draw(dcChange, rcChange, Gdiplus::InterpolationMode::InterpolationModeBilinear);
				//LPF3Cheack = false;
			}


		}

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COOPHW07Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COOPHW07Dlg::OnBnClickedBtnOpenimg()
{
	//==================== Load image //====================
	CFileDialog dlg(true, L"*.jpg", 0, 6UL, L"jpeg files|*.jpg|png files|*.png|all files|*.*||");
	if (dlg.DoModal() != IDOK)
		return;
	if (!orgImg.IsNull())
	{
		orgImg.Detach();
		copyImg.Detach();
	}
		
	orgImg.Load(dlg.GetPathName());
	copyImg.Load(dlg.GetPathName());

	OnPaint();
}


void COOPHW07Dlg::OnBnClickedBtnRemoveBlue()
{
	auto start = system_clock::now();

	blueCheck = true;
	for (auto y = 0; y < copyImg.GetHeight(); y++)
	{
		unsigned char* p = (unsigned char*)orgImg.GetPixelAddress(0, y);
		for (auto x = 0; x < copyImg.GetWidth(); x++)
		{
			p[0] = 0;
			p += 4;
		}
	}

	duration<double> elapsedSeconds = system_clock::now() - start;
	double elapsedTime = elapsedSeconds.count();
	Invalidate(0);
	staticTime.Format(L"Time:%.4f s", elapsedTime);
	//MessageBox(staticTime);
	SetDlgItemText(IDC_STATIC_TIME, staticTime);

	OnPaint();
}


void COOPHW07Dlg::OnNMCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (sliderNum.GetPos() != 0)
	{
		sliderCheck = true;

		int bright = sliderNum.GetPos();
		for (auto y = 0; y < copyImg.GetHeight(); y++)
		{
			unsigned char* p = (unsigned char*)orgImg.GetPixelAddress(0, y);
			for (auto x = 0; x < copyImg.GetWidth(); x++)
			{
				p[0] = min(p[0] + 10, 255);
				p[1] = min(p[1] + 10, 255);
				p[2] = min(p[2] + 10, 255);

				p += 4;
			}
		}
		OnPaint();
	}
}


void COOPHW07Dlg::OnBnClickedBtnRest()
{
	auto start = system_clock::now();
	orgImg = copyImg;

	duration<double> elapsedSeconds = system_clock::now() - start;
	double elapsedTime = elapsedSeconds.count();
	Invalidate(0);
	staticTime.Format(L"Time:%.4f s", elapsedTime);
	//MessageBox(staticTime);
	SetDlgItemText(IDC_STATIC_TIME, staticTime);

	OnPaint();
}


void COOPHW07Dlg::OnBnClickedBtnSave()
{
	CFileDialog dlg(false, L"*.jpg", 0, 6UL, L"jpeg files|*.jpg|png files|*.png|all files|*.*||");
	if (dlg.DoModal() != IDOK)
		return;
	if (!orgImg.IsNull())
	{
		orgImg.Save(dlg.GetPathName());
	}
}


void COOPHW07Dlg::OnBnClickedBtnLpf3()
{
	auto start = system_clock::now();
	LPF3Cheack = true;

	auto h = copyImg.GetHeight();
	auto w = copyImg.GetWidth();

	auto xNew = 0.5 * w;
	auto yNew = 0.5 * h;

	auto xScale = xNew / (w - 1);
	auto yScale = yNew / (h - 1);

	for (auto i = 0; i < xNew - 1; i++)
	{
		unsigned char* p = (unsigned char*)orgImg.GetPixelAddress(0, i);
		for (auto j = 0; j < yNew - 1; j++)
		{
			p[0] += (1 + (i / xScale)) + (1 + (j / yScale));
			p[1] += (1 + (i / xScale)) + (1 + (j / yScale));
			p[2] += (1 + (i / xScale)) + (1 + (j / yScale));

			p += 3;
		}
	}

	duration<double> elapsedSeconds = system_clock::now() - start;
	double elapsedTime = elapsedSeconds.count();
	Invalidate(0);
	staticTime.Format(L"Time:%.4f s", elapsedTime);
	//MessageBox(staticTime);
	SetDlgItemText(IDC_STATIC_TIME, staticTime);

	OnPaint();
}
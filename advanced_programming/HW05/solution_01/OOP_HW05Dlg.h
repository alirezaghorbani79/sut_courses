
// OOP_HW05Dlg.h : header file
//

#pragma once


// COOPHW05Dlg dialog
class COOPHW05Dlg : public CDialogEx
{
// Construction
public:
	COOPHW05Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOP_HW05_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditOutput();
	afx_msg void OnEnChangeEditInput();
	afx_msg void OnBnClickedButtonUpconvert();
	float numA, numB, numC, numX, numY;
	afx_msg void OnEnChangeEditA();
	afx_msg void OnEnChangeEditB();
	afx_msg void OnEnChangeEditC();
	afx_msg void OnEnChangeEditX();
	afx_msg void OnEnChangeEditY();
};

// OOP_HW06Dlg.h : header file
//



#pragma once


// COOPHW06Dlg dialog
class COOPHW06Dlg : public CDialogEx
{
// Construction
public:
	COOPHW06Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOP_HW06_DIALOG };
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
	CStatic graph;
	float X3;
	float x2;
	float x;
	float c;
	afx_msg void OnEnChangeEditX3();
	afx_msg void OnBnClickedBtnPlot();
	afx_msg void OnEnChangeEditX2();
	afx_msg void OnEnChangeEditX();
	afx_msg void OnEnChangeEditC();
	afx_msg void OnEnChangeEditFrom();
	afx_msg void OnEnChangeEditTo();
	float firstPoint;
	float endPoint;
};

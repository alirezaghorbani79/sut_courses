
// OOP_HW07Dlg.h : header file
//

#pragma once


// COOPHW07Dlg dialog
class COOPHW07Dlg : public CDialogEx
{
// Construction
public:
	COOPHW07Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOP_HW07_DIALOG };
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
	afx_msg void OnBnClickedBtnOpenimg();
	CImage orgImg;
	CImage copyImg;
	afx_msg void OnBnClickedBtnRemoveBlue();
	bool blueCheck = false;
	afx_msg void OnNMCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl sliderNum;
	bool sliderCheck = false;
	afx_msg void OnBnClickedBtnRest();
	afx_msg void OnBnClickedBtnSave();
	CString staticTime;
	afx_msg void OnBnClickedBtnLpf3();
	bool LPF3Cheack = false;
};

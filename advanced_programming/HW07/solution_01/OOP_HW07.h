
// OOP_HW07.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// COOPHW07App:
// See OOP_HW07.cpp for the implementation of this class
//

class COOPHW07App : public CWinApp
{
public:
	COOPHW07App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern COOPHW07App theApp;

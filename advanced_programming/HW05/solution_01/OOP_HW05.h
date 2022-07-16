
// OOP_HW05.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// COOPHW05App:
// See OOP_HW05.cpp for the implementation of this class
//

class COOPHW05App : public CWinApp
{
public:
	COOPHW05App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern COOPHW05App theApp;

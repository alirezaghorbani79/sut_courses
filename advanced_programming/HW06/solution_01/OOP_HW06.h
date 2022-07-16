
// OOP_HW06.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// COOPHW06App:
// See OOP_HW06.cpp for the implementation of this class
//

class COOPHW06App : public CWinApp
{
public:
	COOPHW06App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern COOPHW06App theApp;

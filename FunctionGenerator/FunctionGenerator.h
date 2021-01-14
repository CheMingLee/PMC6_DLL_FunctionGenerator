// FunctionGenerator.h : FunctionGenerator DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號
#include "ctrlcard.h"
#include "Dev_PMC6.h"
#include "guid_def.h"
#include "pci.h"

#define DllExport __declspec(dllexport)
#define SETLED 0

// CFunctionGeneratorApp
// 這個類別的實作請參閱 FunctionGenerator.cpp
//

class CFunctionGeneratorApp : public CWinApp
{
public:
	CFunctionGeneratorApp();

// 覆寫
public:
	virtual BOOL InitInstance();
	DllExport void InitialDev();
	DllExport void SetLED(unsigned int u32LEDdata);
	DllExport void CloseDev();

	DECLARE_MESSAGE_MAP()
};

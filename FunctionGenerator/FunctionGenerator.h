// FunctionGenerator.h : FunctionGenerator DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�
#include "ctrlcard.h"
#include "Dev_PMC6.h"
#include "guid_def.h"
#include "pci.h"

#define DllExport __declspec(dllexport)
#define SETLED 0

// CFunctionGeneratorApp
// �o�����O����@�аѾ\ FunctionGenerator.cpp
//

class CFunctionGeneratorApp : public CWinApp
{
public:
	CFunctionGeneratorApp();

// �мg
public:
	virtual BOOL InitInstance();
	DllExport void InitialDev();
	DllExport void SetLED(unsigned int u32LEDdata);
	DllExport void CloseDev();

	DECLARE_MESSAGE_MAP()
};

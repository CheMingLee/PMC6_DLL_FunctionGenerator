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


// CMD structure
typedef struct {
	unsigned int m_iChannel;
	float m_fFreq;
	float m_fDuty;
	float m_fDelay;
}CMD_PWM;

typedef struct {
	int m_iFunction;
	float m_fFreq;
	float m_fAmp;
	float m_fRatio;
	float m_fDelay;
}CMD_ANALOG;

// DLL export
#define DllExport __declspec(dllexport)

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
	DllExport void CloseDev();
	DllExport unsigned int SetLED(unsigned int u32LEDdata);
	DllExport void SetPWM_JF8(CMD_PWM CmdData);
	DllExport void SetPWM_JF7(CMD_PWM CmdData);
	DllExport void SetAnalog_1(CMD_ANALOG CmdData);
	DllExport void SetAnalog_2(CMD_ANALOG CmdData);
	
	DECLARE_MESSAGE_MAP()
};

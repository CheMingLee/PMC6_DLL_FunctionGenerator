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


// CMD structure
typedef struct {
	unsigned int m_iChannel;
	int m_iflag;
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
	DllExport void CloseDev();
	DllExport unsigned int SetLED(unsigned int u32LEDdata);
	DllExport void SetPWM(CMD_PWM CmdData, int iCH);
	DllExport void SetAnalog(CMD_ANALOG CmdData, int iCH);
	DllExport void SetStart();
	DllExport void SetStop();
	DllExport unsigned int GetLED();
	DllExport void GetParamPWM(CMD_PWM *CmdData, int iCH);
	DllExport void GetParamAnalog(CMD_ANALOG *CmdData, int iCH);
	DllExport void GetRunTime(double *pdRunTime);
	
	DECLARE_MESSAGE_MAP()
};

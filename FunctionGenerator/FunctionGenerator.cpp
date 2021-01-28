// FunctionGenerator.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "FunctionGenerator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果這個 DLL 是動態地對 MFC DLL 連結，
//		那麼從這個 DLL 匯出的任何會呼叫
//		MFC 內部的函式，都必須在函式一開頭加上 AFX_MANAGE_STATE
//		巨集。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此處為正常函式主體
//		}
//
//		這個巨集一定要出現在每一個
//		函式中，才能夠呼叫 MFC 的內部。這意味著
//		它必須是函式內的第一個陳述式
//		，甚至必須在任何物件變數宣告前面
//		，因為它們的建構函式可能會產生對 MFC
//		DLL 內部的呼叫。
//
//		請參閱 MFC 技術提示 33 和 58 中的
//		詳細資料。
//

// CFunctionGeneratorApp

BEGIN_MESSAGE_MAP(CFunctionGeneratorApp, CWinApp)
END_MESSAGE_MAP()


// CFunctionGeneratorApp 建構

CFunctionGeneratorApp::CFunctionGeneratorApp()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 僅有的一個 CFunctionGeneratorApp 物件

CFunctionGeneratorApp theApp;


// CFunctionGeneratorApp 初始設定

BOOL CFunctionGeneratorApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


// FunctionGenerator DLL

DllExport void InitialDev()
{
	g_DevPMC6.Dev_Open();
}

DllExport void CloseDev()
{
	g_DevPMC6.Dev_Close();
}

DllExport unsigned int SetLED(unsigned int u32LEDdata)
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	unsigned int u32LEDstatus;
	
	usCmd = CMD_SETLED;
	pData = (char *)&u32LEDdata;
	usSize = sizeof(u32LEDdata);

	BOOL bRet = PCI_Write_Datas(usCmd, pData, usSize);
	if (bRet)
	{
		memcpy(&u32LEDstatus, g_DevPMC6.m_ReadBuffer, sizeof(u32LEDstatus));
	}
	else
	{
		AfxMessageBox(_T("ERROR: PCI failed to read data."));
		u32LEDstatus = 999;
	}

	return u32LEDstatus;
}

DllExport void SetPWM(CMD_PWM CmdData, int iCH)
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	
	usCmd = CMD_SETDIGITAL;
	pData = (char *)&CmdData;
	usSize = sizeof(CmdData);

	PCI_Write_Datas(usCmd, pData, usSize);
}

DllExport void SetAnalog(CMD_ANALOG CmdData, int iCH)
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	
	usCmd = CMD_SETANALOG;
	pData = (char *)&CmdData;
	usSize = sizeof(CmdData);

	PCI_Write_Datas(usCmd, pData, usSize);
}

DllExport void SetStart()
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;

	int iData = 1;
	
	usCmd = CMD_SETSTART;
	pData = (char *)&iData;
	usSize = sizeof(iData);

	PCI_Write_Datas(usCmd, pData, usSize);
}

DllExport void SetStop()
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;

	int iData = 1;
	
	usCmd = CMD_SETSTOP;
	pData = (char *)&iData;
	usSize = sizeof(iData);

	PCI_Write_Datas(usCmd, pData, usSize);
}

DllExport unsigned int GetLED()
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	unsigned int u32LEDstatus;
	int iData;

	iData = 1;
	
	usCmd = CMD_GETLED;
	pData = (char *)&iData;
	usSize = sizeof(iData);

	BOOL bRet = PCI_Write_Datas(usCmd, pData, usSize);
	if (bRet)
	{
		memcpy(&u32LEDstatus, g_DevPMC6.m_ReadBuffer, sizeof(u32LEDstatus));
	}
	else
	{
		AfxMessageBox(_T("ERROR: PCI failed to read data."));
		u32LEDstatus = 999;
	}

	return u32LEDstatus;
}

DllExport void GetParamPWM(CMD_PWM *CmdData, int iCH)
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	
	usCmd = CMD_GETDIGITAL;
	pData = (char *)&iCH;
	usSize = sizeof(iCH);

	BOOL bRet = PCI_Write_Datas(usCmd, pData, usSize);
	if (bRet)
	{
		memcpy(CmdData, g_DevPMC6.m_ReadBuffer, sizeof(CMD_PWM));
	}
}

DllExport void GetParamAnalog(CMD_ANALOG *CmdData, int iCH)
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	
	usCmd = CMD_GETANALOG;
	pData = (char *)&iCH;
	usSize = sizeof(iCH);

	BOOL bRet = PCI_Write_Datas(usCmd, pData, usSize);
	if (bRet)
	{
		memcpy(CmdData, g_DevPMC6.m_ReadBuffer, sizeof(CMD_ANALOG));
	}
}

DllExport void GetRunTime(double *pdRunTime)
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	int iData;

	iData = 1;
	
	usCmd = CMD_GETRUNTIME;
	pData = (char *)&iData;
	usSize = sizeof(iData);

	BOOL bRet = PCI_Write_Datas(usCmd, pData, usSize);
	if (bRet)
	{
		memcpy(pdRunTime, g_DevPMC6.m_ReadBuffer, sizeof(double));
	}
	else
	{
		AfxMessageBox(_T("ERROR: PCI failed to read data."));
	}
}

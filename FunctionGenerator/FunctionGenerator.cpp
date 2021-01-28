// FunctionGenerator.cpp : �w�q DLL ����l�Ʊ`���C
//

#include "stdafx.h"
#include "FunctionGenerator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: �p�G�o�� DLL �O�ʺA�a�� MFC DLL �s���A
//		����q�o�� DLL �ץX������|�I�s
//		MFC �������禡�A�������b�禡�@�}�Y�[�W AFX_MANAGE_STATE
//		�����C
//
//		�Ҧp:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// ���B�����`�禡�D��
//		}
//
//		�o�ӥ����@�w�n�X�{�b�C�@��
//		�禡���A�~����I�s MFC �������C�o�N����
//		�������O�禡�����Ĥ@�ӳ��z��
//		�A�Ʀܥ����b���󪫥��ܼƫŧi�e��
//		�A�]�����̪��غc�禡�i��|���͹� MFC
//		DLL �������I�s�C
//
//		�аѾ\ MFC �޳N���� 33 �M 58 ����
//		�ԲӸ�ơC
//

// CFunctionGeneratorApp

BEGIN_MESSAGE_MAP(CFunctionGeneratorApp, CWinApp)
END_MESSAGE_MAP()


// CFunctionGeneratorApp �غc

CFunctionGeneratorApp::CFunctionGeneratorApp()
{
	// TODO: �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}


// �Ȧ����@�� CFunctionGeneratorApp ����

CFunctionGeneratorApp theApp;


// CFunctionGeneratorApp ��l�]�w

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

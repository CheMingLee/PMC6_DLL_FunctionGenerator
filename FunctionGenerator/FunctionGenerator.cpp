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


DllExport void SetLED(unsigned int u32LEDdata)
{
	unsigned short usCmd;
	char *pData;
	unsigned short usSize;
	
	usCmd = SETLED;
	pData = (char *)&u32LEDdata;
	usSize = sizeof(u32LEDdata);

	PCI_Write_Datas(usCmd, pData, usSize);
}

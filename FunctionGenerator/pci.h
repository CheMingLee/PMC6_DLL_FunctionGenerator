// CMD define
#define CMD_SETLED          0
#define CMD_SETDIGITAL      1
#define CMD_SETANALOG       2
#define CMD_SETSTART        3
#define CMD_SETSTOP         4
#define CMD_GETLED          5
#define CMD_GETDIGITAL      6
#define CMD_GETANALOG       7
#define CMD_GETRUNTIME      8

#ifndef _PCI_
#define _PCI_
BOOL	PCI_Write_Datas(unsigned short usCmd, char *pData, unsigned short usSize);
DWORD	PCI_GetStReg();
BOOL	PCI_SetStReg(WORD bit,WORD On);
#endif

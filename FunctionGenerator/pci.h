// CMD define
#define CMD_SETLED              0
#define CMD_SETOUTPUT           1
#define CMD_SETOUTPUTEX         2
#define CMD_SETANALOG1OUT       3
#define CMD_SETANALOG2OUT       4
#define CMD_GETLED              5
#define CMD_GETDIGITAL_FREQ     6

#ifndef _PCI_
#define _PCI_
BOOL	PCI_Write_Datas(unsigned short usCmd, char *pData, unsigned short usSize);
DWORD	PCI_GetStReg();
BOOL	PCI_SetStReg(WORD bit,WORD On);
#endif

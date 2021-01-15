// CMD define
#define CMD_SETLED 0
#define CMD_SETOUTPUTCH 1
#define CMD_SETOUTPUTEXCH 2
#define CMD_SETANALOG1OUT 3
#define CMD_SETANALOG2OUT 4

#ifndef _PCI_
#define _PCI_
BOOL	PCI_Write_Datas(unsigned short usCmd, char *pData,unsigned short usSize);
DWORD	PCI_GetStReg();
BOOL	PCI_SetStReg(WORD bit,WORD On);
#endif
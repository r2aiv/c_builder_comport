//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <winspool.h>
#include <string.h>
#include <stdio.h>
#pragma hdrstop

#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

DCB dcb;
HANDLE Comport;
bool COMPortOpened=FALSE;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenCOMPortBtnClick(TObject *Sender)
{
char PortName[20];
memset(PortName,0,sizeof(PortName));
strcpy(PortName,(char *)COMPortComboBox->Text.data());

Comport=CreateFile(PortName,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
if(Comport==INVALID_HANDLE_VALUE)
        {
        MessageBox(NULL,"������ �������� �����","OH FUCK!!!",MB_ICONSTOP);
        return;
        }
GetCommState(Comport,&dcb);
dcb.BaudRate=CBR_19200;
dcb.DCBlength=sizeof(dcb);
dcb.Parity=EVENPARITY;
dcb.StopBits=ONESTOPBIT;
SetCommState(Comport,&dcb);
OpenCOMPortBtn->Enabled=FALSE;
CloseCOMPortBtn->Enabled=TRUE;
COMPortOpened=TRUE;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseCOMPortBtnClick(TObject *Sender)
{
CloseHandle(Comport);
OpenCOMPortBtn->Enabled=TRUE;
CloseCOMPortBtn->Enabled=FALSE;
COMPortOpened=FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::COMPortSendBtnClick(TObject *Sender)
{
char UARTBuff[255];
memset(UARTBuff,0,sizeof(UARTBuff));
unsigned long BytesWritten;

if(COMPortOpened==FALSE)
{
        MessageBox(NULL,"���� �� ������!","FUCK ACHTUNG!",MB_ICONSTOP);
        return;
}

strcpy((char *)UARTBuff,(char *)PacketEditBox->Text.data());

WriteFile(Comport,UARTBuff,strlen(UARTBuff),&BytesWritten,NULL);

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExitBtnClick(TObject *Sender)
{
if(COMPortOpened==TRUE)
{
        MessageBox(NULL,"���� �� ������!","ACHTUNG!! UVAGA!!!",MB_ICONSTOP);
        return;
}
Application->Terminate();
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TComboBox *COMPortComboBox;
        TButton *OpenCOMPortBtn;
        TButton *CloseCOMPortBtn;
        TEdit *PacketEditBox;
        TButton *COMPortSendBtn;
        TButton *ExitBtn;
        void __fastcall OpenCOMPortBtnClick(TObject *Sender);
        void __fastcall CloseCOMPortBtnClick(TObject *Sender);
        void __fastcall COMPortSendBtnClick(TObject *Sender);
        void __fastcall ExitBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

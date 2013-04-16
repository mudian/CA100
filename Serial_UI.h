//---------------------------------------------------------------------------

#ifndef Serial_UIH
#define Serial_UIH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "CPort.hpp"
#include "perfgrap.h"
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TListView *lstEvtlog;
	TPanel *Panel2;
	TLabel *Label2;
	TLabel *Label3;
	TMemo *mmIn;
	TButton *btnMmin;
	TButton *btnMmout;
	TPanel *Panel5;
	TLabel *Label5;
	TButton *btnLogclear;
	TButton *btnLogsave;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *close1;
	TPanel *Panel3;
	TLabel *Label1;
	TSpeedButton *btnConnect;
	TComboBox *cbxPort;
	TComboBox *btnBps;
	TPanel *Panel4;
	TMemo *mmOut;
	TPanel *Panel1;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *tabCA100;
	TComboBox *btnGentype;
	TPanel *Panel9;
	TLabel *Label4;
	TComPort *ComPort1;
	TTimer *Timer1;
	TPanel *Panel10;
	TLabel *Label6;
	TCheckBox *chkLF;
	TCheckBox *chkCR;
	TMenuItem *help1;
	TMenuItem *menual1;
	TLabel *Label7;
	TComboBox *btnSourtype;
	TPanel *Panel11;
	TMemo *mmSour;
	TMemo *mmMeas;
	TPanel *Panel12;
	TLabel *status;
	TPanel *Panel13;
	TMemo *mmSetting;
	TButton *btnEnter;
	TTreeView *TreeView1;
	TPanel *Panel14;
	TComboBox *btnSetting;
	TLabel *Label8;
	TPanel *Panel15;
	TButton *btnDown;
	TButton *btnUp;
	TButton *btnClrsour;
	TButton *btnHold;
	TListBox *lstStat;
	TSplitter *Splitter1;
	TScrollBox *ScrollBox1;
	TTimer *Timer2;
	TButton *btnPmsg;
	TButton *btnPca100;
	TPanel *Panel16;
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall btnMminClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall btnLogclearClick(TObject *Sender);
	void __fastcall close1Click(TObject *Sender);
	void __fastcall btnLogsaveClick(TObject *Sender);
	void __fastcall btnMmoutClick(TObject *Sender);
	void __fastcall btnGentypeChange(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall btnSourtypeChange(TObject *Sender);
	void __fastcall btnHoldClick(TObject *Sender);
	void __fastcall btnPca100Click(TObject *Sender);
	void __fastcall btnPmsgClick(TObject *Sender);
private:	// User declarations
	void __fastcall vEventMessage(String msg);
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif

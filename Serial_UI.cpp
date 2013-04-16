//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Serial_UI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma link "perfgrap"
#pragma resource "*.dfm"


TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}  
//---------------------------------------------------------------------------


void __fastcall TfrmMain::vEventMessage(String msg)           //�α� �޼��� ����
{
	String strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
	TListItem * evtLog = lstEvtlog-> Items ->Add();
	evtLog ->Caption = strT;
    evtLog ->SubItems->Add(msg);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnConnectClick(TObject *Sender)    // comport ���� ��ư
{
	if(ComPort1->Connected)
	{                        
		btnConnect->Down = 0;
		btnConnect->Caption ="Disconnect";
		ComPort1->Close();
		Timer1->Enabled = false;
	}
	else 
	{
		try
		{
			btnConnect->Down = 1;              	 //��ư ��� ����
			btnConnect->Caption ="Connect";
			  
			ComPort1->Port = cbxPort->Text;      //��Ʈ ��ȣ, �ӵ� ����, ����
			ComPort1->BaudRate = StrToBaudRate(btnBps->Text);
			ComPort1->Open();
			Timer1->Enabled = ComPort1->Connected;
			Timer2->Enabled = tabCA100->Showing && ComPort1->Connected;

		}catch(...)
		{
			btnConnect->Down = 0;
			btnConnect->Caption ="Disconnect";
			ComPort1->Close();
		}
	}	
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnMminClick(TObject *Sender)      //�޸� �Է� ��ư
{
   
	AnsiString StrMsg1,strT, strIn;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			StrMsg1 = mmIn->Lines->GetText();              	//�޸� ���� �б�
			if(chkCR->Checked)                              //���� ���� ���ϰ� ����
			{
			StrMsg1 = StrMsg1+"\r";
			}if(chkLF->Checked)
			{
			StrMsg1 = StrMsg1+"\n";
			}

			int iRlt = ComPort1->WriteStr(StrMsg1);  		//�޸� ������ ��Ʈ�� ����
			if(iRlt == StrMsg1.Length())//
			{
				vEventMessage("Tx:"+StrMsg1);
				lstEvtlog->Perform(WM_VSCROLL, SB_BOTTOM, 0);//��ũ�ѹ� �� �ϴ����� ������
			}
			else
			{

			}
		}catch(...)
		{
			mmOut->Lines->Clear();                           // ���� ���н� �޼���
			mmOut->Lines->Add("����");
		}
	}else
	{                                                        //���� �ȵǾ�������
		mmOut->Lines->Clear();
		mmOut->Lines->Add("�����ϼ���");
	}	
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer1Timer(TObject *Sender)      //��¸޸� �� �α� �޼��� ��ȯ Ÿ�̸�
{

	AnsiString StrMsg2,strT,strOut;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			int iRx = ComPort1->ReadStr(StrMsg2,256);         //��Ʈ���� �޼��� �о����
			if(StrMsg2.Length() > 0)
			{
				mmOut->Lines->Clear();
				mmOut->Lines->Add(StrMsg2);

				vEventMessage("Rx:"+StrMsg2);
				lstEvtlog->Perform(WM_VSCROLL, SB_BOTTOM, 0);//��ũ�ѹ� �� �ϴ����� ������
			}
		}catch(...)
		{
			mmOut->Lines->Add("����");
		}
	}else
	{
		mmOut->Lines->Add("�����ϼ���");
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnLogclearClick(TObject *Sender)     //�α� Ŭ����
{
	lstEvtlog->Items->Clear();	
}
//---------------------------------------------------------------------------
 

void __fastcall TfrmMain::btnLogsaveClick(TObject *Sender)     // �α� ���� ���� �ȵ�
{	// save log
//	lstEvtlog->
	int d=0;
	int pp = FileExists("logfile.txt");
	if(pp==0)
	{
		d = FileCreate("logfile.txt");
	}else
	{
		d = FileOpen("logfile.txt",256);
    }
	if(d==-1)
	{ mmOut->Lines->Add("����"); }
	else
	{
		mmOut->Lines->Add("dd");
		TStrings * StringGrid1;
//		StringGrid1->Add("�ƾƾ�");
		FileRead(d,StringGrid1 ,256);
		mmOut->Lines->Add(StringGrid1->Text);
		FileClose(d);
	};


//
//	FILE *FOpen;//
//	if( OpenDialog1->Execute() )
//	{
//		FOpen = fopen(OpenDialog1->FileName.c_str(), "r+");
//
//		if( FOpen == NULL )
//		{
//			ShowMessage("The file could not be opened");
//			return;
//		}
//	}
//
//	fclose(FOpen);}
//---------------------------------------------------------------------------




void __fastcall TfrmMain::close1Click(TObject *Sender)            //�Ŵ� �ݱ�
{
	Close();	
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::btnMmoutClick(TObject *Sender)          //�޸� ��� Ŭ����
{
	mmOut->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::btnGentypeChange(TObject *Sender)     //CA100 �߻��� �Լ�
{
	AnsiString SourFunc;
	SourFunc = "SF";
	if(ComPort1->Connected ==1)
	{
		switch(btnGentype->ItemIndex)
		{
			case 0:
//				ComPort1->WriteStr("SO0\n");
				break;
			case 1:
//				ComPort1->WriteStr("SO1\n");
				SourFunc = SourFunc + "0";
				break;
			case 2:
//				ComPort1->WriteStr("SO1\n");
				SourFunc = SourFunc + "1";
				break;
			case 3:
//				ComPort1->WriteStr("SO1\n");
				SourFunc = SourFunc + "2";
				break;
			case 4:
//				ComPort1->WriteStr("SO1\n");
				SourFunc = SourFunc + "3";
				break;
			case 5:
//				ComPort1->WriteStr("SO1\n");
				SourFunc = SourFunc + "4";
				break;
			case 6:
//				ComPort1->WriteStr("SO1\n");
				SourFunc = SourFunc + "5";
				break;
				// ��Ÿ ���ļ� ����,�޽�,�޽�����,�޽� ���ļ� �߻��� ������
		}
		ComPort1->WriteStr(SourFunc+"\n"); //CRLF ���� �߰��ؾ���
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer2Timer(TObject *Sender)         //Sour & Gen �޼��� ���� Ÿ�̸�
{
	AnsiString SourMsg, MeasMsg;
	if(tabCA100->Showing && ComPort1->Connected)
	{
//		ComPort1->WriteStr("SF?\n");
//
//		ComPort1->WriteStr("SR?\n");

		ComPort1->WriteStr("SD?\n");                         	//source
		ComPort1->ReadStr(SourMsg,256);
		mmSour->Text = SourMsg;
		ComPort1->WriteStr("OD\n");    							//measure	
		ComPort1->ReadStr(MeasMsg,256);                         //�޼��� Ÿ���� �����ͷ� ����? or ca100 ��ɾ�� �θ���
		mmMeas->Text = MeasMsg;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::PageControl1Change(TObject *Sender)   //Ÿ�̸�2 Ʈ����
{
	Timer2->Enabled = tabCA100->Showing;	 //tab CA100 ���϶� Ÿ�̸� ��
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnSourtypeChange(TObject *Sender)    //measure function setting
{
	AnsiString MeasFunc;
	MeasFunc = "MF";
	if(ComPort1->Connected ==1)
	{
		switch(btnGentype->ItemIndex)
		{
			case 0:
//				ComPort1->WriteStr("MO0\n");
				break;
			case 1:
//				ComPort1->WriteStr("MO1\n");
				MeasFunc = MeasFunc + "0";
				break;
			case 2:
//				ComPort1->WriteStr("MO1\n");
				MeasFunc = MeasFunc + "1";
				break;
			case 3:
//				ComPort1->WriteStr("MO1\n");
				MeasFunc = MeasFunc + "2";
				break;
				// ��Ÿ ���ļ� ����,�޽�,�޽�����,�޽� ���ļ� �߻��� ������
		}
		ComPort1->WriteStr(MeasFunc+"\n"); //CRLF ���� �߰��ؾ���
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnHoldClick(TObject *Sender)
{
	AnsiString qq;
	ComPort1->ReadStr(qq,256);
	if(qq=="HD0")
	{
		ComPort1->WriteStr("HD1");
	}else
	{
		ComPort1->WriteStr("HD0");
	}                               
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::btnPca100Click(TObject *Sender)
{
	if(tabCA100->TabVisible)
	{
		tabCA100->TabVisible = 0;
	}else
	{
		tabCA100->TabVisible = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnPmsgClick(TObject *Sender)
{
	if(TabSheet1->TabVisible)
	{
		TabSheet1->TabVisible = 0;
	}else
	{
		TabSheet1->TabVisible = 1;
	}
}
//---------------------------------------------------------------------------


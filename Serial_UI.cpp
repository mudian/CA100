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


void __fastcall TfrmMain::vEventMessage(String msg)           //로그 메세지 저장
{
	String strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
	TListItem * evtLog = lstEvtlog-> Items ->Add();
	evtLog ->Caption = strT;
    evtLog ->SubItems->Add(msg);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnConnectClick(TObject *Sender)    // comport 연결 버튼
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
			btnConnect->Down = 1;              	 //버튼 모양 설정
			btnConnect->Caption ="Connect";
			  
			ComPort1->Port = cbxPort->Text;      //포트 번호, 속도 설정, 연결
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

void __fastcall TfrmMain::btnMminClick(TObject *Sender)      //메모 입력 버튼
{
   
	AnsiString StrMsg1,strT, strIn;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			StrMsg1 = mmIn->Lines->GetText();              	//메모 내용 읽기
			if(chkCR->Checked)                              //문자 끝에 붙일것 선택
			{
			StrMsg1 = StrMsg1+"\r";
			}if(chkLF->Checked)
			{
			StrMsg1 = StrMsg1+"\n";
			}

			int iRlt = ComPort1->WriteStr(StrMsg1);  		//메모 내용을 포트로 전송
			if(iRlt == StrMsg1.Length())//
			{
				vEventMessage("Tx:"+StrMsg1);
				lstEvtlog->Perform(WM_VSCROLL, SB_BOTTOM, 0);//스크롤바 최 하단으로 보내기
			}
			else
			{

			}
		}catch(...)
		{
			mmOut->Lines->Clear();                           // 접속 실패시 메세지
			mmOut->Lines->Add("실패");
		}
	}else
	{                                                        //연결 안되어있을때
		mmOut->Lines->Clear();
		mmOut->Lines->Add("연결하세요");
	}	
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer1Timer(TObject *Sender)      //출력메모 및 로그 메세지 반환 타이머
{

	AnsiString StrMsg2,strT,strOut;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			int iRx = ComPort1->ReadStr(StrMsg2,256);         //포트에서 메세지 읽어오기
			if(StrMsg2.Length() > 0)
			{
				mmOut->Lines->Clear();
				mmOut->Lines->Add(StrMsg2);

				vEventMessage("Rx:"+StrMsg2);
				lstEvtlog->Perform(WM_VSCROLL, SB_BOTTOM, 0);//스크롤바 최 하단으로 보내기
			}
		}catch(...)
		{
			mmOut->Lines->Add("실패");
		}
	}else
	{
		mmOut->Lines->Add("연결하세요");
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnLogclearClick(TObject *Sender)     //로그 클리어
{
	lstEvtlog->Items->Clear();	
}
//---------------------------------------------------------------------------
 

void __fastcall TfrmMain::btnLogsaveClick(TObject *Sender)     // 로그 저장 구현 안됨
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
	{ mmOut->Lines->Add("실패"); }
	else
	{
		mmOut->Lines->Add("dd");
		TStrings * StringGrid1;
//		StringGrid1->Add("아아아");
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




void __fastcall TfrmMain::close1Click(TObject *Sender)            //매뉴 닫기
{
	Close();	
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::btnMmoutClick(TObject *Sender)          //메모 출력 클리어
{
	mmOut->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::btnGentypeChange(TObject *Sender)     //CA100 발생부 함수
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
				// 기타 주파수 전압,펄스,펄스전압,펄스 주파수 발생기 존재함
		}
		ComPort1->WriteStr(SourFunc+"\n"); //CRLF 설정 추가해야함
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer2Timer(TObject *Sender)         //Sour & Gen 메세지 띄우는 타이머
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
		ComPort1->ReadStr(MeasMsg,256);                         //메세지 타입은 포인터로 저장? or ca100 명령어로 부르기
		mmMeas->Text = MeasMsg;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::PageControl1Change(TObject *Sender)   //타이머2 트리거
{
	Timer2->Enabled = tabCA100->Showing;	 //tab CA100 보일때 타이머 온
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
				// 기타 주파수 전압,펄스,펄스전압,펄스 주파수 발생기 존재함
		}
		ComPort1->WriteStr(MeasFunc+"\n"); //CRLF 설정 추가해야함
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


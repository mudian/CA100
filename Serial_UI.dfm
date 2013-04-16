object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'CA100 User Interface'
  ClientHeight = 616
  ClientWidth = 627
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 467
    Width = 627
    Height = 1
    Cursor = crVSplit
    Align = alBottom
    ExplicitTop = 462
  end
  object Panel2: TPanel
    Left = 0
    Top = 33
    Width = 627
    Height = 40
    Align = alTop
    BorderWidth = 5
    TabOrder = 0
    ExplicitWidth = 596
    object btnPmsg: TButton
      Left = 6
      Top = 10
      Width = 75
      Height = 25
      Caption = 'btnPmsg'
      TabOrder = 0
      OnClick = btnPmsgClick
    end
    object btnPca100: TButton
      Left = 87
      Top = 10
      Width = 75
      Height = 25
      Caption = 'btnPca100'
      TabOrder = 1
      OnClick = btnPca100Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 627
    Height = 33
    Align = alTop
    BorderWidth = 5
    TabOrder = 1
    ExplicitWidth = 596
    object Label1: TLabel
      Left = 6
      Top = 6
      Width = 51
      Height = 21
      Align = alLeft
      Caption = #53685#49888' '#49444#51221
      Layout = tlCenter
      ExplicitHeight = 13
    end
    object btnConnect: TSpeedButton
      Left = 546
      Top = 6
      Width = 75
      Height = 21
      Align = alRight
      Caption = 'Disconnect'
      OnClick = btnConnectClick
      ExplicitLeft = 571
    end
    object cbxPort: TComboBox
      Left = 57
      Top = 6
      Width = 72
      Height = 21
      Align = alLeft
      Style = csDropDownList
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 13
      ItemIndex = 3
      TabOrder = 0
      Text = 'COM4'
      Items.Strings = (
        'COM1'
        'COM2'
        'COM3'
        'COM4'
        'COM5'
        'COM6'
        'COM7'
        'COM9')
    end
    object btnBps: TComboBox
      Left = 129
      Top = 6
      Width = 96
      Height = 21
      Align = alLeft
      Style = csDropDownList
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 13
      ItemIndex = 5
      TabOrder = 1
      Text = '9600'
      Items.Strings = (
        '300'
        '600'
        '1200'
        '2400'
        '4800'
        '9600')
    end
    object Panel4: TPanel
      Left = 225
      Top = 6
      Width = 323
      Height = 21
      Align = alLeft
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = 'CA100'
      TabOrder = 2
      ExplicitWidth = 292
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 73
    Width = 113
    Height = 394
    Align = alLeft
    TabOrder = 2
    ExplicitHeight = 365
    object status: TLabel
      Left = 1
      Top = 1
      Width = 111
      Height = 24
      Align = alTop
      Alignment = taCenter
      Caption = #49345#53468
      Layout = tlCenter
    end
    object TreeView1: TTreeView
      Left = 1
      Top = 25
      Width = 111
      Height = 368
      Align = alClient
      Indent = 19
      TabOrder = 0
      Items.NodeData = {
        0102000000210000000000000000000000FFFFFFFFFFFFFFFF00000000020000
        00044D00610069006E00230000000000000001000000FFFFFFFFFFFFFFFF0000
        000000000000056500740063002E002E00190000000000000000000000FFFFFF
        FFFFFFFFFF000000000000000000190000000000000000000000FFFFFFFFFFFF
        FFFF000000000000000000}
      ExplicitLeft = 17
      ExplicitTop = 20
      ExplicitHeight = 362
    end
  end
  object PageControl1: TPageControl
    Left = 113
    Top = 73
    Width = 514
    Height = 394
    ActivePage = tabCA100
    Align = alClient
    TabOrder = 3
    OnChange = PageControl1Change
    ExplicitHeight = 388
    object TabSheet1: TTabSheet
      Caption = 'MSG In/Out'
      ExplicitWidth = 456
      ExplicitHeight = 332
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 506
        Height = 113
        Align = alTop
        Caption = 'Panel6'
        TabOrder = 0
        ExplicitWidth = 456
        object Label3: TLabel
          Left = 1
          Top = 1
          Width = 51
          Height = 111
          Align = alLeft
          Caption = #47749#47161' '#51077#47141
          Layout = tlCenter
          ExplicitHeight = 13
        end
        object mmIn: TMemo
          Left = 52
          Top = 1
          Width = 378
          Height = 111
          Align = alClient
          ImeName = 'Microsoft Office IME 2007'
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
          ExplicitLeft = 46
          ExplicitTop = -3
          ExplicitWidth = 328
        end
        object btnMmin: TButton
          Left = 430
          Top = 1
          Width = 75
          Height = 111
          Align = alRight
          Caption = 'b1'
          TabOrder = 1
          OnClick = btnMminClick
          ExplicitLeft = 380
        end
      end
      object Panel7: TPanel
        Left = 0
        Top = 113
        Width = 506
        Height = 121
        Align = alTop
        Caption = 'Panel7'
        TabOrder = 1
        ExplicitWidth = 456
        object Label2: TLabel
          Left = 1
          Top = 1
          Width = 51
          Height = 119
          Align = alLeft
          Caption = #52636#47141' '#45236#50857
          Layout = tlCenter
          ExplicitHeight = 13
        end
        object btnMmout: TButton
          Left = 430
          Top = 1
          Width = 75
          Height = 119
          Align = alRight
          Caption = 'b2'
          TabOrder = 0
          OnClick = btnMmoutClick
          ExplicitLeft = 380
        end
        object mmOut: TMemo
          Left = 52
          Top = 1
          Width = 378
          Height = 119
          Align = alClient
          ImeName = 'Microsoft Office IME 2007'
          TabOrder = 1
          ExplicitWidth = 328
        end
      end
      object Panel8: TPanel
        Left = 0
        Top = 258
        Width = 506
        Height = 108
        Align = alClient
        TabOrder = 2
        ExplicitWidth = 456
        ExplicitHeight = 74
      end
      object Panel10: TPanel
        Left = 0
        Top = 234
        Width = 506
        Height = 24
        Align = alTop
        TabOrder = 3
        ExplicitWidth = 456
        object Label6: TLabel
          AlignWithMargins = True
          Left = 4
          Top = 4
          Width = 55
          Height = 16
          Align = alLeft
          Alignment = taCenter
          Caption = #51077#47141' '#48169#49885':'
          ExplicitHeight = 13
        end
        object chkLF: TCheckBox
          Left = 62
          Top = 1
          Width = 97
          Height = 22
          Align = alLeft
          Caption = 'Line Feed'
          Checked = True
          ParentShowHint = False
          ShowHint = False
          State = cbChecked
          TabOrder = 0
        end
        object chkCR: TCheckBox
          Left = 159
          Top = 1
          Width = 97
          Height = 22
          Align = alLeft
          Caption = 'Carriage Return'
          TabOrder = 1
        end
      end
    end
    object tabCA100: TTabSheet
      Caption = 'CA100'
      ImageIndex = 1
      ExplicitWidth = 456
      ExplicitHeight = 332
      object ScrollBox1: TScrollBox
        Left = 0
        Top = 0
        Width = 506
        Height = 366
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 192
        ExplicitTop = 192
        ExplicitWidth = 185
        ExplicitHeight = 41
        object Panel11: TPanel
          Left = 0
          Top = 25
          Width = 502
          Height = 166
          Align = alClient
          TabOrder = 0
          ExplicitLeft = -1
          ExplicitTop = 21
          ExplicitHeight = 160
          object btnClrsour: TButton
            Left = 2
            Top = 6
            Width = 82
            Height = 25
            Caption = 'Initialize Gen'
            TabOrder = 0
          end
          object btnHold: TButton
            Left = 90
            Top = 5
            Width = 81
            Height = 25
            Caption = 'Measure Hold'
            TabOrder = 1
            OnClick = btnHoldClick
          end
        end
        object Panel12: TPanel
          Left = 0
          Top = 246
          Width = 502
          Height = 116
          Align = alBottom
          TabOrder = 1
          ExplicitTop = -79
          ExplicitWidth = 164
          object mmMeas: TMemo
            Left = 1
            Top = 57
            Width = 500
            Height = 58
            Align = alClient
            ImeName = 'Microsoft Office IME 2007'
            Lines.Strings = (
              'Display Measure Parameter')
            ReadOnly = True
            TabOrder = 0
            ExplicitWidth = 441
          end
          object mmSour: TMemo
            Left = 1
            Top = 1
            Width = 500
            Height = 56
            Align = alTop
            ImeName = 'Microsoft Office IME 2007'
            Lines.Strings = (
              'Display Source Parameter')
            ReadOnly = True
            TabOrder = 1
            ExplicitWidth = 441
          end
        end
        object Panel13: TPanel
          Left = 0
          Top = 191
          Width = 502
          Height = 55
          Align = alBottom
          TabOrder = 2
          ExplicitTop = -18
          ExplicitWidth = 164
          object mmSetting: TMemo
            Left = 225
            Top = 1
            Width = 159
            Height = 53
            Align = alClient
            ImeName = 'Microsoft Office IME 2007'
            Lines.Strings = (
              'Enter Setting Parameter')
            TabOrder = 0
            ExplicitWidth = 100
          end
          object btnEnter: TButton
            Left = 426
            Top = 1
            Width = 75
            Height = 53
            Align = alRight
            Caption = 'Enter'
            TabOrder = 1
            ExplicitLeft = 367
          end
          object Panel14: TPanel
            Left = 1
            Top = 1
            Width = 77
            Height = 53
            Align = alLeft
            TabOrder = 2
            object Label8: TLabel
              Left = 1
              Top = 1
              Width = 75
              Height = 30
              Align = alClient
              Alignment = taCenter
              Caption = #49444#51221' '#53485
              Layout = tlCenter
              ExplicitLeft = 24
              ExplicitTop = 18
              ExplicitWidth = 39
              ExplicitHeight = 13
            end
            object btnSetting: TComboBox
              Left = 1
              Top = 31
              Width = 75
              Height = 21
              HelpType = htKeyword
              Align = alBottom
              Style = csDropDownList
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ItemHeight = 13
              ItemIndex = 0
              ParentFont = False
              ParentShowHint = False
              ShowHint = False
              TabOrder = 0
              Text = #49444#51221' '#45824#44592
              Items.Strings = (
                #49444#51221' '#45824#44592
                #49444#51221' '#52712#49548
                #48276#50948' '#49444#51221
                #54868#47732' '#49444#51221
                #48156#49373' '#49688#52824
                #44592#53440' '#49444#51221)
            end
          end
          object Panel15: TPanel
            Left = 384
            Top = 1
            Width = 42
            Height = 53
            Align = alRight
            TabOrder = 3
            ExplicitLeft = 325
            object btnDown: TButton
              Left = 1
              Top = 26
              Width = 40
              Height = 25
              Align = alTop
              Caption = 'Down'
              TabOrder = 0
            end
            object btnUp: TButton
              Left = 1
              Top = 1
              Width = 40
              Height = 25
              Align = alTop
              Caption = 'Up'
              TabOrder = 1
            end
          end
          object lstStat: TListBox
            Left = 78
            Top = 1
            Width = 147
            Height = 53
            Align = alLeft
            ImeName = 'Microsoft Office IME 2007'
            ItemHeight = 13
            Items.Strings = (
              'Status or Question')
            TabOrder = 4
          end
        end
        object Panel9: TPanel
          Left = 0
          Top = 0
          Width = 502
          Height = 25
          Align = alTop
          TabOrder = 3
          ExplicitWidth = 443
          object Label4: TLabel
            Left = 1
            Top = 1
            Width = 56
            Height = 23
            Align = alLeft
            Alignment = taCenter
            AutoSize = False
            Caption = #48156#49373#48512
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            Layout = tlCenter
            ExplicitLeft = 2
          end
          object Label7: TLabel
            Left = 145
            Top = 1
            Width = 56
            Height = 23
            Align = alLeft
            Alignment = taCenter
            AutoSize = False
            Caption = #44228#52769#48512
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            Layout = tlCenter
            ExplicitLeft = 217
          end
          object btnGentype: TComboBox
            Left = 57
            Top = 1
            Width = 88
            Height = 21
            Align = alLeft
            Style = csDropDownList
            ImeName = 'Microsoft Office IME 2007'
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 0
            Text = #51221#51648
            OnChange = btnGentypeChange
            Items.Strings = (
              #51221#51648
              #51649#47448' '#51204#50517
              #51649#47448' '#51204#47448
              #51200#54637
              #50676#51204#45824
              #52769#50728#51200#54637#52404
              #51452#54028#49688)
            ExplicitLeft = 51
            ExplicitTop = -2
          end
          object btnSourtype: TComboBox
            Left = 201
            Top = 1
            Width = 88
            Height = 21
            Align = alLeft
            Style = csDropDownList
            ImeName = 'Microsoft Office IME 2007'
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 1
            Text = #51221#51648
            OnChange = btnSourtypeChange
            Items.Strings = (
              #51221#51648
              #51649#47448' '#51204#50517
              #51649#47448' '#51204#47448
              #51200#54637)
          end
        end
      end
    end
  end
  object Panel16: TPanel
    Left = 0
    Top = 468
    Width = 627
    Height = 148
    Align = alBottom
    TabOrder = 4
    object lstEvtlog: TListView
      Left = 1
      Top = 33
      Width = 625
      Height = 114
      Align = alClient
      Columns = <
        item
          Caption = 'Time'
          Width = 150
        end
        item
          Caption = 'Log'
          Width = 400
        end>
      FlatScrollBars = True
      RowSelect = True
      ShowWorkAreas = True
      TabOrder = 0
      ViewStyle = vsReport
      ExplicitLeft = 10
      ExplicitTop = 31
      ExplicitHeight = 120
    end
    object Panel5: TPanel
      Left = 1
      Top = 1
      Width = 625
      Height = 32
      Align = alTop
      BorderWidth = 5
      TabOrder = 1
      ExplicitTop = 2
      object Label5: TLabel
        AlignWithMargins = True
        Left = 9
        Top = 9
        Width = 51
        Height = 14
        Align = alLeft
        Alignment = taCenter
        Caption = #53685#49888' '#47196#44536
        Layout = tlCenter
        ExplicitHeight = 13
      end
      object btnLogclear: TButton
        Left = 63
        Top = 6
        Width = 75
        Height = 20
        Align = alLeft
        Caption = #47196#44536' '#49325#51228
        TabOrder = 0
        OnClick = btnLogclearClick
      end
      object btnLogsave: TButton
        Left = 138
        Top = 6
        Width = 75
        Height = 20
        Align = alLeft
        Caption = #47196#44536' '#51200#51109
        TabOrder = 1
        OnClick = btnLogsaveClick
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 392
    object File1: TMenuItem
      Caption = 'File'
      object close1: TMenuItem
        Caption = 'close'
        OnClick = close1Click
      end
    end
    object help1: TMenuItem
      Caption = 'help'
      object menual1: TMenuItem
        Caption = 'Open Manual'
      end
    end
  end
  object ComPort1: TComPort
    BaudRate = br9600
    Port = 'COM1'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    Left = 8
    Top = 424
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 40
    Top = 424
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer2Timer
    Left = 72
    Top = 424
  end
end

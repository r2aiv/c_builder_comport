object MainForm: TMainForm
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = #1056#1072#1073#1086#1090#1072' '#1089' COM-'#1087#1086#1088#1090#1086#1084
  ClientHeight = 73
  ClientWidth = 322
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object COMPortComboBox: TComboBox
    Left = 8
    Top = 8
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'COM1'
    Items.Strings = (
      'COM1'
      'COM2'
      'COM3'
      'COM4'
      'COM5'
      'COM6'
      'COM7'
      'COM8'
      'COM9'
      'COM10')
  end
  object OpenCOMPortBtn: TButton
    Left = 160
    Top = 8
    Width = 75
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = OpenCOMPortBtnClick
  end
  object CloseCOMPortBtn: TButton
    Left = 240
    Top = 8
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    Enabled = False
    TabOrder = 2
    OnClick = CloseCOMPortBtnClick
  end
  object PacketEditBox: TEdit
    Left = 8
    Top = 40
    Width = 145
    Height = 21
    TabOrder = 3
    Text = 'TEST'
  end
  object COMPortSendBtn: TButton
    Left = 160
    Top = 40
    Width = 75
    Height = 25
    Caption = #1054#1090#1087#1088#1072#1074#1080#1090#1100
    TabOrder = 4
    OnClick = COMPortSendBtnClick
  end
  object ExitBtn: TButton
    Left = 240
    Top = 40
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 5
    OnClick = ExitBtnClick
  end
end

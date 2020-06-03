object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 450
  ClientWidth = 851
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 296
    Top = 8
    Width = 529
    Height = 185
    TabOrder = 0
  end
  object Button1: TButton
    Left = 480
    Top = 199
    Width = 137
    Height = 33
    Caption = #1048#1085#1080#1094#1080#1072#1083#1080#1079#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 480
    Top = 238
    Width = 137
    Height = 35
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1091#1076#1077#1085#1090#1072
    TabOrder = 2
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 56
    Top = 16
    Width = 145
    Height = 21
    TabOrder = 3
    Text = #1057#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1100
    OnChange = OnChange1
  end
  object Button3: TButton
    Left = 480
    Top = 279
    Width = 137
    Height = 34
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 480
    Top = 319
    Width = 137
    Height = 34
    Caption = #1055#1086#1080#1089#1082
    TabOrder = 5
    OnClick = Button4Click
  end
  object OpenDialog1: TOpenDialog
    Left = 736
    Top = 360
  end
  object SaveDialog1: TSaveDialog
    Left = 744
    Top = 296
  end
end

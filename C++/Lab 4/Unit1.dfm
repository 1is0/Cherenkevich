object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 438
  ClientWidth = 659
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 88
    Top = 32
    Width = 51
    Height = 13
    Caption = 'Infix form:'
  end
  object Label2: TLabel
    Left = 77
    Top = 104
    Width = 62
    Height = 13
    Caption = 'Postfix form:'
  end
  object Label3: TLabel
    Left = 77
    Top = 256
    Width = 86
    Height = 13
    Caption = 'Calculation result:'
  end
  object Edit1: TEdit
    Left = 48
    Top = 51
    Width = 129
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 48
    Top = 123
    Width = 129
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 48
    Top = 160
    Width = 129
    Height = 41
    Caption = 'Transform the expression'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 48
    Top = 275
    Width = 129
    Height = 21
    TabOrder = 3
  end
  object Button2: TButton
    Left = 48
    Top = 302
    Width = 129
    Height = 41
    Caption = 'Calculate'
    TabOrder = 4
    OnClick = Button2Click
  end
  object StringGrid1: TStringGrid
    Left = 280
    Top = 123
    Width = 153
    Height = 169
    RowCount = 6
    TabOrder = 5
  end
end

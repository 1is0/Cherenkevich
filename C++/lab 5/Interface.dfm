object Present: TPresent
  Left = 0
  Top = 0
  Caption = 'q'
  ClientHeight = 389
  ClientWidth = 403
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
    Left = 69
    Top = 20
    Width = 76
    Height = 21
    Caption = 'Interval=['
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 222
    Top = 25
    Width = 5
    Height = 21
    Caption = ','
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 303
    Top = 20
    Width = 7
    Height = 21
    Caption = ']'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 148
    Top = 120
    Width = 87
    Height = 18
    Caption = 'Queue Items'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object List1: TListBox
    Left = 32
    Top = 144
    Width = 313
    Height = 182
    ItemHeight = 13
    TabOrder = 5
  end
  object Clear1: TButton
    Left = 223
    Top = 348
    Width = 122
    Height = 33
    Caption = 'Delete queue'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Clear1Click
  end
  object AddRand: TButton
    Left = 69
    Top = 81
    Width = 241
    Height = 33
    Caption = 'Add random'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = AddRandClick
  end
  object A: TEdit
    Left = 151
    Top = 17
    Width = 65
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '0'
    OnClick = AClick
  end
  object B: TEdit
    Left = 235
    Top = 17
    Width = 65
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = '10'
    OnClick = BClick
  end
  object DelSame: TButton
    Left = 32
    Top = 348
    Width = 185
    Height = 33
    Caption = 'Delete same elements'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = DelSameClick
  end
end

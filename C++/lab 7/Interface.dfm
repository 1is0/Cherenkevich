object Present: TPresent
  Left = 0
  Top = 0
  Caption = 'Present'
  ClientHeight = 459
  ClientWidth = 685
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 233
    Top = 0
    Width = 452
    Height = 459
    Align = alClient
    Caption = 'View'
    TabOrder = 0
    object Table: TMemo
      Left = 2
      Top = 248
      Width = 448
      Height = 209
      Align = alBottom
      Lines.Strings = (
        'Table')
      ReadOnly = True
      TabOrder = 0
    end
    object Elements: TRichEdit
      Left = 2
      Top = 15
      Width = 238
      Height = 233
      Align = alClient
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Lines.Strings = (
        'Elements')
      ParentFont = False
      TabOrder = 1
      Zoom = 100
      OnClick = ElementsClick
    end
    object Raw: TRichEdit
      Left = 240
      Top = 15
      Width = 210
      Height = 233
      Align = alRight
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Lines.Strings = (
        'Raw')
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
      Zoom = 100
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 0
    Width = 233
    Height = 459
    Align = alLeft
    Caption = 'Control'
    TabOrder = 1
    object FillTable: TButton
      Left = 4
      Top = 123
      Width = 223
      Height = 33
      Caption = 'Fill the table'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = FillTableClick
    end
    object ElemAmount: TEdit
      Left = 4
      Top = 45
      Width = 223
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = 'Elements amount'
      OnClick = ElemAmountClick
    end
    object TableSize: TEdit
      Left = 4
      Top = 80
      Width = 223
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = 'Hash table size'
      OnClick = TableSizeClick
    end
    object KeySrch: TEdit
      Left = 122
      Top = 162
      Width = 105
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = 'Enter a key'
      OnClick = KeySrchClick
    end
    object KeyDel: TEdit
      Left = 122
      Top = 197
      Width = 105
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      Text = 'Enter a key'
      OnClick = KeyDelClick
    end
    object Search: TButton
      Left = 4
      Top = 162
      Width = 112
      Height = 29
      Caption = 'Search'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = SearchClick
    end
    object Del: TButton
      Left = 4
      Top = 197
      Width = 112
      Height = 29
      Caption = 'Delete'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = DelClick
    end
    object CountNodes: TButton
      Left = 4
      Top = 232
      Width = 223
      Height = 33
      Caption = 'Count nodes in every stack'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = CountNodesClick
    end
    object Clear: TButton
      Left = 4
      Top = 271
      Width = 223
      Height = 33
      Caption = 'Clear'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = ClearClick
    end
  end
end

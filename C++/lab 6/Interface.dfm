object Present: TPresent
  Left = 0
  Top = 0
  Caption = 'Present'
  ClientHeight = 583
  ClientWidth = 870
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Control: TGroupBox
    Left = 0
    Top = 0
    Width = 313
    Height = 583
    Align = alLeft
    Caption = 'Control'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      313
      583)
    object Info: TStringGrid
      Left = 2
      Top = 291
      Width = 309
      Height = 258
      Align = alBottom
      ColCount = 2
      DefaultColWidth = 150
      FixedCols = 0
      RowCount = 10
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowMoving, goEditing]
      TabOrder = 11
      RowHeights = (
        24
        24
        24
        23
        24
        24
        24
        24
        24
        27)
    end
    object FiilTree: TButton
      Left = 2
      Top = 129
      Width = 307
      Height = 32
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Fill the tree'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = FiilTreeClick
    end
    object ShowLNR: TButton
      Left = 3
      Top = 91
      Width = 307
      Height = 32
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Show Left-Node-Right'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = ShowLNRClick
    end
    object ShowLRN: TButton
      Left = 3
      Top = 53
      Width = 307
      Height = 32
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Show Left-Right-Node'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = ShowLRNClick
    end
    object ShowNLR: TButton
      Left = 3
      Top = 15
      Width = 307
      Height = 32
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Show Node-Left-Right'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = ShowNLRClick
    end
    object ClearTree: TButton
      Left = 2
      Top = 549
      Width = 309
      Height = 32
      Align = alBottom
      Caption = 'Clear Tree'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = ClearTreeClick
    end
    object AmountOfItems: TEdit
      Left = 3
      Top = 178
      Width = 121
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      Text = '9'
      OnClick = AmountOfItemsClick
    end
    object GetItemsAm: TButton
      Left = 130
      Top = 178
      Width = 177
      Height = 32
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Amount of nodes'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = GetItemsAmClick
    end
    object KeyDelete: TEdit
      Left = 3
      Top = 216
      Width = 121
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      Text = 'Enter key'
      OnChange = KeyDeleteChange
      OnClick = KeyDeleteChange
    end
    object GetChar: TEdit
      Left = 3
      Top = 251
      Width = 121
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      Text = 'Enter key'
      OnChange = GetCharChange
      OnClick = GetCharClick
    end
    object NodeDelete: TButton
      Left = 130
      Top = 216
      Width = 177
      Height = 32
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Delete a node '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = NodeDeleteClick
    end
    object SearchChar: TButton
      Left = 133
      Top = 254
      Width = 177
      Height = 32
      Anchors = [akLeft, akTop, akRight]
      Caption = 'Search'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = SearchCharClick
    end
  end
  object Tree: TGroupBox
    Left = 313
    Top = 0
    Width = 557
    Height = 583
    Align = alClient
    Caption = 'Tree'
    TabOrder = 1
    object TreeView: TTreeView
      Left = 2
      Top = 15
      Width = 310
      Height = 566
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      Indent = 19
      ParentFont = False
      TabOrder = 0
    end
    object Memo: TMemo
      Left = 312
      Top = 15
      Width = 243
      Height = 566
      Align = alRight
      Lines.Strings = (
        'Memo')
      TabOrder = 1
    end
  end
end

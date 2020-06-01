object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 376
  ClientWidth = 793
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = -2
    Width = 354
    Height = 265
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object RadioGroup1: TRadioGroup
    Left = 494
    Top = 8
    Width = 105
    Height = 224
    Caption = 'Choose figure:'
    Items.Strings = (
      'Rectangle '
      'Ellipse '
      'Triangle')
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 8
    Top = 269
    Width = 106
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 8
    Top = 296
    Width = 177
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 8
    Top = 328
    Width = 209
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 319
    Top = 328
    Width = 169
    Height = 21
    TabOrder = 4
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 552
    Top = 328
    Width = 193
    Height = 21
    TabOrder = 5
    Text = 'Edit5'
  end
  object Button1: TButton
    Left = 375
    Top = 238
    Width = 137
    Height = 25
    Caption = 'Button1'
    TabOrder = 6
    OnClick = Button1Click
  end
  object RadioGroup2: TRadioGroup
    Left = 375
    Top = 8
    Width = 113
    Height = 224
    Caption = 'RadioGroup2'
    Items.Strings = (
      'Draw '
      'Move '
      'Icrease(Decrease)Size'
      'Move(Point)')
    TabOrder = 7
  end
  object ComboBox1: TComboBox
    Left = 625
    Top = 8
    Width = 129
    Height = 21
    TabOrder = 8
    Text = 'Color'
    Items.Strings = (
      'White'
      'Blue '
      'Yellow'
      'Green '
      'Black'
      'Red')
  end
  object Button2: TButton
    Left = 616
    Top = 128
    Width = 145
    Height = 33
    Caption = 'Clear'
    TabOrder = 9
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 704
    Top = 180
    Width = 57
    Height = 52
    Caption = '+'
    TabOrder = 10
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 616
    Top = 179
    Width = 57
    Height = 53
    Caption = '-'
    TabOrder = 11
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 616
    Top = 72
    Width = 145
    Height = 33
    Caption = 'Rotate'
    TabOrder = 12
    OnClick = Button5Click
  end
end

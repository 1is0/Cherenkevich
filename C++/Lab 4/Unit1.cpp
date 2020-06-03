//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString otvet;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1 -> Cells[0][0] = "Variable"; StringGrid1 -> Cells[1][0]="Value";
	StringGrid1 -> Cells[0][1] = "a"; StringGrid1 -> Cells[1][1] = "5.6";
	StringGrid1 -> Cells[0][2] = "b"; StringGrid1 -> Cells[1][2] = "3.2";
	StringGrid1 -> Cells[0][3] = "c"; StringGrid1 -> Cells[1][3] = "0.9";
	StringGrid1 -> Cells[0][4] = "d"; StringGrid1 -> Cells[1][4] = "1.7";
	StringGrid1 -> Cells[0][5] = "e"; StringGrid1 -> Cells[1][5] = "4.8";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (Edit1->Text=="")
		ShowMessage("You haven't entered anything!");
	else
	{
		otvet = ToOPZ (Edit1->Text);
		Edit2->Text=otvet;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (Edit1 -> Text == "")
		ShowMessage("You haven't entered anything!");
	else
	{
		if (otvet=="")
			otvet=ToOPZ(Edit1->Text);
		Edit3->Text=Calculate(otvet);
	}
}
//---------------------------------------------------------------------------



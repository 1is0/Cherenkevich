//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Interface.h"
#include "Converter.h"
#include "Calc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Converter* conv;
Calcul* solv;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	double* nums = new double[5];
	AnsiString math;

	conv = new Converter();
	math = conv->RewriteMath(Intput->Text);
	delete conv;
	try {
		nums[0] = StrToFloat(ReplaceComa(A->Text.Trim()));
		nums[1] = StrToFloat(ReplaceComa(B->Text.Trim()));
		nums[2] = StrToFloat(ReplaceComa(C->Text.Trim()));
		nums[3] = StrToFloat(ReplaceComa(D->Text.Trim()));
		nums[4] = StrToFloat(ReplaceComa(E->Text.Trim()));
	} catch (...) {
		A->Text = "DATA?";
		B->Text = "DATA?";
		C->Text = "DATA?";
		D->Text = "DATA?";
		E->Text = "DATA?";
		Intput->Text = "Wrong input.";
        return;
	}
	LastNote->Caption = math;
	solv = new Calcul(math, nums);
	Result->Caption = "=" + solv->GetRes();
    delete solv;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IntputClick(TObject *Sender)
{
	Intput->Text = "";
}
//---------------------------------------------------------------------------

AnsiString  TForm1::ReplaceComa(AnsiString str)
{
	for (int i = 1, len = str.Length(); i <= len; i++) {
		if (str[i] == '.') {
			str[i] = ',';
		}
	}
    return str;
}


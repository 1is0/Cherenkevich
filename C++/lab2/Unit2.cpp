//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern Student *st;
extern int n;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	wchar_t str[100] = L"";
	wchar_t t[] = L"\t";
	wcscat(str, Edit5->Text.c_str());
	wcscat(str, t);
	wcscat(str, Edit6->Text.c_str());
    wcscat(str, t);
	wcscat(str, Edit4->Text.c_str());
    wcscat(str, t);
	wcscat(str, Edit1->Text.c_str());
	wcscat(str, t);
	wcscat(str, Edit2->Text.c_str());
	wcscat(str, t);
	wcscat(str, Edit3->Text.c_str());
	st[n].Extraction(str);

	Memo1->Lines->Add(str);
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";
	Edit5->Text = "";
	Edit6->Text = "";
	Form1->Memo1->Lines->Add(st[n].string);
	n++;
	bool yes = true;
	for(int i = 0; i < n - 1; i++)
	{
		if(strcmp(st[n - 1].speciality, st[i].speciality) == 0)
		{
			yes = false;
        }
	}
	if(yes)
	{
		Form1->ComboBox1->Items->Add(st[n - 1].speciality);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::OnClose1(TObject *Sender, TCloseAction &Action)
{
    Memo1->Clear();
}
//---------------------------------------------------------------------------


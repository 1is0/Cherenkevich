//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#include "student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
extern Student *st;
extern int n;
int del;
bool ind = false;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Memo1->Clear();
	wchar_t *str = Edit1->Text.c_str();
	ind = false;
	char mtr[100];
	size_t len = wcstombs(mtr, str, wcslen(str));
	if(len > 0u)
	{
		mtr[len] = '\0';
	}
	puts(mtr);
	for (int i = 0; i < n; i++)
	{
		if(strcmp(st[i].FIO,mtr) == 0)
		{
			Memo1->Lines->Add(st[i].FIO);
			ind = true;
			del = i;
			break;
		}
	}
	if(ind == false)
	{
		Memo1->Lines->Add("Нет абитуриентов с такими ФИО");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::OnClose1(TObject *Sender, TCloseAction &Action)
{
	Memo1->Clear();
	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	if(ind)
	{
		Form1->Memo1->Clear();
		n--;
		for(int i = del; i < n; i++)
		{
			st[i] = st[i + 1];
		}
		for(int i = 0; i < n; i++)
		{
			Form1->Memo1->Lines->Add(st[i].string);
		}
		ind = false;
	}

}
//---------------------------------------------------------------------------

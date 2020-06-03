//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Student * st = new Student [100];
int n = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ComboBox1->Items->Add("Все специальности");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		TFileStream * tf = new TFileStream(OpenDialog1->FileName, fmOpenRead);
		TStringList * SL = new TStringList;
		SL->LoadFromStream(tf);
		n = SL->Count;
		for(int i = 0; i < SL->Count; i++)
		{
			st[i].Extraction(SL->Strings[i].c_str());
			Memo1->Lines->Add(st[i].string);
		}
		delete tf;
	}
	for(int i = 0; i < n; i++)
	{
		bool yes = true;
		for(int j = i + 1; j < n; j++)
		{
			if (strcmp(st[i].speciality, st[j].speciality) == 0)
			{
				yes = false;
			}
		}
		if(yes)
		{
			ComboBox1->Items->Add(st[i].speciality);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(SaveDialog1->Execute())
	{
        Memo1->Lines->SaveToFile(SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OnChange1(TObject *Sender)
{
	if(ComboBox1->ItemIndex == 0)
	{
        Memo1->Clear();
		for(int i = 0; i < n; i++)
		{
			Memo1->Lines->Add(st[i].string);
		}
	}
	else
	{
		Memo1->Clear();
		wchar_t *sp = ComboBox1->Items->Strings[ComboBox1->ItemIndex].c_str();
		char str[100];
		size_t len = wcstombs(str, sp, wcslen(sp));
		if(len > 0u)
		{
			str[len] = '\0';
		}
		puts(str);
		Student *st2 = new Student[100];
		int n1 = 0;
		for(int i = 0; i < n; i++)
		{
			if(strcmp(str, st[i].speciality) == 0)
			{
				st2[n1] =  st[i];
				n1++;
            }
		}
		for(int i = 1 ; i < n1; i++)
		{
			for(int j = i; j > 0 && st2[j - 1].GetSum() < st2[j].GetSum(); j--)
			{
				Student temp = st2[j - 1];
				st2[j - 1] = st2[j];
				st2[j] = temp;
			}
		}
		for(int i = 0; i < n1; i++)
		{
			Memo1->Lines->Add(st2[i].string);
        }
		delete[] st2;
	}
}
//---------------------------------------------------------------------------


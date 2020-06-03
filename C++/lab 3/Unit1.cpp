//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "MyList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List *list = new List();

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try
	{
        list -> push_back(Edit1 -> Text, Edit2 -> Text, StrToInt(Edit3 -> Text), StrToInt(Edit4 -> Text));
	}

	catch(myexcep &error)
	{
		ShowMessage(error.GetMessage());
	}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	try
	{
		list -> Search(Edit5 -> Text, Memo1);
	}
	catch(myexcep &error)
	{
		ShowMessage(error.GetMessage());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int position = StrToInt(Edit6 -> Text);
	try
	{
		list -> removeAt(position);
	}
	catch(myexcep &error)
	{
		ShowMessage(error.GetMessage());
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
	list -> Show(Memo1);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	try
	{
		list -> SearchSalary(Edit7 -> Text, Memo1);
	}
	catch(myexcep &error)
	{
		ShowMessage(error.GetMessage());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	try
	{
		list -> SearchHours(Edit8 -> Text, Memo1);
	}
	catch(myexcep &error)
	{
		ShowMessage(error.GetMessage());
    }
}
//---------------------------------------------------------------------------


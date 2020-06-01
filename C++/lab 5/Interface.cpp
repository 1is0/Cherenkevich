//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Interface.h"
#include "Queue.h"
#include "RandItems.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPresent *Present;
RandItems* qq = NULL;
//---------------------------------------------------------------------------
__fastcall TPresent::TPresent(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPresent::Clear1Click(TObject *Sender)
{
	if (qq) {
        List1->Clear();
		delete (Queue*)qq;
		qq = NULL;
        ShowMessage("Queue was deleted!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TPresent::InputClick(TObject *Sender)
{
	//Input->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TPresent::AddRandClick(TObject *Sender)
{
	int a, b;

	try {
		a = StrToInt(A->Text);
        b = StrToInt(B->Text);
	} catch (...) {
		A->Text = "Error";
		B->Text = "Error";
        return;
	}

	if (!qq) {
		qq = new RandItems(qq->GetRandNum(a, b));
	} else {
		qq->AddItemToEnd(qq->GetRandNum(a, b));
	}
	qq->ShowQ(Present);
	qq->ShowQ(Present);
}
//---------------------------------------------------------------------------


void __fastcall TPresent::AClick(TObject *Sender)
{
    A->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TPresent::BClick(TObject *Sender)
{
    B->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TPresent::DelSameClick(TObject *Sender)
{
	if (qq->IsEmpty()) {
        ShowMessage("Queue is empty!");
		return;
	}
	qq->DelSameItems();
    qq->ShowQ(Present);
}
//---------------------------------------------------------------------------


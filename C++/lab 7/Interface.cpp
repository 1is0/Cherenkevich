//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Interface.h"
#include "HashTable.h"
#include "CountStack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPresent *Present;
CountStack* table = NULL;
//---------------------------------------------------------------------------
__fastcall TPresent::TPresent(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPresent::ElemAmountClick(TObject *Sender)
{
    ElemAmount->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TPresent::TableSizeClick(TObject *Sender)
{
     TableSize->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TPresent::FillTableClick(TObject *Sender)
{
	if (table) {
		ShowMessage("Clear the table first!");
		return;
	}
	Raw->Lines->Clear();
	Table->Lines->Clear();
	int size, elem;
	try {
        elem = StrToInt(ElemAmount->Text);
	} catch (...) {
		ElemAmount->Text = "Wrong input";
		return;
	}
	try {
		size = StrToInt(TableSize->Text);
	} catch (...) {
		TableSize->Text = "Wrong input";
	}
	if (CheckData(elem)) {
        return;
	}
	table = new class CountStack(size);
	table->FillTable(Present, elem);
    table->ShowTable(Present);
}
//---------------------------------------------------------------------------

bool TPresent::CheckData(int elem)
{
	try {
		for (int i = 0; i < elem; i++) {
			AnsiString line = Elements->Lines->Strings[i];
			StrToInt(line);
		}
	}
	catch (...) {
		ShowMessage("Some mistakes in the element table! Can't procces it.");
		return true;
	}
    return false;
}
void __fastcall TPresent::ElementsClick(TObject *Sender)
{
	Elements->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TPresent::ClearClick(TObject *Sender)
{
    Raw->Lines->Clear();
	Table->Lines->Clear();
	delete table;
    table = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TPresent::SearchClick(TObject *Sender)
{
    if (!table) {
		ShowMessage("The hash table is empty");
		return;
	}
	int key;
	try {
		key = StrToInt(KeySrch->Text);
	} catch (...) {
		KeySrch->Text = "";
	}
	Node* p = table->FindNode(key);
	if (p) {
		ShowMessage("Have found a node with " + IntToStr(key) + "key");
	} else {
		ShowMessage("There is no such key!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TPresent::KeySrchClick(TObject *Sender)
{
    KeySrch->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TPresent::KeyDelClick(TObject *Sender)
{
    KeyDel->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TPresent::DelClick(TObject *Sender)
{
    if (!table) {
		ShowMessage("The hash table is empty");
		return;
	}
	int key;
	try {
		key = StrToInt(KeyDel->Text);
	} catch (...) {
		KeyDel->Text = "";
	}
	if (table->DelNode(key)) {
		ShowMessage("Node with " + IntToStr(key) + "key was deleted!");
	} else {
		ShowMessage("There is no such key!");
	}
    Raw->Lines->Clear();
	Table->Lines->Clear();
    table->ShowTable(Present);
}
//---------------------------------------------------------------------------
void __fastcall TPresent::CountNodesClick(TObject *Sender)
{
	if (!table) {
        ShowMessage("The hash table is empty");
		return;
	}
    ShowMessage(table->CountStackItems());
}
//---------------------------------------------------------------------------


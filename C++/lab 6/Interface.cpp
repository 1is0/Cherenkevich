//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Interface.h"
#include "Tree.h"
#include "Words.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPresent *Present;
Words* tree;

//---------------------------------------------------------------------------
__fastcall TPresent::TPresent(TComponent* Owner)
	: TForm(Owner)
{
	Info->Cells[0][0] = "Strings";
    Info->Cells[1][0] = "Keys";
}
//---------------------------------------------------------------------------
void __fastcall TPresent::KeyDeleteChange(TObject *Sender)
{
    KeyDelete->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TPresent::GetCharClick(TObject *Sender)
{
    GetChar->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TPresent::AmountOfItemsClick(TObject *Sender)
{
    AmountOfItems->Text = "";
}

bool TPresent::CheckInfo()
{
	for (int i = 1, len = Info->RowCount; i < len; i++) {
		if (Info->Cells[0][i] == "" || Info->Cells[1][i] == "") {
			ShowMessage("There are empty slots in the info table! Can't fill the tree.");
			return 1;
		}
		try {
            StrToInt(Info->Cells[1][i]);
		} catch (...) {
			ShowMessage("The are wrong input of a key! Can't fill the tree.");
            return 1;
		}
	}
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TPresent::GetItemsAmClick(TObject *Sender)
{
	int rows;

	try {
		rows = StrToInt(AmountOfItems->Text);
	} catch (...) {
		AmountOfItems->Text = "Wrong input.";
		return;
	}
	if (rows == 0) {
		ShowMessage("Should be at least one node int the table");
        return;
	}
    Info->RowCount = rows + 1;
}
//---------------------------------------------------------------------------
void __fastcall TPresent::FiilTreeClick(TObject *Sender)
{
	if (CheckInfo()) {
		return;
	}
	if (tree) {
		ShowMessage("Clear the tree first!");
        return;
	}
	tree = new class Words();
	tree->FillTree(Present);
    Tree::TreeViewSync(Present, tree->root);
}
//---------------------------------------------------------------------------
void __fastcall TPresent::ClearTreeClick(TObject *Sender)
{
	TreeView->Items->Clear();
	Memo->Clear();
	Tree::ClearTree(&tree->root);
	delete(tree);
    tree = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TPresent::ShowLNRClick(TObject *Sender)
{
	if (!tree) {
		ShowMessage("The Tree is empty!");
		return;
	}
    Memo->Lines->Clear();
	Tree::ShowLNR(Present, tree->root);

}
//---------------------------------------------------------------------------
void __fastcall TPresent::ShowLRNClick(TObject *Sender)
{
    if (!tree) {
		ShowMessage("The Tree is empty!");
		return;
	}
	Memo->Lines->Clear();
	Tree::ShowLRN(Present, tree->root);
}
//---------------------------------------------------------------------------
void __fastcall TPresent::ShowNLRClick(TObject *Sender)
{
    if (!tree) {
		ShowMessage("The Tree is empty!");
		return;
	}
    Memo->Lines->Clear();
	Tree::ShowNLR(Present, tree->root);
}
//---------------------------------------------------------------------------
void __fastcall TPresent::SearchCharClick(TObject *Sender)
{
	int num = 0;
	char ch = '\0';
	Node* p;

	Memo->Lines->Clear();
	try {
		num = StrToInt(GetChar->Text);
	} catch (...) {
        num = 0;
		AnsiString str = GetChar->Text;
		if (str.Length() > 1) {
			GetChar->Text = "Wrong input.";
            return;
		}
        ch = str[1];
	}
	if (num) {
		p = tree->SearchKey(num);
		if (!p) {
			ShowMessage("There is no such key!");
			return;
		}
		Memo->Lines->Add(p->info.text + " " + p->info.key);
	} else {
		tree->WordsWithFirstChar(tree->root, ch, num);
		if (!p) {
			ShowMessage("There is no string which starts with this cahr!");
			return;
		}
		Memo->Lines->Add("There are " + IntToStr(num) + " words with first \'" + ch + "\' char");
    }
}
//---------------------------------------------------------------------------
void __fastcall TPresent::NodeDeleteClick(TObject *Sender)
{
	int num;

	try {
		num = StrToInt(KeyDelete->Text);
	} catch (...) {
		KeyDelete->Text = "Wrong input!";
		return;
	}
    TreeView->Items->Clear();
	tree->root = Tree::RemoveNode(tree->root, num);
	Tree::TreeViewSync(Present, tree->root);
    Memo->Lines->Clear();
}
//---------------------------------------------------------------------------


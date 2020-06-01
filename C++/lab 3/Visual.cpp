//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Visual.h"
#include "WorkersList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Worker* list = NULL;
Worker* chosen = NULL;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShowDataClck(TObject *Sender)
{
    ShowData->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OffFiltClick(TObject *Sender)
{
	ShowData->Visible = false;
	Show->Top = 249;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CertEarnClick(TObject *Sender)
{
	ShowData->Visible = true;
	ShowData->Text = "Input data";
	Show->Top = 281;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CertHoursClick(TObject *Sender)
{
	ShowData->Visible = true;
    ShowData->Text = "Input data";
	Show->Top = 281;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SearchClck(TObject *Sender)
{
    Search->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddClick(TObject *Sender)
{
	struct Info itm;

	try {
		itm.name = Name->Text;
		itm.ID = StrToInt(ID->Text);
		itm.hours = StrToInt(Hours->Text);
		itm.paymnt = StrToFloat(Earn->Text);
		if (!list) {
			list = new Worker(itm);
		} else {
			list = Worker::AddItem(list, itm);
		}
		Name->Text = "";
		ID->Text = "";
		Hours->Text = "";
		Earn->Text = "";
	} catch (...) {
		Name->Text = "Data?";
		ID->Text = "Data?";
		Hours->Text = "Data?";
		Earn->Text = "Data?";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShowClick(TObject *Sender)
{
	AnsiString data = ShowData->Text;

	Info->Lines->Clear();
	chosen = NULL;
	try {
		if (OffFilt->Checked == true) {
			Worker::ShowList(Form1, list);
		} else if (Overtime->Checked == true) {
			Worker::ShowMatches(Form1, list, NULL, Worker::CompOvertime);
		} else if (CertEarn->Checked == true) {
			double ern = StrToFloat(data);
			Worker::ShowMatches(Form1, list, &ern, Worker::CompEarn);
		} else if (CertHours->Checked == true) {
			int hrs = StrToInt(data);
			Worker::ShowMatches(Form1, list, &hrs, Worker::CompHrs);
		}
	} catch (...) {
        ShowData->Text = "Wrong data";
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SrchClick(TObject *Sender)
{
	AnsiString person = Search->Text;
	Worker* p;

	if (!list) {
		ShowMessage("List of workers is empty!");
        return;
	}
	Info->Lines->Clear();
	Info->Lines->Add("Results of the searching:");
	p = Worker::GoSearch(list, person);
	if (p) {
		Info->Lines->Add(p->MkNote());
        chosen = p;
	} else {
        Info->Lines->Add("No matches");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DelClick(TObject *Sender)
{
	if (!list) {
		ShowMessage("List of workers is empty!");
		return;
	}
	if (!chosen) {
		ShowMessage("Nobody selected!");
		return;
	}
	if (!chosen->DelMe()) {
        return;
	}
	Info->Lines->Clear();
	Info->Lines->Add(chosen->LastWish());
	list = Worker::DelItem(list, chosen);
	chosen = NULL;
}
//---------------------------------------------------------------------------


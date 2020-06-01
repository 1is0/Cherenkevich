//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>
#pragma hdrstop

#include "Workspace.h"
#include "Student.h"
#include <memory>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
TStringList* Lst = new TStringList;
vector<Student> Students;
TFileStream *fl = NULL;
bool chosen;
int membr;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::OpenClick(TObject *Sender)
{
	int i, len;

	if (Students.size() != 0) {
        ShowMessage("Before opening a new file, be shure that you have saved everything.");
	}
	if (!OpenDialog1->Execute()){
		ShowMessage("You didn't choose anything.");
		return;
	}
    Students.clear();
	try {
		Table->Lines->LoadFromFile(OpenDialog1->FileName);
		Lst->LoadFromFile(OpenDialog1->FileName);
	} catch (...) {
		ShowMessage("There is no such file. Created new one.");
		fl = new TFileStream(OpenDialog1->FileName, fmCreate);
		fl->Free();
	}

	for (i = 0, len = Lst->Count; i < len; i++) {
		Students.push_back(Student(Lst->Strings[i]));
	}
	SyncData();
}
//---------------------------------------------------------------------------


void TForm2::SyncData()
{
	int i, len = Students.size();

	CBox->Items->Clear();
    Table->Lines->Clear();
	for (i = 0; i < len; i++) {
		Students[i].FillCombo(Form2);
		Table->Lines->Add(Students[i].MkNote());
	}
}

void TForm2::ClearFields()
{
    CBox->Text = "";
	Certificate->Text = "";
	Math->Text = "";
	English->Text = "";
	Physics->Text = "";
	Speciality->Text = "";
}



void __fastcall TForm2::AddClick(TObject *Sender)
{
	try {
		int cert = StrToInt(Certificate->Text);
		int eng = StrToInt(English->Text);
		int math = StrToInt(Math->Text);
		int phys = StrToInt(Physics->Text);
		AnsiString spec = Speciality->Text;
		AnsiString name = CBox->Text;
		if (chosen) {
			Students[membr].ChangeInfo(math, phys, eng, cert, name, spec);
			chosen = false;
		} else {
			Students.push_back(Student(math, phys, eng, cert, name, spec));
        }
		SyncData();
        ClearFields();
	} catch (...) {
        CBox->Text = "";
		Certificate->Text = "DATA?";
		Math->Text = "DATA?";
		English->Text = "DATA?";
		Physics->Text = "DATA?";
		Speciality->Text = "DATA?";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SaveClick(TObject *Sender)
{
	if (!SaveDialog1->Execute()) {
		ShowMessage("You didn't choose anything!");
		return;
	}
	Table->Lines->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::SortClick(TObject *Sender)
{
	sort(Students.begin(), Students.end(), Student::Comp);
    SyncData();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::CBoxChange(TObject *Sender)
{
	chosen = true;
	membr = CBox->ItemIndex;

	Students[membr].FillFields(Form2);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DeleteClick(TObject *Sender)
{
	if (chosen) {
		chosen = false;
		Students.erase(Students.begin() + membr);
        ClearFields();
        SyncData();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::SrchClick(TObject *Sender)
{
    Srch->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SearchClick(TObject *Sender)
{
	AnsiString data = Srch->Text;

    SearchTab->Lines->Clear();
	for (int i = 0, am = Table->Lines->Count; i < am; i++) {
		AnsiString str = Table->Lines->Strings[i];
		if (str.AnsiPos(data)) {
			SearchTab->Lines->Add(Students[i].MkNote());
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ChangeInfo(TObject *Sender)
{
    chosen = false;
}
//---------------------------------------------------------------------------


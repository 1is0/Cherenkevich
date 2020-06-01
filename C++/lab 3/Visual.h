//---------------------------------------------------------------------------

#ifndef VisualH
#define VisualH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TButton *Add;
	TButton *Del;
	TButton *Srch;
	TLabel *Lbl;
	TEdit *Search;
	TEdit *ID;
	TEdit *Hours;
	TEdit *Earn;
	TEdit *Name;
	TButton *Show;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TRadioButton *OffFilt;
	TRadioButton *CertEarn;
	TRadioButton *CertHours;
	TLabel *Label4;
	TEdit *ShowData;
	TRadioButton *Overtime;
	TLabel *Label5;
	TRichEdit *Info;
	void __fastcall ShowDataClck(TObject *Sender);
	void __fastcall OffFiltClick(TObject *Sender);
	void __fastcall CertEarnClick(TObject *Sender);
	void __fastcall CertHoursClick(TObject *Sender);
	void __fastcall SearchClck(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall ShowClick(TObject *Sender);
	void __fastcall SrchClick(TObject *Sender);
	void __fastcall DelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
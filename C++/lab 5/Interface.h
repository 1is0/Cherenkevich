//---------------------------------------------------------------------------

#ifndef InterfaceH
#define InterfaceH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TPresent : public TForm
{
__published:	// IDE-managed Components
	TListBox *List1;
	TButton *Clear1;
	TButton *AddRand;
	TEdit *A;
	TEdit *B;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *DelSame;
	TLabel *Label4;
	void __fastcall Clear1Click(TObject *Sender);
	void __fastcall InputClick(TObject *Sender);
	void __fastcall AddRandClick(TObject *Sender);
	void __fastcall AClick(TObject *Sender);
	void __fastcall BClick(TObject *Sender);
	void __fastcall DelSameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPresent(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPresent *Present;
//---------------------------------------------------------------------------
#endif

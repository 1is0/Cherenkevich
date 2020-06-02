//---------------------------------------------------------------------------

#ifndef InterfaceH
#define InterfaceH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TPresent : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TMemo *Table;
	TRichEdit *Elements;
	TRichEdit *Raw;
	TButton *FillTable;
	TEdit *ElemAmount;
	TEdit *TableSize;
	TEdit *KeySrch;
	TEdit *KeyDel;
	TButton *Search;
	TButton *Del;
	TButton *CountNodes;
	TButton *Clear;
	void __fastcall ElemAmountClick(TObject *Sender);
	void __fastcall TableSizeClick(TObject *Sender);
	void __fastcall FillTableClick(TObject *Sender);
	void __fastcall ElementsClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall KeySrchClick(TObject *Sender);
	void __fastcall KeyDelClick(TObject *Sender);
	void __fastcall DelClick(TObject *Sender);
	void __fastcall CountNodesClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPresent(TComponent* Owner);
    bool CheckData(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TPresent *Present;
//---------------------------------------------------------------------------
#endif

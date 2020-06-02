//---------------------------------------------------------------------------

#ifndef InterfaceH
#define InterfaceH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TPresent : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Info;
	TTreeView *TreeView;
	TGroupBox *Control;
	TGroupBox *Tree;
	TMemo *Memo;
	TButton *FiilTree;
	TButton *ShowLNR;
	TButton *ShowLRN;
	TButton *ShowNLR;
	TButton *ClearTree;
	TEdit *AmountOfItems;
	TButton *GetItemsAm;
	TEdit *KeyDelete;
	TEdit *GetChar;
	TButton *NodeDelete;
	TButton *SearchChar;
	void __fastcall KeyDeleteChange(TObject *Sender);
	void __fastcall GetCharClick(TObject *Sender);
	void __fastcall AmountOfItemsClick(TObject *Sender);
	void __fastcall GetItemsAmClick(TObject *Sender);
	void __fastcall FiilTreeClick(TObject *Sender);
	void __fastcall ClearTreeClick(TObject *Sender);
	void __fastcall ShowLNRClick(TObject *Sender);
	void __fastcall ShowLRNClick(TObject *Sender);
	void __fastcall ShowNLRClick(TObject *Sender);
	void __fastcall SearchCharClick(TObject *Sender);
	void __fastcall NodeDeleteClick(TObject *Sender);
	void __fastcall GetCharChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPresent(TComponent* Owner);
	bool CheckInfo();
};
//---------------------------------------------------------------------------
extern PACKAGE TPresent *Present;
//---------------------------------------------------------------------------
#endif

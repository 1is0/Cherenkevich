//---------------------------------------------------------------------------

#pragma hdrstop

#include "Solution.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Solution :: SearchLetter(tree *t, int k1, AnsiString letter, TMemo* Screen, TEdit* Edit1, TEdit* Edit2)
{
	if(t == NULL)
		return;
	if(t -> s[1] == letter[1])
	{
		Screen -> Lines -> Add(t -> s + " = " + IntToStr(t -> key));
		int a = StrToInt(Edit2 -> Text);
		a++;
		Edit2 -> Text = a;
	}
	k1++;
	SearchLetter(t -> l, k1, letter, Screen, Edit1, Edit2);
	SearchLetter(t -> r, k1, letter, Screen, Edit1, Edit2);
	k1--;
}

//---------------------------------------------------------------------------

#pragma hdrstop

#include "Words.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void Words::WordsWithFirstChar(Node* p, AnsiString ch, int& ans) {
	if (!p) {
		return;
	}
	WordsWithFirstChar(p->left, ch, ans);
	if (ch == p->info.text.SubString(0, 1)) {
        ans++;
	}
    WordsWithFirstChar(p->right, ch, ans);
}

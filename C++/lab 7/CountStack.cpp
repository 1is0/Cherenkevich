//---------------------------------------------------------------------------

#pragma hdrstop

#include "CountStack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

AnsiString CountStack::CountStackItems()
{
	AnsiString line;
	Node* p;
    int count = 0;

    line = "Counting nodes in every stack of the table:\n";
	for (int i = 0; i < size; i++) {
		p = hashTable[i];
		line += IntToStr(i + 1) + ":";
		while(p)
		{
			count++;
			p = p->next;
		}
		line += IntToStr(count) + " nodes\n";
        count = 0;
	}
    return line;
}

//---------------------------------------------------------------------------
#include "Tree.h"
#include <vcl.h>
#ifndef WordsH
#define WordsH
//---------------------------------------------------------------------------

class Words: public Tree{
	public:
        Words(): Tree() {};
		static void WordsWithFirstChar(Node*, AnsiString, int&);
};
#endif

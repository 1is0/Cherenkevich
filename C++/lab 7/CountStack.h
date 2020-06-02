//---------------------------------------------------------------------------
#include "HashTable.h"

#ifndef CountStackH
#define CountStackH
//---------------------------------------------------------------------------

class CountStack : public HashTable{
	public:
        CountStack(int sz): HashTable(sz) {};
		AnsiString CountStackItems();
};
#endif

//---------------------------------------------------------------------------

#ifndef HashH
#define HashH
#include "Stack.h"
//---------------------------------------------------------------------------
#endif

class hesh
{
	protected:
		stack** Stacks;
		int Size;
	public:
		hesh(int size);
		int CreateKey(int x);
		stack* GetStack(int key);
		void Add(int x);
		void Remove(int x);
		void Clear();
		AnsiString Find(int i);
		TStringList* Show();
};
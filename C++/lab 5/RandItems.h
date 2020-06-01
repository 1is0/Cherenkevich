//---------------------------------------------------------------------------
#include "Queue.h"

#ifndef RandItemsH
#define RandItemsH
//---------------------------------------------------------------------------

class RandItems : public Queue {
	public:
        RandItems(int);
		int GetRandNum(int, int);
		void DelSameItems();
        void DelItem(Nums*);
};
#endif

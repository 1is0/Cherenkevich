//---------------------------------------------------------------------------
#include "Interface.h"

#ifndef QueueH
#define QueueH
//---------------------------------------------------------------------------

struct Nums {
	int num;
	Nums* next;
    Nums* prev;
};

class Queue {
	protected:
		Nums* head;
		Nums* tail;
	public:
        Queue(int info);
		void ShowQ(TPresent*);
		void AddItemToEnd(int info);
		int PopHeadItem();
		bool IsEmpty();
		~Queue();
};
#endif

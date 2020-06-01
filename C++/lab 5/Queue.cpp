//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Queue::Queue(int info)
{
	Nums* item = new Nums();

	item->num = info;
	item->next = NULL;
	item->prev = NULL;
	head = item;
    tail = item;
}

void Queue::ShowQ(TPresent* F)
{
	Nums* p = head;

    F->List1->Clear();
	while (p) {
		F->List1->Items->Add(p->num);
        p = p->prev;
    }
}

void Queue::AddItemToEnd(int info)
{
	Nums* item = new Nums();

    if (IsEmpty()) {
        head = item;
	}
	item->num = info;
	item->next = tail;
	item->prev = NULL;
    tail->prev = item;
	tail = item;
}

int Queue::PopHeadItem()
{
	int ans = head->num;
	Nums* p = head->prev;

	if (head == tail) {
        tail = NULL;
	}
	delete head;
	head = p;
    head->next = NULL;
    return ans;
}

bool Queue::IsEmpty()
{
	if (!head) {
		return true;
	}
    return false;
}

Queue::~Queue()
{
	Nums* p = head->prev;

	do {
		delete head;
		head = p;
		p = head->prev;
	} while (p);
}



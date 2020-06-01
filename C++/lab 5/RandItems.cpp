//---------------------------------------------------------------------------

#pragma hdrstop

#include "RandItems.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

RandItems::RandItems(int a): Queue(a) {};

int RandItems::GetRandNum(int a, int b)
{
    return a + rand()%(b - a + 1);
}

void RandItems::DelSameItems()
{
	Nums* p = head;
	Nums* j;
	bool hasSame = false;

	while (p) {
		j = p->prev;
		while (j) {
			if (j->num == p->num) {
				DelItem(j);
                hasSame = true;
			}
            j = j->prev;
		}
		j = p->prev;
		if (hasSame) {
			DelItem(p);
            hasSame = false;
		}
        p = j;
    }
}

void RandItems::DelItem(Nums* p)
{
	if (!p) {
		return;
	}
	if (p == head) {
		head = head->prev;
        head->next = NULL;
	} else {
		p->next->prev = p->prev;
	}
	if (p == tail) {
		tail = tail->next;
        tail->prev = NULL;
	} else {
        p->prev->next = p->next;
	}
	delete p;
}

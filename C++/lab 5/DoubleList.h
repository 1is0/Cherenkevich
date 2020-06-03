//---------------------------------------------------------------------------

#ifndef DoubleListH
#define DoubleListH
//---------------------------------------------------------------------------
#endif

class DoubleList
{
	public:

		int value;
		DoubleList *prev, *next;

		void Show(DoubleList**, TListBox*);
		void Add(DoubleList**, TEdit*, TListBox*);
		bool IsEmpty(DoubleList*);
		DoubleList* Delete(DoubleList*, TListBox*);
        DoubleList* Pop(DoubleList*, TEdit*, TListBox*);
};

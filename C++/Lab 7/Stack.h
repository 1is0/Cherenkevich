//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------
#endif

class stack
{
	public:
	int key;
	stack *next;

	stack* Add(stack* head, int k);
	void delet(stack** head);

};

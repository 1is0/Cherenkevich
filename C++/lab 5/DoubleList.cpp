//---------------------------------------------------------------------------

#pragma hdrstop

#include "DoubleList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void DoubleList :: Show(DoubleList **head, TListBox* ListBox)
{
	ListBox -> Clear();
	DoubleList *current = *head;
	while(current)
	{
		ListBox -> Items -> Add(current -> value);
		current = current -> next;
	}
}

void DoubleList :: Add(DoubleList **head, TEdit* Edit, TListBox* ListBox)
{
	DoubleList *add = new DoubleList;
	add -> value = StrToInt(Edit -> Text);
	add -> next = NULL;
	add -> prev = NULL;

	if(!head)
		*head = add;
	else
	{
		DoubleList *current = *head;
		while(current -> next)
			current = current -> next;
		add -> prev = current;
	}
    (*head) -> Show(head, ListBox);
}

bool DoubleList :: IsEmpty(DoubleList *head)
{
	if(head != NULL)
		return false;
	else
		return true;
}

DoubleList* DoubleList :: Delete(DoubleList *head, TListBox* ListBox)
{
	while(head)
	{
		DoubleList *old = head;
		head = head -> next;
		delete old;
	}
	head -> Show(&head, ListBox);
}

DoubleList* DoubleList :: Pop(DoubleList* head, TEdit* Edit, TListBox* ListBox)
{
	if(head)
	{
		DoubleList *old = head;
		int current = head -> value;
		head = head -> next;
		delete old;
		Edit -> Text = IntToStr(current);
		head -> Show(&head, ListBox);
	}
	return head;
}

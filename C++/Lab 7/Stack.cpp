//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

stack* stack::Add(stack* head, int k)
{

   stack* z= new stack;
   z->key=k;
   z->next=head;
   head=z;
   return head;
}

void stack::delet(stack** head)
{
  while (*head)
  {
   stack* z = new stack;
   z=*head;
   *head=(*head)->next;
   delete z;
  }
}

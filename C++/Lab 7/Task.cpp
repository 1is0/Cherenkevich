//---------------------------------------------------------------------------

#pragma hdrstop

#include "Task.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

task ::task(int size):hesh(size){}

double task::srb()
{
	int k=0,sum=0;
	for (int i=0; i < Size; i++)
	{
	  stack* tmp = new stack;
	  tmp=Stacks[i];
	  while(tmp)
	  {
		  k++;
		  sum+=tmp->key;
		  tmp=tmp->next;
	  }
	}
	double sr=(double)sum/k;
	return sr;
}

void task::Print(TEdit* Edit5)
{
	int kol=0;
	int k=srb();
	for (int i=0; i < Size; i++)
	{
	  stack* tmp = new stack;
	  tmp=Stacks[i];
	  while(tmp)
	  {
		  int z=tmp->key;
		  if(z < k)
		  kol++;
          tmp=tmp->next;
	  }
	}
	Edit5->Text=IntToStr(kol);
}
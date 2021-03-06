//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void tree::push(tree **t, int x, AnsiString d)
  {
	if ((*t)==NULL)
	{
	  tree* st = new tree;
	  st->key=x;
	  st->s=d;
	  st->l=st->r=NULL;
	  *t=st;
	  return;
	}

	if (x>(*t)->key) push(&((*t)->r),x,d);
	else push(&((*t)->l),x,d);
  }

void tree::pr_obx(tree* t,TMemo *Memo1)
  {
	if (t)
	{
	  Memo1->Lines->Add((t->s)+" = "+IntToStr(t->key));
	  pr_obx(t->l,Memo1);
	  pr_obx(t->r,Memo1);
	}
  }

  void tree::obr_obx(tree* t,TMemo *Memo1)
  {
	if (t)
	{
	  obr_obx(t->l,Memo1);
	  obr_obx(t->r,Memo1);
	  Memo1->Lines->Add(t->s+" = "+IntToStr(t->key));
	}
  }

  void tree::poisk(tree* t, int g, TMemo *Memo1)
  {
	if (t)
	{
	  if (t->key==g) Memo1->Lines->Add(t->s+" = "+IntToStr(t->key));
	  if (t->key>g) poisk(t->l,g,Memo1);
	  else  poisk(t->r,g,Memo1);
	}
  }

  bool tree::iskey(tree *t, int g)
  {
	bool A;
	if (t)
	{
	  if (t->key==g) return false;
	  if (t->key>g) A=iskey(t->l,g);
	  else  A=iskey(t->r,g);
	}
	else return true;
	return A;
  }

  tree* tree::delel(tree* t,int k)
  {
	  if(t == NULL)
		return t;

	if(k == t->key)
	{
		if (t->r==NULL&&t->l==NULL)
		return NULL;

		if(t->r == NULL) return t->l;
		if(t->l == NULL) return t->r;

		tree* tmp = new tree;
		tree* ptr = t->r;
		  if(ptr->l == NULL)
		  {
			ptr->l = t->l;
			tmp = ptr;
		  }
		  else
		  {
			 tree* pmin = ptr->l;
			 while(pmin->l)
			  {
				ptr  = pmin;
				pmin = ptr->l;
			  }
				ptr->l = pmin->r;
				pmin->l = t->l;
				pmin->r = t->r;
				tmp = pmin;
		  }
		delete t;
		return tmp;

	} else if(k < t->key)
		t->l=t->delel(t->l,k);
	else
		t->r=t->delel(t->r,k);
	return t;
  }

  void tree::ydalit(tree** t)
  {
	if (*t)
	{
	  ydalit(&((*t)->l));
	  ydalit(&((*t)->r));
	  delete(*t);
	}
  }

  void tree::povoz_obx(tree* t,TMemo *Memo1)
  {
	if (t)
	{
		povoz_obx(t->l,Memo1);
		Memo1->Lines->Add(t->s+" = "+IntToStr(t->key));
		povoz_obx(t->r,Memo1);
	}
  }

  void tree::zapvl(tree* t, TStringList **SL)
  {
	if (t)
	{
		zapvl(t->l,SL);
		(*SL)->Add(IntToStr(t->key));
		(*SL)->Add(t->s);
		zapvl(t->r,SL);
	}
  }

  void tree::zapvm (tree* mas,int n, TStringList *SL)
  {
	  for (int i=0; i < n; i++)
	  {
		mas[i].key=StrToInt(SL->Strings[i*2]);
		mas[i].s=SL->Strings[i*2+1];
	  }
  }

  int tree::max(int a, int b)
  {
	return (a >= b) ? a : b;
  }

  int tree::height(tree* t)
  {
	if (t == NULL) return 0;
	else return 1 + max(height(t->l),height(t->r));
  }

  bool tree::isBalanced(tree* t)
  {
	int lh, rh;
	if (t == NULL) return 1;
	lh = height(t->l);
	rh = height(t->r);
	if (abs(lh - rh) <= 1 && isBalanced(t->l) && isBalanced(t->r)) return 1;
	return 0;
  }

  tree* tree::balance(tree* t,int n)
  {
	tree* mas = new tree[n];
	TStringList *SL = new TStringList;
	zapvl(t,&SL);
	zapvm(mas,n,SL);
	delete SL;
	ydalit(&t);
	tree* newt= new tree;
	newt=NULL;
	newder(&newt,mas,0,n-1);
	return newt;
  }

  void tree::newder(tree** t,tree* mas, int i, int j)
  {
	if (i<=j)
		{
			int middle=(i+j)/2;
			int k=mas[middle].key;
			AnsiString d=mas[middle].s;
			(*t)->push(t,k,d);
			newder(t,mas,middle+1,j);
			newder(t,mas,i,middle-1);
		}
  }

void ViewTree(tree *t, int kl, TTreeView *TreeView1)
{
	if (t == NULL)
		return;
	if (kl == -1)
		TreeView1->Items->AddFirst(NULL,t->s+" = "+IntToStr(t->key));
	else
		TreeView1->Items->AddChildFirst(TreeView1 -> Items -> Item[kl], t->s+" = " + IntToStr(t->key));
	kl++;
	ViewTree(t -> l, kl, TreeView1);
	ViewTree(t -> r, kl, TreeView1);
	kl--;
}



//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------
#endif

class tree
{
	public:

	int key;
	AnsiString s;
	tree *l, *r;

  void push(tree **t, int x, AnsiString d);

  void pr_obx(tree* t,TMemo *Memo1);

  void obr_obx(tree* t,TMemo *Memo1);

  void poisk(tree* t, int g, TMemo *Memo1);

  bool iskey(tree *t, int g);

  tree* delel(tree* t,int k);

  void ydalit(tree** t);

  void povoz_obx(tree* t,TMemo *Memo1);

  void zapvl(tree* t, TStringList **SL);

  void zapvm (tree* mas,int n, TStringList *SL);

  int max(int a, int b);

  int height(tree* t);

  bool isBalanced(tree* t);

  tree* balance(tree* t,int n);

  void newder(tree** t,tree* mas, int i, int j);
};


void ViewTree(tree *t, int kl, TTreeView *TreeView1);
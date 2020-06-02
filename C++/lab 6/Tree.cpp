//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Tree::Tree()
{
    root = NULL;
}

void Tree::FillTree(TPresent* F)
{
	int rows = F->Info->RowCount;
	Info inf;

	for (int i = 1; i < rows; i++) {
		inf.text = F->Info->Cells[0][i];
		inf.key = StrToInt(F->Info->Cells[1][i]);
        root = AddNode(root, inf);
	}
}

unsigned char Tree::GetHeight(Node* p)
{
    return p?p->height:0;
}

int Tree::GetBF(Node* p)
{
    return GetHeight(p->right) - GetHeight(p->left);
}

void Tree::FixHeight(Node* p)
{
	unsigned char hl = GetHeight(p->left);
	unsigned char hr = GetHeight(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

Node* Tree::RotateLeft(Node* q)
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	FixHeight(q);
	FixHeight(p);
    return p;
}

Node* Tree::RotateRight(Node* p)
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	FixHeight(p);
	FixHeight(q);
	return q;
}

Node* Tree::Balance(Node* p)
{
	FixHeight(p);
	if (GetBF(p) == 2) {
		if (GetBF(p->right) < 0) {
			p->right = RotateRight(p->right);
		}
		return RotateLeft(p);
	}
	if (GetBF(p) == -2) {
		if (GetBF(p->left) > 0) {
			p->left = RotateLeft(p->left);
		}
        return RotateRight(p);
	}
    return p;
}

Node* Tree::AddNode(Node* p, Info info)
{
	if (!p) {
		 return new Node(info);
	}
	if (info.key < p->info.key) {
		p->left = AddNode(p->left, info);
	} else {
		p->right = AddNode(p->right, info);
	}
    return Balance(p);
}

Node* Tree::FindMin(Node* p)
{
    return p->left?FindMin(p->left):p;
}

Node* Tree::RemoveMin(Node* p)
{
	if (!p->left) {
		return p->right;
	}
	p->left = RemoveMin(p->left);
    return Balance(p);
}

Node* Tree::RemoveNode(Node* p, int k)
{
	if (!p) {
		return NULL;
	}
	if (k < p->info.key) {
		p->left = RemoveNode(p->left, k);
	} else if (k > p->info.key) {
		p->right = RemoveNode(p->right, k);
	} else {
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r) {
			return q;
		}
		Node* min = FindMin(r);
        min->right = RemoveMin(r);
		min->left = q;
		return Balance(min);
	}
    return Balance(p);
}

void Tree::TreeViewSync(TPresent* F, Node* p, int k)
{
	if (!p) {
		return;
	}
	if (k == -1) {
		F->TreeView->Items->AddFirst(NULL, p->info.text + " = " + IntToStr(p->info.key));
	} else {
		F->TreeView->Items->AddChildFirst(
			F->TreeView->Items->Item[k], p->info.text + " = " + IntToStr(p->info.key));
	}
	k++;
	TreeViewSync(F, p->left, k);
	TreeViewSync(F, p->right, k);
	k--;
}

void Tree::ClearTree(Node** p)
{
	if (!(*p)) {
		return;
	}
	ClearTree(&(*p)->left);
	ClearTree(&(*p)->right);
	delete(*p);
    *p = NULL;
}

void Tree::ShowLNR(TPresent* F, Node* p)
{
	if (!p) {
		return;
	}
	ShowLNR(F, p->left);
	F->Memo->Lines->Add(p->info.text + " " + p->info.key);
	ShowLNR(F, p->right);
}

void Tree::ShowNLR(TPresent* F, Node* p)
{
	if (!p) {
		return;
	}
	F->Memo->Lines->Add(p->info.text + " " + p->info.key);
	ShowNLR(F, p->left);
	ShowNLR(F, p->right);
}

void Tree::ShowLRN(TPresent* F, Node* p)
{
	if (!p) {
		return;
	}
	ShowLRN(F, p->left);
	ShowLRN(F, p->right);
	F->Memo->Lines->Add(p->info.text + " " + p->info.key);
}

Node* Tree::SearchKey(int key)
{
	Node* p = root;
	while(p) {
		if (p->info.key == key) {
			return p;
		}
		if (key < p->info.key) {
			p = p->left;
		} else {
            p = p->right;
        }
	}
    return NULL;
}

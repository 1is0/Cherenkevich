//---------------------------------------------------------------------------

#pragma hdrstop

#include "HashTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

HashTable::HashTable(int sz)
{
	size = sz;
	hashTable = new Node*[sz];
	for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
	}
}

void HashTable::FillTable(TPresent* F, int elem)
{
	for (int i = 0; i < elem; i++) {
		AnsiString line = F->Elements->Lines->Strings[i];
		AddNode(StrToInt(line));
	}
}

void HashTable::AddNode(int key)
{
	int ind = Hash(key);
	Node** p = &hashTable[ind];
    Node* node = new Node(key);

	if (!(*p)) {
		*p = node;
        return;
	}
	while(1)
	{
		if (!(*p)->next) {
			(*p)->next = node;
			break;
		}
		p = &(*p)->next;
    }
}

int HashTable::Hash(int key)
{
	return key % size;
}

bool HashTable::DelNode(int key)
{
	int ind = Hash(key);
	Node** p = &hashTable[ind];
	Node* temp;

	if (*p) {
		if ((*p)->key == key) {
			temp = (*p)->next;
			delete (*p);
			(*p) = temp;
            return true;
		}
	}
	while(*p)
	{
		if ((*p)->next->key == key) {
			temp = (*p)->next->next;
			delete (*p)->next;
			(*p)->next = temp;
			return true;
		}
		p = &(*p)->next;
	}
    return false;
}

void HashTable::ShowTable(TPresent* F)
{
	AnsiString line;
	Node* p;

	for (int i = 0; i < size; i++) {
		p = hashTable[i];
		line = IntToStr(i + 1) + ":";
		while(p)
		{
			F->Raw->Lines->Add(IntToStr(i + 1) + ":" + IntToStr(p->key));
			line += IntToStr(p->key) + " --> ";
			p = p->next;
		}
		F->Table->Lines->Add(line);
	}
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; i++) {
		Node* p = hashTable[i];
		Node* temp;
		while(p)
		{
			temp = p->next;
			delete p;
            p = temp;
        }
	}
    delete hashTable;
}

Node* HashTable::FindNode(int key)
{
	Node* p = hashTable[Hash(key)];

	while(p)
	{
		if (p->key == key) {
			return p;
		}
        p = p->next;
	}
    return p;
}
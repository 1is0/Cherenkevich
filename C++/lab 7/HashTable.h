//---------------------------------------------------------------------------
#include "Interface.h"

#ifndef HashTableH
#define HashTableH
//---------------------------------------------------------------------------

struct Node {
	Node* next;
	int key;

    Node(int k): next(NULL), key(k) {};
};


class HashTable {
	protected:
		int size;
		Node** hashTable;
		int Hash(int);
	public:
		HashTable(int);
		Node* FindNode(int);
		void AddNode(int);
		bool DelNode(int);
		void FillTable(TPresent*, int);
		//My Task
		void ShowTable(TPresent*);
        ~HashTable();
};
#endif

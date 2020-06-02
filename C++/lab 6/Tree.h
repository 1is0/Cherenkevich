//---------------------------------------------------------------------------
#include <vcl.h>
#include "Interface.h"

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------

struct Info {
	int key;
	AnsiString text;
};

struct Node {
	Info info;
    unsigned char height;
	Node* left;
	Node* right;

	Node(Info inf)
	{
        info = inf;
		height = 1;
		left = NULL;
        right = NULL;
	}
};

class Tree {
	protected:
		static Node* AddNode(Node*, Info);
        static unsigned char GetHeight(Node*);
		static int GetBF(Node* );
		static void FixHeight(Node*);
		static Node* RotateLeft(Node*);
		static Node* RotateRight(Node*);
		static Node* Balance(Node*);
		static Node* FindMin(Node*);
		static Node* RemoveMin(Node*);
	public:
		Node* root;
		Tree();
		void FillTree(TPresent*);
		Node* SearchKey(int);
		void SearchChar(AnsiString);
        static Node* RemoveNode(Node*, int);
		static void ShowNLR(TPresent*, Node*);
		static void ShowLRN(TPresent*, Node*);
		static void ShowLNR(TPresent*, Node*);
		static void TreeViewSync(TPresent*, Node*, int k = -1);
		static void ClearTree(Node**);
};
#endif

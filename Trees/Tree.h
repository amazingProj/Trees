#pragma once

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Node
{
	list<Node*> sons;
	string value;

	Node(string v) 
	{
		value = v; 
	}
};
/**
  *@brief class represents a tree with single root and many sons of each node
  */
class Tree
{
	Node* root;
	public:
		/**
		  *@brief c'ctor of tree
		  * constructs a tree and root equals to NULL
		  */
		Tree()
		{
			root = NULL;
		}

		~Tree()
		{
			deleteAllSubTree(root);
			delete root;
		}

		Node* getRoot()
		{
			return root;
		}

		void setRoot(Node* _root)
		{
			root = _root;
		}

		void deleteAllSubTree(Node* t);

		void addRoot(string newval);

		void addSon(string father, string newval);

		Node* SubTreeSearch(Node* p, string val);

		bool searchAndPrint(Node* p, string val);

		void searchAndPrint(string val)
		{
			if (!searchAndPrint(root, val))
			{
				cout << "Value not found" << endl;
			}
				
		}
		void searchAndPrintArea(string val)
		{
			Node* area = SubTreeSearch(root, val);
			if (area) print(root);
		}

		void print(Node* p, int level = 0);

		void printAllTree()
		{
			print(root);
		}
		void printAllLeaves()
		{
			cout << "leaves:";
			printLeaves(root); cout << endl;
		}

		void printLeaves(Node* t);

		void printLeavesSubtree(string val)
		{
			Node* t = SubTreeSearch(root, val);
			if (t)
			{
				printLeaves(t);
			}
		}

		void deleteSubTree(string val)
		{
			Node* t = SubTreeSearch(root, val);
			if (t)
			{
				deleteAllSubTree(t);
			}
		}
};
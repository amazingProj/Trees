#include "Tree.h"
#include "limits.h"
/**
  * @file Tree.h
  */

Tree::Tree()
{
	root = NULL;
}

Tree::~Tree()
{
	deleteAllSubTree(this->getRoot());
}

void Tree::setRoot(Node *_root)
{
	root = _root;
}

Node* Tree::getRoot()
{
	return root;
}

void Tree::printLeavesNew(Node* subTree)
{
	if (subTree == NULL)
	{
		return;
	}
	list<Node*> pNodes = subTree->getSonsList();
	// break condition
	if (pNodes.empty())
	{
		cout << subTree->getValue() << "\t";
	}

	list<Node *>::iterator it;
	for (it = pNodes.begin(); it != pNodes.end(); ++it) 
	{
		// recursion
		printLeavesNew(*it);
	}
}

void Tree::deleteAllSubTree(Node *subRoot)
{
	// if a null is given
	if (subRoot == NULL)
	{
		return;
	}
	list<Node*> pNodes = subRoot->getSonsList();
	//Break condition
	if (pNodes.empty())
	{
		delete subRoot;
	}

	list<Node*>::iterator it;
	for (it = pNodes.begin(); it != pNodes.end(); ++it)
	{
		//recursion
		deleteAllSubTree(*it);
	}
	
}

void Tree::setRoot(string newval)
{
	// if string is empty
	if (newval.empty())
	{
		return;
	}
	Node *newRoot = new Node(newval);
	newRoot->addSon(this->getRoot());
	this->setRoot(newRoot);
}

void Tree::addSon(string father, string newval)
{
	if (father.empty() || newval.empty())
	{
		return;
	}
	Node* node = SubTreeSearch(root, father);
	if (node == nullptr)
	{
		return;
	}
	node->addSon(new Node(newval));
}

Node* Tree::SubTreeSearch(Node* node, string val)
{
	if (node == NULL)
	{
		return nullptr;
	}
	// breakpoint condition
	if (node->getValue() == val)
	{
		return node;
	}
	
	list<Node*> pNodes = node->getSonsList();
	list<Node*>::iterator it;
	for (it = pNodes.begin(); it != pNodes.end(); ++it)
	{
		//recursion
		SubTreeSearch(*it, val);
	}
	//not found
	return nullptr;
}

bool Tree::printToScreenSearch(Node* p, string val)
{
	if (p == NULL)
	{
		return false;
	}

	Node* result = SubTreeSearch(p, val);
	if (result == nullptr)
	{
		cout << "not found" << endl;
		return false;
	}
	cout << "found the value in the sub tree" << endl;
	return true;
}

void Tree::print(Node* node, int level)
{
	if (node == NULL)
	{
		return;
	}
	if (level == 1 || node->getSonsList().empty())
	{
		return;
	}
	cout << node->getValue() << "\n";
	
	list<Node*> nodes = node->getSonsList();
	
	list<Node*>::iterator it;
	
	for (it = nodes.begin(); it != nodes.end(); ++it)
	{
		print(*it, level - 1);
	}
}

/// <summary>
/// Helper function of function printAllTree()
/// </summary>
///@see Tree::printAllTree()
void printAllTreeRecursion(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	list<Node*> nodes = node->getSonsList();
	cout << node->getValue() << endl;
	//break condition
	if (nodes.empty())
	{
		return;
	}
	list<Node*>::iterator it;
	for (it = nodes.begin(); it != nodes.end(); ++it)
	{
		printAllTreeRecursion(*it);
	}
}

void Tree::printAllTree()
{
	if (this->root == NULL)
	{
		cout << "no found a tree because root is not defined" << endl;
		return;
	}
	cout << endl;
	printAllTreeRecursion(this->root);
	cout << endl;
}


void Tree::printAllLeaves()
{
	cout << "leaves:";
	this->printLeavesNew(root);
	cout << endl;
}

void Tree::printLeavesSubtree(string val)
{
	Node* t = SubTreeSearch(root, val);
	if (t)
	{
	    this->printLeavesNew(t);
	}
}

void Tree::deleteSubTree(string val)
{
	Node* t = SubTreeSearch(root, val);
	if (t)
	{
		deleteAllSubTree(t);
	}
}

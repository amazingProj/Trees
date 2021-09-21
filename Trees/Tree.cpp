#include "Tree.h"

void Tree::printLeaves(Node* t)
{
	if (t == NULL)
	{
		return;
	}
	if (t->sons.empty())
	{
		cout << t->value << "\t";
	}
	std::list<Node *>::iterator it;
	for (it = t->sons.begin(); it != t->sons.end(); ++it) 
	{
		printLeaves(*it);
	}
}

void Tree::deleteAllTree(Node* t)
{
	if (t == NULL)
	{
		return;
	}

}

void Tree::addRoot(string newval)
{
}

void Tree::addSon(string father, string newval)
{
}

Node* Tree::search(Node* p, string val)
{
	return nullptr;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	return false;
}

void Tree::print(Node* p, int level)
{
}

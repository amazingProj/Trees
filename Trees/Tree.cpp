#include "Tree.h"

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
/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
void Tree::printLeaves(Node* subTree)
{
	if (subTree == NULL)
	{
		return;
	}
	list<Node*>* pNodes = subTree->getSons();
	if (pNodes->empty())
	{
		cout << subTree->getValue() << "\t";
	}
	std::list<Node *>::iterator it;
	for (it = pNodes->begin(); it != pNodes->end(); ++it) 
	{
		printLeaves(*it);
	}
	//delete pNodes;
}

void Tree::deleteAllSubTree(Node *subRoot)
{
	if (this->getRoot()->getSons()->empty())
	{
		return;
	}
	list<Node*>* pNodes = subRoot->getSons();
	std::list<Node*>::iterator it;
	for (it = pNodes->begin(); it != pNodes->end(); ++it)
	{
		deleteAllSubTree(*it);
	}
	std::list<Node*>::iterator iter;
	for (iter = pNodes->begin(); iter != pNodes->end(); ++iter)
	{
		delete *iter;
	}
	subRoot = nullptr;
}

void Tree::addRoot(string newval)
{
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
}

Node* Tree::SubTreeSearch(Node* node, string val)
{
	if (node == NULL)
	{
		return nullptr;
	}
	if (node->getValue() == val)
	{
		return node;
	}
	list<Node*>* pNodes = node->getSons();
	std::list<Node*>::iterator it;
	for (it = pNodes->begin(); it != pNodes->end(); ++it)
	{
		SubTreeSearch(*it, val);
	}
	return nullptr;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	return false;
}

void Tree::print(Node* node, int level)
{
	if (node == NULL)
	{
		return;
	}
	if (level == 0 || )
	{
		return;
	}
	cout << node->getValue() << "\n";
	if (node->getSonsList().back() == NULL)
	{
		return;
	}
	list<Node*> nodes = node->getSonsList();
	if (nodes.back() == NULL)
	{
		return;
	}
	list<Node*>::iterator it;
	
	for (it = nodes.begin();; it != nodes.end(); ++it)
	{
		if (*it)
		{
			print(*it, level - 1);
		}
	}
}

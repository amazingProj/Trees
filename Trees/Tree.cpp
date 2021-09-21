#include "Tree.h"

class SingletonTree
{
private:
	/* Here will be the instance stored. */
	static SingletonTree* instance;
	Tree tree;
	/* Private constructor to prevent instancing. */
	SingletonTree();

public:
	/* Static access method. */
	static SingletonTree* getInstance();
	Tree getTree()
	{
		return tree;
	}
};

/* Null, because instance will be initialized on demand. */
SingletonTree* SingletonTree::instance = 0;

SingletonTree* SingletonTree::getInstance()
{
	if (instance == 0)
	{
		instance = new SingletonTree();
	}

	return instance;
}

SingletonTree::SingletonTree()
{
	tree = Tree();
}

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

void Tree::deleteAllSubTree(Node* t)
{
	if (t == NULL)
	{
		return;
	}
	if (t->sons.empty())
	{
		return;
	}
	std::list<Node*>::iterator it;
	for (it = t->sons.begin(); it != t->sons.end(); ++it)
	{
		deleteAllSubTree(*it);
	}
	std::list<Node*>::iterator it;
	for (it = t->sons.begin(); it != t->sons.end(); ++it)
	{
		delete *it;
	}
	delete t;
}

void Tree::addRoot(string newval)
{
	if (newval.empty())
	{
		return;
	}
	SingletonTree* singletonTree = SingletonTree::getInstance();
	Tree tree = singletonTree->getTree();
	Node newRoot = Node(newval);
	newRoot.sons.push_back(tree.getRoot());
	tree.setRoot(&newRoot);
}

void Tree::addSon(string father, string newval)
{
	
}

Node* Tree::SubTreeSearch(Node* p, string val)
{
	if (p == NULL)
	{
		return nullptr;
	}
	if (p->value == val)
	{
		return p;
	}
	std::list<Node*>::iterator it;
	for (it = p->sons.begin(); it != p->sons.end(); ++it)
	{
		SubTreeSearch(*it, val);
	}
	return nullptr;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	return false;
}

void Tree::print(Node* p, int level)
{
	if (p == NULL)
	{
		return;
	}
	if (level == 0)
	{
		return;
	}
	cout << p->value;
	std::list<Node*>::iterator it;
	for (it = p->sons.begin(); it != p->sons.end(); ++it)
	{
		print(*it, level - 1);
	}
}

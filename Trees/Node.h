#pragma once
#include <list>
#include <string>

using namespace std;

class Node
{
	list<Node*> sons;
	string value;
public:
	/// <summary>
	/// constructs a leaf node by only value
	/// </summary>
	/// <param name="v">
	/// a string
	/// </param>
	Node(string v)
	{
		value = v;
	}
	Node()
	{
		sons.push_back(NULL);
	}
	/// <summary>
	/// 
	/// </summary>
	/// <returns>
	/// a string of value of node
	/// </returns>
	string getValue()
	{
		return value;
	}
	list<Node*>* getSons()
	{
		list<Node*>* pList = &sons;
		return pList;
	}
	list<Node*> getSonsList()
	{
		return sons;
	}
	void addSon(string _value)
	{
		Node* newNode = new Node(_value);
		sons.push_back(newNode);
	}
	void addSon(Node *_node)
	{
		sons.push_back(_node);
	}
};

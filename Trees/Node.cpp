#include "Node.h"

/**
  *@file Node.h
  */

Node::Node(string v)
{
	value = v;
}

string Node::getValue()
{
	return value;
}

list<Node*> Node::getSonsList()
{
	return sons;
}

void Node::addSonValue(string _value)
{
	Node* newNode = new Node(_value);
	sons.push_back(newNode);
}

void Node::addSon(Node* _node)
{
	sons.push_back(_node);
}
#pragma once
#include <list>
#include <string>

using namespace std;

/// <summary>
/// class reprsents a node that points to zero to many other nodes
/// </summary>
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
	Node(string v);
	/// <summary>
	/// 
	/// </summary>
	/// <returns>
	/// a string of value of node
	/// </returns>
	string getValue();
	/// <summary>
	/// node's sons getter
	/// </summary>
	/// <returns>a list of pointer of sons nodes</returns>
	list<Node*> getSonsList();
	/// <summary>
	/// adds a new son to node with a value
	/// </summary>
	/// <param name="_value">a value</param>
	void addSonValue(string _value);
	/// <summary>
	/// adds a new son to a node 
	/// </summary>
	/// <param name="_node">a pointer node</param>
	void addSon(Node* _node);
};

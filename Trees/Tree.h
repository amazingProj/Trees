#pragma once

#include <iostream>
#include "Node.h"

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
		Tree();

		/**
		  *@brief d'ctor of tree
		  * destruct a tree
		  */
		~Tree();
		/// <summary>
		/// getter of tree root
		/// </summary>
		/// <returns>
		/// a root node
		/// </returns>
		Node* getRoot();
		/// <summary>
		/// setter of root
		/// </summary>
		/// <param name="_root">
		/// a new root node
		/// </param>
		void setRoot(Node* _root);
		/// <summary>
		/// deletes all nodes in a sub tree
		/// </summary>
		/// <param name="">a subtree node</param>
		void deleteAllSubTree(Node*);
		/// <summary>
		/// sets a root by a value
		/// </summary>
		/// <param name="newval">a value</param>
		void setRoot(string newval);
		/// <summary>
		/// adds a son to a tree
		/// </summary>
		/// <param name="father">the value of the father</param>
		/// <param name="newval">the new son value</param>
		void addSon(string father, string newval);
		/// <summary>
		/// searches a value in a subtree
		/// </summary>
		/// <param name="p">a subtree node</param>
		/// <param name="val">a value</param>
		/// <returns>the sub subtree with the specific value</returns>
		Node* SubTreeSearch(Node* p, string val);
		/// <summary>
		/// search 
		/// </summary>
		/// <param name="subtree">a sub tree</param>
		/// <param name="val">a value</param>
		/// <returns>if value was not found then false otherwise true</returns>
		bool printToScreenSearch(Node* subtree, string val);
		/// <summary>
		/// prints subtree and dpeth level
		/// </summary>
		/// <param name="p">a subtree node</param>
		/// <param name="level">a depth level</param>
		void print(Node* p, int level);
		/// <summary>
		/// prints all the tree
		/// </summary>
		void printAllTree();
		/// <summary>
		/// prints all the leaves 
		/// </summary>
		void printAllLeaves();		
		/// <summary>
		/// prints all leaves in the subtree
		/// </summary>
		/// <param name="t">a subtree</param>
		void printLeavesNew(Node* t);
		/// <summary>
		/// prints all leaves with the specific value
		/// </summary>
		/// <param name="val">a value</param>
		void printLeavesSubtree(string val);
		/// <summary>
		/// deletes all subtrees with the specific value in the tree
		/// </summary>
		/// <param name="val">a value</param>
		void deleteSubTree(string val);
		/// <summary>
		/// creates a random tree
		/// </summary>
		/// <returns>a tree root</returns>
	};
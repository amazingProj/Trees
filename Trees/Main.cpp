#include <iostream>
#include <list>
#include <string>
#include <assert.h>
#include "Tree.h"
#include <map>
constexpr auto SUCCESSFULLY_FINISHED = 1;

/// <summary>
/// print to screen some commandd to do with the tree,
/// </summary>
void printInformation()
{
	cout << "Choose one of the following:" << endl << endl;
	cout << "key value \t\t" << "explanation" << endl;
	cout << "n: \t\tNew tree" << endl;
	cout << "ss: \t\tAdd son to specific value" << endl;
	cout << "p: \t\tprint all the tree" << endl;
	cout << "e: \t\tterminate and exit" << endl;
	cout << endl;
}

/// <summary>
/// checks Tree class implementation
/// @notice the outputs prove that it works
/// </summary>
/// <param name="">no input</param>
/// <returns>1 if it is succeded</returns>
int main(void)
{
	Tree tree;
	string val, op;
	string fatherValue;
	char input[100];
	char operation[100];
	char inputOptional[100];
	bool alive = true;
	bool firstTime = true;
	cout << "Welcome to our tree database" << endl;
	do
	{
		cout << "Please enter a value " << endl;
		if (firstTime)
		{
			cout << "NOTICE THIS VALUE IS THE ROOT" << endl;
		}
		cout.flush();
		cin.getline(input, _MAX_PATH);
		val = (string) input;
		if (firstTime)
		{
			tree.setRoot(val);
			firstTime = false;
			continue;
		}
		cout << "Enter a command code" << endl << "Press i to information about how to use the commands" << endl;
		cout << "Press e to terminate" << endl;
		cout.flush();
		cin.getline(operation, _MAX_PATH);
		op = (string) operation;

		if (op._Equal("i"))
		{

			printInformation();
			cout << "Enter a command code" << endl << "Press i to the all commands" << endl;
			cout << "Press e to terminate" << endl;
			cout.flush();
			cin.getline(operation, _MAX_PATH);
			op = (string) operation;
		}

		if (op._Equal("n"))
		{
			tree.setRoot(val);
		} 
		else if (op._Equal("e"))
		{
			tree.addSon(tree.getRoot()->getValue(), val);
			cout << "Bye" << endl;
			alive = false;
		}
		else if (op._Equal("p"))
		{
			tree.addSon(tree.getRoot()->getValue(), val);
			tree.printAllTree();
		} 
		else if (op._Equal("ss"))
		{
			tree.addSon(tree.getRoot()->getValue(), val);
			cout << "enter father value" << endl;
			cout.flush();
			cin.getline(inputOptional, _MAX_PATH);
			fatherValue = (string) inputOptional;
			tree.addSon(fatherValue, val);
		}
		
	} while (alive);
	return SUCCESSFULLY_FINISHED;
}
